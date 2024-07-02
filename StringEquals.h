#pragma once

#include <stdbool.h>
#include <string.h>

static inline bool equals(const char* lhs, const char* rhs)
{
    return strcmp(lhs, rhs) == 0;
}

static inline bool empty(const char* lhs)
{
    return equals(lhs, "");
}
