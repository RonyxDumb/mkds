#include "Main/Unknown/code_02119a90.h"

#pragma thumb on

void func_02119a90(void) {
    int *piVar1;
    piVar1 = (int *) &data_0217d364;
    *(u32 *) ((*(int *) &data_0217d364) + 0x38) = 6;
    *(u32 *) (*piVar1 + 0x3c) = 0;
    func_0212775c((int) (0), (u32) (7));
    func_0212775c((int) (1), (u32) (0x10));
    func_0212775c((int) (0xffffffff), (u32) (0x10));
    return;
}

#pragma thumb off
