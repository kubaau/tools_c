#pragma once

#include "Logging.h"
#include "Repeat.h"
#include "StringEquals.h"

typedef struct
{
    int argc;
    char** argv;
} Args;

static inline Args createArgs(int argc, char** argv)
{
    Args ret;
    ret.argc = argc;
    ret.argv = argv;
    return ret;
}

static inline bool argsContains(const Args* args, const char* str)
{
    repeat(args->argc) if (equals(args->argv[i], str)) return true;
    return false;
}

static inline void debugArgs(const Args* args)
{
    DEBUG_LOG("Args:");
    repeat(args->argc) DEBUG_LOG("%s", args->argv[i]);
}
