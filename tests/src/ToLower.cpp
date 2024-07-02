#include "GtestWrapper.hpp"
#include "StringEquals.h"
#include "ToLower.h"

TEST(ToLowerC, toLower)
{
    char buf[20];
    toLower("Ala ma kota", buf);
    EXPECT_TRUE(equals("ala ma kota", buf));
    toLower("Ala ma kota!", buf);
    EXPECT_TRUE(equals("ala ma kota!", buf));
    toLower("AlA mA KoTa", buf);
    EXPECT_TRUE(equals("ala ma kota", buf));
    toLower("ala ma kota", buf);
    EXPECT_TRUE(equals("ala ma kota", buf));
    toLower("", buf);
    EXPECT_TRUE(equals("", buf));
    toLower("#", buf);
    EXPECT_TRUE(equals("#", buf));
}
