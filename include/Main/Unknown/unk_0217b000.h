#pragma once

#include "types.h"
#include "code_0212da38.h" // Unk02017328
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_01ffdee4.h" // Unk0217b614
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/unk_02158000.h"

struct Unk020f41c4_B;
struct Unk0217b4f0;
struct Unk020d9cf4;
struct Unk020b47d8;
struct Unk020b4934;
struct Unk020b4a44;
struct Unk02022aa8;
struct Unk020a3fa8_a4;

// Element of 0x14 bytes of the table behind data_0217b704.
typedef struct Unk020de84c_14 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
} Unk020de84c_14;

// Element of 8 bytes of the table behind data_0217b708.
typedef struct Unk020de84c_08 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk020de84c_08;

// 8-byte elements of the table at member 0xc of Unk0217b498 (UnkPair020b502c of code_020b502c.h is this type).
typedef struct Unk0217b498_0c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0217b498_0c;

// 0x14-byte elements of the table at member 0x10 of Unk0217b498.
typedef struct Unk0217b498_10 {
    /* 00 */ Unk0217b498_0c mUnk_00;
    /* 08 */ struct Unk020224e0_c *mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u8 mUnk_12[2];
} Unk0217b498_10;

// Elements of the table at member 0 of Unk0217b498.
typedef struct Unk0217b498_00 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ u8 mUnk_10[0xc];
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u8 mUnk_20[0x5e];
    /* 7e */ u16 mUnk_7e;
} Unk0217b498_00;

// Object behind data_0217b3fc to data_0217b420, data_0217b42c to data_0217b434, data_0217b440 to data_0217b484,
// data_0217b48c, data_0217b494, data_0217b498, data_0217b4a0 and the ov001 pointers data_ov001_021a9b8c and
// data_ov001_021a9ba4 to data_ov001_021a9bc4 (func_020c0c2c and func_020c0ba8 allocate it, func_020c0b84 clears it).
typedef struct Unk0217b498 {
    /* 00 */ Unk0217b498_00 **mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ Unk0217b498_0c *mUnk_0c;
    /* 10 */ Unk0217b498_10 *mUnk_10;
} Unk0217b498;

// Object behind data_0217b4b4, 0x28 bytes; mUnk_18 points into mUnk_08.
typedef struct Unk0217b4b4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08[4];
    /* 18 */ s32 *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u16 mUnk_20;
    /* 22 */ u8 mUnk_22[2];
    /* 24 */ s32 mUnk_24;
} Unk0217b4b4;

// Object behind data_0217b4d8: the words at 0x00 to 0x0c.
typedef struct Unk0217b4d8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk0217b4d8;

// Object at data_0217b4f8: six vectors between words at 0x00/0x04 and 0x50/0x54.
typedef struct Unk0217b4f8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ Vec3 mUnk_08;
    /* 14 */ Vec3 mUnk_14;
    /* 20 */ Vec3 mUnk_20;
    /* 2c */ Vec3 mUnk_2c;
    /* 38 */ Vec3 mUnk_38;
    /* 44 */ Vec3 mUnk_44;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
} Unk0217b4f8;

// Object behind data_0217b438, 0x6c bytes (func_020ca6c4 allocates it); func_020ca9e4 calls the function at 0x0c.
typedef struct Unk0217b438 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ UnkFunc *mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ u8 mUnk_30[0x20];
    /* 50 */ u8 mUnk_50[0x10];
    /* 60 */ struct Unk020b4a44 *mUnk_60;
    /* 64 */ struct Unk020b4934 *mUnk_64;
    /* 68 */ struct Unk020b47d8 *mUnk_68;
} Unk0217b438;

// 16-byte rows of the table behind data_0217b4d4 (func_020d34e4 reads the halfwords).
typedef struct Unk0217b4d4 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
} Unk0217b4d4;

