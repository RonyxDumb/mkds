#include "Main/Unknown/code_020e57fc.h"

#include "Main/Unknown/unk_02159000.h"

void func_020e5830(Unk020e43a8 *p) {
    if (p->mUnk_00.mUnk_80.mUnk_04 > p->mUnk_c4) {
        p->mUnk_00.mUnk_80.mUnk_10 = 0;
        p->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}

s32 func_020e57fc(Unk020e43a8 *p, Unk020e57fc *q, s32 param_3, u8 *param_4) {
    u32 x;

    x = q->mUnk_29c;
    if (x == 1 || x == 3) {
        p->mUnk_00.mUnk_78 |= data_021590e8;
    }
    return *param_4;
}
