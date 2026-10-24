#include "Main/Unknown/code_0205950c.h"

#pragma thumb on

// non-matching: 2 instructions differ; first at +0x2: original nothing, ours `ldr r2, [pc, #0x34] (->0x38)`
unsigned int func_0205950c(unsigned int p0, unsigned int p1) {
    unsigned int load_0 =
        ((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217aa00))) + 0));
    unsigned int load_2;
    unsigned int load_3;
    unsigned int load_5;
    unsigned int load_8;
    unsigned int load_10;
    *(unsigned int *) ((unsigned char *) (unsigned int) (load_0) + 0 + (0x1e34u)) = (unsigned int) (0x0u);
    load_2 = ((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217aa00))) + 0));
    load_3 = ((unsigned int) *(const unsigned char *) ((unsigned char *) (unsigned int) (((load_2) + (0x1e44u))) + 0));
    *(unsigned char *) ((unsigned char *) (unsigned int) (((load_2) + (0x1e44u))) + 0) =
        (unsigned char) (((load_3) & ~(0x2u)));
    load_5 = ((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217aa00))) + 0));
    *(unsigned short *) ((unsigned char *) (unsigned int) (((load_5) + (0x1608u))) + 16) = (unsigned short) (0x10u);
    *(unsigned short *) ((unsigned char *) (unsigned int) (((load_5) + (0x1608u))) + 18) = (unsigned short) (0x1u);
    load_8 = ((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217aa00))) + 0));
    *(unsigned int *) ((unsigned char *) (unsigned int) (load_8) + 0 + (0x1650u)) = (unsigned int) (p0);
    load_10 =
        ((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217aa00))) + 0));
    *(unsigned int *) ((unsigned char *) (unsigned int) (load_10) + 0 + (0x1654u)) = (unsigned int) (p1);
    return 0x1654u;
}

#pragma thumb off
