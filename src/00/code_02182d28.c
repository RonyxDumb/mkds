#include "00/code_02182d28.h"

void func_ov000_02182d28(void) {
    int iVar1;
    *(int *) ((*(int *) &data_ov000_021b4c70) + 0x10) = *(int *) ((*(int *) &data_ov000_021b4c70) + 0x10) + 1;
    iVar1 = ((u32) func_02125fa4());
    if ((iVar1 != 0) && (0x78 < *(int *) ((*(int *) &data_ov000_021b4c70) + 0x10))) {
        func_02125fc0();
    }
    iVar1 = ((u32) func_02125f88());
    if (iVar1 != 0) {
        *(u32 *) ((*(int *) &data_ov000_021b4c70) + 4) = 2;
        func_ov000_02182de8();
        *(u32 *) ((*(int *) &data_ov000_021b4c70) + 0x10) = 0;
    }
    return;
}
