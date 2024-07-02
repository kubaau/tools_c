#include <gtest/gtest.h>
#include <iostream>
#include "DefaultRandomEngine.h"
#include "Iota.h"
#include "Random.h"
#include "Repeat.h"

using namespace std;

TEST(RandomC, randomInt)
{
    const auto r = randomInt(-3, 7);
    printf("%d\n", r);
    EXPECT_TRUE(r >= -3 and r <= 7);

    EXPECT_EQ(5, randomInt(5, 5));
}

TEST(RandomC, randomFloat)
{
    const auto r = randomFloat(-3.14f, 7.17f);
    printf("%f\n", r);
    EXPECT_TRUE(r >= -3.14 and r <= 7.17);

    EXPECT_EQ(5.5, randomFloat(5.5f, 5.5f));
}

TEST(RandomC, shuffle)
{
    int is[5];
    iota(is, 5);
    shuffle(is, 5);
    repeat(5) cout << is[i] << endl;
    EXPECT_EQ(1, count(cbegin(is), cend(is), 0));
    EXPECT_EQ(1, count(cbegin(is), cend(is), 1));
    EXPECT_EQ(1, count(cbegin(is), cend(is), 2));
    EXPECT_EQ(1, count(cbegin(is), cend(is), 3));
    EXPECT_EQ(1, count(cbegin(is), cend(is), 4));
}
