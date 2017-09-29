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
class QGraphicsPixmapItem;
class FractalGraphicsItem;
class FractalSettingsWidget;
class ColoringSettingsWidget;
class FractalTransformationWidget;
class FractalGraphicsScene;
class FractalGraphicsView;

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
    QGraphicsPixmapItem* _item;
    FractalSettingsWidget* _fractal_settings;
    ColoringSettingsWidget* _coloring_settings;
    FractalTransformationWidget* _transformation_settings;

    std::unique_ptr<FractalCreator> _fractal_creator;

signals:
    void dummySignal();
public slots:

private slots:
    void recalculate();
    void updateImage();
    void updateImageDimensions(QSize);
};

#endif // MAINWINDOW_H
