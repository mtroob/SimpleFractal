/*
 * Bitmap.cpp
 *
 *  Created on: Jul 27, 2017
 *      Author: michael
 */

#include <fstream>
#include <string>

#include "output/bmp/bmpfile.h"

using std::string;
using std::ofstream;
using std::ios;

namespace fractal {

void BMPFile::convert(const PixelArray& pixel_array) {
    _data_pointer = reinterpret_cast<const char*>(pixel_array.data.data());
    _bitmap_size = pixel_array.width * pixel_array.height * sizeof(Color);
    // fill necessary fields in bitmap headers
    _file_header.data_offset = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader);
    _file_header.file_size = _file_header.data_offset + _bitmap_size;
    _info_header.width = pixel_array.width;
    _info_header.height = pixel_array.height;
}

bool BMPFile::write(const string& file_name) const {
	// open file in binary output mode
	ofstream file;
    file.open(file_name, ios::out | ios::binary);

	// check if file was successfully opened
	if (!file) {
		return false;
	}

	// write data to file
    file.write(reinterpret_cast<const char*>(&_file_header), sizeof(BMPFileHeader));
    file.write(reinterpret_cast<const char*>(&_info_header), sizeof(BMPInfoHeader));
    file.write(_data_pointer, _bitmap_size);

	file.close();
	return true;
}

//void Bitmap::setPixel(uint32_t x, uint32_t y, Color color) {
//	if ((x < _width) && (y < _height))
//		_pixel_buffer[y*_width + x] = color;
//}

} /* namespace fractal */
