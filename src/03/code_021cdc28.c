#include "03/code_021cdc28.h"

// non-matching: 0x20 bytes, original 0x24; 9 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021cdc28(void) {
    func_ov003_021d34c8(0, *(u32 *) (*((int *) ((u32) (&data_ov003_021da274))) + 0x98));
    func_ov003_021d2808(((int *) ((u32) (&data_ov003_021da274))));
    return;
}
