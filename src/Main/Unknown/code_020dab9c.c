#include "Main/Unknown/code_020dab9c.h"

void func_020dab9c(Unk020da494 *p) {
    p->mUnk_c4 = (s32) (((s64) p->mUnk_c4 * 0xd99) >> 12);
    if (p->mUnk_c4 < 0x333) {
        p->mUnk_80.mUnk_10 = 4;
        p->mUnk_80.mUnk_12 = 1;
    }
}
