#include "Main/Unknown/code_02151718.h"

#pragma thumb on

u32 func_02151830(u16 *param_1) {
    int iVar1;
    iVar1 = func_0215122c((u32) (0x20), (u32) (0x20), (u32) ((u32) (u32) (param_1)));
    if (iVar1 == 0) {
        return 0;
    }
    *((int *) ((u32) (&data_0218049c))) = (u32) *param_1 * 8 - ((int) 0x00000400u);
    return 1;
}

u32 func_02151804(u32 param_1) {
    int iVar1;
    iVar1 = func_0215122c((u32) (*((u32 *) ((u32) (&data_0218049c)))), (u32) (((u32) 0x00000400u)), (u32) (param_1));
    if (iVar1 != 0) {
        return 1;
    }
    return 0;
}

u32 func_02151794(int param_1, int *param_2, u32 param_3) {
    int iVar1;
    int iVar2;
    int iVar3;
    int *local_20;
    int local_1c;
    iVar2 = ((int) 0x00000100u);
    iVar3 = *((int *) ((u32) (&data_0218049c)));
    local_1c = 0;
    local_20 = param_2;
    do {
        if (*local_20 != 0) {
            do {
                func_021511d8(iVar3, iVar2, param_1);
                iVar1 = func_0215119c(param_1, iVar3, iVar2, param_3);
            } while (iVar1 == 0);
        }
        local_20 = local_20 + 1;
        param_1 = param_1 + iVar2;
        local_1c = local_1c + 1;
        iVar3 = iVar3 + iVar2;
    } while (local_1c < 4);
    iVar2 = func_02151154();
    if (iVar2 != 0) {
        return 1;
    }
    return 0;
}

u32 func_02151718(int param_1) {
    int local_18;
    int iVar5;
    int iVar4;
    int iVar3;
    int iVar2;
    u16 uVar1;
    iVar3 = ((int) 0x00000100u);
    iVar5 = *((int *) ((u32) (&data_0218049c)));
    local_18 = 0;
    iVar4 = param_1;
    do {
        uVar1 = func_020205e8(param_1 + ((int) 0x00000500u), iVar4, 0xfe);
        *(u16 *) (iVar4 + 0xfe) = uVar1;
        do {
            func_021511d8(iVar5, iVar3, iVar4);
            iVar2 = func_0215119c(iVar4, iVar5, iVar3, param_1 + ((int) 0x00000400u));
        } while (iVar2 == 0);
        iVar4 = iVar4 + iVar3;
        local_18 = local_18 + 1;
        iVar5 = iVar5 + iVar3;
    } while (local_18 < 4);
    iVar3 = func_02151154();
    if (iVar3 != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off