// Objects whose layout isn't known yet.
extern u8 data_0217b038[];
extern u8 data_0217b03c[];
struct Unk020184e4;

extern struct Unk020184e4 *data_0217b044;
extern u8 data_0217b04c[];
extern u8 data_0217b050[];
extern u8 data_0217b054[];
// Object behind data_0217b080, 0x60 bytes: 12-byte blocks at 0x00, 0x0c, 0x18 and 0x24.
typedef struct Unk0217b080 {
    /* 00 */ Unk02017328 mUnk_00;
    /* 0c */ Unk02017328 mUnk_0c[2];
    /* 24 */ Unk02017328 mUnk_24;
    /* 30 */ u8 mUnk_30[0x2c];
    /* 5c */ u16 mUnk_5c;
    /* 5e */ u8 mUnk_5e[2];
} Unk0217b080;

extern Unk0217b080 *data_0217b080;

// Object behind data_0217b08c, 0x38 bytes: 12-byte blocks at 0x00, 0x0c and 0x18.
typedef struct Unk0217b08c {
    /* 00 */ Unk02017328 mUnk_00;
    /* 0c */ Unk02017328 mUnk_0c;
    /* 18 */ Unk02017328 mUnk_18;
    /* 24 */ u8 mUnk_24[8];
    /* 2c */ void *mUnk_2c;
    /* 30 */ void *mUnk_30;
    /* 34 */ s32 mUnk_34;
} Unk0217b08c;

extern Unk0217b08c *data_0217b08c;

// The 0x10 bytes at 0x784 of Unk0217b034; the callbacks at 0x794 and 0x798 get their address.
typedef struct Unk0217b034_784 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ s32 mUnk_08;
    /* 0c */ u8 mUnk_0c[4];
} Unk0217b034_784;

// Object behind data_0217b034, 0x79c bytes.
typedef struct Unk0217b034 {
    /* 000 */ void *mUnk_000[9];
    /* 024 */ u8 mUnk_024[0x718];
    /* 73c */ s32 mUnk_73c;
    /* 740 */ u16 mUnk_740;
    /* 742 */ u16 mUnk_742;
    /* 744 */ u8 mUnk_744[0x40];
    /* 784 */ Unk0217b034_784 mUnk_784;
    /* 794 */ void (*mUnk_794)(Unk0217b034_784 *);
    /* 798 */ void (*mUnk_798)(Unk0217b034_784 *);
} Unk0217b034;

extern Unk0217b034 *data_0217b034;
extern u8 data_0217b0d8[];
extern u8 data_0217b118[];
extern u8 data_0217b11c[];
extern u8 data_0217b120[];
extern u8 data_0217b124[];
extern u8 data_0217b128[];
extern u8 data_0217b12c[];
extern u8 data_0217b130[];
extern u8 data_0217b134[];
extern u8 data_0217b138[];
extern u8 data_0217b13c[];
extern u8 data_0217b140[];
extern u8 data_0217b144[];
extern u8 data_0217b148[];
extern u8 data_0217b14c[];
extern u8 data_0217b150[];
extern u8 data_0217b154[];
extern u8 data_0217b158[];
extern u8 data_0217b15c[];
extern u8 data_0217b160[];
extern u8 data_0217b164[];
extern u8 data_0217b168[];
extern u8 data_0217b16c[];
extern u8 data_0217b170[];
extern u8 data_0217b1a4[];
// 0x70-byte entries of Unk0217b1fc, one per index 0 to 7.
typedef struct Unk0217b1fc_000 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24[8];
    /* 44 */ u16 mUnk_44;
    /* 46 */ u16 mUnk_46;
    /* 48 */ u16 mUnk_48;
    /* 4a */ u8 mUnk_4a[2];
    /* 4c */ s32 mUnk_4c;
    /* 50 */ u16 mUnk_50;
    /* 52 */ u8 mUnk_52[0x12];
    /* 64 */ s32 mUnk_64;
    /* 68 */ u8 mUnk_68[4];
    /* 6c */ s32 mUnk_6c;
} Unk0217b1fc_000;

