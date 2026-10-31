#include "Main/Unknown/code_020ab5e4.h"

#pragma thumb on

void func_020ab5f4(Unk0217b278_34 *p0) {
    *(u16 *) ((u8 *) (u32) p0 + 0) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 6) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 2) = (u16) 0x28u;
    *(u16 *) ((u8 *) (u32) p0 + 4) = (u16) 0x2du;
}

void func_020ab5e4(Unk0217b278_34 *p0, u32 p1, u32 p2) {
    *(u16 *) ((u8 *) (u32) p0 + 0) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 6) = (u16) 0x0u;
    *(u16 *) ((u8 *) (u32) p0 + 2) = (u16) p1;
    *(u16 *) ((u8 *) (u32) p0 + 4) = (u16) (((p1) + (p2)));
}

#pragma thumb off
