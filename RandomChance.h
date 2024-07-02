#pragma once

#include "Random.h"

static inline bool chance(int n)
{
    return randomInt(1, n) == n;
}
