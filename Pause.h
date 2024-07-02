#pragma once

#include <stdio.h>
#include <stdlib.h>

static inline void pauseIO()
{
    getchar();
}

static inline void winIoPause()
{
#ifdef _WIN32
    system("pause");
#endif
}
