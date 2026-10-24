#include "00/code_021a1754.h"

u32 func_ov000_021a1754(int param_1, int param_2) {
    int iVar2;
    int iVar1;
    iVar1 = *((int *) ((u32) (&data_ov000_021b566c)));
    if (0 == iVar1) {
        return 0;
    }
    iVar2 = 0;
    if (0 < param_2) {
        do {
            if (param_1 == *(int *) (iVar1 + 0xf4)) {
                func_ov000_021a1620(iVar2);
                return 1;
            }
            iVar1 = iVar1 + 4;
            iVar2 = iVar2 + 1;
        } while (iVar2 < param_2);
    }
    return 0;
}
