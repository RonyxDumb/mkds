#include "Main/Unknown/code_02057260.h"

#pragma thumb on

// non-matching: 0x30 bytes, original 0x34; 9 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_02057260(void) {
    func_0214d168((void *) ((u32 *) (u32) (*(u32 *) (*((int *) ((u32) (&data_0217aa08))) + 0x14))), (u8) (0),
                  (u32) (((u32) 0x00000e00u)));
    func_0214d168((void *) ((u32 *) (u32) (*(u32 *) (*((int *) ((u32) (&data_0217aa08))) + 0x18))), (u8) (0),
                  (u32) (((u32) 0x00001000u)));
    return;
}

#pragma thumb off
