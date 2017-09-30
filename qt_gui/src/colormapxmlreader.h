#ifndef COLORMAPXMLREADER_H
#define COLORMAPXMLREADER_H

#include <map>

#include <QXmlStreamReader>

#include "color/color.h"

using ColorMap = std::map<double, fractal::Color>;

class ColorMapXmlReader
{
public:
    ColorMapXmlReader(ColorMap* color_map);
    bool read(QIODevice* device);
    QString getName() const;

private:
    ColorMap* _color_map;
    QString* _name;
    QXmlStreamReader _xml_reader;

    void readColorMap();
    fractal::Color readColor();
};

#endif // COLORMAPXMLREADER_H
