#include "Allocs.h"
#include "GtestWrapper.hpp"

TEST(AllocsC, malloc)
{
    int* p0 = MALLOC(int, 0);
    free(p0);
    int* p1 = MALLOC(int, 1);
    EXPECT_TRUE(p1);
    *p1 = 1;
    EXPECT_EQ(1, *p1);
    free(p1);
    int* p2 = MALLOC(int, 2);
    EXPECT_TRUE(p2);
    *p2 = 2;
    *(p2 + 1) = 3;
    EXPECT_EQ(2, *p2);
    EXPECT_EQ(3, *(p2 + 1));
    free(p2);
}

TEST(AllocsC, calloc)
{
    int* p0 = CALLOC(int, 0);
    free(p0);
    int* p1 = CALLOC(int, 1);
    EXPECT_TRUE(p1);
    EXPECT_EQ(0, *p1);
    *p1 = 1;
    EXPECT_EQ(1, *p1);
    free(p1);
    int* p2 = CALLOC(int, 2);
    EXPECT_TRUE(p2);
    EXPECT_EQ(0, *p2);
    EXPECT_EQ(0, *(p2 + 1));
    *p2 = 2;
    *(p2 + 1) = 3;
    EXPECT_EQ(2, *p2);
    EXPECT_EQ(3, *(p2 + 1));
    free(p2);
}

TEST(AllocsC, realloc)
{
    u8* pm = MALLOC(u8, 4);
    generate(pm, pm + 4, []() -> u8 { return 1; });

    u16* pr1 = REALLOC(u16, pm, 1);
    EXPECT_EQ(0x0101u, *pr1);

    u32* pr2 = REALLOC(u32, pr1, 1);
    *pr2 = 2;
    EXPECT_EQ(2u, *pr2);

    u32* pr3 = REALLOC(u32, pr2, 1);
    *pr3 = 3;
    EXPECT_EQ(3u, *pr3);

    free(pr3);
}
