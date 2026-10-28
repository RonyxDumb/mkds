#include "Main/Unknown/code_020fd264.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020fd83c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0216c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020ee684.h"

#pragma thumb off

u32 func_020fd7a4(int param_1) {
    Unk020fdae8 *e;
    u32 f;

    e = (Unk020fdae8 *) data_027e00cc[9].mUnk_04[param_1];
    f = e->mUnk_000.mUnk_74;
    if ((f & 0x8000) && (f & 0x180000) == 0 && e->mUnk_192 != 3 && e->mUnk_198 == 0) {
        return (u32) e;
    }
    return 0;
}

void func_020fd754(void *param_1) {
    Unk020fdae8 *e;

    e = param_1;
    e->mUnk_000.mUnk_74 &= ~0x8000;
    if ((e->mUnk_000.mUnk_74 & 0x180000) == 0) {
        e->mUnk_000.mUnk_120 = 0;
    }
    func_020f9c40((int) e);
    e->mUnk_1a0 = 0;
    func_02046bcc(&e->mUnk_184, 3);
    e->mUnk_174 = 0;
}

void func_020fd684(void *param_1, Vec3 *param_2, Vec3 *param_3) {
    Unk020fdae8 *e;
    Vec3 *a;
    Vec3 *b;
    Unk021052fc *v1;

    e = param_1;
    a = param_2;
    b = param_3;
    if (e->mUnk_198 == 0) {
        e->mUnk_1a0 = 1;
        func_0208ad74(e->mUnk_000.mUnk_7c.mUnk_00, 1);
    }
    if (a != 0) {
        e->mUnk_000.mUnk_f0 = *a;
        e->mUnk_000.mUnk_74 |= 0x80;
    }
    if (b == 0) {
        return;
    }
    e->mUnk_000.mUnk_50 = *b;
    func_021484d0(&e->mUnk_000.mUnk_50, &e->mUnk_000.mUnk_0e4, &e->mUnk_000.mUnk_5c);
    if (e->mUnk_198 == 0) {
        return;
    }
    e->mUnk_198->mUnk_00.mUnk_04 = *b;
    e->mUnk_198->mUnk_00.mUnk_04.y += e->mUnk_19c;
    v1 = e->mUnk_198;
    v1->mUnk_00.mUnk_02 &= ~2;
    v1->mUnk_00.mUnk_02 &= ~8;
    v1->mUnk_00.mUnk_66 = 0x1f;
}

void func_020fd540(void **param_1, Vec3 *v, s32 a) {
    Unk020fdae8 *e;
    Unk021052fc *v1;

    e = *param_1;
    v1 = e->mUnk_198;
    e->mUnk_000.mUnk_78 |= data_02159f28;
    if (v1 == 0) {
        func_020f9ca8(e);
        e->mUnk_1a0 = 1;
    }
    func_020f9114((Unk0206bcb0 *) e);
    func_02046be8(&e->mUnk_184, (UnkFunc *const *) data_0216c714, 4, e);
    func_02046bcc(&e->mUnk_184, 0);
    e->mUnk_170 = 0x12c;
    e->mUnk_174 = 0;
    e->mUnk_178 = 8;
    e->mUnk_17c = 0x5f592e1;
    e->mUnk_180 = 0;
    e->mUnk_16c = 0;
    e->mUnk_134 = 0xccd;
    e->mUnk_170 = a;
    e->mUnk_130 = 1;
    func_020f30ec((Unk020f2df0 *) e, 3, v);
    if ((e->mUnk_000.mUnk_74 & 0x180000) == 0) {
        e->mUnk_000.mUnk_120 = (void (*)(Unk020f41c4_A *)) func_020fdae8;
    }
    if (v1 != 0) {
        v1->mUnk_00.mUnk_02 &= ~2;
        v1->mUnk_00.mUnk_02 &= ~8;
        v1->mUnk_00.mUnk_66 = 0x1f;
        v1->mUnk_00.mUnk_02 &= ~4;
        if (v1->mUnk_00.mUnk_00 != 0x191) {
            v1->mUnk_00.mUnk_02 &= ~1;
        }
    }
    *param_1 = 0;
}

int func_020fd528(Unk0206bcb0 *param_1) {
    Unk020fdae8 *e;

    e = (Unk020fdae8 *) param_1;
    return e->mUnk_192 == 2;
}

void func_020fd494(void **param_1) {
    Unk020fdae8 *e;
    Unk021052fc *v1;

    e = *param_1;
    func_02046bcc(&e->mUnk_184, 0);
    v1 = e->mUnk_198;
    if (v1 != 0) {
        v1->mUnk_00.mUnk_02 &= ~1;
        func_020d2398(&v1->mUnk_00);
        e->mUnk_198 = 0;
        func_020f0f70(data_027e00cc + e->mUnk_000.mUnk_44, &e->mUnk_000);
    } else {
        func_020f0f70(data_027e00cc + e->mUnk_000.mUnk_44, &e->mUnk_000);
    }
    *param_1 = 0;
}

void *func_020fd428(void) {
    Unk020fdae8 *e;

    e = func_020fa3d0(9, 8, data_02159f40, data_02159f40);
    if (e == 0) {
        return 0;
    }
    if ((e->mUnk_000.mUnk_74 & 0x180000) == 0) {
        e->mUnk_000.mUnk_120 = 0;
    }
    func_020f9c40((int) e);
    e->mUnk_1a0 = 0;
    func_02046bcc(&e->mUnk_184, 3);
    e->mUnk_174 = 0;
    return e;
}

void *func_020fd338(void *param_1, s32 a) {
    Unk020fdae8 *e;
    Unk021052fc *v1;

    v1 = param_1;
    e = func_020fa3d0(9, 8, data_02159f40, data_02159f40);
    if (e == 0) {
        e = 0;
    } else {
        if ((e->mUnk_000.mUnk_74 & 0x180000) == 0) {
            e->mUnk_000.mUnk_120 = 0;
        }
        func_020f9c40((int) e);
        e->mUnk_1a0 = 0;
        func_02046bcc(&e->mUnk_184, 3);
        e->mUnk_174 = 0;
    }
    if (e == 0) {
        return 0;
    }
    func_020d233c(&v1->mUnk_00);
    v1->mUnk_00.mUnk_02 |= data_02159f18;
    v1->mUnk_00.mUnk_02 |= data_02159f1c;
    v1->mUnk_00.mUnk_02 |= data_02159f20;
    v1->mUnk_00.mUnk_02 |= data_02159f24;
    e->mUnk_198 = v1;
    e->mUnk_19c = a;
    return e;
}

Vec3 *func_020fd308(Unk020fdae8 *e, s32 *a, s32 *b) {
    *a = e->mUnk_188;
    *b = (s32) (((s64) e->mUnk_000.mUnk_68.z * data_0217bd48) >> 12);
    return &e->mUnk_000.mUnk_50;
}

#pragma thumb on

void func_020fd264(void) {
    s32 k;

    data_0217bd50 = 0x18006;
    data_0217bd48 = func_02147f34(0x1000, 0x18006);
    data_0217bd54 = 0x2148;
    data_0217bd58 = (s32) (((s64) data_0217bd50 * data_0217bc34[9].mUnk_6c) >> 12);
    data_0217bd58 >>= 12;
    data_0217bd58 *= data_0217bd58;
    k = data_021759c0->mUnk_010;
    switch (k) {
        case 0:
            data_0217bd4c = 0xb4;
            break;
        case 1:
            data_0217bd4c = 0x96;
            break;
        default:
            data_0217bd4c = 0x78;
            break;
    }
}

#pragma thumb off
