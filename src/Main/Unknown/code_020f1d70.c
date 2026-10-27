#include "Main/Unknown/code_020f1d70.h"

#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_01ffd000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02109000.h"
#include "code_02147cd8.h"

// non-matching: 33 instructions differ; first at +0x0: original `push {r4, r5, r6, r7, r8, lr}`, ours
// `push {r4, r5, r6, r7, lr}`; the fifth argument of the else-branch call is materialised in ip instead of
// r8, so 4 fewer bytes are reserved and e/f are read at [sp, #0x1c]/[sp, #0x20], not [sp, #0x24]/[sp, #0x28]
void func_020f2b94(void *a0, void *b0, s32 c, s32 d, s32 e, s32 f) {
    Unk0206bcb0 *a;
    Unk020edb8c *b;
    s32 n;
    s32 t;
    s32 u;

    a = a0;
    b = b0;
    if (d != 0) {
        a->mUnk_12c.x = func_020edc9c((Unk020eda5c *) b, f, 0x1000, 0x3800, (Vec3 *) &a->mUnk_12c.y);
    } else {
        Vec3 *p = (Vec3 *) &a->mUnk_12c.y;
        a->mUnk_12c.x = func_020edb8c((Unk020eda5c *) b, 0x3000, 0x1000, 0x4000, p);
    }
    *(Vec3 *) &a->mUnk_138.y = *(Vec3 *) &a->mUnk_12c.y;
    t = -a->mUnk_138.x;
    u = a->mUnk_12c.y;
    a->mUnk_150.x = u;
    ((s32 *) a->mUnk_144)[1] = t;
    ((s32 *) a->mUnk_144)[2] = 0;
    a->mUnk_05c.x = (s32) (((s64) a->mUnk_12c.y * a->mUnk_12c.x) >> 12);
    a->mUnk_05c.z = (s32) (((s64) a->mUnk_138.x * a->mUnk_12c.x) >> 12);
    if (d == 0) {
        func_02148504(&a->mUnk_05c, &b->mUnk_10->mUnk_1fc, &a->mUnk_05c);
    }
    if (b->mUnk_10->mUnk_48 & 1) {
        n = func_0214848c((const Vec3 *) &b->mUnk_38, &a->mUnk_05c);
        a->mUnk_05c.x -= (s32) (((s64) b->mUnk_38.x * n) >> 12);
        a->mUnk_05c.y -= (s32) (((s64) b->mUnk_38.y * n) >> 12);
        a->mUnk_05c.z -= (s32) (((s64) b->mUnk_38.z * n) >> 12);
        func_02147fd8(-0x1000, (const Vec3 *) &b->mUnk_38, &a->mUnk_05c, &a->mUnk_05c);
    }
    if (a->mUnk_68.z < 0xccd) {
        a->mUnk_68.x = 0xccd;
        a->mUnk_68.y = 0xccd;
        a->mUnk_68.z = 0xccd;
        if (d != 0) {
            a->mUnk_50 = b->mUnk_10->mUnk_1b8;
            func_02147fd8(a->mUnk_68.z * 10, (const Vec3 *) &b->mUnk_44, (const Vec3 *) &a->mUnk_50,
                          (Vec3 *) &a->mUnk_50);
        }
    }
    if (c < 0) {
        a->mUnk_150.y = 0;
        a->mUnk_15c.x = 0;
    } else {
        a->mUnk_150.y = c;
        a->mUnk_15c.x = 1;
    }
    a->mUnk_124 = func_020f1f98;
    a->mUnk_15c.y = 1;
    a->mUnk_150.z = e;
    ((u16 *) &a->mUnk_15c)[4] = 4;
}

