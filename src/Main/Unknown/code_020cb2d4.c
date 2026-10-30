#include "Main/Unknown/code_020cb2d4.h"

#pragma thumb on

void func_020cb2d4(void) {
    int iVar1;
    func_020cb340();
    iVar1 = *(int *) &data_0217b43c;
    func_02124c30((void *) (*(u32 *) (iVar1 + 0x940)), (void *) (*(u32 *) (iVar1 + 0x918)),
                  (void *) 0, (void *) (iVar1 + 0x108),
                  (void *) (*(u32 *) (iVar1 + 0x93c)));
    iVar1 = *(int *) &data_0217b43c;
    func_02124c30((void *) (*(u32 *) (iVar1 + 0x94c)), (void *) (*(u32 *) (iVar1 + 0x928)),
                  (void *) 0, (void *) (iVar1 + 0x50c),
                  (void *) (*(u32 *) (iVar1 + 0x948)));
}

#pragma thumb off
