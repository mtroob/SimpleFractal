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

FractalCreator::FractalCreator(int width, int height, std::shared_ptr<Fractal> fractal) :
		_width(width), _height(height),
		_bitmap(width, height),
		_fractal(fractal),
		_zoom_list(width, height, _fractal->LEFT_BOTTOM, _fractal->RIGHT_TOP),
		_fractal_values(width*height) {}

FractalCreator::~FractalCreator() {}

void FractalCreator::calcuclateIterationsPerPixel() {
	for (auto y = 0; y < _height; ++y) {
		for (auto x = 0; x < _width; ++x) {
			auto fractal_coords = _zoom_list.apply({x, y});
			_fractal_values[y*_width + x] = _fractal->getFractalValue(fractal_coords);
		}
	}
}



void FractalCreator::drawFractal(std::shared_ptr<ColoringAlgorithm> coloring_algorithm) {
	coloring_algorithm->setup();

	for (auto y = 0; y < _height; ++y) {
		for (auto x = 0; x < _width; ++x) {
			auto iterations = _fractal_values[y*_width + x];
			_bitmap.setPixel(x, y, coloring_algorithm->getColor(iterations));
		}
	}
}

void FractalCreator::addZoom(const Zoom& zoom) {
	_zoom_list.addZoom(zoom);
}

bool FractalCreator::removeZoom() {
	return _zoom_list.removeZoom();
}

void FractalCreator::rotate(double angle) {
	_zoom_list.setRotationAngle(angle);
}

void FractalCreator::writeBitmap(const string& name) {
	_bitmap.write(name);
}

double FractalCreator::getIterationCount(const BitmapPoint& point) const {
	return _fractal_values[point.y*_width + point.x];
}

} /* namespace fractal */