void func_020f2a6c(Vec3 *a, Vec3 *b, Vec3 *c) {
    s32 n;

    n = b->y * b->y;
    if (n < 0x10) {
        c->x = -a->x;
        c->y = -a->y;
        c->z = -a->z;
        return;
    }
    c->x = b->x >> 2;
    c->y = b->y >> 2;
    c->z = b->z >> 2;
    c->x = a->x - c->x;
    c->z = a->z - c->z;
    n = (s32) (((s64) a->x * b->x) >> 12) + (s32) (((s64) a->z * b->z) >> 12);
    c->y = -(n + c->y);
    c->y = func_02147f34(c->y, b->y);
    if ((s64) c->x * c->x + (s64) c->y * c->y + (s64) c->z * c->z >= 0x10) {
        func_02039860((const Vec3 *) c, c);
    }
}

void func_020f29e8(u32 a) {
    Unk0206bcb0 *b;
    Vec3 *p;
    s32 n;

    b = (Unk0206bcb0 *) a;
    n = 0;
    p = &b->mUnk_f0;
    if ((s64) b->mUnk_05c.x * b->mUnk_05c.x + (s64) b->mUnk_05c.y * b->mUnk_05c.y +
            (s64) b->mUnk_05c.z * b->mUnk_05c.z >=
        0x10) {
        n = func_02039860(&b->mUnk_05c, (Vec3 *) &b->mUnk_12c.y);
    }
    b->mUnk_12c.x = n;
    func_020f2a6c((Vec3 *) &b->mUnk_12c.y, p, (Vec3 *) &b->mUnk_138.y);
    func_020397a8((const Vec3 *) &b->mUnk_138.y, p, (Vec3 *) &b->mUnk_144[4]);
    b->mUnk_124 = func_020f1f98;
}

void func_020f288c(Unk0206bcb0 *a, Vec3 *b) {
    Vec3 v;
    Vec3 *p;
    Vec3 *q;
    s32 n;

    p = (Vec3 *) &a->mUnk_138.y;
    q = (Vec3 *) &a->mUnk_12c.y;
    n = func_0214848c(b, p);
    v.x = (s32) (((s64) b->x * n) >> 12);
    v.y = (s32) (((s64) b->y * n) >> 12);
    v.z = (s32) (((s64) b->z * n) >> 12);
    a->mUnk_138.y -= v.x;
    p->y -= v.y;
    p->z -= v.z;
    if (a->mUnk_15c.y != 0) {
        func_021484d0((const Vec3 *) p, &v, p);
    }
    if ((s64) p->x * p->x + (s64) p->y * p->y + (s64) p->z * p->z >= 0x10) {
        func_02039860((const Vec3 *) p, p);
    }
    n = p->z;
    q->x = p->x;
    q->y = 0;
    q->z = n;
    if ((s64) q->x * q->x + (s64) q->y * q->y + (s64) q->z * q->z >= 0x10) {
        func_02039860((const Vec3 *) q, q);
    }
    func_020397a8((const Vec3 *) q, &a->mUnk_f0, (Vec3 *) &a->mUnk_144[4]);
    func_021090c4(&a->mUnk_00, 0xd5, 0x7f, 0);
}

void func_020f2768(Unk0206bcb0 *a, Vec3 *b, Vec3 *c) {
    Vec3 v;
    Vec3 *p;
    s32 n;

    p = (Vec3 *) &a->mUnk_12c.y;
    n = func_0214848c(b, p);
    v.x = (s32) (((s64) b->x * n) >> 12);
    v.y = (s32) (((s64) b->y * n) >> 12);
    v.z = (s32) (((s64) b->z * n) >> 12);
    a->mUnk_12c.y -= v.x;
    p->y -= v.y;
    p->z -= v.z;
    if (a->mUnk_15c.y != 0) {
        func_021484d0((const Vec3 *) p, &v, p);
    }
    if ((s64) p->x * p->x + (s64) p->y * p->y + (s64) p->z * p->z >= 0x10) {
        func_02039860((const Vec3 *) p, p);
    }
    *(Vec3 *) &a->mUnk_138.y = *p;
    func_020397a8((const Vec3 *) p, &a->mUnk_f0, (Vec3 *) &a->mUnk_144[4]);
    a->mUnk_f0.y += 1;
    func_021090c4(&a->mUnk_00, 0xd5, 0x7f, 0);
}

