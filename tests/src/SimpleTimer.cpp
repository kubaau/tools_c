#include "SimpleTimer.h"
#include "GtestWrapper.hpp"

TEST(SimpleTimerC, SimpleTimerC)
{    
    auto timer = createSimpleTimer();
    this_thread::sleep_for(10ms);
    print("elapsed:", elapsed(&timer));
}
