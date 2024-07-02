#include "CurrentTime.h"
#include "GtestWrapper.hpp"

TEST(CurrentTimeC, date)
{
    DateBuffer d;
    date(d);
    print(d);
    this_thread::sleep_for(17ms);
    date(d);
    print(d);
}

TEST(CurrentTimeC, hour)
{
    HourBuffer h;
    hour(h);
    print(h);
    this_thread::sleep_for(17ms);
    hour(h);
    print(h);
}