// non-matching: 8 instructions differ; first at +0x1a4: the 64-bit dot-product accumulator uses r1/r2
// (low/high) where the original uses r2/r1, which also swaps the two registers of the following comparison
// and the two argument registers of func_02039860
void func_020f2228(Unk0206bcb0 *a, s32 b) {
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 v;
    Vec3 *q;
    Vec3 *p;
    Vec3 *r;
    s32 f;
    s32 n;
    s32 t;
    Vec3 *w;

    q = (Vec3 *) &a->mUnk_50;
    p = &a->mUnk_05c;
    r = (Vec3 *) &a->mUnk_12c.y;
    func_02148504((const Vec3 *) p, q, q);
    n = func_01ffdee4((int *) q, (u32 *) &a->mUnk_e4, 0, a->mUnk_dc, ((u16 *) &a->mUnk_15c)[4],
                      ((s16 *) &a->mUnk_d8)[1], (int *) &v1, (int *) &v2, (int *) &v3, (u32 *) &a->mUnk_fc, 0, 0, 0, 0);
    if (n != 0) {
        f = a->mUnk_fc & 0x80000;
        if (a->mUnk_150.z != 0) {
            if (v1.y > 0) {
                q->y += v1.y;
            }
        } else {
            func_02148504((const Vec3 *) &v1, q, q);
        }
        if (a->mUnk_fc & 0x1e34ef) {
            t = v2.x == a->mUnk_f0.x && v2.y == a->mUnk_f0.y && v2.z == a->mUnk_f0.z;
            if (t == 0) {
                a->mUnk_f0 = v2;
                *(u32 *) &a->mUnk_74 |= 0x100;
                if (f != 0) {
                    n = func_0214848c(&v2, (Vec3 *) &a->mUnk_138.y);
                    a->mUnk_138.y -= (s32) (((s64) v2.x * n) >> 12);
                    a->mUnk_138.z -= (s32) (((s64) v2.y * n) >> 12);
                    ((s32 *) a->mUnk_144)[0] -= (s32) (((s64) v2.z * n) >> 12);
                    if ((s64) a->mUnk_138.y * a->mUnk_138.y + (s64) a->mUnk_138.z * a->mUnk_138.z +
                            (s64) ((s32 *) a->mUnk_144)[0] * ((s32 *) a->mUnk_144)[0] >=
                        0x10) {
                        func_02039860((const Vec3 *) &a->mUnk_138.y, (Vec3 *) &a->mUnk_138.y);
                    }
                    *r = *(Vec3 *) &a->mUnk_138.y;
                } else {
                    func_020f2a6c(r, &v2, (Vec3 *) &a->mUnk_138.y);
                }
                func_020397a8((const Vec3 *) &a->mUnk_138.y, &v2, (Vec3 *) &a->mUnk_144[4]);
            }
        }
        if (a->mUnk_fc & 0x214300) {
            if (a->mUnk_150.z != 0) {
                q->x += v1.x;
                q->z += v1.z;
            }
            if (f != 0) {
                func_021484d0(&v3, &a->mUnk_f0, &v3);
                func_020f288c(a, &v3);
            } else {
                v3.y = 0;
                func_020f2768(a, &v3, 0);
            }
            *(u16 *) &a->mUnk_78 &= ~0x4000;
            if (a->mUnk_15c.x != 0) {
                *(u32 *) &a->mUnk_74 |= 0x20;
                a->mUnk_150.y -= 1;
            }
        }
        n = a->mUnk_12c.x;
        p->x = (s32) (((s64) a->mUnk_138.y * n) >> 12);
        p->y = (s32) (((s64) a->mUnk_138.z * n) >> 12);
        p->z = (s32) (((s64) ((s32 *) a->mUnk_144)[0] * n) >> 12);
        if (a->mUnk_fc & 0x1e34ef) {
            v1.y = q->y - a->mUnk_e4.y;
            if (v1.y > 0x5000 && f == 0) {
                v1.y = 0x5000;
            }
            if (v1.y > p->y) {
                p->y = v1.y;
            }
        }
        if (a->mUnk_150.y < 0) {
            p->x = (s32) (((s64) p->x * 0x23d) >> 12);
            p->y = (s32) (((s64) p->y * 0x23d) >> 12);
            p->z = (s32) (((s64) p->z * 0x23d) >> 12);
            func_020f6fc4(a, 1);
            return;
        }
        if ((a->mUnk_fc & 0x8000) && a->mUnk_44 != 5) {
            func_020f7070(a, 1);
            return;
        }
    }
    a->mUnk_12c.x += (s32) (((s64) (b - a->mUnk_12c.x) * 0x29) >> 12);
    w = &a->mUnk_05c;
    if (a->mUnk_fc & 0x1e34ef) {
        v.x = a->mUnk_f0.x >> 2;
        v.y = a->mUnk_f0.y >> 2;
        v.z = a->mUnk_f0.z >> 2;
        func_021484d0((const Vec3 *) w, &v, w);
        return;
    }
    n = w->y;
    if (n > 0) {
        w->y -= 0x6b8;
        if (!(*(u32 *) &a->mUnk_74 & 0x20000)) {
            return;
        }
        n = w->y;
        if (n > 0xa000) {
            w->y = w->y >> 3;
            return;
        }
        w->y = (s32) (((s64) n * 0xe66) >> 12);
    } else {
        w->y -= 0x333;
        if (w->y >= -0xa000) {
            return;
        }
        if (*(u32 *) &a->mUnk_74 & 0x20000) {
            w->y = -0xa000;
        }
    }
}

