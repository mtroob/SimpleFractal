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
    SimpleColoring();
    void setup(const FractalCreator* fractal_creator) override;
    void setColorMap(const std::shared_ptr<ColorMap> color_map) override;

	Color getColor(double key) const;

private:
    Color _halo_color;
    Color _background_color;
    int _key_scale_factor;
};

} /* namespace fractal */

#endif /* SIMPLECOLORING_H_ */
