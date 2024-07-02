#pragma once

#include "Repeat.h"

#define CREATE_FILLED_ARRAY(T, Name, Size, Value) \
    T Name[Size];                                 \
    repeat(Size) Name[i] = Value;
