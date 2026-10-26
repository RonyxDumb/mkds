#include "Main/Unknown/code_0203434c.h"

#pragma thumb on

// non-matching: 0x20 bytes, original 0x24; 10 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_0203434c(void) {
    func_02036ab0((void *) (*(u32 *) (*((int *) ((u32) (&data_02174e64))) + ((int) 0x000001a4u))));
    *((int *) ((u32) (&data_02174e64))) = 0;
    return;
}

#pragma thumb off
