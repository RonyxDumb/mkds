#include "00/code_02193e70.h"

int func_ov000_02193e70(u32 param_1, u32 *param_2) {
    int iVar1;
    int local_14[2];
    iVar1 = func_ov000_021938cc((int *) ((int *) (u32) (param_1)), (int) (2), (int) (0), (int *) (local_14), (int) (0),
                                (int) (0), (int) (0));
    if ((iVar1 == 0) && (iVar1 = func_ov000_02192330((int *) ((int *) (u32) (param_1)), (u32) (param_2[3]),
                                                     (u32) (*(u32 *) (local_14[0] + 0x18))),
                         iVar1 == 0)) {
        *param_2 = 0x65;
        iVar1 = 0;
    }
    return iVar1;
}
