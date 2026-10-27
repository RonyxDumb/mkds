#include "00/code_021ab6d4.h"

void func_ov000_021ab6d4(int param_1, u32 param_2) {
    int uVar1;
    int iVar2;
    func_ov000_021abc14(param_2, param_1 + 0x10, 8);
    uVar1 = *(u32 *) (param_1 + 0x10) >> 3 & 0x3f;
    if (uVar1 < 0x38) {
        iVar2 = 0x38 - uVar1;
    } else {
        iVar2 = 0x78 - uVar1;
    }
    func_ov000_021ab728((int) (param_1), (int) (((u32) &data_ov000_021b4aa4)), (u32) (iVar2));
    func_ov000_021ab728((int) (param_1), (int) (param_2), (u32) (8));
    func_ov000_021abc14(param_2, param_1, 0x10);
    return;
}
