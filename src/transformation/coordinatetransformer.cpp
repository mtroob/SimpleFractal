/*
 * zoomlist.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: michael
 */

#include "coordinatetransformer.h"

#include <cmath>

namespace fractal {

//CoordinateTransformer::CoordinateTransformer(int width, int height, const FractalPoint& left_bottom, const FractalPoint& right_top)
//		: _bitmap_dimensions(width, height), _fractal_dimensions(right_top - left_bottom),
//		_center((right_top + left_bottom) / 2), _zoom_factor(1),
//		_rotation_cos(1), _rotation_sin(0){}

CoordinateTransformer::CoordinateTransformer() {}

void CoordinateTransformer::addZoom(const Zoom& zoom) {

    _zoom_array.push_back(zoom);

    // TODO: check values for validity (account for dimensions, Mandelbrot scale and zoom scale
    //	_center.x += (zoom._focus_point.x - _dimensions.x/2) * 3.0/_dimensions.x * _zoom_factor;
    //	_center.y += (zoom._focus_point.y - _dimensions.y/2) * 2.0/_dimensions.y * _zoom_factor;

//	_center += (zoom._focus - _bitmap_dimensions/2) * _fractal_dimensions/_bitmap_dimensions * _zoom_factor;

//	_zoom_factor *= zoom._scale;
}

bool CoordinateTransformer::removeZoom() {
    if (_zoom_array.empty()) {
//		_zoom_factor = 1;
        return false;
    }
//	auto zoom = _zoom_array.back();

//	_zoom_factor /= zoom._scale;
//	_center -= (zoom._focus - _bitmap_dimensions/2) * _fractal_dimensions/_bitmap_dimensions * _zoom_factor;

    _zoom_array.pop_back();
    return true;
}

void CoordinateTransformer::setRotationAngle(double angle) {
    _rotation_cos = cos(fmod(angle, 360) * M_PI / 180);
    _rotation_sin = sin(fmod(angle, 360) * M_PI / 180);
}

void CoordinateTransformer::initialize(int width, int height, const FractalPoint& left_bottom, const FractalPoint& right_top) {
    _bitmap_dimensions = {width, height};
    _fractal_dimensions = right_top - left_bottom;
    _center = (right_top + left_bottom) / 2;
    _zoom_factor = 1;

    for(const auto& zoom : _zoom_array) {
        _center += (zoom._focus - _bitmap_dimensions/2) * _fractal_dimensions/_bitmap_dimensions * _zoom_factor;
        _zoom_factor *= zoom._scale;
    }
}

FractalPoint CoordinateTransformer::apply(const BitmapPoint& focus) {
    auto scaled_coordinates = (focus - _bitmap_dimensions/2) * _fractal_dimensions / _bitmap_dimensions * _zoom_factor;

    auto rotated_coordinates = scaled_coordinates;

    rotated_coordinates.x = scaled_coordinates.x*_rotation_cos - scaled_coordinates.y*_rotation_sin;
    rotated_coordinates.y = scaled_coordinates.x*_rotation_sin + scaled_coordinates.y*_rotation_cos;
    return rotated_coordinates + _center;
}

bool CoordinateTransformer::defaultScale() const {
    return _zoom_array.empty();
}

} /* namespace fractal */
