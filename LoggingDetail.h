#pragma once

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#ifdef _WIN32
#include <ext/threads.h>
#else
#include <threads.h>
#endif
#include "CurrentTime.h"
#include "FileName.h"

enum
{
    thread_name_buffer_size = 20,
    log_buffer_size = 4096
};

thread_local extern char thread_name[thread_name_buffer_size];
thread_local extern bool thread_name_initialized;
thread_local extern char printf_buffer[log_buffer_size];

extern bool enable_debug_logs;

static inline void logPrintf(const char* log_level,
                             const char* thrd_name,
                             const char* file_name,
                             int line,
                             const char* func_name,
                             const char* format,
                             ...)
{
    hour(printf_buffer);
    sprintf(
        printf_buffer + sizeof(HourBuffer) - 1, "/%s/%s/%s:%d/%s:\t", log_level, thrd_name, file_name, line, func_name);
    strcat(printf_buffer, format);
    strcat(printf_buffer, "\n");

    va_list args;
    va_start(args, format);
    vprintf(printf_buffer, args);
    va_end(args);

    fflush(stdout);
}

static inline const char* threadName(const char*);

#define LOG(Level, ...) logPrintf(Level, threadName(NULL), FILE_NAME, __LINE__, __func__, __VA_ARGS__)
