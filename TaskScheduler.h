#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include "Logging.h"

typedef void* ScheduledTaskParams;
typedef void (*Task)(ScheduledTaskParams);

typedef int Repetitions;
static const Repetitions unlimited_repetitions = -1;

typedef struct
{
    Task task;
    Delay delay;
    Repetitions repetitions;
    Repetitions repetitions_so_far;
    TimePoint launch_time;
    bool active;
} ScheduledTask;

static inline void rescheduleTask(ScheduledTask* task)
{
    const TimePoint current_time = currentTime();
    task->launch_time.tv_sec = current_time.tv_sec + task->delay.tv_sec;
    task->launch_time.tv_nsec = current_time.tv_nsec + task->delay.tv_nsec;
}

static inline void resetTask(ScheduledTask* task)
{
    rescheduleTask(task);
    task->repetitions_so_far = 0;
}

static inline ScheduledTask createScheduledTask(Task task, const Delay* delay, Repetitions repetitions)
{
    ScheduledTask ret;
    ret.task = task;
    ret.delay = *delay;
    ret.repetitions = repetitions;
    ret.repetitions_so_far = 0;
    ret.active = true;
    resetTask(&ret);
    return ret;
}

static inline bool isTaskReady(const ScheduledTask* task)
{
    const TimePoint current_time = currentTime();
    return task->active and
        (current_time.tv_sec > task->launch_time.tv_sec or
         (current_time.tv_sec == task->launch_time.tv_sec and current_time.tv_nsec > task->launch_time.tv_nsec));
}

static void disableTask(ScheduledTask* task)
{
    task->active = false;
}

static inline void launchTask(ScheduledTask* task, ScheduledTaskParams params)
{
    if (not isTaskReady(task))
        return;

    if (task->repetitions == unlimited_repetitions or ++task->repetitions_so_far < task->repetitions)
        rescheduleTask(task);
    else
        disableTask(task);

    task->task(params);
}

static inline bool isStale(const ScheduledTask* task)
{
    return not task->active;
}

enum
{
    scheduled_tasks_max_count = 10
};

typedef struct
{
    ScheduledTask tasks[scheduled_tasks_max_count];
    Count task_count;
    void* params[scheduled_tasks_max_count];
} ScheduledTasks;

static inline ScheduledTask* scheduleTask(ScheduledTasks* tasks, const ScheduledTask* task, ScheduledTaskParams params)
{
    if (tasks->task_count >= scheduled_tasks_max_count)
    {
        WARN_LOG("Cannot schedule any more tasks");
        return NULL;
    }

    tasks->tasks[tasks->task_count] = *task;
    tasks->params[tasks->task_count] = params;
    return tasks->tasks + tasks->task_count++;
}

static inline void removeStaleTasks(ScheduledTasks* tasks)
{
    for (Count i = 0; i < tasks->task_count; ++i)
        if (tasks->params[i] and isStale(tasks->tasks + i))
        {
            free(tasks->params[i]);
            tasks->params[i] = NULL;
        }
}

static inline void launchScheduledTasks(ScheduledTasks* tasks)
{
    for (Count i = 0; i < tasks->task_count; ++i)
        launchTask(tasks->tasks + i, tasks->params[i]);

    removeStaleTasks(tasks);
}
