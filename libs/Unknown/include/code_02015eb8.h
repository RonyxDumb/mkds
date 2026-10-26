#pragma once

#include "types.h"

// Object with a flags word, three words at 0x04 and byte areas at 0x28 and 0x4c.
typedef struct Unk02015eb8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0x18];
    /* 28 */ u8 mUnk_28[0x24];
    /* 4c */ u8 mUnk_4c[0xc];
} Unk02015eb8;

void func_02015eb8(Unk02015eb8 *a, u32 *b, u32 c, u32 d);
void func_02015ef4(Unk02015eb8 *a);
s32 func_02015f78(void);
s32 func_02015f80(void);
s32 func_02015f88(void);
s32 func_02015f90(void);
