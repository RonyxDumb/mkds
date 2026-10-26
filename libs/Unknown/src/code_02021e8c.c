#include "code_02021e8c.h"

Unk02021e40 *func_02021f48(Unk02021dc8 *a) {
    if (a->mUnk_02 & 1) {
        return (Unk02021e40 *) (a->mUnk_04 + a->mUnk_00 * 16);
    }
    return (Unk02021e40 *) (a->mUnk_04 + a->mUnk_00 * 8);
}

Unk02021e40 *func_02021f1c(Unk02021dc8 *a, u32 b) {
    if (b >= a->mUnk_00) {
        return 0;
    }
    if (a->mUnk_02 & 1) {
        return (Unk02021e40 *) (a->mUnk_04 + b * 16);
    }
    return (Unk02021e40 *) (a->mUnk_04 + b * 8);
}

void func_02021e8c(Unk02021dc8 *a) {
    Unk02021e40 *e;
    Unk02021e40 *p;
    u16 i;

    a->mUnk_04 += (u32) a;
    e = func_02021f48(a);
    for (i = 0; i < a->mUnk_00; i++) {
        p = func_02021f1c(a, i);
        p->mUnk_04 += (u32) e;
    }
    if (a->mUnk_0c != 0) {
        a->mUnk_0c = (Unk02021e40 *) ((u32) a->mUnk_0c + (u32) a);
        p = a->mUnk_0c;
        p->mUnk_04 += (u32) p;
        a->mUnk_0c = p;
    }
}
