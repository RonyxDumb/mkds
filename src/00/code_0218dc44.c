#include "00/code_0218dc44.h"

void func_ov000_0218dc48(int *param_1) {
    int iVar1;
    if (param_1 == (int *) 0x0) {
        func_0213442c((u32) (((u32) ((u32) (&data_ov000_021b2334)))), (u32) (((u32) ((u32) (&data_ov000_021b22dc)))),
                      (u32) (0), (u32) (0x69));
    }
    iVar1 = 0;
    if (0 < *param_1) {
        do {
            func_ov000_0218dd74(param_1, iVar1);
            iVar1 = iVar1 + 1;
        } while (iVar1 < *param_1);
    }
    func_ov000_021a3668((u32) (param_1[5]));
    func_ov000_021a3668((u32) ((u32) (u32) (param_1)));
    return;
}

u32 func_ov000_0218dc44(u32 *param_1) {
    return *param_1;
}
