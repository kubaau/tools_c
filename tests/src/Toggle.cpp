#include "Toggle.h"

#include "GtestWrapper.hpp"

TEST(Toggle, toggle)
{
    bool b = false;
    toggle(&b);
    EXPECT_TRUE(b);
    toggle(&b);
    EXPECT_FALSE(b);
    EXPECT_TRUE(toggle(&b));
    EXPECT_FALSE(toggle(&b));
}
