/*
 * SimpleColoring.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: michael
 */

#include "simplecoloring.h"

using std::uint8_t;

namespace fractal {

Color SimpleColoring::getColor(double key) const {
	key /= _max_iterations;
	if (key == 1.0)
		return {0, 0, 0};
    return {
        static_cast<uint8_t>(255*key),
        static_cast<uint8_t>(255*key),
        static_cast<uint8_t>(255*key)
    };
}

} /* namespace fractal */
