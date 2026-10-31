#include "Main/Unknown/code_02126ea8.h"

#pragma thumb on

void func_02126ef8(void) {
    int iVar1;
    iVar1 = *(int *) &data_0217d3f0;
    if (0 < *(int *) (iVar1 + 0x28)) {
        ((u32) func_02016468((u32) 0x1f, (u32) ((0xee - *(int *) (iVar1 + 0x2c)) * 2),
                             (void *) (iVar1 + 0x2246), (u32) 2));
        ((u32) func_02016468((u32) 0x1f, (u32) ((0xfe - *(int *) ((*(int *) &data_0217d3f0) + 0x2c)) * 2),
                             (void *) ((*(int *) &data_0217d3f0) + 0x2246), (u32) 2));
        iVar1 = *(int *) &data_0217d3f0;
        if (*(int *) (iVar1 + 0x28) == 2) {
            ((u32) func_02016468((u32) 0x1f, (u32) ((*(int *) (iVar1 + 0x2c) + 0xed) * 2),
                                 (void *) (iVar1 + 0x2244), (u32) 2));
            ((u32) func_02016468((u32) 0x1f, (u32) ((*(int *) ((*(int *) &data_0217d3f0) + 0x2c) + 0xfd) * 2),
                                 (void *) ((*(int *) &data_0217d3f0) + 0x2244), (u32) 2));
        }
    }
}

void func_02126ea8(void) {
    int iVar2;
    int iVar3;
    iVar2 = 0x2244;
    if (0 < *(int *) ((*(int *) &data_0217d3f0) + 0x28)) {
        iVar3 = 0;
        do {
            ((u32) func_02016468((u32) 0x1f, (u32) ((iVar3 + 0xed) * 2), (void *) (*(int *) &data_0217d3f0 + iVar2),
                                 (u32) 2));
            ((u32) func_02016468((u32) 0x1f, (u32) ((iVar3 + 0xfd) * 2), (void *) (*(int *) &data_0217d3f0 + iVar2),
                                 (u32) 2));
            iVar3 = iVar3 + 1;
        } while (iVar3 < 2);
    }
}

#pragma thumb off
