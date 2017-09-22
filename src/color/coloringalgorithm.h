/*
 * coloringalgorithm.h
 *
 *  Created on: Sep 6, 2017
 *      Author: michael
 */

#ifndef COLORINGALGORITHM_H_
#define COLORINGALGORITHM_H_

#include "color.h"

namespace fractal {

class FractalCreator;

// Abstract interface for coloring algorithm implementations
// Transformes key value to an RGB color
class ColoringAlgorithm {
public:
	ColoringAlgorithm();
	virtual ~ColoringAlgorithm();
    virtual void setup(const FractalCreator* fractal_creator);
    virtual void setup();
	virtual Color getColor(double key) const = 0;
};

} /* namespace fractal */

#endif /* COLORINGALGORITHM_H_ */
