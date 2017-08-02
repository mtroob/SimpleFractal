/*
 * fractalcreator.h
 *
 *  Created on: Aug 2, 2017
 *      Author: michael
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <memory>

#include "bitmap.h"
#include "zoomlist.h"

using std::unique_ptr;
using std::string;

namespace fractal {

class FractalCreator {
public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void calculateIteration();
	void drawFractal();
	void addZoom(const Zoom& zoom);
	void writeBitmap(const string& name);

private:
	int _width;
	int _height;
	Bitmap _bitmap;
	ZoomList _zoom_list;
	unique_ptr<int[]> _histogram;
	unique_ptr<int[]> _fractal;
};

} /* namespace fractal */

#endif /* FRACTALCREATOR_H_ */
