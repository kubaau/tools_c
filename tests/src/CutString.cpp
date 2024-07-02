#include "CutString.h"
#include "GtestWrapper.hpp"
#include "StringEquals.h"

TEST(CutStringC, cutFromBegin)
{
    EXPECT_TRUE(equals(cutFromBegin("", 3), ""));
    EXPECT_TRUE(equals(cutFromBegin("12", 3), ""));
    EXPECT_TRUE(equals(cutFromBegin("123456789", 3), "456789"));
}

TEST(CutStringC, cutFromEnd)
{
    char s[10];
    strcpy(s, "");
    EXPECT_TRUE(equals(cutFromEnd(s, 3), ""));
    strcpy(s, "12");
    EXPECT_TRUE(equals(cutFromEnd(s, 3), ""));
    strcpy(s, "123456789");
    EXPECT_TRUE(equals(cutFromEnd(s, 3), "123456"));
}
