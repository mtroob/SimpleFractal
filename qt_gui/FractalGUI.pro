QT += core gui
QT += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app
CONFIG += c++11

QMAKE_CXXFLAGS += -I ../src/

HEADERS += \
    ../src/color/color.h \
    ../src/color/coloringalgorithm.h \
    ../src/color/linearinterpolatedcoloring.h \
    ../src/fractal/fractal.h \
    ../src/fractal/mandelbrot.h \
    ../src/transformation/coordinatetransformer.h \
    ../src/transformation/zoom.h \
    ../src/util/point.h \
    ../src/fractalcreator.h \
    src/mainwindow.h \
    src/fractalsettingswidget.h \
    src/coloringsettingswidget.h \
#    fractalcreatorwrapper.h \
    ../src/output/fileformat.h \
    ../src/output/bmp/bmpfile.h \
    ../src/output/bmp/bmpfileheader.h \
    ../src/output/bmp/bmpinfoheader.h \
    ../src/util/pixelarray.h \
    src/fractaltransformationwidget.h \
    src/fractalgraphicsscene.h \
    src/fractalgraphicsitem.h \
    src/fractalgraphicsview.h \
    src/colormapxmlreader.h \
    ../src/color/simplehalocoloring.h

SOURCES += \
    ../src/color/coloringalgorithm.cpp \
    ../src/color/linearinterpolatedcoloring.cpp \
    ../src/fractal/fractal.cpp \
    ../src/fractal/mandelbrot.cpp \
    ../src/transformation/coordinatetransformer.cpp \
    ../src/fractalcreator.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/fractalsettingswidget.cpp \
    src/coloringsettingswidget.cpp \
#    fractalcreatorwrapper.cpp \
    ../src/output/fileformat.cpp \
    ../src/output/bmp/bmpfile.cpp \
    src/fractaltransformationwidget.cpp \
    src/fractalgraphicsscene.cpp \
    src/fractalgraphicsitem.cpp \
    src/fractalgraphicsview.cpp \
    src/colormapxmlreader.cpp \
    ../src/color/simplehalocoloring.cpp
