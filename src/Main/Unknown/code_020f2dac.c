#include "Main/Unknown/code_020f2dac.h"

#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_01ffd000.h"
#include "Main/Unknown/code_020f92e8.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02039860.h"
#include "code_02147cd8.h"

#pragma thumb on

// non-matching: 116 of 267 lines differ; both compile to 121 instructions and every instruction
// matches except where data_02175620->mUnk_58 and the third loop's counter live: the original
// stores the loaded value at [sp,#0] and reloads it for the four loop tests, holding the third
// counter in r7, while this source keeps the loaded value in r7 and spills the third counter to [sp,#4].
void func_020f357c(void) {
    Unk020f371c *e;
    Vec3 v;
    u32 n;
    u16 i;

    n = data_02175620->mUnk_58;
    e = data_02175620->mUnk_ac;
    i = 0;
    for (i = 0; i < 4; i++) {
        data_0217bc38[i] = 0;
    }
    for (i = 0; i < n; i++) {
        if (e->mUnk_1c >= 0x3e8000) {
            data_0217bc38[e->mUnk_20] = (s32) e;
        }
        e++;
    }
    e = data_02175620->mUnk_ac;
    for (i = 0; i < n; i++) {
        func_021484d0(e->mUnk_00[0]->mUnk_18, e->mUnk_18, &v);
        if ((s64) v.z * v.z + (s64) v.x * v.x + (s64) v.y * v.y >= 0x10) {
            func_02039860(&v, &v);
        }
        e->mUnk_21 = v.x >> 6;
        e->mUnk_22 = v.y >> 6;
        e->mUnk_23 = v.z >> 6;
        e++;
    }
}

#pragma thumb off

// non-matching: 9 of 267 lines differ. 0x130/0x1a4: the high word of the 64-bit store to the
// accumulator is addressed as [sl, #0x480] off the pointer local where the original uses
// [r9, #4] off the derived pointer; 0x194: the low sum stays in r3 (original r1) and the v.x
// load is hoisted above the store; 0x25c-0x26c: the multiply's variable takes r3 and its pool
// constant r1, the original has the two the other way round.
void func_020f3150(Unk0206bcb0 *p, Unk020edb8c *a, s32 b, s32 c, s32 d, s32 e, s32 f) {
    Unk020f41c4_B *q;
    Unk0217561c *o;
    Vec3 v;
    s32 n;
    s32 m;
    Vec3 *u;
    s32 dx;
    s32 dy;
    s32 dz;

    n = func_02039828((const Vec3 *) &a->mUnk_6c, (const Vec3 *) &a->mUnk_44);
    m = (a->mUnk_10->mUnk_48 & 1) != 0;
    n = (s32) (((s64) n * 0x1ec) >> 12);
    if (n < 0x666) {
        n = 0x666;
    }
    if (c != 0) {
        n = func_020edc9c((Unk020eda5c *) a, d, 0x1b33, 0x7000, &v);
    } else {
        n = func_020edb8c((Unk020eda5c *) a, n, 0x1000, 0x7000, &v);
    }
    if (c != 0) {
        if (a->mUnk_7c > 0) {
            n += (s32) (((s64) a->mUnk_7c * 0x14cd) >> 12);
        }
    }
    if (a->mUnk_68 < 0x3000) {
        o = data_0217561c;
        q = &o->mUnk_47c;
        o->mUnk_47c.mUnk_00 = q->mUnk_08 * q->mUnk_00 + q->mUnk_10;
        v.z += (u32) (((u64) (u32) (q->mUnk_00 >> 32) * 0xf6) >> 32) - 0x7b;
        o->mUnk_47c.mUnk_00 = q->mUnk_08 * q->mUnk_00 + q->mUnk_10;
        v.x += (u32) (((u64) (u32) (q->mUnk_00 >> 32) * 0xf6) >> 32) - 0x7b;
    }
    v.x = (s32) (((s64) v.x * n) >> 12);
    v.y = (s32) (((s64) v.y * n) >> 12);
    v.z = (s32) (((s64) v.z * n) >> 12);
    if (!m) {
        if (c != 0) {
            n = e + (s32) (((s64) a->mUnk_68 * 0x200) >> 12) + (s32) (((s64) a->mUnk_6c.y * 0x2000) >> 12);
        } else {
            n = f;
            n += (s32) (((s64) (a->mUnk_6c.y > 0 ? 0x666 : 0x1333) * a->mUnk_6c.y) >> 12);
        }
        func_02147fd8(n, (const Vec3 *) &a->mUnk_38, &v, &p->mUnk_05c);
    }
    if (c == 0) {
        func_02148504(&p->mUnk_05c, &a->mUnk_10->mUnk_1fc, &p->mUnk_05c);
    }
    if (c != 0) {
        p->mUnk_50 = a->mUnk_10->mUnk_1b8;
        func_02147fd8(p->mUnk_68.z * 10, (const Vec3 *) &a->mUnk_44, (Vec3 *) &p->mUnk_50, (Vec3 *) &p->mUnk_50);
    } else {
        if (a->mUnk_7c != 0 && a->mUnk_68 < 0x2000 && p->mUnk_68.z < 0xccd) {
            func_021484d0((const Vec3 *) &a->mUnk_38, (const Vec3 *) &a->mUnk_44, &v);
            func_02147fd8(0x2000, &v, (Vec3 *) &p->mUnk_50, (Vec3 *) &p->mUnk_50);
        }
    }
    if (p->mUnk_68.z < 0xccd) {
        u = (Vec3 *) &p->mUnk_68;
        u->x = 0xccd;
        u->y = 0xccd;
        u->z = 0xccd;
    }
    p->mUnk_12c.x = b;
    p->mUnk_124 = func_020f2dac;
    *(u32 *) &p->mUnk_74 &= ~0x7000000;
    if (!m) {
        return;
    }
    n = func_0214848c((const Vec3 *) &a->mUnk_38, &p->mUnk_05c);
    dx = (s32) (((s64) a->mUnk_38.x * n) >> 12);
    dy = (s32) (((s64) a->mUnk_38.y * n) >> 12);
    dz = (s32) (((s64) a->mUnk_38.z * n) >> 12);
    p->mUnk_05c.x -= dx;
    p->mUnk_05c.y -= dy;
    p->mUnk_05c.z -= dz;
    func_02147fd8(c != 0 ? 0x8800 : -0x1000, (const Vec3 *) &a->mUnk_38, &p->mUnk_05c, &p->mUnk_05c);
    p->mUnk_12c.x = 0;
}

