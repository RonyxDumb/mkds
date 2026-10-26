#include "Main/Unknown/code_02033d9c.h"

#pragma thumb on

// non-matching: 0x38 bytes, original 0x34; 9 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push
// {r4, r5, lr}`
void func_02033d9c(void) {
    u32 uVar1;
    u32 uVar2;
    uVar1 = ((int) func_020b3f7c((void *) (*(u32 *) (*((int *) ((u32) (&data_02174e60))) + 200)), (s32) (0x5d)));
    uVar2 = ((int) func_020b3f7c((void *) (*(u32 *) (*((int *) ((u32) (&data_02174e60))) + 200)), (s32) (0x5f)));
    func_021277f8((void *) (uVar1), (void *) (uVar2), (int) (0));
    return;
}

#pragma thumb off
