#include "00/code_0219d6c4.h"

void func_ov000_0219d708(u32 param_1, u32 *param_2) {
    if (*(int *) ((*(int *) &data_ov000_021b5664) + 0x18) != 0) {
        func_ov000_0218eff8((int *) (u32) (param_1), *param_2, 0, 0, (u32) &func_ov000_0219cd74, 0);
    }
    return;
}

u32 func_ov000_0219d6c4(u32 param_1, u32 *param_2) {
    int iVar1;
    iVar1 = func_0213a074((const u8 *) (param_2[2]), (const u8 *) (((u32) &data_ov000_021b4078)));
    if (iVar1 == 0) {
        func_ov000_0218eff8((int *) (u32) (param_1), *param_2, 0, 0, (u32) &func_ov000_0219cc94, 0);
        return 1;
    }
    return 0;
}
