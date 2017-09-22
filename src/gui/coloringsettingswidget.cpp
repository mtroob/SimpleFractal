#include <QFormLayout>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>

#include "coloringsettingswidget.h"

#include "color/simplecoloring.h"
#include "color/linearinterpolatedcoloring.h"

ColoringSettingsWidget::ColoringSettingsWidget(QWidget *parent) : QWidget(parent)
{
    QFormLayout* layout = new QFormLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    _coloring_type = new QComboBox();
    _coloring_type->addItem(tr("Simple"));
    _coloring_type->addItem(tr("Linear interpolated"));
    layout->addRow(new QLabel(tr("Coloring")), _coloring_type);

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

    algorithmChanged(_coloring_type->currentText());
//    _coloring_algorithm.reset(new SimpleColoring(1000));
}

void ColoringSettingsWidget::algorithmChanged(QString algorithm_name) {
    if (algorithm_name == tr("Simple")) {
        _coloring_algorithm.reset(new SimpleColoring());
        _min_colors = 2;
        _max_colors = 2;
    }
    else {
        auto coloring = new LinearInterpolatedColoring();
        // TODO: load preset
        _min_colors = 2;
        _max_colors = -1;
        coloring->addColor(0.0, {0, 7, 100});
        coloring->addColor(0.02, {62, 230, 120});
        coloring->addColor(0.08, {50, 107, 203});
        coloring->addColor(0.32, {237, 255, 255});
        coloring->addColor(0.6425, {255, 170, 0});
        coloring->addColor(0.8575, {200, 2, 0});
        coloring->addColor(1, {0, 0, 0});
        _coloring_algorithm.reset(coloring);
    }
    emit newColoring();
}

std::shared_ptr<ColoringAlgorithm> ColoringSettingsWidget::getColoringAlgorithm() const {
    return _coloring_algorithm;
}
