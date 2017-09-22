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
    void setup(const FractalCreator* fractal_creator) override;
    Color getColor(double key) const override;

    bool addColor(double key, const Color& color);

private:
	using ColorMap = std::map<double, Color>;
	ColorMap _color_map;
    int _key_scale_factor;
};

} /* namespace fractal */

#endif /* LINEARINTERPOLATEDCOLORING_H_ */
