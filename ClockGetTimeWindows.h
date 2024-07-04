#pragma once

#ifdef _WIN32

#include <time.h>

#include "Typedefs.h"
#include "tools/WindowsNoMinMax.hpp"

enum
{
    CLOCK_REALTIME
};

static inline struct timespec unixTime(void)
{
    i64 win_time;
    GetSystemTimeAsFileTime((FILETIME*)&win_time);

    win_time -= 116444736000000000; // 1 Jan 1601 to 1 Jan 1970
    enum
    {
        exp7 = 10000000
    };

    struct timespec ret;
    ret.tv_sec = win_time / exp7;
    ret.tv_nsec = win_time % exp7 * 100;
    return ret;
}

static inline int clock_gettime(int unused, struct timespec* spec)
{
    (void)unused;

    enum
    {
        nano_ratio = 1000 * 1000 * 1000
    };

    static struct timespec start_spec;
    static i64 ticks_per_sec;
    static i64 start_ticks;
    static double ticks_to_nano;
    static bool initialized = false;
    if (not initialized)
    {
        start_spec = unixTime();
        QueryPerformanceFrequency((LARGE_INTEGER*)&ticks_per_sec);
        QueryPerformanceCounter((LARGE_INTEGER*)&start_ticks);
        ticks_to_nano = (double)nano_ratio / ticks_per_sec;
        initialized = true;
    }

    i64 current_ticks;
    QueryPerformanceCounter((LARGE_INTEGER*)&current_ticks);
    current_ticks -= start_ticks;
    spec->tv_sec = start_spec.tv_sec + current_ticks / ticks_per_sec;
    spec->tv_nsec = start_spec.tv_nsec + (long)((current_ticks % ticks_per_sec) * ticks_to_nano);
    if (spec->tv_nsec >= nano_ratio)
    {
        spec->tv_sec++;
        spec->tv_nsec -= nano_ratio;
    }
    return 0;
}

#endif
