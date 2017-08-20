/*
 * fractalcreator.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: michael
 */
#include <math.h>
#include <algorithm>

#include "fractalcreator.h"
#include "mandelbrot.h"

namespace fractal {

FractalCreator::FractalCreator(int width, int height) :
		_width(width), _height(height),
		_bitmap(width, height),
		_zoom_list(width, height, Mandelbrot::LEFT_BOTTOM, Mandelbrot::RIGHT_TOP),
		_histogram(Mandelbrot::MAX_ITERATIONS, 0),
		_fractal(width*height) {}

FractalCreator::~FractalCreator() {

}

void FractalCreator::calcuclateIterationsPerPixel() {
	// clear
	for (auto& column : _histogram)
		column = 0;

	for (int y = 0; y < _height; ++y) {
		for (int x = 0; x < _width; ++x) {
			auto fractal_coords = _zoom_list.getScaledCoordinates({x, y});

			uint iterations = Mandelbrot::getIterationNumber(fractal_coords);

			if (iterations != Mandelbrot::MAX_ITERATIONS)
				++_histogram[iterations];

			_fractal[y*_width + x] = iterations;
		}
	}
}

void FractalCreator::calcualtePixelsPerColorRange() {
	// clear
	for (auto& pixel_number : _pixels_in_range)
		pixel_number = 0;

	int range_number = 1;
	for (uint i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
		if (i >= _ranges[range_number])
			++range_number;

		_pixels_in_range[range_number-1] += _histogram[i];
	}
}

void FractalCreator::drawFractal() {

	int total = 0;
	for(auto i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i)
		total += _histogram[i];

	for (int y = 0; y < _height; ++y) {
		for (int x = 0; x < _width; ++x) {
			uint iterations = _fractal[y*_width + x];
			Color cl = {0, 0, 0};

			if (iterations != Mandelbrot::MAX_ITERATIONS) {
				double hue = 0.0;
				auto range = getRange(iterations);

				auto& start_color = _colors[range];
				auto& end_color = _colors[range+1];
				auto color_diff = end_color - start_color;

				for (uint i = _ranges[range]; i <= iterations; ++i)
					hue += _histogram[i];
				hue /= _pixels_in_range[range];

				cl = start_color + color_diff*hue;

//				for (uint i = 0; i <= iterations; ++i)
//					hue += _histogram[i];
//				hue /= total;
//
//				cl.blue = hue*255;
			}
			_bitmap.setPixel(x, y, cl);
		}
	}
}

void FractalCreator::addZoom(const Zoom& zoom) {
	_zoom_list.zoomIn(zoom);
}

bool FractalCreator::removeZoom() {
	return _zoom_list.zoomOut();
}

void FractalCreator::addRange(float range_end, const Color& color) {
	_ranges.push_back(range_end * Mandelbrot::MAX_ITERATIONS);
	_colors.push_back(color);

	if (_ranges.size() > 1)
		_pixels_in_range.push_back(0);
}

uint FractalCreator::getRange(uint iterations) const {
	uint range = 0;

	for(uint i = 1; i < _ranges.size(); ++i) {
		range = i - 1;
		if (_ranges[i] > iterations)
			break;
	}

	return range;
}

void FractalCreator::writeBitmap(const string& name) {
	_bitmap.write(name);
}

} /* namespace fractal */
