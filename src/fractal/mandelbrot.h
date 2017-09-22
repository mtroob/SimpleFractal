/*
 * mandelbrot.h
 *
 *  Created on: Aug 1, 2017
 *      Author: michael
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

#include "util/point.h"
#include "fractal/fractal.h"

namespace fractal {

class Mandelbrot : public Fractal {
public:

	Mandelbrot(int max_iterations, int escape_radius);

    virtual double getFractalValue(const FractalPoint& coords) const override;

    virtual int getMaxIterations() const override;

private:
    int _max_iterations;
	int _escape_radius;
};

} /* namespace fractal */

#endif /* MANDELBROT_H_ */
