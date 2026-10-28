#include "Main/Unknown/code_020dac00.h"

void func_020dac00(Unk020da494 *p) {
    p->mUnk_c4 = (s32) (((s64) p->mUnk_c4 * 0x1266) >> 12);
    if (p->mUnk_c4 > 0x1800) {
        p->mUnk_80.mUnk_10 = 3;
        p->mUnk_80.mUnk_12 = 1;
    }
}
