#include "BitCount.h"
#include "GtestWrapper.hpp"

TEST(BitCountC, bitsIn_type)
{
    EXPECT_EQ(8u, BITS_IN(u8));
    EXPECT_EQ(16u, BITS_IN(u16));
    EXPECT_EQ(32u, BITS_IN(u32));
    EXPECT_EQ(64u, BITS_IN(u64));
}

TEST(BitCountC, bitsIn_value)
{
    EXPECT_EQ(8u, BITS_IN(u8{}));
    EXPECT_EQ(16u, BITS_IN(u16{}));
    EXPECT_EQ(32u, BITS_IN(u32{}));
    EXPECT_EQ(64u, BITS_IN(u64{}));
}

TEST(BitCountC, countSetBits)
{
    EXPECT_EQ(0u, COUNT_SET_BITS(0));
    EXPECT_EQ(1u, COUNT_SET_BITS(1));
    EXPECT_EQ(1u, COUNT_SET_BITS(2));
    EXPECT_EQ(2u, COUNT_SET_BITS(3));
    EXPECT_EQ(1u, COUNT_SET_BITS(4));
    EXPECT_EQ(2u, COUNT_SET_BITS(5));
    EXPECT_EQ(2u, COUNT_SET_BITS(6));
    EXPECT_EQ(3u, COUNT_SET_BITS(7));
    EXPECT_EQ(1u, COUNT_SET_BITS(8));
    EXPECT_EQ(32u, COUNT_SET_BITS(-1));
    EXPECT_EQ(31u, COUNT_SET_BITS(-2));
}
