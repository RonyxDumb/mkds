#include "Main/Unknown/code_020a9f20.h"

#pragma thumb on

void func_020a9f20(Unk0217b278_10 *p, u32 a, u32 b, u32 c, u32 d) {
    if (p != 0) {
        p->mUnk_00 = a;
        p->mUnk_01 = b;
        p->mUnk_02 = c - a;
        p->mUnk_03 = d - b;
        p->mUnk_04 = 0;
        p->mUnk_06 = 0xff00;
    }
}

#pragma thumb off
