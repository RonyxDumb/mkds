#include "ITCM/code_01ff9320.h"
#include "ITCM/code_01ff8000.h"
#include "code_02147cd8.h"

// non-matching: same instructions and stores, but the constants are held in other registers (this one loads 0x1000
// into r3, 3 into r2, 2 into r1 and 0 into r0; the original keeps 0 in r1, 3 in r3, 2 in r2 and 0x1000 in r0), and
// the 64-bit products are compiled in a different order.
void func_01ff9320(Unk0201290c_1c *p) {
    Unk01ff9320_buf b;

    if (p->mUnk_00 & 8) {
        b.mUnk_00 = 0x101610;
    } else {
        b.mUnk_00 = 0x101810;
    }
    b.mUnk_08[15] = 0x1000;
    b.mUnk_04 = 3;
    b.mUnk_48 = 2;
    b.mUnk_08[14] = 0;
    b.mUnk_08[11] = 0;
    b.mUnk_08[10] = 0;
    b.mUnk_08[9] = 0;
    b.mUnk_08[8] = 0;
    b.mUnk_08[7] = 0;
    b.mUnk_08[6] = 0;
    b.mUnk_08[3] = 0;
    b.mUnk_08[2] = 0;
    ((Unk01ff9320_Fn *) 0x1ff9300)[p->mUnk_00 & 7](b.mUnk_08, p);
    if (p->mUnk_30 != 0x1000) {
        b.mUnk_08[0] = ((s64) p->mUnk_30 * b.mUnk_08[0]) >> 12;
        b.mUnk_08[1] = ((s64) p->mUnk_30 * b.mUnk_08[1]) >> 12;
        b.mUnk_08[12] = ((s64) p->mUnk_30 * b.mUnk_08[12]) >> 12;
    }
    if (p->mUnk_34 != 0x1000) {
        b.mUnk_08[4] = ((s64) p->mUnk_34 * b.mUnk_08[4]) >> 12;
        b.mUnk_08[5] = ((s64) p->mUnk_34 * b.mUnk_08[5]) >> 12;
        b.mUnk_08[13] = ((s64) p->mUnk_34 * b.mUnk_08[13]) >> 12;
    }
    func_01ff9048(b.mUnk_00, &b.mUnk_04, 0x12);
}

void func_01ff946c(s32 *o) {
    o[0] = 0x1000;
    o[1] = 0;
    o[4] = 0;
    o[5] = 0x1000;
    o[12] = 0;
    o[13] = 0;
}

// non-matching: size 0x40 against 0x44; the original computes -(x << 1) with lsl, rsb #0 and then add #0x2000 (this one
// folds it to rsb r, r, #0x2000), and holds the halfword in r3 with ip as the zero register.
void func_01ff9490(s32 *o, const Unk0201290c_1c *v1) {
    s32 t;

    o[0] = v1->mUnk_18[0];
    o[5] = v1->mUnk_18[1];
    o[1] = 0;
    o[12] = 0;
    t = -(v1->mUnk_18[1] << 1);
    o[13] = ((t + 0x2000) * v1->mUnk_2e) << 3;
    o[4] = 0;
}

// non-matching: size 0xc0 against 0xc4; the original negates with rsb #0 and adds #0x1000 afterwards in the two
// products at +0x30/+0x34 (this one folds them to rsb r, r, #0x1000 and add/sub order differs).
void func_01ff94d4(s32 *o, const Unk0201290c_1c *v1) {
    s32 a;
    s32 b;
    s32 t;

    a = v1->mUnk_2c << 12;
    b = v1->mUnk_2e << 12;
    func_02147d88(b, a);
    o[0] = v1->mUnk_20[1];
    o[5] = v1->mUnk_20[1];
    o[1] = (-v1->mUnk_20[0] * func_02147e28()) >> 12;
    func_02147d88(a, b);
    t = -(v1->mUnk_20[0] + v1->mUnk_20[1]);
    o[12] = (v1->mUnk_2c * (t + 0x1000)) << 3;
    o[13] = (v1->mUnk_2e * (v1->mUnk_20[0] - v1->mUnk_20[1] + 0x1000)) << 3;
    o[4] = (v1->mUnk_20[0] * func_02147e28()) >> 12;
}
