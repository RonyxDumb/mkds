#include "Main/Unknown/code_020a36a8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"
#include "code_02148538.h"

// non-matching: 4 bytes shorter (the original also saves r11); from the first 64-bit product on the registers and
// the order of the loads differ, 83 instructions.
void func_020a36a8(Unk020a2fe4 *a) {
    Unk0206bcb0 *p;
    Vec3 *q;
    Vec3 v;
    s32 s;
    s32 t;
    s32 v1;
    s32 v2;
    s32 v3;
    s32 v4;
    s32 v5;
    s32 v6;
    s32 v7;

    if (a->mUnk_a4 < 0) {
        a->mUnk_00.mUnk_10.y = a->mUnk_00.mUnk_10.y + 0x1800;
    } else {
        p = func_0207a974((u16) a->mUnk_a4);
        q = &p->mUnk_12c;
        a->mUnk_00.mUnk_10.x = a->mUnk_00.mUnk_10.x + (q->x + (q->x >> 1));
        a->mUnk_00.mUnk_10.y = a->mUnk_00.mUnk_10.y + (q->y + (q->y >> 1));
        a->mUnk_00.mUnk_10.z = a->mUnk_00.mUnk_10.z + (q->z + (q->z >> 1));
    }
    t = (s32) (((s64) 0xa000 * (a->mUnk_d0 + a->mUnk_d8)) >> 12);
    v3 = (a->mUnk_00.mUnk_04.z + a->mUnk_00.mUnk_10.z) - (a->mUnk_b0.z + a->mUnk_bc.z);
    v1 = (a->mUnk_00.mUnk_04.x + a->mUnk_00.mUnk_10.x) - (a->mUnk_b0.x + a->mUnk_bc.x);
    v6 = v3 < 0 ? -v3 : v3;
    v4 = v1 < 0 ? -v1 : v1;
    v7 = v4 / 2 + v6 / 2;
    if (v7 <= t) {
        a->mUnk_e0 = 1;
    } else if (a->mUnk_e0 != 0) {
        if (v7 > t) {
            s = func_02147f34(v7 - t, v7);
            v.x = (s32) (((s64) v1 * s) >> 12);
            v.y = 0;
            v.z = (s32) (((s64) v3 * s) >> 12);
            func_021484d0(&a->mUnk_00.mUnk_04, &v, &a->mUnk_00.mUnk_04);
        }
    }
    v1 = (a->mUnk_00.mUnk_04.x + a->mUnk_00.mUnk_10.x) - (a->mUnk_b0.x + a->mUnk_bc.x);
    v2 = (a->mUnk_00.mUnk_04.y + a->mUnk_00.mUnk_10.y) - (a->mUnk_b0.y + a->mUnk_bc.y);
    v3 = (a->mUnk_00.mUnk_04.z + a->mUnk_00.mUnk_10.z) - (a->mUnk_b0.z + a->mUnk_bc.z);
    v5 = v2 < 0 ? -v2 : v2;
    v4 = v1 < 0 ? -v1 : v1;
    v6 = v3 < 0 ? -v3 : v3;
    v7 = v5 + (v4 >> 2) + (v6 >> 2);
    t = (a->mUnk_d0 + a->mUnk_d8) << 4;
    if (v7 > t) {
        s = func_02147f34(v7 - t, v7);
        v.x = (s32) (((s64) v1 * s) >> 12);
        v.y = (s32) (((s64) v2 * s) >> 12);
        v.z = (s32) (((s64) v3 * s) >> 12);
        if (a->mUnk_a4 >= 0) {
            func_021484d0(&a->mUnk_00.mUnk_10, &v, &a->mUnk_00.mUnk_10);
        } else {
            func_02148504(&a->mUnk_bc, &v, &a->mUnk_bc);
        }
    }
    func_02148504(&a->mUnk_00.mUnk_04, &a->mUnk_00.mUnk_10, &a->mUnk_00.mUnk_04);
    func_02148504(&a->mUnk_b0, &a->mUnk_bc, &a->mUnk_b0);
}
