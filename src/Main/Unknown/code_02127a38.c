#include "Main/Unknown/code_02127a38.h"

#pragma thumb on

void func_02127a38(void) {
    int *piVar1;
    int iVar2;
    piVar1 = (int *) &data_0217d3f4;
    iVar2 = *(int *) &data_0217d3f4;
    if (*(int *) (0x28 + iVar2) != 0) {
        *(u32 *) (iVar2 + 8) = 0;
        *(u32 *) (*piVar1 + 0x28) = 0;
        return;
    }
    *(int *) (iVar2 + 0xc) = *(int *) (iVar2 + 0xc) + 1;
    iVar2 = *(int *) (*piVar1 + 0xc);
    if (15 <= iVar2) {
        *(u32 *) (*piVar1 + 0x1c) = 1;
        *(u32 *) (*piVar1 + 0xc) = 0xf;
        return;
    }
    if (5 <= iVar2) {
        func_02127d74();
    }
}

#pragma thumb off
