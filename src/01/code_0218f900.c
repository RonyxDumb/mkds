#include "01/code_0218f900.h"

#include "01/code_02187098.h"
#include "01/code_021874c4.h"
#include "01/code_02188000.h"
#include "01/code_02188158.h"
#include "01/code_0218fa20.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_0218f000.h"

void *func_ov001_0218fa04(void) {
    return func_0209bf1c(func_ov001_0218fa78, func_ov001_0218fa58, func_ov001_02187098);
}

void *func_ov001_0218f9ec(void) {
    return func_0209bf48((UnkFunc *) (func_ov001_0218fbe0), (UnkFunc *) (func_ov001_0218fb24), (UnkFunc *) (0));
}

void *func_ov001_0218f9d4(void) {
    return func_0209bf48((UnkFunc *) (func_ov001_0218fcc4), (UnkFunc *) (func_ov001_0218fc4c), (UnkFunc *) (0));
}

u16 func_ov001_0218f9c0(Unk02188950 *param_1) {
    return param_1->mUnk_0a8 == 2;
}

void func_ov001_0218f9a8(Unk02188950 *param_1) {
    param_1->mUnk_2d8 = 0;
    func_ov001_02188200(param_1, func_ov001_0218f9a8);
}

void func_ov001_0218f900(Unk02188950 *param_1) {
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_198, param_1->mUnk_0a0->mUnk_19c);
    func_ov001_02188d1c(param_1, param_1->mUnk_0a0->mUnk_1ac, param_1->mUnk_0a0->mUnk_1b0);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188c90(param_1);
    func_ov001_021875c0((int) param_1, 0, 0, 0, 0x41b, 0);
    func_ov001_021875c0((int) param_1, 0, 0, 0, 0x41c, 0);
    func_ov001_021875c0((int) param_1, 0, 0, 0, 0x41d, 0);
    func_020d2774(param_1, 0x22e);
    param_1->mUnk_002 &= ~1;
}
