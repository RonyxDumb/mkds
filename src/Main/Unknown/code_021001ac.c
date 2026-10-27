#include "Main/Unknown/code_021001ac.h"

#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02100de4.h"
#include "Main/Unknown/code_01ff9000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ed578.h"
#include "Main/Unknown/code_020ed588.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f81b8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_027e0000.h"

void func_02100564(Unk020f41c4_A *p) {
    s32 a;
    s32 i;

    a = p->mUnk_154 != 0x13;
    if (p->mUnk_15c == 0) {
        p->mUnk_178 = (s32) (((s64) p->mUnk_178 * 0xf85) >> 12);
        p->mUnk_180 = (s32) (((s64) p->mUnk_180 * 0xf85) >> 12);
        p->mUnk_16c += p->mUnk_178;
        p->mUnk_174 += p->mUnk_180;
    }
    if (a != 0) {
        if (p->mUnk_164 < 0x1f) {
            p->mUnk_164 += 8;
        }
    }
    if (func_02101618(p, p->mUnk_15c == 0 ? 1 : 0, 7) != 0) {
        if (a != 0) {
            if ((p->mUnk_78 & 0x8000) == 0) {
                i = (u16) (p->mUnk_78 & ~0xff00);
            } else {
                i = 8;
            }
            ((void (*)(s32 param_1, s32 param_2, s32 param_3)) func_020f40a0)(p->mUnk_154, p->mUnk_158, (u16) i);
        }
        func_020f0f70(data_027e00cc + p->mUnk_44, (Unk020f41c4_A *) p);
    }
    if (!(p->mUnk_74 & 0x8000000)) {
        return;
    }
    if (p->mUnk_24c != 0) {
        return;
    }
    if (p->mUnk_144 != 0) {
        return;
    }
    if (p->mUnk_264 == 0xffffffff) {
        return;
    }
    if (p->mUnk_264 - 5 <= 1) {
        p->mUnk_144 = 1;
        p->mUnk_264 = -1;
    }
}

void func_0210050c(Unk020f41c4_A *p) {
    int i;
    Unk020f40dc_Owner *e;

    if ((p->mUnk_78 & 0x8000) == 0) {
        i = (u16) (p->mUnk_78 & ~0xff00);
    } else {
        i = 8;
    }
    e = &((Unk020f40dc_Owner *) *(void **) data_027e00c8)[(u16) i];
    if (e->mUnk_14 != 0x10) {
        return;
    }
    if (p->mUnk_158 != -0x40) {
        e->mUnk_14 = 0x13;
    }
}

void func_021004c4(void *p, Unk020f41c4_A *a, void *b) {
    func_020fecdc(p, a, b);
    if (a == 0) {
        return;
    }
    if (b == 0) {
        return;
    }
    func_020fe8ac(a->mUnk_44);
}

void func_0210045c(Unk020f41c4_A *p) {
    int i;

    func_020f8e78(p);
    func_0208adc8(&p->mUnk_7c, 1);
    func_02046bcc((int) p->mUnk_12c, 0);
    if ((p->mUnk_78 & 0x8000) == 0) {
        i = (u16) (p->mUnk_78 & ~0xff00);
    } else {
        i = 8;
    }
    func_020f81b8((unsigned int) &((Unk020f40dc_Owner *) *(void **) data_027e00c8)[(u16) i], 0x10);
}

void func_021003e8(Unk020f41c4_A *p, u32 sel, s32 v1) {
    switch (sel) {
        case 0:
            p->mUnk_250 = v1;
            if (p->mUnk_250 == data_021759c0->mUnk_62) {
                p->mUnk_24c = 1;
            }
            break;
        case 1:
            p->mUnk_264 = v1;
            break;
        case 2:
            p->mUnk_254 = v1 >> 2;
            p->mUnk_258 = v1 & 3;
            break;
        case 3:
            p->mUnk_25c = v1 >> 2;
            p->mUnk_260 = v1 & 3;
            break;
    }
}

// non-matching: the pointer argument of func_020e6854 needs an explicit (u32) cast against the
// shared declaration, which costs a stack slot (0x24 vs 0x1c); the three v[] stores are also
// emitted interleaved with their loads (original: ldr p->0x70, 0x6c, 0x68 into r3, r2, r1, then
// `mov r0, #0x1b`, then the three stores).
void func_021001ac(Unk020f41c4_A *p, s32 param_2, Unk020ed578 *q) {
    s32 a;
    s32 n;
    s32 b;
    s32 t;
    s16 d;
    s32 v[3];
    Unk020ed578 *r;
    s32 i;
    s32 b2;

    if (p->mUnk_d8 <= 0) {
        return;
    }
    a = 0x1e;
    func_01ff9048(0x14, &a, 1);
    func_01ff9048(0x19, func_020e6cf8(p->mUnk_d0), 0xc);
    v[0] = p->mUnk_68;
    v[1] = p->mUnk_6c;
    v[2] = p->mUnk_70;
    func_01ff9048(0x1b, v, 3);
    if (p->mUnk_160 < 0xe && p->mUnk_13a >= 3) {
        r = (Unk020ed578 *) func_020ed578(p->mUnk_160);
        n = p->mUnk_164;
        b2 = p->mUnk_158;
        if (p->mUnk_d8 < 0x1f) {
            if (p->mUnk_d8 < n) {
                n = p->mUnk_d8;
            }
        }
        if (n > 0x1f) {
            n = 0x1f;
        }
        if (n < 1) {
            n = 1;
        }
        func_01ff9048(0x11, 0, 0);
        r->mUnk_14 = r->mUnk_14 & ~0x1f0000;
        r->mUnk_14 = r->mUnk_14 | ((u16) n << 16);
        func_020e6a18(r);
        i = 0;
        r->mUnk_18 = 0;
        while (i < b2) {
            func_01ff9048(0x1c, &data_0215a190[b2 == 2 ? 1 - i : i + 1], 3);
            t = func_020d3c44();
            r->mUnk_14 = r->mUnk_14 & ~0x3f000000;
            r->mUnk_14 = r->mUnk_14 | (t << 24);
            func_020e6854((u32) r, (u32) &p->mUnk_50, 1, 0x1f);
            i++;
        }
        b = 1;
        func_01ff9048(0x12, &b, 1);
        if (n != 0x1f) {
            r->mUnk_14 = r->mUnk_14 & ~0x1f0000;
            r->mUnk_14 = r->mUnk_14 | 0x1f0000;
        }
    }
    t = func_020d3c44();
    q->mUnk_14 = q->mUnk_14 & ~0x3f000000;
    q->mUnk_14 = q->mUnk_14 | (t << 24);
    d = p->mUnk_d8;
    q->mUnk_14 = q->mUnk_14 & ~0x1f0000;
    q->mUnk_14 = q->mUnk_14 | ((u16) d << 16);
    func_020ed588((int) p, (u32) q);
}
