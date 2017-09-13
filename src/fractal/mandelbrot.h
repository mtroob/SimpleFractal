/*
 * mandelbrot.h
 *
 *  Created on: Aug 1, 2017
 *      Author: michael
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

#include "point.h"
#include "fractal.h"

namespace fractal {

class Mandelbrot : public Fractal {
public:

	Mandelbrot(int max_iterations, int escape_radius);

	double getFractalValue(const FractalPoint& coords) const;

	int getMaxIterations() const {
		return _max_iterations;
	}

private:
	int _max_iterations;
	int _escape_radius;
};

} /* namespace fractal */

#endif /* MANDELBROT_H_ */
