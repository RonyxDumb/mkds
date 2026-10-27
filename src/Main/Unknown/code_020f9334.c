#include "Main/Unknown/code_020f9334.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_01ffd000.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020f504c.h"
#include "Main/Unknown/code_020f5d6c.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_02109000.h"
#include "code_02147cd8.h"

s32 func_020f9c08(Unk020f41c4_A *param_1) {
    if (param_1->mUnk_11c > 0x12c && (param_1->mUnk_74 & 0x8000) != 0 &&
        param_1->mUnk_120 == (void (*)(Unk020f41c4_A *)) func_020f68b0) {
        return 1;
    }
    return 0;
}

void func_020f9ba8(Unk020f41c4_A *param_1) {
    if (param_1->mUnk_11c <= 0x12c) {
        return;
    }
    if ((param_1->mUnk_74 & 0x8000) == 0) {
        return;
    }
    if (param_1->mUnk_120 != (void (*)(Unk020f41c4_A *)) func_020f68b0) {
        return;
    }
    func_020f7658(param_1, 1);
}

void func_020f9b0c(Unk020f41c4_A *param_1) {
    if ((param_1->mUnk_74 & 0x8000) != 0) {
        func_020f7658(param_1, 1);
        return;
    }
    param_1->mUnk_5c.x = (s32) (((s64) param_1->mUnk_5c.x * 0x99a) >> 12);
    param_1->mUnk_5c.y = (s32) (((s64) param_1->mUnk_5c.y * 0x99a) >> 12);
    param_1->mUnk_5c.z = (s32) (((s64) param_1->mUnk_5c.z * 0x99a) >> 12);
    func_020f6fc4(param_1, 1);
}

void func_020f9a14(Unk020f41c4_A *param_1, s32 param_2) {
    void (*f)(void *);

    f = data_0217bc34[param_2].mUnk_18;
    param_1->mUnk_44 = param_2;
    param_1->mUnk_74 = 0;
    param_1->mUnk_7a = 0;
    param_1->mUnk_68 = 0;
    param_1->mUnk_6c = 0;
    param_1->mUnk_70 = 0;
    param_1->mUnk_100 = 0;
    param_1->mUnk_dc = 0x7b;
    param_1->mUnk_e0 = 0x7b;
    param_1->mUnk_d8 = 0x1f;
    param_1->mUnk_fc = 0;
    param_1->mUnk_118 = 0;
    param_1->mUnk_114 = 5;
    param_1->mUnk_124 = 0;
    param_1->mUnk_d0 = &param_1->mUnk_50;
    param_1->mUnk_da = -1;
    *param_1->mUnk_104 = 0;
    if (data_021759c0->mUnk_08 == 5) {
        param_1->mUnk_74 |= 0x8000000;
    }
    param_1->mUnk_78 |= data_02159cac;
    func_0208adc8(param_1->mUnk_7c.mUnk_00, 1);
    param_1->mUnk_90 = 0;
    if (f != 0) {
        f(param_1);
    }
    param_1->mUnk_128 = 0;
}

void func_020f99b8(Unk020f41c4_A *param_1, s32 param_2, u16 param_3, Vec3 *param_4) {
    param_1->mUnk_50 = *param_4;
    param_1->mUnk_78 = param_3;
    func_020f9a14(param_1, param_2);
    if ((param_1->mUnk_74 & 0x8000000) == 0) {
        return;
    }
    param_1->mUnk_4e = func_020ff178(param_1);
}

// non-matching: the two words of the data_0217bc34 lookup keep the opposite registers: the
// original emits `ldr r1,[r0]; ldr r2,[r4,#0x44]; mla r0,r2,r0,r1`, this emits
// `ldr r2,[r0]; ldr r1,[r4,#0x44]; mla r0,r1,r0,r2`.
void func_020f992c(Unk020f41c4_A *param_1) {
    if (param_1->mUnk_da != -1) {
        param_1->mUnk_da = func_020d5344(param_1->mUnk_da);
    }
    if ((param_1->mUnk_74 & 0x400000) != 0) {
        func_02109054(&param_1->mUnk_00);
        param_1->mUnk_00.mUnk_30 = 0;
        param_1->mUnk_74 &= ~0x400000;
    }
    param_1->mUnk_74 |= 4;
    if (data_0217bc34[param_1->mUnk_44].mUnk_3c != 0) {
        data_0217bc34[param_1->mUnk_44].mUnk_3c(param_1);
    }
}

