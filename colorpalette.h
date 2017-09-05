/*
 * colorpalette.h
 *
 *  Created on: Aug 20, 2017
 *      Author: michael
 */

#ifndef COLORPALETTE_H_
#define COLORPALETTE_H_

#include <map>

#include "color.h"

namespace fractal {

class ColorPalette {
public:

	using ColorMap = std::map<double, Color>;

	bool addColor(double key, const Color& color);
	Color getColor(double key) const;
	Color getColor(double iterations, uint max_iterations) const;

private:
	ColorMap _color_map;
};

} /* namespace fractal */

#endif /* COLORPALETTE_H_ */
