#pragma once

#include "types.h"

// 16 bytes: two words and two pointers to other Unk020169a4 (func_020169a4 and func_02016b00 unlink and relink them).
typedef struct Unk020169a4 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ struct Unk020169a4 *mUnk_08;
    /* 0c */ struct Unk020169a4 *mUnk_0c;
} Unk020169a4;

s32 func_020169a4(Unk020169a4 **a, Unk020169a4 **b, u32 c, u32 d);
s32 func_02016b00(Unk020169a4 **a, Unk020169a4 **b, u32 *c, u32 d, u32 e);
s32 func_02016c44(Unk020169a4 **a, Unk020169a4 **b, u32 *c, u32 d);
s32 func_02016c64(Unk020169a4 **a, Unk020169a4 **b, u32 c, u32 d);
Unk020169a4 *func_02016cd8(Unk020169a4 *p, u32 n);
