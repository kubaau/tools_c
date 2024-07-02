#include "ErrorChecks.h"
#include "GtestWrapper.hpp"

static bool succeededFoo(int i)
{
    return not i;
}
static bool failedBar(const void* p)
{
    return not p;
}

GENERATE_CHECK_INT(Foo)
GENERATE_REVERSE_CHECK_PTR(Bar)

TEST(ErrorChecksC, generate_check)
{
    checkFoo(0);
}

TEST(ErrorChecksC, generate_reverse_check)
{
    int i = 0;
    checkBar(&i);
}

TEST(ErrorChecksC, failedFgets)
{
    int i = 0;
    EXPECT_FALSE(failedFgets(&i));
    EXPECT_TRUE(failedFgets(NULL));
}
