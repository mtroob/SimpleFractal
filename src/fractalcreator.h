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

#include "util/pixelarray.h"
#include "output/fileformat.h"
#include "color/coloringalgorithm.h"
#include "transformation/coordinatetransformer.h"

#include "fractal/fractal.h"

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
    bool save(FileFormat* file_format, const std::string& file_name) const;
	inline double getIterationCount(const BitmapPoint& point) const;

private:

	std::shared_ptr<Fractal> _fractal;
    PixelArray _pixel_array;
	CoordinateTransformer _coordinate_transformer;
	std::vector<double> _fractal_values;
};

} /* namespace fractal */

#endif /* FRACTALCREATOR_H_ */
