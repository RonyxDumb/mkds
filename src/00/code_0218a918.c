#include "00/code_0218a918.h"

void func_ov000_0218a98c(u32 param_1) {
    u32 uVar1;
    while ((*(int *) (param_1 + 0x10) < *(int *) (param_1 + 4) && (0 < *(int *) (param_1 + 0x1c)))) {
        uVar1 = func_ov000_0218aea4((int *) ((int *) (u32) (param_1 + 0x14)));
        func_ov000_0218ad44((int *) ((int *) (u32) (param_1)), (int *) ((int *) (u32) (uVar1)));
    }
    return;
}

void func_ov000_0218a950(int param_1) {
    if (*(int *) (param_1 + 0x10) != 0) {
        func_ov000_0218aa14((int *) ((int *) (u32) (param_1)), (int) (0));
        func_ov000_0218a9bc((int) (param_1));
        if (0 < *(int *) (param_1 + 0x1c)) {
            func_ov000_0218a98c((u32) (param_1));
        }
        if (*(int *) (param_1 + 0x10) == 0) {
            (**(UnkFunc **) (param_1 + 0x44))(param_1, 2, 0, *(u32 *) (param_1 + 0x48));
        }
    }
    return;
}

void func_ov000_0218a93c(u32 param_1, u8 param_2) {
    int iVar1;
    iVar1 = *(int *) (param_1 + 0x40);
    if (iVar1 < 0x14) {
        *(int *) (param_1 + 0x40) = iVar1 + 1;
        *(u8 *) (param_1 + iVar1 + 0x2c) = param_2;
    }
    return;
}

void func_ov000_0218a918(int param_1, u32 param_2) {
    int iVar1;
    iVar1 = func_ov000_0218ae68(param_1 + 8);
    if (iVar1 == 0) {
        func_ov000_0218ae68((int *) (u32) (param_1 + 0x14), param_2);
    }
    return;
}
