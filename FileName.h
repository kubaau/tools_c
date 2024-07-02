#pragma once

#include <string.h>

#ifndef _WIN32
#define PATH_DELIMITER '/'
#else
#define PATH_DELIMITER '\\'
#endif

static inline const char* filenameIndexRchr(const char* file)
{
    return strrchr(file, PATH_DELIMITER) ? strrchr(file, PATH_DELIMITER) + 1 : file;
}
#define FILE_NAME_RCHR filenameIndexRchr(__FILE__)

#define FILE_NAME FILE_NAME_RCHR
