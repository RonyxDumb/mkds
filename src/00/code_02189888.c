#include "00/code_02189888.h"

u32 func_ov000_02189888(int param_1) {
    u8 uVar1;
    int iVar2;
    u32 uVar3;
    if ((*(unsigned short *) (param_1 + ((int) 0x00000d16u)) != 0) &&
        (iVar2 = func_ov000_0218973c((int) (2)), iVar2 != 0)) {
        uVar1 = func_ov000_02189df8((u32) (0));
        *(u8 *) (param_1 + ((int) 0x00000d11u)) = uVar1;
        return 5;
    }
    if (((u32) * (u8 *) (param_1 + ((int) 0x00000d0bu)) << 0x18) >> 0x1c < 1) {
        uVar3 = func_ov000_02189c04((int) (param_1));
        return uVar3;
    }
    return 6;
}
