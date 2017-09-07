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

//const Mandelbrot::FractalPoint Mandelbrot::LEFT_BOTTOM (-2.0, -1.0);
//const Mandelbrot::FractalPoint Mandelbrot::RIGHT_TOP (1.0, 1.0);

Mandelbrot::Mandelbrot(int max_iterations) :
		_max_iterations(max_iterations) {}

//int Mandelbrot::getIterationNumber(FractalPoint coords) {
//	complex<double> z = {0.0, 0.0};
//	complex<double> c {coords.x, coords.y};
//
//	int iterations = 0;
//
//	while (iterations < MAX_ITERATIONS && std::abs(z) < 2.0) {
//		z = z*z + c;
//
//		++iterations;
//	}
//
//	return iterations;
//}

int Mandelbrot::getIterationCount(const FractalPoint& coords) {
	auto x = 0.0;
	auto y = 0.0;

	int iterations = 0;

	while (iterations < _max_iterations && x*x + y*y < 2*2) {
		auto x_temp = x*x - y*y + coords.x;
		y = 2*x*y + coords.y;
		x = x_temp;

		++iterations;
	}

	return iterations;
}

double Mandelbrot::getNormalizedIterationCount(const FractalPoint& coords) {
	auto x = 0.0;
	auto y = 0.0;

	double iterations = 0.0;

	while (iterations < _max_iterations && x*x + y*y < 2*2) {
		auto x_temp = x*x - y*y + coords.x;
		y = 2*x*y + coords.y;
		x = x_temp;

		++iterations;
	}

//  // Uncomment this for fractional iteration count
//	if (iterations < MAX_ITERATIONS) {
//		iterations += 1 - log2((log2(x*x + y*y)/2));
//		//iterations += - log2(log2((x*x + y*y))) + 4.0;
//	}

	return iterations;
}

} /* namespace fractal */
