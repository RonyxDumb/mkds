#include "00/code_0219922c.h"
#include "00/code_0218e8c4.h"

u32 func_ov000_0219922c(int param_1, u32 param_2, u32 param_3) {
    int iVar1;
    int iVar2;
    iVar1 = (int) func_ov000_0219a5b0((Unk02197e8c *) param_1, param_2, param_3);
    if (*(int *) (param_1 + 0x2c) != 0) {
        iVar2 = func_ov000_02197f28((int) (param_1), (int) (iVar1), (u32) (param_2), (u32) (param_3), (u32) (1),
                                    (int) (0), (int) (0), (int) (0));
        if (iVar2 == 0) {
            return 0;
        }
    }
    if (iVar1 == 0) {
        return 1;
    }
    if (*(int *) (iVar1 + 0xc) == 0) {
        if ((*(int *) (iVar1 + 0x20) == 0) ||
            (iVar2 = func_ov000_0218e8c4(), (u32) (iVar2 - *(int *) (iVar1 + 0x1c)) < *(u32 *) (iVar1 + 0x20))) {
            return 1;
        }
        iVar1 = func_ov000_02199fb0((int) (iVar1), (u32) (6), (u32) (1));
        if (iVar1 == 0) {
            return 0;
        }
    } else {
        iVar1 = func_ov000_02199fb0((int) (iVar1), (u32) (2), (u32) (1));
        if (iVar1 == 0) {
            return 0;
        }
    }
    return 1;
}
