#include "Compare.h"
#include "PrintArray.h"
#include "RandomContainers.h"
#include "Unique.h"

#include "GtestWrapper.hpp"

TEST(RandomContainersC, fillWithRandomInts)
{
    int dest[10];
    fillWithRandomInts(dest, 10, -3, 7);
    printArray_int(dest, 10);

    qsort(dest, 10, sizeof(int), compare_int);
    printArray_int(dest, 10);

    EXPECT_TRUE(dest[0] >= -3);
    EXPECT_TRUE(dest[9] <= 7);
}

TEST(RandomContainersC, fillWithRandomFloats)
{
    float dest[10];
    fillWithRandomFloats(dest, 10, -3.14f, 7.17f);
    printArray_float(dest, 10);

    qsort(dest, 10, sizeof(float), compare_float);
    printArray_float(dest, 10);

    EXPECT_TRUE(dest[0] >= -3.14);
    EXPECT_TRUE(dest[9] <= 7.17);
}

TEST(RandomContainersC, fillWithRandomUniqueInts_largeWidth)
{
    int dest[10];
    fillWithRandomUniqueInts(dest, 10, 0, 100);
    printArray_int(dest, 10);

    qsort(dest, 10, sizeof(int), compare_int);
    printArray_int(dest, 10);

    EXPECT_TRUE(allUnique_int(dest, 10));
    EXPECT_TRUE(dest[0] >= 0);
    EXPECT_TRUE(dest[9] <= 100);
}

TEST(RandomContainersC, fillWithRandomUniqueInts_smallWidth)
{
    int dest[10];
    fillWithRandomUniqueInts(dest, 10, 0, 9);
    printArray_int(dest, 10);

    qsort(dest, 10, sizeof(int), compare_int);
    printArray_int(dest, 10);

    EXPECT_TRUE(allUnique_int(dest, 10));
    EXPECT_TRUE(dest[0] >= 0);
    EXPECT_TRUE(dest[9] <= 9);
}

TEST(RandomContainersC, shuffledIndexes)
{
    unsigned* is = shuffledIndexes(3);
    EXPECT_EQ(1, count(is, is + 3, 0u));
    EXPECT_EQ(1, count(is, is + 3, 1u));
    EXPECT_EQ(1, count(is, is + 3, 2u));
    free(is);
}

TEST(RandomContainersC, randomIndex)
{
    const unsigned i = randomIndex(10);
    EXPECT_TRUE(i < 10);
}

TEST(RandomContainersC, randomElement)
{
    int v[] = {1, 2, 3};
    const int elem = *(const int*)randomElement(v, sizeof(int), 3);
    EXPECT_TRUE(elem == 1 or elem == 2 or elem == 3);
}
