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

using BitmapPoint = Point<int>;

// A Object to contain image zoom parameters
class Zoom {
public:
    Zoom(const BitmapPoint& fp, double scale) : _focus(fp), _scale(scale) {}

public:
    // The point, that will be in the center of the picture
    // after this zoom operation is applied
    BitmapPoint _focus;
    // Zoom scale (reverse multiplication factor).
    // The acceptable value ranges are:
    //      (0:1) - zoom in;
    //      1 - no zoom;
    //      (1:...) - zoom out;
	double _scale;
};

} /* namespace fractal */

#endif /* ZOOM_H_ */
