#pragma once

#include <stdio.h>
#include <string.h>
#include "Allocs.h"
#include "Repeat.h"
#include "Typedefs.h"

static inline int ctoi(char c)
{
    return c - '0';
}

static inline int stoi(const char* str)
{
    return atoi(str);
}

static inline void toVectorOfDigits(u8* dest, const char* str)
{
    const size_t len = strlen(str);
    repeat_count(len) dest[i] = (u8)ctoi(str[i]);
}

static inline Byte wordToByte(const char* word)
{
    return (Byte)strtoul(word, NULL, 16);
}

static inline Count hexStringToBytes(Byte* dest, const char* str)
{
    int offset = 0;
    char hex[3];
    Count count = 0;
    while (sscanf(str, " %2s%n", hex, &offset) == 1)
    {
        *(dest + count++) = wordToByte(hex);
        str += offset;
    }
    return count;
}