void func_020f30ec(Unk0206bcb0 *a, s32 b, Vec3 *c) {
    if (c != 0) {
        a->mUnk_05c = *c;
    }
    if (a->mUnk_68.z < 0xccd) {
        a->mUnk_68.x = 0xccd;
        a->mUnk_68.y = 0xccd;
        a->mUnk_68.z = 0xccd;
    }
    a->mUnk_12c.x = b;
    a->mUnk_124 = func_020f2dac;
    *(u32 *) &a->mUnk_74 &= ~0x7000000;
}

void func_020f2df0(Unk0206bcb0 *a, s32 b, s32 c, s32 d, u32 *e) {
    Vec3 t;
    Vec3 u;
    Vec3 v;
    Vec3 *p;
    Vec3 *q;
    s32 n;

    p = &a->mUnk_05c;
    q = (Vec3 *) &a->mUnk_50;
    func_02148504(p, q, q);
    p->x = (s32) (((s64) p->x * c) >> 12);
    p->y = (s32) (((s64) p->y * c) >> 12);
    p->z = (s32) (((s64) p->z * c) >> 12);
    if (func_01ffdee4((int *) q, (u32 *) &a->mUnk_e4, 0, a->mUnk_dc, 0x24, ((s16 *) &a->mUnk_d8)[1], (int *) &t,
                      (int *) &u, (int *) &v, (u32 *) &a->mUnk_fc, (u32 *) 0, (int *) 0, (u16 *) 0, e) != 0) {
        func_02148504(&t, q, q);
        if (a->mUnk_fc & 0x1e34ef) {
            n = a->mUnk_12c.x;
            a->mUnk_12c.x = n - 1;
            if (n <= 0) {
                func_020f9334(a, q, p, b, &u);
            } else {
                *(u32 *) &a->mUnk_74 |= 0x10;
                n = func_0214848c(&u, p);
                t.x = (s32) (((s64) u.x * n) >> 12);
                t.y = (s32) (((s64) u.y * n) >> 12);
                t.z = (s32) (((s64) u.z * n) >> 12);
                p->x -= t.x;
                p->y -= t.y;
                p->z -= t.z;
                p->x = (s32) (((s64) p->x * 0x8cd) >> 12);
                p->y = (s32) (((s64) p->y * 0x8cd) >> 12);
                p->z = (s32) (((s64) p->z * 0x8cd) >> 12);
                func_02147fd8(-d, &t, p, p);
                a->mUnk_f0 = u;
            }
        }
        if (a->mUnk_fc & 0x214300) {
            *(u32 *) &a->mUnk_74 |= 0x20;
            func_020f92e8((u32) p, (u32) &v);
            if (func_020f9290(a, &v) != 0) {
                return;
            }
            *(u16 *) &a->mUnk_78 &= ~0x4000;
        }
        if (a->mUnk_fc & 0x8000) {
            func_020f7070(a, 1);
            return;
        }
    }
    *(u32 *) &a->mUnk_74 &= ~0x4000000;
    if (a->mUnk_fc & 0x1e34ef) {
        return;
    }
    p->y -= b;
    if (p->y < -0xa000) {
        p->y = -0xa000;
    }
}

void func_020f2dac(Unk0206bcb0 *a, Vec3 *b, Vec3 *c) {
    func_020f92e8((u32) &a->mUnk_05c, (u32) c);
    if (*(u32 *) &a->mUnk_74 & 0x1000000) {
        return;
    }
    *(u32 *) &a->mUnk_74 |= 0x1000000;
    a->mUnk_108.x = 0;
    a->mUnk_108.y = 0;
    a->mUnk_108.z = 0;
}
