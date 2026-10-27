#include "Main/Unknown/code_02104a0c.h"

#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020deb2c.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f5d6c.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_021053d8.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_021052fc.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f81b8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02147cd8.h"
#include "code_0212c6ac.h"
#include "code_0212df7c.h"

u16 data_0215a584 = 0x2000;

Unk0215a6c0 data_0215a6c0 = {{0x1000, 0x1000, 0x1000}};
Unk0215a6c0 data_0215a6cc = {{0, 0, 0}};

#pragma thumb on
void func_02105214(void) {
    Unk0215a6c0 buf;
    s32 i;
    switch (data_021759c0->mUnk_08) {
        case 2:
            data_0217c724 = 0xb;
            break;
        case 4:
            data_0217c724 = 0x20;
            break;
        case 5:
            data_0217c724 = 6;
            break;
        default:
            data_0217c724 = 3;
            break;
    }
    data_0217c72c = func_02036bec(func_020364e0(func_020364e8()), data_0217c724 * 4);
    buf = data_0215a6cc;
    data_0217c730.mUnk_00 = buf;
    data_0217c73c = buf;
    data_0217c748 = data_0215a6c0;
    data_0217c730.mUnk_24 = 0x6f;
    data_0217c730.mUnk_2e = 1;
    for (i = 0; i < data_0217c724; i++) {
        data_0217c72c[i] = func_020d34c4(&data_0217c730, 0x6f);
    }
    data_0217c728 = 0;
}
#pragma thumb off

void func_021051d4(Unk020edb8c *p0, Unk020f40dc *p1) {
    func_020695c4(p1->mUnk_04->mUnk_1fc);
    func_020f4754(p1, 1);
    func_020f81b8((unsigned int) p0->mUnk_0c, 0xe);
}

void func_0210515c(s32 a) {
    (*(Unk020ee684 **) data_027e00c8)[a].mUnk_014 = 0x13;
    if (data_021759c0->mUnk_08 != 5) {
        return;
    }
    if (a == data_021759c0->mUnk_62) {
        return;
    }
    func_020efd84(&(*(Unk020ee684 **) data_027e00c8)[a], 0xe);
}

void func_02104ff8(void) {
    s32 i;
    s32 c;
    Unk020ee684 *p;
    Unk020f40dc *q;
    Unk0212c400 **v;
    u32 a = 0;
    u32 b = 0;
    if (data_021759c0->mUnk_08 != 2) {
        return;
    }
    for (i = 0; i < 8; i++) {
        c = data_0217c6e4[i];
        if (c < 0) {
            continue;
        }
        p = &(*(Unk020ee684 **) data_027e00c8)[(u16) i];
        q = &p->mUnk_030;
        if (q->mUnk_00 != 0x13) {
            continue;
        }
        if (c == 0) {
            func_020f47e4(q, 0x11);
            data_0217c704[i] = 0;
            if (i == data_021759c0->mUnk_62 && (data_0217c780 & 1)) {
                v = (Unk0212c400 **) func_0210e128((void *) func_02108ea0(0));
                if (data_0217d084.mUnk_0c != 0) {
                    if (v[0] != 0) {
                        func_0212c6f0(v, 0);
                    }
                    if (v[0] != 0) {
                        func_0212c6f0(v, a);
                    }
                    func_0212ecc0(v, b, 0x3f);
                }
            }
        } else if (data_0217c704[i] != 0 && c > 0) {
            data_0217c6e4[i]--;
        }
    }
}

void func_02104f84(s32 a) {
    if (data_021759c0->mUnk_08 != 2) {
        return;
    }
    if ((s32) data_0217c6e4[a] >= 0) {
        return;
    }
    data_0217c6e4[a] = 0;
    func_020f0044(&(*(Unk020ee684 **) data_027e00c8)[a]);
}

void func_02104f58(Unk0206bcb0 *p) {
    if (p->mUnk_138.x != 0) {
        (*(Unk021052fc **) &p->mUnk_12c.z)->mUnk_b0 = 1;
    }
    if ((*(u32 *) &p->mUnk_74 & 0x180000) == 0) {
        p->mUnk_120 = func_02104a0c;
    }
}

u32 func_02104f14(Unk0206bcb0 *p) {
    u16 i = (u16) (*(u16 *) &p->mUnk_78 & ~0xff00);
    if ((s32) data_0217c6e4[i] > 0) {
        data_0217c704[i] = 1;
    }
    return func_021053d8((u32) * (Unk021052fc **) &p->mUnk_12c.z);
}

void func_02104ee0(Unk0206bcb0 *p, s32 a) {
    func_020deb2c((u32) &p->mUnk_50, a, 0, (*(u32 *) &p->mUnk_74 & 0x10000) ? 1 : 0, 0);
}

void func_02104e58(Unk0206bcb0 *p) {
    p->mUnk_148 = 0x666;
    func_021053e4(*(Unk021052fc **) &p->mUnk_12c.z);
    p->mUnk_138.x = (u16) (*(u16 *) &p->mUnk_78 & ~0xff00) == data_021759c0->mUnk_62;
    if (p->mUnk_138.x != 0) {
        (*(Unk021052fc **) &p->mUnk_12c.z)->mUnk_b0 = 2;
    }
    data_0217c6e4[(u16) (*(u16 *) &p->mUnk_78 & ~0xff00)] = 0x258;
}

