#include "Main/Unknown/code_02009928.h"

#pragma thumb on

void func_02009928(u16 a, s32 b) {
    u16 v[2];
    if (b != 2 && b != 0) {
        v[0] = a;
        v[1] = b;
        data_0216fda8->mUnk_51c(0xff, (Unk021425e8 *) v);
    }
}

#pragma thumb off
