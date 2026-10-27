#include "00/code_0219caac.h"

u32 func_ov000_0219caf4(void) {
    return *(u32 *) ((*(int *) &data_ov000_021b5664) + 0x20);
}

void func_ov000_0219caac(int param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6, u32 param_7) {
    int *piVar1;
    *(int *) &data_ov000_021b565c = param_1;
    func_0214d168((void *) ((u32 *) (u32) (param_1)), (u8) (0), (u32) (((u32) 0x00000264u)));
    piVar1 = (int *) &data_ov000_021b565c;
    *(u32 *) (*(int *) &data_ov000_021b565c) = param_3;
    *(u32 *) (*piVar1 + 4) = 0;
    *(u32 *) (*piVar1 + 8) = param_4;
    *(u32 *) (*piVar1 + 0xc) = param_5;
    *(u32 *) (*piVar1 + 0x18) = param_6;
    *(u32 *) (*piVar1 + 0x1c) = param_7;
    *(u32 *) (*piVar1 + 0x20) = param_2;
    return;
}
