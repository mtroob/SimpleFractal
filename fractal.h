/*
 * fractal.h
 *
 *  Created on: Sep 12, 2017
 *      Author: michael
 */

#ifndef FRACTAL_H_
#define FRACTAL_H_

#include "point.h"

namespace fractal {

using FractalPoint = Point<double>;

// Provides abstract Fractal interface
class Fractal {
public:

	Fractal(FractalPoint left_bottom = {-1, -1}, FractalPoint right_top = {1, 1}) :
		LEFT_BOTTOM(left_bottom), RIGHT_TOP(right_top) {};
	virtual ~Fractal() {};
	virtual double getFractalValue(const FractalPoint& coords) const = 0;

	// Points to describe fractal XY scale
	const FractalPoint LEFT_BOTTOM;
	const FractalPoint RIGHT_TOP;
};

} /* namespace fractal */

#endif /* FRACTAL_H_ */
