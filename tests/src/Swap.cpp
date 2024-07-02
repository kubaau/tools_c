#include "GtestWrapper.hpp"
#include "Swap.h"

TEST(SwapC, swap)
{
    int a = 3;
    int b = 7;
    SWAP(int, a, b);
    EXPECT_EQ(7, a);
    EXPECT_EQ(3, b);

    float fa = 3.1f;
    float fb = 3.37f;
    SWAP(float, fa, fb);
    EXPECT_EQ(3.37f, fa);
    EXPECT_EQ(3.1f, fb);
}
