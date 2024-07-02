#pragma once

#include "DefaultRandomEngine.h"
#include "Swap.h"
#include "Typedefs.h"

static inline int randomInt(int min, int max)
{
    defaultRandomEngine();

    return min + rand() % (max - min + 1);
}

static inline float randomFloat(float min, float max)
{
    defaultRandomEngine();

    return (float)((double)min + (double)rand() / (double)(RAND_MAX) * ((double)max - (double)min));
}

static inline void shuffle(void* dest, Count count)
{
    defaultRandomEngine();

    int* desti = (int*)dest;
    for (Count i = 0; i < count - 1; ++i)
    {
        const int r = randomInt(0, (int)(count - i - 1));
        SWAP(int, *(desti + i), *(desti + i + r));
    }
}
