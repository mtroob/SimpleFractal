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

void SimpleColoring::setup(const FractalCreator *fractal_creator) {
    _key_scale_factor = fractal_creator->getMaxIterations();
}

Color SimpleColoring::getColor(double key) const {
    key /= _key_scale_factor;
	if (key == 1.0)
		return {0, 0, 0};
    return {
        static_cast<uint8_t>(255*key),
        static_cast<uint8_t>(255*key),
        static_cast<uint8_t>(255*key)
    };
}

} /* namespace fractal */
