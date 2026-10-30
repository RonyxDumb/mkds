#include "Main/Unknown/code_02028ec0.h"
#include "Main/Unknown/code_02028f08.h"

#pragma thumb on

void func_02028ec0(s32 a, s32 b, s32 c, Unk02174e14_00 *d) {
    Unk0201ea84 *p = func_02028f08(a, d->mUnk_0c);
    Unk0201ea84 *q = func_02028f08(b, d->mUnk_0c);
    d->mUnk_18[a].mUnk_04 = (100 - c) * (q->mUnk_00_0 - p->mUnk_00_0) / 100;
}

#pragma thumb off
