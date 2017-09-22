#ifndef FRACTALTRANSFORMATIONWIDGET_H
#define FRACTALTRANSFORMATIONWIDGET_H

#include <QWidget>

#include <memory>
#include "transformation/coordinatetransformer.h"

using namespace fractal;

class QSpinBox;
class QDoubleSpinBox;
class QPushButton;

class FractalTransformationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FractalTransformationWidget(QWidget *parent = 0);
    std::shared_ptr<CoordinateTransformer> getTransformation() const;

private:
    QSpinBox* _x_coordinate;
    QSpinBox* _y_coordinate;
    QDoubleSpinBox* _zoom_factor;
    QDoubleSpinBox* _rotation_angle;
    QPushButton* _apply_rotation;
    QPushButton* _add_zoom;
    QPushButton* _remove_zoom;

    std::shared_ptr<CoordinateTransformer> _transformation;

signals:
    void transformationApplied();

public slots:

private slots:
    void addZoom();
    void removeZoom();
    void changeRotation();
};

#endif // FRACTALTRANSFORMATIONWIDGET_H
