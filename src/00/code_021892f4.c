#include "00/code_021892f4.h"

u32 func_ov000_021892f4(u8 *param_1) {
    u8 bVar1;
    int iVar2;
    bVar1 = *param_1;
    if (bVar1 <= 10) {
        iVar2 = func_ov000_02189280();
        if (iVar2 == 1) {
            *param_1 = 0;
            return 1;
        }
        if (iVar2 == -1) {
            *param_1 = 0x12;
            return 1;
        }
    } else if (bVar1 == 0xe) {
        func_ov000_02187fb8();
        func_ov000_02188068();
        *param_1 = 0xc;
    } else if ((bVar1 < 0x12) && (iVar2 = func_ov000_0218925c(), iVar2 == 1)) {
        *param_1 = 10;
    }
    return 0;
}
