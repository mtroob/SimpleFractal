/*
 * bitmap_file_header.h
 *
 *  Created on: Jul 27, 2017
 *      Author: michael
 */

#ifndef BMPFILEHEADER_H_
#define BMPFILEHEADER_H_

#include <cstdint>

using std::uint32_t;
using std::uint8_t;

#pragma pack(push, 2)

namespace fractal {

struct BMPFileHeader {
	uint8_t header[2]{'B', 'M'};
	uint32_t file_size;
	uint32_t reserved{0};
	uint32_t data_offset;
};

}

#pragma pack(pop)

#endif /* BMPFILEHEADER_H_ */
