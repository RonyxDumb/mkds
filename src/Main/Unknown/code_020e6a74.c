#include "Main/Unknown/code_020e6a74.h"

unsigned int func_020e6b48(void) {
    return ((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217b860))) + 0));
}

unsigned int func_020e6b38(void) {
    return ((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217b848))) + 0));
}

unsigned int func_020e6b28(void) {
    return ((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217b848))) + 0));
}

unsigned int func_020e6b14(void) {
    return (
        (((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (((u32) (&data_0217b848))) + 0))) +
        (0x18u));
}

void func_020e6ab8(unsigned int p0) {
    *(unsigned int *) ((unsigned char *) (unsigned int) (p0) + 16) = (unsigned int) ((
        (((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (p0) + 16))) & (0x8000ffffu)));
    *(unsigned int *) ((unsigned char *) (unsigned int) (p0) + 16) = (unsigned int) ((
        (((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (p0) + 16))) | (0x294a0000u)));
    *(unsigned int *) ((unsigned char *) (unsigned int) (p0) + 20) = (unsigned int) ((
        (((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (p0) + 20))) & ~(0x3f000000u)));
    *(unsigned int *) ((unsigned char *) (unsigned int) (p0) + 20) = (unsigned int) ((
        (((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (p0) + 20))) | (0x3f000000u)));
    *(unsigned int *) ((unsigned char *) (unsigned int) (p0) + 20) = (unsigned int) ((
        (((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (p0) + 20))) & ~(0xfu)));
    *(unsigned int *) ((unsigned char *) (unsigned int) (p0) + 20) = (unsigned int) ((
        (((unsigned int) *(const unsigned int *) ((unsigned char *) (unsigned int) (p0) + 20))) | (0x2u)));
}

void func_020e6a74(void) {
    u32 local_8[1];
    func_01ff9048((u32) (0x17), (void *) (*(u32 *) (((u32) ((u32) (&data_0217b854))))), (int) (0xc));
    local_8[0] = 0x1e;
    func_01ff9048((u32) (0x13), (void *) ((u32) (u32) (local_8)), (int) (1));
    return;
}
