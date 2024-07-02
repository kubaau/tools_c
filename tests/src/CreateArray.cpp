#include "CreateArray.h"
#include "GtestWrapper.hpp"

TEST(CreateArrayC, createFilledArray)
{
    CREATE_FILLED_ARRAY(int, a1, 3, 2);
    const int a1e[] = {2, 2, 2};
    EXPECT_EQ(0, memcmp(a1e, a1, sizeof(a1)));
    CREATE_FILLED_ARRAY(unsigned, a2, 3, 2);
    const unsigned a2e[] = {2, 2, 2};
    EXPECT_EQ(0, memcmp(a2e, a2, sizeof(a2)));
}
