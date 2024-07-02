#pragma once

#define OFFSET_OF_MEMBER(Struct, Member, Ret) \
    {                                         \
        const Struct s = {};                  \
        Ret = (Byte*)&(s.Member) - (Byte*)&s; \
    }
