/*
 * coloringalgorithm.h
 *
 *  Created on: Sep 6, 2017
 *      Author: michael
 */

#ifndef COLORINGALGORITHM_H_
#define COLORINGALGORITHM_H_

#include <map>
#include <memory>
#include "color.h"

namespace fractal {

class FractalCreator;

// ColorMap describes key-color mapping.
using ColorMap = std::map<double, Color>;

// Abstract interface for coloring algorithm implementations.
// Transformes key value to an RGB color according to an implemented algorithm.
// Should be used in conjunction with FractalCreator and ColorMap objects.
class ColoringAlgorithm {
public:
	ColoringAlgorithm();
	virtual ~ColoringAlgorithm();
    // Sets ColorMap object to use for color calculation.
    virtual void setColorMap(const std::shared_ptr<ColorMap> color_map);
    // Performs inital setup based on FractalCreator internal state.
    virtual void setup(const FractalCreator* fractal_creator);
    virtual void setup();
    // Returns color value for a given key.
    // Should be overriden by derived classes.
	virtual Color getColor(double key) const = 0;
};

} /* namespace fractal */

#endif /* COLORINGALGORITHM_H_ */
