#pragma once

#include <limits.h>
#include "Logging.h"
#include "Typedefs.h"

static inline void toBinary(Byte byte, char* dest)
{
    const Byte mask = 1 << (CHAR_BIT - 1);
    for (int i = 0; i < CHAR_BIT; ++i, byte <<= 1)
        dest[i] = byte & mask ? '1' : '0';
}

static inline void dumpMemory(const void* bytes, Count count)
{
    const Byte* byte = (Byte*)bytes;
    char as_binary[CHAR_BIT + 1] = {0};
    for (Count i = 0; i < count; ++i)
    {
        toBinary(byte[i], as_binary);
        DEBUG_LOG("%3d --- %3d --- %s", i, byte[i], as_binary);
    }
}
