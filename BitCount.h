#pragma once

#include <limits.h>
#include "Typedefs.h"

enum
{
    bits_in_byte = CHAR_BIT
};

#define BITS_IN(T) (bits_in_byte * sizeof(T))

static inline Count countSetBits(u64 val, Count bits_to_count)
{
    Count set_bits_count = 0;
    for (Count i = 0; i < bits_to_count; ++i)
    {
        set_bits_count += val & 1;
        val >>= 1;
    }
    return set_bits_count;
}

#define COUNT_SET_BITS(Val) (countSetBits((u64)Val, BITS_IN(Val)))
