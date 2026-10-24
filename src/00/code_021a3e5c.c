#include "00/code_021a3e5c.h"

u32 func_ov000_021a3e5c(int param_1, int param_2) {
    int iVar3;
    int extraout_r1;
    int iVar2;
    int *piVar1;
    iVar3 = 0;
    iVar2 = param_1;
    do {
        if (param_2 == *(int *) (iVar2 + 0xd8)) {
            return 1;
        }
        iVar2 = iVar2 + 4;
        iVar3 = iVar3 + 1;
    } while (iVar3 < 10);
    extraout_r1 = (*(int *) (param_1 + ((int) 0x00000100u)) + 1) % (10);
    piVar1 = (int *) (param_1 + ((int) 0x00000100u));
    *piVar1 = extraout_r1;
    *(int *) (param_1 + *piVar1 * 4 + 0xd8) = param_2;
    return 0;
}
