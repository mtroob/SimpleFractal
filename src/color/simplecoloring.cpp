/*
 * SimpleColoring.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: michael
 */

#include "simplecoloring.h"
#include "fractalcreator.h"

using std::uint8_t;

namespace fractal {

SimpleColoring::SimpleColoring() :
    _halo_color{255, 255, 255},
    _background_color{0, 0, 0},
    _key_scale_factor(1) {}

void SimpleColoring::setup(const FractalCreator *fractal_creator) {
    _key_scale_factor = fractal_creator->getMaxIterations();
}

void SimpleColoring::setColorMap(const std::shared_ptr<ColorMap> color_map) {
    _halo_color = color_map->at(0.0);
}

Color SimpleColoring::getColor(double key) const {
    key /= _key_scale_factor;
	if (key == 1.0)
        return _background_color;

    return {
        static_cast<uint8_t>(_halo_color.red * key),
        static_cast<uint8_t>(_halo_color.green * key),
        static_cast<uint8_t>(_halo_color.blue * key)
    };
}

} /* namespace fractal */
