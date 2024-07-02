#pragma once

#define DEFINE_COMPARE(T)                                           \
    static inline int compare_##T(const void* lhs, const void* rhs) \
    {                                                               \
        const T lhs_t = *(const T*)lhs;                             \
        const T rhs_t = *(const T*)rhs;                             \
        if (lhs_t < rhs_t)                                          \
            return -1;                                              \
        if (lhs_t > rhs_t)                                          \
            return 1;                                               \
        return 0;                                                   \
    }

DEFINE_COMPARE(int)
DEFINE_COMPARE(float)
