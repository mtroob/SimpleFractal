/*
 * fractalcreator.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: michael
 */
#include <math.h>
#include <algorithm>

#include <iostream>

#include "fractalcreator.h"
#include "mandelbrot.h"

namespace fractal {

FractalCreator::FractalCreator(int width, int height) :
		_width(width), _height(height),
		_bitmap(width, height),
		_fractal(),
		_zoom_list(width, height, _fractal.LEFT_BOTTOM, _fractal.RIGHT_TOP),
		_histogram(_fractal.MAX_ITERATIONS, 0),
		_iterations(width*height) {}

FractalCreator::~FractalCreator() {

}

void FractalCreator::calcuclateIterationsPerPixel() {
	for (auto y = 0; y < _height; ++y) {
		for (auto x = 0; x < _width; ++x) {
			auto fractal_coords = _zoom_list.getScaledCoordinates({x, y});

			auto iterations = _fractal.getNormalizedIterationCount(fractal_coords);

			_iterations[y*_width + x] = iterations;
		}
	}
}

void FractalCreator::generateIterationHistogram() {
	// clear previous histogram
	for (auto& column : _histogram)
		column = 0;

	for (auto y = 0; y < _height; ++y) {
		for (auto x = 0; x < _width; ++x) {
			auto iterations = _iterations[y*_width + x];
			if (iterations < _fractal.MAX_ITERATIONS)
				++_histogram[iterations];
		}
	}
	std::cout << "Histogram: ";
	std::cout << std::count_if(_histogram.begin(), _histogram.end(), [](uint x){ return x > 0; });
	std::cout << std::endl;
}

//void FractalCreator::calcualtePixelsPerColorRange() {
//	// clear
//	for (auto& pixel_number : _pixels_in_range)
//		pixel_number = 0;
//
//	int range_number = 1;
//	for (uint i = 0; i < Mandelbrot::MAX_ITERATIONS; ++i) {
//		if (i >= _ranges[range_number])
//			++range_number;
//
//		_pixels_in_range[range_number-1] += _histogram[i];
//	}
//}

void FractalCreator::drawFractal() {

	uint total = 0;
	for(auto i = 0; i < _fractal.MAX_ITERATIONS; ++i)
		total += _histogram[i];

	for (auto y = 0; y < _height; ++y) {
		for (auto x = 0; x < _width; ++x) {
			auto iterations = _iterations[y*_width + x];
			Color cl = {0, 0, 0};

			if (iterations < _fractal.MAX_ITERATIONS) {
				double hue = 0.0;
//				auto range = getRange(iterations);
//
//				for (auto i = _ranges[range]; i <= iterations; ++i)
//					hue += _histogram[i];
//				hue /= _pixels_in_range[range];
//
//				cl = _colors[range] + color_diff*hue;

				for (auto i = 0; i < iterations; ++i)
					hue += _histogram[i];
				hue /= total;
//
//				//hue = static_cast<double>(iterations)/Mandelbrot::MAX_ITERATIONS;
//
//				hue_set_tmp.insert(hue);

//				cl = _color_palette.getColor(hue);
				cl = _color_palette.getColor(iterations, _fractal.MAX_ITERATIONS);
//				cl.blue = pow(255, hue);

			}
			_bitmap.setPixel(x, y, cl);
		}
	}

	for (auto hue : hue_set_tmp)
		std::cout << hue << " ";
	std::cout << std::endl;
}

void FractalCreator::addZoom(const Zoom& zoom) {
	_zoom_list.zoomIn(zoom);
}

bool FractalCreator::removeZoom() {
	return _zoom_list.zoomOut();
}

void FractalCreator::addRange(double range_end, const Color& color) {
	_ranges.push_back(range_end * _fractal.MAX_ITERATIONS);
	_colors.push_back(color);

	if (_ranges.size() > 1)
		_pixels_in_range.push_back(0);

	_color_palette.addColor(range_end, color);
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
