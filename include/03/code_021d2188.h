#pragma once

#include "types.h"
#include "Main/Unknown/types_02180728.h"
#include "code_02023374.h"

// 0x38-byte object; func_ov003_021d2288 sets it up.
typedef struct Unk021d2188 {
    /* 00 */ Unk02023374 mUnk_00;
    /* 20 */ Unk02180728 mUnk_20;
    /* 30 */ u8 *mUnk_30;
    /* 34 */ u32 mUnk_34;
} Unk021d2188;

void func_ov003_021d2188(Unk021d2188 *param_1);
void func_ov003_021d21f8(u32 param_1, u8 *param_2);
Unk021d2188 *func_ov003_021d2288(u32 param_1, u32 param_2);
