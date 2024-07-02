#include "CustomRangeAlgorithms.hpp"
#include "Timer.h"

#include "GtestWrapper.hpp"

TEST(TimerC, Timer)
{
    Timer t = createTimer();
    auto f = [&t](auto time) {
        this_thread::sleep_for(time);
        tickTimer(&t);
    };

    print(t.delta_time);
    print(t.total_time);

    f(17ms);
    print(t.delta_time);
    print(t.total_time);

    resetTimer(&t);
    print(t.delta_time);
    print(t.total_time);

    runInLoop(3, f, 10ms);
    print(t.delta_time);
    print(t.total_time);

    t.paused = true;
    runInLoop(3, f, 10ms);
    print(t.delta_time);
    print(t.total_time);

    t.paused = false;
    runInLoop(3, f, 10ms);
    print(t.delta_time);
    print(t.total_time);

    this_thread::sleep_for(10ms);
    print(tickTimer(&t)->delta_time);
}
