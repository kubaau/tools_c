#pragma once

#include "Typedefs.h"

static inline void* moveNBytes(const void* ptr, int n)
{
    return (Byte*)ptr + n;
}
