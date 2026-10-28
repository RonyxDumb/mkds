#include "Main/Unknown/code_0202cbf4.h"

#pragma thumb on

// non-matching: 5 instructions differ; first at +0x4: original nothing, ours `ldr r2, [pc, #0x28] (->0x30)`
void func_0202cc44(int param_1, u32 param_2) {
    int *piVar1;
    piVar1 = (int *) &data_02174e3c;
    param_1 = param_1 * 0x2c;
    *(u32 *) ((*(int *) &data_02174e3c) + param_1 + 0x50) = 10;
    *(u32 *) (*piVar1 + param_1 + 0x5c) = param_2;
    *(u32 *) (*piVar1 + param_1 + 0x54) = *(u32 *) (*piVar1 + param_1 + 0x5c);
    *(u32 *) (*piVar1 + param_1 + 0x58) = *(u32 *) (*piVar1 + param_1 + 0x54);
    return;
}

void func_0202cc18(int param_1, int param_2) {
    int *piVar1;
    piVar1 = (int *) ((*(int *) &data_02174e3c) + 0x50 + param_1 * 0x2c);
    piVar1[1] = param_2;
    if (piVar1[1] == piVar1[2]) {
        piVar1[2] = piVar1[3];
        piVar1[3] = piVar1[1];
        *piVar1 = 10 - *piVar1;
    }
    return;
}

void func_0202cbf4(void) {
    int iVar1;
    iVar1 = 0;
    do {
        func_0202cc44((int) (iVar1), (u32) (0));
        func_0202cc18((int) (iVar1), (int) (1));
        iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    return;
}

#pragma thumb off
