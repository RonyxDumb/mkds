#include "00/code_0219d478.h"

// non-matching: 0x20 bytes, original 0x24; 10 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov000_0219d478(void) {
    if (*((int *) ((u32) (&data_ov000_021b5664))) != 0) {
        func_ov000_02197634();
        *(u32 *) *((int *) ((u32) (&data_ov000_021b5664))) = 0;
    }
    return;
}
