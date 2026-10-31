#include "Main/Unknown/code_020e66e4.h"

#include "Main/Unknown/code_020e5d0c.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"

void func_020e6a18(Unk020e6488 *p) {
    if (p->mUnk_1a == 1) {
        func_01ff9048(0x2b, p->mUnk_20, 1);
        func_01ff9048(0x2a, p->mUnk_1c, 1);
    }
    func_01ff9048(0x30, &p->mUnk_0c, 1);
    func_01ff9048(0x31, &p->mUnk_10, 1);
}

s32 func_020e69bc(Vec3 *v) {
    Unk02012f58 *t;
    s64 acc;

    t = data_0217b854;
    acc = (s64) v->x * t->mUnk_00.z + (s64) v->y * t->mUnk_0c.z + (s64) v->z * t->mUnk_18.z;
    return -(t->mUnk_24.z + (s32) (acc >> 12)) >> 9;
}

void func_020e6854(Unk020e6488 *p, Vec3 *q, s32 c, u32 d) {
    u32 a[3];
    u32 v;
    u32 e;
    Unk02012f58 *t;
    s32 m;
    u32 r;
    s64 acc;

    a[0] = p->mUnk_08;
    a[1] = a[0];
    a[2] = a[0];
    func_01ff9048(0x1b, a, 3);
    v = p->mUnk_14;
    e = (v & 0x1f0000) >> 16;
    if (d < e) {
        v &= ~0x1f0000;
        v |= d << 16;
        r = func_020d3c44();
        v &= 0xc0ffffff;
        v |= r << 24;
    } else if (c != 0) {
        t = data_0217b854;
        acc = (s64) q->x * t->mUnk_00.z + (s64) q->y * t->mUnk_0c.z + (s64) q->z * t->mUnk_18.z;
        m = -(t->mUnk_24.z + (s32) (acc >> 12)) >> 9;
        if (m < e) {
            if (m == 0) {
                m = 1;
            }
            v &= ~0x1f0000;
            v |= (u32) m << 16;
            r = func_020d3c44();
            v &= 0xc0ffffff;
            v |= r << 24;
        }
    }
    func_01ff9048(0x29, &v, 1);
    if (p->mUnk_1a != 1) {
        u16 n;

        n = p->mUnk_18;
        func_01ff9048(0x2b, p->mUnk_20 + n, 1);
        func_01ff9048(0x2a, p->mUnk_1c + n, 1);
    }
    func_01ff9144((const void *) p->mUnk_00, p->mUnk_04);
}

void func_020e67c4(Unk020e6488 *p, Unk02012f58 *q, Vec3 *v, s32 a4, u16 a5) {
    u32 n;
    Vec3 t;
    s32 x;
    s32 z;
    s32 y;

    n = 0x1e;
    func_01ff9048(0x14, &n, 1);
    func_01ff9048(0x19, q, 0xc);
    if (v != 0) {
        z = v->z;
        y = v->y;
        x = v->x;
        t.x = x;
        t.y = y;
        t.z = z;
        func_01ff9048(0x1b, &t, 3);
    }
    func_020e6854(p, &q->mUnk_24, a4, a5);
}

void func_020e66e4(Unk020e6488 *p, Unk02012f58 *q, s32 r, Vec3 *v, s32 a5, u16 a6) {
    u32 n;
    Vec3 t;
    s32 i;
    s32 x;
    s32 z;
    s32 y;

    n = 0x1e;
    func_01ff9048(0x14, &n, 1);
    func_01ff9048(0x19, q, 0xc);
    if (r != 0) {
        i = r >> 4;
        func_02146d60((s32 *) *(void **) data_0217b858, data_0215d4b4[i * 2], data_0215d4b4[i * 2 + 1]);
        func_01ff9048(0x1a, *(void **) data_0217b858, 9);
    }
    if (v != 0) {
        z = v->z;
        y = v->y;
        x = v->x;
        t.x = x;
        t.y = y;
        t.z = z;
        func_01ff9048(0x1b, &t, 3);
    }
    func_020e6854(p, &q->mUnk_24, a5, a6);
}
