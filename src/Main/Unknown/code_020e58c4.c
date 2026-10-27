#include "Main/Unknown/code_020e58c4.h"

void func_020e58c4(Unk020e43a8 *p) {
    p->mUnk_7e = p->mUnk_7e + p->mUnk_c6;
    if (*((u16 *) &p->mUnk_a0.mUnk_18.z + 1) == 0) {
        return;
    }
    if (p->mUnk_84 > *((u16 *) &p->mUnk_a0.mUnk_18.z + 1)) {
        p->mUnk_90 = 2;
        p->mUnk_92 = 1;
    }
}
