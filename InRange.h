#pragma once

enum
{
    range_closed,
    range_open_left,
    range_open_right,
    range_open
};

#define IN_RANGE(Val, Min, Max, Openness)                     \
    (Openness == range_closed ? Val > Min and Val < Max :     \
                                Openness == range_open_left ? \
                                Val >= Min and Val < Max :    \
                                Openness == range_open_right ? Val > Min and Val <= Max : Val >= Min and Val <= Max)
