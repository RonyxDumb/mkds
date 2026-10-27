#include "Main/Unknown/code_021052fc.h"

void func_02105338(Unk021052fc *p, s32 a, Vec3 *v) {
    p->mUnk_04 = *p->mUnk_fc;
    if (a < 1) {
        a = 1;
    }
    p->mUnk_66 = a;
    p->mUnk_1c = (s32) (((s64) v->x * 0x666) >> 12);
    p->mUnk_20 = (s32) (((s64) v->y * 0x666) >> 12);
    p->mUnk_24 = (s32) (((s64) v->z * 0x666) >> 12);
}

void func_021052fc(Unk021052fc *p) {
    p->mUnk_a0 = p->mUnk_a0 + 1;
    if (p->mUnk_a0 >= 0x12c) {
        p->mUnk_a0 = 0;
    }
    p->mUnk_a2 = p->mUnk_a2 + 1;
    if (p->mUnk_a2 >= 0x82) {
        p->mUnk_a2 = 0;
    }
}
