#include "Main/Unknown/code_020091e0.h"

#pragma thumb on

void func_020091e0(void *p0, unsigned int p1) {
    *(unsigned short *) ((unsigned char *) (unsigned int) p0 + 10) = (unsigned short) 0x20u;
    *(unsigned short *) ((unsigned char *) (unsigned int) p0 + 12) = (unsigned short) p1;
    *(unsigned short *) ((unsigned char *) (unsigned int) p0 + 14) =
        (unsigned short) (((((p1) & (0xffff0000u))) >> 16));
    *(unsigned short *) ((unsigned char *) (unsigned int) p0 + 16) = (unsigned short) (((unsigned int) *(
        const unsigned short *) ((unsigned char *) (unsigned int) (((((p0) + (0x0u))) + (0x48u))) + 0)));
}

#pragma thumb off
