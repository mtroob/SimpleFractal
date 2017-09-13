/*
 * Bitmap.h
 *
 *  Created on: Jul 27, 2017
 *      Author: michael
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#include <memory>
#include <vector>
#include <cstdint>
#include <string>

#include "color.h"

using std::string;
using std::uint32_t;
using std::uint8_t;
using std::unique_ptr;

namespace fractal {

class Bitmap {
public:
	Bitmap(uint32_t width, uint32_t height);

	virtual ~Bitmap() = default;

	bool write(const string& filename) const;
	void setPixel(uint32_t x, uint32_t y, Color color);

private:
	uint32_t _width;
	uint32_t _height;
	std::vector<Color> _pixel_buffer;
};

} /* namespace fractal */

#endif /* BITMAP_H_ */
