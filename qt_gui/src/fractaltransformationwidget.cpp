#include "fractaltransformationwidget.h"

#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>

FractalTransformationWidget::FractalTransformationWidget(QWidget *parent) : QWidget(parent)
{
    auto layout = new QFormLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    _zoom_mode = new QPushButton(tr("Zoom Mode"));
    _zoom_mode->setCheckable(true);
    layout->addWidget(_zoom_mode);
//    _x_coordinate = new QSpinBox();
//    _x_coordinate->setRange(0, 900-1);
//    _x_coordinate->setValue(900/2);
//    layout->addRow(new QLabel(tr("X:")), _x_coordinate);

//    _y_coordinate = new QSpinBox();
//    _y_coordinate->setRange(0, 600-1);
//    _y_coordinate->setValue(600/2);
//    layout->addRow(new QLabel(tr("Y:")), _y_coordinate);

//    _zoom_factor = new QDoubleSpinBox();
//    _zoom_factor->setMinimum(1.0);
//    _zoom_factor->setValue(1.0);
//    layout->addRow(new QLabel(tr("Zoom:")), _zoom_factor);

//    _add_zoom = new QPushButton(tr("Add Zoom"));
//    layout->addWidget(_add_zoom);

//    _remove_zoom = new QPushButton(tr("Remove Zoom"));
//    _remove_zoom->setEnabled(false);
//    layout->addWidget(_remove_zoom);

    _rotation_angle = new QDoubleSpinBox();
    _rotation_angle->setRange(-360.0, 360.0);
    _rotation_angle->setValue(0.0);
    layout->addRow(new QLabel(tr("Angle:")), _rotation_angle);

    _apply_rotation = new QPushButton(tr("Rotate"));
    layout->addWidget(_apply_rotation);

    connect(_zoom_mode, SIGNAL(toggled(bool)), this, SIGNAL(zoomModeEnabled(bool)));
    connect(_apply_rotation, SIGNAL(clicked(bool)), this, SLOT(changeRotation()));

//    connect(_add_zoom, SIGNAL(clicked(bool)), this, SLOT(addZoom()));

//    connect(_remove_zoom, SIGNAL(clicked(bool)), this, SLOT(removeZoom()));

    setLayout(layout);

    _transformation = std::shared_ptr<CoordinateTransformer>(new CoordinateTransformer);
}

void FractalTransformationWidget::setDimensions(int width, int height) {
    _width = width;
    _height = height;
}

std::shared_ptr<CoordinateTransformer> FractalTransformationWidget::getTransformation() const {
    return _transformation;
}

void FractalTransformationWidget::zoomInOnRect(QRect rect) {
//    _remove_zoom->setEnabled(true);
    _transformation->addZoom({getCenterPoint(rect), rect.width() / static_cast<double>(_width)});
    emit transformationApplied();
}

void FractalTransformationWidget::zoomInOnPoint(QPoint point) {
//    _remove_zoom->setEnabled(true);
    auto zoom_factor = 0.5;
    _transformation->addZoom({qPointToPoint(point), zoom_factor});
    emit transformationApplied();
}

//void FractalTransformationWidget::addZoom() {
//    _remove_zoom->setEnabled(true);
//    _transformation->addZoom({{_x_coordinate->value(), _y_coordinate->value()}, 1 / _zoom_factor->value()});
//    emit transformationApplied();
//}

//void FractalTransformationWidget::addZoom(Zoom zoom) {
//    _remove_zoom->setEnabled(true);
//    _transformation->addZoom(zoom);
//    emit transformationApplied();
//}

void FractalTransformationWidget::removeZoom() {
    _transformation->removeZoom();
//    if (_transformation->defaultScale())
//        _remove_zoom->setEnabled(false);
    emit transformationApplied();
}

void FractalTransformationWidget::changeRotation() {
    _transformation->setRotationAngle(_rotation_angle->value());
    emit transformationApplied();
}

// helper functions

inline Point<int> qPointToPoint(const QPoint& point) {
    return {point.x(), point.y()};
}

inline Point<int> getCenterPoint(const QRect& rect) {
    return {rect.x() + rect.width()/2, rect.y() + rect.height()/2};
}
