#include "Main/Unknown/code_0202d82c.h"

#pragma thumb on

// non-matching: 10 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push {r4, r5, lr}`
void func_0202d82c(void) {
    u32 uVar1;
    u32 uVar2;
    uVar1 = ((int) func_020b3f7c((void *) (*(u32 *) (*((int *) ((u32) (&data_02174e40))) + 0xac)), (s32) (0xd)));
    uVar2 = ((int) func_020b3f7c((void *) (*(u32 *) (*((int *) ((u32) (&data_02174e40))) + 0xa8)), (s32) (4)));
    *(u32 *) (*((int *) ((u32) (&data_02174e40))) + 0xb0) = 8;
    func_02126230((unsigned int) (uVar1), (unsigned int) (uVar2));
    return;
}

#pragma thumb off
