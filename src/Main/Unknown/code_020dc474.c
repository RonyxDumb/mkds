#include "Main/Unknown/code_020dc474.h"
#include "code_02147cd8.h"

// non-matching: after the first compare the original loads the words at 0x10 and 0x18 again and keeps the compared word in r12, so it needs r4-r6 only; this build keeps a loaded word and takes r7 (0x164 bytes vs 0x168)
void func_020dc474(Unk020dc474 *p) {
    Vec3 a;

    if ((s64) (p->mUnk_00.mUnk_04.x - p->mUnk_a0.x) * (p->mUnk_00.mUnk_04.x - p->mUnk_a0.x) +
            (s64) (p->mUnk_00.mUnk_04.z - p->mUnk_a0.z) * (p->mUnk_00.mUnk_04.z - p->mUnk_a0.z) >=
        (s64) p->mUnk_1fc * p->mUnk_1fc) {
        func_021484d0(&p->mUnk_a0, &p->mUnk_00.mUnk_04, &a);
        p->mUnk_00.mUnk_10.x += (s32) (((s64) a.x << 2) >> 12);
        p->mUnk_00.mUnk_10.z += (s32) (((s64) a.z << 2) >> 12);
        if ((s64) p->mUnk_00.mUnk_10.x * p->mUnk_00.mUnk_10.x + (s64) p->mUnk_00.mUnk_10.z * p->mUnk_00.mUnk_10.z >=
            0x1000000) {
            p->mUnk_00.mUnk_10.x -= (s32) (((s64) p->mUnk_00.mUnk_10.x * 0x199) >> 12);
            p->mUnk_00.mUnk_10.z -= (s32) (((s64) p->mUnk_00.mUnk_10.z * 0x199) >> 12);
        }
        p->mUnk_00.mUnk_04.x += p->mUnk_00.mUnk_10.x;
        p->mUnk_00.mUnk_04.z += p->mUnk_00.mUnk_10.z;
    }
    if (p->mUnk_00.mUnk_80.mUnk_04 >= 0xb4) {
        p->mUnk_00.mUnk_80.mUnk_10 = 0;
        p->mUnk_00.mUnk_80.mUnk_12 = 1;
    }
}
