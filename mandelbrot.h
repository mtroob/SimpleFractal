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

	Mandelbrot(int max_iterations);

	int getIterationCount(const FractalPoint& coords);
	double getNormalizedIterationCount(const FractalPoint& coords);

	int getMaxIterations() const {
		return _max_iterations;
	}
	const FractalPoint LEFT_BOTTOM {-2.0, -1.0};
	const FractalPoint RIGHT_TOP {1.0, 1.0};

private:
	int _max_iterations;
};

} /* namespace fractal */

#endif /* MANDELBROT_H_ */
