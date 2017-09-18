#include "fileformat.h"

namespace fractal {

FileFormat::~FileFormat() {}

bool FileFormat::convertAndWrite(const PixelArray& pixel_array, const std::string& file_name) {
    convert(pixel_array);
    return write(file_name);
}

}
