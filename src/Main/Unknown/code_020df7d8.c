#include "Main/Unknown/code_020df7d8.h"
#include "Main/Unknown/code_020d2000.h"

void func_020df83c(Unk020df6c8 *a) {
    if (a->mUnk_00.mUnk_80.mUnk_04 >= a->mUnk_a0) {
        a->mUnk_00.mUnk_80.mUnk_10 = 0;
        a->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}

u8 func_020df7d8(Unk020df6c8 *a, Unk020dea50_1 *b, void *c, u8 *d) {
    u32 m;

    m = (1 << b->mUnk_74) & 0xff;
    if ((a->mUnk_e4 & m) == 0) {
        if (func_020d26f8(&a->mUnk_00, (Unk0206bcb0 *) b) != 0) {
            a->mUnk_00.mUnk_78 |= data_02158778;
            a->mUnk_e4 |= m;
        }
    }
    return *d;
}
