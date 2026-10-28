#pragma once

#include "types.h"

// 0x30-byte entries from 0x70 of the object behind data_021759c0.
typedef struct Unk021759c0_70 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u16 mUnk_14;
    /* 16 */ s8 mUnk_16;
    /* 17 */ u8 mUnk_17;
    /* 18 */ void *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ u8 mUnk_24;
    /* 25 */ u8 mUnk_25;
    /* 26 */ u8 mUnk_26;
    /* 27 */ u8 mUnk_27;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
} Unk021759c0_70;

// Object behind data_021759c0.
typedef struct Unk021759c0 {
    /* 00 */ s32 mUnk_00;
    /* 004 */ s32 mUnk_004;
    /* 08 */ s32 mUnk_08;
    /* 00c */ u32 mUnk_00c;
    /* 010 */ s32 mUnk_010;
    /* 014 */ s32 mUnk_014;
    /* 018 */ s32 mUnk_18;
    /* 01c */ s32 mUnk_1c;
    /* 020 */ s32 mUnk_020;
    /* 024 */ u8 mUnk_024[0x4];
    /* 028 */ u16 mUnk_028;
    /* 02a */ u16 mUnk_02a;
    /* 02c */ s16 mUnk_02c;
    /* 02e */ u8 mUnk_2e;
    /* 2f */ u8 mUnk_2f;
    /* 030 */ u8 mUnk_030[0x6];
    /* 036 */ u8 mUnk_036;
    /* 37 */ u8 mUnk_37;
    /* 038 */ u16 mUnk_038;
    /* 03a */ u8 mUnk_03a[0x2];
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u16 mUnk_3e;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u16 mUnk_42;
    /* 044 */ u16 mUnk_044;
    /* 046 */ u8 mUnk_046[0xe];
    /* 54 */ s8 mUnk_54;
    /* 55 */ s8 mUnk_55;
    /* 056 */ u8 mUnk_056[0x1];
    /* 57 */ s8 mUnk_57;
    /* 58 */ s8 mUnk_58;
    /* 059 */ u8 mUnk_059[0x3];
    /* 05c */ s32 mUnk_05c;
    /* 60 */ u16 mUnk_60;
    /* 62 */ s8 mUnk_62;
    /* 063 */ u8 mUnk_063;
    /* 064 */ s8 mUnk_064;
    /* 065 */ u8 mUnk_065[0xb];
    /* 70 */ Unk021759c0_70 mUnk_70[18];
    /* 3d0 */ u8 mUnk_3d0;
    /* 3d1 */ u8 mUnk_3d1;
    /* 3d2 */ u8 mUnk_3d2;
    /* 3d3 */ u8 mUnk_3d3;
    /* 3d4 */ u8 mUnk_3d4;
    /* 3d5 */ s8 mUnk_3d5[3];
    /* 3d8 */ u16 mUnk_3d8;
    /* 3da */ u8 mUnk_3da[0x2];
    /* 3dc */ void *mUnk_3dc;
    /* 3e0 */ u8 mUnk_3e0;
    /* 3e1 */ u8 mUnk_3e1;
    /* 3e2 */ u16 mUnk_3e2;
    /* 3e4 */ u8 mUnk_3e4;
    /* 3e5 */ u8 mUnk_3e5;
    /* 3e6 */ s8 mUnk_3e6;
    /* 3e7 */ u8 mUnk_3e7[0x1];
    /* 3e8 */ u16 mUnk_3e8;
    /* 3ea */ u8 mUnk_3ea;
    /* 3eb */ u8 mUnk_3eb;
    /* 3ec */ u32 mUnk_3ec[1];
} Unk021759c0;

extern Unk021759c0 *data_021759c0;
