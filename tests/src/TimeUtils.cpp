#include "TimeUtils.h"

#include "GtestWrapper.hpp"

TEST(TimeUtilsC, isZero)
{
    Duration d{};
    EXPECT_TRUE(isZero(&d));
    d.tv_nsec = 1;
    EXPECT_FALSE(isZero(&d));
    d = {};
    EXPECT_TRUE(isZero(&d));
}

TEST(TimeUtilsC, compareTime)
{
    timeval t1{};
    timeval t2{};
    EXPECT_EQ(compareTime(&t1, &t2), 0);
    t1.tv_sec = -1;
    EXPECT_LT(compareTime(&t1, &t2), 0);
    t1.tv_sec = 1;
    EXPECT_GT(compareTime(&t1, &t2), 0);
    t2.tv_sec = 1;
    EXPECT_EQ(compareTime(&t1, &t2), 0);
    t2.tv_usec = 1;
    EXPECT_LT(compareTime(&t1, &t2), 0);
    t1.tv_usec = 2;
    EXPECT_GT(compareTime(&t1, &t2), 0);
}
