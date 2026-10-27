#include "Main/Unknown/code_020e2fac.h"

#pragma thumb on

// non-matching: 0x3c bytes, original 0x38; 10 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push
// {r4, r5, lr}`
void func_020e2fac(void) {
    u32 uVar1;
    u32 uVar2;
    uVar1 = (u32) func_020d21ec((const char *) data_0216c128);
    uVar2 = (u32) func_020d21ec((const char *) data_0216c138);
    func_020e6488((u32 *) (((u32 *) ((u32) (&data_0217b7b8)))), (u32) (uVar1), (u32) (uVar2), (u32) (0));
    func_020e6ab8((unsigned int) (*((u32 *) ((u32) (&data_0217b7b8)))));
    return;
}

#pragma thumb off
