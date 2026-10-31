#include "00/code_02193e70.h"

int func_ov000_02193e70(Unk0218f960 *param_1, Unk02193f2cNode *param_2) {
    int iVar1;
    int local_14[2];
    iVar1 = func_ov000_021938cc((int *) ((int *) (u32) (param_1)), 2, 0, (int *) (local_14), 0,
                                0, 0);
    if ((iVar1 == 0) && (iVar1 = func_ov000_02192330((Unk021919ac *) (u32) (param_1), (u32) (param_2->mUnk_0c),
                                                     (u32) (*(u32 *) (local_14[0] + 0x18))),
                         iVar1 == 0)) {
        param_2->mUnk_00 = 0x65;
        iVar1 = 0;
    }
    return iVar1;
}
