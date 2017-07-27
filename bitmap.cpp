/*
 * Bitmap.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: michael
 */

#include "bitmap.h"

namespace fractal {

Bitmap::Bitmap(uint32_t width, uint32_t height) :
		_width(width), _height(height),
		_pixel_buffer(new Color[width*height]) {}

bool Bitmap::write(const string& filename) const {
	return false;
}

void Bitmap::setPixel(uint32_t x, uint32_t y, Color color) {

}

} /* namespace fractal */
