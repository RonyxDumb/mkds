#include "Main/Unknown/code_020f6be8.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f6be4.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "code_02147cd8.h"

s32 func_020f7184(Unk020f41c4_A *param_1, s32 param_2, s32 param_3) {
    Vec3 *v = &param_1->mUnk_5c;
    Unk0217bc34 *e;
    s32 r;
    enum { K0 } k;

    if (param_1->mUnk_74 & 0x80000) {
        return 2;
    }
    if (param_3 == 0 && (param_1->mUnk_74 & 0x8000000) && !(param_1->mUnk_74 & 0x10000000) &&
        !(param_1->mUnk_74 & 0x20000000)) {
        if (param_1->mUnk_78 & 0xf00) {
            return 2;
        }
        if (param_2 == 0) {
            param_1->mUnk_78 |= data_02159b6c;
        } else {
            param_1->mUnk_78 |= data_02159b68;
            func_020f9c40((int) param_1);
        }
        param_1->mUnk_120 = 0;
        return 1;
    }
    if (param_2 == 0) {
        k = param_1->mUnk_44;
        e = &data_0217bc34[k];
        if (e->mUnk_34 != 0) {
            r = e->mUnk_34(param_1);
            if (r == 0) {
                return 2;
            }
            if (r == 1) {
                return 0;
            }
        }
    }
    if (param_2 != 0) {
        param_1->mUnk_108.y = 0x266;
    } else {
        param_1->mUnk_108.y = 0x333;
        if (!(param_1->mUnk_74 & 0x8000)) {
            param_1->mUnk_108.y += (s32) (((s64) func_021482cc(v) * 0x15c) >> 12);
            if (param_1->mUnk_108.y > 0x5c3) {
                param_1->mUnk_108.y = 0x5c3;
            }
        }
    }
    k = param_1->mUnk_44;
    e = &data_0217bc34[k];
    if (e->mUnk_40 == 0) {
        param_1->mUnk_120 = func_020f6e58;
    }
    param_1->mUnk_124 = (void (*)(Unk020f41c4_A *, Vec3 *, Vec3 *)) func_020f6be4;
    if (param_1->mUnk_f0.y != 0) {
        Vec3 *w = &param_1->mUnk_f0;

        r = func_02039828(v, w);
        if (r < 0x3000) {
            func_02147fd8(0x3000 - r, w, v, v);
        }
    }
    param_1->mUnk_74 |= 0x80001;
    func_020f9c40((int) param_1);
    r = func_02039828(v, (Vec3 *) func_020e6b28());
    if (r > 1) {
        param_1->mUnk_108.x = 1;
    } else {
        param_1->mUnk_108.x = 0;
    }
    return 0;
}

void func_020f7104(Unk020f41c4_A *param_1, s32 param_2) {
    s32 r;

    if (!(param_1->mUnk_74 & 0x8000000)) {
        func_020f7184(param_1, 0, 0);
        return;
    }
    r = func_020f7184(param_1, 0, 0);
    if (r != 0) {
        return;
    }
    if (param_2 == 0) {
        return;
    }
    func_020fe7a0(param_1->mUnk_44, 0, 8, param_1->mUnk_4e);
}

void func_020f70f0(Unk020f41c4_A *param_1) {
    func_020f7184(param_1, 0, 1);
}

void func_020f7070(void *param_1, s32 param_2) {
    Unk020f41c4_A *p = param_1;
    s32 r;

    if (!(p->mUnk_74 & 0x8000000)) {
        func_020f7184(p, 1, 0);
        return;
    }
    r = func_020f7184(p, 1, 0);
    if (r != 0) {
        return;
    }
    if (param_2 == 0) {
        return;
    }
    func_020fe7a0(p->mUnk_44, 1, 8, p->mUnk_4e);
}

void func_020f705c(Unk020f41c4_A *param_1) {
    func_020f7184(param_1, 1, 1);
}

