#include "Main/Unknown/code_020f8e78.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210c000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02109038.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_020e337c.h"

s32 func_020f9290(void *param_1, Vec3 *param_2) {
    Unk020f41c4_A *p = param_1;
    if ((p->mUnk_74 & 0x2000000) != 0 && func_02039828(param_2, &p->mUnk_108) < 0 && (p->mUnk_74 & 8) == 0) {
        func_020f6fc4(p, 1);
        return 1;
    }
    return 0;
}

void func_020f91fc(void *param_1, s32 param_2) {
    Unk020f41c4_A *p = param_1;
    Unk0210b7a8 a;

    if (param_2 == 1) {
        return;
    }
    if ((s32) (p->mUnk_d4 & ~0xc000001f) >= data_0217ca6c[1].mUnk_20) {
        return;
    }
    if (param_2 == 1) {
        return;
    }
    a = data_0216c698;
    a.mUnk_04 = (s32) &p->mUnk_50;
    a.mUnk_00 = param_2;
    a.mUnk_0c = p->mUnk_d4 & ~0xc000001f;
    func_0210b7a8(&a);
}

s32 func_020f91e0(void *param_1) {
    Unk020f41c4_A *p = param_1;

    return p->mUnk_70 >= 0xccd;
}

s32 func_020f91c4(Unk020f41c4_A *param_1, s32 param_2) {
    return (s32) (param_1->mUnk_d4 & ~0xc000001f) > param_2 * param_2;
}

s32 func_020f9160(Unk020f41c4_A *param_1) {
    s32 a;
    s32 b;

    a = 0;
    if ((param_1->mUnk_74 & 0x10000) == 0) {
        a = 1;
    }
    if (a != 0 && (s32) (param_1->mUnk_d4 & ~0xc000001f) <= 0x3d0900) {
        b = 1;
    } else {
        b = 0;
    }
    if (b == 0 && (s32) (param_1->mUnk_d4 & ~0xc000001f) > 0x3d090) {
        return 1;
    }
    return 0;
}

// non-matching: the table element's subscript and base keep the opposite registers: the original
// emits `ldr r3,[r4,#0x44]; ldr r2,[r1]; mla r1,r3,r1,r2`, this emits
// `ldr r3,[r1]; ldr r2,[r4,#0x44]; mla r1,r2,r1,r3`.
void func_020f9114(void *param_1) {
    Unk020f41c4_A *p = param_1;
    s32 a = p->mUnk_44;

    func_02109038((u32) p, (u32) data_0217bc34[a].mUnk_a0, (u32) &p->mUnk_50);
    func_0210cf9c(p, 1);
    p->mUnk_74 |= 0x400000;
}

// non-matching: the bit test uses r0 where the original uses r1:
// `ldr r1,[r4,#0x74]; ands r1,r1,#0x400000` against `ldr r0; ands r0`.
void func_020f90dc(void *param_1) {
    Unk020f41c4_A *p = param_1;
    if ((p->mUnk_74 & 0x400000) == 0) {
        return;
    }
    func_02109054();
    p->mUnk_30 = 0;
    p->mUnk_74 &= ~0x400000;
}

void func_020f90bc(void *param_1) {
    Unk020f41c4_A *p = param_1;

    p->mUnk_40 = p->mUnk_d4 & ~0xc000001f;
    func_020d4e28(p, &p->mUnk_50, p->mUnk_d4);
}

void func_020f9054(void *param_1, s32 param_2, void *param_3, s32 param_4) {
    Unk020f41c4_A *p = param_1;
    void *(*f)(void *, void *, s32);

    f = param_4 != 0 ? func_020fe4c0 : data_0217bc34[param_2].mUnk_48;
    func_020f9a14(p, param_2);
    f(param_3, p, 0);
    p->mUnk_74 &= ~0x400000;
    p->mUnk_74 |= 0x10000000;
}

// non-matching: every data_0217bc34 lookup keeps the subscript and the base in the opposite
// registers (the original loads the subscript first into the higher of the two, this loads the base
// first), which also schedules the subscript load late; the element computed before the 0x180000 bit
// test is recomputed inside the taken path instead of being predicated. 0x1e0 bytes against
// 0x1dc.
void func_020f8e78(void *param_1) {
    Unk020f41c4_A *p = param_1;
    Unk0217bc34 *e;
    s32 a;

    p->mUnk_70 = 0xccd;
    p->mUnk_74 |= 0x40;
    p->mUnk_6c = p->mUnk_70;
    p->mUnk_68 = p->mUnk_6c;
    e = &data_0217bc34[p->mUnk_44];
    p->mUnk_dc = (s32) (((s64) p->mUnk_6c * e->mUnk_64) >> 12);
    p->mUnk_e0 = (s32) (((s64) p->mUnk_6c * e->mUnk_6c) >> 12);
    func_020d5148(p->mUnk_da, p->mUnk_e0 + 0xa000);
    func_0208adc8(p->mUnk_7c.mUnk_00, 1);
    p->mUnk_90 = 0;
    p->mUnk_f0 = data_02159ca0;
    p->mUnk_fc = 0;
    p->mUnk_100 = 0;
    *p->mUnk_104 = 0;
    p->mUnk_108.x = 0;
    p->mUnk_108.y = 0;
    p->mUnk_108.z = 0;
    p->mUnk_114 = 5;
    p->mUnk_116 = 0;
    p->mUnk_118 = 0;
    p->mUnk_11a = 0;
    p->mUnk_11c = 1;
    if ((p->mUnk_74 & 0x400000) == 0) {
        func_02109038((u32) p, (u32) data_0217bc34[p->mUnk_44].mUnk_a0, (u32) &p->mUnk_50);
        func_0210cf9c(p, 1);
        p->mUnk_74 |= 0x400000;
    }
    if ((p->mUnk_74 & 0x180000) == 0) {
        p->mUnk_120 = data_0217bc34[p->mUnk_44].mUnk_28;
    }
    if ((p->mUnk_78 & 0xf00) != 0) {
        return;
    }
    if (data_0217bc34[p->mUnk_44].mUnk_54 != 0) {
        return;
    }
    a = p->mUnk_da != -1;
    if (a != 0) {
        return;
    }
    if (a != 0) {
        return;
    }
    p->mUnk_da = func_020d555c(&p->mUnk_50, p->mUnk_e0 + 0xa000, 0x4000, p);
}
