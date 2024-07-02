#ifndef _WIN32
#include "GtestWrapper.hpp"
#include "Sigaction.h"

static int counter;

static SigActionSignature(foo)
{
    ++counter;
}

TEST(SigactionC, installSigaction)
{
    counter = 0;
    installSigaction(SIGCONT, foo);
    raise(SIGCONT);
    EXPECT_EQ(1, counter);
}

TEST(SigactionC, failedSigaction)
{
    EXPECT_TRUE(failedSigaction(-1));
    EXPECT_FALSE(failedSigaction(0));
    EXPECT_TRUE(failedSigaction(1));
}

#endif
