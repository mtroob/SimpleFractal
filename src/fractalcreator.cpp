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
#include "fractal/mandelbrot.h"

namespace fractal {

FractalCreator::FractalCreator(int width, int height, std::shared_ptr<Fractal> fractal) :
		_fractal(fractal),
        _pixel_array(width, height),
		_coordinate_transformer(width, height, _fractal->LEFT_BOTTOM, _fractal->RIGHT_TOP),
		_fractal_values(width*height) {}

FractalCreator::~FractalCreator() {}

void FractalCreator::calcuclateIterationsPerPixel() {
    for (auto y = 0; y < _pixel_array.height; ++y) {
        for (auto x = 0; x < _pixel_array.width; ++x) {
			auto fractal_coords = _coordinate_transformer.apply({x, y});
            _fractal_values[y*_pixel_array.width + x] = _fractal->getFractalValue(fractal_coords);
		}
	}
}

void FractalCreator::drawFractal(std::shared_ptr<ColoringAlgorithm> coloring_algorithm) {
	coloring_algorithm->setup();

    for (auto y = 0; y < _pixel_array.height; ++y) {
        for (auto x = 0; x < _pixel_array.width; ++x) {
            auto iterations = _fractal_values[y*_pixel_array.width + x];
            _pixel_array.data[y*_pixel_array.width + x] = coloring_algorithm->getColor(iterations);
//			_bitmap.setPixel(x, y, coloring_algorithm->getColor(iterations));
		}
	}
}

void FractalCreator::addZoom(const Zoom& zoom) {
	_coordinate_transformer.addZoom(zoom);
}

bool FractalCreator::removeZoom() {
	return _coordinate_transformer.removeZoom();
}

void FractalCreator::rotate(double angle) {
	_coordinate_transformer.setRotationAngle(angle);
}

bool FractalCreator::save(FileFormat* file_format, const std::string& file_name) const {
    return file_format->convertAndWrite(_pixel_array, file_name);
}

//void FractalCreator::writeBitmap(const string& name) {
//	_bitmap.write(name);
//}

double FractalCreator::getIterationCount(const BitmapPoint& point) const {
    return _fractal_values[point.y*_pixel_array.width + point.x];
}

} /* namespace fractal */
