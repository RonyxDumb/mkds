#include "code_02021db0.h"

void func_02021dc8(Unk02021dc8 *a) {
    int t;
    u16 i;
    u16 j;
    Unk02021e1c *p;
    u32 q;
    s32 r;

    a->mUnk_04 += (u32) a;
    a->mUnk_08 += (u32) a;
    a->mUnk_0c = (Unk02021e40 *) ((u32) a->mUnk_0c + (u32) a);
    p = (Unk02021e1c *) a->mUnk_04;
    r = (u32) a->mUnk_0c;
    q = a->mUnk_08;
    for (i = 0; i < a->mUnk_00; i++) {
        t = p[i].mUnk_0c;
        p[i].mUnk_0c = q + t;
        for (j = 0; j < p[i].mUnk_00; j++) {
            ((Unk02021e40 *) p[i].mUnk_0c)[j].mUnk_00 = r + ((Unk02021e40 *) p[i].mUnk_0c)[(u32) j].mUnk_00;
        }
    }
}

void *func_02021db0(void *a, u32 b) {
    Unk02021dc8 *p = a;

    if (p->mUnk_00 > b) {
        return (Unk02021e1c *) p->mUnk_04 + b;
    }
    return 0;
}
