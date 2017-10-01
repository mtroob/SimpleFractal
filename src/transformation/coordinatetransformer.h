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

// Converts bitmap pixel coordinates into fractal coordinates
// Implements zooming in/out and rotation
class CoordinateTransformer {
public:

	// Costructs ZoomList object using information on bitmap dimensions
	// and fractal x/y scale
    CoordinateTransformer();
    //	CoordinateTransformer(int width, int height, const FractalPoint& left_bottom, const FractalPoint& right_top);

    // Adds a zoom operation to the queue
	void addZoom(const Zoom& zoom);

    // Removes a zoom operation from the queue
	// Returns:	true if zooming out was successful
	//			false if zooming out is impossible (_zoom_array is empty)
	bool removeZoom();

    // Checks if fractal is in default scale
    // Returns true if fractal is in it's default scale
    bool defaultScale() const;

	// Sets rotation angle (about the _center point of fractal image)
	void setRotationAngle(double angle);

    // Initializes internal variables based on image dimensions, fractal coordinate range
    // and the transformation operations to be performed
    void initialize(int width, int height, const FractalPoint& left_bottom, const FractalPoint& right_top);

	// Applies specified transformations to bitmap coordinates
	// Returns resulting fractal coordinates
    FractalPoint apply(const BitmapPoint& focus);

private:
    // Bitmap dimensions (width and height in pinxels)
	BitmapPoint _bitmap_dimensions;
    // Fractal representation dimensions (fractal coordinate range)
	FractalPoint _fractal_dimensions;
    // The fractal coordinates of the point, that will be in the center
    // of the bitmap.
	FractalPoint _center;
    // Zoom scale
    double _zoom_factor {1};
    // The container (queue) with all Zoom operations to be applied
	std::vector<Zoom> _zoom_array;
    // cos() of the rotation angle
    double _rotation_cos {1};
    // sin() of the rotation angle
    double _rotation_sin {0};
};

} /* namespace fractal */

#endif /* COORDINATETRANSFORMER_H_ */
