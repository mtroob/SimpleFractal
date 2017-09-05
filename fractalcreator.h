/*
 * fractalcreator.h
 *
 *  Created on: Aug 2, 2017
 *      Author: michael
 */

#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

//#include <string>
#include <vector>
#include <memory>

#include <set>

#include "bitmap.h"
#include "zoomlist.h"
#include "colorpalette.h"

using std::unique_ptr;
//using std::string;

using uint = unsigned int;

namespace fractal {

class FractalCreator {
public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void calcuclateIterationsPerPixel();
	void calcualtePixelsPerColorRange();
	void addZoom(const Zoom& zoom);
	bool removeZoom();
	void addRange(double range_end, const Color& color);
	void drawFractal();
	void writeBitmap(const string& name);

private:

	uint getRange(uint iterations) const;

	uint _width;
	uint _height;
	Bitmap _bitmap;
	ZoomList _zoom_list;
	vector<uint> _histogram;
	vector<double> _fractal;
	vector<uint> _ranges;
	vector<Color> _colors;
	vector<uint> _pixels_in_range;
	ColorPalette _color_palette;

	std::set<double> hue_set_tmp;
};

} /* namespace fractal */

#endif /* FRACTALCREATOR_H_ */
