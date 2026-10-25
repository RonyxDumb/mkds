#pragma once

#include "types.h"
#include "01/code_021987d4.h"
#include "01/code_0219a950.h"
#include "01/code_0219bb48.h"
#include "01/code_02193b1c.h"
#include "00/code_02182fdc.h"

// One 0x40-byte element of the arrays behind Unk021a9bf8::mUnk_1034.
typedef struct Unk021a9bf8Entry {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ u8 mUnk_08[0x38];
} Unk021a9bf8Entry;

// Object that holds a count at offset 6.
typedef struct Unk021a9bf8Count {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u16 mUnk_06;
} Unk021a9bf8Count;

// Allocated by func_ov001_0219d2c0 and held in data_ov001_021a9bf8.
typedef struct Unk021a9bf8 {
    /* 0000 */ s32 mUnk_00;
    /* 0004 */ s32 mUnk_04;
    /* 0008 */ s32 mUnk_08;
    /* 000c */ s32 mUnk_0c;
    /* 0010 */ s32 mUnk_10;
    /* 0014 */ s32 mUnk_14;
    /* 0018 */ s32 mUnk_18;
    /* 001c */ s32 mUnk_1c;
    /* 0020 */ s32 mUnk_20;
    /* 0024 */ s32 mUnk_24;
    /* 0028 */ u8 pad_28[8];
    /* 0030 */ u16 mUnk_30[64][32];
    /* 1030 */ void *mUnk_1030;
    /* 1034 */ Unk021a9bf8Entry *mUnk_1034[2];
    /* 103c */ void *mUnk_103c;
    /* 1040 */ void *mUnk_1040;
    /* 1044 */ Unk020b4934 *mUnk_1044;
    /* 1048 */ Unk020b4934 *mUnk_1048;
    /* 104c */ u8 pad_104c[8];
    /* 1054 */ Unk021a9bf8Count *mUnk_1054[2];
    /* 105c */ void *mUnk_105c[2];
    /* 1064 */ void *mUnk_1064[2];
    /* 106c */ Unk020b47d8 *mUnk_106c[3];
    /* 1078 */ void *mUnk_1078;
    /* 107c */ void *mUnk_107c;
    /* 1080 */ void *mUnk_1080;
    /* 1084 */ void *mUnk_1084;
} Unk021a9bf8;

// Four words set up by func_ov001_02180728.
typedef struct Unk02180728 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk02180728;

// Object that func_ov001_02180610 allocates and data_ov001_021a99e4 points to.
typedef struct Unk021a99e4 {
    /* 0000 */ s32 mUnk_0000;
    /* 0004 */ s32 mUnk_0004;
    /* 0008 */ s32 mUnk_0008;
    /* 000c */ void *mUnk_000c[3];
    /* 0018 */ u8 mUnk_0018[3][0x20];
    /* 0078 */ Unk02180728 mUnk_0078[3];
    /* 00a8 */ u16 mUnk_00a8[0x3000];
    /* 60a8 */ u16 mUnk_60a8[0x300];
} Unk021a99e4;

// Objects whose layout isn't known yet.
extern u8 data_ov001_021a9278[];
extern u8 data_ov001_021a927c[];
extern u8 data_ov001_021a9280[];
extern u8 data_ov001_021a9284[];
extern u8 data_ov001_021a928c[];
extern u8 data_ov001_021a9298[];
extern u8 data_ov001_021a929c[];
extern u8 data_ov001_021a92a0[];
extern u8 data_ov001_021a92a4[];
extern u8 data_ov001_021a92a8[];
extern u8 data_ov001_021a92ac[];
extern u8 data_ov001_021a92b0[];
extern u8 data_ov001_021a92bc[];
extern u8 data_ov001_021a92c0[];
extern u8 data_ov001_021a92c4[];
extern u8 data_ov001_021a9938[];
extern u8 data_ov001_021a993c[];
extern u8 data_ov001_021a9940[];
extern u8 data_ov001_021a9944[];
extern Unk021a99e4 *data_ov001_021a99e4;
extern u8 data_ov001_021a9b88[];
extern u16 data_ov001_021a9ba0;
extern u8 data_ov001_021a9b90[];
extern u8 data_ov001_021a9bd0[];
extern u8 data_ov001_021a9bec[];
extern Unk021a9bf8 *data_ov001_021a9bf8;
extern u8 data_ov001_021a9bfc[];
extern const char *data_ov001_021a90a8;
extern const char *data_ov001_021a90e4;
extern const char *data_ov001_021a90cc;
extern const char *data_ov001_021a90dc;
extern const char *data_ov001_021a90b8;
extern const char *data_ov001_021a90bc;
extern const char *data_ov001_021a90c8;
extern const char *data_ov001_021a90a4;
extern const char *data_ov001_021a90d8;
extern const char *data_ov001_021a90d4;
extern const char *data_ov001_021a90c4;
extern const char *data_ov001_021a90c0;
extern const char *data_ov001_021a94dc;
extern const char *data_ov001_021a94e0;
extern const char *data_ov001_021a94e4;
extern const char *data_ov001_021a94e8;
extern const char *data_ov001_021a94ec;
extern const char *data_ov001_021a94f0;
extern const char *data_ov001_021a94f4;
extern const char *data_ov001_021a94f8;
extern const char *data_ov001_021a94fc;
extern const char *data_ov001_021a9500;
extern const char *data_ov001_021a9504;
extern const char *data_ov001_021a9508;
extern const char *data_ov001_021a950c;
extern const char *data_ov001_021a9510;
extern s32 data_ov001_021a99e8;
extern u16 data_ov001_021a99ec[];
extern char data_ov001_021a94a4[];
extern char data_ov001_021a94b0[];
extern char data_ov001_021a94bc[];
extern char data_ov001_021a94d0[];
typedef struct Unk021a9be0 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk021a9bdcEntry *mUnk_0c;
    /* 10 */ u8 mUnk_10[8];
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ u8 mUnk_2c[4];
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
} Unk021a9be0;

extern Unk021a9be0 *data_ov001_021a9be0;
