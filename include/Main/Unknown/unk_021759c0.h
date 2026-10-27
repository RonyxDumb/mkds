#pragma once

#include "types.h"

// 0x30-byte entries from 0x70 of the object behind data_021759c0.
typedef struct Unk021759c0_70 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x28];
} Unk021759c0_70;

// Object behind data_021759c0.
typedef struct Unk021759c0 {
    /* 00 */ s32 mUnk_00;
    /* 004 */ u8 mUnk_004[0x4];
    /* 08 */ s32 mUnk_08;
    /* 00c */ u32 mUnk_00c;
    /* 010 */ s32 mUnk_010;
    /* 014 */ u8 mUnk_014[0x4];
    /* 018 */ s32 mUnk_18;
    /* 01c */ u8 mUnk_01c[0x12];
    /* 02e */ u8 mUnk_2e;
    /* 2f */ u8 mUnk_2f;
    /* 030 */ u8 mUnk_030[0x7];
    /* 37 */ u8 mUnk_37;
    /* 038 */ u8 mUnk_038[0x4];
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u16 mUnk_3e;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u16 mUnk_42;
    /* 044 */ u8 mUnk_044[0x11];
    /* 55 */ s8 mUnk_55;
    /* 56 */ u8 mUnk_56[1];
    /* 57 */ s8 mUnk_57;
    /* 58 */ s8 mUnk_58;
    /* 59 */ u8 mUnk_59[9];
    /* 62 */ s8 mUnk_62;
    /* 63 */ u8 mUnk_63[0xd];
    /* 70 */ Unk021759c0_70 mUnk_70[18];
    /* 3d0 */ u8 mUnk_3d0;
} Unk021759c0;

extern Unk021759c0 *data_021759c0;
