/*
 * zoomlist.h
 *
 *  Created on: Aug 2, 2017
 *      Author: michael
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility>

#include "zoom.h"

using std::vector;
using std::pair;

namespace fractal {

class ZoomList {
public:
	ZoomList(int width, int height);
	void add(const Zoom& zoom);
	pair<double, double> ZoomIn(int x, int y);

private:
	int _width;
	int _height;
	double _x_center;
	double _y_center;
	double _scale;
	vector<Zoom> _zoom_array;
};

} /* namespace fractal */

#endif /* ZOOMLIST_H_ */
