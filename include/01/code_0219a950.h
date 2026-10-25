#pragma once

#include "types.h"

// One 0x40-byte element of the arrays held by Unk021a9bf0.
typedef struct Unk021a9bf0Entry {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ u8 mUnk_08[0x38];
} Unk021a9bf0Entry;

// Overlay state, allocated by the setup function below.
typedef struct Unk021a9bf0 {
    /* 0x00 */ void *mUnk_00;
    /* 0x04 */ u16 *mUnk_04;
    /* 0x08 */ void *mUnk_08;
    /* 0x0c */ void *mUnk_0c;
    /* 0x10 */ void *mUnk_10;
    /* 0x14 */ void *mUnk_14;
    /* 0x18 */ Unk021a9bf0Entry *mUnk_18;
    /* 0x1c */ Unk021a9bf0Entry *mUnk_1c;
    /* 0x20 */ void *mUnk_20;
    /* 0x24 */ void *mUnk_24;
    /* 0x28 */ u8 mUnk_28[4];
    /* 0x2c */ void *mUnk_2c;
    /* 0x30 */ s32 mUnk_30;
    /* 0x34 */ s32 mUnk_34;
    /* 0x38 */ s32 mUnk_38;
    /* 0x3c */ s32 mUnk_3c;
    /* 0x40 */ s32 mUnk_40;
    /* 0x44 */ s32 mUnk_44;
} Unk021a9bf0;

extern Unk021a9bf0 *data_ov001_021a9bf0;

void func_ov001_0219a950(void);
void func_ov001_0219a9a0(void *heap);
void func_ov001_0219ac98(void);
void func_ov001_0219ad10(void);
void func_ov001_0219ad3c(void);
void func_ov001_0219ad68(void);
void func_ov001_0219ad7c(void);
void func_ov001_0219ad98(void);
void func_ov001_0219adbc(void);
void func_ov001_0219ade8(void);
void func_ov001_0219adfc(void);
void func_ov001_0219ae10(void);
