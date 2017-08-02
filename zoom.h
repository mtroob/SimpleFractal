/*
 * zoom.h
 *
 *  Created on: Aug 2, 2017
 *      Author: michael
 */

#ifndef ZOOM_H_
#define ZOOM_H_

namespace fractal {

class Zoom {
public:
	Zoom(int x, int y, double scale) : _x(x), _y(y), _scale(scale) {}
public:
	int _x;
	int _y;
	double _scale;
};

} /* namespace fractal */

#endif /* ZOOM_H_ */
