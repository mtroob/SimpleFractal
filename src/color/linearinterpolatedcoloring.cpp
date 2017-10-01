/*
 * linearinterpolatedcoloring.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: michael
 */

#include "linearinterpolatedcoloring.h"
#include "fractalcreator.h"

namespace fractal {

void LinearInterpolatedColoring::setColorMap(const std::shared_ptr<ColorMap> color_map) {
    _color_map = color_map;
}

void LinearInterpolatedColoring::setup(const FractalCreator *fractal_creator) {
    _key_scale_factor = fractal_creator->getMaxIterations();
}

Color LinearInterpolatedColoring::getColor(double key) const {
    key /= _key_scale_factor;
	// look for key in color map
    auto iterator = _color_map->lower_bound(key);
    if (iterator == _color_map->end())
		return (--iterator)->second;
	if (iterator->first == key)
		return iterator->second;

	// the needed color is between two color map entries
	auto next = *iterator;
	auto previous = *(--iterator);

    // linear interpolation of color components
	auto scale_factor = (key - previous.first) / (next.first - previous.first);
	auto blue = static_cast<uint8_t>(previous.second.blue + (next.second.blue - previous.second.blue) * scale_factor);
	auto red = static_cast<uint8_t>(previous.second.red + (next.second.red - previous.second.red) * scale_factor);
	auto green = static_cast<uint8_t>(previous.second.green + (next.second.green - previous.second.green) * scale_factor);

    return {red, green, blue};
}

} /* namespace fractal */
