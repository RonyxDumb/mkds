#include "Main/Unknown/code_0211d44c.h"

#pragma thumb on

u16 func_0211d478(s32 param_1) {
    Unk0217d368 *p;
    p = data_0217d368;
    if (p->mUnk_68[1] == 0) {
        return p->mUnk_ac[param_1];
    }
    return p->mUnk_ac[param_1] + p->mUnk_b0[param_1];
}

u32 func_0211d44c(s32 param_1) {
    if (func_0211d478(data_0217d368->mUnk_8c[param_1]) != 1) {
        return 1;
    }
    return 0;
}

#pragma thumb off
