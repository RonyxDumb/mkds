#include "Main/Unknown/code_02126ea8.h"

#pragma thumb on

// non-matching: 0x78 bytes, original 0x80; 21 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_02126ef8(void) {
    int iVar1;
    iVar1 = *((int *) ((u32) (&data_0217d3f0)));
    if (0 < *(int *) (iVar1 + 0x28)) {
        ((u32) func_02016468((u32) (0x1f), (u32) ((0xee - *(int *) (iVar1 + 0x2c)) * 2),
                             (void *) (iVar1 + ((int) 0x00002246u)), (u32) (2)));
        ((u32) func_02016468((u32) (0x1f), (u32) ((0xfe - *(int *) (*((int *) ((u32) (&data_0217d3f0))) + 0x2c)) * 2),
                             (void *) (*((int *) ((u32) (&data_0217d3f0))) + ((int) 0x00002246u)), (u32) (2)));
        iVar1 = *((int *) ((u32) (&data_0217d3f0)));
        if (*(int *) (iVar1 + 0x28) == 2) {
            ((u32) func_02016468((u32) (0x1f), (u32) ((*(int *) (iVar1 + 0x2c) + 0xed) * 2),
                                 (void *) (iVar1 + ((int) 0x00002244u)), (u32) (2)));
            ((u32) func_02016468((u32) (0x1f),
                                 (u32) ((*(int *) (*((int *) ((u32) (&data_0217d3f0))) + 0x2c) + 0xfd) * 2),
                                 (void *) (*((int *) ((u32) (&data_0217d3f0))) + ((int) 0x00002244u)), (u32) (2)));
        }
    }
    return;
}

// non-matching: register allocation only, 9 instructions; first at +0x4: original `ldr r4, [pc, #0x40] (->0x48)`, ours
// `ldr r5, [pc, #0x40] (->0x48)`
void func_02126ea8(void) {
    int *piVar1;
    int iVar2;
    int iVar3;
    iVar2 = ((int) 0x00002244u);
    piVar1 = ((int *) ((u32) (&data_0217d3f0)));
    if (0 < *(int *) (*((int *) ((u32) (&data_0217d3f0))) + 0x28)) {
        iVar3 = 0;
        do {
            ((u32) func_02016468((u32) (0x1f), (u32) ((iVar3 + 0xed) * 2), (void *) (*piVar1 + iVar2), (u32) (2)));
            ((u32) func_02016468((u32) (0x1f), (u32) ((iVar3 + 0xfd) * 2), (void *) (*piVar1 + iVar2), (u32) (2)));
            iVar3 = iVar3 + 1;
        } while (iVar3 < 2);
    }
    return;
}

#pragma thumb off
