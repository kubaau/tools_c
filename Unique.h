#pragma once

#include "Compare.h"
#include "Repeat.h"

#define DEFINE_ALL_UNIQUE(T)                                                          \
    static inline bool allUnique_##T(const T* a, Count count)                         \
    {                                                                                 \
        repeat_count(count - 1) if (compare_##T(a + i, a + i + 1) == 0) return false; \
        return true;                                                                  \
    }

DEFINE_ALL_UNIQUE(int)
DEFINE_ALL_UNIQUE(float)
