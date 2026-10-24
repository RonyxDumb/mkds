#include "00/code_021abc24.h"

void func_ov000_021abc4c(int param_1, u32 param_2) {
    int uVar1;
    int iVar2;
    func_ov000_021ac37c((u8 *) ((u8 *) (u32) (param_2)), (u32 *) ((u32 *) (u32) (param_1 + 0x14)), (u32) (8));
    uVar1 = *(u32 *) (param_1 + 0x18) >> 3 & 0x3f;
    if (uVar1 < 0x38) {
        iVar2 = 0x38 - uVar1;
    } else {
        iVar2 = 0x78 - uVar1;
    }
    func_ov000_021abca0((int) (param_1), (int) (((u32) ((u32) (&data_ov000_021b4be4)))), (u32) (iVar2));
    func_ov000_021abca0((int) (param_1), (int) (param_2), (u32) (8));
    func_ov000_021ac37c((u8 *) ((u8 *) (u32) (param_2)), (u32 *) ((u32 *) (u32) (param_1)), (u32) (0x14));
    return;
}

void func_ov000_021abc24(u32 param_1, u32 param_2) {
    func_ov000_021abca0((int) (param_1), (int) (((u32) ((u32) (&data_ov000_021b4be5)))), (u32) (0x2c));
    func_ov000_021ac37c((u8 *) ((u8 *) (u32) (param_2)), (u32 *) ((u32 *) (u32) (param_1)), (u32) (0x14));
    return;
}
