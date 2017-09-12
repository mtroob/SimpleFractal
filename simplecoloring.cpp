/*
 * SimpleColoring.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: michael
 */

#include "simplecoloring.h"

namespace fractal {

Color SimpleColoring::getColor(double key) const {
	key /= _max_iterations;
	if (key == 1.0)
		return {0, 0, 0};
	return {255*key, 255*key, 255*key};
}

} /* namespace fractal */
