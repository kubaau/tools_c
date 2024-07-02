#pragma once

#include "FileCommon.h"

inline static size_t readFile(char* dest, const char* path, const char* mode)
{
    FILE* file = openFile(path, mode);
    jumpToEnd(file);
    const long length = ftell(file);
    jumpToStart(file);
    const size_t ret = fread(dest, sizeof(char), length, file);
    fclose(file);
    return ret;
}

inline static void readBinaryFile(char* dest, const char* path)
{
    readFile(dest, path, "rb");
}

inline static void readTextFile(char* dest, const char* path)
{
    dest[readFile(dest, path, "r")] = 0;
}
