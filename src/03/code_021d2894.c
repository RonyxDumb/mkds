#include "03/code_021d2894.h"

// non-matching: 0x18 bytes, original 0x1c; 10 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
void func_ov003_021d2894(void) {
    unsigned int v2 = ((u32) (&data_ov003_021da2c8));
    unsigned int v3 = ((unsigned int) *(unsigned int *) ((v2) + (0)));
    unsigned int v4 = func_0201797c((unsigned int) (v3));
    unsigned int v6 = ((u32) (&data_ov003_021da2c8));
    *(unsigned int *) ((v6) + (0)) = (unsigned int) (0x0u);
}
