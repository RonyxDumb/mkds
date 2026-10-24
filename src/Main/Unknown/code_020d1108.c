#include "Main/Unknown/code_020d1108.h"

#pragma thumb on

void func_020d1108(void) {
    int iVar1;
    u32 uVar2;
    iVar1 = func_020d1158();
    if (iVar1 == 0) {
        uVar2 = func_020d113c();
        iVar1 = ((u32) func_02036bec((void *) (uVar2), (u32) (((u32) 0x0000185cu))));
        *((int *) ((u32) (&data_0217b4a4))) = iVar1;
        *(u32 *) (iVar1 + 0xc) = 0;
        func_020d0efc((int) (0x14));
    }
    return;
}

#pragma thumb off
