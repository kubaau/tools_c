#include "GtestWrapper.hpp"
#include "Unique.h"

TEST(UniqueC, allUnique_int)
{
    int i[] = {1, 2, 3, 3};
    EXPECT_TRUE(allUnique_int(i, 3));
    EXPECT_FALSE(allUnique_int(i, 4));
}

TEST(UniqueC, allUnique_float)
{
    float f[] = {1.1f, 2.2f, 3.3f, 3.3f};
    EXPECT_TRUE(allUnique_float(f, 3));
    EXPECT_FALSE(allUnique_float(f, 4));
}
