#pragma once

#include "types.h"

// Objects whose layout isn't known yet.
// What data_0217aa08 points to.
typedef struct Unk0217aa08_00 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 mUnk_0c[0x14];
    /* 20 */ u8 mUnk_20[0x11];
    /* 31 */ union {
        u8 mUnk_31;
        struct {
            u8 mUnk_31_0 : 1;
            u8 mUnk_31_1 : 2;
            u8 mUnk_31_3 : 1;
            u8 mUnk_31_4 : 1;
            u8 mUnk_31_5 : 3;
        };
    };
    /* 32 */ u8 mUnk_32[0x2];
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
    /* 40 */ u32 mUnk_40;
    /* 44 */ u32 mUnk_44;
    /* 48 */ u32 mUnk_48;
} Unk0217aa08_00;

typedef struct Unk0217aa08_04 {
    /* 000 */ u8 mUnk_000[0x4];
    /* 004 */ u8 mUnk_004 : 1;
    /* 005 */ u8 mUnk_005[0x3];
    /* 008 */ u8 mUnk_008[0x200];
} Unk0217aa08_04;

typedef struct Unk0217aa08 {
    /* 00 */ Unk0217aa08_00 *mUnk_00;
    /* 04 */ Unk0217aa08_04 *mUnk_04;
    /* 08 */ u8 mUnk_08[0x20];
    /* 28 */ u8 mUnk_28;
} Unk0217aa08;

extern u8 data_0217aa00[];
extern Unk0217aa08 *data_0217aa08;
extern u8 data_0217aa0c[];
extern u8 data_0217aa10[];
// Object behind data_0217aa14 with a halfword at 0x724.
typedef struct Unk0217aa14 {
    /* 000 */ u8 mUnk_000[0x724];
    /* 724 */ u16 mUnk_724;
} Unk0217aa14;

extern Unk0217aa14 *data_0217aa14;
extern u8 data_0217aa54[];
extern u8 data_0217aa64[];
extern u8 data_0217aa6c[];
extern u8 data_0217aa7c[];
extern u8 data_0217ac94[];
extern u8 data_0217aca8[];
extern u8 data_0217acb4[];
extern u8 data_0217acbc[];
extern u8 data_0217acc0[];
extern u8 data_0217ad00[];
extern u8 data_0217ad08[];
extern u8 data_0217ad10[];
extern u8 data_0217ad24[];
extern u8 data_0217ad28[];
extern u8 data_0217ad2c[];
extern u8 data_0217ad30[];
extern u8 data_0217ae84[];
extern u8 data_0217aebc[];
extern u8 data_0217aec0[];
extern u8 data_0217aec4[];
extern u8 data_0217aec8[];
extern u8 data_0217aed0[];
extern u8 data_0217af24[];
extern u8 data_0217af28[];

extern u8 data_0217aa04[];
extern u8 data_0217aa24[];
extern u8 data_0217aa2c[];
extern u8 data_0217acac[];

extern u8 data_0217aa18[];
extern u8 data_0217aa1c[];
extern u8 data_0217ad18[];
extern u8 data_0217aeb0[];
