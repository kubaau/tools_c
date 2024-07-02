#include "GtestWrapper.hpp"
#include "Repeat.h"

TEST(RepeatC, repeat_c)
{
    int sum = 0;
    repeat(3) sum += i;
    EXPECT_EQ(3, sum);
    repeat_j(4) sum += j;
    EXPECT_EQ(9, sum);
    repeat_count(2u) sum += static_cast<int>(i);
    EXPECT_EQ(10, sum);
}
