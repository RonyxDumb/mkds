#pragma once

#include "types.h"

// Four words; func_0214e274 checks each against a range, func_0214e258 reads the first three.
typedef struct Unk0214e1e0 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk0214e1e0;

s64 func_0214e1e0(const Unk0214e1e0 *a, const Unk0214e1e0 *b);
