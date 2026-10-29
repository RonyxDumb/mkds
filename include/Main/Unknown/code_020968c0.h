#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Unk0206bcb0
#include "Main/Unknown/code_020e6fd4.h" // Unk020e71a0

// Object up to 0x109 bytes.
typedef struct Unk02096a04 {
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
    /* c4 */ u16 mUnk_c4;
    /* c6 */ u8 mUnk_c6[2];
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mUnk_cc;
    /* d0 */ s32 mUnk_d0;
    /* d4 */ s32 mUnk_d4;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* e4 */ u16 mUnk_e4;
    /* e6 */ u8 mUnk_e6[2];
    /* e8 */ s32 mUnk_e8;
    /* ec */ s32 mUnk_ec;
    /* f0 */ s32 mUnk_f0;
    /* f4 */ s32 mUnk_f4;
    /* f8 */ s32 mUnk_f8;
    /* fc */ s32 mUnk_fc;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ u8 mUnk_108;
} Unk02096a04;

// Pointer table with a halfword count behind it.
typedef struct Unk020968f4 {
    /* 00 */ Unk02096a04 **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk020968f4;

u32 func_0209702c(Unk02096a04 *p, Unk0206bcb0 *a, u8 *b, u8 *c);
u32 func_02096f54(Unk02096a04 *p, Unk0206bcb0 *a, u8 *b, u8 *c);
s32 func_02096df0(Unk02096a04 *p, const Vec3 *a, s32 b, Vec3 *c);
void func_02096d68(void *a);
void func_02096a04(void *a, Unk02096a04 *p);
void func_020968f4(Unk020968f4 *p);
s32 func_020968dc(s32 a);
s32 func_020968c0(s32 a, s32 b);
