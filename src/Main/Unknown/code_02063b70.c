#include "Main/Unknown/code_02063b70.h"
#include "Main/Unknown/code_01ff9000.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02079b60.h"
#include "Main/Unknown/code_02079000.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207a30c.h"
#include "Main/Unknown/code_02081374.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02086080.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_0215d000.h"

// non-matching: 89.7: stack offsets and multiplication order differ
s32 func_02063b70(Unk0206bcb0 *a) {
    Unk0206bcb0_590 *b;
    Unk0206bcb0_590_08 *c;
    s32 d;
    s32 e;
    s32 f;
    Unk02012f58 g;
    Vec3 h;
    Vec3 i;

    b = (Unk0206bcb0_590 *) a->mUnk_590;
    d = b->mUnk_058 == 0;
    if (d != 0) {
        g = *a->mUnk_1b4;
        func_02147fd8(a->mUnk_1d0 + 0x5000, &a->mUnk_12c, a->mUnk_508, &h);
        g.mUnk_24.y = h.y >> 4;
        g.mUnk_24.z = h.z >> 4;
        g.mUnk_24.x = h.x >> 4;
        i.x = (s64) a->mUnk_bc * a->mUnk_4c8 >> 12;
        i.y = (s64) a->mUnk_c0 * a->mUnk_4c8 >> 12;
        i.z = (s64) a->mUnk_c4 * a->mUnk_4c8 >> 12;
        f = 0x1e;
        func_01ff9048(0x14, &f, 1);
        func_01ff9048(0x19, &g, 0xc);
        func_01ff9048(0x1b, &i, 3);
        func_0208ab4c(&b->mUnk_040);
        func_0207a30c(a->mUnk_74);
        e = ((Unk0206bcb0_590 *) a->mUnk_590)->mUnk_0a4;
        c = func_02079b60();
        c->mUnk_0c = e;
        *c->mUnk_1c[c->mUnk_1a] = c->mUnk_0c;
        func_020849d0(func_02079b88());
        func_0207ae58(func_02079b74());
    }
    return d;
}

// non-matching: 92.8: stack offsets of the argument buffers differ
void func_02063cc4(Unk0206bcb0 *a) {
    u32 b;
    u32 c;
    u32 d;
    Unk0206bcb0_590 *e;
    Unk0206bcb0_590_54 *f;
    s32 g;
    s32 h;
    s32 i;
    s32 j[9];
    s32 k[9];
    Vec3 l;
    Vec3 m;
    Vec3 n;
    Vec3 o;
    Vec3 p;
    Vec3 q;
    Vec3 r;
    Vec3 s;
    Vec3 t;
    Vec3 u;
    s32 v;
    s32 w;

    b = (a->mUnk_4c & 0x10) != 0;
    c = a->mUnk_4c;
    d = a->mUnk_7c & 0x1008040;
    e = (Unk0206bcb0_590 *) a->mUnk_590;
    if (d != 0 || (c & 0x11800000) != 0) {
        g = 0;
        if (d == 0 && (c & 0x1800000) == 0) {
            g = func_02063b70(a);
        }
        func_0208155c(a->mUnk_74, g);
        a->mUnk_384 = 0;
        return;
    }
    if ((a->mUnk_7c & 0x404004) != 0) {
        a->mUnk_384 = ~a->mUnk_384;
        if (a->mUnk_384 == 0) {
            return;
        }
    } else {
        a->mUnk_384 = 0xffff;
    }
    v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    if (b != 0) {
        a->mUnk_144.x = a->mUnk_508->x >> 4;
        a->mUnk_144.y = a->mUnk_508->y >> 4;
        a->mUnk_144.z = a->mUnk_508->z >> 4;
        func_01ff9048(0x19, &a->mUnk_120, 0xc);
        func_01ff9048(0x1b, &a->mUnk_bc, 3);
        l.x = a->mUnk_414;
        l.y = a->mUnk_404;
        l.z = a->mUnk_418;
        func_01ff9048(0x1b, &l, 3);
        func_0207ae58(e->mUnk_01c);
        v = 0x1e;
        func_01ff9048(0x14, &v, 1);
    }
    func_01ff9048(0x19, a->mUnk_1b4, 0xc);
    func_01ff9048(0x1b, &a->mUnk_bc, 3);
    v = 0x1d;
    func_01ff9048(0x13, &v, 1);
    m.x = a->mUnk_414;
    m.y = a->mUnk_404;
    m.z = a->mUnk_418;
    func_01ff9048(0x1b, &m, 3);
    if (b == 0) {
        func_0207ae58(e->mUnk_01c);
    }
    func_0208ab4c(&e->mUnk_040);
    if (e->mUnk_058 == 0) {
        func_02079b9c(e, e->mUnk_060 == 0);
        v = 0x1c;
        func_01ff9048(0x13, &v, 1);
        n.x = a->mUnk_4f0;
        n.y = a->mUnk_4f4;
        n.z = 0x1000;
        func_01ff9048(0x1b, &n, 3);
        func_020849d0(e->mUnk_014);
        if (e->mUnk_018 != 0) {
            f = ((Unk0206bcb0_590 *) a->mUnk_590)->mUnk_054;
            h = ((Unk0206bcb0_590 *) a->mUnk_590)->mUnk_020->mUnk_10;
            v = 0x1c;
            func_01ff9048(0x14, &v, 1);
            func_01ff9048(0x1c, &f->mUnk_18, 3);
            w = (a->mUnk_3a4 >> 4) * 2;
            func_02146d28(j, data_0215d4b4[w], data_0215d4b4[w + 1]);
            func_01ff9048(0x1a, j, 9);
            func_020849d0(e->mUnk_018);
            if (f->mUnk_18 != 0) {
                o.x = f->mUnk_24;
                o.y = 0;
                o.z = 0;
                func_01ff9048(0x1c, &o, 3);
                func_020849d0(e->mUnk_018);
            }
            v = 0x1c;
            func_01ff9048(0x14, &v, 1);
            func_01ff9048(0x1c, f, 3);
            p.x = h;
            p.y = h;
            p.z = h;
            func_01ff9048(0x1b, &p, 3);
            func_01ff9048(0x11, 0, 0);
            w = (a->mUnk_4cc >> 4) * 2;
            func_02146d44(k, data_0215d4b4[w], data_0215d4b4[w + 1]);
            func_01ff9048(0x1a, k, 9);
            func_01ff9048(0x1a, j, 9);
            func_020849d0(e->mUnk_018);
            if (f->mUnk_00 != 0) {
                v = 1;
                func_01ff9048(0x12, &v, 1);
                q.x = f->mUnk_0c;
                q.y = 0;
                q.z = 0;
                func_01ff9048(0x1c, &q, 3);
                func_01ff9048(0x1a, k, 9);
                func_01ff9048(0x1a, j, 9);
                func_020849d0(e->mUnk_018);
            }
        }
    }
    if (e->mUnk_05c != 0) {
        return;
    }
    r = ((Vec3 *) &e->mUnk_020->mUnk_44)[e->mUnk_000];
    r.y = r.y + (a->mUnk_408 + a->mUnk_4f8);
    v = 0x1d;
    func_01ff9048(0x14, &v, 1);
    func_01ff9048(0x1c, &r, 3);
    func_020849d0(e->mUnk_010);
}

void func_02064180(Unk0206bcb0 *a) {
    a->mUnk_00.mUnk_40 = func_02086080(a->mUnk_74);
    func_0210b7ec(&a->mUnk_518, func_02086080(a->mUnk_74));
}
