#pragma once

#define SWAP(T, lhs, rhs) \
    {                     \
        T temp = lhs;     \
        lhs = rhs;        \
        rhs = temp;       \
    }
