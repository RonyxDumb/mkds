#include "Main/Unknown/code_020ada94.h"

#pragma thumb on

// non-matching: 0x38 bytes, original 0x3c; 12 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_020ada94(void) {
    (**(UnkFunc **) (*((int *) ((u32) (&data_0217b340))) + *(int *) (*((int *) ((u32) (&data_0217b340))) + 0xc) * 8 +
                     0x14))();
    *(u32 *) (*((int *) ((u32) (&data_0217b340))) + 4) = 0;
    func_021258f0();
    func_020ae5f0((void *) (*((int *) ((u32) (&data_0217b340))) + 0xb0), (void *) (*((int *) ((u32) (&data_0217b340))) + ((int) 0x000004b4u)));
    return;
}

#pragma thumb off
