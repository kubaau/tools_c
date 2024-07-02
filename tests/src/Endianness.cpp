#include "Endianness.h"
#include "DumpMemory.hpp"
#include "GtestWrapper.hpp"

TEST(EndiannessC, isLittleEndian)
{
    constexpr u16 val = 1;
    dumpMemory(&val);
    print(isLittleEndian());
}
