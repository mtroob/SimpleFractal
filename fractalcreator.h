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
#include "coloringalgorithm.h"
#include "coordinatetransformer.h"

#include "fractal.h"

using uint = unsigned int;

namespace fractal {

class FractalCreator {
public:
	FractalCreator(int width, int height, std::shared_ptr<Fractal> fractal);
	virtual ~FractalCreator();

	void calcuclateIterationsPerPixel();
	void addZoom(const Zoom& zoom);
	bool removeZoom();
	void rotate(double angle);

	void drawFractal(std::shared_ptr<ColoringAlgorithm> coloring_algorithm);
	void writeBitmap(const string& name);

	inline double getIterationCount(const BitmapPoint& point) const;

private:

	uint _width;
	uint _height;
	Bitmap _bitmap;
	std::shared_ptr<Fractal> _fractal;
	CoordinateTransformer _zoom_list;
	std::vector<double> _fractal_values;
};

} /* namespace fractal */

#endif /* FRACTALCREATOR_H_ */
