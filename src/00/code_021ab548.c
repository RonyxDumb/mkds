#include "00/code_021ab548.h"

void func_ov000_021ab594(u32 param_1, u32 param_2) {
    int iVar1;
    iVar1 = *(int *) (*(int *) (((int) (u32) ((u8 *) &data_0216ff5c)) + 4) + 0xa4);
    if ((iVar1 != 0) && (iVar1 = *(int *) (iVar1 + 0xc), iVar1 != 0)) {
        *(u32 *) (iVar1 + 0x7e8) = param_1;
        *(u32 *) (iVar1 + 0x7ec) = param_2;
    }
}

u32 func_ov000_021ab548(int param_1, u32 param_2) {
    int iVar5;
    int iVar4;
    u32 *puVar3;
    u32 *puVar2;
    int iVar1;
    iVar4 = 0;
    iVar5 = *(int *) (param_1 + 0x7ec);
    if (0 < iVar5) {
        puVar2 = *(u32 **) (param_1 + 0x7e8);
        puVar3 = puVar2;
        do {
            iVar1 = func_0213a074((const u8 *) (*(u32 *) *puVar3), (const u8 *) param_2);
            if (iVar1 == 0) {
                return puVar2[iVar4];
            }
            puVar3 = puVar3 + 1;
            iVar4 = iVar4 + 1;
        } while (iVar4 < iVar5);
    }
    return 0;
}
