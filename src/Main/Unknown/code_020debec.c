#include "Main/Unknown/code_020debec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e55b4.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
void func_020df3f8(void) {
    data_0217b750 = 0;
    data_0217b754 = 0;
    data_0217b75c = 0x1000;
    data_0217b760.x = 0x1000;
    data_0217b760.y = 0x1000;
    data_0217b760.z = 0x1000;
}
#pragma thumb off

Unk020de390 *func_020df3a8(void) {
    Unk020de390 *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    *p = data_02158654;
    return p;
}

Unk020de334 *func_020df34c(void) {
    data_0217b70c = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    *data_0217b70c = data_02158628;
    func_020d49d8(&data_0217b70c);
    return data_0217b70c;
}

Unk020de334 *func_020df2f0(void) {
    data_0217b700 = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    *data_0217b700 = data_021585fc;
    func_020d49d8(&data_0217b700);
    return data_0217b700;
}

Unk020de334 *func_020df294(void) {
    data_0217b714 = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    *data_0217b714 = data_021585d0;
    func_020d49d8(&data_0217b714);
    return data_0217b714;
}

Unk020de2d8 *func_020df238(void) {
    data_0217b718 = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    *data_0217b718 = data_021585a8;
    func_020e6f50(&data_0217b718);
    return data_0217b718;
}

void func_020df220(void) {
    func_020e6a18(data_0217b71c);
}

void func_020df07c(void *a, Unk020de6a8 *b, void *c, u16 d) {
    Unk02012f58 q;
    Unk020e6488 *p;
    Vec3 *w;
    s32 e;
    s32 g;
    s32 h;
    u16 x;
    u16 y;
    u16 r;
    Unk020de84c_14 *t;

    if (b->mUnk_0e8 < 1) {
        return;
    }
    if (b->mUnk_100 != 0) {
        b->mUnk_100(b->mUnk_104, &q);
        r = func_020d3c44();
        p = data_0217b71c;
        p->mUnk_14 = p->mUnk_14 & 0xc0ffffff;
        p->mUnk_14 = p->mUnk_14 | r << 24;
    } else {
        t = &data_0217b704[b->mUnk_0a0];
        e = t->mUnk_00;
        q.mUnk_00.x = e;
        g = t->mUnk_04;
        q.mUnk_00.y = g;
        q.mUnk_00.z = 0;
        h = -t->mUnk_10;
        q.mUnk_0c.x = h;
        q.mUnk_0c.y = t->mUnk_08;
        q.mUnk_0c.z = g;
        q.mUnk_18.x = t->mUnk_0c;
        q.mUnk_18.y = h;
        q.mUnk_18.z = e;
        w = b->mUnk_0fc;
        q.mUnk_24.x = w->x >> 4;
        q.mUnk_24.y = w->y >> 4;
        q.mUnk_24.z = w->z >> 4;
        y = b->mUnk_0f0;
        p = data_0217b71c;
        p->mUnk_14 = p->mUnk_14 & 0xc0ffffff;
        p->mUnk_14 = p->mUnk_14 | y << 24;
    }
    x = b->mUnk_0e8;
    p = data_0217b71c;
    p->mUnk_14 = p->mUnk_14 & 0xffe0ffff;
    p->mUnk_14 = p->mUnk_14 | x << 16;
    if (b->mUnk_0fc != 0) {
        if (b->mUnk_000.mUnk_1c.z < 0x29) {
            return;
        }
        func_020e67c4(data_0217b71c, &q, &b->mUnk_000.mUnk_1c, 0, d);
    } else {
        func_020e67c4(data_0217b71c, &q, 0, 0, d);
    }
}

void func_020df064(void) {
    func_020e6a18(data_0217b710);
}

