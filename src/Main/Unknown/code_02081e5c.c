#include "Main/Unknown/code_02081e5c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_0201c528.h"

void func_02081e5c(Unk0201ca6c *p, s32 a) {
    u8 i;
    u8 j;
    Vec3 *v;
    Unk0206bcb0 *q;
    s32 x;
    s32 y;
    s32 z;

    if (a != 0) {
        return;
    }
    i = p->mUnk_98_24;
    j = p->mUnk_98_16;
    q = func_0207a974(i);
    v = q->mUnk_508;
    x = v->x;
    y = v->y;
    z = v->z;
    p->mUnk_28.x = (x >> 4) + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = (y >> 4) + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = (z >> 4) + p->mUnk_20->mUnk_00->mUnk_04.z;
    if (j >= p->mUnk_98_8) {
        if (j == p->mUnk_98_8) {
            p->mUnk_24.mUnk_00_0 = 1;
        }
    } else {
        p->mUnk_98_16 = j + 1;
    }
}
