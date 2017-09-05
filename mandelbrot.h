/*
 * mandelbrot.h
 *
 *  Created on: Aug 1, 2017
 *      Author: michael
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

#include "point.h"

namespace fractal {

class Mandelbrot {
public:

	using FractalPoint = Point<double>;

	Mandelbrot();
	virtual ~Mandelbrot();

	static int getIterationCount(const FractalPoint& coords);
	static double getNormalizedIterationCount(const FractalPoint& coords);

public:
	static const int MAX_ITERATIONS = 1000;
	static const FractalPoint LEFT_BOTTOM;
	static const FractalPoint RIGHT_TOP;
};

} /* namespace fractal */

#endif /* MANDELBROT_H_ */
