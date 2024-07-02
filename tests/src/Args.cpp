#include "Args.h"
#include "GtestWrapper.hpp"

TEST(ArgsC, args)
{
    constexpr auto argc = 3;
    char* argv[argc];

    const auto args = createArgs(argc, argv);
    EXPECT_EQ(argc, args.argc);
    EXPECT_EQ(argv, args.argv);
}
