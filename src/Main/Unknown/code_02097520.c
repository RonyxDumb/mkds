#include "Main/Unknown/code_02097520.h"

u32 func_0209753c(u32 param_1) {
    void *iVar2;
    iVar2 = func_0209bc5c(func_02100138(0x1a9), param_1);
    *(u32 *) ((u8 *) iVar2 + 0xebc) = 0xaa;
    return 1;
}

void func_02097520(unsigned int p0) {
    *(unsigned short *) ((unsigned char *) (unsigned int) (p0) + 2) = (unsigned short) ((
        (((unsigned int) *(const unsigned short *) ((unsigned char *) (unsigned int) (p0) + 2))) |
        (((unsigned int) *(const unsigned short *) ((unsigned char *) (unsigned int) (((u32) (&data_021564c0))) +
                                                    0)))));
}
