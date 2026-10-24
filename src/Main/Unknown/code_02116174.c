#include "Main/Unknown/code_02116174.h"

#pragma thumb on

// non-matching: 16 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push {r4, r5, lr}`
void func_021161d0(void) {
    int iVar1;
    int iVar2;
    iVar2 = (*(short *) (*((int *) ((u32) (&data_0217d350))) + 0x74) + 1) * 0x10000 >> 0x10;
    iVar1 = func_02116844((int) (iVar2));
    if ((iVar1 == 0) || (5 <= iVar2)) {
        iVar2 = 0;
    }
    if (*(short *) (*((int *) ((u32) (&data_0217d350))) + 0x74) != iVar2) {
        func_0212ecc0((const void *) (((u32) (u32) ((unsigned char *) &data_0217d068))), (u32) (0), (u32) (0));
    }
    *(short *) (*((int *) ((u32) (&data_0217d350))) + 0x74) = (short) iVar2;
    return;
}

// non-matching: 17 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push {r4, r5, lr}`
void func_02116174(void) {
    int iVar1;
    u32 uVar2;
    int extraout_r1;
    int iVar3;
    iVar3 = (*(short *) (*((int *) ((u32) (&data_0217d350))) + 0x74) + -1) * 0x10000 >> 0x10;
    if (iVar3 < 0) {
        iVar3 = 4;
        iVar1 = func_02116844((int) (4));
        if (iVar1 == 0) {
            uVar2 = func_021143b4();
            extraout_r1 = (int) (uVar2) % (int) (5);
            iVar3 = (extraout_r1 + -1) * 0x10000 >> 0x10;
        }
    }
    if (*(short *) (*((int *) ((u32) (&data_0217d350))) + 0x74) != iVar3) {
        func_0212ecc0((const void *) (((u32) ((u32) (&data_0217d068)))), (u32) (0), (u32) (0));
    }
    *(short *) (*((int *) ((u32) (&data_0217d350))) + 0x74) = (short) iVar3;
    return;
}

#pragma thumb off
