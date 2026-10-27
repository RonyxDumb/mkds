#pragma once

#include "types.h"

// Three vectors, 0x24 bytes.
typedef struct Unk020e43a8_28 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ Vec3 mUnk_0c;
    /* 18 */ Vec3 mUnk_18;
} Unk020e43a8_28;

// Object read through mUnk_9c; only the s16 at 0x28 is seen.
typedef struct Unk020e4a68 Unk020e4a68;

typedef struct Unk020e43a8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ Vec3 mUnk_1c;
    /* 28 */ Unk020e43a8_28 mUnk_28;
    /* 4c */ Vec3 mUnk_4c;
    /* 58 */ Vec3 mUnk_58;
    /* 64 */ s16 mUnk_64;
    /* 66 */ u8 mUnk_66[0x0a];
    /* 70 */ s32 mUnk_70;
    /* 74 */ u8 mUnk_74[0x04];
    /* 78 */ u32 mUnk_78;
    /* 7c */ u8 mUnk_7c[0x02];
    /* 7e */ u16 mUnk_7e;
    /* 80 */ u8 mUnk_80[0x04];
    /* 84 */ u32 mUnk_84;
    /* 88 */ u8 mUnk_88[0x06];
    /* 8e */ u16 mUnk_8e;
    /* 90 */ u16 mUnk_90;
    /* 92 */ u16 mUnk_92;
    /* 94 */ u8 mUnk_94[0x08];
    /* 9c */ Unk020e4a68 *mUnk_9c;
    /* a0 */ Unk020e43a8_28 mUnk_a0;
    /* c4 */ u16 mUnk_c4;
    /* c6 */ s16 mUnk_c6;
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mUnk_cc;
    /* d0 */ u8 mUnk_d0[0x04];
    /* d4 */ s32 mUnk_d4;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* e0 */ u8 mUnk_e0[0x14];
    /* f4 */ Vec3 mUnk_f4;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ u8 mUnk_10c[0x18];
    /* 124 */ s32 mUnk_124;
    /* 128 */ s32 mUnk_128;
    /* 12c */ s32 mUnk_12c;
    /* 130 */ u8 mUnk_130[0x14];
    /* 144 */ u16 mUnk_144;
    /* 146 */ u16 mUnk_146;
    /* 148 */ u8 mUnk_148[0x02];
    /* 14a */ s16 mUnk_14a;
    /* 14c */ s32 mUnk_14c;
    /* 150 */ s32 mUnk_150;
    /* 154 */ u8 mUnk_154[0x08];
    /* 15c */ s32 mUnk_15c;
} Unk020e43a8;

void func_020e43a8(Unk020e43a8 *p);
