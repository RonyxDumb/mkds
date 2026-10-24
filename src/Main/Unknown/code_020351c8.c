#include "Main/Unknown/code_020351c8.h"

#pragma thumb on

// non-matching: 0x5c bytes, original 0x60; 10 instructions differ; first at +0x4: original `ldr r0, [pc, #0x54]
// (->0x5c)`, ours `ldr r4, [pc, #0x50] (->0x58)`
void func_020351c8(void) {
    u32 uVar1;
    u32 uVar2;
    u32 uVar3;
    uVar1 = ((int) func_020b3f7c((void *) (*(u32 *) (*((int *) ((u32) (&data_02174e64))) + 0x88)), (s32) (8)));
    uVar2 = ((int) func_020b3f7c((void *) (*(u32 *) (*((int *) ((u32) (&data_02174e64))) + 0x84)), (s32) (0)));
    uVar3 = ((int) func_020b3f7c((void *) (*(u32 *) (*((int *) ((u32) (&data_02174e64))) + 0x84)), (s32) (1)));
    func_02125ed0((int) (0), (u32) (5));
    func_02125fd4((u32) (uVar1), (u32) (uVar2), (u32) (uVar3), (u32) (0), (u32) (0), (u32) (1), (u32) (1), (u32) (0));
    return;
}

#pragma thumb off
