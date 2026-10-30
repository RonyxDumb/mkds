#pragma once

#include "types.h"
#include "03/unk_021da000.h"

typedef struct Unk021d1358 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18;
} Unk021d1358;

u32 func_ov003_021d11d4(void);
void func_ov003_021d1218(void);
u32 func_ov003_021d1290(void);
void func_ov003_021d1358(Unk021da2ac *param_1, Unk021d1358 *param_2);
