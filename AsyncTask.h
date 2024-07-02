#pragma once

#include "Logging.h"

enum
{
    max_task_count = 10
};

typedef struct
{
    thrd_t tasks[max_task_count];
    Count count;
} AsyncTasks;

static inline AsyncTasks createAsyncTasks(void)
{
    AsyncTasks ret;
    ret.count = 0;
    return ret;
}

typedef void* TaskParams;
static inline void startTask(AsyncTasks* tasks, thrd_start_t task, TaskParams params)
{
    if (tasks->count < max_task_count)
        thrd_create(tasks->tasks + tasks->count++, task, params);
    else
        WARN_LOG("Cannot start any more tasks");
}

static inline void join(AsyncTasks* tasks)
{
    void* const ignore_join_result = NULL;
    for (Count i = 0; i < tasks->count; ++i)
        thrd_join(tasks->tasks[i], ignore_join_result);
}
