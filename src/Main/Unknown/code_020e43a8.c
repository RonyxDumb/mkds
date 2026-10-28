#include "Main/Unknown/code_020e43a8.h"

void func_020e43a8(Unk020e43a8 *p) {
    p->mUnk_14c = p->mUnk_14c - p->mUnk_150;
    p->mUnk_7e = p->mUnk_7e + (s16) (((s64) p->mUnk_14c * p->mUnk_14a) >> 12);
    if (p->mUnk_80.mUnk_04 > p->mUnk_144) {
        p->mUnk_14a = -p->mUnk_14a;
        p->mUnk_80.mUnk_10 = 3;
        p->mUnk_80.mUnk_12 = 1;
    }
}
