#include "00/code_021ae01c.h"

u32 func_ov000_021ae01c(int *param_1, u32 param_2) {
    int iVar1;
    iVar1 = *(int *) (param_2 + 0x44);
    while (iVar1 == 0) {
        *(u32 *) (param_2 + 4) = 3;
        func_0200e01c((int) (0));
        iVar1 = *(int *) (param_2 + 0x44);
    }
    *param_1 = iVar1;
    return *(u32 *) (param_2 + 0x40);
}
