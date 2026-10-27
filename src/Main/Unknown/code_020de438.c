#include "Main/Unknown/code_020de438.h"

#pragma thumb on

// non-matching: 17 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4, r5, lr}`
void func_020de438(void) {
    u32 uVar1;
    uVar1 = (u32) func_020d21ec((const char *) data_0216bf7c);
    func_020e6488((u32 *) (((u32 *) ((u32) (&data_0217b6f0)))), (u32) (uVar1), (u32) (0), (u32) (0));
    uVar1 = (u32) func_020d21ec((const char *) data_0216bf90);
    func_020e6488((u32 *) (((u32 *) ((u32) (&data_0217b6f4)))), (u32) (uVar1), (u32) (0), (u32) (0));
    func_020e6ab8((unsigned int) (*((u32 *) ((u32) (&data_0217b6f0)))));
    func_020e6ab8((unsigned int) (*((u32 *) ((u32) (&data_0217b6f4)))));
    return;
}

#pragma thumb off