void func_020f2150(void *a0) {
    Unk0206bcb0 *a;
    Vec3 *p;
    s32 n;

    a = a0;
    p = &a->mUnk_05c;
    n = p->y;
    if (n > 0) {
        p->y -= 0x6b8;
        if (!(*(u32 *) &a->mUnk_74 & 0x20000)) {
            return;
        }
        n = p->y;
        if (n > 0xa000) {
            p->y = p->y >> 3;
            return;
        }
        p->y = (s32) (((s64) n * 0xe66) >> 12);
    } else {
        p->y -= 0x333;
        if (p->y >= -0xa000) {
            return;
        }
        if (*(u32 *) &a->mUnk_74 & 0x20000) {
            p->y = -0xa000;
        }
    }
}

void func_020f2028(Unk0206bcb0 *a) {
    Vec3 *p;
    Vec3 v;
    s32 n;

    p = &a->mUnk_05c;
    if (a->mUnk_fc & 0x1e34ef) {
        v.x = a->mUnk_f0.x >> 2;
        v.y = a->mUnk_f0.y >> 2;
        v.z = a->mUnk_f0.z >> 2;
        func_021484d0(p, &v, p);
        return;
    }
    n = p->y;
    if (n > 0) {
        p->y -= 0x6b8;
        if (!(*(u32 *) &a->mUnk_74 & 0x20000)) {
            return;
        }
        n = p->y;
        if (n > 0xa000) {
            p->y = p->y >> 3;
            return;
        }
        p->y = (s32) (((s64) n * 0xe66) >> 12);
    } else {
        p->y -= 0x333;
        if (p->y >= -0xa000) {
            return;
        }
        if (*(u32 *) &a->mUnk_74 & 0x20000) {
            p->y = -0xa000;
        }
    }
}

