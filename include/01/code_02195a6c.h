#pragma once

#include "code_021458c4.h"
#include "types.h"
#include "01/code_02196da8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0212426c.h"
#include "00/code_02182fdc.h"
#include "01/code_02196e30.h"
#include "code_0212df7c.h"

// Object behind data_ov001_021a9bdc.
typedef struct Unk021a9bdc {
    /* 00 */ Unk020b4934 *mUnk_00;
    /* 04 */ struct Unk02021dc8 *mUnk_04;
    /* 08 */ Unk0201ea30 *mUnk_08;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ Unk0201ea30 *mUnk_10;
    /* 14 */ Unk020b4934 *mUnk_14;
    /* 18 */ struct Unk02021dc8 *mUnk_18;
    /* 1c */ Unk0201ea30 *mUnk_1c;
    /* 20 */ void *mUnk_20;
    /* 24 */ Unk0201ea30 *mUnk_24;
    /* 28 */ void *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ Unk020b4a44 *mUnk_30;
    /* 34 */ void *mUnk_34;
    /* 38 */ Unk02124b1c *mUnk_38;
    /* 3c */ Unk02124b1c *mUnk_3c;
    /* 40 */ void *mUnk_40;
    /* 44 */ void *mUnk_44;
    /* 48 */ void *mUnk_48;
    /* 4c */ void *mUnk_4c;
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
    /* 78 */ s32 mUnk_78[2];
    /* 80 */ s16 mUnk_80;
    /* 82 */ u8 mUnk_82[2];
    /* 84 */ s32 mUnk_84;
    /* 88 */ s32 mUnk_88;
    /* 8c */ s32 mUnk_8c;
    /* 90 */ s32 mUnk_90;
} Unk021a9bdc;

// Object behind data_021759d4.
typedef struct Unk021759d4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u8 mUnk_26[0x2];
    /* 28 */ void *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ void *mUnk_30;
    /* 34 */ void *mUnk_34;
    /* 38 */ void *mUnk_38;
    /* 3c */ u8 mUnk_3c[0x4];
    /* 40 */ void *mUnk_40;
    /* 44 */ void *mUnk_44;
    /* 48 */ void *mUnk_48;
    /* 4c */ u8 mUnk_4c[0x4];
    /* 50 */ void *mUnk_50;
    /* 54 */ void *mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ void *mUnk_60;
    /* 64 */ void *mUnk_64;
    /* 68 */ void *mUnk_68;
    /* 6c */ u8 mUnk_6c;
} Unk021759d4;

extern Unk021a9bdc *data_ov001_021a9bdc;
extern u16 data_ov001_021a67c0[];
extern u16 data_ov001_021a67c4[];
extern u16 data_ov001_021a67c8[];
extern u16 data_ov001_021a67d4[];
extern u16 data_ov001_021a67e0[];
extern u16 data_ov001_021a67ec[];
extern u16 data_ov001_021a67f8[];
extern u16 data_ov001_021a6804[];
extern u16 data_ov001_021a6810[];
extern u16 data_ov001_021a681c[];
extern u16 data_ov001_021a6850[][2];
extern s32 data_ov001_021a6900[];
extern Unk021759d4 *data_021759d4;

s16 func_020ae488(s32 a);
s16 func_020adc64(s32 a);
s32 func_02060268(s32 a);
void func_02060004(s32 a);
void func_02057d9c(void);
#include "Main/Unknown/code_021172a8.h"
#include "Main/Unknown/code_0211130c.h"

void func_ov001_02195a6c(void);
void func_ov001_02195ba4(void);
void func_ov001_02195d64(void);
void func_ov001_02195e38(void);
void func_ov001_02195ea0(void);
void func_ov001_02195eb8(void);
void func_ov001_02195ff8(void);
void func_ov001_02196058(void);
void func_ov001_021960a4(void);
void func_ov001_0219623c(void);
void func_ov001_021963a8(void);
void func_ov001_02196514(void);
void func_ov001_02196724(void);
void func_ov001_021968bc(void);
void func_ov001_02196904(void);
void func_ov001_02196960(void *heap);
s32 func_ov001_02196c4c(void);
void func_ov001_02196cd0(void);
void func_ov001_02196d78(void);
void func_ov001_02196d8c(void);
void func_ov001_021978b4(void);
