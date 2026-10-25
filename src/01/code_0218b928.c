#include "01/code_0218b928.h"
#include "01/unk_021a6000.h"
#include "01/code_02188000.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_020d4000.h"

typedef struct Unk0218b928_local {
    s32 mUnk_00;
    Vec3 *mUnk_04;
    s32 mUnk_08;
    u32 mUnk_0c;
} Unk0218b928_local;

void func_ov001_0218bee4(Unk02188950 *param_1) {
    Unk0206bcb0 *unk;

    unk = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 2, func_ov001_0218c55c);
    func_ov001_02188d30(param_1, param_1->mUnk_0a0->mUnk_184, param_1->mUnk_0a0->mUnk_188, func_ov001_0218bfc8);
    func_ov001_0219b1c4(param_1->mUnk_304, param_1->mUnk_0a0->mUnk_18c, param_1->mUnk_0a0->mUnk_188, 0);
    func_ov001_02188cd8(param_1, 0, param_1->mUnk_0a0->mUnk_144);
    func_ov001_02188a30(param_1, 0, param_1->mUnk_0a0->mUnk_154, param_1->mUnk_0a0->mUnk_148,
                        param_1->mUnk_0a0->mUnk_14c);
    func_ov001_02188968(param_1, &unk->mUnk_80);
    func_ov001_02188980(param_1, (Vec3 *)func_ov001_02187fc0(param_1));
    func_ov001_02188e74((int) (param_1), (u32) (param_1->mUnk_0a0->mUnk_190), (u32) (func_ov001_0218c0a4));
}

void func_ov001_0218bde8(Unk02188950 *param_1) {
    Unk0206bcb0 *unk;

    unk = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 2, func_ov001_0218c55c);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_134, param_1->mUnk_0a0->mUnk_138);
    func_ov001_0219b1c4(param_1->mUnk_304, param_1->mUnk_0a0->mUnk_13c, param_1->mUnk_0a0->mUnk_138, 0);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_140, param_1->mUnk_0a0->mUnk_144);
    func_ov001_02188a30(param_1, param_1->mUnk_0a0->mUnk_150, param_1->mUnk_0a0->mUnk_154, param_1->mUnk_0a0->mUnk_148,
                        param_1->mUnk_0a0->mUnk_14c);
    func_ov001_02188968(param_1, &unk->mUnk_80);
    func_ov001_02188980(param_1, (Vec3 *)func_ov001_02187fc0(param_1));
    func_ov001_02188e24((int) (param_1), (u32) (param_1->mUnk_0a0->mUnk_158), (int) (func_ov001_0218bee4));
    param_1->mUnk_138 = func_ov001_02187f7c(param_1);
    func_ov001_0218c5fc((u32) (param_1));
}

void func_ov001_0218bd80(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 7, 0);
    func_ov001_02188d30(param_1, param_1->mUnk_0a0->mUnk_1f8, param_1->mUnk_0a0->mUnk_1fc, 0);
    func_ov001_0219b1c4(param_1->mUnk_304, param_1->mUnk_0a0->mUnk_200, param_1->mUnk_0a0->mUnk_1fc, 0);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    param_1->mUnk_002 &= ~0x20;
}

void func_ov001_0218bcc4(Unk02188950 *param_1) {
    Vec3 local = {0, 0, 0};

    local.y = param_1->mUnk_0a0->mUnk_1f4;
    func_ov001_02187218(param_1, 7, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_1e0, param_1->mUnk_0a0->mUnk_1e4);
    func_ov001_0219b1c4(param_1->mUnk_304, param_1->mUnk_0a0->mUnk_1e8, param_1->mUnk_0a0->mUnk_1e4, 0);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188c90(param_1);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_1ec, param_1->mUnk_0a0->mUnk_1f0);
    func_ov001_02188db8((int) (param_1), (int) (func_ov001_0218bd80));
    func_020d2774((int) (param_1), (u32) (0x226));
    param_1->mUnk_002 |= data_ov001_021a65a8;
}

void func_ov001_0218bc60(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 7, 0);
    func_ov001_02188d30(param_1, param_1->mUnk_0a0->mUnk_1d4, param_1->mUnk_0a0->mUnk_1d8, func_ov001_0218bcc4);
    func_ov001_0219b1c4(param_1->mUnk_304, param_1->mUnk_0a0->mUnk_1dc, param_1->mUnk_0a0->mUnk_1d8, 0);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
}

