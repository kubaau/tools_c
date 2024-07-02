#pragma once

#include "CurrentTime.h"
#include "TimeUtils.h"

typedef struct
{
    TimePoint last_tick;
} SimpleTimer;

static inline SimpleTimer createSimpleTimer(void)
{
    SimpleTimer t = {currentTime()};
    return t;
}

static inline double elapsed(SimpleTimer* timer)
{
    const TimePoint new_tick = currentTime();
    const double ret = secondsElapsed(&timer->last_tick, &new_tick);
    timer->last_tick = new_tick;
    return ret;
}
