#pragma once

#include <stdio.h>
#include "Repeat.h"

#define DEFINE_PRINT_ARRAY(T, Format)                              \
    static inline void printArray_##T(const T* a, Count count)     \
    {                                                              \
        printf("{");                                               \
        if (count)                                                 \
        {                                                          \
            repeat_count(count - 1) printf("%" Format ", ", a[i]); \
            printf("%" Format, a[count - 1]);                      \
        }                                                          \
        printf("}\n");                                             \
    }

DEFINE_PRINT_ARRAY(int, "d")
DEFINE_PRINT_ARRAY(float, "f")
