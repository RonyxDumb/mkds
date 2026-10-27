#include "Main/Unknown/code_020e34f8.h"

void func_020e34f8(Unk020e1e98 *a) {
    a->mUnk_004.y = a->mUnk_004.y + a->mUnk_010.y;
    if (a->mUnk_004.y > a->mUnk_0ac + 0x11199) {
        a->mUnk_004.y = a->mUnk_0ac + 0x11199;
        a->mUnk_080.mUnk_10 = 2;
        a->mUnk_080.mUnk_12 = 1;
    }
}
