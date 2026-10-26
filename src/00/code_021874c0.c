#include "00/code_021874c0.h"

// non-matching: 7 instructions differ; first at +0x2: original `ldr r0, [pc, #0x20] (->0x24)`, ours `ldr r4, [pc,
// #0x20] (->0x24)`
u32 func_ov000_021874c0(void) {
    u32 uVar1;
    func_0200ed34((void *) (*((int *) ((u32) (&data_ov000_021b4cb0))) + ((int) 0x000001dcu)));
    uVar1 = *(u32 *) *((int *) ((u32) (&data_ov000_021b4cb0)));
    func_0200ecc4((void *) (*((int *) ((u32) (&data_ov000_021b4cb0))) + ((int) 0x000001dcu)));
    return uVar1;
}
