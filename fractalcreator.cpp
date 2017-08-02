/*
 * fractalcreator.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: michael
 */
#include <math.h>

#include "fractalcreator.h"
#include "mandelbrot.h"

namespace fractal {

FractalCreator::FractalCreator(int width, int height) :
		_width(width), _height(height),
		_bitmap(width, height), _zoom_list(width, height),
		_histogram(new int[Mandelbrot::MAX_ITERATIONS]{0}),
		_fractal (new int[width*height]{0}) {}

FractalCreator::~FractalCreator() {

}

void FractalCreator::calculateIteration() {
	for (int y = 0; y < _height; ++y) {
		for (int x = 0; x < _width; ++x) {
			auto fractal_coords = _zoom_list.ZoomIn(x, y);

			int iterations = Mandelbrot::iterate(fractal_coords.first, fractal_coords.second);

			if (iterations != Mandelbrot::MAX_ITERATIONS)
				++_histogram[iterations];

			_fractal[y*_width + x] = iterations;
		}
	}
}

void FractalCreator::drawFractal() {
	int total = 0;
	for(auto i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i)
		total += _histogram[i];

	for (int y = 0; y < _height; ++y) {
		for (int x = 0; x < _width; ++x) {
			int iterations = _fractal[y*_width + x];
			Color cl{0, 0, 0};
			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				double hue = 0.0;
				for (auto i = 0; i <= iterations; ++i)
					hue += _histogram[i];
				hue /= total;
				cl.blue = pow(255, hue);
			}
			_bitmap.setPixel(x, y, cl);
		}
	}
}

void FractalCreator::addZoom(const Zoom& zoom) {
	_zoom_list.add(zoom);
}

void FractalCreator::writeBitmap(const string& name) {
	_bitmap.write(name);
}

} /* namespace fractal */
