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
    void setup(const FractalCreator* fractal_creator) override;

	Color getColor(double key) const;

private:
    int _key_scale_factor;
};

} /* namespace fractal */

#endif /* SIMPLECOLORING_H_ */