// Object behind data_0217b1fc: eight 0x70-byte entries, then callbacks at 0x380 to 0x39c (set by func_020a2300 to
// func_020a2364) and the pointer at 0x3bc (func_020a238c / func_020a2378), whose 0x38-byte entries are read like
// Unk020a3fa8_a4.
typedef struct Unk0217b1fc {
    /* 000 */ Unk0217b1fc_000 mUnk_000[8];
    /* 380 */ s32 (*mUnk_380)(s32, s32);
    /* 384 */ void (*mUnk_384)(s32, s32);
    /* 388 */ s32 (*mUnk_388)(u16, u16);
    /* 38c */ void (*mUnk_38c)(u16);
    /* 390 */ void (*mUnk_390)(void);
    /* 394 */ u8 mUnk_394[8];
    /* 39c */ void (*mUnk_39c)(s32, s32);
    /* 3a0 */ u16 mUnk_3a0;
    /* 3a2 */ u16 mUnk_3a2;
    /* 3a4 */ u16 mUnk_3a4;
    /* 3a6 */ u8 mUnk_3a6[2];
    /* 3a8 */ s32 mUnk_3a8;
    /* 3ac */ s32 mUnk_3ac;
    /* 3b0 */ s32 mUnk_3b0;
    /* 3b4 */ s32 mUnk_3b4;
    /* 3b8 */ u16 mUnk_3b8;
    /* 3ba */ u8 mUnk_3ba[2];
    /* 3bc */ struct Unk020a3fa8_a4 *mUnk_3bc;
} Unk0217b1fc;

extern Unk0217b1fc *data_0217b1fc;
// 8-byte entries of the tables Unk0217b278 points to (func_020ab338 returns one).
typedef struct Unk0217b278_10 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ s16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk0217b278_10;

// Object behind Unk0217b278_1c::mUnk_04.
typedef struct Unk0217b278_1c_04 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[0xc];
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
} Unk0217b278_1c_04;

struct Unk0217b278;

// Set up by func_020aa028 (at 0x1c of Unk0217b278, which mUnk_2c then points to); mUnk_08 is called with the
// Unk0217b278 (func_020ab45c is one).
typedef struct Unk0217b278_1c {
    /* 00 */ Unk0217b278_10 *mUnk_00;
    /* 04 */ Unk0217b278_1c_04 *mUnk_04;
    /* 08 */ void (*mUnk_08)(struct Unk0217b278 *);
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
} Unk0217b278_1c;

// Four halfwords at 0x34 of Unk0217b278 (func_020ab59c, func_020ab5bc).
typedef struct Unk0217b278_34 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk0217b278_34;

// Object at data_0217b278, 0x54 bytes. data_0217b280, data_0217b294, data_0217b2ac and data_0217b2b8 are the
// addresses of its members at 0x08, 0x1c, 0x34 and 0x40.
typedef struct Unk0217b278 {
    /* 00 */ Unk0217b278_10 mUnk_00;
    /* 08 */ Unk0217b278_10 mUnk_08;
    /* 10 */ Unk0217b278_10 *mUnk_10;
    /* 14 */ Unk0217b278_10 *mUnk_14;
    /* 18 */ Unk0217b278_10 *mUnk_18;
    /* 1c */ Unk0217b278_1c mUnk_1c;
    /* 2c */ Unk0217b278_1c *mUnk_2c;
    /* 30 */ u16 *mUnk_30;
    /* 34 */ Unk0217b278_34 mUnk_34;
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u16 mUnk_3e;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u16 mUnk_42;
    /* 44 */ Unk0217b278_10 *mUnk_44;
    /* 48 */ u8 mUnk_48[4];
    /* 4c */ s32 (*mUnk_4c)(s32, u16);
    /* 50 */ s32 (*mUnk_50)(s32, s32);
} Unk0217b278;

