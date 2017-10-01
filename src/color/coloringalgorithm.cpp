/*
 * coloringalgorithm.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: michael
 */

#include "coloringalgorithm.h"

namespace fractal {

// Default implementation: does nothing
ColoringAlgorithm::ColoringAlgorithm() {}

// Default implementation: does nothing
ColoringAlgorithm::~ColoringAlgorithm() {}

// Default implementation: does nothing
void ColoringAlgorithm::setup() {}

// Default implementation: does nothing
void ColoringAlgorithm::setup(const FractalCreator* fractal_creator) {}

// Default implementation: does nothing
void ColoringAlgorithm::setColorMap(const std::shared_ptr<ColorMap> color_map) {}

} /* namespace fractal */
