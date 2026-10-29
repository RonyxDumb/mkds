#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_020d8000.h"

#include "Main/Unknown/unk_0215d000.h"

void func_020e012c(Unk020e005c *a) {
    Unk020e0144 *b = &a->mUnk_144;
    s32 v = func_020d8cac(b);
    s32 w = (u16) (((s64) v << 18) >> 12);
    s16 t = data_0215d4b4[(w >> 4) * 2];
    s32 p = (s32) (((s64) t * a->mUnk_168) >> 12);
    s32 m;

    b->mUnk_04 = p > 0x200 ? p : 0x200;
    m = b->mUnk_00->mUnk_00[b->mUnk_0c].mUnk_34;
    if (p <= 0x200) {
        p = 0x200;
    }
    b->mUnk_10 = (s32) (((s64) p * m) >> 12);
    if (func_020d8cac(b) >= 0x100) {
        a->mUnk_080.mUnk_10 = 1;
        a->mUnk_080.mUnk_12 = 1;
    }
}

void func_020e00f8(Unk020e005c *a) {
    s32 v = a->mUnk_168;

    a->mUnk_144.mUnk_04 = v;
    a->mUnk_144.mUnk_10 = (s32) (((s64) v * a->mUnk_144.mUnk_00->mUnk_00[a->mUnk_144.mUnk_0c].mUnk_34) >> 12);
}

void func_020e005c(Unk020e005c *a) {
    Unk020e0144 *b = &a->mUnk_144;

    if (b->mUnk_20->mUnk_0e == 0) {
        Unk020e0144_00 *d = b->mUnk_00;
        s32 c;
        s32 f = 0;

        if (d->mUnk_08 == 0) {
            if (b->mUnk_18 != 0) {
                c = b->mUnk_0c == d->mUnk_04 - 1;
            } else {
                c = b->mUnk_0c == 0;
            }
            if (c) {
                f = 1;
            }
        }
        if (f == 0) {
            return;
        }
    }
    if (func_020d8cac(b) >= 0xf00) {
        a->mUnk_080.mUnk_10 = 2;
        a->mUnk_080.mUnk_12 = 1;
    }
}
