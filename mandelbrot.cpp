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

Mandelbrot::Mandelbrot() {
	// TODO Auto-generated constructor stub

}

Mandelbrot::~Mandelbrot() {
	// TODO Auto-generated destructor stub
}

int Mandelbrot::iterate(double x, double y) {
	complex<double> z = 0;
	complex<double> c {x, y};

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
