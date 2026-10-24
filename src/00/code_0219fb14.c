#include "00/code_0219fb14.h"

// non-matching: 10 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4, lr}`
unsigned int func_ov000_0219fb14(unsigned int p0) {
    unsigned int v2 = ((p0) + (0x0u));
    unsigned int v3 = ((u32) (&data_ov000_021b566c));
    unsigned int v4 = ((unsigned int) *(unsigned int *) ((v3) + (0)));
    unsigned int v9 = ((unsigned int) *(unsigned int *) ((v4) + (36)));
    unsigned int v10 = ((v4) + (0xa4u));
    unsigned int v11 = ((unsigned int) *(unsigned short *) ((v10) + (0)));
    unsigned int v12 = func_ov000_021a0ae8((unsigned int) (0x5u), (unsigned int) (v2), (unsigned int) (v9),
                                           (unsigned int) (v11), (unsigned int) (0x0u), (unsigned int) (0x0u));
    unsigned int v14 = ((u32) (&data_ov000_021b566c));
    unsigned int v15 = ((unsigned int) *(unsigned int *) ((v14) + (0)));
    unsigned int v16 = 0x1ecu;
    *(unsigned int *) ((v15) + (0 + (v16))) = (unsigned int) (0x0u);
    return v12;
}
