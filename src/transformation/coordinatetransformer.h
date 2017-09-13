/*
 * zoomlist.h
 *
 *  Created on: Aug 2, 2017
 *      Author: michael
 */

#ifndef COORDINATETRANSFORMER_H_
#define COORDINATETRANSFORMER_H_

#include <vector>

#include "util/point.h"
#include "transformation/zoom.h"

namespace fractal {

using FractalPoint = Point<double>;
using BitmapPoint = Point<int>;

// Converts bitmap pixel coordinates into fractal coordinates
// Implements zooming in/out and rotation
class CoordinateTransformer {
public:

	// Costructs ZoomList object using information on bitmap dimensions
	// and fractal x/y scale
	CoordinateTransformer(int width, int height, const FractalPoint& left_bottom, const FractalPoint& right_top);

	// Performs zoom in on a fractal.
	void addZoom(const Zoom& zoom);

	// Performs zoom out on a fractal (cancels the last applied zoom).
	// Returns:	true if zooming out was successful
	//			false if zooming out is impossible (_zoom_array is empty)
	bool removeZoom();

	// Sets rotation angle (about the _center point of fractal image)
	void setRotationAngle(double angle);

	// Applies specified transformations to bitmap coordinates
	// Returns resulting fractal coordinates
	FractalPoint apply(const BitmapPoint& focus);

private:

	BitmapPoint _bitmap_dimensions;
	FractalPoint _fractal_dimensions;
	FractalPoint _center;
	double _zoom_factor;
	std::vector<Zoom> _zoom_array;
	double _rotation_cos;
	double _rotation_sin;
};

} /* namespace fractal */

#endif /* COORDINATETRANSFORMER_H_ */
