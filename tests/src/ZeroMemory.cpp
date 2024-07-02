#include "GtestWrapper.hpp"
#include "ZeroMemory.h"

TEST(ZeroMemoryC, zero)
{
    struct Data
    {
        int i;
        float f;
    } d{1, 2};

    ZERO_MEMORY(&d);
    CHECK_ZERO_MEMORY(&d);

    char zeroed[sizeof(Data)] = {};
    EXPECT_EQ(0, memcmp(&d, zeroed, sizeof(Data)));
}
