/*
 * mandelbrot.h
 *
 *  Created on: Aug 1, 2017
 *      Author: michael
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

#include "util/point.h"
#include "fractal.h"

namespace fractal {

// Mandelbrot Fractal class. Implements mathematical functions
// to calculate fractal values.
class Mandelbrot : public Fractal {
public:
	Mandelbrot(int max_iterations, int escape_radius);
    // Returns the value of a fractal for the given coordinates.
    // Mandelbrot fractal value is a number of iterations it takes
    // for the calculation to satisfy the escape condition.
    virtual double calculateValue(const FractalPoint& coords) const override;
    // Returns maximum value of a fractal
    virtual int maxValue() const override;
    // Returns left bottom corner of the fractal coordinate range (minimum coordinate values)
    virtual FractalPoint leftBottom() const override;
    // Returns right top corner of the fractal coordinate range (maximum coordinate values)
    virtual FractalPoint rightTop() const override;

private:
    // Left bottom corner (minimum coordinate values)
    const FractalPoint LEFT_BOTTOM {-2, -2};
    // Right top corner (maximum coordinate values)
    const FractalPoint RIGHT_TOP {2, 2};
    // Maximum number of allowed iterations.
    int _max_iterations;
    // Fractal escape radius. Determines the escape condition
    // for a successful termination of iterational calculation process.
	int _escape_radius;
};

} /* namespace fractal */

#endif /* MANDELBROT_H_ */
