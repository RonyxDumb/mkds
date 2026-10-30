#include "Main/Unknown/code_02095228.h"
#include "Main/Unknown/code_020918a8.h"
#include "Main/Unknown/code_02093ff0.h"
#include "Main/Unknown/code_02094000.h"
#include "Main/Unknown/code_0209520c.h"
#include "Main/Unknown/unk_0215d000.h"

static inline u32 func_02095228_inline(Unk020f41c4_B *b, u32 n) {
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    if (n == 0) {
        return (u32) (b->mUnk_00 >> 32);
    }
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

static inline u32 func_020952dc_inline(Unk020f41c4_B *b, u32 n) {
    if (n == 0) {
        return 0;
    }
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    if (n == 0) {
        return (u32) (b->mUnk_00 >> 32);
    }
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

void func_02095228(Unk02095228 *a) {
    s32 i;
    Unk02094e8c *o;

    if (a == 0) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (o = a->mUnk_00[i]) != 0; i++) {
        o->mUnk_a0 = (u16) func_02095228_inline(&data_0217561c->mUnk_498, 0xf);
    }
}

// non-matching: the loop matches; in the random-range tail the original narrows the result to a halfword inside each branch (lsl/lsr r0, r0, #16 after the 0x10000 product) and re-narrows the count (lsl r0, r0, #16) before the zero test in the second branch, then both branches share one store to 0xa8 and one return; here the branches each end with their own store and return and the count is narrowed once (size 0x210 against 0x208, later words differ from +0x114)
void func_020952dc(Unk02094e8c *a, s32 b, s32 c, s32 d, s32 e) {
    s32 i;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    float f;
    u32 r;
    u16 q;
    Vec3 v;

    if (func_02093ff0() < b) {
        k = i = 0;
        for (; i < c; i++) {
            if (d > 0) {
                f = 0.5f + (float) (d << 12);
            } else {
                f = (float) (d << 12) - 0.5f;
            }
            z = 0;
            y = a->mUnk_00.mUnk_04.y;
            x = 0;
            r = func_02091f6c(func_0209520c(), (s32) f);
            q = func_020951b4(func_0209520c());
            v.x = x + func_0209518c(r, func_0209519c(q));
            v.y = y + func_02091f6c(func_0209520c(), k);
            v.z = z + func_0209518c(r, func_0209516c(q));
            func_02094000(&v);
        }
        if ((u16) e == 0x10000) {
            a->mUnk_a8 = (u16) func_02095228_inline(&data_0217561c->mUnk_498, 0x10000);
        } else {
            a->mUnk_a8 = (u16) func_020952dc_inline(&data_0217561c->mUnk_498, (u16) e);
        }
    }
}
