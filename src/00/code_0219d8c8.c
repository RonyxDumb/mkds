#include "00/code_0219d8c8.h"

void func_ov000_0219d8c8(u32 *param_1, u32 param_2, u32 param_3, u32 param_4, u32 param_5) {
    int *piVar1;
    int iVar2;
    piVar1 = (int *) &data_ov000_021b5664;
    *(int *) &data_ov000_021b5664 = (int) param_1;
    *param_1 = 0;
    *(u32 *) (*piVar1 + 4) = param_2;
    *(u32 *) (*piVar1 + 8) = 0;
    iVar2 = *piVar1;
    *(u32 *) (iVar2 + 0xc) = 0;
    *(u32 *) (iVar2 + 0x10) = 0;
    *(u32 *) (iVar2 + 0x14) = param_5;
    *(u32 *) (*piVar1 + 0x18) = param_4;
    *(u8 *) (*piVar1 + 0x1c) = 0;
    *(u8 *) (*piVar1 + 0x1d) = 0;
    *(u8 *) (*piVar1 + 0x1e) = 0;
    *(u8 *) (*piVar1 + 0x1f) = 0;
    *(u32 *) (*piVar1 + 0x20) = 0;
    *(u32 *) (*piVar1 + 0x24) = 0;
    *(u32 *) (*piVar1 + 0x28) = param_3;
    *(u32 *) (*piVar1 + 0x2c) = 0;
    *(u32 *) (*piVar1 + 0x30) = 0;
    *(u32 *) (*piVar1 + 0x34) = 0;
    *(u32 *) (*piVar1 + 0x38) = 0;
    *(u32 *) (*piVar1 + 0x3c) = 0;
    *(u32 *) (*piVar1 + 0x40) = 0;
    *(u32 *) (*piVar1 + 0x44) = 0;
    *(u32 *) (*piVar1 + 0x48) = 0;
    *(u32 *) (*piVar1 + 0x4c) = 0;
    *(u32 *) (*piVar1 + 0x50) = 0;
    return;
}
