#include "Main/Unknown/code_02035d90.h"

#pragma thumb on

// non-matching: 0x20 bytes, original 0x24; 10 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_02035d90(void) {
    func_02036ab0((u32) (*(u32 *) (*((int *) ((u32) (&data_02174e6c))) + ((int) 0x00000650u))));
    *((int *) ((u32) (&data_02174e6c))) = 0;
    return;
}

#pragma thumb off
