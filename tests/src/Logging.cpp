#include "Logging.h"

#include "GtestWrapper.hpp"

ENABLE_LOGGING

TEST(LoggingC, log)
{
    INFO_LOG("1");
    INFO_LOG("%d", 2);
}

static string foo()
{
    FUNCTION_LOG;
    return __FUNCTION__;
}

TEST(LoggingC, enable_disable)
{
    enable_debug_logs = false;
    DEBUG_LOG("no");
    enable_debug_logs = true;
    DEBUG_LOG("yes");
    enable_debug_logs = false;
    DEBUG_LOG("no");
}

TEST(LoggingC, called_recursively)
{
    enable_debug_logs = true;
    DEBUG_LOG("%s", foo().c_str());
    INFO_LOG("%s", foo().c_str());
    WARN_LOG("%s", foo().c_str());
    ERROR_LOG("%s", foo().c_str());
}

TEST(LoggingC, if_else)
{
    enable_debug_logs = false;
    bool b = true;
    if (b)
        DEBUG_LOG("aaa");
    else
        b = false;
    EXPECT_TRUE(b);
    enable_debug_logs = true;
}
