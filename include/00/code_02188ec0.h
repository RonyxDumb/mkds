#pragma once

#include "types.h"
#include "00/code_02188de4.h"

// Eleven entries of 0xc0 bytes at 0x470 of Unk02188ec0.
typedef struct Unk02188ee0 {
    /* 00 */ u8 pad_00[0xa];
    /* 0a */ u16 fieldA;
    /* 0c */ u8 fieldC[4];
    /* 10 */ s32 field10;
    /* 14 */ u8 field14;
    /* 15 */ u8 field15;
    /* 16 */ u8 field16;
    /* 17 */ u8 pad_17[0x15];
    /* 2c */ u16 field2C;
    /* 2e */ u8 pad_2e[8];
    /* 36 */ u16 field36;
    /* 38 */ u8 pad_38[0x88];
} Unk02188ee0;

// Entries of 0x24 bytes at 0x300 of Unk02188ec0.
typedef struct Unk02188ec0_300 {
    /* 00 */ u8 mUnk_00_lo : 4;
    /* 00 */ u8 mUnk_00_hi : 4;
    /* 01 */ u8 field1;
    /* 02 */ u8 field2;
    /* 03 */ u8 field3;
    /* 04 */ u8 field4[0x20];
} Unk02188ec0_300;

// Entries of 4 bytes at 0x444 of Unk02188ec0.
typedef struct Unk02188ec0_444 {
    /* 00 */ u8 field0;
    /* 01 */ u8 pad_01;
    /* 02 */ u8 field2;
    /* 03 */ u8 field3;
} Unk02188ec0_444;

typedef struct Unk02188ec0 {
    /* 000 */ Unk02188db0 field0[3];
    /* 300 */ Unk02188ec0_300 field300[9];
    /* 444 */ Unk02188ec0_444 field444[11];
    /* 470 */ Unk02188ee0 field470[11];
    /* cb0 */ u64 fieldCB0;
    /* cb8 */ Unk02188de4 fieldCB8;
    /* d0a */ u8 fieldD0A;
    /* d0b */ u8 fieldD0B : 2;
    /* d0b */ u8 fieldD0B_2 : 2;
    /* d0b */ u8 fieldD0B_4 : 4;
    /* d0c */ u8 fieldD0C : 4;
    /* d0c */ u8 fieldD0C_4 : 2;
    /* d0c */ u8 fieldD0C_6 : 2;
    /* d0d */ u8 fieldD0D;
    /* d0e */ u8 fieldD0E;
    /* d0f */ u8 fieldD0F;
    /* d10 */ u8 fieldD10;
    /* d11 */ s8 fieldD11;
    /* d12 */ u8 fieldD12;
    /* d13 */ u8 fieldD13;
    /* d14 */ u8 fieldD14;
    /* d15 */ u8 fieldD15;
    /* d16 */ u16 fieldD16;
} Unk02188ec0;

u32 func_ov000_02188ec0(Unk02188ec0 *object);
