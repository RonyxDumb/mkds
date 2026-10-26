#include "00/code_021948bc.h"

u32 func_ov000_021948bc(u32 param_1, int param_2, u32 *param_3) {
    int iVar1;
    u32 *puVar2;
    puVar2 = *(u32 **) (param_2 + 0xc);
    if (((puVar2 != (u32 *) 0x0) &&
         (iVar1 = func_0213a074((const u8 *) (*param_3), (const u8 *) (*puVar2)), iVar1 == 0)) &&
        (iVar1 = func_0213a074((const u8 *) (param_3[1]), (const u8 *) (puVar2[2])), iVar1 == 0)) {
        *(int *) param_3[2] = param_2;
        param_3[3] = 1;
        return 0;
    }
    return 1;
}
