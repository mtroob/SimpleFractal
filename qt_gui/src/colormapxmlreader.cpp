#include "colormapxmlreader.h"

#include <QDebug>

ColorMapXmlReader::ColorMapXmlReader(ColorMap* color_map)
{
    _color_map = color_map;
}

bool ColorMapXmlReader::read(QIODevice *device) {
    _xml_reader.setDevice(device);

    if (_xml_reader.readNextStartElement()) {
        if (_xml_reader.name() == "color_map" &&
                _xml_reader.attributes().hasAttribute("name")) {
            _name = new QString(_xml_reader.attributes().value("name").toString());
            readColorMap();
        }
        else
            _xml_reader.raiseError(QObject::tr("Not a color preset file"));
    }
    return !_xml_reader.error();
}

void ColorMapXmlReader::readColorMap() {
    while (_xml_reader.readNextStartElement()) {
        if (_xml_reader.name() == "color_entry"
                && _xml_reader.attributes().hasAttribute("key")
                && _xml_reader.attributes().hasAttribute("red")
                && _xml_reader.attributes().hasAttribute("green")
                && _xml_reader.attributes().hasAttribute("blue")) {
            // read color entry attributes
            double key = _xml_reader.attributes().value("key").toDouble();
            uint8_t red = _xml_reader.attributes().value("red").toInt();
            uint8_t green = _xml_reader.attributes().value("green").toInt();
            uint8_t blue = _xml_reader.attributes().value("blue").toInt();
            // add color to color map
            _color_map->emplace(key, fractal::Color{red, green, blue});
            _xml_reader.skipCurrentElement();
        }
        else
            _xml_reader.raiseError(QObject::tr("Incorrect color element"));
    }
}

QString ColorMapXmlReader::getName() const {
    return *_name;
}
