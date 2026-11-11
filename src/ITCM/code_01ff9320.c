#include "ITCM/code_01ff9320.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9598.h"
#include "code_02010c84.h"
#include "code_02147cd8.h"

#pragma opt_arithtransformation off

// The table below is initialized data kept in .text ahead of the code, right before NNSi_G3dSendTexSRTMaya.
#pragma define_section ITCM ".text"                                                                                    \
                            ".bss" abs32 RWX
#pragma section ITCM begin

CalcTexMtxFunc calcTexMtx_[8] = {
    (CalcTexMtxFunc) texmtxCalc_flag_,   (CalcTexMtxFunc) texmtxCalc_flagS_,   (CalcTexMtxFunc) texmtxCalc_flagR_,
    (CalcTexMtxFunc) texmtxCalc_flagRS_, (CalcTexMtxFunc) texmtxCalc_flagT_,   (CalcTexMtxFunc) texmtxCalc_flagTS_,
    (CalcTexMtxFunc) texmtxCalc_flagTR_, (CalcTexMtxFunc) texmtxCalc_flagTRS_,
};

#pragma section ITCM end

void texmtxCalc_flagTS_(s32 *matrix, const NNSG3dMatAnmResult *matAnmResult) {
    s32 widthFixed;
    s32 heightFixed;
    s32 negSum;

    widthFixed = matAnmResult->mUnk_2c << 12;
    heightFixed = matAnmResult->mUnk_2e << 12;
    FX_DivAsync(heightFixed, widthFixed);
    matrix[0] = matAnmResult->mUnk_20[1];
    matrix[5] = matAnmResult->mUnk_20[1];
    matrix[1] = (-matAnmResult->mUnk_20[0] * FX_GetDivResult()) >> 12;
    FX_DivAsync(widthFixed, heightFixed);
    negSum = -(matAnmResult->mUnk_20[0] + matAnmResult->mUnk_20[1]);
    matrix[12] = (matAnmResult->mUnk_2c * (negSum + 0x1000)) << 3;
    matrix[13] = (matAnmResult->mUnk_2e * (matAnmResult->mUnk_20[0] - matAnmResult->mUnk_20[1] + 0x1000)) << 3;
    matrix[4] = (matAnmResult->mUnk_20[0] * FX_GetDivResult()) >> 12;
}

void texmtxCalc_flagTR_(s32 *matrix, const NNSG3dMatAnmResult *matAnmResult) {
    s32 negScale;

    matrix[0] = matAnmResult->mUnk_18[0];
    matrix[5] = matAnmResult->mUnk_18[1];
    matrix[1] = 0;
    matrix[12] = 0;
    negScale = -(matAnmResult->mUnk_18[1] << 1);
    matrix[13] = (matAnmResult->mUnk_2e * (negScale + 0x2000)) << 3;
    matrix[4] = 0;
}

void texmtxCalc_flagTRS_(s32 *matrix) {
    matrix[0] = 0x1000;
    matrix[1] = 0;
    matrix[4] = 0;
    matrix[5] = 0x1000;
    matrix[12] = 0;
    matrix[13] = 0;
}

void NNSi_G3dSendTexSRTMaya(NNSG3dMatAnmResult *matAnmResult) {
    TexMtxCommand command;

    if (matAnmResult->mUnk_00 & 8) {
        command.mCommand = 0x101610;
    } else {
        command.mCommand = 0x101810;
    }
    command.mMtxModeTex = 3;
    command.mMtxModePosVec = 2;
    command.mMatrix[14] = 0;
    command.mMatrix[11] = 0;
    command.mMatrix[10] = 0;
    command.mMatrix[9] = 0;
    command.mMatrix[8] = 0;
    command.mMatrix[7] = 0;
    command.mMatrix[6] = 0;
    command.mMatrix[3] = 0;
    command.mMatrix[2] = 0;
    command.mMatrix[15] = 0x1000;
    calcTexMtx_[matAnmResult->mUnk_00 & 7](command.mMatrix, matAnmResult);
    if (matAnmResult->mUnk_30 != 0x1000) {
        command.mMatrix[0] = MUL_FIXED12_NO_ROUND(matAnmResult->mUnk_30, command.mMatrix[0]);
        command.mMatrix[1] = MUL_FIXED12_NO_ROUND(matAnmResult->mUnk_30, command.mMatrix[1]);
        command.mMatrix[12] = MUL_FIXED12_NO_ROUND(matAnmResult->mUnk_30, command.mMatrix[12]);
    }
    if (matAnmResult->mUnk_34 != 0x1000) {
        command.mMatrix[4] = MUL_FIXED12_NO_ROUND(matAnmResult->mUnk_34, command.mMatrix[4]);
        command.mMatrix[5] = MUL_FIXED12_NO_ROUND(matAnmResult->mUnk_34, command.mMatrix[5]);
        command.mMatrix[13] = MUL_FIXED12_NO_ROUND(matAnmResult->mUnk_34, command.mMatrix[13]);
    }
    NNS_G3dGeBufferOP_N(command.mCommand, (u32 *) &command + 1, 0x12);
}
