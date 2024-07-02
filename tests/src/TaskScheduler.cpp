#include "Repeat.h"
#include "TaskScheduler.h"

#include "GtestWrapper.hpp"

static int counter;

void task(void*)
{
    ++counter;
}

struct RecursiveParams
{
    ScheduledTasks* ts;
};

static void scheduleTaskRecursive(void* params)
{
    RecursiveParams* p = (RecursiveParams*)params;
    Delay d = {};
    ScheduledTask t = createScheduledTask(task, &d, (Repetitions)1);
    scheduleTask(p->ts, &t, NULL);
}

TEST(TaskSchedulerC, task_scheduler)
{
    ScheduledTasks ts = {};

    Delay d = {};
    ScheduledTask t1 = createScheduledTask(task, &d, (Repetitions)1);
    scheduleTask(&ts, &t1, NULL); // 1

    d.tv_nsec = 1000000;
    ScheduledTask t2 = createScheduledTask(task, &d, (Repetitions)3);
    scheduleTask(&ts, &t2, NULL); // 3

    d.tv_nsec = 1;
    ScheduledTask t3 = createScheduledTask(task, &d, (Repetitions)2);
    ScheduledTask* t3_handle = scheduleTask(&ts, &t3, NULL); // 1 (disable)

    ScheduledTask t4 = createScheduledTask(task, &d, (Repetitions)3);
    ScheduledTask* t4_handle = scheduleTask(&ts, &t4, NULL); // 10 (reset)

    ScheduledTask t5 = createScheduledTask(scheduleTaskRecursive, &d, (Repetitions)1);
    RecursiveParams* rp = (RecursiveParams*)malloc(sizeof(RecursiveParams));
    rp->ts = &ts;
    scheduleTask(&ts, &t5, rp); // 1

    repeat(10)
    {
        this_thread::sleep_for(2ms);
        launchScheduledTasks(&ts);
        disableTask(t3_handle);
        EXPECT_TRUE(isStale(t3_handle));
        resetTask(t4_handle);
    }

    EXPECT_FALSE(isStale(t4_handle));

    EXPECT_EQ(16, counter);
}
