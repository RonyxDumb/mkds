#include "01/code_021842ec.h"
#include "01/unk_021a6000.h"

void func_ov001_021842ec(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 7, 0);
    func_ov001_02188d30(param_1, param_1->mUnk_0a0->mUnk_23c, param_1->mUnk_0a0->mUnk_240, 0);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02187518((Unk02188950 *) param_1, 0, 0, 0, 0x411, 0);
    func_ov001_02187518((Unk02188950 *) param_1, 0, 0, 0, 0x412, 0);
    func_020d2774(&param_1->mUnk_000, (u32) (0x242));
    func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_ov001_02188200(param_1, func_ov001_02184874);
    param_1->mUnk_000.mUnk_02 &= ~0x20;
}
