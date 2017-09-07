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

class ColoringAlgorithm {
public:
	ColoringAlgorithm();
	virtual ~ColoringAlgorithm();
	virtual void setup();
	virtual Color getColor(double key) const = 0;
};

} /* namespace fractal */

#endif /* COLORINGALGORITHM_H_ */
