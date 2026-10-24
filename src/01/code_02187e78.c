#include "01/code_02187e78.h"

void func_ov001_02187e78(int param_1) {
    int iVar1;
    if (*(int *) (param_1 + ((int) 0x00000148u)) < (int) (u32) * (u16 *) (*((int *) ((u32) (&data_02175620))) + 0xc)) {
        iVar1 = *(int *) (param_1 + ((int) 0x0000014cu)) + 1;
        if (iVar1 >= (int) (u32) * (u16 *) (*(int *) (*((int *) ((u32) (&data_02175620))) + 8) +
                                            ((u32) (*(int *) (param_1 + ((int) 0x00000148u)) << 0x10) >> 0xe) + 2)) {
            iVar1 = 0;
        }
        *(int *) (param_1 + ((int) 0x0000014cu)) = iVar1;
    }
    return;
}
