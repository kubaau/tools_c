#include "GtestWrapper.hpp"
#include "PrintArray.h"

TEST(PrintArrayC, printArray)
{
    int i[] = {1, 2, 3};
    printArray_int(i, 0);
    printArray_int(i, 1);
    printArray_int(i, 2);
    printArray_int(i, 3);

    float f[] = {1.1f, 2.2f, 3.3f};
    printArray_float(f, 0);
    printArray_float(f, 1);
    printArray_float(f, 2);
    printArray_float(f, 3);
}