void func_020def00(void *a, Unk020de6a8 *b, void *c, u16 d) {
    Unk02012f58 q;
    s32 e;
    s32 f;
    Unk020de84c_08 *t;
    Unk020e6488 *p;
    Vec3 *w;
    s32 x;
    Unk020e6488 *p2;
    u16 y;

    b->mUnk_0f0 = func_020d3c44();
    if (b->mUnk_100 != 0) {
        return;
    }
    if ((s32) (b->mUnk_000.mUnk_78 & 0x3fffffe0) > 0x27100) {
        if (func_0203c5e4() == 0) {
            return;
        }
    }
    if (b->mUnk_0ec < 1) {
        return;
    }
    t = &data_0217b708[b->mUnk_0a2];
    e = t->mUnk_00;
    q.mUnk_00.x = e;
    q.mUnk_00.y = 0;
    f = -t->mUnk_04;
    q.mUnk_00.z = f;
    q.mUnk_0c.x = 0;
    q.mUnk_0c.y = 0x1000;
    q.mUnk_0c.z = 0;
    q.mUnk_18.x = -f;
    q.mUnk_18.y = 0;
    q.mUnk_18.z = e;
    w = b->mUnk_0fc;
    q.mUnk_24.x = w->x >> 4;
    q.mUnk_24.y = w->y >> 4;
    q.mUnk_24.z = w->z >> 4;
    p = data_0217b710;
    x = b->mUnk_0ec;
    p->mUnk_14 &= 0xffe0ffff;
    p->mUnk_14 |= (u16) x << 16;
    y = b->mUnk_0f0;
    p2 = data_0217b710;
    p2->mUnk_14 &= 0xc0ffffff;
    p2->mUnk_14 |= y << 24;
    func_020e67c4(data_0217b710, &q, b->mUnk_0fc != 0 ? &b->mUnk_000.mUnk_1c : 0, 0, d);
}

void func_020dee8c(void) {
    s32 n;

    func_020e55b4();
    if (func_020b2ec0() != 0) {
        return;
    }
    data_0217b6fc += 0xca;
    n = data_0217b6fc >> 4;
    func_02147250(&data_0217b720, data_0215d4b4[n * 2], data_0215d4b4[n * 2 + 1]);
}

void func_020dec4c(void *a, Unk020de6a8 *b, u32 c, u32 d) {
    Vec3 v;
    Vec3 *p;
    s32 n;
    s32 x;
    s32 y;
    Unk02012f58 *q;

    n = b->mUnk_0a4 - 0x40;
    if (n >= 0x40) {
        b->mUnk_0e8 = 0x1a;
        b->mUnk_0ec = 0x14;
        n = 0xd;
    } else {
        x = n * 0x1a >> 6;
        y = n * 0x14 >> 6;
        n = n * 0xd >> 6;
        if (x > 0) {
            if (y < 1) {
                y = 1;
            }
            if (n < 1) {
                n = 1;
            }
        }
        b->mUnk_0e8 = x;
        b->mUnk_0ec = y;
    }
    if ((s32) (b->mUnk_000.mUnk_78 & ~0xc000001f) > 0x27100) {
        if (func_0203c5e4() == 0) {
            return;
        }
    }
    if (n < 1) {
        return;
    }
    if (b->mUnk_0b0 == 0) {
        b->mUnk_0b4.mUnk_030 = n;
        func_020e54e4(&b->mUnk_0b4, b->mUnk_0a8 != 0 ? &data_0217b75c : 0, c, d);
        return;
    }
    if (b->mUnk_0b0 != 1) {
        return;
    }
    if (b->mUnk_0a8 != 0) {
        p = b->mUnk_0fc;
        data_0217b720.mUnk_24.x = p->x >> 4;
        data_0217b720.mUnk_24.y = p->y >> 4;
        data_0217b720.mUnk_24.z = p->z >> 4;
        func_020e5370(&data_0217b760, &data_0217b720, (u16) n, d);
        return;
    }
    v.x = (s32) (((s64) b->mUnk_000.mUnk_1c.x * 0x1666) >> 12);
    v.y = (s32) (((s64) b->mUnk_000.mUnk_1c.y * 0x1666) >> 12);
    v.z = (s32) (((s64) b->mUnk_000.mUnk_1c.z * 0x1666) >> 12);
    if (b->mUnk_100 != 0) {
        q = func_020e6b58(b->mUnk_0fc);
    } else {
        p = b->mUnk_0fc;
        data_0217b720.mUnk_24.x = p->x >> 4;
        data_0217b720.mUnk_24.y = p->y >> 4;
        data_0217b720.mUnk_24.z = p->z >> 4;
        q = &data_0217b720;
    }
    func_020e5370(&v, q, (u16) n, d);
}

void func_020debec(void *a, Unk020de6a8 *b) {
    u32 n;

    b->mUnk_0a0++;
    if (b->mUnk_0a0 >= 0x12c) {
        b->mUnk_0a0 = 0;
    }
    b->mUnk_0a2++;
    if (b->mUnk_0a2 >= 0x82) {
        b->mUnk_0a2 = 0;
    }
    n = b->mUnk_0a4;
    if (n >= 0x80) {
        return;
    }
    b->mUnk_0a4 = n + 1;
    if (n > 0x60) {
        b->mUnk_000.mUnk_02 = b->mUnk_000.mUnk_02 & ~1;
    }
}
