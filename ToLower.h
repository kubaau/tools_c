#pragma once

#include <ctype.h>

static inline void toLower(const char* str, char* out)
{
    while (*str)
        *out++ = (char)tolower(*str++);
    *out = '\0';
}
