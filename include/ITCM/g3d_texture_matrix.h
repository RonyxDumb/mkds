#pragma once

#include "types.h"
#include "model_draw_blend.h" // NNSG3dMatAnmResult, MtxFx44

typedef struct NNSG3dMatAnmResult NNSG3dMatAnmResult;

// TexMtxCommand.mCommand: three packed geometry commands (matrix mode, load or multiply the 4x4 matrix, matrix mode),
// and the matrix modes the command sets before and after the matrix: texture, and position and vector.
#define TEX_MTX_COMMAND_SET 0x101610
#define TEX_MTX_COMMAND_MULT 0x101810
#define TEX_MTX_MODE_TEXTURE 3
#define TEX_MTX_MODE_POSITION_VECTOR 2
// Bits of NNSG3dMatAnmResult.mFlag that pick the texture matrix calculation (scale one, rotation zero, translation
// zero).
#define TEX_MTX_CALC_FLAG_MASK 7

// Command word and the 18 words sent with it: a mode, a 4x4 matrix and a trailing value.
typedef struct TexMtxCommand {
    /* 00 */ u32 mCommand;
    /* 04 */ u32 mMtxModeTex;
    /* 08 */ MtxFx44 mMatrix;
    /* 48 */ u32 mMtxModePosVec;
    /* 4c */ u32 mUnk_4c;
} TexMtxCommand;

typedef void (*CalcTexMtxFunc)(MtxFx44 *, const NNSG3dMatAnmResult *);

void NNSi_G3dSendTexSRTMaya(NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flagTRS_(MtxFx44 *matrix, const NNSG3dMatAnmResult *matAnmResult);
void texmtxCalc_flagTR_(MtxFx44 *matrix, const NNSG3dMatAnmResult *in);
void texmtxCalc_flagTS_(MtxFx44 *matrix, const NNSG3dMatAnmResult *in);
