#include <QDockWidget>
#include <QPixmap>
#include <QLabel>
#include <QImage>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "mainwindow.h"
#include "fractalsettingswidget.h"
#include "coloringsettingswidget.h"
#include "fractaltransformationwidget.h"
#include "fractalgraphicsscene.h"
#include "fractalgraphicsitem.h"

// for test
#include <memory>
#include "fractal/mandelbrot.h"
#include "fractalcreator.h"
#include "color/linearinterpolatedcoloring.h"
#include "transformation/coordinatetransformer.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    _image_view = new QGraphicsView();
    _scene = new FractalGraphicsScene();
    _item = new FractalGraphicsItem();
    _item->setAcceptHoverEvents(true);
    _scene->addItem(_item);

    _image_view->setScene(_scene);

    this->setCentralWidget(_image_view);

    createDockWindows();

    const int WIDTH {900};
    const int HEIGHT {600};

    _fractal_creator.reset(new FractalCreator(WIDTH, HEIGHT, _fractal_settings->getFractal()));

//    _fractal_creator->addZoom(Zoom({WIDTH/4, HEIGHT/2}, 0.5));
//    _fractal_creator->addZoom(fractal::Zoom({WIDTH/2, 3*HEIGHT/4}, 0.5));
//    _fractal_creator->addZoom(fractal::Zoom({WIDTH/2, HEIGHT/2}, 0.5));

    connect(_fractal_settings, SIGNAL(settingsChanged()), this, SLOT(recalculate()));

    connect(_coloring_settings, SIGNAL(newColoring()), this, SLOT(updateImage()));

    connect(_transformation_settings, SIGNAL(transformationApplied()), this, SLOT(recalculate()));

    //recalculate();
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
    _item->setPixmap(QPixmap::fromImage(image.mirrored(false, true)));
    _scene->update();
    _image_view->fitInView(_scene->sceneRect(), Qt::KeepAspectRatio);

//    emit dummySignal();
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    _image_view->fitInView(_scene->sceneRect(), Qt::KeepAspectRatio);
    QMainWindow::resizeEvent(event);
}
