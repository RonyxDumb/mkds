#pragma once

#include "types.h"

// One element of the table at the start of Unk021b5dd0.
typedef struct Unk021a2d68 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ u8 *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ u8 mUnk_1c;
    /* 1d */ u8 mUnk_1d;
    /* 1e */ u8 mUnk_1e;
    /* 1f */ u8 pad_1f[3];
    /* 22 */ u16 mUnk_22;
    /* 24 */ u64 mUnk_24;
    /* 2c */ u32 mUnk_2c;
} Unk021a2d68;

typedef struct Unk021b5dd0 {
    /* 000 */ Unk021a2d68 mUnk_000[32];
    /* 600 */ void (*mUnk_600)(s32 a, u32 b);
    /* 604 */ void (*mUnk_604)(u32 a, u8 *b, s32 c);
    /* 608 */ void (*mUnk_608)(u32 a);
    /* 60c */ void (*mUnk_60c)(u32 a, u32 b);
    /* 610 */ u16 mUnk_610;
    /* 612 */ u8 pad_612[2];
} Unk021b5dd0;

extern Unk021b5dd0 *data_ov000_021b5dd0;

void func_ov000_021a31a4(Unk021b5dd0 *state);
