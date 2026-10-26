#include "Main/Unknown/code_020303c4.h"

#pragma thumb on

// non-matching: 0x20 bytes, original 0x24; 10 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_020303c4(void) {
    func_0204f7f4();
    func_02036ab0((void *) (*(u32 *) (*((int *) ((u32) (&data_02174e54))) + 0x3c)));
    *((int *) ((u32) (&data_02174e54))) = 0;
    return;
}

#pragma thumb off
