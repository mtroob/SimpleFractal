/*
 * mandelbrot.h
 *
 *  Created on: Aug 1, 2017
 *      Author: michael
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace fractal {

class Mandelbrot {
public:
	Mandelbrot();
	virtual ~Mandelbrot();

	static int iterate(double x, double y);

public:
	static const int MAX_ITERATIONS = 1000;
};

} /* namespace fractal */

#endif /* MANDELBROT_H_ */
