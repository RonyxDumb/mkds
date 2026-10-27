#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020f1000.h"
#include "Main/Unknown/code_020f2000.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_01ffd000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02047b08.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02135014.h"
#include "code_02147cd8.h"

#pragma thumb on
#pragma optimize_for_size on

// non-matching: the argument test is `adds r3, r0, #0; cmp r3, #0` in the
// original; the compiled code compares r0 directly, so the copy of the first
// argument is missing and every later word shifts (8 words).
void *func_020ed548(u8 *a) {
    u8 buf[0x100];

    if (a == 0) {
        return 0;
    }
    func_02135048(buf, 0x100, data_0216c604);
    func_02047b08((u32) buf);
}

Unk020e6488 *func_020ed4d0(u8 *a, u8 *b, u8 *c) {
    Unk020e6488 *p;
    void *q;
    void *r;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    q = func_020ed548(a);
    r = func_020ed548(b);
    func_020e64b8(p, q, r, 0);
    p->mUnk_14 &= 0xc0ffffff;
    p->mUnk_14 |= 0x04000000;
    p->mUnk_14 &= ~0xf;
    p->mUnk_14 |= 0x2;
    p->mUnk_10 &= 0x8000ffff;
    p->mUnk_10 |= 0x10840000;
    return p;
}

void *func_020ed490(u8 *a, u8 *b) {
    void *p;
    void *q;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x6c);
    q = func_020ed548(a);
    func_02084e28(p, q);
    func_02084968(p, 4, 2, 0x294a);
    return p;
}

// non-matching: the loops walk the two tables with a pointer that is advanced
// each iteration, where the original scales the counter for every load and
// store (0x18c bytes against 0x198).
void func_020ed2f8(void) {
    s32 i;
    void *p;
    s32 f;

    i = 0;
    while (i < 0xe) {
        data_0217bbfc[i] = 0;
        i++;
    }
    data_0217bbfc[0] = func_020ed4d0(data_0216c42c, 0, data_0216c440);
    data_0217bbfc[1] = func_020ed4d0(data_0216c454, 0, data_0216c468);
    data_0217bbfc[2] = func_020ed4d0(data_0216c47c, 0, data_0216c48c);
    data_0217bbfc[3] = func_020ed4d0(data_0216c49c, 0, data_0216c4ac);
    data_0217bbfc[4] = func_020ed4d0(data_0216c4bc, 0, data_0216c4cc);
    data_0217bbfc[5] = func_020ed4d0(data_0216c4dc, 0, data_0216c4f0);
    data_0217bbfc[6] = func_020ed4d0(data_0216c504, 0, data_0216c518);
    data_0217bbfc[7] = func_020ed4d0(data_0216c52c, 0, data_0216c53c);
    data_0217bbfc[9] = func_020ed4d0(data_0216c54c, data_0216c55c, data_0216c56c);
    data_0217bbfc[10] = func_020ed4d0(data_0216c57c, 0, data_0216c58c);
    data_0217bbfc[11] = func_020ed4d0(data_0216c59c, 0, data_0216c5ac);
    data_0217bbfc[12] = func_020ed4d0(data_0216c5bc, 0, data_0216c5d0);
    data_0217bbfc[13] = func_020ed4d0(data_0216c5e4, 0, data_0216c5f4);
    data_0217bbfc[8] = data_0217bbfc[7];
    f = (*(s32 *) data_021759c0->mUnk_00 == 0x1d);
    i = 0;
    while (i < 0xe) {
        p = &data_0217bc34[i];
        if (((Unk0217bc34_14 *) p)->mUnk_14 != 0) {
            ((Unk0217bc34_14 *) p)->mUnk_14();
        }
        if (f != 0) {
            data_0217bbfc[i]->mUnk_14 &= 0xffff7fff;
        }
        i++;
    }
}

#pragma optimize_for_size off
#pragma thumb off

// non-matching: the two field loads [r1,#0x1f0] and [r1,#0x1f4] are issued in
// the opposite order (the compiled code loads 0x1f4 first).
void func_020ed268(Unk020ec8bc *p, u8 *q, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, u16 g, s32 h) {
    Unk020ec8bc_00c *n;
    s32 v1;
    s32 v2;

    func_020f2b94(p, q, (e == 0) ? -1 : 0, c, d, f);
    p->mUnk_214 = a;
    p->mUnk_218 = b;
    n = ((Unk020ec8bc *) q)->mUnk_00c;
    v1 = n->mUnk_1f0;
    v2 = n->mUnk_1f4;
    p->mUnk_21c = v1;
    p->mUnk_220 = v2;
    func_020f371c((Unk020f371c_Ref *) &p->mUnk_21c, (Unk020f371c_Ref *) &p->mUnk_168, g, h);
    p->mUnk_224 = 0;
}

