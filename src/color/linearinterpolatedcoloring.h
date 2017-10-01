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

// Uses linear interpolation between ColorMap entries to calculate color value.
class LinearInterpolatedColoring : public ColoringAlgorithm {
public:
    // Sets ColorMap object to use for color calculation.
    void setColorMap(const std::shared_ptr<ColorMap> color_map) override;
    // Performs inital setup based on FractalCreator internal state.
    void setup(const FractalCreator* fractal_creator) override;
    // Returns color value for a given key.
    Color getColor(double key) const override;

private:
    // Pointer to a ColorMap object. Might be shared between different algorithms.
    std::shared_ptr<ColorMap> _color_map;
    // Key value scaling coefficient
    int _key_scale_factor;
};

} /* namespace fractal */

#endif /* LINEARINTERPOLATEDCOLORING_H_ */
