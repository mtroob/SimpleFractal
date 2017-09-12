/*
 * mandelbrot.cpp
 *
 *  Created on: Aug 1, 2017
 *      Author: michael
 */

//#include <complex>
#include <cmath>

#include "mandelbrot.h"


//using std::complex;

namespace fractal {

Mandelbrot::Mandelbrot(int max_iterations, int escape_radius) :
		Fractal(FractalPoint(-2.0, -1.0), FractalPoint(1.0, 1.0)),
		_max_iterations(max_iterations), _escape_radius(escape_radius) {}

double Mandelbrot::getFractalValue(const FractalPoint& coords) const {
	auto x = 0.0;
		auto y = 0.0;

		double iterations = 0.0;

		while (iterations < _max_iterations && x*x + y*y < _escape_radius*_escape_radius) {
			auto x_temp = x*x - y*y + coords.x;
			y = 2*x*y + coords.y;
			x = x_temp;

			++iterations;
		}

	  // Uncomment this for fractional iteration count
		if (iterations < _max_iterations) {
			iterations += 1 - log2((log2(x*x + y*y)/2));
			//iterations += - log2(log2((x*x + y*y))) + 4.0;
		}

		return iterations;
}

} /* namespace fractal */
