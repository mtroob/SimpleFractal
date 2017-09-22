QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += c++11

QMAKE_CXXFLAGS += -I /home/michael/Projects/C++/Fractal/SimpleFractal/src

HEADERS += \
    ../../SimpleFractal/src/color/color.h \
    ../../SimpleFractal/src/color/coloringalgorithm.h \
    ../../SimpleFractal/src/color/linearinterpolatedcoloring.h \
    ../../SimpleFractal/src/color/simplecoloring.h \
    ../../SimpleFractal/src/fractal/fractal.h \
    ../../SimpleFractal/src/fractal/mandelbrot.h \
    ../../SimpleFractal/src/transformation/coordinatetransformer.h \
    ../../SimpleFractal/src/transformation/zoom.h \
    ../../SimpleFractal/src/util/point.h \
    ../../SimpleFractal/src/fractalcreator.h \
    mainwindow.h \
    fractalsettingswidget.h \
    coloringsettingswidget.h \
    fractalcreatorwrapper.h \
    ../../SimpleFractal/src/output/fileformat.h \
    ../../SimpleFractal/src/output/bmp/bmpfile.h \
    ../../SimpleFractal/src/output/bmp/bmpfileheader.h \
    ../../SimpleFractal/src/output/bmp/bmpinfoheader.h \
    ../../SimpleFractal/src/util/pixelarray.h \
    fractaltransformationwidget.h \
    fractalgraphicsscene.h \
    fractalgraphicsitem.h

SOURCES += \
    ../../SimpleFractal/src/color/coloringalgorithm.cpp \
    ../../SimpleFractal/src/color/linearinterpolatedcoloring.cpp \
    ../../SimpleFractal/src/color/simplecoloring.cpp \
    ../../SimpleFractal/src/fractal/mandelbrot.cpp \
    ../../SimpleFractal/src/transformation/coordinatetransformer.cpp \
    ../../SimpleFractal/src/fractalcreator.cpp \
#    ../../SimpleFractal/src/main.cpp \
    main.cpp \
    mainwindow.cpp \
    fractalsettingswidget.cpp \
    coloringsettingswidget.cpp \
    fractalcreatorwrapper.cpp \
    ../../SimpleFractal/src/output/fileformat.cpp \
    ../../SimpleFractal/src/output/bmp/bmpfile.cpp \
    fractaltransformationwidget.cpp \
    fractalgraphicsscene.cpp \
    fractalgraphicsitem.cpp
