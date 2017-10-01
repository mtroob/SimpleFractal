/*
 * SimpleColoring.h
 *
 *  Created on: Sep 6, 2017
 *      Author: michael
 */

#ifndef SIMPLEHALOCOLORING_H_
#define SIMPLEHALOCOLORING_H_

#include "coloringalgorithm.h"

namespace fractal {

// Draws the fractal with a simple halo.
// Uses a shade of a single color (white by default) to draw the halo,
// while the other fractal areas are black;
class SimpleHaloColoring: public ColoringAlgorithm {
public:
    SimpleHaloColoring();
    // Sets ColorMap object to use for color calculation.
    void setColorMap(const std::shared_ptr<ColorMap> color_map) override;
    // Performs inital setup based on FractalCreator internal state.
    void setup(const FractalCreator* fractal_creator) override;
    // Returns color value for a given key.
	Color getColor(double key) const;

private:
    // The color of the halo
    Color _halo_color;
    // The backgorund color
    Color _background_color;
    // Key value scaling coefficient
    int _key_scale_factor;
};

} /* namespace fractal */

#endif /* SIMPLEHALOCOLORING_H_ */
