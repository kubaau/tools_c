#pragma once

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#ifndef __USE_GNU
#define __USE_GNU
#endif

#include <execinfo.h>
#include "Sigaction.h"

static inline SigActionSignature(printBacktrace)
{
    enum
    {
        backtrace_max_size = 20
    };
    void* bt[backtrace_max_size];

    void* caller_address = (void*)((struct ucontext_t*)ucontext)
#ifndef __cplusplus
                               ->uc_mcontext.__gregs[
#else
                               ->uc_mcontext.gregs[
#endif
#ifdef __i386__
                                   REG_EIP
#else
                                   REG_RIP
#endif
    ];

    ERROR_LOG("Signal %d (%s), address is %p from %p", signal, strsignal(signal), info->si_addr, caller_address);

    const Size bt_size = backtrace(bt, backtrace_max_size);

    bt[1] = caller_address; // overwrite sigaction with caller's address

    char** bt_symbols = backtrace_symbols(bt, bt_size);
    for (Size i = 1; i < bt_size; ++i) // skip first stack frame (points here)
        ERROR_LOG("%d: %s", i, bt_symbols[i]);
    free(bt_symbols);

    exit(EXIT_FAILURE);
}