extern Unk0217b278 data_0217b278;
extern u8 data_0217b280[];
extern u16 data_0217b2b8[2];
extern Unk0217b278_1c data_0217b294;
extern Unk0217b278_34 data_0217b2ac;
extern u8 data_0217b2d8[];
extern u16 *data_0217b318;
extern u16 *data_0217b328;
extern u16 *data_0217b32c;
extern u16 *data_0217b330;
// Object behind data_0217b334, 0x78 bytes, allocated in func_020abcf4. func_020aba9c passes the pointers at 0x00
// and 0x04 to func_0200ee74 with the words at 0x08 and 0x0c.
typedef struct Unk0217b334 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ struct Unk020b4934 *mUnk_10[5];
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ void *mUnk_28[6];
    /* 40 */ u16 *mUnk_40;
    /* 44 */ u16 mUnk_44;
    /* 46 */ u16 mUnk_46;
    /* 48 */ u16 mUnk_48;
    /* 4a */ u16 mUnk_4a;
    /* 4c */ s32 mUnk_4c;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s32 mUnk_74;
} Unk0217b334;

extern Unk0217b334 *data_0217b334;
extern void *data_0217b338;
extern u8 data_0217b340[];
extern u8 data_0217b344[];
// Object behind data_0217b350 (words from 0x828 to 0x910 read and written by func_020aeb7c). The pointers at 0x80c
// to 0x824 are written through func_020b4a7c, func_020b496c and func_020b4810.
typedef struct Unk0217b350 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ u8 mUnk_004[0x808];
    /* 80c */ struct Unk020b4a44 *mUnk_80c;
    /* 810 */ struct Unk020b4a44 *mUnk_810;
    /* 814 */ struct Unk020b4934 *mUnk_814;
    /* 818 */ struct Unk020b4934 *mUnk_818;
    /* 81c */ struct Unk020b47d8 *mUnk_81c;
    /* 820 */ struct Unk020b47d8 *mUnk_820;
    /* 824 */ struct Unk020b47d8 *mUnk_824;
    /* 828 */ s32 mUnk_828;
    /* 82c */ s32 mUnk_82c;
    /* 830 */ u8 mUnk_830[8];
    /* 838 */ s32 mUnk_838;
    /* 83c */ s32 mUnk_83c;
    /* 840 */ s32 mUnk_840;
    /* 844 */ u8 mUnk_844[8];
    /* 84c */ s32 mUnk_84c;
    /* 850 */ s32 mUnk_850;
    /* 854 */ u8 mUnk_854[0x44];
    /* 898 */ s32 mUnk_898;
    /* 89c */ u8 mUnk_89c[0x40];
    /* 8dc */ s32 mUnk_8dc;
    /* 8e0 */ s32 mUnk_8e0;
    /* 8e4 */ s32 mUnk_8e4;
    /* 8e8 */ s32 mUnk_8e8;
    /* 8ec */ s32 mUnk_8ec;
    /* 8f0 */ s32 mUnk_8f0;
    /* 8f4 */ s32 mUnk_8f4;
    /* 8f8 */ s32 mUnk_8f8;
    /* 8fc */ s32 mUnk_8fc;
    /* 900 */ s32 mUnk_900;
    /* 904 */ s32 mUnk_904;
    /* 908 */ s32 mUnk_908;
    /* 90c */ s32 mUnk_90c;
    /* 910 */ s32 mUnk_910;
} Unk0217b350;

extern Unk0217b350 *data_0217b350;
extern u8 data_0217b354[];
extern u8 data_0217b3c4[];
extern u8 data_0217b3d8[];
// Object behind data_0217b3dc, 0x25c bytes, allocated by func_020beb9c.
typedef struct Unk0217b3dc {
    /* 000 */ u16 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ s32 mUnk_00c;
    /* 010 */ void (*mUnk_010[49])(void);
    /* 0d4 */ void (*mUnk_0d4[49])(void);
    /* 198 */ void (*mUnk_198[49])(void *);
} Unk0217b3dc;

