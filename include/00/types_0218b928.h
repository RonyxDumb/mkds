#pragma once

#include "types.h"

// Connection object; it sits at offset 0x4c of Unk0218b668.
typedef struct Unk0218b928 {
    /* 000 */ s32 mUnk_00;
    /* 004 */ void *mUnk_04;
    /* 008 */ void *mUnk_08;
    /* 00c */ u8 pad_0c[0x48];
    /* 054 */ u8 mUnk_54[0x20];
    /* 074 */ s8 mUnk_74[8];
    /* 07c */ u8 *mUnk_7c;
    /* 080 */ s32 mUnk_80;
    /* 084 */ u8 *mUnk_84[255];
    /* 480 */ s32 mUnk_480;
    /* 484 */ s32 mUnk_484;
    /* 488 */ void (*mUnk_488)();
    /* 48c */ void (*mUnk_48c)();
    /* 490 */ void (*mUnk_490)();
    /* 494 */ void *mUnk_494;
    /* 498 */ u8 pad_498[8];
    /* 4a0 */ u32 mUnk_4a0;
    /* 4a4 */ s32 mUnk_4a4;
    /* 4a8 */ u16 mUnk_4a8;
    /* 4aa */ u8 pad_4aa[6];
    /* 4b0 */ s32 mUnk_4b0;
    /* 4b4 */ u32 mUnk_4b4;
    /* 4b8 */ s32 mUnk_4b8;
    /* 4bc */ u8 mUnk_4bc[0x108];
    /* 5c4 */ u32 mUnk_5c4;
    /* 5c8 */ s32 mUnk_5c8;
    /* 5cc */ u8 pad_5cc[8];
} Unk0218b928;

// Event data passed to the callbacks stored at Unk0218b668::mUnk_630.
typedef struct Unk0218b74c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 pad_06[0xe];
    /* 14 */ u8 mUnk_14;
    /* 15 */ u8 mUnk_15;
} Unk0218b74c;

// Address block filled in by func_ov000_0218e438.
typedef struct Unk0218b8f4 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk0218b8f4;

// Entry of the list at Unk0218b928::mUnk_08.
typedef struct Unk0218c0bc {
    /* 0 */ u8 *mUnk_00;
    /* 4 */ s32 mUnk_04;
} Unk0218c0bc;
