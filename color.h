/*
 * color.h
 *
 *  Created on: Aug 14, 2017
 *      Author: michael
 */

#ifndef COLOR_H_
#define COLOR_H_

#include <cstdint>

using std::uint8_t;

namespace fractal {

struct Color {
	uint8_t blue;
	uint8_t green;
	uint8_t red;
};

const Color COLOR_RED {0, 0, 255};
const Color COLOR_BLUE {255, 0, 0};
const Color COLOR_GREEN {0, 255, 0};
const Color COLOR_WHITE {255, 255, 255};
const Color COLOR_BLACK {0, 0, 0};

Color operator+(const Color& lhs, const Color& rhs);

Color operator-(const Color& lhs, const Color& rhs);

template <class T>
Color operator*(const Color& lhs, const T& rhs) {
	return {lhs.blue * rhs, lhs.green * rhs, lhs.red * rhs};
}

} /* namespace fractal */

#endif /* COLOR_H_ */
