/*
 * SimpleColoring.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: michael
 */

#include "simplecoloring.h"

namespace fractal {

void SimpleColoring::setup() {}

Color SimpleColoring::getColor(double key) const {
	if (key == 1.0)
		return {0, 0, 0};
	return {255*key, 255*key, 255*key};
}

} /* namespace fractal */
