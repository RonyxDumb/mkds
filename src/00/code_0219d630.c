#include "00/code_0219d630.h"

u32 func_ov000_0219d660(void) {
    if ((*(int *) &data_ov000_021b5664) != 0) {
        return *(u32 *) ((*(int *) &data_ov000_021b5664) + 0x14);
    }
    return 0;
}

int func_ov000_0219d630(int param_1) {
    u32 uVar1;
    u32 iVar2;
    uVar1 = func_ov000_0219c9c4();
    iVar2 = func_02152520((void *) (uVar1), (void *) (*(int *) ((*(int *) &data_ov000_021b5664) + 0x18) + param_1 * 0xc));
    if ((iVar2 == 0) || (iVar2 == -1)) {
        iVar2 = 0;
    }
    return iVar2;
}
