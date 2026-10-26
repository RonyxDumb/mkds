#include "code_0202210c.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_02134420.h"

// non-matching: the loop condition is built with predicated moves (moveq/movlt) instead of branches, and a->mUnk_1c is
// loaded once instead of twice
u32 func_0202212c(Unk02022030 *a, s32 b) {
    u32 r;
    s32 n;
    Unk02021e40 *c;
    u16 i;
    s32 *p;

    r = 0;
    if (a->mUnk_08 != 1) {
        return 0;
    }
    a->mUnk_0c += func_02134420((u32) (((s64) a->mUnk_10 * b + 0x800) >> 12));
    p = &a->mUnk_0c;
    while (a->mUnk_08 != 0 ? a->mUnk_0c >= (((Unk02022188 *) a->mUnk_00)->mUnk_04 << 12) : 0) {
        r = 1;
        *p = *p - (((Unk02022188 *) a->mUnk_00)->mUnk_04 << 12);
        if ((a->mUnk_10 > 0) ^ a->mUnk_04) {
            a->mUnk_00++;
        } else {
            a->mUnk_00--;
        }
        c = a->mUnk_00;
        if ((a->mUnk_10 > 0) ^ a->mUnk_04) {
            n = c >= &a->mUnk_18->mUnk_0c[a->mUnk_18->mUnk_00];
        } else {
            n = c <= &a->mUnk_18->mUnk_0c[a->mUnk_18->mUnk_02] - 1;
        }
        if (n) {
            func_02022310(a);
        }
        if (a->mUnk_1c != 0) {
            i = ((u32) a->mUnk_00 - (u32) a->mUnk_18->mUnk_0c) >> 3;
            switch (a->mUnk_1c) {
                case 2:
                    if (i == a->mUnk_28) {
                        a->mUnk_24(a->mUnk_20, i);
                    }
                    break;
                case 3:
                    a->mUnk_24(a->mUnk_20, i);
                    break;
            }
        }
    }
    return r;
}

u32 func_0202210c(Unk02022030 *a, u32 b) {
    u32 r;

    r = func_020222ec(a, b);
    if (r != 0) {
        a->mUnk_0c = 0;
    }
    return r;
}
