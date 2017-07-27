/*
 * bitmap_file_header.h
 *
 *  Created on: Jul 27, 2017
 *      Author: michael
 */

#ifndef BITMAP_FILE_HEADER_H_
#define BITMAP_FILE_HEADER_H_

#include <cstdint>

using std::uint32_t;

#pragma pack(push, 2)

struct BitmapFileHeader {
	char header[2]{'B', 'M'};
	uint32_t file_size;
	uint32_t reserved{0};
	uint32_t data_offset;
};

#pragma pack(pop)

#endif /* BITMAP_FILE_HEADER_H_ */
