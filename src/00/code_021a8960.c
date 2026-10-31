#include "00/code_021a8960.h"

u32 func_ov000_021a8960(int param_1) {
    u32 uVar3;
    int iVar2;
    s8 cVar1;
    iVar2 = *(int *) (param_1 + 100);
    uVar3 = 0;
    if (iVar2 != 0) {
        cVar1 = *(s8 *) (param_1 + 0x73);
        if (cVar1 == 1) {
            if (*(int *) (iVar2 + 0x104) != 0) {
                uVar3 = (u32) * (u16 *) (*(int *) (iVar2 + 0x104) + 4);
            }
        } else if ((cVar1 == 0) || (cVar1 == 4)) {
            uVar3 = *(int *) (param_1 + 0x44) - *(int *) (iVar2 + 0xf8);
        }
    }
    return uVar3;
}
