/*
 * zoomlist.cpp
 *
 *  Created on: Aug 2, 2017
 *      Author: michael
 */

#include "zoomlist.h"

namespace fractal {

ZoomList::ZoomList(int width, int height) : _width(width), _height(height),
		_x_center(0), _y_center(0), _scale(1) {}

void ZoomList::add(const Zoom& zoom) {
	_zoom_array.push_back(zoom);

	_x_center += (zoom._x - _width/2)*_scale;
	_y_center += (zoom._y - _height/2)*_scale;

	_scale *= zoom._scale;
}

pair<double, double> ZoomList::ZoomIn(int x, int y) {
	double x_fractal = (x - _width/2)*_scale + _x_center;
	double y_fractal = (y - _height/2)*_scale + _y_center;
	return pair<double, double>(x_fractal, y_fractal);
}

} /* namespace fractal */
