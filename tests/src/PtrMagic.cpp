#include "PtrMagic.h"
#include "GtestWrapper.hpp"

TEST(PtrMagicC, moveNBytes_int)
{
    int n[3];
    auto p = n;
    p = reinterpret_cast<decltype(p)>(moveNBytes(p, 8));
    EXPECT_EQ(n + 2, p);
    p = reinterpret_cast<decltype(p)>(moveNBytes(p, -8));
    EXPECT_EQ(n, p);
    p = reinterpret_cast<decltype(p)>(moveNBytes(p, 5));
    EXPECT_EQ(reinterpret_cast<size_t>(n) + 5, reinterpret_cast<size_t>(p));
}

TEST(PtrMagicC, moveNBytes_const_short)
{
    const short n[5] = {};
    auto p = n;
    p = reinterpret_cast<decltype(p)>(moveNBytes(p, 8));
    EXPECT_EQ(n + 4, p);
    p = reinterpret_cast<decltype(p)>(moveNBytes(p, -8));
    EXPECT_EQ(n, p);
    p = reinterpret_cast<decltype(p)>(moveNBytes(p, 5));
    EXPECT_EQ(reinterpret_cast<size_t>(n) + 5, reinterpret_cast<size_t>(p));
}
