#pragma once

#include "types.h"
#include "Main/Unknown/code_02080b1c.h"
#include "Main/Unknown/code_020e6fd4.h" // Unk020e71a0

// Object of 0x2a bytes: an Unk02080b1c at 0x00, a word at 0x20, the halfword at 0x24 given to func_0207a974 and
// halfwords at 0x26 and 0x28.
typedef struct Unk020905a8 {
    /* 00 */ Unk02080b1c mUnk_00;
    /* 20 */ s32 mUnk_20;
    /* 24 */ u16 mUnk_24;
    /* 26 */ s16 mUnk_26;
    /* 28 */ s16 mUnk_28;
} Unk020905a8;

// Value at 0x00 (halfword), 0x02 and 0x03 (bytes) combined by func_020908d0.
typedef struct Unk020908d0 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk020908d0;

// An Unk020e71a0 at 0x00 followed by words from 0xa0 to 0xc8.
typedef struct Unk020912a0 {
    /* 00 */ Unk020e71a0 mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ s32 mUnk_b8;
    /* bc */ s32 mUnk_bc;
    /* c0 */ s32 mUnk_c0;
    /* c4 */ s32 mUnk_c4;
    /* c8 */ s32 mUnk_c8;
} Unk020912a0;

// Array of Unk020912a0 pointers at 0x00, its count at 0x04.
typedef struct Unk0209151c {
    /* 00 */ Unk020912a0 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0209151c;

void func_02090354(void);
s32 func_020905a8(Unk020905a8 *a);
void func_02090638(Unk020905a8 *a);
void func_02090748(Unk020905a8 *a);
void func_0209081c(Unk020905a8 *a);
void func_02090838(Unk020905a8 *a, Unk02080b1c_00 *b);
void func_0209086c(Unk020905a8 *a, u32 b);
s32 func_020908d0(u32 a, void *b);
void func_02090920(u32 a);
s32 func_02090940(void);
s32 func_020909cc(void);
u32 func_02090b24(void);
u32 func_02090cf8(void);
u32 func_02090ff4(void);
u32 func_0209119c(void);
u32 func_020911a8(void);
u32 func_020911f4(void);
u32 func_02091214(void);
u32 func_02091238(void);
void func_0209125c(void);
void func_020912a0(void *a, Unk020912a0 *b);
void func_0209151c(Unk0209151c *a);
void func_020915c0(void *a, Unk020912a0 *b);
void func_02091654(void *a);
void func_0209166c(void *a);
void func_020916a0(void *a, Unk020912a0 *b);
void func_02091784(void *a);
void func_0209179c(void *a);
