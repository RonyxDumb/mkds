#include "01/code_0218ce30.h"

void func_ov001_0218ce30(u32 param_1, int param_2) {
    int iVar1;
    func_ov001_0218dc20((Unk02188950 *) ((int) (param_2)));
    func_ov001_0218dba8((Unk02188950 *) ((int) (param_2)));
    iVar1 =
        func_020d2c2c((u32 *) ((u32 *) (u32) (param_2 + ((int) 0x00000238u))), (u32 *) ((u32 *) (u32) (param_2 + 0x10)),
                      (u32) (*(u32 *) (*(int *) (param_2 + 0xa0) + ((int) 0x00000100u))),
                      (u32) ((int) *(short *) (param_2 + 100)), (u32) (9), (int *) (0));
    if (iVar1 == 2) {
        func_020d2774((int) (param_2), (u32) (((u32) 0x00000253u)));
    }
    func_ov001_021864ac((u32) (param_1), (Unk02188950 *) ((int) (param_2)));
    return;
}
