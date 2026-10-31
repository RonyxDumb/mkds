#include "00/code_02189888.h"

u32 func_ov000_02189888(Unk02188ec0 *param_1) {
    u8 uVar1;
    int iVar2;
    u32 uVar3;
    if ((param_1->mUnk_d16 != 0) && (iVar2 = func_ov000_0218973c(2), iVar2 != 0)) {
        uVar1 = func_ov000_02189df8((u32) (0));
        param_1->mUnk_d11 = uVar1;
        return 5;
    }
    if (param_1->mUnk_d0b_4 < 1) {
        uVar3 = func_ov000_02189c04(param_1);
        return uVar3;
    }
    return 6;
}
