/*
 * linearinterpolatedcoloring.h
 *
 *  Created on: Sep 6, 2017
 *      Author: michael
 */

#ifndef LINEARINTERPOLATEDCOLORING_H_
#define LINEARINTERPOLATEDCOLORING_H_

#include "coloringalgorithm.h"

namespace fractal {

class LinearInterpolatedColoring : public ColoringAlgorithm {
public:
    void setup(const FractalCreator* fractal_creator) override;
    Color getColor(double key) const override;
    void setColorMap(const std::shared_ptr<ColorMap> color_map) override;

private:
    std::shared_ptr<ColorMap> _color_map;
    int _key_scale_factor;
};

} /* namespace fractal */

#endif /* LINEARINTERPOLATEDCOLORING_H_ */
