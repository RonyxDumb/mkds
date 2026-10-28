#include "Main/Unknown/code_020ec1fc.h"

#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ec1ec.h"
#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/code_020ea670.h"
#include "code_02147cd8.h"

const Unk021594e4 data_021594e4 = {
    0, 0, (u32) &func_020eb720, 0, (u32) &func_020ec1ec, 0, 0, 0, 0, 0,
};

const Unk0215950c data_0215950c = {
    0, 0, (u32) &func_020eb72c, 0, (u32) &func_020ec1fc, 0, 1, 0, 0, 0, 0,
};

const Unk02159538 data_02159538 = {
    (u32) &func_020eb7e0, (u32) &func_020eb760, 4, 0xa000, 0xa000, 0xa000, 0, 1, 1, 0x168, 0x169, 0, 0, 0, 0, 0,
};

s32 func_020ec450(Unk020e43a8 *param_1, void *param_2, u8 *param_3) {
    if (*param_3 != 1) {
        return 0;
    }
    func_020ec6e4(param_1, param_2);
    param_1->mUnk_00.mUnk_80.mUnk_10 = 1;
    param_1->mUnk_00.mUnk_80.mUnk_12 = 1;
    return 1;
}

s32 func_020ec41c(Unk020e43a8 *param_1, void *param_2, u8 *param_3) {
    if (*param_3 != 1) {
        return 0;
    }
    func_020ec538(param_1, param_2);
    param_1->mUnk_00.mUnk_80.mUnk_10 = 1;
    param_1->mUnk_00.mUnk_80.mUnk_12 = 1;
    return 1;
}

Unk02159538 *func_020ec3cc(void) {
    Unk02159538 *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x40);
    *p = data_02159538;
    return p;
}

Unk0215950c *func_020ec370(void) {
    Unk0215950c *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x2c);
    data_0217bbec = p;
    *p = data_0215950c;
    func_020d49d8(&data_0217bbec);
    return data_0217bbec;
}

Unk021594e4 *func_020ec314(void) {
    Unk021594e4 *p;

    p = func_02036bec(func_020364e0(func_020364e8()), 0x28);
    data_0217bbf4 = p;
    *p = data_021594e4;
    func_020e6f50(&data_0217bbf4);
    return data_0217bbf4;
}

void func_020ec1fc(void *param_1, Unk020e43a8 *param_2, void *param_3, u32 param_4) {
    u16 h;
    s32 t;
    Vec3 v;

    h = param_2->mUnk_00.mUnk_80.mUnk_0e;
    param_2->mUnk_00.mUnk_28.mUnk_24.x = param_2->mUnk_00.mUnk_04.x >> 4;
    param_2->mUnk_00.mUnk_28.mUnk_24.y = param_2->mUnk_00.mUnk_04.y >> 4;
    param_2->mUnk_00.mUnk_28.mUnk_24.z = param_2->mUnk_00.mUnk_04.z >> 4;
    func_020ea8a8(data_0217bbf8, &param_2->mUnk_00.mUnk_28, &param_2->mUnk_00.mUnk_1c, param_4);
    if (h == 0) {
        return;
    }
    t = (s32) (((s64) (0x5a000 - param_2->mUnk_d0) * 0x2e) >> 12);
    v.x = param_2->mUnk_00.mUnk_04.x;
    v.z = param_2->mUnk_00.mUnk_04.z;
    v.y = param_2->mUnk_0b4 - (s32) (((s64) param_2->mUnk_0bc * param_2->mUnk_cc) >> 12) -
          (s32) (((s64) param_2->mUnk_0c4 * param_2->mUnk_d4) >> 12);
    func_02147fd8(-param_2->mUnk_00.mUnk_58.x, (const Vec3 *) &param_2->mUnk_0bc, &v, &v);
    func_020e5634((Unk020e516c *) &param_2->mUnk_114, &v);
    func_020e53ac((Unk020e516c *) &param_2->mUnk_114, &t, 0, param_4);
}
