#pragma once

#include "types.h"
#include "01/unk_021a9000.h"

// Object at the start of a 0xdc-byte allocation made by func_02038d88.
typedef struct Unk02180774 {
    /* 00 */ u8 mUnk_00[0x28];
    /* 28 */ u8 mUnk_28[0x48];
    /* 70 */ u8 mUnk_70[0x6c];
} Unk02180774;

void func_ov001_02180610(void);
void func_ov001_02180728(Unk02180728 *p0, void *p1, void *p2, s32 p3, s32 p4);
void func_ov001_02180740(Unk02180774 *p0, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6);
void func_ov001_02180774(Unk02180774 *p0, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6);
void func_ov001_021807a8(Unk02180774 *p0, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
unsigned int func_ov001_021807e4(void);
void func_ov001_02180800(void);
unsigned int func_ov001_02180ad0(Unk02180728 *p0, u32 p1, u32 p2, u32 p3, u32 p4, u16 *p5);
