#pragma once

#include "types.h"
#include "00/code_02182fdc.h"
#include "01/code_02195a6c.h"
#include "01/code_0219c544.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02029520.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02117224.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0211de40.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"

// One 0x40-byte element of the arrays held by Unk021a9bf4.
typedef struct Unk021a9bf4Entry {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ u8 mUnk_08[0x38];
} Unk021a9bf4Entry;

// Object that holds a count at offset 6.
typedef struct Unk021a9bf4Count {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u16 mUnk_06;
} Unk021a9bf4Count;

// Object with a pointer at offset 0xc.
typedef struct Unk021a9bf4Block {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 *mUnk_0c;
} Unk021a9bf4Block;

// Object behind data_ov001_021a9bf4.
typedef struct Unk021a9bf4 {
    /* 00 */ void *mUnk_00;
    /* 04 */ Unk021a9bf4Count *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ Unk021a9bf4Count *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ Unk020b4a44 *mUnk_1c;
    /* 20 */ void *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ Unk021a9bf4Block *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ Unk021a9bf4Entry *mUnk_30;
    /* 34 */ Unk021a9bf4Entry *mUnk_34;
    /* 38 */ void *mUnk_38;
    /* 3c */ void *mUnk_3c;
    /* 40 */ void *mUnk_40;
    /* 44 */ void *mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ s32 mUnk_4c;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s16 mUnk_54[2];
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ u32 mUnk_64;
    /* 68 */ u32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
} Unk021a9bf4;

extern Unk021a9bf4 *data_ov001_021a9bf4;
extern u16 data_ov001_021a6b38[];
extern u16 data_ov001_021a6b3c[];
extern u16 data_ov001_021a6b40[];
extern u16 data_ov001_021a6b48[];
extern u16 data_ov001_021a6b54[];
extern u16 data_ov001_021a6b60[];
extern u16 data_ov001_021a6b6c[];
extern u32 data_ov001_021a6b78[];
extern u16 data_ov001_021a6b88[];
extern u32 data_ov001_021a6ba4[];

void func_ov001_0219bb48(u32 param_1, u32 param_2, u32 param_3);
void func_ov001_0219be5c(void);
void func_ov001_0219bfc0(void);
void func_ov001_0219bff4(void);
void func_ov001_0219c058(void);
void func_ov001_0219c0bc(void);
void func_ov001_0219c2a4(void);
void func_ov001_0219c358(void);
void func_ov001_0219c3a8(void);
void func_ov001_0219c3bc(void);
void func_ov001_0219c3d8(void);
void func_ov001_0219c3ec(void);
