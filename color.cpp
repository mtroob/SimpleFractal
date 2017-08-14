/*
 * color.cpp
 *
 *  Created on: Aug 14, 2017
 *      Author: michael
 */

#include "color.h"

namespace fractal {

Color operator+(const Color& lhs, const Color& rhs) {
	return Color{lhs.blue + rhs.blue, lhs.green + rhs.green, lhs.red + rhs.red};
}

Color operator-(const Color& lhs, const Color& rhs) {
	return Color{lhs.blue - rhs.blue, lhs.green - rhs.green, lhs.red - rhs.red};
}

} /* namespace fractal */
