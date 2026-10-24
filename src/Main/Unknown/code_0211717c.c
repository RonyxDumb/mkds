#include "Main/Unknown/code_0211717c.h"

#pragma thumb on

// non-matching: 0x28 bytes, original 0x24; 11 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push
// {r4, r5, lr}`
void func_0211717c(u32 param_1) {
    u32 uVar1;
    uVar1 = ((u32) func_02036bec((void *) (param_1), (u32) (4)));
    *((u32 *) ((u32) (&data_0217d358))) = uVar1;
    uVar1 = func_0203bedc((u32) (param_1));
    *(u32 *) *((u32 *) ((u32) (&data_0217d358))) = uVar1;
    return;
}

#pragma thumb off
