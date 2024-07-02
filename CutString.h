#pragma once

#include <string.h>

static inline size_t getLengthAndCorrectN(const char* s, size_t* n)
{
    const size_t len = strlen(s);
    if (*n > len)
        *n = len;
    return len;
}

static inline const char* cutFromBegin(const char* s, size_t n)
{
    getLengthAndCorrectN(s, &n);
    return s + n;
}

static inline const char* cutFromEnd(char* s, size_t n)
{
    const size_t len = getLengthAndCorrectN(s, &n);
    s[len - n] = '\0';
    return s;
}
