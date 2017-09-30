#include <QDockWidget>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QDebug>

#include "mainwindow.h"
#include "fractalsettingswidget.h"
#include "coloringsettingswidget.h"
#include "fractaltransformationwidget.h"
#include "fractalgraphicsscene.h"
#include "fractalgraphicsitem.h"
#include "fractalgraphicsview.h"

// for test
#include <memory>
#include "fractal/mandelbrot.h"
#include "fractalcreator.h"
#include "color/linearinterpolatedcoloring.h"
#include "transformation/coordinatetransformer.h"

using namespace fractal;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    _image_view = new QGraphicsView();
    _scene = new FractalGraphicsScene();
    _item = new QGraphicsPixmapItem();
    _item->setAcceptHoverEvents(true);
    _scene->addItem(_item);

    _image_view->setScene(_scene);

    this->setCentralWidget(_image_view);

    createDockWindows();

    auto dimenions = _fractal_settings->getDimensions();

    _fractal_creator.reset(new FractalCreator(dimenions.width(), dimenions.height(), _fractal_settings->getFractal()));
    _transformation_settings->setDimensions(dimenions.width(), dimenions.height());

    connect(_fractal_settings, SIGNAL(dimensionsChanged(QSize)), this, SLOT(updateImageDimensions(QSize)));
    connect(_fractal_settings, SIGNAL(settingsChanged()), this, SLOT(recalculate()));

    connect(_coloring_settings, SIGNAL(newColoring()), this, SLOT(updateImage()));

    connect(_transformation_settings, SIGNAL(transformationApplied()), this, SLOT(recalculate()));

    connect(_transformation_settings, &FractalTransformationWidget::zoomModeEnabled, this, &MainWindow::connectZoomSignals);
}

void MainWindow::connectZoomSignals(bool mode) {
    if (mode) {
        connect(_scene, SIGNAL(areaSelected(QRect)), _transformation_settings, SLOT(zoomInOnRect(QRect)));
        connect(_scene, SIGNAL(leftButtonDoubleClicked(QPoint)), _transformation_settings, SLOT(zoomInOnPoint(QPoint)));
        connect(_scene, SIGNAL(rightButtonClicked(QPoint)), _transformation_settings, SLOT(removeZoom()));
    }
    else {
        disconnect(_scene, SIGNAL(areaSelected(QRect)), _transformation_settings, SLOT(zoomInOnRect(QRect)));
        disconnect(_scene, SIGNAL(leftButtonDoubleClicked(QPoint)), _transformation_settings, SLOT(zoomInOnPoint(QPoint)));
        disconnect(_scene, SIGNAL(rightButtonClicked(QPoint)), _transformation_settings, SLOT(removeZoom()));
    }
    _scene->selectionEnable(mode);
}

void MainWindow::createDockWindows() {

    QDockWidget* dock = new QDockWidget(tr("Fractal Settings"), this);
    dock->setAllowedAreas(Qt::RightDockWidgetArea | Qt::LeftDockWidgetArea);

    _fractal_settings = new FractalSettingsWidget(dock);
    dock->setWidget(_fractal_settings);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    dock = new QDockWidget(tr("Coloring Settings"), this);
    dock->setAllowedAreas(Qt::RightDockWidgetArea | Qt::LeftDockWidgetArea);

    _coloring_settings = new ColoringSettingsWidget(dock);
    dock->setWidget(_coloring_settings);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    dock = new QDockWidget(tr("Transformation Settings"), this);
    dock->setAllowedAreas(Qt::RightDockWidgetArea | Qt::LeftDockWidgetArea);

    _transformation_settings = new FractalTransformationWidget(dock);
    dock->setWidget(_transformation_settings);
    addDockWidget(Qt::RightDockWidgetArea, dock);
}

void MainWindow::updateImageDimensions(QSize size) {
    qDebug() << Q_FUNC_INFO << size;
    _fractal_creator.reset(new FractalCreator(size.width(), size.height(), _fractal_settings->getFractal()));
    _transformation_settings->setDimensions(size.width(), size.height());
    recalculate();
}

void MainWindow::recalculate() {
    _fractal_creator->calculateValues(_fractal_settings->getFractal(), _transformation_settings->getTransformation());
    updateImage();
}

void MainWindow::updateImage() {
    // redraw fractal using specified coloring algorithm
    auto coloring = _coloring_settings->getColoringAlgorithm();
    coloring->setup(_fractal_creator.get());
    _fractal_creator->drawFractal(coloring);

    // update fractal visual representation
    auto pixel_array = _fractal_creator->getPixelArray();
    QImage image(reinterpret_cast<unsigned char*>(pixel_array.data.data()), pixel_array.width, pixel_array.height, QImage::Format_RGB888);
    _item->setPixmap(QPixmap::fromImage(image));
    _scene->selectionReset();
    _scene->setSceneRect(_scene->itemsBoundingRect());
//    _scene->updateSizeRect(_item->boundingRect());
    _image_view->fitInView(_scene->sceneRect(), Qt::KeepAspectRatio);
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    _image_view->fitInView(_scene->sceneRect(), Qt::KeepAspectRatio);
    QMainWindow::resizeEvent(event);
}
