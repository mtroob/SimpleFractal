/*
 * zoomlist.h
 *
 *  Created on: Aug 2, 2017
 *      Author: michael
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>

#include "point.h"
#include "zoom.h"

using std::vector;

namespace fractal {

// Implements zooming in/out algorithm and converts bitmap pixel coordinates
// into fractal coordinates
class ZoomList {
public:

	using FractalPoint = Point<double>;
	using BitmapPoint = Point<int>;

	// Costructs ZoomList object using information on bitmap dimensions
	// and fractal x/y scale
	ZoomList(int width, int height, const FractalPoint& left_bottom, const FractalPoint& right_top);

	// Performs zoom in on a fractal.
	void zoomIn(const Zoom& zoom);

	// Performs zoom out on a fractal (cancels the last applied zoom).
	// Returns:	true if zooming out was successful
	//			false if zooming out is impossible (_zoom_array is empty)
	bool zoomOut();

	// Converts bitmap pixel coordinates to fractal coordinates
	// according to fractal scale and applied zoom.
	FractalPoint getScaledCoordinates(const BitmapPoint& focus);

private:

	BitmapPoint _bitmap_dimensions;
	FractalPoint _fractal_dimensions;
	FractalPoint _center;
	double _zoom_factor;
	vector<Zoom> _zoom_array;
};

} /* namespace fractal */

#endif /* ZOOMLIST_H_ */
