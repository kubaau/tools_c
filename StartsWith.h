#pragma once

#include <string.h>

static inline bool startsWith(const char* str, const char* prefix)
{
    return strncmp(str, prefix, strlen(prefix)) == 0;
}
