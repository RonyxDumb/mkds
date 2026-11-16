#pragma once

#include "types.h"

typedef struct NNSG3dMatAnmResult NNSG3dMatAnmResult;

// Command word and the 18 words sent with it: a mode, a 4x4 matrix and a trailing value.
typedef struct Unk01ff9320_buf {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ s32 mUnk_08[16];
    /* 48 */ u32 mUnk_48;
    /* 4c */ u32 mUnk_4c;
} Unk01ff9320_buf;

typedef void (*Unk01ff9320_Fn)(s32 *, NNSG3dMatAnmResult *);

void NNSi_G3dSendTexSRTMaya(NNSG3dMatAnmResult *p);
void texmtxCalc_flagTRS_(s32 *o);
void texmtxCalc_flagTR_(s32 *o, const NNSG3dMatAnmResult *in);
void texmtxCalc_flagTS_(s32 *o, const NNSG3dMatAnmResult *in);
