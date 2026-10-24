#include "01/code_02180c88.h"

#pragma thumb off

unsigned int func_ov001_02180ca4(void) {
    return ((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_021755a0))) + 0));
}

void func_ov001_02180c88(unsigned int p0) {
    *(unsigned int *) ((unsigned char *) (unsigned int) (p0) + 0) = (unsigned int) (0x1000u);
    *(unsigned int *) ((unsigned char *) (unsigned int) (p0) + 4) = (unsigned int) (0x0u);
    *(unsigned int *) ((unsigned char *) (unsigned int) (p0) + 8) = (unsigned int) (0x0u);
    *(unsigned int *) ((unsigned char *) (unsigned int) (p0) + 12) = (unsigned int) (0x1000u);
}

#pragma thumb on
