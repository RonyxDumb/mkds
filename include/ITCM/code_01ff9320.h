#pragma once

#include "types.h"

typedef struct NNSG3dMatAnmResult NNSG3dMatAnmResult;

// Command word and the 18 words sent with it: a mode, a 4x4 matrix and a trailing value.
typedef struct TexMtxCommand {
    /* 00 */ u32 mCommand;
    /* 04 */ u32 mMtxModeTex;
    /* 08 */ s32 mMatrix[16];
    /* 48 */ u32 mMtxModePosVec;
    /* 4c */ u32 mUnk_4c;
} TexMtxCommand;

typedef void (*CalcTexMtxFunc)(s32 *, NNSG3dMatAnmResult *);

void NNSi_G3dSendTexSRTMaya(NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flagTRS_(s32 *matrix);
void texmtxCalc_flagTR_(s32 *matrix, const NNSG3dMatAnmResult *in);
void texmtxCalc_flagTS_(s32 *matrix, const NNSG3dMatAnmResult *in);
