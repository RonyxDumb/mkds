#include "00/code_0218d2a8.h"

int func_ov000_0218d300(u32 param_1, int param_2) {
    int iVar1;
    int *piVar2;
    int iVar3;
    iVar1 = func_ov000_0218dc44((u32 *) ((u32 *) (u32) (*(u32 *) (param_1 + 4))));
    iVar3 = 0;
    if (0 < iVar1) {
        do {
            piVar2 = (int *) func_ov000_0218dbf8((int *) ((int *) (u32) (*(u32 *) (param_1 + 4))), (int) (iVar3));
            if (param_2 == *piVar2) {
                return iVar3;
            }
            iVar3 = iVar3 + 1;
        } while (iVar3 < iVar1);
    }
    return -1;
}

int func_ov000_0218d2a8(int param_1, int param_2, int param_3) {
    u32 uVar5;
    int iVar4;
    int iVar3;
    u32 *puVar2;
    int iVar1;
    iVar1 = func_ov000_0218dc44((u32 *) ((u32 *) (u32) (*(u32 *) (4 + param_1))));
    iVar4 = 0;
    if (0 < iVar1) {
        do {
            puVar2 = (u32 *) func_ov000_0218dbf8((int *) ((int *) (u32) (*(u32 *) (param_1 + 4))), (int) (iVar4));
            uVar5 = *puVar2;
            iVar3 = func_ov000_0218b27c((u32 *) ((u32 *) (u32) (uVar5)));
            if ((param_2 == iVar3) && (iVar3 = func_ov000_0218b25c((int) (uVar5)), param_3 == iVar3)) {
                return iVar4;
            }
            iVar4 = iVar4 + 1;
        } while (iVar4 < iVar1);
    }
    return -1;
}
