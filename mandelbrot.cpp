/*
 * mandelbrot.cpp
 *
 *  Created on: Aug 1, 2017
 *      Author: michael
 */

#include <complex>
#include "mandelbrot.h"

using std::complex;

namespace fractal {

const Mandelbrot::FractalPoint Mandelbrot::LEFT_BOTTOM (-2, -1);
const Mandelbrot::FractalPoint Mandelbrot::RIGHT_TOP (1, 1);

Mandelbrot::Mandelbrot() {
	// TODO Auto-generated constructor stub

}

Mandelbrot::~Mandelbrot() {
	// TODO Auto-generated destructor stub
}

int Mandelbrot::getIterationNumber(FractalPoint coords) {
	complex<double> z = 0;
	complex<double> c {coords.x, coords.y};

	int iterations = 0;

	while (iterations < MAX_ITERATIONS) {
		z = z*z + c;

		if (abs(z) > 2) {
			break;
		}
		++iterations;
	}

	return iterations;
}

} /* namespace fractal */
