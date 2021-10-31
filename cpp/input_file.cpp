#include "input_file.hpp"
#include <cstdio>

bool InputFile::CheckEnd(const char &data) {
    return data == EOF;
}
