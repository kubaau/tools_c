#pragma once

#include <stdio.h>
#include "ClockGetTimeWindows.h"
#include "CutString.h"
#include "TimeTypedefs.h"

typedef char DateBuffer[30];
typedef char HourBuffer[19];

static inline TimePoint currentTime(void)
{
    TimePoint ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    return ts;
}

static inline long currentNanoseconds(void)
{
    return currentTime().tv_nsec;
}

static inline void date(char* s)
{
    const time_t time_t = time(NULL);
    const struct tm tm = *localtime(&time_t);

#if not defined(__clang__) and not defined(_WIN32)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-overflow"
#endif
    sprintf(s,
            "%02d.%02d.%d %02d:%02d:%02d.%09ld",
            tm.tm_mday,
            tm.tm_mon + 1,
            tm.tm_year + 1900,
            tm.tm_hour,
            tm.tm_min,
            tm.tm_sec,
            currentNanoseconds());
#if not defined(__clang__) and not defined(_WIN32)
#pragma GCC diagnostic pop
#endif
}

static inline void hour(char* s)
{
    DateBuffer d;
    date(d);
    strcpy(s, cutFromBegin(d, sizeof(DateBuffer) - sizeof(HourBuffer)));
}
