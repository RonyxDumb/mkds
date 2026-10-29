#include "Main/Unknown/code_020ab5bc.h"

#pragma thumb on

void func_020ab5bc(Unk0217b278_34 *p) {
    p->mUnk_00 = p->mUnk_00 + 1;
    if (p->mUnk_00 == p->mUnk_02 || p->mUnk_00 == p->mUnk_04) {
        p->mUnk_06 = 1;
    }
    if (p->mUnk_00 > p->mUnk_04) {
        p->mUnk_00 = p->mUnk_02 + 1;
    }
}

#pragma thumb off
