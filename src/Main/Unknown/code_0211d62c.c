#include "Main/Unknown/code_0211d62c.h"

#pragma thumb on

unsigned short func_0211d62c(void) {
    int iVar1;
    iVar1 = *((int *) ((u32) (&data_0217d368)));
    if (*(int *) (iVar1 + 0x6c) == 0) {
        return 0;
    }
    return *(unsigned short *) (iVar1 + 0xb0) + *(unsigned short *) (iVar1 + 0xb2);
}

#pragma thumb off
