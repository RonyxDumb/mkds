#include "Main/Unknown/code_020ccb78.h"

#pragma thumb on

void func_020ccb78(void) {
    u8 bVar1;
    u32 *puVar2;
    int iVar3;
    puVar2 = (u32 *) ((u32) func_02029930());
    iVar3 = ((u32) func_02029930());
    func_020468b0((int) 0, (u32) (*puVar2), (u32) (*(u32 *) (iVar3 + 4)), (int) 0, (u32) 0xffffffff, (int) 3);
    bVar1 = 1;
    do {
        func_020ccb48((u32) bVar1);
        bVar1 = bVar1 + 1;
    } while (bVar1 < 8);
}

#pragma thumb off
