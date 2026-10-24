#include "Main/Unknown/code_0202b6a0.h"

#pragma thumb on

// non-matching: 0x48 bytes, original 0x50; 16 instructions differ; first at +0x0: original `push {r4, r5, lr}`, ours
// `push {r4, r5, r6, lr}`
void func_0202b6a0(int param_1, int param_2) {
    u32 uVar1;
    if ((*(int *) (*((int *) ((u32) (&data_02174e3c))) + ((int) 0x00000204u)) != 0) &&
        (param_2 != *(int *) (*((int *) ((u32) (&data_02174e3c))) + param_1 * 0x2c + 0x4c))) {
        if (param_2 == 1) {
            uVar1 = 2;
        } else {
            uVar1 = 1;
        }
        func_0202cc18((int) (param_1), (int) (uVar1));
    }
    *(int *) (*((int *) ((u32) (&data_02174e3c))) + param_1 * 0x2c + 0x4c) = param_2;
    return;
}

#pragma thumb off
