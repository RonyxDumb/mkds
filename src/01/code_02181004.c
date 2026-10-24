#include "01/code_02181004.h"

u32 func_ov001_02181020(u32 param_1, u32 param_2, u32 param_3) {
    u8 *pbVar1;
    u32 uVar2;
    uVar2 = 0;
    pbVar1 = (u8 *) func_ov001_02181200();
    if ((pbVar1 != (u8 *) 0x0) && (*pbVar1 != param_3)) {
        uVar2 = 1;
        func_ov001_021811c8();
        *pbVar1 = (u8) param_3;
    }
    return uVar2;
}

u8 func_ov001_02181004(void) {
    u8 *puVar1;
    puVar1 = (u8 *) func_ov001_02181200();
    if (puVar1 != (u8 *) 0x0) {
        return *puVar1;
    }
    return 0;
}
