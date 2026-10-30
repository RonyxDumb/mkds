#include "Main/Unknown/code_020e35a0.h"

void func_020e35a0(unsigned int p0) {
    *(unsigned int *) ((unsigned char *) (unsigned int) p0 + 8) =
        (unsigned int) (((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) p0 + 172)));
    *(unsigned int *) ((unsigned char *) (unsigned int) p0 + 20) = (unsigned int) 0x0u;
    *(unsigned short *) ((unsigned char *) (unsigned int) p0 + 2) = (unsigned short) ((
        (((unsigned int) *(const unsigned short *) ((unsigned char *) (unsigned int) p0 + 2))) |
        (((unsigned int) *(const unsigned short *) ((unsigned char *) (unsigned int) (((u32) (&data_02158bb8))) +
                                                    0)))));
    *(unsigned short *) ((unsigned char *) (unsigned int) p0 + 2) = (unsigned short) ((
        (((unsigned int) *(const unsigned short *) ((unsigned char *) (unsigned int) p0 + 2))) |
        (((unsigned int) *(const unsigned short *) ((unsigned char *) (unsigned int) (((u32) (&data_02158bb4))) +
                                                    0)))));
}
