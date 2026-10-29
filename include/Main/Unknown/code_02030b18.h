#pragma once

#include "types.h"

// Object whose u16 at 4 func_02030b18 and func_02030ea4 set.
typedef struct Unk02030b18 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk02030b18;

s32 func_02030b18(Unk02030b18 *a);
s32 func_02030ea4(Unk02030b18 *a);
