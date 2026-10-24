#include "Main/Unknown/code_020075f8.h"

#pragma thumb on

// non-matching: 10 instructions differ; first at +0x0: original `push {r4, lr}`, ours `push {r4, r5, lr}`
void func_020075f8(u8 param_1, u32 param_2) {
    u8 local_10[8];
    local_10[0] = param_1;
    func_0200c3a4((u8 *) (local_10), (u8 *) ((u8 *) (u32) (*((u32 *) ((u32) (&data_0216fdac))))));
    func_02008908((int) (6), (u32) (param_2), (u32) (*((u32 *) ((u32) (&data_0216fdac)))));
    return;
}

#pragma thumb off
