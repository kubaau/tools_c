#pragma once

#include "Typedefs.h"

static inline bool isLittleEndian()
{
    const u16 val = 1;
    static const bool ret = (val == *(const u8*)&val);
    return ret;
}
