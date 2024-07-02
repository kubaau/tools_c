#pragma once

#include "Ratios.h"

static inline double inRatio(double seconds, int den, int num)
{
    return seconds * den / num;
}
static inline double inNanoseconds(double seconds)
{
    return inRatio(seconds, nano_denominator, 1);
}
static inline double inMicroseconds(double seconds)
{
    return inRatio(seconds, micro_denominator, 1);
}
static inline double inMilliseconds(double seconds)
{
    return inRatio(seconds, milli_denominator, 1);
}
static inline double inMinutes(double seconds)
{
    return inRatio(seconds, 1, secs_in_min);
}
static inline double inHours(double seconds)
{
    return inRatio(seconds, 1, secs_in_hr);
}
