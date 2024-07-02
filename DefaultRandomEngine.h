#pragma once

#include <stdlib.h>
#include <time.h>

static inline void defaultRandomEngine(void)
{
    static bool initialized = false;
    if (not initialized)
    {
        srand((unsigned)time(NULL));
        initialized = true;
    }
}
