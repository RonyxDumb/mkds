#pragma once

#include "types.h"

#include "code_0212c478.h" // Unk0212c400
#include "code_0212c7a0.h" // Unk0212c7a0
#include "code_0212c7f0.h" // Unk0212c8a4
#include "code_0212c9d4.h" // Unk0212ccd4, Unk0212c9d4
#include "code_0200e904.h" // Unk0200eb90
#include "code_0212da38.h" // Unk02017328, Unk0212d9dc

// Object behind data_0217d358.
typedef struct Unk0217d358 {
    /* 00 */ u8 *mUnk_00;
} Unk0217d358;

struct Unk020b4a44;

// Object behind data_0217d35c: 0x18 bytes allocated by func_021172a8; members 0x0, 0x4 and 0x8 + 4 * i are filled
// through func_020b49bc, func_020b48b4 and func_020b4a44.
typedef struct Unk0217d35c {
    /* 00 */ struct Unk020b4934 *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ struct Unk020b4a44 *mUnk_08[3];
    /* 14 */ void *mUnk_14;
} Unk0217d35c;

struct Unk0212d5f8;
struct Unk0212ef48;
struct Unk020b4934;
struct Unk020b4a44;
struct Unk020b47d8;
struct Unk0201ea30;

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
    /* 6c */ s32 mUnk_6c;
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

// Object behind data_0217d36c.
typedef struct Unk0217d36c {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
} Unk0217d36c;

// Object at data_0217d070 (0x14 bytes); func_0210d740 fills it. data_0217d07c names its member 0x0c.
typedef struct Unk0217d070 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b;
    /* 0c */ Unk0212c400 *mUnk_0c;
    /* 10 */ Unk0212c400 *mUnk_10;
} Unk0217d070;

// Object at data_0217d084 (0x1c bytes); func_0210dc60 stores its second argument at 0x00.
typedef struct Unk0217d084 {
    /* 00 */ Unk0217d070 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ Unk0212c400 **mUnk_18;
} Unk0217d084;

// Object at data_0217d32c (0x10 bytes); mUnk_08 points to a row of six words.
typedef struct Unk0217d32c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Unk0212d9dc *mUnk_04;
    /* 08 */ u32 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0217d32c;

// Object behind data_0217d348.
typedef struct Unk0217d348 {
    /* 00 */ struct Unk020b4934 *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ Unk0217d350_30 *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ struct Unk020b47d8 *mUnk_10;
    /* 14 */ Unk0217d350_3c *mUnk_14;
    /* 18 */ Unk0217d350_30 *mUnk_18;
    /* 1c */ void *mUnk_1c;
    /* 20 */ struct Unk020b47d8 *mUnk_20;
    /* 24 */ Unk0217d350_3c *mUnk_24;
    /* 28 */ struct Unk020b4934 *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ Unk0217d350_30 *mUnk_30;
    /* 34 */ struct Unk0201ea30 *mUnk_34;
    /* 38 */ void *mUnk_38;
    /* 3c */ Unk0217d350_3c *mUnk_3c;
    /* 40 */ s32 mUnk_40;
    /* 44 */ void *mUnk_44;
    /* 48 */ void *mUnk_48;
    /* 4c */ s32 mUnk_4c;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s16 mUnk_68;
    /* 6a */ s16 mUnk_6a;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s16 mUnk_74;
    /* 76 */ u8 mUnk_76[2];
    /* 78 */ void *mUnk_78;
    /* 7c */ void *mUnk_7c;
    /* 80 */ s32 mUnk_80[2];
    /* 88 */ s32 mUnk_88;
    /* 8c */ s32 mUnk_8c;
    /* 90 */ s32 mUnk_90;
} Unk0217d348;

// Object behind data_0217d360.
typedef struct Unk0217d360 {
    /* 00 */ void *mUnk_00;
    /* 04 */ Unk0217d350_30 *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ struct Unk0201ea30 *mUnk_14;
    /* 18 */ Unk0217d350_3c *mUnk_18;
    /* 1c */ Unk0217d350_3c *mUnk_1c;
    /* 20 */ void *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ void *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s32 mUnk_40;
    /* 44 */ s32 mUnk_44;
    /* 48 */ s32 mUnk_48[8];
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s32 mUnk_74;
    /* 78 */ s16 mUnk_78;
    /* 7a */ u8 mUnk_7a[2];
    /* 7c */ s32 mUnk_7c;
    /* 80 */ void *mUnk_80;
    /* 84 */ void *mUnk_84;
    /* 88 */ s32 mUnk_88;
} Unk0217d360;

