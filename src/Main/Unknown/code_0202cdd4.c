#include "Main/Unknown/code_0202cdd4.h"

#pragma thumb on

// non-matching: 0x1c bytes, original 0x20; 10 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_0202cdd4(void) {
    func_02036ab0((void *) (*(u32 *) (*((int *) ((u32) (&data_02174e40))) + 0xdc)));
    *((int *) ((u32) (&data_02174e40))) = 0;
    return;
}

#pragma thumb off
