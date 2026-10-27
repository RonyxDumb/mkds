#pragma once

#include "types.h"

#include "code_0212c478.h" // Unk0212c400
#include "code_0212c7a0.h" // Unk0212c7a0
#include "code_0212c7f0.h" // Unk0212c8a4
#include "code_0212c9d4.h" // Unk0212ccd4, Unk0212c9d4
#include "code_0200e904.h" // Unk0200eb90
#include "code_0212da38.h" // Unk02017328

struct Unk0212d5f8;
struct Unk0212ef48;

// Object behind data_0217d354; the object at its member 0x8 has 0xc added to it.
typedef struct Unk0217d354_08 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 *mUnk_0c;
} Unk0217d354_08;

typedef struct Unk0217d354 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ Unk0217d354_08 *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u16 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ u16 mUnk_24;
    /* 28 */ s32 mUnk_28;
} Unk0217d354;

// Object behind data_0217d350; its member 0x3c points to a table of 0x40-byte objects.
typedef struct Unk0217d350_3c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ u8 mUnk_08[0x38];
} Unk0217d350_3c;

typedef struct Unk0217d350_30 {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u16 mUnk_06;
} Unk0217d350_30;

// Object behind data_0217d350 members 0x10 and 0x20.
typedef struct Unk0217d350_10 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08;
    /* 0c */ u8 mUnk_0c;
} Unk0217d350_10;

typedef struct Unk0217d350 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ void *mUnk_04;
    /* 08 */ Unk0217d350_30 *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ Unk0217d350_10 *mUnk_10;
    /* 14 */ Unk0217d350_3c *mUnk_14;
    /* 18 */ Unk0217d350_30 *mUnk_18;
    /* 1c */ void *mUnk_1c;
    /* 20 */ Unk0217d350_10 *mUnk_20;
    /* 24 */ Unk0217d350_3c *mUnk_24;
    /* 28 */ u8 mUnk_28[4];
    /* 2c */ void *mUnk_2c;
    /* 30 */ Unk0217d350_30 *mUnk_30;
    /* 34 */ void *mUnk_34;
    /* 38 */ void *mUnk_38;
    /* 3c */ Unk0217d350_3c *mUnk_3c;
    /* 40 */ s32 mUnk_40;
    /* 44 */ void *mUnk_44;
    /* 48 */ void *mUnk_48;
    /* 4c */ s32 mUnk_4c;
    /* 50 */ void *mUnk_50;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68;
    /* 6c */ u8 mUnk_6c[4];
    /* 70 */ s32 mUnk_70;
    /* 74 */ s16 mUnk_74;
    /* 76 */ s16 mUnk_76;
    /* 78 */ s32 mUnk_78;
    /* 7c */ s32 mUnk_7c;
    /* 80 */ s16 mUnk_80;
    /* 82 */ u8 mUnk_82[2];
    /* 84 */ u32 mUnk_84;
    /* 88 */ void *mUnk_88;
    /* 8c */ void *mUnk_8c;
    /* 90 */ s32 mUnk_90[2];
    /* 98 */ s32 mUnk_98;
    /* 9c */ s32 mUnk_9c;
    /* a0 */ s32 mUnk_a0;
} Unk0217d350;

// Objects whose layout isn't known yet.
extern u8 data_0217d014[];
extern u8 data_0217d018[];
extern u8 data_0217d01c[];
extern u8 data_0217d028[];
extern u8 data_0217d064[];
extern u8 data_0217d07c[];
extern u8 data_0217d0a0[];
extern u8 data_0217d134[];
extern u8 data_0217d178[];
extern u8 data_0217d1f4[];
extern s32 data_0217d20c;
extern s32 data_0217d21c;
extern u8 data_0217d220[];
extern u8 data_0217d244[];
extern u8 data_0217d344[];
extern u8 data_0217d348[];
extern u8 data_0217d34c[];
extern Unk0217d350 *data_0217d350;
extern Unk0217d354 *data_0217d354;
extern u8 data_0217d358[];
extern u8 data_0217d35c[];
extern u8 data_0217d360[];
extern u8 data_0217d364[];
extern u8 data_0217d368[];
extern u8 data_0217d36c[];
extern u8 data_0217d370[];
extern u8 data_0217d37c[];
extern u8 data_0217d380[];
extern u8 data_0217d3ec[];
extern u8 data_0217d3f0[];
extern u8 data_0217d3f4[];
extern u8 data_0217d3f8[];
extern u8 data_0217d3fc[];
extern u8 data_0217d400[];
extern u8 data_0217d408[];
extern u32 data_0217d084[];
extern u8 data_0217d1f0[];
extern u8 data_0217d22c[];
extern u8 data_0217d320[];
extern u8 data_0217d324[];
extern u8 data_0217d328[];
extern u8 data_0217d32c[];
extern u8 data_0217d40c[];
extern u32 data_0217d438;
extern u32 data_0217d43c;
extern u32 data_0217d440;
extern u32 data_0217dda8;
extern Unk0212ccd4 data_0217ddd0;
extern Unk0212c400 data_0217d45c[16];
extern Unk0212c7a0 data_0217d89c[];
extern Unk02017328 data_0217dd1c;
extern Unk0212c8a4 data_0217dd28[];
extern s32 data_0217ddac;
extern Unk0200eb90 data_0217ddb0;
extern Unk0212c9d4 data_0217de24[8];
extern struct Unk0212d5f8 *data_0217dec4;
extern u8 data_0217d1e8[];
extern u8 data_0217d1ec[];
extern u8 data_0217d1f8[];
extern u8 data_0217d200[];
extern u8 data_0217d208[];
extern u8 data_0217d33c[];
extern u8 data_0217d340[];
extern u8 data_0217d404[];
extern u8 data_0217d410[];
extern struct Unk0212ef48 *data_0217df04;
extern u8 data_0217df08[];
extern u8 data_0217d070[];
extern Unk0212d9dc *data_0217d130;
extern u32 data_0217d1bc;
extern u8 data_0217d1c0[];
extern u8 data_0217d1c4[];
extern u8 data_0217d1c8[];
extern u8 data_0217d1cc[];
extern u8 data_0217d1d0[];
extern u32 data_0217d23c[];
