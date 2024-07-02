#include "GtestWrapper.hpp"

#define MAX(lhs, rhs) (((lhs) > (rhs)) ? (lhs) : (rhs))
#define MIN(lhs, rhs) (((lhs) < (rhs)) ? (lhs) : (rhs))

TEST(MinMaxC, min)
{
    EXPECT_EQ(3, MIN(3, 4));
    EXPECT_EQ(3, MIN(4, 3));
    EXPECT_EQ(3.14, MIN(3.14, 3.15));
    EXPECT_EQ(3.14, MIN(3.15, 3.14));
}

TEST(MinMaxC, max)
{
    EXPECT_EQ(4, MAX(3, 4));
    EXPECT_EQ(4, MAX(4, 3));
    EXPECT_EQ(3.15, MAX(3.14, 3.15));
    EXPECT_EQ(3.15, MAX(3.15, 3.14));
}
