#ifndef FILEFORMAT_H_
#define FILEFORMAT_H_

#include <vector>
#include <string>

#include "util/pixelarray.h"

namespace fractal {

class FileFormat
{
public:
    virtual ~FileFormat();
    bool convertAndWrite(const PixelArray& pixel_array, const std::string& file_name);

private:
    virtual void convert(const PixelArray& pixel_array) = 0;
    virtual bool write(const std::string& file_name) const = 0;
};

}

#endif // FILEFORMAT_H_
