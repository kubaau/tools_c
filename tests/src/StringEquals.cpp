#include "GtestWrapper.hpp"
#include "StringEquals.h"

TEST(StringEqualsC, equals)
{
    EXPECT_TRUE(equals("str1", "str1"));
    EXPECT_FALSE(equals("str1", "str1 "));
}

TEST(StringEqualsC, empty)
{
    EXPECT_TRUE(empty(""));
    EXPECT_FALSE(empty(" "));
}
