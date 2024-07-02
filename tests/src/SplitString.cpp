#include "Allocs.h"
#include "GtestWrapper.hpp"
#include "Repeat.h"
#include "SplitString.h"

TEST(SplitStringC, unifyDelimeters)
{
    char s[] = "ala:ma kota";
    unifyDelimiters(s, "");
    EXPECT_TRUE(equals("ala:ma kota", s));
    unifyDelimiters(s, ": ");
    EXPECT_TRUE(equals("ala:ma:kota", s));
    unifyDelimiters(s, "");
    EXPECT_TRUE(equals("ala:ma:kota", s));
}

TEST(SplitStringC, split)
{
    char* strs[3];
    repeat(3) strs[i] = MALLOC(char, 5);

    EXPECT_EQ(0u, split(strs, "", " "));

    EXPECT_EQ(1u, split(strs, "a", " "));
    EXPECT_TRUE(equals("a", strs[0]));

    EXPECT_EQ(2u, split(strs, "a b", " "));
    EXPECT_TRUE(equals("a", strs[0]));
    EXPECT_TRUE(equals("b", strs[1]));

    EXPECT_EQ(2u, split(strs, "a  b", " "));
    EXPECT_TRUE(equals("a", strs[0]));
    EXPECT_TRUE(equals("b", strs[1]));

    EXPECT_EQ(3u, split(strs, "ala ma kota", " "));
    EXPECT_TRUE(equals("ala", strs[0]));
    EXPECT_TRUE(equals("ma", strs[1]));
    EXPECT_TRUE(equals("kota", strs[2]));

    EXPECT_EQ(3u, split(strs, "ala:ma:kota", ":"));
    EXPECT_TRUE(equals("ala", strs[0]));
    EXPECT_TRUE(equals("ma", strs[1]));
    EXPECT_TRUE(equals("kota", strs[2]));

    EXPECT_EQ(3u, split(strs, "ala::ma:kota", ":"));
    EXPECT_TRUE(equals("ala", strs[0]));
    EXPECT_TRUE(equals("ma", strs[1]));
    EXPECT_TRUE(equals("kota", strs[2]));

    EXPECT_EQ(3u, split(strs, "ala:ma kota", ": "));
    EXPECT_TRUE(equals("ala", strs[0]));
    EXPECT_TRUE(equals("ma", strs[1]));
    EXPECT_TRUE(equals("kota", strs[2]));

    EXPECT_EQ(0u, split(strs, "ala:ma kota", ""));

    repeat(3) free(strs[i]);
}
