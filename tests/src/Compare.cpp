#include "Compare.h"
#include "GtestWrapper.hpp"

TEST(CompareC, compare_int)
{
    int i1 = -2;
    int i2 = 3;
    EXPECT_EQ(-1, compare_int(&i1, &i2));
    EXPECT_EQ(0, compare_int(&i2, &i2));
    EXPECT_EQ(1, compare_int(&i2, &i1));
}

TEST(CompareC, compare_float)
{
    float f1 = -2.14f;
    float f2 = 3.17f;
    EXPECT_EQ(-1, compare_float(&f1, &f2));
    EXPECT_EQ(0, compare_float(&f2, &f2));
    EXPECT_EQ(1, compare_float(&f2, &f1));
}
