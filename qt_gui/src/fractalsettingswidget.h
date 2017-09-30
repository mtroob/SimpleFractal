#ifndef FRACTALSETTINGSWIDGET_H
#define FRACTALSETTINGSWIDGET_H

#include <QWidget>

#include <memory>
#include "fractal/fractal.h"

using namespace fractal;

class QComboBox;
class QPushButton;
class QSpinBox;

class FractalSettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FractalSettingsWidget(QWidget *parent = 0);
    const std::shared_ptr<Fractal> getFractal() const;
    QSize getDimensions() const;

private:
    inline void createLayout();
    inline void connectSignals();

    QComboBox* _fractal_type;
    QPushButton* _apply_changes;
    QSpinBox* _max_iterations;
    QSpinBox* _escape_radius;
    QSpinBox* _image_width;
    QSpinBox* _image_height;
    QPushButton* _change_dimensions;

    std::shared_ptr<Fractal> _fractal;

signals:
    void settingsChanged();
    void dimensionsChanged(QSize);

public slots:

private slots:
//    void updateSettings();
    void applyButtonPressed(bool);
    void changeDimensionsButtonPressed(bool);
};

#endif // FRACTALSETTINGSWIDGET_H
