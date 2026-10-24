#include "Main/Unknown/code_020cef1c.h"

#pragma thumb on

// non-matching: 0x48 bytes, original 0x4c; 28 instructions differ; first at +0x0: original `push {lr}`, ours `push {r4,
// lr}`
unsigned int func_020cef1c(void) {
    unsigned int v2 = ((u32) (&data_0217b488));
    unsigned int v3 = ((unsigned int) *(unsigned int *) ((v2) + (0)));
    unsigned int v4 = 0x130u;
    unsigned int v5 = func_020cef68((unsigned int) (v3), (unsigned int) (v4));
    unsigned int v7 = ((u32) (&data_0217b488));
    unsigned int v8 = ((unsigned int) *(unsigned int *) ((v7) + (0)));
    unsigned int v10;
    unsigned int v12;
    unsigned int v14;
    unsigned int v16;
    unsigned int v18;
    unsigned int v20;
    unsigned int v22;
    unsigned int v23;
    unsigned int v25;
    unsigned int v27;
    *(unsigned int *) ((v8) + (0)) = (unsigned int) (0x0u);
    v10 = ((unsigned int) *(unsigned int *) ((v7) + (0)));
    *(unsigned int *) ((v10) + (4)) = (unsigned int) (0x0u);
    v12 = ((unsigned int) *(unsigned int *) ((v7) + (0)));
    *(unsigned int *) ((v12) + (8)) = (unsigned int) (0x0u);
    v14 = ((unsigned int) *(unsigned int *) ((v7) + (0)));
    *(unsigned int *) ((v14) + (12)) = (unsigned int) (0x0u);
    v16 = ((unsigned int) *(unsigned int *) ((v7) + (0)));
    *(unsigned int *) ((v16) + (16)) = (unsigned int) (0x0u);
    v18 = ((unsigned int) *(unsigned int *) ((v7) + (0)));
    *(unsigned int *) ((v18) + (20)) = (unsigned int) (0x0u);
    v20 = ((unsigned int) *(unsigned int *) ((v7) + (0)));
    *(unsigned int *) ((v20) + (28)) = (unsigned int) (0x0u);
    v22 = ((unsigned int) *(unsigned int *) ((v7) + (0)));
    v23 = ((v22) + (0x54u));
    *(unsigned char *) ((v23) + (0)) = (unsigned char) (0x0u);
    v25 = ((unsigned int) *(unsigned int *) ((v7) + (0)));
    *(unsigned int *) ((v25) + (88)) = (unsigned int) (0x0u);
    v27 = ((unsigned int) *(unsigned int *) ((v7) + (0)));
    *(unsigned int *) ((v27) + (112)) = (unsigned int) (0x0u);
    return 0x0u;
}

#pragma thumb off
