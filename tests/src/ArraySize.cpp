#include "ArraySize.h"
#include "GtestWrapper.hpp"

TEST(ArraySizeC, arraySize)
{
    int a[3];
    EXPECT_EQ(3u, ARRAY_SIZE(a));
}

TEST(ArraySizeC, arraySizeInBytes)
{
    int a[3];
    EXPECT_EQ(12u, ARRAY_SIZE_IN_BYTES(a));
    char b[3];
    EXPECT_EQ(3u, ARRAY_SIZE_IN_BYTES(b));
}
