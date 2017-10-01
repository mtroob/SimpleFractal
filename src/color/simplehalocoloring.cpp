/*
 * SimpleColoring.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: michael
 */

#include "simplehalocoloring.h"
#include "fractalcreator.h"

using std::uint8_t;

namespace fractal {

SimpleHaloColoring::SimpleHaloColoring() :
    _halo_color{255, 255, 255},
    _background_color{0, 0, 0},
    _key_scale_factor(1) {}

void SimpleHaloColoring::setup(const FractalCreator *fractal_creator) {
    _key_scale_factor = fractal_creator->getMaxIterations();
}

// Sets the color of the halo to the first color of the color map
void SimpleHaloColoring::setColorMap(const std::shared_ptr<ColorMap> color_map) {
    _halo_color = color_map->at(0.0);
}

Color SimpleHaloColoring::getColor(double key) const {
    key /= _key_scale_factor;
	if (key == 1.0)
        return _background_color;

    // the shade of the halo color is scaled by the key value
    return {
        static_cast<uint8_t>(_halo_color.red * key),
        static_cast<uint8_t>(_halo_color.green * key),
        static_cast<uint8_t>(_halo_color.blue * key)
    };
}

} /* namespace fractal */
