/*
 * Bitmap.h
 *
 *  Created on: Jul 27, 2017
 *      Author: michael
 */

#ifndef BMPFILE_H_
#define BMPFILE_H_

#include <memory>
#include <vector>
#include <cstdint>
#include <string>

#include "output/fileformat.h"
#include "output/bmp/bmpfileheader.h"
#include "output/bmp/bmpinfoheader.h"
#include "color/color.h"
#include "util/pixelarray.h"

namespace fractal {

class BMPFile : public FileFormat {
public:
    virtual void convert(const PixelArray& pixel_array) override;

    virtual bool write(const std::string& file_name) const override;

    //void setPixel(uint32_t x, uint32_t y, Color color);

private:
    std::uint64_t _bitmap_size;
    BMPFileHeader _file_header;
    BMPInfoHeader _info_header;
    const char* _data_pointer;

//	uint32_t _width;
//	uint32_t _height;
//	std::vector<Color> _pixel_buffer;
//    PixelArray _pixel_array;
};

} /* namespace fractal */

#endif /* BMPFILE_H_ */
