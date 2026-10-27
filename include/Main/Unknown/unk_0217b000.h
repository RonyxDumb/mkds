#pragma once

#include "types.h"
#include "Main/Unknown/code_020e5d0c.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_01ffdee4.h" // Unk0217b614
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/unk_02158000.h"

struct Unk020f41c4_B;
struct Unk0217b4f0;

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

// 0x14-byte elements of the table at member 0x10 of Unk0217b498.
typedef struct Unk0217b498_10 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u8 mUnk_12[2];
} Unk0217b498_10;

// 8-byte elements of the table at member 0xc of Unk0217b498.
typedef struct Unk0217b498_0c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0217b498_0c;

// Elements of the table at member 0 of Unk0217b498.
typedef struct Unk0217b498_00 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ u8 mUnk_10[0xc];
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u8 mUnk_20[0x5e];
    /* 7e */ u16 mUnk_7e;
} Unk0217b498_00;

// Object behind data_0217b498.
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

// Object behind data_0217b4e4.
typedef struct Unk0217b4e4 {
    /* 000 */ u8 mUnk_000[4];
    /* 004 */ s32 mUnk_004;
    /* 008 */ u8 mUnk_008[0x24];
    /* 02c */ u16 mUnk_02c;
    /* 02e */ u8 mUnk_02e[2];
    /* 030 */ s32 mUnk_030;
    /* 034 */ u8 mUnk_034[0x13c];
    /* 170 */ s32 mUnk_170;
} Unk0217b4e4;

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
extern u8 data_0217b044[];
extern u8 data_0217b04c[];
extern u8 data_0217b050[];
extern u8 data_0217b054[];
extern u8 data_0217b08c[];
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
extern u8 data_0217b1fc[];
extern u8 data_0217b278[];
extern u8 data_0217b280[];
extern u8 data_0217b2b8[];
extern u8 data_0217b2d8[];
extern u8 data_0217b318[];
extern u8 data_0217b328[];
extern u8 data_0217b32c[];
extern u8 data_0217b330[];
extern u8 data_0217b334[];
extern u8 data_0217b340[];
extern u8 data_0217b344[];
extern u8 data_0217b350[];
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
extern u8 data_0217b3e0[];
extern u8 data_0217b3e8[];
extern u8 data_0217b3f0[];
extern u8 data_0217b3f4[];
extern u8 data_0217b438[];
extern u8 data_0217b43c[];
extern struct Unk0217b4a4 *data_0217b4a4;
extern struct Unk0217b4b0 *data_0217b4b0;
extern struct Unk020f41c4_B *data_0217b4b8;
extern struct Unk020f41c4_B *data_0217b4bc;
extern Unk0217b4d8 *data_0217b4d8;
extern Vec3 *data_0217b4dc;
extern s32 data_0217b4e0;
extern Unk0217b4e4 *data_0217b4e4;
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
extern u8 data_0217b3e4[];
extern u8 data_0217b3ec[];
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
extern u8 data_0217b234[];
extern u8 data_0217b238[];
extern u8 data_0217b254[];
extern u8 data_0217b368[];
extern u8 data_0217b370[];
extern u8 data_0217b378[];
extern u8 data_0217b380[];
extern u8 data_0217b388[];
extern u8 data_0217b390[];
extern u8 data_0217b3fc[];
extern u8 data_0217b400[];
extern u8 data_0217b404[];
extern u8 data_0217b408[];
extern u8 data_0217b40c[];
extern u8 data_0217b410[];
extern u8 data_0217b414[];
extern u8 data_0217b418[];
extern u8 data_0217b41c[];
extern u8 data_0217b420[];
extern u8 data_0217b42c[];
extern u8 data_0217b430[];
extern u8 data_0217b434[];
extern u8 data_0217b440[];
extern u8 data_0217b444[];
extern u8 data_0217b448[];
extern u8 data_0217b44c[];
extern u8 data_0217b450[];
extern u8 data_0217b454[];
extern u8 data_0217b458[];
extern u8 data_0217b45c[];
extern u8 data_0217b460[];
extern u8 data_0217b464[];
extern u8 data_0217b468[];
extern u8 data_0217b46c[];
extern u8 data_0217b470[];
extern u8 data_0217b474[];
extern u8 data_0217b478[];
extern u8 data_0217b47c[];
extern u8 data_0217b480[];
extern u8 data_0217b484[];
extern u8 data_0217b48c[];
extern u8 data_0217b490[];
extern u8 data_0217b494[];
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
