#include "Main/Unknown/code_020e5854.h"

void func_020e5854(Unk020e43a8 *p) {
    p->mUnk_c8 = p->mUnk_c8 - p->mUnk_cc;
    p->mUnk_00.mUnk_7e = p->mUnk_00.mUnk_7e + (s16) (((s64) p->mUnk_c8 * p->mUnk_c6) >> 12);
    if (p->mUnk_00.mUnk_80.mUnk_04 > *(u16 *) &p->mUnk_a0.mUnk_18.z) {
        p->mUnk_c6 = -p->mUnk_c6;
        p->mUnk_00.mUnk_80.mUnk_10 = 3;
        p->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}
