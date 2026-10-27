#include "Main/Unknown/code_020e4ad0.h"

#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020e337c.h"
#include "code_02147cd8.h"

// non-matching: mUnk_100 sum: the compiled first product keeps both words live (low in r4)
// and merges them after the second product, where the original merges the first product at once
// (lsr r3/ orr r3) and moves it to r2 (add r2, r3, #0) before the final add.
// mUnk_10.y += (rng >> 32) >> 21: compiled emits lsr r1, r0, #21; mov r0, #0; orr ... lsl #11,
// the original keeps the zero word in r1 (lsl r1, r1, #11) before the orr.
void func_020e4ad0(Unk020e43a8 *p) {
    s32 y;

    p->mUnk_10.y -= 0x385;
    func_02148504(&p->mUnk_04, &p->mUnk_10, &p->mUnk_04);
    p->mUnk_100 = (s32) (((s64) p->mUnk_104 * (p->mUnk_04.x - p->mUnk_a0.mUnk_18.x)) >> 12) +
                  (s32) (((s64) p->mUnk_108 * (p->mUnk_04.z - p->mUnk_a0.mUnk_18.z)) >> 12);
    y = p->mUnk_a0.mUnk_18.y + p->mUnk_100;
    if (p->mUnk_04.y >= y) {
        return;
    }
    if (!(p->mUnk_78 & 4)) {
        Unk0210b7a8 s;
        u32 k;

        if (p->mUnk_70 == data_0217ca6c[2].mUnk_20) {
            k = 2;
        } else if (p->mUnk_70 == data_0217ca6c[3].mUnk_20) {
            k = 3;
        } else {
            k = 4;
        }
        s.mUnk_00 = 0x10b;
        s.mUnk_04 = &p->mUnk_04;
        s.mUnk_08 = k;
        s.mUnk_0c = func_020d4ef4(&p->mUnk_04);
        func_0210b7a8(&s);
    }
    p->mUnk_04.y = y;
    p->mUnk_c4 = p->mUnk_c4 - 1;
    if (p->mUnk_c4 == 0) {
        Unk020f41c4_B *r;

        p->mUnk_10.y = 0x3199;
        r = func_020d22d0();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        p->mUnk_c4 = (u16) (((u64) (u32) (r->mUnk_00 >> 32) * 3) >> 32) + 4;
    } else {
        Unk020f41c4_B *r;

        p->mUnk_10.y = 0x2000;
        r = func_020d22d0();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        p->mUnk_10.y = p->mUnk_10.y + (s32) (((u64) (u32) (r->mUnk_00 >> 32)) >> 21);
    }
    if (p->mUnk_04.x > p->mUnk_a0.mUnk_18.x + 0x14000) {
        p->mUnk_10.x = -0xccc;
    } else if (p->mUnk_04.x < p->mUnk_a0.mUnk_18.x - 0x14000) {
        p->mUnk_10.x = 0xccc;
    } else {
        Unk020f41c4_B *r;

        r = func_020d22d0();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        p->mUnk_10.x = (s32) (((u64) (u32) (r->mUnk_00 >> 32) * 0x1998) >> 32) - 0xccc;
    }
    if (p->mUnk_04.z > p->mUnk_a0.mUnk_18.z + 0x14000) {
        p->mUnk_10.z = -0xccc;
        return;
    }
    if (p->mUnk_04.z < p->mUnk_a0.mUnk_18.z - 0x14000) {
        p->mUnk_10.z = 0xccc;
        return;
    }
    {
        Unk020f41c4_B *r;

        r = func_020d22d0();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        p->mUnk_10.z = (s32) (((u64) (u32) (r->mUnk_00 >> 32) * 0x1998) >> 32) - 0xccc;
    }
}
