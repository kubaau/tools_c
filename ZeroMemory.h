#pragma once

#include <assert.h>
#include <iso646.h>
#include <string.h>

#define ZERO_MEMORY(ptr) memset(ptr, 0, sizeof(*ptr))

#define CHECK_ZERO_MEMORY(ptr)                    \
    {                                             \
        char* byte_ptr = (char*)ptr;              \
        for (size_t i = 0; i < sizeof(*ptr); ++i) \
            assert(not*(byte_ptr + i));           \
    }

#define CREATE_ZEROED(Type, Name) \
    Type Name;                    \
    ZERO_MEMORY(&Name);
