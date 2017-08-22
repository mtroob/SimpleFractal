/*
 * color.cpp
 *
 *  Created on: Aug 14, 2017
 *      Author: michael
 */

#include "color.h"

namespace fractal {

Color operator+(const Color& lhs, const Color& rhs) {
	auto blue = lhs.blue + rhs.blue;
//	if (blue > 255)
//		blue = 255;
	auto green = lhs.green + rhs.green;
//	if (green > 255)
//		green = 255;
	auto red = lhs.red + rhs.red;
//	if (red > 255)
//		red = 255;

	return Color{blue, green, red};
}

Color operator-(const Color& lhs, const Color& rhs) {
	auto blue = lhs.blue - rhs.blue;
//	if (blue < 0)
//		blue = 0;
	auto green = lhs.green - rhs.green;
//	if (green < 0)
//		green = 0;
	auto red = lhs.red - rhs.red;
//	if (red < 0)
//		red = 0;
	return Color{blue, green, red};
}

} /* namespace fractal */
