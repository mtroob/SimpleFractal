#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QSpinBox>

#include <iostream>

#include "fractalsettingswidget.h"

#include "fractal/mandelbrot.h"

FractalSettingsWidget::FractalSettingsWidget(QWidget *parent) : QWidget(parent)
{
    createLayout();

    connect(_change_dimensions, SIGNAL(clicked(bool)), this, SLOT(changeDimensionsButtonPressed(bool)));
    connect(_apply_changes, SIGNAL(clicked(bool)), this, SLOT(applyButtonPressed(bool)));
    connect(_fractal_type, SIGNAL(currentIndexChanged(int)), this, SLOT(updateSettings()));
    connect(_max_iterations, SIGNAL(editingFinished()), this, SLOT(updateSettings()));
    connect(_escape_radius, SIGNAL(editingFinished()), this, SLOT(updateSettings()));

    applyButtonPressed(true);
}

void FractalSettingsWidget::createLayout() {
    QFormLayout* layout = new QFormLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    _image_width = new QSpinBox();
    _image_width->setRange(1, 10000);
    _image_width->setValue(900);
    layout->addWidget(_image_width);

    _image_height = new QSpinBox();
    _image_height->setRange(1, 10000);
    _image_height->setValue(600);
    layout->addWidget(_image_height);

    _change_dimensions = new QPushButton(tr("Change Dimensions"));
    layout->addWidget(_change_dimensions);

    _fractal_type = new QComboBox();
    _fractal_type->addItem(tr("Mandelbrot"));
    layout->addRow(new QLabel(tr("Fractal type:")), _fractal_type);

    _max_iterations = new QSpinBox();
    _max_iterations->setRange(1, 100000);
    _max_iterations->setValue(100);
    layout->addRow(new QLabel(tr("Max iterations:")), _max_iterations);

    _escape_radius = new QSpinBox();
    _escape_radius->setRange(1, 100);
    _escape_radius->setValue(2);
    layout->addRow(new QLabel(tr("Escape radius:")), _escape_radius);

    _apply_changes = new QPushButton(tr("Apply"));
    layout->addWidget(_apply_changes);

    this->setLayout(layout);
}

QSize FractalSettingsWidget::getDimensions() const {
    return {_image_width->value(), _image_height->value()};
}

void FractalSettingsWidget::applyButtonPressed(bool state) {
    auto fractal_name = _fractal_type->currentText();
    if (fractal_name == "Mandelbrot") {
        _fractal.reset(new Mandelbrot(_max_iterations->value(), _escape_radius->value()));
    }
    emit settingsChanged();
//    std::cout << "FractalSettingsWidget::applyButtonPressed()" << std::endl;
}

void FractalSettingsWidget::changeDimensionsButtonPressed(bool) {
    emit dimensionsChanged({_image_width->value(), _image_height->value()});
}

void FractalSettingsWidget::updateSettings() {

//    std::cout << "FractalSettingsWidget::updateSettings()" << std::endl;
}

const std::shared_ptr<Fractal> FractalSettingsWidget::getFractal() const {
    return _fractal;
}
