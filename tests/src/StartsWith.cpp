#include "StartsWith.h"
#include "GtestWrapper.hpp"

TEST(StartsWithC, startsWith)
{
    EXPECT_TRUE(startsWith("ala ma kota", "ala ma"));
    EXPECT_FALSE(startsWith("ala ma kota", "alama"));
}
