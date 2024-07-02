#pragma once

#include <iso646.h>
#include <stdbool.h>
#include "Ratios.h"
#include "TimeTypedefs.h"
#ifndef _WIN32
#include <sys/time.h>
#else
#include <winsock.h>
#endif

static inline bool isZero(Duration* duration)
{
    return not(duration->tv_sec or duration->tv_nsec);
}

static inline int compareTime(const struct timeval* lhs, const struct timeval* rhs)
{
    if (lhs->tv_sec < rhs->tv_sec)
        return -1;
    if (lhs->tv_sec > rhs->tv_sec)
        return 1;
    if (lhs->tv_usec < rhs->tv_usec)
        return -1;
    if (lhs->tv_usec > rhs->tv_usec)
        return 1;
    return 0;
}

static inline double secondsElapsed(const TimePoint* from, const TimePoint* to)
{
    const time_t elapsed_s = to->tv_sec - from->tv_sec;
    const long elapsed_ns = to->tv_nsec - from->tv_nsec;
    return elapsed_s + (double)elapsed_ns / (int)nano_denominator;
}
