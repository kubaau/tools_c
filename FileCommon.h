#pragma once

#include <stdio.h>

#include "CheckResult.h"

enum
{
    wrong_entity_buffer_size = 64
};

static inline void jump(FILE* file, int origin)
{
    fseek(file, 0, origin);
}

static inline void jumpToStart(FILE* file)
{
    rewind(file);
}

static inline void jumpToEnd(FILE* file)
{
    jump(file, SEEK_END);
}

inline static FILE* openFile(const char* filename, const char* mode)
{
    FILE* file = fopen(filename, mode);
    if (not file)
    {
        char wrong_file[wrong_entity_buffer_size];
        sprintf(wrong_file, "Cannot open file %s", filename);
        check(false, wrong_file);
    }
    return file;
}