// non-matching: the original copies the nine halfwords with post-increment addressing
// (`ldrh r1,[r3],#2; ldrh r0,[r3],#2; subs r2,r2,#1; strh r1,[ip],#2; strh r0,[ip],#2;
// bne`), this emits a load, an add and a store per halfword and `cmp r2,#0; bgt`;
// 0x9c bytes against 0x8c.
void func_020f98a0(void *param_1, Vec3 *param_2, Vec3 *param_3, u16 *param_4, s32 param_5) {
    Unk020f41c4_A *a = param_1;
    u16 *p;
    u16 *q;
    s32 i;

    a->mUnk_0e4 = *param_2;
    if (param_4 != 0) {
        p = a->mUnk_7c.mUnk_00;
        q = param_4;
        i = 4;
        do {
            *p++ = *q++;
            *p++ = *q++;
        } while (--i != 0);
        *p = *q;
    } else {
        func_0208adc8(a->mUnk_7c.mUnk_00, 1);
    }
    a->mUnk_f0 = *param_3;
    a->mUnk_116 = param_5 != 0 ? 0 : 5;
}

s32 func_020f9880(Unk020f41c4_A *param_1) {
    return data_0217bc34[param_1->mUnk_44].mUnk_84;
}

// non-matching: the differences and the radius keep the opposite registers: the
// original computes both differences in ip and the radius in r4, this reuses r4 for the first
// difference and the radius.
s32 func_020f97e0(Unk020f41c4_A *param_1, Unk0206bcb0 *param_2) {
    Vec3 d;
    u32 a;
    s32 n;

    if (param_1->mUnk_da != -1) {
        if ((param_1->mUnk_78 & 0x4000) != 0) {
            a = (u16) (param_1->mUnk_78 & ~0xff00);
        } else {
            a = 8;
        }
        if (param_2->mUnk_74 == (u16) a) {
            d.y = param_1->mUnk_50.y - param_2->mUnk_1d8.y;
            d.x = param_1->mUnk_50.x - param_2->mUnk_1d8.x;
            d.z = param_1->mUnk_50.z - param_2->mUnk_1d8.z;
            n = param_2->mUnk_1d0 + param_1->mUnk_e0;
            return (s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z < (s64) n * n;
        }
    }
    return 0;
}

// non-matching: the radius and the first difference keep the opposite registers: the original
// holds the radius in r5 and the differences in ip, this holds the radius in r2 and the
// differences in r4 and r5.
s32 func_020f9780(Unk020f41c4_A *param_1, Vec3 *param_2, s32 param_3) {
    Vec3 d;
    s32 n;

    d.y = param_1->mUnk_50.y - param_2->y;
    d.x = param_1->mUnk_50.x - param_2->x;
    d.z = param_1->mUnk_50.z - param_2->z;
    n = param_3 + param_1->mUnk_e0;
    return (s64) d.x * d.x + (s64) d.y * d.y + (s64) d.z * d.z < (s64) n * n;
}

void func_020f95d4(Unk020f41c4_A *param_1, Unk020f41c4_A *param_2) {
    Vec3 v;
    s32 a;
    s32 b;

    if (param_2->mUnk_da == -1) {
        return;
    }
    if ((param_2->mUnk_74 & 0x1000) != 0) {
        return;
    }
    if ((param_2->mUnk_74 & 0x8000) == 0) {
        if (param_1->mUnk_48 > param_2->mUnk_48) {
            return;
        }
    }
    if ((param_1->mUnk_74 & 0x10000000) != 0 && (param_2->mUnk_74 & 0x10000000) != 0) {
        if (func_020f7ea8(param_1, param_2) != 1 && func_020f7ea8(param_2, param_1) != 1) {
            return;
        }
    }
    if (func_020f9780(param_1, &param_2->mUnk_50, param_2->mUnk_e0) == 0) {
        if (func_020f9780(param_1, &param_2->mUnk_0e4, param_2->mUnk_e0) == 0) {
            return;
        }
        if (func_020f9780(param_2, &param_1->mUnk_0e4, param_1->mUnk_e0) == 0) {
            return;
        }
    }
    v = param_1->mUnk_5c;
    a = func_020f7ea8(param_1, param_2);
    b = func_020f7ea8(param_2, param_1);
    func_020f77f8(param_1, a, &param_2->mUnk_50, &param_2->mUnk_5c, 0);
    func_020f77f8(param_2, b, &param_1->mUnk_50, &v, 0);
    if (param_1->mUnk_44 == 1) {
        func_020f5614(param_1, a, param_2);
    }
    if (param_2->mUnk_44 != 1) {
        return;
    }
    func_020f5614(param_2, b, param_1);
}

void func_020f944c(void *param_1, void *param_2) {
    Vec3 a;
    Vec3 t;
    s32 b;
    Unk020f944c *q;
    Unk020f41c4_A *p = param_1;
    Unk020f944c *r = param_2;

    if (func_020d3e34(&p->mUnk_50, p->mUnk_e0, r, &a) == 0) {
        return;
    }
    if ((r->mUnk_02 & 0x40) == 0 && (p->mUnk_74 & 0x80000) == 0 && func_020d6968(p->mUnk_44, r) != 0) {
        func_02148504(&p->mUnk_50, &a, &p->mUnk_50);
    }
    switch (func_020d6a54(p, r, &b)) {
        case 1:
            t.x = r->mUnk_04.x;
            t.y = p->mUnk_50.y;
            t.z = r->mUnk_04.z;
            a = t;
            if (b == 1 || (r->mUnk_78 & 0x80000000) != 0) {
                r->mUnk_78 &= ~0x80000000;
                q = r;
            } else {
                r->mUnk_78 &= ~0x80000000;
                q = 0;
            }
            func_020f77f8(p, 1, &a, &r->mUnk_10, q);
            p->mUnk_78 &= ~0x4000;
            return;
        case 2:
            if (b == 1 || (r->mUnk_78 & 0x80000000) != 0) {
                r->mUnk_78 &= ~0x80000000;
                q = r;
            } else {
                r->mUnk_78 &= ~0x80000000;
                q = 0;
            }
            func_020f77f8(p, 2, &r->mUnk_04, &r->mUnk_10, q);
            return;
    }
}

// non-matching: only the order of the argument setup differs, the instructions are the same:
// the original loads all three components of v before storing any of them and keeps
// param_1->mUnk_dc in r4, this stores each component as it is computed and reloads
// mUnk_dc for the shift.
void func_020f9334(void *param_1, Vec3 *param_2, Vec3 *param_3, s32 param_4, Vec3 *param_5) {
    Unk020f41c4_A *p = param_1;
    Vec3 v;
    u32 a;

    a = 0;
    v.y = param_2->y - p->mUnk_dc;
    v.z = param_2->z;
    v.x = param_2->x;

    func_01ffdee4((int *) &v, (u32 *) param_2, 0, p->mUnk_dc >> 1, 0x24, p->mUnk_da, 0, 0, 0, &a, 0, 0, 0, 0);
    if ((a & 0x1e34ef) != 0 || (p->mUnk_fc & 0x80000) != 0) {
        if ((p->mUnk_74 & 0x4000000) != 0) {
            return;
        }
        p->mUnk_74 |= 8;
        p->mUnk_f0 = *param_5;
        return;
    }
    param_3->z = 0;
    param_3->x = param_3->z;
    if (param_3->y > 0) {
        param_3->y = 0;
        return;
    }
    if (param_3->y > -param_4) {
        param_3->y = -param_4;
    }
}
