#include "ITCM/texture_matrix_calc.h"
#include "ITCM/model_draw_and_irq_handler.h"
#include "ITCM/kart_ground_contact.h"
#include "model_draw_state.h"
#include "fixed_vector_math.h"

#pragma opt_arithtransformation off

#pragma define_section ITCM ".text"                                                                                    \
                            ".bss" abs32 RWX
#pragma section ITCM begin

CalcTexMtxFunc calcTexMtx_[8] = {
    texmtxCalc_flag_,   texmtxCalc_flagS_,   texmtxCalc_flagR_,
    texmtxCalc_flagRS_, texmtxCalc_flagT_,   texmtxCalc_flagTS_,
    texmtxCalc_flagTR_, texmtxCalc_flagTRS_,
};

#pragma section ITCM end

void texmtxCalc_flagTS_(MtxFx44 *matrix, const NNSG3dMatAnmResult *matAnmResult) {
    s32 widthFixed;
    s32 heightFixed;
    s32 negSum;

    widthFixed = TO_FIXED12(matAnmResult->mOrigWidth);
    heightFixed = TO_FIXED12(matAnmResult->mOrigHeight);
    FX_DivAsync(heightFixed, widthFixed);
    matrix->mRows[0].x = matAnmResult->mSinCosR[1];
    matrix->mRows[1].y = matAnmResult->mSinCosR[1];
    matrix->mRows[0].y = (-matAnmResult->mSinCosR[0] * FX_GetDivResult()) >> 12;
    FX_DivAsync(widthFixed, heightFixed);
    negSum = -(matAnmResult->mSinCosR[0] + matAnmResult->mSinCosR[1]);
    matrix->mRows[3].x = (matAnmResult->mOrigWidth * (negSum + FIXED12_UNIT)) << 3;
    matrix->mRows[3].y =
        (matAnmResult->mOrigHeight * (matAnmResult->mSinCosR[0] - matAnmResult->mSinCosR[1] + FIXED12_UNIT)) << 3;
    matrix->mRows[1].x = (matAnmResult->mSinCosR[0] * FX_GetDivResult()) >> 12;
}

void texmtxCalc_flagTR_(MtxFx44 *matrix, const NNSG3dMatAnmResult *matAnmResult) {
    s32 negDoubleScale;

    matrix->mRows[0].x = matAnmResult->mScaleST[0];
    matrix->mRows[1].y = matAnmResult->mScaleST[1];
    matrix->mRows[0].y = 0;
    matrix->mRows[3].x = 0;
    negDoubleScale = -(matAnmResult->mScaleST[1] << 1);
    matrix->mRows[3].y = (matAnmResult->mOrigHeight * (negDoubleScale + 0x2000)) << 3;
    matrix->mRows[1].x = 0;
}

void texmtxCalc_flagTRS_(MtxFx44 *matrix, const NNSG3dMatAnmResult *matAnmResult) {
    matrix->mRows[0].x = FIXED12_UNIT;
    matrix->mRows[0].y = 0;
    matrix->mRows[1].x = 0;
    matrix->mRows[1].y = FIXED12_UNIT;
    matrix->mRows[3].x = 0;
    matrix->mRows[3].y = 0;
}

void NNSi_G3dSendTexSRTMaya(NNSG3dMatAnmResult *matAnmResult) {
    TexMtxCommand command;

    if (matAnmResult->mFlag & MAT_RESULT_TEX_MATRIX_SET) {
        command.mCommand = TEX_MTX_COMMAND_SET;
    } else {
        command.mCommand = TEX_MTX_COMMAND_MULT;
    }
    command.mMtxModeTex = TEX_MTX_MODE_TEXTURE;
    command.mMtxModePosVec = TEX_MTX_MODE_POSITION_VECTOR;
    command.mMatrix.mRows[3].z = 0;
    command.mMatrix.mRows[2].wComponent = 0;
    command.mMatrix.mRows[2].z = 0;
    command.mMatrix.mRows[2].y = 0;
    command.mMatrix.mRows[2].x = 0;
    command.mMatrix.mRows[1].wComponent = 0;
    command.mMatrix.mRows[1].z = 0;
    command.mMatrix.mRows[0].wComponent = 0;
    command.mMatrix.mRows[0].z = 0;
    command.mMatrix.mRows[3].wComponent = FIXED12_UNIT;
    calcTexMtx_[matAnmResult->mFlag & TEX_MTX_CALC_FLAG_MASK](&command.mMatrix, matAnmResult);
    if (matAnmResult->mMagW != FIXED12_UNIT) {
        command.mMatrix.mRows[0].x = MUL_FIXED12_NO_ROUND(matAnmResult->mMagW, command.mMatrix.mRows[0].x);
        command.mMatrix.mRows[0].y = MUL_FIXED12_NO_ROUND(matAnmResult->mMagW, command.mMatrix.mRows[0].y);
        command.mMatrix.mRows[3].x = MUL_FIXED12_NO_ROUND(matAnmResult->mMagW, command.mMatrix.mRows[3].x);
    }
    if (matAnmResult->mMagH != FIXED12_UNIT) {
        command.mMatrix.mRows[1].x = MUL_FIXED12_NO_ROUND(matAnmResult->mMagH, command.mMatrix.mRows[1].x);
        command.mMatrix.mRows[1].y = MUL_FIXED12_NO_ROUND(matAnmResult->mMagH, command.mMatrix.mRows[1].y);
        command.mMatrix.mRows[3].y = MUL_FIXED12_NO_ROUND(matAnmResult->mMagH, command.mMatrix.mRows[3].y);
    }
    NNS_G3dGeBufferOP_N(command.mCommand, (u32 *) &command + 1, 0x12);
}
