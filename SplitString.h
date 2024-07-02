#pragma once

#include "Allocs.h"
#include "StringEquals.h"
#include "Typedefs.h"

static inline void unifyDelimiters(char* s, const char* delims)
{
    if (empty(delims))
        return;

    while (*s)
    {
        if (strchr(delims, *s))
            *s = *delims;
        ++s;
    }
}

static inline Count split(char** dest, const char* src, const char* delims)
{
    Count count = 0;

    if (empty(src) or empty(delims))
        return count;

    char* src_unified = MALLOC(char, strlen(src) + 1);
    strcpy(src_unified, src);
    unifyDelimiters(src_unified, delims);

    const char* s = src_unified;
    while (true)
    {
        const char* next = strchr(s, *delims);
        if (not next)
        {
            strcpy(dest[count++], s);
            break;
        }

        if (next > s)
        {
            const ptrdiff_t chars_to_copy = next - s;
            strncpy(dest[count], s, chars_to_copy);
            dest[count][chars_to_copy] = '\0';
            ++count;
        }
        s = next + 1;
    }

    free(src_unified);

    return count;
}
