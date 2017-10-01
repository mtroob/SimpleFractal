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
#include "bmpfileheader.h"
#include "bmpinfoheader.h"
#include "color/color.h"
#include "util/pixelarray.h"

namespace fractal {

// BMP file format representation. Used to save data from PixelArray object
// as a BMP file.
class BMPFile : public FileFormat {
public:
    // Makes a copy of the image (PixelArray data) and modifies it
    // according to BMP file format specifications.
    virtual void convert(const PixelArray& pixel_array) override;
    // Writes converted image to the specified file.
    virtual bool write(const std::string& file_name) const override;
private:
    // Bitmap size in bytes (the image itself only).
    std::uint64_t _bitmap_size;
    // Bitmap file header
    BMPFileHeader _file_header;
    // Bitmap information header (DIB)
    BMPInfoHeader _info_header;
    // Pixel array data
    PixelArray _pixel_array;
};

} /* namespace fractal */

#endif /* BMPFILE_H_ */
