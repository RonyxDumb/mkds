#include "Main/Unknown/code_021144c0.h"

#pragma thumb on

// non-matching: 0x40 bytes, original 0x44; 16 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push
// {r4, r5, lr}`
void func_021144c0(u32 param_1) {
    int iVar1;
    u32 uVar2;
    iVar1 = ((u32) func_02036bec((void *) (param_1), (u32) (0x10)));
    *((int *) ((u32) (&data_0217d34c))) = iVar1;
    uVar2 = ((u32) func_02036bec((void *) (param_1), (u32) (0x78)));
    *(u32 *) (*((int *) ((u32) (&data_0217d34c))) + 4) = uVar2;
    uVar2 = func_0205eda0((u32) (param_1));
    *(u32 *) (*((int *) ((u32) (&data_0217d34c))) + 8) = uVar2;
    uVar2 = ((int) func_0204799c((const char *) (((u32) ((u32) (&data_0216d3e4))))));
    *(u32 *) (*((int *) ((u32) (&data_0217d34c))) + 0xc) = uVar2;
    return;
}

#pragma thumb off
