#include "MemberOffset.h"
#include "GtestWrapper.hpp"

TEST(MemberOffsetC, offsetOfMember)
{
    struct S
    {
        u8 m1;
        __attribute__((aligned(8))) u64 m2;
        u16 m3[3];
        u16 pad;
        u32 m4;
        u8 m5;
        u8 m6;
        u32 m7;
        u8 m8;
        u16 m9;
    };

    ptrdiff_t ret;
    OFFSET_OF_MEMBER(S, m1, ret);
    EXPECT_EQ(0, ret);    
    OFFSET_OF_MEMBER(S, m2, ret);
    EXPECT_EQ(8, ret);
    OFFSET_OF_MEMBER(S, m3, ret);
    EXPECT_EQ(16, ret);
    OFFSET_OF_MEMBER(S, m4, ret);
    EXPECT_EQ(24, ret);
    OFFSET_OF_MEMBER(S, m5, ret);
    EXPECT_EQ(28, ret);
    OFFSET_OF_MEMBER(S, m6, ret);
    EXPECT_EQ(29, ret);
    OFFSET_OF_MEMBER(S, m7, ret);
    EXPECT_EQ(32, ret);
    OFFSET_OF_MEMBER(S, m8, ret);
    EXPECT_EQ(36, ret);
    OFFSET_OF_MEMBER(S, m9, ret);
    EXPECT_EQ(38, ret);
}