void func_020f6fc4(void *param_1, s32 param_2) {
    Unk020f41c4_A *p = param_1;
    s32 r;
    enum { K0 } k;

    r = func_020f7184(p, 0, 0);
    if (r <= 1) {
        k = p->mUnk_44;
        func_020f91fc(p, data_0217bc34[k].mUnk_94);
    }
    if (r != 0) {
        return;
    }
    if (!(p->mUnk_74 & 0x8000000)) {
        return;
    }
    if (param_2 == 0) {
        return;
    }
    if (p->mUnk_44 == 5) {
        return;
    }
    func_020fe7a0(p->mUnk_44, 2, 8, p->mUnk_4e);
}

void func_020f6f10(Unk020f41c4_A *param_1, s32 param_2, s32 param_3) {
    s32 r;
    enum { K0 } k;

    r = func_020f7184(param_1, 0, 0);
    if (r <= 1) {
        k = param_1->mUnk_44;
        func_020f91fc(param_1, data_0217bc34[k].mUnk_98);
    }
    if (r != 0) {
        return;
    }
    if (!(param_1->mUnk_74 & 0x8000000)) {
        return;
    }
    if (param_2 == 0) {
        return;
    }
    if (param_1->mUnk_44 == 5) {
        return;
    }
    func_020fe7a0(param_1->mUnk_44, 3, param_3, param_1->mUnk_4e);
}

void func_020f6e58(Unk020f41c4_A *param_1) {
    Vec3 v;

    func_020397a8(&param_1->mUnk_f0, (Vec3 *) func_020e6b14(), &v);
    func_02147fd8(param_1->mUnk_108.x != 0 ? param_1->mUnk_108.y : -param_1->mUnk_108.y, &v, &param_1->mUnk_f0,
                  &param_1->mUnk_f0);
    param_1->mUnk_74 |= 0x80;
    param_1->mUnk_5c.y -= 0x400;
    func_02148504(&param_1->mUnk_50, &param_1->mUnk_5c, &param_1->mUnk_50);
    param_1->mUnk_d8--;
    if (param_1->mUnk_d8 > 0) {
        return;
    }
    func_020f0f70(&data_027e00cc[param_1->mUnk_44], param_1);
}

void func_020f6be8(Unk020f41c4_A *param_1, Vec3 *param_2, Vec3 *param_3, Vec3 *param_4) {
    Vec3 v;
    Vec3 a;
    Vec3 *q;
    s32 dot;
    s64 d;

    func_021484d0(param_3, &param_1->mUnk_5c, &a);
    func_021484d0(&param_1->mUnk_50, param_2, &v);
    dot = func_0214848c(param_4, &v);
    v.x -= (s32) (((s64) param_4->x * dot) >> 12);
    v.y -= (s32) (((s64) param_4->y * dot) >> 12);
    v.z -= (s32) (((s64) param_4->z * dot) >> 12);
    d = (s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z;
    if (d >= 0x10) {
        func_02039860(&v, &v);
    }
    if (param_1->mUnk_74 & 0x8000) {
        func_02147fd8(0x666, &a, &param_1->mUnk_5c, &param_1->mUnk_5c);
        q = data_0217bc4c;
        q->x = (s32) (((s64) v.x * 0xccd) >> 12);
        q->y = (s32) (((s64) v.y * 0xccd) >> 12);
        q->z = (s32) (((s64) v.z * 0xccd) >> 12);
        func_02148504(&param_1->mUnk_5c, data_0217bc4c, &param_1->mUnk_5c);
    } else {
        param_1->mUnk_5c.x = (s32) (((s64) param_3->x * 0x8cd) >> 12);
        param_1->mUnk_5c.y = (s32) (((s64) param_3->y * 0x8cd) >> 12);
        param_1->mUnk_5c.z = (s32) (((s64) param_3->z * 0x8cd) >> 12);
        q = data_0217bc4c;
        q->x = (s32) (((s64) v.x * 0x1800) >> 12);
        q->y = (s32) (((s64) v.y * 0x1800) >> 12);
        q->z = (s32) (((s64) v.z * 0x1800) >> 12);
        func_02148504(&param_1->mUnk_5c, data_0217bc4c, &param_1->mUnk_5c);
    }
}
