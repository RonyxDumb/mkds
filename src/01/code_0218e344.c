#include "01/code_0218e344.h"

void func_ov001_0218e344(int param_1) {
    int iVar1;
    iVar1 = func_ov001_021871f8((Unk02188950 *) ((int) (param_1)), (int) (5));
    if (iVar1 != 0) {
        func_ov001_0218edc8((Unk02188950 *) ((int) (param_1)));
    }
    *(u32 *) (param_1 + ((int) 0x000002d8u)) = 0xd;
    func_ov001_02188200((Unk02188950 *) ((int) (param_1)), (UnkFunc *) ((u32) (((u32) ((u32) (&func_ov001_0218e344))))));
    if (*(int *) (param_1 + ((int) 0x000002d0u)) == 0) {
        func_020d2774((int) (param_1), (u32) (((u32) 0x00000234u)));
    }
    return;
}
