#ifndef PIXELARRAY_H
#define PIXELARRAY_H

#include <vector>
#include <cstdint>

#include "color/color.h"

namespace fractal {

struct PixelArray {
    PixelArray(std::uint32_t width, std::uint32_t height) :
        width(width), height(height), data(width*height) {}
    std::uint32_t width;
    std::uint32_t height;
    std::vector<Color> data;
};

}
#endif // PIXELARRAY_H
