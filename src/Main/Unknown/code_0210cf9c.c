#include "Main/Unknown/code_0210cf9c.h"

void func_0210cfbc(Unk0210bfbc *p, s32 b, s32 c) {
    if (c == 1) {
        p->mUnk_34 |= 1 << b;
    } else {
        p->mUnk_34 &= ~(1 << b);
    }
}

void func_0210cf9c(Unk0210bfbc *p, s32 b) {
    if (b == 1) {
        p->mUnk_34 |= 1;
    } else {
        p->mUnk_34 &= ~1;
    }
}
