#include "GtestWrapper.hpp"
#include "Iota.h"

TEST(IotaC, iota)
{
    int is[4];
    iota(is, 4);
    repeat(4) EXPECT_EQ(i, is[i]);
}
