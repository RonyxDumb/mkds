#include "Main/Unknown/code_0202a90c.h"

#pragma thumb on

// non-matching: 0x1c bytes, original 0x20; 10 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_0202a90c(void) {
    func_02036ab0((u32) (*(u32 *) (*((int *) ((u32) (&data_02174e28))) + 0x90)));
    *((int *) ((u32) (&data_02174e28))) = 0;
    return;
}

#pragma thumb off
