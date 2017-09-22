#include "fractaltransformationwidget.h"

#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>

FractalTransformationWidget::FractalTransformationWidget(QWidget *parent) : QWidget(parent)
{
    auto layout = new QFormLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    _x_coordinate = new QSpinBox();
    _x_coordinate->setRange(0, 900-1);
    _x_coordinate->setValue(900/2);
    layout->addRow(new QLabel(tr("X:")), _x_coordinate);

    _y_coordinate = new QSpinBox();
    _y_coordinate->setRange(0, 600-1);
    _y_coordinate->setValue(600/2);
    layout->addRow(new QLabel(tr("Y:")), _y_coordinate);

    _zoom_factor = new QDoubleSpinBox();
    _zoom_factor->setMinimum(1.0);
    _zoom_factor->setValue(1.0);
    layout->addRow(new QLabel(tr("Zoom:")), _zoom_factor);

    _add_zoom = new QPushButton(tr("Add Zoom"));
    layout->addWidget(_add_zoom);

    _remove_zoom = new QPushButton(tr("Remove Zoom"));
    _remove_zoom->setEnabled(false);
    layout->addWidget(_remove_zoom);

    _rotation_angle = new QDoubleSpinBox();
    _rotation_angle->setRange(-360.0, 360.0);
    _rotation_angle->setValue(0.0);
    layout->addRow(new QLabel(tr("Angle:")), _rotation_angle);

    _apply_rotation = new QPushButton(tr("Rotate"));
    layout->addWidget(_apply_rotation);

    connect(_apply_rotation, SIGNAL(clicked(bool)), this, SLOT(changeRotation()));

    connect(_add_zoom, SIGNAL(clicked(bool)), this, SLOT(addZoom()));

    connect(_remove_zoom, SIGNAL(clicked(bool)), this, SLOT(removeZoom()));

    setLayout(layout);

    _transformation = std::shared_ptr<CoordinateTransformer>(new CoordinateTransformer);
}

std::shared_ptr<CoordinateTransformer> FractalTransformationWidget::getTransformation() const {
    return _transformation;
}

void FractalTransformationWidget::addZoom() {
    _remove_zoom->setEnabled(true);
    _transformation->addZoom({{_x_coordinate->value(), _y_coordinate->value()}, 1 / _zoom_factor->value()});
    emit transformationApplied();
}

void FractalTransformationWidget::removeZoom() {
    if (!_transformation->removeZoom())
        _remove_zoom->setEnabled(false);
    emit transformationApplied();
}

void FractalTransformationWidget::changeRotation() {
    _transformation->setRotationAngle(_rotation_angle->value());
    emit transformationApplied();
}
