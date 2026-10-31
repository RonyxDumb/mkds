#pragma once

#include "types.h"
#include "03/code_021be610.h"
#include "03/code_021d2060.h"

// Object behind data_ov003_021da1f4 (0x5c bytes).
typedef struct Unk021c5c68State {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk021d2188 *mUnk_0c;
    /* 10 */ Unk021da104_04 *mUnk_10[5];
    /* 24 */ Unk021da104_04 *mUnk_24[5];
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
    /* 40 */ u16 mUnk_40;
    /* 42 */ u16 mUnk_42[3];
    /* 48 */ u16 mUnk_48[4];
    /* 50 */ s8 mUnk_50;
    /* 51 */ u8 mUnk_51;
    /* 52 */ u8 mUnk_52;
    /* 53 */ u8 mUnk_53;
    /* 54 */ u8 mUnk_54;
    /* 55 */ u8 mUnk_55;
    /* 56 */ u8 mUnk_56;
    /* 57 */ u8 mUnk_57;
    /* 58 */ u8 mUnk_58;
    /* 59 */ u8 mUnk_59;
} Unk021c5c68State;
#include "03/code_021c5000.h"
#include "03/code_021d1000.h"
#include "03/unk_021da000.h"
#include "Main/Unknown/code_02147000.h"

void func_ov003_021c5c68(void);
