#pragma once

inline bool toggle(bool* flag)
{
    return *flag = not *flag;
}
