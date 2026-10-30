#include "Main/Unknown/code_02031208.h"

#pragma thumb on

u32 func_02031268(void) {
    if (*(int *) ((*(int *) &data_02174e58) + 0xc0) == 1) {
        return 1;
    }
    return 0;
}

u32 func_02031250(void) {
    if (*(int *) ((*(int *) &data_02174e58) + 0xc0) == 3) {
        return 1;
    }
    return 0;
}

void func_02031208(void) {
    int iVar5;
    int iVar4;
    int iVar3;
    int iVar2;
    int *piVar1;
    piVar1 = (int *) &data_02174e58;
    if (*(int *) (0x94 + (*(int *) &data_02174e58)) != 6) {
        iVar5 = 0;
        iVar4 = 0;
        iVar3 = 0;
        do {
            iVar2 = *piVar1 + 0x24 + iVar4;
            func_02124c30((void *) (*(u32 *) (iVar2 + 0xc)), (void *) (*(u32 *) (iVar2 + 8)),
                          (void *) (*(u32 *) (iVar2 + 0x14)), (void *) (*(u32 *) (*piVar1 + iVar3 + 0x5c)),
                          (void *) (*(u32 *) (iVar2 + 0x18)));
            iVar4 = iVar4 + 0x1c;
            iVar3 = iVar3 + 4;
            iVar5 = iVar5 + 1;
        } while (iVar5 < 2);
    }
}

#pragma thumb off
