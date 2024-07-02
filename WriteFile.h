#pragma once

#include "FileCommon.h"

inline static void writeFile(const char* path, const char* data, size_t length, const char* mode)
{
    FILE* file = openFile(path, mode);
    fwrite(data, sizeof(char), length, file);
    fclose(file);
}

inline static void writeBinaryFile(const char* path, const char* data, size_t length)
{
    writeFile(path, data, length, "wb");
}

inline static void writeTextFile(const char* path, const char* data, size_t length)
{
    writeFile(path, data, length, "w");
}