void func_020f1f98(Unk0206bcb0 *a, Vec3 *b, Vec3 *c) {
    Vec3 v;
    s32 n;

    if (c->y > 0) {
        func_020f2768(a, c, c);
    } else {
        v = *c;
        v.y = 0;
        func_020f2768(a, &v, 0);
    }
    n = a->mUnk_12c.x;
    a->mUnk_05c.x = (s32) (((s64) a->mUnk_138.y * n) >> 12);
    a->mUnk_05c.y = (s32) (((s64) a->mUnk_138.z * n) >> 12);
    a->mUnk_05c.z = (s32) (((s64) ((s32 *) a->mUnk_144)[0] * n) >> 12);
}

void func_020f1ea4(void *a0, s32 b, s32 c, s32 d) {
    Unk0206bcb0 *a;
    s32 n;
    s32 t;
    s32 u;

    a = a0;
    n = 0;
    if ((s64) a->mUnk_05c.x * a->mUnk_05c.x + (s64) a->mUnk_05c.y * a->mUnk_05c.y +
            (s64) a->mUnk_05c.z * a->mUnk_05c.z >=
        0x10) {
        n = func_02039860(&a->mUnk_05c, (Vec3 *) &a->mUnk_12c.y);
    }
    a->mUnk_12c.x = n;
    if (c != 0) {
        a->mUnk_12c.x = -a->mUnk_12c.x;
        a->mUnk_12c.y = -a->mUnk_12c.y;
        a->mUnk_12c.z = -a->mUnk_12c.z;
        a->mUnk_138.x = -a->mUnk_138.x;
    }
    *(Vec3 *) &a->mUnk_138.y = *(Vec3 *) &a->mUnk_12c.y;
    t = -a->mUnk_138.x;
    u = a->mUnk_12c.y;
    a->mUnk_150.x = u;
    ((s32 *) a->mUnk_144)[1] = t;
    ((s32 *) a->mUnk_144)[2] = 0;
    if (b < 0) {
        a->mUnk_150.y = 0;
        a->mUnk_15c.x = 0;
    } else {
        a->mUnk_150.y = b;
        a->mUnk_15c.x = 1;
    }
    a->mUnk_124 = func_020f1f98;
    a->mUnk_15c.y = 1;
    a->mUnk_150.z = d;
}

void func_020f1d70(void *a0, const Vec3 *b) {
    Unk0206bcb0 *a;
    Vec3 *p;
    Vec3 v;
    s32 t;
    s32 s;

    a = a0;
    a->mUnk_12c.y = b->x;
    a->mUnk_138.x = b->z;
    p = &a->mUnk_f0;
    t = func_0214848c(p, b);
    v.x = b->x - (s32) (((s64) p->x * t) >> 12);
    v.y = b->y - (s32) (((s64) p->y * t) >> 12);
    v.z = b->z - (s32) (((s64) p->z * t) >> 12);
    a->mUnk_138.y = p->x >> 2;
    a->mUnk_138.z = p->y >> 2;
    ((s32 *) a->mUnk_144)[0] = p->z >> 2;
    func_021484d0(&v, (const Vec3 *) &a->mUnk_138.y, (Vec3 *) &a->mUnk_138.y);
    if ((s64) a->mUnk_138.y * a->mUnk_138.y + (s64) a->mUnk_138.z * a->mUnk_138.z +
            (s64) ((s32 *) a->mUnk_144)[0] * ((s32 *) a->mUnk_144)[0] >=
        0x10) {
        func_02039860((const Vec3 *) &a->mUnk_138.y, (Vec3 *) &a->mUnk_138.y);
    }
    s = a->mUnk_12c.x;
    a->mUnk_05c.x = (s32) (((s64) a->mUnk_138.y * s) >> 12);
    a->mUnk_05c.z = (s32) (((s64) ((s32 *) a->mUnk_144)[0] * s) >> 12);
    func_020397a8(b, p, (Vec3 *) &a->mUnk_144[4]);
}
