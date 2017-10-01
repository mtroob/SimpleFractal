/*
 * mandelbrot.cpp
 *
 *  Created on: Aug 1, 2017
 *      Author: michael
 */

#include <cmath>

#include "mandelbrot.h"

namespace fractal {

Mandelbrot::Mandelbrot(int max_iterations, int escape_radius) :
        _max_iterations(max_iterations), _escape_radius(escape_radius) {}

double Mandelbrot::calculateValue(const FractalPoint& coords) const {
	auto x = 0.0;
    auto y = 0.0;
    auto iterations = 0.0;

    // Count the number of iterations to "escape"
    while ((iterations < _max_iterations)
           && (x*x + y*y < _escape_radius*_escape_radius)) {
        auto x_temp = x*x - y*y + coords.x;
        y = 2*x*y + coords.y;
        x = x_temp;
        ++iterations;
    }

    // Calculate the fractional part of iteration number
    // to smooth fractal visual representation
    if (iterations < _max_iterations) {
        // TODO: experiment with different ways to
        // implement fractional iteration count
        iterations += 1 - log2((log2(x*x + y*y)/2));
        //iterations += - log2(log2((x*x + y*y))) + 4.0;
    }

    return iterations;
}

FractalPoint Mandelbrot::leftBottom() const {
    return LEFT_BOTTOM;
}

FractalPoint Mandelbrot::rightTop() const {
    return RIGHT_TOP;
}

int Mandelbrot::maxValue() const {
    return _max_iterations;
}

} /* namespace fractal */
