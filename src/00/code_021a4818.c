#include "00/code_021a4818.h"

void func_ov000_021a4818(int param_1) {
    int iVar1;
    if (param_1 == 0) {
        param_1 = *(int *) &data_ov000_021b426c;
    }
    if (*(int *) (param_1 + 0xbc) != 0) {
        iVar1 = func_ov000_0218e8c4();
        if ((u32) (iVar1 - *(int *) (param_1 + 0xac)) < ((u32) 0x00002710u)) {
            *(u32 *) (param_1 + 0xb4) = 1;
            return;
        }
        func_ov000_021a3a18((u32 *) ((u32 *) (u32) (param_1)), (int) (1));
        *(u32 *) (param_1 + 0xb4) = 0;
    }
    return;
}
