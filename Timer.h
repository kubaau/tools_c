#pragma once

#include "CurrentTime.h"
#include "TimeUtils.h"

typedef struct
{
    double delta_time;
    double total_time;
    bool paused;
    TimePoint last_tick;
} Timer;

static inline void resetTimer(Timer* t)
{
    t->last_tick = currentTime();
    t->delta_time = 0;
    t->total_time = 0;
    t->paused = false;
}

static inline Timer createTimer(void)
{
    Timer t;
    resetTimer(&t);
    return t;
}

static inline Timer* tickTimer(Timer* t)
{
    const TimePoint new_tick = currentTime();
    if (t->paused)
        t->delta_time = 0;
    else
    {
        t->delta_time = secondsElapsed(&t->last_tick, &new_tick);
        t->total_time += t->delta_time;
    }
    t->last_tick = new_tick;
    return t;
}
