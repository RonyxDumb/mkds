#include "00/code_021a7bc8.h"

void func_ov000_021a7bc8(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4) {
    unsigned int v2 = ((p0) + (0x0u));
    unsigned int v3 = ((p1) + (0x0u));
    unsigned int v4 = ((p2) + (0x0u));
    unsigned int v5 = ((p3) + (0x0u));
    unsigned int v6 = ((u32) (&func_ov000_021a7af0));
    unsigned int v7 = ((v2) + (0x0u));
    unsigned int v9 = ((unsigned int) func_ov000_021a7064((u32) (v6), (int) (v7), (u32) (0x1u)));
    unsigned int v10 = ((v9) + (0x0u));
    unsigned int v14;
    unsigned int v16;
    unsigned int v17;
    *(unsigned int *) ((v10) + (16)) = (unsigned int) (v3);
    *(unsigned int *) ((v10) + (20)) = (unsigned int) (v4);
    *(unsigned int *) ((v10) + (24)) = (unsigned int) (v5);
    v14 = p4;
    *(unsigned int *) ((v10) + (28)) = (unsigned int) (v14);
    v16 = ((v2) + (0x0u));
    v17 = func_ov000_021a6fb4((unsigned int) (v16), (unsigned int) (v10));
}
