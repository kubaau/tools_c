#include "ContainerMemSize.hpp"
#include "DumpMemory.h"
#include "GtestWrapper.hpp"

TEST(DumpMemoryC, toBinary)
{
    char as_binary[CHAR_BIT + 1] = {0};
    toBinary((Byte)11, as_binary);
    EXPECT_EQ("00001011", string{as_binary});
    toBinary((Byte)0x7A, as_binary);
    EXPECT_EQ("01111010", string{as_binary});
    toBinary((Byte)-1, as_binary);
    EXPECT_EQ("11111111", string{as_binary});
    toBinary((Byte)-2, as_binary);
    EXPECT_EQ("11111110", string{as_binary});
}

TEST(DumpMemoryC, dumpMemory_struct)
{
    enable_debug_logs = true;
    struct S
    {
        int n = 7;
        char c = 0x7A;
    };
    S s;
    dumpMemory(&s, sizeof(S));
}

TEST(DumpMemoryC, dumpMemory_givenByteCount)
{
    enable_debug_logs = true;
    V v = {1, 2, 3};
    dumpMemory(v.data(), (v.size() - 1) * sizeof(V::value_type));
}

TEST(DumpMemoryC, dumpMemory_container)
{
    enable_debug_logs = true;
    V v = {1, 2, 3};
    dumpMemory(v.data(), memSize(v));
}