// Object behind data_0217d364.
typedef struct Unk0217d364 {
    /* 00 */ void *mUnk_00;
    /* 04 */ Unk0217d350_30 *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ Unk0217d350_30 *mUnk_10;
    /* 14 */ struct Unk0201ea30 *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ Unk0217d350_3c *mUnk_1c;
    /* 20 */ Unk0217d350_3c *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ void *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ void *mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s32 mUnk_40;
    /* 44 */ s32 mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ u8 mUnk_4c[4];
    /* 50 */ s16 mUnk_50;
    /* 52 */ u8 mUnk_52[2];
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s16 mUnk_5c;
    /* 5e */ u8 mUnk_5e[2];
    /* 60 */ s32 mUnk_60;
    /* 64 */ void *mUnk_64;
    /* 68 */ void *mUnk_68;
    /* 6c */ s32 mUnk_6c;
} Unk0217d364;

// Object behind data_0217d368, and the objects its mUnk_04, mUnk_14 and mUnk_20 members point to.
typedef struct Unk0217d368_04 {
    /* 00 */ u8 mUnk_00[0x06];
    /* 06 */ u16 mUnk_06;
} Unk0217d368_04;

typedef struct Unk0217d368_14 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ u8 mUnk_08[0x38];
} Unk0217d368_14;

typedef struct Unk0217d368_20 {
    /* 00 */ u8 mUnk_00[0x0c];
    /* 0c */ u16 mUnk_0c;
} Unk0217d368_20;

typedef struct Unk0217d368 {
    /* 00 */ void *mUnk_00;
    /* 04 */ Unk0217d368_04 *mUnk_04;
    /* 08 */ struct Unk0201ea30 *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ Unk0217d368_14 *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ void *mUnk_1c;
    /* 20 */ Unk0217d368_20 *mUnk_20;
    /* 24 */ u8 mUnk_24[0x04];
    /* 28 */ void *mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s16 mUnk_3c[5][2];
    /* 50 */ s16 mUnk_50[2][2];
    /* 58 */ s16 mUnk_58;
    /* 5a */ u8 mUnk_5a[0x02];
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68[4];
    /* 78 */ s32 mUnk_78;
    /* 7c */ s32 mUnk_7c;
    /* 80 */ s32 mUnk_80;
    /* 84 */ u32 mUnk_84;
    /* 88 */ s16 mUnk_88;
    /* 8a */ s16 mUnk_8a;
    /* 8c */ u32 mUnk_8c[8];
    /* ac */ u16 mUnk_ac[2];
    /* b0 */ u16 mUnk_b0[2];
    /* b4 */ void *mUnk_b4;
    /* b8 */ vu32 mUnk_b8;
} Unk0217d368;

// Object behind data_0217d37c (0x10 bytes), allocated by func_0211f2b8.
typedef struct Unk0217d37c {
    /* 00 */ struct Unk020b4934 *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ struct Unk020b4a44 *mUnk_08;
    /* 0c */ void *mUnk_0c;
} Unk0217d37c;

// Object behind data_0217d380 (0x28 bytes), allocated by func_0211f4b0.
typedef struct Unk0217d380 {
    /* 00 */ void *mUnk_00;
    /* 04 */ Unk0217d350_30 *mUnk_04;
    /* 08 */ u8 mUnk_08[0x4];
    /* 0c */ void *mUnk_0c;
    /* 10 */ Unk0217d350_3c *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
} Unk0217d380;

// Object at data_0217d244 (0x10 bytes).
typedef struct Unk0217d244 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0217d244;

// Object at data_0217d2a4.
typedef struct Unk0217d2a4 {
    /* 00 */ s32 mUnk_00[14];
    /* 38 */ s32 mUnk_38[14];
    /* 70 */ s32 mUnk_70;
    /* 74 */ s32 mUnk_74;
    /* 78 */ s32 mUnk_78;
} Unk0217d2a4;

// Object behind data_0217d374, allocated by func_0211e480.
typedef struct Unk0217d374 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ u8 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ s16 mUnk_10;
} Unk0217d374;

// Objects the mUnk_04, mUnk_10, mUnk_18 and mUnk_1c members of data_0217d378 point to.
typedef struct Unk0217d378_18 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x02];
    /* 06 */ s16 mUnk_06;
    /* 08 */ u8 mUnk_08[0x38];
} Unk0217d378_18;

