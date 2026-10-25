#include "01/code_0218b640.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02109000.h"
#include "01/code_02187af4.h"
#include "01/code_02187d14.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/unk_0217c000.h"

void func_ov001_0218b72c(Unk02188950 *param_1) {
    func_020ac588(0x191, 0x32, (u32)param_1);
    param_1->mUnk_094 = func_02036bec((void *)func_020364e0(func_020364e8()), 0x44);
    func_02109110(param_1->mUnk_094, 0xf, &param_1->mUnk_004);
    param_1->mUnk_070 = data_0217cc6c[15];
}

void func_ov001_0218b6f8(Unk02188950 *param_1, void *param_2) {
    func_ov001_02188200(param_1, func_ov001_0218b6f8);
    if (param_1->mUnk_2d0 == 0) {
        func_020d26ec(param_2, 0x224);
    }
}

void func_ov001_0218b640(Unk02188950 *param_1, void *param_2) {
    param_1->mUnk_010 = (s64)param_1->mUnk_0a0->mUnk_130 * data_0215d4b4[((u16)param_1->mUnk_1a8 >> 4) * 2] >> 12;
    param_1->mUnk_014 = 0;
    param_1->mUnk_018 = (s64)param_1->mUnk_0a0->mUnk_130 * data_0215d4b4[((u16)param_1->mUnk_1a8 >> 4) * 2 + 1] >> 12;
    param_1->mUnk_2d8 = 0xd;
    func_02073fb0(param_1->mUnk_078 & 0x3fffffe0, 0x1000);
    func_ov001_02188200(param_1, func_ov001_0218b6f8);
    if (param_1->mUnk_2d0 == 0) {
        func_020d26ec(param_2, 0x224);
    }
}
