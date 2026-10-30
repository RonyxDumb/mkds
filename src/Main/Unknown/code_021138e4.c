#include "Main/Unknown/code_021138e4.h"

#pragma thumb on

void func_02113940(void) {
    int iVar1;
    int iVar2;
    iVar2 = (data_0217d348->mUnk_68 + 1) * 0x10000 >> 0x10;
    iVar1 = func_02113ef0((int) iVar2);
    if ((iVar1 == 0) || (5 <= iVar2)) {
        iVar2 = 0;
    }
    if (data_0217d348->mUnk_68 != iVar2) {
        func_0212ecc0((const void *) (((u32) (u32) ((unsigned char *) &data_0217d068))), (u32) 0, (u32) 0);
    }
    data_0217d348->mUnk_68 = (short) iVar2;
}

void func_021138e4(void) {
    int iVar1;
    u32 uVar2;
    int extraout_r1;
    int iVar3;
    iVar3 = (data_0217d348->mUnk_68 + -1) * 0x10000 >> 0x10;
    if (iVar3 < 0) {
        iVar3 = 4;
        iVar1 = func_02113ef0((int) 4);
        if (iVar1 == 0) {
            uVar2 = func_021143b4();
            extraout_r1 = (int) (uVar2) % (int) 5;
            iVar3 = (extraout_r1 + -1) * 0x10000 >> 0x10;
        }
    }
    if (data_0217d348->mUnk_68 != iVar3) {
        func_0212ecc0((const void *) &data_0217d068, (u32) 0, (u32) 0);
    }
    data_0217d348->mUnk_68 = (short) iVar3;
}

#pragma thumb off
