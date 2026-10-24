#include "Main/Unknown/code_020ab848.h"

#pragma thumb on

// non-matching: 2 instructions differ; first at +0x10: original `ldr r2, [r5, #0x0]`, ours `ldr r0, [pc, #0x60]
// (->0x74)`
void func_020ab848(int *param_1, int *param_2, int *param_3, int *param_4) {
    int *piVar1;
    int iVar2;
    func_020ab11c();
    piVar1 = ((int *) ((u32) (&data_0217b334)));
    *param_1 = *param_1 - *(int *) (*((int *) ((u32) (&data_0217b334))) + 0x50);
    *param_2 = *param_2 - *(int *) (*piVar1 + 0x54);
    *param_3 = *param_3 - *(int *) (*piVar1 + 0x50);
    *param_4 = *param_4 - *(int *) (*piVar1 + 0x54);
    iVar2 = *param_1;
    if (iVar2 < 0) {
        iVar2 = iVar2 + ((int) 0x00000100u);
    }
    *param_1 = iVar2;
    iVar2 = *param_2;
    if (iVar2 < 0) {
        iVar2 = iVar2 + ((int) 0x00000100u);
    }
    *param_2 = iVar2;
    iVar2 = *param_3;
    if (iVar2 < 0) {
        iVar2 = iVar2 + ((int) 0x00000100u);
    }
    *param_3 = iVar2;
    iVar2 = *param_4;
    if (iVar2 < 0) {
        iVar2 = iVar2 + ((int) 0x00000100u);
    }
    *param_4 = iVar2;
    return;
}

#pragma thumb off
