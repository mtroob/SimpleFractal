#include <QApplication>
#include "mainwindow.h"
//#include "fractalcreatorwrapper.h"

// for old_main
#include <iostream>
#include <limits>
#include <memory>
#include <chrono>
#include <exception>
#include <string>
#include <algorithm>

#include "fractalcreator.h"
#include "color/linearinterpolatedcoloring.h"
#include "color/simplehalocoloring.h"
#include "fractal/mandelbrot.h"
#include "output/bmp/bmpfile.h"
//

#include <QXmlStreamReader>
#include <QDebug>

void old_main();
void drawFractal(FractalCreator& fc, std::shared_ptr<ColoringAlgorithm> coloring_algorithm, std::shared_ptr<CoordinateTransformer> transform, const std::string& file_name);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mw;
    mw.show();
    mw.showMaximized();
    mw.setWindowTitle("Fractal");



//    FractalCreatorWrapper fcw;

//    QObject::connect(&mw, SIGNAL(dummySignal()), &fcw, SLOT(dummySlot()));

    // uncomment to check plain fractal functionality
//    old_main();

    return a.exec();
}

void old_main() {
    std::cout << "Fractal generation started" << std::endl;
    try {
        const int WIDTH {1800};
        const int HEIGHT {1200};

        const int MAX_ITERATIONS {1000};

        std::shared_ptr<Mandelbrot> fractal{new Mandelbrot (MAX_ITERATIONS, 2)};

        FractalCreator fc(WIDTH, HEIGHT, fractal);

        std::shared_ptr<SimpleHaloColoring> simple_coloring {new SimpleHaloColoring()};

        std::shared_ptr<LinearInterpolatedColoring> linear_coloring {new LinearInterpolatedColoring()};

        std::shared_ptr<ColorMap> color_map {new ColorMap()};

        color_map->emplace(0.0, Color{0, 7, 100});
        color_map->emplace(0.02, Color{62, 230, 120});
        color_map->emplace(0.08, Color{50, 107, 203});
        color_map->emplace(0.32, Color{237, 255, 255});
        color_map->emplace(0.6425, Color{255, 170, 0});
        color_map->emplace(0.8575, Color{200, 2, 0});
        color_map->emplace(1, Color{0, 0, 0});
        linear_coloring->setColorMap(color_map);
//        linear_coloring->addColor(0.0, {100, 7, 0});
//        linear_coloring->addColor(0.02, {120, 230, 62});
//        linear_coloring->addColor(0.08, {203, 107, 50});
//        linear_coloring->addColor(0.32, {255, 255, 237});
//        linear_coloring->addColor(0.6425, {0, 170, 255});
//        linear_coloring->addColor(0.8575, {0, 2, 200});
//        linear_coloring->addColor(1, {0, 0, 0});

    //		drawFractalCircle(fc, linear_coloring, "rotation.bmp");

        std::shared_ptr<CoordinateTransformer> transform {new CoordinateTransformer};

        drawFractal(fc, linear_coloring, transform, "bitmap_1.bmp");

    //		fc.addZoom(Zoom({759, 1200-490}, 0.001));

        transform->addZoom(Zoom({WIDTH/4, HEIGHT/2}, 0.5));
        transform->addZoom(Zoom({WIDTH/2, 3*HEIGHT/4}, 0.5));
        transform->addZoom(Zoom({WIDTH/2, HEIGHT/2}, 0.5));

        drawFractal(fc, linear_coloring, transform, "bitmap_2.bmp");

        transform->addZoom(Zoom({3*WIDTH/4, HEIGHT/2}, 0.5));
        transform->addZoom(Zoom({WIDTH/2, 2*HEIGHT/3}, 0.2));
        transform->addZoom(Zoom({WIDTH/3, HEIGHT/2}, 0.1));
        transform->addZoom(Zoom({WIDTH/2, 2*HEIGHT/3}, 0.2));

        drawFractal(fc, linear_coloring, transform, "bitmap_3.bmp");

        while(transform->removeZoom());

        drawFractal(fc, simple_coloring, transform, "bitmap_4.bmp");

        std::cout << "Fractal generation finished" << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}

void drawFractal(FractalCreator& fc,
                 std::shared_ptr<ColoringAlgorithm> coloring_algorithm,
                 std::shared_ptr<CoordinateTransformer> transform,
                 const std::string& file_name) {
    using std::chrono::system_clock;
    using std::chrono::duration;

    system_clock::time_point start_point;
    duration<double> elapsed;

    start_point = system_clock::now();
    fc.calculateValues(transform);
    //fc.generateIterationHistogram();
    elapsed = system_clock::now() - start_point;
    std::cout << "calcuclateIterationsPerPixel: " << elapsed.count() << std::endl;

    start_point = system_clock::now();
    fc.drawFractal(coloring_algorithm);
    elapsed = system_clock::now() - start_point;
    std::cout << "drawFractal: " << elapsed.count() << std::endl;

    start_point = system_clock::now();
    BMPFile file{};
    fc.save(&file, file_name);
    //fc.writeBitmap(file_name);
    elapsed = system_clock::now() - start_point;
    std::cout << "writeBitmap: " << elapsed.count() << std::endl;
}
