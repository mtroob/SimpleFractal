/*
 * linearinterpolatedcoloring.h
 *
 *  Created on: Sep 6, 2017
 *      Author: michael
 */

#ifndef LINEARINTERPOLATEDCOLORING_H_
#define LINEARINTERPOLATEDCOLORING_H_

#include <map>

#include "coloringalgorithm.h"

namespace fractal {

class LinearInterpolatedColoring : public ColoringAlgorithm {
public:
	LinearInterpolatedColoring(int max_iterations = 1) : _max_iterations(max_iterations) {}
	Color getColor(double key) const;

	bool addColor(double key, const Color& color);

	void setup(int max_iterations) {
		_max_iterations = max_iterations;
	}

private:
	using ColorMap = std::map<double, Color>;
	ColorMap _color_map;
	int _max_iterations;
};

} /* namespace fractal */

#endif /* LINEARINTERPOLATEDCOLORING_H_ */
