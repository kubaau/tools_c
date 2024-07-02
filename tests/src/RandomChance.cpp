#include "RandomChance.h"
#include "GtestWrapper.hpp"

TEST(RandomChanceC, chance)
{
    const auto to_be = chance(5);
    EXPECT_TRUE(to_be or not to_be);
}
