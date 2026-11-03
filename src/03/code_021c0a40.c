#include "03/code_021c0a40.h"
#include "03/code_021bf8c0.h"
#include "03/code_021c0a24.h"
#include "03/code_021d1770.h"
#include "03/code_021d34e0.h"
#include "03/unk_021d5f00.h"
#include "03/unk_021da000.h"

// placeholder: volatile stack copies and sprite reads retain the original coordinate access order.
void func_ov003_021c0c2c(u32 param_1) {
    volatile u32 x;
    s32 y;
    s32 z;
    x = ((*(volatile u32 *) &data_ov003_021da15c->mUnk_030[0]->mUnk_00) & 0x1ff0000) >> 16;
    z = *(volatile u32 *) &data_ov003_021da15c->mUnk_030[0]->mUnk_00 & 0xff;
    *(volatile s32 *) &y = z;
    z -= 12;
    *(volatile s32 *) &y = z;
    if (z > data_ov003_021d5fb0[0][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 0, z);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 0, data_ov003_021d5fb0[0][1]);
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 1, 0xc0);
    func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021c0bb0);
}

// placeholder: volatile stack copies and sprite reads retain the original coordinate access order.
void func_ov003_021c0bb0(u32 param_1) {
    volatile u32 x;
    s32 y;
    s32 z;
    x = ((*(volatile u32 *) &data_ov003_021da15c->mUnk_030[12]->mUnk_00) & 0x1ff0000) >> 16;
    z = *(volatile u32 *) &data_ov003_021da15c->mUnk_030[12]->mUnk_00 & 0xff;
    *(volatile s32 *) &y = z;
    z -= 12;
    *(volatile s32 *) &y = z;
    if (z > data_ov003_021d5fb0[12][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 1, z);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 1, data_ov003_021d5fb0[12][1]);
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 2, 0xc0);
    func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021c0b30);
}

// placeholder: volatile stack copies and sprite reads retain the original coordinate access order.
void func_ov003_021c0b30(u32 param_1) {
    volatile u32 x;
    s32 y;
    s32 z;
    x = ((*(volatile u32 *) &data_ov003_021da15c->mUnk_030[24]->mUnk_00) & 0x1ff0000) >> 16;
    z = *(volatile u32 *) &data_ov003_021da15c->mUnk_030[24]->mUnk_00 & 0xff;
    *(volatile s32 *) &y = z;
    z -= 12;
    *(volatile s32 *) &y = z;
    if (z > data_ov003_021d5ff0[8][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 2, z);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 2, data_ov003_021d5ff0[8][1]);
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 3, 0xc0);
    func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021c0ab0);
}

// placeholder: volatile stack copies and sprite reads retain the original coordinate access order.
void func_ov003_021c0ab0(u32 param_1) {
    volatile u32 x;
    s32 y;
    s32 z;
    x = ((*(volatile u32 *) &data_ov003_021da15c->mUnk_030[36]->mUnk_00) & 0x1ff0000) >> 16;
    z = *(volatile u32 *) &data_ov003_021da15c->mUnk_030[36]->mUnk_00 & 0xff;
    *(volatile s32 *) &y = z;
    z -= 12;
    *(volatile s32 *) &y = z;
    if (z > data_ov003_021d6030[4][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 3, z);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 3, data_ov003_021d6030[4][1]);
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 4, 0xc0);
    func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021c0a40);
}

void func_ov003_021c0a40(u32 param_1) {
    u32 x;
    s32 y;
    func_ov003_021d1770(data_ov003_021da15c->mUnk_0fc[0], 0, &x, &y);
    y -= 12;
    if (y > data_ov003_021d5f88[0][1]) {
        func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 4, y);
        return;
    }
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 4, data_ov003_021d5f88[0][1]);
    func_ov003_021bffb0();
    func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021c0a24);
}
