#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <memory>
#include "fractalcreator.h"
#include "color/linearinterpolatedcoloring.h"

using namespace fractal;

class QLabel;
class QGraphicsView;
class QGraphicsScene;
class FractalGraphicsItem;
class FractalSettingsWidget;
class ColoringSettingsWidget;
class FractalTransformationWidget;
class FractalGraphicsScene;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);

protected:
    virtual void resizeEvent(QResizeEvent* event);

private:
    void createDockWindows();
    void connectZoomSignals(bool mode);

    FractalGraphicsScene* _scene;
    QGraphicsView* _image_view;
    FractalGraphicsItem* _item;
    FractalSettingsWidget* _fractal_settings;
    ColoringSettingsWidget* _coloring_settings;
    FractalTransformationWidget* _transformation_settings;

    std::unique_ptr<FractalCreator> _fractal_creator;

signals:
    void dummySignal();
public slots:
    void recalculate();
    void updateImage();
};

#endif // MAINWINDOW_H
