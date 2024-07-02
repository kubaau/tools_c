#pragma once

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "Logging.h"

static inline bool die(const char* func, size_t result)
{
    ERROR_LOG("%s failed, return value = %ld, errno = %d (%s)", func, result, errno, strerror(errno));
    exit(EXIT_FAILURE);
}

#ifndef _WIN32
#define MAYBE_UNUSED __attribute__((unused))
#else
#define MAYBE_UNUSED
#endif

#define GENERATE_CHECK(Function, Result)                               \
    MAYBE_UNUSED static inline void check##Function(Result result)     \
    {                                                                  \
        succeeded##Function(result) or die(__func__, (size_t)result);  \
    }                                                                  \
    MAYBE_UNUSED static inline Result checked##Function(Result result) \
    {                                                                  \
        check##Function(result);                                       \
        return result;                                                 \
    }

#define GENERATE_REVERSE_CHECK(Function, Result)                                                                \
    MAYBE_UNUSED static inline bool succeeded##Function(Result result) { return not failed##Function(result); } \
    GENERATE_CHECK(Function, Result)

#define GENERATE_CHECK_INT(Function) GENERATE_CHECK(Function, int)
#define GENERATE_REVERSE_CHECK_INT(Function) GENERATE_REVERSE_CHECK(Function, int)
#define GENERATE_CHECK_PTR(Function) GENERATE_CHECK(Function, const void*)
#define GENERATE_REVERSE_CHECK_PTR(Function) GENERATE_REVERSE_CHECK(Function, const void*)

static inline bool failedFgets(const void* result)
{
    return not result;
}
GENERATE_REVERSE_CHECK_PTR(Fgets)
