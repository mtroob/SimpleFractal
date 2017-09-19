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
    // copy pixel data
    _pixel_array = pixel_array;
    // swap red and blue colors
    for (auto i = 0; i < _pixel_array.height; ++i)
        for (auto j = 0; j < _pixel_array.width; ++j)
            std::swap(_pixel_array.data[i*_pixel_array.width + j].red, _pixel_array.data[i*_pixel_array.width + j].blue);

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
    file.write(reinterpret_cast<const char*>(_pixel_array.data.data()), _bitmap_size);

	file.close();
	return true;
}

} /* namespace fractal */