// Object behind data_0217d378, allocated by func_0211e958.
typedef struct Unk0217d378 {
    /* 00 */ void *mUnk_00;
    /* 04 */ Unk0217d378_18 *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ Unk0217d378_18 *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ Unk0217d378_18 *mUnk_18;
    /* 1c */ Unk0217d378_18 *mUnk_1c;
    /* 20 */ void *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ void *mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s32 mUnk_40;
    /* 44 */ u8 mUnk_44[0x04];
    /* 48 */ void *mUnk_48;
    /* 4c */ void *mUnk_4c;
    /* 50 */ s32 mUnk_50;
} Unk0217d378;


// Halfword objects behind data_0217d34c member 0x4.
typedef struct Unk0217d34c_04 {
    /* 00 */ u16 mUnk_00;
} Unk0217d34c_04;

// Object behind data_0217d34c.
typedef struct Unk0217d34c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ Unk0217d34c_04 *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
} Unk0217d34c;

// Objects whose layout isn't known yet.
extern u8 data_0217d014[];
extern u8 data_0217d018[];
extern u8 data_0217d01c[];
extern u8 data_0217d028[];
extern u32 data_0217d064;
extern u8 data_0217d134[];
extern u8 data_0217d178[];
extern s32 data_0217d1f4;
extern s32 data_0217d20c;
extern s32 data_0217d21c;
extern u32 data_0217d220;
extern Unk0217d244 data_0217d244;
extern struct Unk0217d344 *data_0217d344;
extern Unk0217d350 *data_0217d350;
extern Unk0217d354 *data_0217d354;
extern Unk0217d358 *data_0217d358;
extern Unk0217d35c *data_0217d35c;
extern Unk0217d368 *data_0217d368;
extern Unk0217d36c *data_0217d36c;
extern u8 data_0217d370[];
extern Unk0217d374 *data_0217d374;
extern Unk0217d378 *data_0217d378;
extern Unk0217d37c *data_0217d37c;
extern Unk0217d380 *data_0217d380;
extern u8 data_0217d3ec[];
extern u8 data_0217d3f0[];
extern u8 data_0217d3f4[];
extern u8 data_0217d3f8[];
extern u8 data_0217d3fc[];
extern u8 data_0217d400[];
extern u8 data_0217d408[];
extern u32 data_0217d1f0;
extern s32 data_0217d22c[];
extern s32 data_0217d320;
extern s32 data_0217d324;
extern s32 data_0217d328;
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
extern s32 data_0217d1e8;
extern s32 data_0217d1ec;
extern s32 data_0217d1f8;
extern s32 data_0217d200;
extern s32 data_0217d208;
extern u8 data_0217d1e0;
extern u8 data_0217d1e4;
extern s32 data_0217d1fc;
extern u32 data_0217d204;
extern s32 data_0217d210;
extern s32 data_0217d214;
extern s32 data_0217d218;
extern s32 data_0217d224[2];
extern Unk0217d2a4 data_0217d2a4;
extern void *data_0217d33c;
extern void *data_0217d340;
extern u8 data_0217d404[];
extern u8 data_0217d410[];
extern struct Unk0212ef48 *data_0217df04;
extern u8 data_0217df08[];
extern Unk0212d9dc *data_0217d130;
extern Unk0217d070 data_0217d070;
// The member at 0x0c of data_0217d070, addressed through a pool word of its own.
extern Unk0212c400 *data_0217d07c;
extern Unk0217d084 data_0217d084;
extern struct Unk0212d5f8 data_0217d0a0;
extern Unk0217d32c data_0217d32c;
extern Unk0217d348 *data_0217d348;
extern Unk0217d34c *data_0217d34c;
extern Unk0217d360 *data_0217d360;
extern Unk0217d364 *data_0217d364;
extern u32 data_0217d1bc;
extern u8 data_0217d1c0[];
extern u8 data_0217d1c4[];
extern u8 data_0217d1c8[];
extern u8 data_0217d1cc[];
extern u8 data_0217d1d0[];
extern u32 data_0217d23c[];
extern u32 data_0217d010[];
extern u32 data_0217d024[];
extern u8 data_0217d034[];
extern u8 data_0217d048[];
extern u8 data_0217d054[];
extern u32 data_0217d020;
extern void *data_0217d06c;
