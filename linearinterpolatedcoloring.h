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
	Color getColor(double key) const;

	bool addColor(double key, const Color& color);

private:
	using ColorMap = std::map<double, Color>;
	ColorMap _color_map;
};

} /* namespace fractal */

#endif /* LINEARINTERPOLATEDCOLORING_H_ */
