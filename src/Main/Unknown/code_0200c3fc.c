#include "Main/Unknown/code_0200c3fc.h"

#pragma thumb on

// non-matching: 0x38 bytes, original 0x34; 14 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push
// {r4, r5, lr}`
void func_0200c3fc(short param_1) {
    if (*((int *) ((u32) (&data_0216fdf4))) != 0) {
        func_0214d168((void *) ((u32 *) (u32) (*((int *) ((u32) (&data_0216fdf4))) + (param_1 + -1) * 0x20)), (u8) (0),
                      (u32) (0x1e));
        *(u32 *) (*((int *) ((u32) (&data_0216fdf4))) + (param_1 + -1) * 4 + ((int) 0x000001e0u)) = 0;
    }
    return;
}

#pragma thumb off
