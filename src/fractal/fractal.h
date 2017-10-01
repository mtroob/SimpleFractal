/*
 * fractal.h
 *
 *  Created on: Sep 12, 2017
 *      Author: michael
 */

#ifndef FRACTAL_H_
#define FRACTAL_H_

#include "util/point.h"

namespace fractal {

using FractalPoint = Point<double>;

// Abstract Fractal interface
class Fractal {
public:
    // Destructor
    virtual ~Fractal();
    // Returns the value of a fractal for the given coordinates
    virtual double calculateValue(const FractalPoint& coords) const = 0;
    // Returns maximum value of a fractal
    virtual int maxValue() const = 0;
    // Returns left bottom corner of the fractal coordinate range (minimum coordinate values)
    virtual FractalPoint leftBottom() const = 0;
    // Returns right top corner of the fractal coordinate range (maximum coordinate values)
    virtual FractalPoint rightTop() const = 0;
    // Points to describe fractal XY scale
};

} /* namespace fractal */

#endif /* FRACTAL_H_ */
