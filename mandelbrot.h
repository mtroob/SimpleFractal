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

	int getIterationCount(const FractalPoint& coords);
	double getNormalizedIterationCount(const FractalPoint& coords);

public:
	const int MAX_ITERATIONS = 1000;
	const FractalPoint LEFT_BOTTOM {-2.0, -1.0};
	const FractalPoint RIGHT_TOP {1.0, 1.0};
};

} /* namespace fractal */

#endif /* MANDELBROT_H_ */
