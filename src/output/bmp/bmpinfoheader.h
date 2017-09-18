/*
 * bitmap_info_header.h
 *
 *  Created on: Jul 27, 2017
 *      Author: michael
 */

#ifndef BMPINFOHEADER_H_
#define BMPINFOHEADER_H_

#include <cstdint>

using std::uint32_t;
using std::uint16_t;

#pragma pack(push, 2)

namespace fractal {

struct BMPInfoHeader {
	uint32_t header_size{40};
	uint32_t width;
	uint32_t height;
	uint16_t planes{1};
	uint16_t bits_per_pixel{24};
	uint32_t compression{0};
	uint32_t data_size{0};
	uint32_t horizontal_resolution{2400};
	uint32_t vertical_resolution{2400};
	uint32_t colors{0};
	uint32_t important_colors{0};
};

}

#pragma pack(pop)

#endif /* BMPINFOHEADER_H_ */
