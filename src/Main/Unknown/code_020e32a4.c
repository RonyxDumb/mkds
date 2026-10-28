#include "Main/Unknown/code_020e32a4.h"

void func_020e32a4(Unk020e1e98 *a) {
    if (a->mUnk_0b4.mUnk_00 != 0) {
        a->mUnk_0b4.mUnk_04 += 0x400;
    } else {
        a->mUnk_0b4.mUnk_04 -= 0x400;
    }
    a->mUnk_000.mUnk_10.y -= 0x400;
    a->mUnk_000.mUnk_04.y = a->mUnk_000.mUnk_04.y + a->mUnk_000.mUnk_10.y;
    if (a->mUnk_000.mUnk_04.y < a->mUnk_0b0) {
        a->mUnk_000.mUnk_80.mUnk_10 = 5;
        a->mUnk_000.mUnk_80.mUnk_12 = 1;
    }
}