s32 func_020ed0f4(Unk020ec8bc *p) {
    Vec3 v[6];
    Vec3 *r;
    Vec3 *q;
    s32 n;
    s32 s;

    q = &p->mUnk_050;
    r = &p->mUnk_130;
    func_021484d0(((Unk020f371c *) p->mUnk_168)->mUnk_18, q, &v[0]);
    if ((s64) v[0].x * v[0].x + (s64) v[0].y * v[0].y + (s64) v[0].z * v[0].z >= 0x10) {
        func_02039860(&v[0], &v[1]);
    }
    n = func_02039828(r, &v[1]);
    if (n > 0xddb || p->mUnk_158 != 0) {
        v[0].x >>= 2;
        v[0].y >>= 2;
        v[0].z >>= 2;
        s = func_0214848c(r, &v[0]);
        v[1].x = (s32) (((u64) ((s64) r->x * s)) >> 12);
        v[1].y = (s32) (((u64) ((s64) r->y * s)) >> 12);
        v[1].z = (s32) (((u64) ((s64) r->z * s)) >> 12);
        func_02148504(&v[0], &v[1], &v[0]);
        func_021484d0(q, &v[1], &v[2]);
        v[3] = *q;
        func_02148504(q, &v[0], &v[4]);
        v[5] = *((Unk020f371c *) p->mUnk_168)->mUnk_18;
        func_020f4020((Unk020f3fa8 *) &p->mUnk_170, &v[2], p->mUnk_12c);
        return 1;
    }
    return 0;
}

// non-matching: the registers are handed out differently (original keeps c in
// r4, p+0x13c in r5, p+0x130 in r6, b in r7, p in r8; compiled keeps r in r4,
// q in r5, c in r6).
void func_020ece1c(Unk020ec8bc *p, s32 a, s32 b, s32 c) {
    Vec3 v;
    Vec3 *q;
    Vec3 *r;
    s32 n;
    s32 s;

    func_020f2228((Unk0206bcb0 *) p, a);
    if (p->mUnk_158 != 0 && (p->mUnk_074 & 0x20000) != 0) {
        n = func_0207a974(p->mUnk_078 & 0xff)->mUnk_98.y + 0x1e000;
        if (p->mUnk_050.y < n) {
            p->mUnk_050.y = n;
        }
    }
    if (p->mUnk_074 & 1) {
        return;
    }
    if (p->mUnk_158 == 0) {
        if (p->mUnk_074 & 0x20000) {
            return;
        }
    }
    q = &p->mUnk_130;
    r = &p->mUnk_13c;
    if (func_020f3bb4((Unk020f371c_Ref *) &p->mUnk_21c, (Unk020f371c_Ref *) &p->mUnk_168,
                      (Unk020f371c_Ref *) &p->mUnk_21c, &p->mUnk_050) != 0) {
        func_020f371c((Unk020f371c_Ref *) &p->mUnk_21c, (Unk020f371c_Ref *) &p->mUnk_168, b, c);
    }
    func_021484d0(((Unk020f371c *) p->mUnk_168)->mUnk_18, &p->mUnk_050, &v);
    if (p->mUnk_074 & 0x40000000) {
        s = func_0214848c(r, &v);
        v.x -= (s32) (((u64) ((s64) r->x * s)) >> 12);
        v.y -= (s32) (((u64) ((s64) r->y * s)) >> 12);
        v.z -= (s32) (((u64) ((s64) r->z * s)) >> 12);
        s = func_0214848c(&p->mUnk_0f0, &v);
        v.x -= (s32) (((u64) ((s64) p->mUnk_0f0.x * s)) >> 12);
        v.y -= (s32) (((u64) ((s64) p->mUnk_0f0.y * s)) >> 12);
        v.z -= (s32) (((u64) ((s64) p->mUnk_0f0.z * s)) >> 12);
        func_02147fd8(0x29, &v, &p->mUnk_050, &p->mUnk_050);
        func_02147fd8(0x3, &v, r, r);
        return;
    }
    if (func_02039828(r, &v) < 0) {
        func_020397a8(r, &p->mUnk_0f0, &p->mUnk_148);
        if (func_02039828(&p->mUnk_148, &v) > 0) {
            v = p->mUnk_148;
        } else {
            v.x = -p->mUnk_148.x;
            v.y = -p->mUnk_148.y;
            v.z = -p->mUnk_148.z;
        }
        p->mUnk_224 = 1;
    }
    if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
        func_02039860(&v, &v);
    }
    n = (p->mUnk_224 != 0) ? 0x266 : 0x148;
    func_020eacc0(q, (s32) (((u64) ((s64) n * (0x1000 - p->mUnk_214 * p->mUnk_218))) >> 12), &v, &v);
    func_020f1d70(p, &v);
}

