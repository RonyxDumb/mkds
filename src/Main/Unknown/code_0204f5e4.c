#include "Main/Unknown/code_0204f5e4.h"

#pragma thumb on

void func_0204f5e4(void) {
    int iVar5;
    int iVar4;
    int iVar3;
    u32 uVar2;
    u32 uVar1;
    uVar2 = ((int) 0xe0000000u);
    uVar1 = ((u32) 0xdfffffffu);
    iVar4 = (*(int *) &data_0217aa00) + ((int) 0x000016a0u);
    iVar5 = 0;
    iVar3 = iVar4;
    do {
        *(u8 *) (iVar3 + 0x34) = 0;
        *(u32 *) (iVar3 + 0x74) = 0;
        *(u32 *) (iVar3 + 0x78) = 0;
        *(u32 *) (iVar3 + 0x84) = *(u32 *) (iVar3 + 0x84) & uVar1;
        *(u32 *) (iVar3 + 0x84) = *(u32 *) (iVar3 + 0x84) & uVar2;
        iVar3 = iVar3 + 0x88;
        iVar5 = iVar5 + 1;
    } while (iVar5 < 0xc);
    *(u16 *) (iVar4 + ((int) 0x00000668u)) = 0xc;
    return;
}

#pragma thumb off