void func_02104d78(Unk020edb8c *p0, Unk0206bcb0 *p1) {
    Vec3 t;
    Unk021052fc *b = *(Unk021052fc **) &p1->mUnk_12c.z;
    s32 n;
    if (p1->mUnk_138.x != 0) {
        func_02147fd8((s32) (((s64) p0->mUnk_8c * -28877) >> 12), &p0->mUnk_38, &p1->mUnk_50, (Vec3 *) &p1->mUnk_138.y);
        n = p1->mUnk_148;
        t.x = (s32) (((s64) p1->mUnk_68.x * n) >> 12);
        t.y = (s32) (((s64) p1->mUnk_68.y * n) >> 12);
        t.z = (s32) (((s64) p1->mUnk_68.z * n) >> 12);
        func_02105338(b, *(s16 *) &p1->mUnk_d8, &t);
    } else {
        *(Vec3 *) &p1->mUnk_138.y = p1->mUnk_50;
        func_02105338(b, *(s16 *) &p1->mUnk_d8, &p1->mUnk_68);
    }
    func_021052fc(b);
}

s32 func_02104c68(Unk020edb8c *p0, Unk0206bcb0 *p1) {
    func_020f9114(p1);
    *(u16 *) &p1->mUnk_78 |= data_0215a584;
    if (p1->mUnk_138.x != 0) {
        (*(Unk021052fc **) &p1->mUnk_12c.z)->mUnk_b0 = 1;
    }
    if ((p0->mUnk_0c->mUnk_1ec & 0x10) != 0) {
        func_020f3150(p1, p0, 0, 1, 0x4000, 0x3000, 0x59a);
        func_021090c4(p1, 0xda, 0x7f, 0);
        p1->mUnk_12c.y = 1;
        return p1->mUnk_12c.y;
    } else {
        func_020f3150(p1, p0, 0, 0, 0x4000, 0x3000, 0x59a);
        if (p0->mUnk_68 < 0x1000) {
            p1->mUnk_05c.x = 0;
            p1->mUnk_05c.y = 0;
            p1->mUnk_05c.z = 0;
        }
        p1->mUnk_12c.y = 0;
        return p1->mUnk_12c.y;
    }
}

void func_02104a0c(Unk0206bcb0 *p) {
    u32 buf;
    Vec3 d;
    Vec3 t;
    u16 i;
    s32 v;
    s32 n;
    s32 a;
    Unk021052fc *b;
    if ((*(u32 *) &p->mUnk_74 & 0x180000) != 0) {
        if ((*(u32 *) &p->mUnk_74 & 0x80000) != 0) {
            func_020f6e58((Unk020f41c4_A *) p);
        } else if ((*(u32 *) &p->mUnk_74 & 0x100000) != 0) {
            func_020f758c((Unk020f41c4_A *) p);
        }
    } else if ((*(u32 *) &p->mUnk_74 & 0x8000) != 0) {
        if (data_021759c0->mUnk_08 == 2) {
            i = (u16) (*(u16 *) &p->mUnk_78 & ~0xff00);
            v = data_0217c6e4[i] - 0x3c;
            if (v < *(s16 *) &p->mUnk_d8) {
                *(s16 *) &p->mUnk_d8 = v;
            }
            if (v < 0xa) {
                func_020f9c40((int) p);
                if (v == 0) {
                    func_020f0f70(&data_027e00cc[p->mUnk_44], (Unk020f41c4_A *) p);
                    return;
                }
            }
            data_0217c6e4[i]--;
        }
        func_020f68b0(p);
    } else if ((*(u32 *) &p->mUnk_74 & 0x4000) != 0) {
        func_020f63cc(p);
    } else {
        if (p->mUnk_12c.y != 0) {
            func_020f2df0(p, 0x1ec, 0xfec, 0, &buf);
        } else {
            func_020f2df0(p, 0x2e1, 0xf85, 0, &buf);
        }
        if ((*(u32 *) &p->mUnk_74 & 8) != 0 && (*(u32 *) &p->mUnk_74 & 3) == 0) {
            if (p->mUnk_12c.y != 0) {
                p->mUnk_05c.y <<= 1;
            }
            func_02109060(p, 0xda);
            func_020f6a6c(p, &buf);
        }
    }
    a = p->mUnk_138.x;
    b = *(Unk021052fc **) &p->mUnk_12c.z;
    if (a != 0 && p->mUnk_148 < 0x1000) {
        p->mUnk_148 += 0xcd;
        n = p->mUnk_148;
        t.x = (s32) (((s64) p->mUnk_68.x * n) >> 12);
        t.y = (s32) (((s64) p->mUnk_68.y * n) >> 12);
        t.z = (s32) (((s64) p->mUnk_68.z * n) >> 12);
        func_021484d0(&p->mUnk_50, (Vec3 *) &p->mUnk_138.y, &d);
        func_02147fd8((s32) (((s64) p->mUnk_148 * p->mUnk_148) >> 12), &d, (Vec3 *) &p->mUnk_138.y,
                      (Vec3 *) &p->mUnk_138.y);
        func_02105338(b, *(s16 *) &p->mUnk_d8, &t);
    } else {
        *(Vec3 *) &p->mUnk_138.y = p->mUnk_50;
        func_02105338(b, *(s16 *) &p->mUnk_d8, &p->mUnk_68);
    }
    func_021052fc(b);
}
