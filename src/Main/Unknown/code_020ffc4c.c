#include "Main/Unknown/code_020ffc4c.h"

void func_020ffc98(Unk020ffb1c *p) {
    s16 d;

    p->mUnk_ac -= p->mUnk_b0;
    d = (s16) ((s32) (((s64) p->mUnk_ac * p->mUnk_a8) >> 12));
    if (d <= 0x96) {
        d = 0x96;
    }
    p->mUnk_a6 += d;
    if (p->mUnk_00.mUnk_80.mUnk_04 > p->mUnk_a0) {
        p->mUnk_00.mUnk_80.mUnk_10 = 5;
        p->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}

void func_020ffc4c(Unk020ffb1c *p) {
    s32 n;

    n = p->mUnk_a6;
    p->mUnk_bc = 0x1999 - n % 0x1999;
}
