/*
 * zoomlist.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: michael
 */

#include "zoomlist.h"

namespace fractal {

ZoomList::ZoomList(int width, int height, const FractalPoint& left_bottom, const FractalPoint& right_top)
		: _bitmap_dimensions(width, height), _fractal_dimensions(right_top - left_bottom),
		_center((right_top + left_bottom) / 2), _zoom_factor(1) {}

void ZoomList::zoomIn(const Zoom& zoom) {

	_zoom_array.push_back(zoom);

	// TODO: check values for validity (account for dimensions, Mandelbrot scale and zoom scale
	//	_center.x += (zoom._focus_point.x - _dimensions.x/2) * 3.0/_dimensions.x * _zoom_factor;
	//	_center.y += (zoom._focus_point.y - _dimensions.y/2) * 2.0/_dimensions.y * _zoom_factor;

	_center += (zoom._focus - _bitmap_dimensions/2) * _fractal_dimensions/_bitmap_dimensions * _zoom_factor;

	_zoom_factor *= zoom._scale;
}

bool ZoomList::zoomOut() {
	if (_zoom_array.empty())
		return false;
	auto zoom = _zoom_array.back();

	_zoom_factor /= zoom._scale;
	_center -= (zoom._focus - _bitmap_dimensions/2) * _fractal_dimensions/_bitmap_dimensions * _zoom_factor;

	_zoom_array.pop_back();
	return true;
}

ZoomList::FractalPoint ZoomList::getScaledCoordinates(const BitmapPoint& focus) {
	//	FractalPoint fractal_coords (focus - _dimensions/2);
	//	fractal_coords *= _fractal_scale/_dimensions;
	//	fractal_coords *= _zoom_factor;
	//	fractal_coords += _center;
	//	return fractal_coords;

	return (focus - _bitmap_dimensions/2) * _fractal_dimensions/_bitmap_dimensions * _zoom_factor + _center;
}

} /* namespace fractal */