extern Unk0217b3dc *data_0217b3dc;
// Object behind data_0217b3e0, 0x20e4 bytes, allocated by func_020c3200.
typedef struct Unk0217b3e0 {
    /* 0000 */ s32 mUnk_0000[8];
    /* 0020 */ s32 mUnk_0020[8];
    /* 0040 */ s32 mUnk_0040[8];
    /* 0060 */ s32 mUnk_0060[8];
    /* 0080 */ s32 mUnk_0080[8];
    /* 00a0 */ s32 mUnk_00a0;
    /* 00a4 */ s32 mUnk_00a4;
    /* 00a8 */ s32 mUnk_00a8;
    /* 00ac */ void *mUnk_00ac;
    /* 00b0 */ s32 mUnk_00b0;
    /* 00b4 */ s32 mUnk_00b4;
    /* 00b8 */ struct Unk020b4a44 *mUnk_00b8;
    /* 00bc */ struct Unk020b4934 *mUnk_00bc;
    /* 00c0 */ struct Unk020b47d8 *mUnk_00c0[6];
    /* 00d8 */ u16 mUnk_00d8[2][0x800];
    /* 20d8 */ s32 mUnk_20d8;
    /* 20dc */ s32 mUnk_20dc;
    /* 20e0 */ s32 mUnk_20e0;
} Unk0217b3e0;

extern Unk0217b3e0 *data_0217b3e0;
extern struct Unk0217b3e8 *data_0217b3e8;
extern u8 data_0217b3f0[];
extern u8 data_0217b3f4[];
extern Unk0217b438 *data_0217b438;
extern u8 data_0217b43c[];
extern struct Unk0217b4a4 *data_0217b4a4;
extern struct Unk0217b4b0 *data_0217b4b0;
extern struct Unk020f41c4_B *data_0217b4b8;
extern struct Unk020f41c4_B *data_0217b4bc;
extern Unk0217b4d8 *data_0217b4d8;
extern Vec3 *data_0217b4dc;
extern s32 data_0217b4e0;
extern struct Unk020d9cf4 *data_0217b4e4;
extern s32 data_0217b4ec;
extern struct Unk0217b4f0 *data_0217b4f0;
extern s32 data_0217b4f4;
extern Unk0217b4f8 data_0217b4f8;
extern Unk0217b4f8 data_0217b550;
extern struct Unk0217b650 *data_0217b650;
extern struct Unk0217b654 *data_0217b654;
extern struct Unk020ea868 *data_0217b658;
extern struct Unk020ea670 *data_0217b65c;
extern struct Unk020d7b88 data_0217b660;
extern struct Unk020e0144_00 *data_0217b670;
extern struct Unk020db20c *data_0217b680;
extern struct Unk020db1b0 *data_0217b684;
extern Unk020e6488 *data_0217b688;
extern struct Unk020ea670 *data_0217b68c;
extern struct Unk020dbe74 *data_0217b690;
extern struct Unk020ea868 *data_0217b694;
extern struct Unk020dbed0 *data_0217b698;
extern Unk020e6b58 data_0217b69c;
extern struct Unk020ea670 *data_0217b6cc;
extern struct Unk020ea868 *data_0217b6d0;
extern Unk020de334 *data_0217b6dc;
extern Unk020de2d8 *data_0217b6e0;
extern Unk020e6488 *data_0217b6e4;
extern Unk020e6488 *data_0217b6e8;
extern Unk020de2d8 *data_0217b6ec;
extern Unk020e6488 *data_0217b6f0;
extern Unk020e6488 *data_0217b6f4;
extern Unk020de334 *data_0217b6f8;
extern u16 data_0217b6fc;
extern Unk020de334 *data_0217b700;
extern Unk020de84c_14 *data_0217b704;
extern Unk020de84c_08 *data_0217b708;
extern Unk020de334 *data_0217b70c;
extern Unk020e6488 *data_0217b710;
extern Unk020de334 *data_0217b714;
extern Unk020de2d8 *data_0217b718;
extern Unk020e6488 *data_0217b71c;
extern Unk020e6b58 data_0217b720;
extern u16 data_0217b750;
extern s32 data_0217b754;
extern Unk020de2d8 *data_0217b758;
extern s32 data_0217b75c;
extern Vec3 data_0217b760;
extern Unk020dfc44 *data_0217b76c;
extern void *data_0217b770;
extern Unk020de334 *data_0217b774;
extern void *data_0217b778;
extern void *data_0217b77c;
extern Unk020e6488 *data_0217b7b8;
extern Unk020e6488 *data_0217b7f0;
extern Unk020e53ac *data_0217b814;
extern Unk020e6488 *data_0217b830;
extern Unk020e6b58 *data_0217b844;
extern Unk020e6b58 *data_0217b848;
extern Unk020e6b58 *data_0217b84c;
extern Unk020e6b58 *data_0217b850;
extern Unk020e6b58 *data_0217b854;
extern u8 data_0217b858[];
extern Unk020e6b58 *data_0217b85c;
extern Unk020e6b58 *data_0217b860;
extern u8 data_0217b868[];
extern s32 data_0217bc5c;
extern s32 data_0217bc60;

