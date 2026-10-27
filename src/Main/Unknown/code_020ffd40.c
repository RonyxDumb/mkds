#include "Main/Unknown/code_020ffd40.h"

void func_020ffd40(Unk020ffb1c *p) {
    p->mUnk_ac += p->mUnk_b0;
    p->mUnk_a6 += (s16) ((s32) (((s64) p->mUnk_ac * p->mUnk_a8) >> 12));
    if (p->mUnk_00.mUnk_84 > p->mUnk_a0) {
        p->mUnk_00.mUnk_90 = 3;
        p->mUnk_00.mUnk_92 = 1;
    }
}
