#include <QFormLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QFile>
#include <QDebug>
#include <QDir>

#include "coloringsettingswidget.h"
#include "colormapxmlreader.h"

#include "color/simplecoloring.h"
#include "color/linearinterpolatedcoloring.h"

ColoringSettingsWidget::ColoringSettingsWidget(QWidget *parent) : QWidget(parent)
{    
    QFormLayout* layout = new QFormLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    _coloring_type = new QComboBox();
    _coloring_type->addItem(tr("Simple"));
    _coloring_type->addItem(tr("Linear interpolated"));
    _coloring_type->model()->sort(0, Qt::AscendingOrder);
    layout->addRow(new QLabel(tr("Coloring")), _coloring_type);

    _color_map_type = new QComboBox();
    loadColorMaps();
    layout->addRow(new QLabel(tr("Color Map")), _color_map_type);

//    _apply_changes = new QPushButton("Apply");
//    layout->addWidget(_apply_changes);

    QLabel* color_label = new QLabel();
    Color test {120, 62, 77};
    QString style_sheet = "QLabel { background-color: rgb(";
    style_sheet += QString::number(test.red) + QString(", ") + QString::number(test.green) + QString(", ") + QString::number(test.blue) + QString(") }");
    color_label->setStyleSheet(style_sheet);
    color_label->setFrameStyle(QFrame::Box);
    color_label->setAlignment(Qt::AlignHCenter);
    color_label->setText("0.0");

    QLabel* color_label2 = new QLabel();
    color_label2->setFrameStyle(QFrame::Box);
    color_label2->setAlignment(Qt::AlignHCenter);
    color_label2->setText("1.0");

    layout->addRow(new QLabel(tr("0.0")), color_label);
    layout->addRow(new QLabel(tr("1.0")), color_label2);

    this->setLayout(layout);

    connect(_coloring_type, SIGNAL(currentIndexChanged(QString)), this, SLOT(algorithmChanged(QString)));
    connect(_color_map_type, SIGNAL(currentIndexChanged(QString)), this, SLOT(colorMapChanged(QString)));

    algorithmChanged(_coloring_type->currentText());
//    _coloring_algorithm.reset(new SimpleColoring(1000));
}

void ColoringSettingsWidget::loadColorMaps() {
    // read directory with coloring presets
    QDir directory("../qt_gui/color_maps/");

    // get a list of xml files in directory
    QStringList filters;
    filters << "*.xml";
    directory.setNameFilters(filters);
    auto file_list = directory.entryList();

    // parse each xml file and create color_map objects
    for (const auto& file_name : file_list) {
        QFile file(directory.absoluteFilePath(file_name));
        if (!file.open(QFile::ReadOnly | QFile::Text)) {
            qDebug() << "Cannot read file" << file.errorString();
            continue;
        }
        std::shared_ptr<ColorMap> color_map {new ColorMap};
        ColorMapXmlReader reader(color_map.get());
        if (reader.read(&file)) {
            auto item_name = reader.getName();
            _color_map_array.emplace(item_name.toStdString(), color_map);
            _color_map_type->addItem(item_name);
        }
        file.close();
    }

    _color_map_type->model()->sort(0, Qt::AscendingOrder);
}

void ColoringSettingsWidget::algorithmChanged(QString algorithm_name) {
    if (algorithm_name == tr("Simple")) {
        _coloring_algorithm.reset(new SimpleColoring());
    }
    else {
        auto coloring = new LinearInterpolatedColoring();

        _coloring_algorithm.reset(coloring);
    }
    _coloring_algorithm->setColorMap(_color_map_array.at(_color_map_type->currentText().toStdString()));
    emit newColoring();
}

void ColoringSettingsWidget::colorMapChanged(QString color_map_name) {
    _coloring_algorithm->setColorMap(_color_map_array.at(color_map_name.toStdString()));
    emit newColoring();
}

std::shared_ptr<ColoringAlgorithm> ColoringSettingsWidget::getColoringAlgorithm() const {
    return _coloring_algorithm;
}
