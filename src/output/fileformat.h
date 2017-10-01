#ifndef FILEFORMAT_H_
#define FILEFORMAT_H_

#include <vector>
#include <string>

#include "util/pixelarray.h"

namespace fractal {

// Abstract interface for file format implementations.
// Used to convert fractal visual representation data form PixelArray object
// and save it as a file of a specified format.
// Implements Strategy pattern.
class FileFormat
{
public:
    virtual ~FileFormat();
    // Converts PixelArray data to the necessary image format/structure (if needed)
    // and write the result to a specified file.
    bool convertAndWrite(const PixelArray& pixel_array, const std::string& file_name);

private:
    // Converts PixelArray data to the necessary image format/structure
    // without modifying the original contents.
    virtual void convert(const PixelArray& pixel_array) = 0;
    // Writes converted image to the specified file.
    virtual bool write(const std::string& file_name) const = 0;
};

}

#endif // FILEFORMAT_H_
