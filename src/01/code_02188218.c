#include "01/code_02188218.h"

unsigned short func_ov001_02188220(Unk02188950 *param_1) {
    u32 uVar1;
    uVar1 = param_1->mUnk_0ac;
    if ((int) uVar1 < 0) {
        uVar1 = -uVar1;
    }
    return uVar1 & 0xffff;
}

void func_ov001_02188218(int param_1, u32 param_2) {
    *(u32 *) (param_1 + 0xb4) = param_2;
    return;
}
