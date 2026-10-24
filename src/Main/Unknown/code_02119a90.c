#include "Main/Unknown/code_02119a90.h"

#pragma thumb on

// non-matching: 6 instructions differ; first at +0x4: original nothing, ours `ldr r2, [pc, #0x28] (->0x30)`
void func_02119a90(void) {
    int *piVar1;
    piVar1 = ((int *) ((u32) (&data_0217d364)));
    *(u32 *) (*((int *) ((u32) (&data_0217d364))) + 0x38) = 6;
    *(u32 *) (*piVar1 + 0x3c) = 0;
    func_0212775c((int) (0), (u32) (7));
    func_0212775c((int) (1), (u32) (0x10));
    func_0212775c((int) (0xffffffff), (u32) (0x10));
    return;
}

#pragma thumb off
