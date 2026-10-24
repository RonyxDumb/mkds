#include "Main/Unknown/code_0207adf8.h"

// non-matching: 0x64 bytes, original 0x60; 17 instructions differ; first at +0x0: original `stmdb sp!, {r4, lr}`, ours
// `stmdb sp!, {r4, r5, lr}`
void func_0207adf8(unsigned int p0, unsigned int p1, unsigned int p2) {
    unsigned int v2 = ((unsigned int) *(unsigned short *) ((p0) + (110)));
    unsigned int v3 = ((v2) & (0xffu));
    unsigned int v4 = func_02084ad8((unsigned int) (p0), (unsigned int) (v3), (unsigned int) (p2));
    unsigned int v5 = ((unsigned int) *(unsigned int *) ((p0) + (88)));
    unsigned int v6 = ((u32) (&data_02155a20));
    unsigned int v8 = ((unsigned int) *(unsigned int *) ((v6) + (0 + (((v5) << 2)))));
    unsigned int v9 = ((unsigned int (*)(unsigned int, unsigned int, unsigned int))(v8))(p0, v8, v5);
    unsigned int v10 = ((unsigned int) *(unsigned short *) ((p0) + (110)));
    unsigned int v11 = ((unsigned int) *(unsigned short *) ((p0) + (108)));
    unsigned int v13 = ((v10) & (0xffu));
    unsigned int v14 = ((v11) & (0xffu));
    unsigned int v15 = func_02084a88((unsigned int) (p0), (unsigned int) (v13), (unsigned int) (v14));
    unsigned int v16 = ((unsigned int) *(unsigned int *) ((p0) + (88)));
    unsigned int v17 = ((u32) (&data_02155a20));
    unsigned int v19 = ((unsigned int) *(unsigned int *) ((v17) + (0 + (((v16) << 2)))));
    unsigned int v20 = ((unsigned int (*)(unsigned int, unsigned int, unsigned int))(v19))(p0, v19, v16);
}
