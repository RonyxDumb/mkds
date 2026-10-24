#include "00/code_0218e2c0.h"

// non-matching: 0x18 bytes, original 0x1c; 9 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov000_0218e2c0(void) {
    u32 uVar1;
    uVar1 = func_ov000_0218e2dc((u32) (*((u32 *) ((u32) (&data_ov000_021b23ac)))));
    *((u32 *) ((u32) (&data_ov000_021b23ac))) = uVar1;
    return;
}