extern u8 data_0217b220[];
extern u8 data_0217b358[];
extern u8 data_0217b35c[];
extern u8 data_0217b3c8[];
extern u8 data_0217b3cc[];
extern u8 data_0217b3d0[];
extern u8 data_0217b3d4[];
// 0x18-byte elements of the tables at member 0x10 of Unk0217b3e4.
typedef struct Unk0217b3e4_10 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u8 mUnk_0e[2];
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
} Unk0217b3e4_10;

// 0x40-byte elements of the table at member 0x790 of Unk0217b3e4.
typedef struct Unk0217b3e4_790 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Vec3 mUnk_04[3];
    /* 28 */ s32 mUnk_28[3];
    /* 34 */ s32 mUnk_34[3];
} Unk0217b3e4_790;

// 0x10-byte elements of the table at member 0x810 of Unk0217b3e4.
typedef struct Unk0217b3e4_810 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk0217b3e4_810;

// Object behind data_0217b3e4, 0x910 bytes, allocated by func_020c4780.
typedef struct Unk0217b3e4 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004[2];
    /* 00c */ s32 mUnk_00c;
    /* 010 */ Unk0217b3e4_10 mUnk_010[2][0x28];
    /* 790 */ Unk0217b3e4_790 mUnk_790[2];
    /* 810 */ Unk0217b3e4_810 mUnk_810[16];
} Unk0217b3e4;

extern Unk0217b3e4 *data_0217b3e4;
// Object behind data_0217b3ec.
typedef struct Unk0217b3ec {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
} Unk0217b3ec;

extern Unk0217b3ec *data_0217b3ec;
extern u8 data_0217b424[];
extern struct Unk0217b49c *data_0217b49c;
extern u8 data_0217b4a8[];
extern struct Unk0217b4ac *data_0217b4ac;
extern Unk0217b4b4 *data_0217b4b4;
extern u16 data_0217b4c0;
extern u16 data_0217b4c4;
extern u16 data_0217b4c8;
extern u16 data_0217b4cc;
extern u16 data_0217b4d0;
extern Unk0217b4d4 *data_0217b4d4;
extern Unk020e71a0 **data_0217b4e8;
extern u8 data_0217b7c4[];
extern u8 data_0217b86c[];
extern Unk020e6488 *data_0217bbfc[];
struct Unk020f41c4_A;

extern struct Unk020f41c4_A **data_0217bd30;