void func_ov001_0218bbac(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 7, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_1b4, param_1->mUnk_0a0->mUnk_1b8);
    func_ov001_0219b1c4(param_1->mUnk_304, param_1->mUnk_0a0->mUnk_1bc, param_1->mUnk_0a0->mUnk_1b8, 0);
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_1c8, param_1->mUnk_0a0->mUnk_1cc);
    func_ov001_02188998(param_1, &param_1->mUnk_09c->mUnk_00);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_1c0, param_1->mUnk_0a0->mUnk_1c4);
    func_ov001_02188e24((int) (param_1), (u32) (param_1->mUnk_0a0->mUnk_1d0), (int) (func_ov001_0218bc60));
    func_ov001_0218c5fc((u32) (param_1));
}

int func_ov001_0218bb74(Unk02188950 *param_1) {
    if (func_ov001_02188220((int) (param_1)) == 1) {
        func_020d275c((int) (param_1), (u32) (0x220));
    } else if (func_ov001_02188220((int) (param_1)) == 2) {
        func_020d275c((int) (param_1), (u32) (0x221));
    }
    return 0;
}

void func_ov001_0218ba48(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, func_ov001_0218bb74);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_0dc, param_1->mUnk_0a0->mUnk_0e0);
    func_ov001_0219b1c4(param_1->mUnk_304, param_1->mUnk_0a0->mUnk_0e4, param_1->mUnk_0a0->mUnk_0e0, 0);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_0e8, param_1->mUnk_0a0->mUnk_0ec);
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_0f0, param_1->mUnk_0a0->mUnk_0f4);
    func_ov001_02188998(param_1, (Vec3 *)func_ov001_02187fc0(param_1));
    func_ov001_02188e24((int) (param_1), (u32) (param_1->mUnk_0a0->mUnk_100), (int) (func_ov001_0218c354));
    func_ov001_02188d08(param_1, param_1->mUnk_01c + param_1->mUnk_0a0->mUnk_0f8, param_1->mUnk_0a0->mUnk_0fc);
    func_ov001_02188cec(param_1, 0);
    func_0209b688(param_1->mUnk_304, func_ov001_02188220((int) (param_1)));
    if (func_ov001_02188220((int) (param_1)) == 0) {
        func_ov001_0218c6b4((int) (param_1));
        func_ov001_0218756c((int) (param_1), (u32) (0), (u32) (0x1800), (u32) (0), (u32) (0x419), (u32) (0));
    } else if (func_ov001_02188220((int) (param_1)) == 1) {
        func_ov001_0218c63c((int) (param_1));
        func_ov001_0218756c((int) (param_1), (u32) (0), (u32) (0x1800), (u32) (0), (u32) (0x41a), (u32) (0));
    }
}

void func_ov001_0218ba34(Unk02188950 *param_1) {
    func_ov001_0218ba48(param_1);
    func_ov001_02188230(param_1);
}

void func_ov001_0218b9b4(Unk02188950 *param_1) {
    Unk0206bcb0 *unk;

    unk = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 8, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_078, param_1->mUnk_0a0->mUnk_07c);
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_20c, param_1->mUnk_0a0->mUnk_210);
    func_ov001_02188998(param_1, &unk->mUnk_80);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_204, param_1->mUnk_0a0->mUnk_208);
}

void func_ov001_0218b928(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, 0);
    func_0208b7bc(0x418, &param_1->mUnk_004);
    func_0208b7bc(0x417, &param_1->mUnk_004);
    func_0208b7bc(0x416, &param_1->mUnk_004);
    {
        Unk0218b928_local local = {0x225, 0, 0xf, 0};

        local.mUnk_04 = &param_1->mUnk_004;
        local.mUnk_0c = func_020d4ef4(local.mUnk_04);
        func_0210b734((u32) &local, func_02108e7c());
    }
    param_1->mUnk_002 |= data_ov001_021a659c;
    param_1->mUnk_002 |= data_ov001_021a65a0;
    param_1->mUnk_002 |= data_ov001_021a65a4;
}
