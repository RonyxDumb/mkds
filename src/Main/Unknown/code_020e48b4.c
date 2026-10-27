#include "Main/Unknown/code_020e48b4.h"

#pragma thumb on

// non-matching: 13 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4, lr}`
void func_020e48b4(void) {
    u32 uVar1;
    uVar1 = (u32) func_020d21ec((const char *) data_0216c20c);
    func_020e6488((u32 *) (((u32 *) ((u32) (&data_0217b7f0)))), (u32) (uVar1), (u32) (0), (u32) (0));
    func_020e6ab8((unsigned int) (*((u32 *) ((u32) (&data_0217b7f0)))));
    return;
}

#pragma thumb off