extern u8 data_0217b040[];
extern s32 data_0217b234;
extern s32 data_0217b238;
extern u16 *data_0217b23c[2];
extern u16 *data_0217b244[2];
extern u16 *data_0217b24c[2];
// Object at data_0217b254, 0x24 bytes.
typedef struct Unk0217b254 {
    /* 00 */ struct Unk02022aa8 *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u16 *mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} Unk0217b254;

extern Unk0217b254 data_0217b254;
extern u8 data_0217b368[];
extern u8 data_0217b370[];
extern u8 data_0217b378[];
extern u8 data_0217b380[];
extern u8 data_0217b388[];
extern u8 data_0217b390[];
extern Unk0217b498 *data_0217b3fc;
extern Unk0217b498 *data_0217b400;
extern Unk0217b498 *data_0217b404;
extern Unk0217b498 *data_0217b408;
extern Unk0217b498 *data_0217b40c;
extern Unk0217b498 *data_0217b410;
extern Unk0217b498 *data_0217b414;
extern Unk0217b498 *data_0217b418;
extern Unk0217b498 *data_0217b41c;
extern Unk0217b498 *data_0217b420;
extern Unk0217b498 *data_0217b42c;
extern Unk0217b498 *data_0217b430;
extern Unk0217b498 *data_0217b434;
extern Unk0217b498 *data_0217b440;
extern Unk0217b498 *data_0217b444;
extern Unk0217b498 *data_0217b448;
extern Unk0217b498 *data_0217b44c;
extern Unk0217b498 *data_0217b450;
extern Unk0217b498 *data_0217b454;
extern Unk0217b498 *data_0217b458;
extern Unk0217b498 *data_0217b45c;
extern Unk0217b498 *data_0217b460;
extern Unk0217b498 *data_0217b464;
extern Unk0217b498 *data_0217b468;
extern Unk0217b498 *data_0217b46c;
extern Unk0217b498 *data_0217b470;
extern Unk0217b498 *data_0217b474;
extern Unk0217b498 *data_0217b478;
extern Unk0217b498 *data_0217b47c;
extern Unk0217b498 *data_0217b480;
extern Unk0217b498 *data_0217b484;
extern Unk0217b498 *data_0217b48c;
extern u8 data_0217b490[];
extern Unk0217b498 *data_0217b494;
extern Unk0217b498 *data_0217b498;
extern Unk0217b498 *data_0217b4a0;
extern s32 data_0217b890;
extern s32 data_0217b8ac;
extern s32 data_0217b8c4;
extern s32 data_0217b8e4;
extern s32 data_0217b900;

// Object whose halfword at 0xe is read by func_020e9d10.
typedef struct Unk0217b9ec {
    /* 000 */ u8 mUnk_000[0xe];
    /* 00e */ u16 mUnk_00e;
} Unk0217b9ec;

