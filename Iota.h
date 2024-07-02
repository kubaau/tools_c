#pragma once

#include "Repeat.h"

static inline void iota(void* dest, Count count)
{
    int* desti = (int*)dest;
    repeat_count(count) desti[i] = (int)i;
}