// non-matching: the original hoists `add r4, sl, #0x21c` before the loop and
// spills n to sp+0x2c; the compiled loop recomputes the address and keeps n in
// a register (0x45c bytes against 0x458).
void func_020ec9c0(Unk020ec8bc *p, s32 a, s32 b, s32 c, s32 e) {
    u8 *t;
    Vec3 *q;
    Vec3 *r;
    Vec3 v28;
    Vec3 v34;
    Vec3 v40;
    Vec3 v4c;
    s32 n;
    s32 s;
    s32 f;
    s32 w;

    t = p->mUnk_170;
    q = &p->mUnk_050;
    r = &p->mUnk_05c;
    f = (p->mUnk_074 & 0x40000000) != 0;
    n = a - p->mUnk_12c;
    p->mUnk_12c = p->mUnk_12c + (s32) (((u64) ((s64) n * b)) >> 12);
    func_020d84c0(t, p->mUnk_12c);
    if (func_020d849c(t) != 0) {
        do {
            p->mUnk_21c = (s32) p->mUnk_168;
            p->mUnk_220 = p->mUnk_16c;
            func_020f371c((Unk020f371c_Ref *) &p->mUnk_21c, (Unk020f371c_Ref *) &p->mUnk_168, c, e);
        } while (func_020f3fa8((Unk020f3fa8 *) t, ((Unk020f371c *) p->mUnk_168)->mUnk_18) != 0);
    }
    if (f) {
        v4c = *q;
        func_020d8488((u32) t, (u32) q);
        r->y = 0;
        if (p->mUnk_158 == 0) {
            func_021484d0(q, &v4c, &v4c);
            w = func_02039828(&v4c, &p->mUnk_0f0);
            if (w > 0) {
                func_02147fd8(-w, &p->mUnk_0f0, q, q);
            }
        }
    } else {
        if (p->mUnk_158 != 0 && (p->mUnk_074 & 0x20000) != 0) {
            n = q->y;
            func_020d8460(t, q);
            if (q->y < n) {
                q->y = n;
            }
        } else {
            func_020d8474((u32) t, (u32) q);
        }
        q->y = q->y + r->y;
    }
    if (func_01ffdee4((int *) q, (u32 *) &p->mUnk_0e4, 0, p->mUnk_0dc, 4, p->mUnk_0da, (int *) &v28, (int *) &v34,
                      (int *) &v40, &p->mUnk_0fc, 0, 0, 0, 0) != 0) {
        if (p->mUnk_158 != 0) {
            if (n > 0) {
                q->y = q->y + n;
            }
        } else {
            func_02148504(&v28, q, q);
        }
        if (p->mUnk_0fc & 0x1e34ef) {
            s = func_0214848c(&v34, r);
            r->x -= (s32) (((u64) ((s64) v34.x * s)) >> 12);
            r->y -= (s32) (((u64) ((s64) v34.y * s)) >> 12);
            r->z -= (s32) (((u64) ((s64) v34.z * s)) >> 12);
            s = (v34.x == p->mUnk_0f0.x && v34.y == p->mUnk_0f0.y && v34.z == p->mUnk_0f0.z) ? 1 : 0;
            if (s == 0) {
                p->mUnk_0f0 = v34;
                p->mUnk_074 |= 0x100;
            }
        }
        if ((p->mUnk_0fc & 0x214300) != 0 && p->mUnk_15c != 0) {
            s = func_0214848c(&v40, r);
            v28.x = (s32) (((u64) ((s64) v40.x * s)) >> 12);
            v28.y = (s32) (((u64) ((s64) v40.y * s)) >> 12);
            v28.z = (s32) (((u64) ((s64) v40.z * s)) >> 12);
            r->x -= v28.x;
            r->y -= v28.y;
            r->z -= v28.z;
            func_021484d0(r, &v28, r);
            r->x = (s32) (((u64) ((s64) r->x * 0x23d)) >> 12);
            r->y = (s32) (((u64) ((s64) r->y * 0x23d)) >> 12);
            r->z = (s32) (((u64) ((s64) r->z * 0x23d)) >> 12);
            func_020f6fc4(p, 1);
            return;
        }
        if (p->mUnk_0fc & 0x8000) {
            if (p->mUnk_044 != 5) {
                func_020f7070(p, 1);
                return;
            }
        }
    }
    func_020f2150(p);
    r->x = q->x - p->mUnk_0e4.x;
    r->z = q->z - p->mUnk_0e4.z;
}

void func_020ec918(Unk020ec8bc *p, s32 a, s32 b, s32 c, s32 d) {
    if (p->mUnk_214 >= 0) {
        func_020ece1c(p, a, c, d);
        if (p->mUnk_214 == 0) {
            if (func_020ed0f4(p) != 0) {
                p->mUnk_214 = -1;
            }
            return;
        }
        if (p->mUnk_074 & 0x40020000) {
            if (p->mUnk_158 == 0) {
                return;
            }
        }
        p->mUnk_214 -= 1;
    } else {
        func_020ec9c0(p, a, b, c, d);
    }
}

void func_020ec8bc(Unk020ec8bc *p, s32 a, s32 b, s32 c, s32 d, s32 e, u16 f, s32 g) {
    func_020f1ea4(p, (d == 0) ? -1 : 0, e, c);
    p->mUnk_214 = a;
    p->mUnk_218 = b;
    func_020f371c((Unk020f371c_Ref *) &p->mUnk_21c, (Unk020f371c_Ref *) &p->mUnk_168, f, g);
    p->mUnk_224 = 0;
}
