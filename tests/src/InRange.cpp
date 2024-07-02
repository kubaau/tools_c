#include "GtestWrapper.hpp"
#include "InRange.h"

TEST(InRangeC, inRange_open)
{
    EXPECT_TRUE(IN_RANGE(0, 0, 0, range_open));
    EXPECT_TRUE(IN_RANGE(0, 0, 1, range_open));
    EXPECT_TRUE(IN_RANGE(1, 0, 1, range_open));
    EXPECT_TRUE(IN_RANGE(1, 0, 2, range_open));
    EXPECT_TRUE(IN_RANGE(3, 1, 7, range_open));
    EXPECT_FALSE(IN_RANGE(0, 1, 1, range_open));
    EXPECT_FALSE(IN_RANGE(0, 1, 7, range_open));
    EXPECT_FALSE(IN_RANGE(8, 1, 7, range_open));
    EXPECT_FALSE(IN_RANGE(8, 1.3, 7.2, range_open));
}

TEST(InRangeC, inRange_closed)
{
    EXPECT_FALSE(IN_RANGE(0, 0, 0, range_closed));
    EXPECT_FALSE(IN_RANGE(0, 0, 1, range_closed));
    EXPECT_FALSE(IN_RANGE(1, 0, 1, range_closed));
    EXPECT_TRUE(IN_RANGE(1, 0, 2, range_closed));
    EXPECT_TRUE(IN_RANGE(3, 1, 7, range_closed));
    EXPECT_FALSE(IN_RANGE(0, 1, 1, range_closed));
    EXPECT_FALSE(IN_RANGE(0, 1, 7, range_closed));
    EXPECT_FALSE(IN_RANGE(8, 1, 7, range_closed));
}

TEST(InRangeC, inRange_open_left)
{
    EXPECT_FALSE(IN_RANGE(0, 0, 0, range_open_left));
    EXPECT_TRUE(IN_RANGE(0, 0, 1, range_open_left));
    EXPECT_FALSE(IN_RANGE(1, 0, 1, range_open_left));
    EXPECT_TRUE(IN_RANGE(1, 0, 2, range_open_left));
    EXPECT_TRUE(IN_RANGE(3, 1, 7, range_open_left));
    EXPECT_FALSE(IN_RANGE(0, 1, 1, range_open_left));
    EXPECT_FALSE(IN_RANGE(0, 1, 7, range_open_left));
    EXPECT_FALSE(IN_RANGE(8, 1, 7, range_open_left));
}

TEST(InRangeC, inRange_open_right)
{
    EXPECT_FALSE(IN_RANGE(0, 0, 0, range_open_right));
    EXPECT_FALSE(IN_RANGE(0, 0, 1, range_open_right));
    EXPECT_TRUE(IN_RANGE(1, 0, 1, range_open_right));
    EXPECT_TRUE(IN_RANGE(1, 0, 2, range_open_right));
    EXPECT_TRUE(IN_RANGE(3, 1, 7, range_open_right));
    EXPECT_FALSE(IN_RANGE(0, 1, 1, range_open_right));
    EXPECT_FALSE(IN_RANGE(0, 1, 7, range_open_right));
    EXPECT_FALSE(IN_RANGE(8, 1, 7, range_open_right));
}