extern Unk0217b9ec data_0217b9ec;
extern Vec3 *data_0217bc4c;
extern void *data_0217b7d0;
extern void *data_0217b7cc;
extern void *data_0217b7c0;
extern void *data_0217b7bc;
extern void *data_0217b7b4;
extern void *data_0217b780;
extern void *data_0217b784;
extern void *data_0217b788;
extern void *data_0217b78c;
extern void *data_0217b790;
extern void *data_0217b794;
extern void *data_0217b798;
extern void *data_0217b79c;
extern void *data_0217b7a0;
extern void *data_0217b7a4;
extern void *data_0217b7a8;
extern void *data_0217b7ac;
extern void *data_0217b7b0;
extern void *data_0217b7c8;
extern void *data_0217b7d4;
extern void *data_0217b7d8;
extern void *data_0217b7e0;
extern void *data_0217b7e4;
extern void *data_0217b7e8;
extern void *data_0217b7ec;
extern void **data_0217b5c4;
extern s16 data_0217b5a8;
extern u16 *data_0217b5bc;
extern s16 data_0217b5ac;
extern s16 data_0217b5b0;
extern struct Unk0217b5b4 *data_0217b5b4;
extern struct Unk0217b5b8 *data_0217b5b8;
extern struct Unk0217b5b4 *data_0217b5c0;
extern s16 *data_0217b5c8;
extern s16 *data_0217b5cc;
extern Vec3 data_0217b800;
extern void *data_0217b838;
extern void *data_0217b83c;
extern void *data_0217b820;
extern void *data_0217b864;
extern s32 data_0217b8b4;
extern u16 data_0217b884;
extern u16 data_0217b880;
extern u16 data_0217b888;
extern u16 data_0217b870;
extern u16 data_0217b87c;
extern s32 data_0217b8b8;
extern s32 data_0217b88c;
extern s32 data_0217b8cc;
extern s32 data_0217b8ec;
extern s32 data_0217b8f0;
extern s32 data_0217b8bc;
extern s32 data_0217b894;
extern s32 data_0217b8f8;
extern s32 data_0217b8b0;
extern u16 *data_0217b8c0;
extern Vec3 data_0217b9c0;
extern Vec3 data_0217b90c;
extern Vec3 data_0217b918;
extern Vec3 data_0217b93c;
extern Vec3 data_0217b99c;
extern Vec3 data_0217b930;
extern Vec3 data_0217b948;
extern Vec3 data_0217b9b4;
extern Vec3 data_0217b924;
extern Vec3 data_0217bb28[];
extern s16 *data_0217b8a4;
extern s16 *data_0217b8a8;
extern s16 *data_0217b8a0;
extern s16 *data_0217b8e0;
extern s16 *data_0217b904;
extern s32 data_0217b8e8;
extern u32 data_0217bb04[];
extern Vec3 data_0217b96c;
extern s32 data_0217b8d0;
extern s32 data_0217b898;
extern s32 data_0217b89c;
extern s32 data_0217b8d8;
extern s32 data_0217b908;
extern Vec3 data_0217b954;
extern Vec3 data_0217b960;
extern Vec3 data_0217b978;
extern Vec3 data_0217b984;
extern Vec3 data_0217bb7c;
extern Vec3 data_0217bb34;
extern Vec3 data_0217bb40;
extern Vec3 *data_0217b9cc[4];
extern u16 data_0217b874;
extern u16 data_0217b878;
extern Vec3 data_0217b990;
extern Vec3 data_0217b9a8;
extern void *data_0217b5d0[16];
extern s32 data_0217b610;
extern Unk0217b614 data_0217b614;
extern u32 data_0217bbe8;
extern Vec3 data_0217bad0;
extern Vec3 data_0217badc;
extern Vec3 data_0217bac4;
extern Vec3 data_0217ba7c;
extern s32 data_0217b8d4;
extern s32 data_0217b8dc;
extern s32 data_0217b8f4;
extern u32 data_0217b8fc;
extern s32 data_0217bce8[];
extern s32 data_0217bc58;
extern s32 data_0217bca0[];
extern u16 data_0217bc54;
extern u16 data_0217bc50;
extern u16 data_0217bc7c[];
extern s32 data_0217bd3c;
extern s32 data_0217bd40;
extern s32 data_0217bd44;
extern volatile s32 data_0217bd34;
extern s32 data_0217bd48;
extern s32 data_0217bd4c;
extern s32 data_0217bd50;
extern s32 data_0217bd54;
extern s32 data_0217bd58;
extern u8 data_0217bd5c[];
extern u8 data_0217bd60[];
extern u8 data_0217bd64[];
extern u8 data_0217bd68[];
extern u8 data_0217bd80[];
extern u8 data_0217bdc0[];
extern u8 data_0217bd6c[];
extern u8 data_0217bdc1[];
extern u8 data_0217bd81[];
extern void *data_0217b224;
extern void *data_0217b1f8;
