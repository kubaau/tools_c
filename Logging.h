#pragma once

#include <iso646.h>
#include "LoggingDetail.h"
#include "Typedefs.h"

#ifdef _DEBUG
#define ENABLE_DEBUG_LOGS true
#else
#define ENABLE_DEBUG_LOGS false
#endif
#define ENABLE_LOGGING                                      \
    bool enable_debug_logs = ENABLE_DEBUG_LOGS;             \
    thread_local char thread_name[thread_name_buffer_size]; \
    thread_local bool thread_name_initialized;              \
    thread_local char printf_buffer[log_buffer_size];

#define DEBUG_LOG(...)            \
    if (not enable_debug_logs) {} \
    else                          \
        LOG("DBG", __VA_ARGS__)
// do not remove this empty if branch; consider where the else belongs:
// if (cond)
//     DEBUG_LOG("");
// else
//     foo();
// if logging is not in the else branch, then calling foo() depends on enableDebugLogs()

#define FUNCTION_LOG DEBUG_LOG("")
#define INFO_LOG(...) LOG("INF", __VA_ARGS__)
#define WARN_LOG(...) LOG("WRN", __VA_ARGS__)
#define ERROR_LOG(...) LOG("ERR", __VA_ARGS__)

static inline const char* threadName(const char* name)
{
    if (not thread_name_initialized)
    {
        sprintf(thread_name,
                "0x%lx",
#ifndef _WIN32
                thrd_current());
#else
                GetCurrentThreadId());
#endif
        thread_name_initialized = true;
    }

    if (name)
    {
        const size_t name_length = strlen(name);
        if (name_length < thread_name_buffer_size)
            strcpy(thread_name, name);
        else
            WARN_LOG("%s is too long a thread name (length %d>=%d)", name, name_length, thread_name_buffer_size);
    }

    return thread_name;
}
