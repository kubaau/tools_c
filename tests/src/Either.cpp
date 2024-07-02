#include "Either.h"
#include "GtestWrapper.hpp"

TEST(EitherC, either)
{
    const auto to_be = either();
    EXPECT_TRUE(to_be or not to_be); // lel
}
