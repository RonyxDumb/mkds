#include "00/code_02197ddc.h"

u32 func_ov000_02197e60(int *param_1, int param_2) {
    int iVar1;
    iVar1 = func_ov000_021a3690((u32) (param_2));
    *param_1 = iVar1;
    if (*param_1 == 0) {
        return 0;
    }
    param_1[1] = param_2;
    return 1;
}

int func_ov000_02197e58(int param_1) {
    return *(int *) (param_1 + 4) - *(int *) (param_1 + 8);
}

void func_ov000_02197e20(int *param_1, u8 param_2) {
    int iVar1;
    if (param_1[2] >= param_1[1]) {
        func_0213442c(data_ov000_021b3f34, data_ov000_021b3ebc, 0, 0x23);
    }
    iVar1 = param_1[2];
    param_1[2] = iVar1 + 1;
    *(u8 *) (*param_1 + iVar1) = param_2;
    return;
}

void func_ov000_02197ddc(int *param_1, u32 param_2) {
    int iVar1;
    if (param_1[2] + 2 > param_1[1]) {
        func_0213442c(data_ov000_021b3f10, data_ov000_021b3ebc, 0, 0x2e);
    }
    iVar1 = param_1[2];
    param_1[2] = iVar1 + 1;
    *(s8 *) (*param_1 + iVar1) = (s8) ((int) param_2 >> 8);
    iVar1 = param_1[2];
    param_1[2] = iVar1 + 1;
    *(s8 *) (*param_1 + iVar1) = (s8) param_2;
    return;
}
