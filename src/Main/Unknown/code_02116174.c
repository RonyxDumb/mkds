#include "Main/Unknown/code_02116174.h"

#pragma thumb on

void func_021161d0(void) {
    int iVar1;
    int iVar2;
    iVar2 = (data_0217d350->mUnk_74 + 1) * 0x10000 >> 0x10;
    iVar1 = func_02116844(iVar2);
    if ((iVar1 == 0) || (5 <= iVar2)) {
        iVar2 = 0;
    }
    if (data_0217d350->mUnk_74 != iVar2) {
        func_0212ecc0((const void *) (((u32) ((u8 *) &data_0217d068))), (u32) 0, (u32) 0);
    }
    data_0217d350->mUnk_74 = (short) iVar2;
}

void func_02116174(void) {
    int iVar1;
    u32 uVar2;
    int extraout_r1;
    int iVar3;
    iVar3 = (data_0217d350->mUnk_74 + -1) * 0x10000 >> 0x10;
    if (iVar3 < 0) {
        iVar3 = 4;
        iVar1 = func_02116844(4);
        if (iVar1 == 0) {
            uVar2 = func_021143b4();
            extraout_r1 = (int) (uVar2) % 5;
            iVar3 = (extraout_r1 + -1) * 0x10000 >> 0x10;
        }
    }
    if (data_0217d350->mUnk_74 != iVar3) {
        func_0212ecc0((const void *) &data_0217d068, (u32) 0, (u32) 0);
    }
    data_0217d350->mUnk_74 = (short) iVar3;
}

#pragma thumb off
