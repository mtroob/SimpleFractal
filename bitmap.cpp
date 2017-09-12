/*
 * Bitmap.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: michael
 */

#include <fstream>
#include <string>

#include "bitmap.h"
#include "bitmap_file_header.h"
#include "bitmap_info_header.h"

using std::string;
using std::ofstream;
using std::ios;

namespace fractal {

Bitmap::Bitmap(uint32_t width, uint32_t height) :
		_width(width), _height(height),
		_pixel_buffer(width*height) {}

bool Bitmap::write(const string& filename) const {

	auto bitmap_size = _width*_height*sizeof(Color);

	// fill necessary fields in bitmap headers
	BitmapFileHeader file_header;
	file_header.data_offset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);
	file_header.file_size = file_header.data_offset + bitmap_size;

	BitmapInfoHeader info_header;
	info_header.width = _width;
	info_header.height = _height;

	// open file in binary output mode
	ofstream file;
	file.open(filename, ios::out | ios::binary);

	// check if file was successfully opened
	if (!file) {
		return false;
	}

	// write data to file
	file.write(reinterpret_cast<const char*>(&file_header), sizeof(file_header));
	file.write(reinterpret_cast<const char*>(&info_header), sizeof(info_header));
	file.write(reinterpret_cast<const char*>(_pixel_buffer.data()), bitmap_size);

	file.close();
	return true;
}

void Bitmap::setPixel(uint32_t x, uint32_t y, Color color) {
	if ((x < _width) && (y < _height))
		_pixel_buffer[y*_width + x] = color;
}

} /* namespace fractal */
