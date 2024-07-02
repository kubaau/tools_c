#pragma once

#include <signal.h>
#include "ErrorChecks.h"
#include "ZeroMemory.h"

typedef int Signal;
typedef void (*SigAction)(int, siginfo_t*, void*);
#define SigActionSignature(Action)                       \
    void Action(__attribute__((unused)) Signal signal,   \
                __attribute__((unused)) siginfo_t* info, \
                __attribute__((unused)) void* ucontext)

static inline struct sigaction createSigaction(SigAction action)
{
    struct sigaction sigact;
    ZERO_MEMORY(&sigact);
    sigact.sa_sigaction = action;
    sigact.sa_flags = SA_RESTART | SA_SIGINFO;
    return sigact;
}

static inline bool failedSigaction(int result)
{
    return result != 0;
}
GENERATE_REVERSE_CHECK_INT(Sigaction)

static inline void installSigaction(Signal signal, SigAction action)
{
    const struct sigaction sigact = createSigaction(action);
    struct sigaction* const ignore_old_sigact = NULL;
    checkSigaction(sigaction(signal, &sigact, ignore_old_sigact));
}
