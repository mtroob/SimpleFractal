/*
 * Bitmap.h
 *
 *  Created on: Jul 27, 2017
 *      Author: michael
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#include <memory>
#include <cstdint>
#include <string>

using std::string;
using std::uint32_t;
using std::uint8_t;
using std::unique_ptr;

namespace fractal {

struct Color {
	uint8_t blue;
	uint8_t green;
	uint8_t red;
};

const Color COLOR_RED {0, 0, 255};
const Color COLOR_BLUE {255, 0, 0};
const Color COLOR_GREEN {0, 255, 0};
const Color COLOR_WHITE {255, 255, 255};
const Color COLOR_BLACK {0, 0, 0};

class Bitmap {
public:
	Bitmap(uint32_t width, uint32_t height);

	virtual ~Bitmap() = default;

	bool write(const string& filename) const;
	void setPixel(uint32_t x, uint32_t y, Color color);

private:
	uint32_t _width;
	uint32_t _height;
	unique_ptr<Color[]> _pixel_buffer;
};

} /* namespace fractal */

#endif /* BITMAP_H_ */
