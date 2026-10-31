#include "Main/Unknown/code_020e6a74.h"

u32 func_020e6b48(void) {
    return ((u32) *(const u32 *) ((u8 *) (u32) (((u32) (&data_0217b860))) + 0));
}

u32 func_020e6b38(void) {
    return ((u32) *(const u32 *) ((u8 *) (u32) (((u32) (&data_0217b848))) + 0));
}

u32 func_020e6b28(void) {
    return ((u32) *(const u32 *) ((u8 *) (u32) (((u32) (&data_0217b848))) + 0));
}

u32 func_020e6b14(void) {
    return (
        (((u32) *(const u32 *) ((u8 *) (u32) (((u32) (&data_0217b848))) + 0))) +
        (0x18u));
}

void func_020e6ab8(Unk020e6488 *p0) {
    *(u32 *) ((u8 *) (u32) (p0) + 16) = (u32) ((
        (((u32) *(const u32 *) ((u8 *) (u32) (p0) + 16))) & (0x8000ffffu)));
    *(u32 *) ((u8 *) (u32) (p0) + 16) = (u32) ((
        (((u32) *(const u32 *) ((u8 *) (u32) (p0) + 16))) | (0x294a0000u)));
    *(u32 *) ((u8 *) (u32) (p0) + 20) = (u32) ((
        (((u32) *(const u32 *) ((u8 *) (u32) (p0) + 20))) & ~(0x3f000000u)));
    *(u32 *) ((u8 *) (u32) (p0) + 20) = (u32) ((
        (((u32) *(const u32 *) ((u8 *) (u32) (p0) + 20))) | (0x3f000000u)));
    *(u32 *) ((u8 *) (u32) (p0) + 20) = (u32) ((
        (((u32) *(const u32 *) ((u8 *) (u32) (p0) + 20))) & ~(0xfu)));
    *(u32 *) ((u8 *) (u32) (p0) + 20) = (u32) ((
        (((u32) *(const u32 *) ((u8 *) (u32) (p0) + 20))) | (0x2u)));
}

void func_020e6a74(void) {
    u32 local_8[1];
    func_01ff9048((u32) 0x17, (void *) (u32) data_0217b854, 0xc);
    local_8[0] = 0x1e;
    func_01ff9048((u32) 0x13, (void *) ((u32) local_8), 1);
}
