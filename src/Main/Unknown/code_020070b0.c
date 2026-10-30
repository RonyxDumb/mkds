#include "Main/Unknown/code_020070b0.h"

#pragma thumb on

unsigned int func_020070e4(void) {
    return ((unsigned int) *(const short *) ((unsigned char *) (unsigned int) (((u32) (&data_0216f3d0))) + 0 + (0x0u)));
}

unsigned int func_020070d8(void) {
    return ((unsigned int) *(const short *) ((unsigned char *) (unsigned int) (((u32) (&data_0216f3d4))) + 0 + (0x0u)));
}

void func_020070cc(unsigned int p0) {
    *(unsigned short *) ((unsigned char *) (unsigned int) (((u32) (&data_0216f3d0))) + 0) = (unsigned short) p0;
}

void func_020070c0(unsigned int p0) {
    *(unsigned short *) ((unsigned char *) (unsigned int) (((u32) (&data_0216f3d4))) + 0) = (unsigned short) p0;
}

Unk0216f3dc *func_020070b8(void) {
    return (Unk0216f3dc *) data_0216f3dc;
}

unsigned int func_020070b0(void) {
    return ((u32) (&data_0216f478));
}

#pragma thumb off
