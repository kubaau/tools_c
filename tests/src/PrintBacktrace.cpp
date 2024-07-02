#ifndef _WIN32
#include "GtestWrapper.hpp"
#include "PrintBacktrace.h"

static void foo3(char)
{
    char* null = nullptr;
    *null = 1;
}

static void foo2()
{
    foo3('x');
}

[[maybe_unused]] static void foo1(int)
{
    foo2();
}

[[maybe_unused]] static void foo1() {}

TEST(PrintBacktraceC, bt)
{
    installSigaction(SIGSEGV, printBacktrace);
    // foo1(1);
}
#endif
