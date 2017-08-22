/*
 * colorpalette.cpp
 *
 *  Created on: Aug 20, 2017
 *      Author: michael
 */

#include "colorpalette.h"

namespace fractal {

// Add a color to color palette
bool ColorPalette::addColor(double key, const Color& color) {
	return _color_map.emplace(key, color).second;
}

// Returns interpolated color from a normalized color palette
Color ColorPalette::getColor(double key) const {
	auto iterator = _color_map.lower_bound(key);
	if (iterator == _color_map.end())
		return (--iterator)->second;
	//return iterator->second;
	if (iterator->first == key)
		return iterator->second;

	auto next = *iterator;
	auto previous = *(--iterator);
	//Color color (previous.second);
	auto scale_factor = (key - previous.first) / (next.first - previous.first);
	auto blue = static_cast<uint8_t>(previous.second.blue + (next.second.blue - previous.second.blue) * scale_factor);
	auto red = static_cast<uint8_t>(previous.second.red + (next.second.red - previous.second.red) * scale_factor);
	auto green = static_cast<uint8_t>(previous.second.green + (next.second.green - previous.second.green) * scale_factor);

	Color color {blue, green, red};
//		Color color = previous.second + (next.second - previous.second) *
//				((key - previous.first) / (next.first - previous.first));
	return color;
}

} /* namespace fractal */
