#include "Main/Unknown/code_02097520.h"

u32 func_0209753c(u32 param_1) {
    u32 uVar1;
    int iVar2;
    uVar1 = (u32) func_02100138((u32) (0x000001a9u));
    iVar2 = func_0209bc5c((u32) (uVar1), (int) (param_1));
    *(u32 *) (iVar2 + 0xebc) = 0xaa;
    return 1;
}

void func_02097520(unsigned int p0) {
    *(unsigned short *) ((unsigned char *) (unsigned int) (p0) + 2) = (unsigned short) ((
        (((unsigned int) *(const unsigned short *) ((unsigned char *) (unsigned int) (p0) + 2))) |
        (((unsigned int) *(const unsigned short *) ((unsigned char *) (unsigned int) (((u32) (&data_021564c0))) +
                                                    0)))));
}
