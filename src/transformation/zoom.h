/*
 * zoom.h
 *
 *  Created on: Aug 2, 2017
 *      Author: michael
 */

#ifndef ZOOM_H_
#define ZOOM_H_

#include "util/point.h"

namespace fractal {

class Zoom {
public:
    using FocusPoint = Point<int>;

	Zoom(const FocusPoint& fp, double scale) : _focus(fp), _scale(scale) {}

public:
	FocusPoint _focus;
	double _scale;
};

} /* namespace fractal */

#endif /* ZOOM_H_ */
