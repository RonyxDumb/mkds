#include "Main/Unknown/code_02092b3c.h"
#include "Main/Unknown/code_0209219c.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02147cd8.h"
#include "code_02148538.h"

static inline u32 func_02092b5c_inline(u32 n) {
    Unk020f41c4_B *b;

    b = func_020d22d0();
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

static inline u16 func_02092b5c_inline_2(u32 n) {
    Unk020f41c4_B *b;

    b = func_020d22d0();
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

void func_02092b3c(void) {
    func_0209bf48((u32) func_020930c8, (u32) func_02092b5c, 0);
}

// non-matching: the original keeps the loop constants (the three random ranges and the call arguments) in ten stack words set before the loop, 0x20 more stack than here, and allocates registers differently (80%)
void func_02092b5c(void *a, Unk020919e8 *p) {
    s32 i;
    s32 f;
    s32 q;
    u16 r;
    u16 k;
    s32 v1;
    s32 v2;
    s32 d;
    Unk0206bcb0 *o;
    Vec3 v3;
    Vec3 v4;

    if (p->mUnk_ac == 0) {
        if (func_02061818() == 2) {
            p->mUnk_ac = 1;
            return;
        }
        if (p->mUnk_00.mUnk_02 & 0x800) {
            if (p->mUnk_a4-- <= 0) {
                p->mUnk_a4 = 4;
                p->mUnk_ac = 1;
            }
            return;
        }
        k = p->mUnk_00.mUnk_7e;
        q = 0;
        for (i = 0; i < data_021759c0->mUnk_3d0; i++) {
            f = 0;
            if ((u32) data_021759c0->mUnk_70[(u16) i].mUnk_00 <= 3 &&
                ((1 << data_021759c0->mUnk_70[(u16) i].mUnk_00) & 0xd)) {
                f = 1;
            }
            if (f == 0 && i != data_021759c0->mUnk_62) {
                continue;
            }
            o = func_0207a974((u16) i);
            v2 = o->mUnk_80.z - p->mUnk_00.mUnk_04.z;
            v1 = o->mUnk_80.x - p->mUnk_00.mUnk_04.x;
            if ((s64) v2 * v2 + (s64) v1 * v1 >= 0x15f900000000LL) {
                continue;
            }
            d = func_02148714(o->mUnk_80.x - p->mUnk_00.mUnk_04.x, o->mUnk_80.z - p->mUnk_00.mUnk_04.z) - k;
            if (d < -0x1f40) {
                continue;
            }
            if (d <= 0x1f40) {
                q = 1;
                break;
            }
        }
        if (q != 0) {
            p->mUnk_a4 = 4;
            p->mUnk_ac = 1;
        }
        return;
    }
    if (p->mUnk_ac != 1) {
        return;
    }
    if (p->mUnk_a0 == 0x14) {
        for (i = 0; i < 2; i++) {
            v3.x = p->mUnk_00.mUnk_04.x - 0x5000 + func_02092b5c_inline(0xa000);
            v3.y = p->mUnk_00.mUnk_04.y + 0x23000 - 0x5000 + func_02092b5c_inline(0xa000);
            v3.z = p->mUnk_00.mUnk_04.z - 0x28000 + func_02092b5c_inline(0x50000);
            k = p->mUnk_00.mUnk_7e;
            r = func_02091f6c(func_020d22d0(), 0x1000) + 0x2000;
            k = k - 0xbb8 + func_02046524(func_020d22d0(), 0x1770);
            v4.x = func_020930a0(r, func_020930b0(k));
            v4.y = func_02091f6c(func_020d22d0(), 0x400) - 0xa00;
            v4.z = func_020930a0(r, func_02093080(k));
            if (i == 0 && p->mUnk_a8 == 0) {
                func_0209219c(0x8c, &v3, &v4, 0xf, 1, i == 0 ? 2 : 0);
            } else {
                func_0209219c(0x8c, &v3, &v4, 0xf, 0, i == 0 ? 2 : 0);
            }
        }
        p->mUnk_a8 += 1;
        if (p->mUnk_a8 >= 3) {
            p->mUnk_a8 = 0;
        }
    }
    k = p->mUnk_a0 + 1;
    if (k >= 0x32) {
        k = 0;
    }
    p->mUnk_a0 = k;
    if (p->mUnk_a0 != 0) {
        return;
    }
    if (p->mUnk_a4-- > 0) {
        return;
    }
    p->mUnk_a8 = 0;
    p->mUnk_ac = 0;
    if (p->mUnk_00.mUnk_02 & 0x800) {
        p->mUnk_a4 = (u16) (func_02092b5c_inline_2(25) + 200);
    }
}

s16 func_02093080(s32 a) {
    return data_0215d4b4[(a >> 4) * 2 + 1];
}

s32 func_020930a0(s32 a, s32 b) {
    return (s32) (((s64) a * b) >> 12);
}

s16 func_020930b0(s32 a) {
    return data_0215d4b4[(a >> 4) * 2];
}

void func_020930c8(Unk020e6fd4 *a) {
    s32 i;
    Unk020919e8 *p;

    if (a == 0) {
        return;
    }
    for (i = 0; i < a->mUnk_04 && (p = (Unk020919e8 *) a->mUnk_00[i]) != 0; i++) {
        if (p->mUnk_00.mUnk_02 & 0x800) {
            p->mUnk_a4 = (u16) (func_02092b5c_inline_2(25) + 200);
        }
    }
}
