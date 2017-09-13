/*
 * SimpleColoring.h
 *
 *  Created on: Sep 6, 2017
 *      Author: michael
 */

#ifndef SIMPLECOLORING_H_
#define SIMPLECOLORING_H_

#include "coloringalgorithm.h"

namespace fractal {

class SimpleColoring: public ColoringAlgorithm {
public:
	SimpleColoring(int max_iterations = 1) : _max_iterations(max_iterations) {}

	void setup(int max_iterations) {
		_max_iterations = max_iterations;
	}

	Color getColor(double key) const;

private:
	int _max_iterations;
};

} /* namespace fractal */

#endif /* SIMPLECOLORING_H_ */
