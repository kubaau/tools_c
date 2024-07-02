#pragma once

#include <stdlib.h>
#include "Logging.h"
#include "Pause.h"

inline static void check(bool result, const void* msg)
{
    if (not result)
    {
        ERROR_LOG("%s", msg);
        winIoPause();
        exit(EXIT_FAILURE);
    }
}
