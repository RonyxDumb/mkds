#include "Main/Unknown/code_02047634.h"
#include "Main/Unknown/unk_02175000.h"

#pragma thumb on

void func_02047634(void *a, s32 b, s32 c, u32 d, u32 e) {
    Unk021759c8_9b0 *p = &data_021759c8->mUnk_9b0[b];
    p->mUnk_00 = a;
    p->mUnk_04 = 0;
    p->mUnk_08_0 = c << 10;
    p->mUnk_08_29 = d;
    p->mUnk_08_30 = e;
    p->mUnk_08_31 = 1;
}

#pragma thumb off
