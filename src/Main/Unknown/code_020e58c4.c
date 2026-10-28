#include "Main/Unknown/code_020e58c4.h"

void func_020e58c4(Unk020e43a8 *p) {
    p->mUnk_00.mUnk_7e = p->mUnk_00.mUnk_7e + p->mUnk_c6;
    if (*((u16 *) &p->mUnk_a0.mUnk_18.z + 1) == 0) {
        return;
    }
    if (p->mUnk_00.mUnk_80.mUnk_04 > *((u16 *) &p->mUnk_a0.mUnk_18.z + 1)) {
        p->mUnk_00.mUnk_80.mUnk_10 = 2;
        p->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}
