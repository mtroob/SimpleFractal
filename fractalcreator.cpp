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

FractalCreator::FractalCreator(int width, int height, std::shared_ptr<ColoringAlgorithm> coloring_algorithm) :
		_width(width), _height(height),
		_bitmap(width, height),
		_fractal(1000),
		_zoom_list(width, height, _fractal.LEFT_BOTTOM, _fractal.RIGHT_TOP),
		_histogram(_fractal.getMaxIterations(), 0),
		_iterations(width*height),
		_coloring_algorithm(coloring_algorithm) {}

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

// TODO: should be moved to appropriate coloring algorithm
void FractalCreator::generateIterationHistogram() {
	// clear previous histogram
	for (auto& column : _histogram)
		column = 0;

	for (auto y = 0; y < _height; ++y) {
		for (auto x = 0; x < _width; ++x) {
			auto iterations = _iterations[y*_width + x];
			if (iterations < _fractal.getMaxIterations())
				++_histogram[iterations];
		}
	}
	std::cout << "Histogram: ";
	std::cout << std::count_if(_histogram.begin(), _histogram.end(), [](uint x){ return x > 0; });
	std::cout << std::endl;
}

void FractalCreator::drawFractal() {

	_coloring_algorithm->setup();

//	uint total = 0;
//	for(auto i = 0; i < _fractal.getMaxIterations(); ++i)
//		total += _histogram[i];

	for (auto y = 0; y < _height; ++y) {
		for (auto x = 0; x < _width; ++x) {
			auto iterations = _iterations[y*_width + x];

			_bitmap.setPixel(x, y, _coloring_algorithm->getColor(iterations/_fractal.getMaxIterations()));

//			Color cl = {0, 0, 0};
//
//
//
//			if (iterations < _fractal.getMaxIterations()) {
//				double hue = 0.0;
////				auto range = getRange(iterations);
////
////				for (auto i = _ranges[range]; i <= iterations; ++i)
////					hue += _histogram[i];
////				hue /= _pixels_in_range[range];
////
////				cl = _colors[range] + color_diff*hue;
//
//				for (auto i = 0; i < iterations; ++i)
//					hue += _histogram[i];
//				hue /= total;
////
////				//hue = static_cast<double>(iterations)/Mandelbrot::MAX_ITERATIONS;
//
////				cl = _color_palette.getColor(hue);
//				cl = _color_palette.getColor(iterations/_fractal.getMaxIterations());
////				cl.blue = pow(255, hue);
//
//			}
//			_bitmap.setPixel(x, y, cl);
		}
	}
}

void FractalCreator::addZoom(const Zoom& zoom) {
	_zoom_list.zoomIn(zoom);
}

bool FractalCreator::removeZoom() {
	return _zoom_list.zoomOut();
}

void FractalCreator::setColoringAlgorithm(std::shared_ptr<ColoringAlgorithm> coloring_algorithm) {
	_coloring_algorithm = coloring_algorithm;
}

void FractalCreator::writeBitmap(const string& name) {
	_bitmap.write(name);
}

} /* namespace fractal */
