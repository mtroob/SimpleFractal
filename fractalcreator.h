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

#include "coloringalgorithm.h"

#include "mandelbrot.h"

using std::unique_ptr;
//using std::string;

using uint = unsigned int;

namespace fractal {

class FractalCreator {
public:
	FractalCreator(int width, int height, std::shared_ptr<ColoringAlgorithm> coloring_algorithm);
	virtual ~FractalCreator();

	void calcuclateIterationsPerPixel();
	void generateIterationHistogram();
	void addZoom(const Zoom& zoom);
	bool removeZoom();

	void setColoringAlgorithm(std::shared_ptr<ColoringAlgorithm> coloring_algorithm);

	void drawFractal();
	void writeBitmap(const string& name);

private:

	uint getRange(uint iterations) const;

	uint _width;
	uint _height;
	Bitmap _bitmap;
	Mandelbrot _fractal;
	ZoomList _zoom_list;
	vector<uint> _histogram;
	vector<double> _iterations;
	vector<uint> _ranges;
	std::shared_ptr<ColoringAlgorithm> _coloring_algorithm;
};

} /* namespace fractal */

#endif /* FRACTALCREATOR_H_ */
