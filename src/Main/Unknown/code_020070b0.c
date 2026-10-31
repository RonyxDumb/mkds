#include "Main/Unknown/code_020070b0.h"

#pragma thumb on

u32 func_020070e4(void) {
    return ((u32) *(const short *) ((u8 *) (u32) (((u32) (&data_0216f3d0))) + 0 + (0x0u)));
}

u32 func_020070d8(void) {
    return ((u32) *(const short *) ((u8 *) (u32) (((u32) (&data_0216f3d4))) + 0 + (0x0u)));
}

void func_020070cc(u32 p0) {
    *(u16 *) ((u8 *) (u32) (((u32) (&data_0216f3d0))) + 0) = (u16) p0;
}

void func_020070c0(u32 p0) {
    *(u16 *) ((u8 *) (u32) (((u32) (&data_0216f3d4))) + 0) = (u16) p0;
}

Unk0216f3dc *func_020070b8(void) {
    return (Unk0216f3dc *) data_0216f3dc;
}

u32 func_020070b0(void) {
    return ((u32) (&data_0216f478));
}

#pragma thumb off
