#include "code_02010c84.h"

#include "code_02147288.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02170000.h"
#include "00/code_02188720.h"
#include "code_02012b30.h"
#include "fx_mtx33.h"
#include "code_02147cd8.h"
#include "code_021479b4.h"
#include "g3imm.h"
#include "code_0214a748.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_02171000.h"
#include "registers.h"
#include "code_021471bc.h"
#include "code_02147954.h"

// Draws one shape of the model, first sending the material and the texture matrix when sendMat is set.
void NNS_G3dDraw1Mat1Shp(NNSG3dResMdl *resMdl, u32 matId, u32 shpId, BOOL sendMat) {
    u32 words[7];
    NNSG3dMatAnmResult texResult;
    s32 scale[3];
    s32 invScale[3];
    u8 *texMtx;
    NNSG3dResMat *matBlock;
    NNSG3dResShp *shpBlock;
    NNSG3dResDictEntryHeader *entries;
    NNSG3dResMatData *matData;
    NNSG3dResShpData *shpData;
    s32 posScale;
    void (*sendTexSRT)(NNSG3dMatAnmResult *);
    u32 polyAttr;

    posScale = resMdl->mInfo.mPosScale;
    if (posScale != 0x1000) {
        scale[0] = posScale;
        scale[1] = posScale;
        scale[2] = posScale;
        NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    }
    if (sendMat != 0) {
        matBlock = OFFSET_PTR(NNSG3dResMat, resMdl, resMdl->mOfsMat);
        entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &matBlock->mDict, matBlock->mDict.mOfsEntry);
        matData = OFFSET_PTR(NNSG3dResMatData, matBlock, *DICT_ENTRY(u32, entries, matId));
        if (!(matData->mPolyAttr & 0x1f0000)) {
            return;
        }
        words[0] = 0x293130;
        words[1] = matData->mDiffAmb;
        words[2] = matData->mSpecEmi;
        polyAttr = matData->mPolyAttr;
        words[3] = polyAttr;
        if (matData->mFlag & 0x20) {
            words[3] = polyAttr & ~0x1f0000;
        }
        words[4] = 0x2b2a;
        words[5] = matData->mTexImageParam;
        words[6] = matData->mTexPlttBase;
        NNS_G3dGeBufferOP_N(words[0], &words[1], 6);
        if (matData->mFlag & 1) {
            sendTexSRT = NNS_G3dSendTexSRT_FuncArray[resMdl->mInfo.mTexMtxMode];
            texResult.mFlag = 8;
            texResult.mOrigWidth = matData->mOrigWidth;
            texResult.mOrigHeight = matData->mOrigHeight;
            texResult.mMagW = matData->mMagW;
            texResult.mMagH = matData->mMagH;
            texMtx = matData->mTexMtxData;
            if (!(matData->mFlag & 2)) {
                texResult.mScaleST[0] = ((u32 *) texMtx)[0];
                texResult.mScaleST[1] = ((u32 *) texMtx)[1];
                texMtx += 8;
            } else {
                texResult.mFlag |= 1;
            }
            if (!(matData->mFlag & 4)) {
                texResult.mSinCosR[0] = ((s16 *) texMtx)[0];
                texResult.mSinCosR[1] = ((s16 *) texMtx)[1];
                texMtx += 4;
            } else {
                texResult.mFlag |= 2;
            }
            if (!(matData->mFlag & 8)) {
                texResult.mTransST[0] = ((u32 *) texMtx)[0];
                texResult.mTransST[1] = ((u32 *) texMtx)[1];
            } else {
                texResult.mFlag |= 4;
            }
            sendTexSRT(&texResult);
        }
    }
    shpBlock = OFFSET_PTR(NNSG3dResShp, resMdl, resMdl->mOfsShp);
    entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &shpBlock->mDict, shpBlock->mDict.mOfsEntry);
    shpData = OFFSET_PTR(NNSG3dResShpData, shpBlock, *DICT_ENTRY(u32, entries, shpId));
    NNS_G3dGeSendDL((u8 *) shpData + shpData->mOfsDL, shpData->mSizeDL);
    posScale = resMdl->mInfo.mInvPosScale;
    if (posScale != 0x1000) {
        invScale[0] = posScale;
        invScale[1] = posScale;
        invScale[2] = posScale;
        NNS_G3dGeBufferOP_N(0x1b, invScale, 3);
    }
}

// SBC command for a billboard node.
void NNSi_G3dFuncSbc_BB(NNSG3dRS *state, u32 mode) {
    u32 restoreIdx;
    u32 storeIdx;
    MtxFx44 clipMtx;
    MtxFx44 invWV;
    MtxFx44 camMtx;
    u32 timing;
    u32 commandSize = 2;
    Vec3 *pos = &data_0216190c;
    Vec3 *scaleVec = &data_02161918;

    if (state->mFlag & 0x200) {
        if (mode == 0x40 || mode == 0x60) {
            commandSize++;
        }
        if (mode == 0x20 || mode == 0x60) {
            commandSize++;
        }
        state->mC += commandSize;
        return;
    }
    if (mode == 0x40 || mode == 0x60) {
        commandSize++;
        if (!(state->mFlag & 0x100)) {
            if (mode == 0x40) {
                restoreIdx = state->mC[2];
            } else {
                restoreIdx = state->mC[3];
            }
            NNS_G3dGeBufferOP_N(0x14, &restoreIdx, 1);
        }
    }
    if (state->mCbVecFunc[7] != 0) {
        timing = state->mCbVecTiming[7];
    } else {
        timing = 0;
    }
    if (!(state->mFlag & 0x100)) {
        NNS_G3dGeFlushBuffer();
        reg_G3X_GXFIFO = 0x151110;
        reg_G3X_GXFIFO = 0;
        reg_G3X_GXFIFO = 0;
        while (G3X_GetClipMtx(&clipMtx) != 0) {
        }
        if (NNS_G3dGlb.mFlag & 1) {
            MTX_Copy43To44_(NNS_G3dGlbGetWV(), &invWV);
            MTX_Concat44(&clipMtx, &invWV, &clipMtx);
        } else if (NNS_G3dGlb.mFlag & 2) {
            MTX_Copy43To44_(&NNS_G3dGlb.mCameraMtx, &camMtx);
            MTX_Concat44(&clipMtx, &camMtx, &clipMtx);
        }
        pos->x = clipMtx.mUnk_00[3].x;
        pos->y = clipMtx.mUnk_00[3].y;
        pos->z = clipMtx.mUnk_00[3].z;
        scaleVec->x = VEC_Mag((Vec3 *) &clipMtx.mUnk_00[0]);
        scaleVec->y = VEC_Mag((Vec3 *) &clipMtx.mUnk_00[1]);
        scaleVec->z = VEC_Mag((Vec3 *) &clipMtx.mUnk_00[2]);
        if (NNS_G3dGlb.mFlag & 1) {
            reg_G3X_GXFIFO = 0x171012;
            MIi_CpuSend32(data_021618e0, &reg_G3X_GXFIFO, 8);
            MIi_CpuSend32(NNS_G3dGlbGetInvWV(), &reg_G3X_GXFIFO, 0x30);
            reg_G3X_GXFIFO = 0x1b19;
            MIi_CpuSend32(data_021618e8, &reg_G3X_GXFIFO, 0x3c);
        } else if (NNS_G3dGlb.mFlag & 2) {
            reg_G3X_GXFIFO = 0x171012;
            MIi_CpuSend32(data_021618e0, &reg_G3X_GXFIFO, 8);
            MIi_CpuSend32(NNS_G3dGlbGetInvV(), &reg_G3X_GXFIFO, 0x30);
            reg_G3X_GXFIFO = 0x1b19;
            MIi_CpuSend32(data_021618e8, &reg_G3X_GXFIFO, 0x3c);
        } else {
            MIi_CpuSend32(data_021618dc, &reg_G3X_GXFIFO, 0x48);
        }
    }
    if (timing == 3) {
        state->mFlag &= ~0x40;
        state->mCbVecFunc[7](state);
        timing = state->mFlag & 0x40;
    } else {
        timing = 0;
    }
    if (mode == 0x20 || mode == 0x60) {
        commandSize++;
        if (timing == 0 && !(state->mFlag & 0x100)) {
            storeIdx = state->mC[2];
            NNS_G3dGeBufferOP_N(0x13, &storeIdx, 1);
        }
    }
    state->mC += commandSize;
}

// SBC command for a billboard node that turns about the Y axis only.
void NNSi_G3dFuncSbc_BBY(NNSG3dRS *state, u32 mode) {
    u32 restoreIdx;
    u32 storeIdx;
    MtxFx44 clipMtx;
    MtxFx44 invWV;
    MtxFx44 camMtx;
    u32 timing;
    u32 commandSize = 2;
    Vec3 *pos = &data_02161954;
    Vec3 *scaleVec = &data_02161960;
    Vec3 *axes = data_02161930;

    if (state->mFlag & 0x200) {
        if (mode == 0x40 || mode == 0x60) {
            commandSize++;
        }
        if (mode == 0x20 || mode == 0x60) {
            commandSize++;
        }
        state->mC += commandSize;
        return;
    }
    if (mode == 0x40 || mode == 0x60) {
        commandSize++;
        if (!(state->mFlag & 0x100)) {
            if (mode == 0x40) {
                restoreIdx = state->mC[2];
            } else {
                restoreIdx = state->mC[3];
            }
            NNS_G3dGeBufferOP_N(0x14, &restoreIdx, 1);
        }
    }
    if (state->mCbVecFunc[8] != 0) {
        timing = state->mCbVecTiming[8];
    } else {
        timing = 0;
    }
    if (!(state->mFlag & 0x100)) {
        NNS_G3dGeFlushBuffer();
        reg_G3X_GXFIFO = 0x151110;
        reg_G3X_GXFIFO = 0;
        reg_G3X_GXFIFO = 0;
        while (G3X_GetClipMtx(&clipMtx) != 0) {
        }
        if (NNS_G3dGlb.mFlag & 1) {
            MTX_Copy43To44_(NNS_G3dGlbGetWV(), &invWV);
            MTX_Concat44(&clipMtx, &invWV, &clipMtx);
        } else if (NNS_G3dGlb.mFlag & 2) {
            MTX_Copy43To44_(&NNS_G3dGlb.mCameraMtx, &camMtx);
            MTX_Concat44(&clipMtx, &camMtx, &clipMtx);
        }
        pos->x = clipMtx.mUnk_00[3].x;
        pos->y = clipMtx.mUnk_00[3].y;
        pos->z = clipMtx.mUnk_00[3].z;
        scaleVec->x = VEC_Mag((Vec3 *) &clipMtx.mUnk_00[0]);
        scaleVec->y = VEC_Mag((Vec3 *) &clipMtx.mUnk_00[1]);
        scaleVec->z = VEC_Mag((Vec3 *) &clipMtx.mUnk_00[2]);
        if (clipMtx.mUnk_00[1].y != 0 || clipMtx.mUnk_00[1].z != 0) {
            VEC_Normalize((Vec3 *) &clipMtx.mUnk_00[1], &axes[1]);
            axes[2].y = -axes[1].z;
            axes[2].z = axes[1].y;
        } else {
            VEC_Normalize((Vec3 *) &clipMtx.mUnk_00[2], &axes[2]);
            axes[1].z = -axes[2].y;
            axes[1].y = axes[2].z;
        }
        if (NNS_G3dGlb.mFlag & 1) {
            reg_G3X_GXFIFO = 0x171012;
            MIi_CpuSend32(data_02161928, &reg_G3X_GXFIFO, 8);
            MIi_CpuSend32(NNS_G3dGlbGetInvWV(), &reg_G3X_GXFIFO, 0x30);
            reg_G3X_GXFIFO = 0x1b19;
            MIi_CpuSend32(data_02161930, &reg_G3X_GXFIFO, 0x3c);
        } else if (NNS_G3dGlb.mFlag & 2) {
            reg_G3X_GXFIFO = 0x171012;
            MIi_CpuSend32(data_02161928, &reg_G3X_GXFIFO, 8);
            MIi_CpuSend32(NNS_G3dGlbGetInvV(), &reg_G3X_GXFIFO, 0x30);
            reg_G3X_GXFIFO = 0x1b19;
            MIi_CpuSend32(data_02161930, &reg_G3X_GXFIFO, 0x3c);
        } else {
            MIi_CpuSend32(data_02161924, &reg_G3X_GXFIFO, 0x48);
        }
    }
    if (timing == 3) {
        state->mFlag &= ~0x40;
        state->mCbVecFunc[8](state);
        timing = state->mFlag & 0x40;
    } else {
        timing = 0;
    }
    if (mode == 0x20 || mode == 0x60) {
        commandSize++;
        if (timing == 0 && !(state->mFlag & 0x100)) {
            storeIdx = state->mC[2];
            NNS_G3dGeBufferOP_N(0x13, &storeIdx, 1);
        }
    }
    state->mC += commandSize;
}

// SBC command that blends several joint matrices by weight into one node matrix.
void NNSi_G3dFuncSbc_NODEMIX(NNSG3dRS *state) {
    u8 *invMtx;
    u32 count;
    u32 cached;
    s64 weight;
    u8 *commandBytes;
    u32 entryIndex;
    NNSG3dResMdl *resMdl;
    s32 *clip;
    s32 *vec;
    u32 jntIdx;
    struct {
        MtxFx43 pos;
        MtxFx33 nrm;
    } sum;

    resMdl = state->mRenderObj->mResMdl;
    count = state->mC[2];
    invMtx = (u8 *) resMdl + resMdl->mOfsEvpMtx;
    weight = 0;
    commandBytes = state->mC + 3;
    MemFillWordsByBlock_inline(&sum, sizeof(sum));
    NNS_G3dGeFlushBuffer();
    reg_G3_MTX_MODE = 0;
    reg_G3_MTX_STORE = 1;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 2;
    for (entryIndex = 0; entryIndex < count; entryIndex++) {
        jntIdx = commandBytes[1];
        cached = ((s32 *) state->mIsEvpCached)[jntIdx >> 5] & (1 << (jntIdx & 0x1f));
        clip = data_02171904[jntIdx];
        if (!cached) {
            state->mIsEvpCached[jntIdx >> 5] |= 1 << (jntIdx & 0x1f);
            reg_G3_MTX_RESTORE = commandBytes[0];
            reg_G3_MTX_MODE = 1;
            G3_MultMtx43(invMtx + jntIdx * 0x54);
        }
        if (entryIndex != 0) {
            sum.nrm.mRows[0].x += (weight * vec[0]) >> 12;
            sum.nrm.mRows[0].y += (weight * vec[1]) >> 12;
            sum.nrm.mRows[0].z += (weight * vec[2]) >> 12;
            sum.nrm.mRows[1].x += (weight * vec[3]) >> 12;
            sum.nrm.mRows[1].y += (weight * vec[4]) >> 12;
            sum.nrm.mRows[1].z += (weight * vec[5]) >> 12;
            sum.nrm.mRows[2].x += (weight * vec[6]) >> 12;
            sum.nrm.mRows[2].y += (weight * vec[7]) >> 12;
            sum.nrm.mRows[2].z += (weight * vec[8]) >> 12;
        }
        if (!cached) {
            while (G3X_GetClipMtx(clip) != 0) {
            }
            reg_G3_MTX_MODE = 2;
            G3_MultMtx33(invMtx + jntIdx * 0x54 + 0x30);
        }
        vec = data_02171944[jntIdx];
        weight = commandBytes[2] << 4;
        sum.pos.mRows[0].x += (weight * clip[0]) >> 12;
        sum.pos.mRows[0].y += (weight * clip[1]) >> 12;
        sum.pos.mRows[0].z += (weight * clip[2]) >> 12;
        sum.pos.mRows[1].x += (weight * clip[4]) >> 12;
        sum.pos.mRows[1].y += (weight * clip[5]) >> 12;
        sum.pos.mRows[1].z += (weight * clip[6]) >> 12;
        sum.pos.mRows[2].x += (weight * clip[8]) >> 12;
        sum.pos.mRows[2].y += (weight * clip[9]) >> 12;
        sum.pos.mRows[2].z += (weight * clip[10]) >> 12;
        sum.pos.mRows[3].x += (weight * clip[12]) >> 12;
        sum.pos.mRows[3].y += (weight * clip[13]) >> 12;
        sum.pos.mRows[3].z += (weight * clip[14]) >> 12;
        commandBytes += 3;
        if (!cached) {
            while (G3X_GetVectorMtx(vec) != 0) {
            }
        }
    }
    sum.nrm.mRows[0].x += (weight * vec[0]) >> 12;
    sum.nrm.mRows[0].y += (weight * vec[1]) >> 12;
    sum.nrm.mRows[0].z += (weight * vec[2]) >> 12;
    sum.nrm.mRows[1].x += (weight * vec[3]) >> 12;
    sum.nrm.mRows[1].y += (weight * vec[4]) >> 12;
    sum.nrm.mRows[1].z += (weight * vec[5]) >> 12;
    sum.nrm.mRows[2].x += (weight * vec[6]) >> 12;
    sum.nrm.mRows[2].y += (weight * vec[7]) >> 12;
    sum.nrm.mRows[2].z += (weight * vec[8]) >> 12;
    G3_LoadMtx43(&sum.nrm);
    reg_G3_MTX_MODE = 1;
    G3_LoadMtx43(&sum.pos);
    reg_G3_MTX_MODE = 0;
    reg_G3_MTX_RESTORE = 1;
    reg_G3_MTX_MODE = 2;
    reg_G3_MTX_STORE = state->mC[1];
    state->mC += (state->mC[2] + 1) * 3;
}

// SBC command that sends a display list.
void NNSi_G3dFuncSbc_CALLDL(NNSG3dRS *state) {
    u8 *commandBytes;
    u32 timing;

    if (state->mCbVecFunc[10] != 0) {
        timing = state->mCbVecTiming[10];
    } else {
        timing = 0;
    }
    if (!(state->mFlag & 0x100)) {
        commandBytes = state->mC;
        NNS_G3dGeSendDL(commandBytes + (commandBytes[1] | (commandBytes[2] << 8) | (commandBytes[3] << 16) |
                                        (commandBytes[4] << 24)),
                        commandBytes[5] | (commandBytes[6] << 8) | (commandBytes[7] << 16) | (commandBytes[8] << 24));
    }
    if (timing == 3) {
        state->mFlag &= ~0x40;
        state->mCbVecFunc[10](state);
    }
    state->mC += 9;
}

// SBC command that sets up environment-mapped texture coordinates.
void NNSi_G3dFuncSbc_ENVMAP(NNSG3dRS *state) {
    u32 texMode;
    u32 texCoord;
    u32 vecMode;
    u32 texMode2;
    u32 vecMode2;
    MtxFx43 nrm;
    u32 timing;
    u8 *texMtx;
    NNSG3dResMatData *matData;
    NNSG3dResDictEntryHeader *entries;
    u16 flag;
    s32 width;
    s32 height;

    if (!(state->mFlag & 0x200) && (state->mFlag & 1)) {
        if ((state->mMatAnmResult->mPrmTexImage & 0xc0000000) != 0x80000000) {
            state->mMatAnmResult->mPrmTexImage &= ~0xc0000000;
            state->mMatAnmResult->mPrmTexImage |= 0x80000000;
            data_02161874[1] = state->mMatAnmResult->mPrmTexImage;
            NNS_G3dGeBufferOP_N(data_02161874[0], &data_02161874[1], 1);
        }
        texMode = 3;
        NNS_G3dGeBufferOP_N(0x10, &texMode, 1);
        if (state->mCbVecFunc[12] != 0) {
            timing = state->mCbVecTiming[12];
        } else {
            timing = 0;
        }
        width = state->mMatAnmResult->mOrigWidth;
        height = state->mMatAnmResult->mOrigHeight;
        nrm.mRows[3].x = width << 15;
        nrm.mRows[3].y = -height << 15;
        nrm.mRows[3].z = 0x10000;
        NNS_G3dGeBufferOP_N(0x1b, &nrm.mRows[3], 3);
        texCoord = (u16) (s16) (width << 3) | ((u16) (s16) (height << 3) << 16);
        NNS_G3dGeBufferOP_N(0x22, &texCoord, 1);
        entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &state->mResMat->mDict, state->mResMat->mDict.mOfsEntry);
        matData =
            OFFSET_PTR(NNSG3dResMatData, state->mResMat, *(u32 *) (entries->mData + entries->mSizeUnit * state->mC[1]));
        flag = matData->mFlag;
        if (flag & 0x2000) {
            texMtx = matData->mTexMtxData;
            if (!(flag & 2)) {
                texMtx += 8;
            }
            if (!(flag & 4)) {
                texMtx += 4;
            }
            if (!(flag & 8)) {
                texMtx += 8;
            }
            NNS_G3dGeBufferOP_N(0x18, texMtx, 0x10);
        }
        if (timing == 3) {
            state->mFlag &= ~0x40;
            state->mCbVecFunc[12](state);
            timing = state->mFlag & 0x40;
        } else {
            timing = 0;
        }
        if (timing == 0) {
            vecMode = 2;
            NNS_G3dGeBufferOP_N(0x10, &vecMode, 1);
            NNS_G3dGetCurrentMtx(0, &nrm);
            texMode2 = 3;
            NNS_G3dGeBufferOP_N(0x10, &texMode2, 1);
            if (NNS_G3dGlb.mFlag & 1) {
                NNS_G3dGeBufferOP_N(0x1a, &NNS_G3dGlb.mCameraMtx, 9);
                NNS_G3dGeBufferOP_N(0x1a, &NNS_G3dGlb.mPrmBaseRot, 9);
                NNS_G3dGeBufferOP_N(0x1a, &nrm, 9);
            } else if (NNS_G3dGlb.mFlag & 2) {
                NNS_G3dGeBufferOP_N(0x1a, &NNS_G3dGlb.mCameraMtx, 9);
                NNS_G3dGeBufferOP_N(0x1a, &nrm, 9);
            } else {
                NNS_G3dGeBufferOP_N(0x1a, &nrm, 9);
            }
        }
        vecMode2 = 2;
        NNS_G3dGeBufferOP_N(0x10, &vecMode2, 1);
    }
    state->mC += 3;
}

// SBC command that sets up projection-mapped texture coordinates.
void NNSi_G3dFuncSbc_PRJMAP(NNSG3dRS *state) {
    u32 storeIdx;
    u32 texCoord;
    u32 vecMode;
    u32 restoreIdx;
    MtxFx43 curMatrix;
    MtxFx44 texMtx;
    u32 timing;
    u8 *effectMtx;
    NNSG3dResMatData *matData;
    NNSG3dResDictEntryHeader *entries;
    u16 flag;
    s32 width;
    s32 height;
    s32 transX;
    s32 transY;

    if (!(state->mFlag & 0x200) && (state->mFlag & 1)) {
        NNS_G3dGetCurrentMtx(&curMatrix, 0);
        storeIdx = 0x1e;
        NNS_G3dGeBufferOP_N(0x13, &storeIdx, 1);
        if ((state->mMatAnmResult->mPrmTexImage & 0xc0000000) != 0xc0000000) {
            state->mMatAnmResult->mPrmTexImage &= ~0xc0000000;
            state->mMatAnmResult->mPrmTexImage |= 0xc0000000;
            data_0216186c[1] = state->mMatAnmResult->mPrmTexImage;
            NNS_G3dGeBufferOP_N(data_0216186c[0], &data_0216186c[1], 1);
        }
        if (state->mCbVecFunc[13] != 0) {
            timing = state->mCbVecTiming[13];
        } else {
            timing = 0;
        }
        height = state->mMatAnmResult->mOrigHeight;
        width = state->mMatAnmResult->mOrigWidth;
        data_0216189c[0] = width << 15;
        data_0216189c[5] = -height << 15;
        data_0216189c[12] = width << 15;
        data_0216189c[13] = height << 15;
        NNS_G3dGeBufferOP_N(0x16, data_0216189c, 0x10);
        entries = OFFSET_PTR(NNSG3dResDictEntryHeader, &state->mResMat->mDict, state->mResMat->mDict.mOfsEntry);
        matData =
            OFFSET_PTR(NNSG3dResMatData, state->mResMat, *(u32 *) (entries->mData + entries->mSizeUnit * state->mC[1]));
        flag = matData->mFlag;
        if (flag & 0x2000) {
            effectMtx = matData->mTexMtxData;
            if (!(flag & 2)) {
                effectMtx += 8;
            }
            if (!(flag & 4)) {
                effectMtx += 4;
            }
            if (!(flag & 8)) {
                effectMtx += 8;
            }
            NNS_G3dGeBufferOP_N(0x18, effectMtx, 0x10);
        }
        if (timing == 3) {
            state->mFlag &= ~0x40;
            state->mCbVecFunc[13](state);
            timing = state->mFlag & 0x40;
        } else {
            timing = 0;
        }
        if (timing == 0) {
            if (NNS_G3dGlb.mFlag & 1) {
                NNS_G3dGeBufferOP_N(0x1c, &NNS_G3dGlb.mPrmBaseTrans, 3);
                NNS_G3dGeBufferOP_N(0x1a, &NNS_G3dGlb.mPrmBaseRot, 9);
                NNS_G3dGeBufferOP_N(0x19, &curMatrix, 0xc);
            } else if (NNS_G3dGlb.mFlag & 2) {
                NNS_G3dGeBufferOP_N(0x19, &curMatrix, 0xc);
            } else {
                NNS_G3dGeBufferOP_N(0x19, NNS_G3dGlbGetInvV(), 0xc);
                NNS_G3dGeBufferOP_N(0x19, &curMatrix, 0xc);
            }
            NNS_G3dGeFlushBuffer();
            reg_G3_MTX_MODE = 0;
            reg_G3_MTX_PUSH = 0;
            reg_G3_MTX_IDENTITY = 0;
            while (G3X_GetClipMtx(&texMtx) != 0) {
            }
            reg_G3_MTX_POP = 1;
            reg_G3_MTX_MODE = 3;
            NNS_G3dGeBufferOP_N(0x16, &texMtx, 0x10);
            transX = texMtx.mUnk_00[3].x >> 4;
            transY = texMtx.mUnk_00[3].y >> 4;
            texCoord = (u16) (s16) (transX >> 8) | ((u16) (s16) (transY >> 8) << 16);
            NNS_G3dGeBufferOP_N(0x22, &texCoord, 1);
        }
        vecMode = 2;
        NNS_G3dGeBufferOP_N(0x10, &vecMode, 1);
        restoreIdx = 0x1e;
        NNS_G3dGeBufferOP_N(0x14, &restoreIdx, 1);
    }
    state->mC += 3;
}

// Calls the animation functions of every animation object of the list that has data for the material.
BOOL NNSi_G3dAnmBlendMat(NNSG3dMatAnmResult *result, NNSG3dAnmObj *anmObj, u32 matId) {
    BOOL ret = FALSE;

    do {
        u32 mapValue = anmObj->mMapData[matId];

        if (mapValue & 0x100) {
            anmObj->mFuncAnm(result, anmObj, mapValue & 0xff);
            ret = TRUE;
        }
        anmObj = anmObj->mNext;
    } while (anmObj != 0);
    return ret;
}

// Adds ratio times v1 to v0, or just ratio when v1 is one.
void blendScaleVec_(Vec3 *dest, const Vec3 *src, s32 weight, u32 srcIsOne) {
    if (srcIsOne != 0) {
        dest->x += weight;
        dest->y += weight;
        dest->z += weight;
    } else {
        dest->x += (weight * src->x) >> 12;
        dest->y += (weight * src->y) >> 12;
        dest->z += (weight * src->z) >> 12;
    }
}

// Blends the joint animations of every animation object of the list for one node.
BOOL NNSi_G3dAnmBlendJnt(NNSG3dJntAnmResult *result, NNSG3dAnmObj *anmObj, u32 nodeId) {
    NNSG3dJntAnmResult animResult;
    NNSG3dAnmObj *currentAnmObj;
    s32 count;
    s32 totalWeight;
    NNSG3dAnmObj *last;
    s32 weight;
    u32 mapValue;

    if (anmObj->mNext == 0) {
        mapValue = anmObj->mMapData[nodeId];
        if ((mapValue & 0x300) != 0x100) {
            return 0;
        }
        anmObj->mFuncAnm(result, anmObj, mapValue & 0xff);
        return 1;
    }
    totalWeight = 0;
    count = 0;
    currentAnmObj = anmObj;
    do {
        if ((currentAnmObj->mMapData[nodeId] & 0x300) == 0x100) {
            last = currentAnmObj;
            totalWeight += currentAnmObj->mRatio;
            count++;
        }
        currentAnmObj = currentAnmObj->mNext;
    } while (currentAnmObj != 0);
    if (totalWeight == 0) {
        return 0;
    }
    if (count == 1) {
        last->mFuncAnm(result, last, last->mMapData[nodeId] & 0xff);
        return 1;
    }
    MemFillWordsByBlock_inline(result, sizeof(*result));
    result->mFlag = -1;
    do {
        mapValue = anmObj->mMapData[nodeId];
        if ((mapValue & 0x300) == 0x100 && anmObj->mRatio > 0) {
            anmObj->mFuncAnm(&animResult, anmObj, mapValue & 0xff);
            if (totalWeight == 0x1000) {
                weight = anmObj->mRatio;
            } else {
                weight = FX_Div(anmObj->mRatio, totalWeight);
            }
            blendScaleVec_(&result->mScale, &animResult.mScale, weight, animResult.mFlag & 1);
            blendScaleVec_(&result->mScaleEx0, &animResult.mScaleEx0, weight, animResult.mFlag & 8);
            blendScaleVec_(&result->mScaleEx1, &animResult.mScaleEx1, weight, animResult.mFlag & 0x10);
            if (!(animResult.mFlag & 4)) {
                result->mTrans.x += MUL_FIXED12_NO_ROUND(weight, animResult.mTrans.x);
                result->mTrans.y += MUL_FIXED12_NO_ROUND(weight, animResult.mTrans.y);
                result->mTrans.z += MUL_FIXED12_NO_ROUND(weight, animResult.mTrans.z);
            }
            if (!(animResult.mFlag & 2)) {
                result->mRot.mRows[0].x += (weight * animResult.mRot.mRows[0].x) >> 12;
                result->mRot.mRows[0].y += (weight * animResult.mRot.mRows[0].y) >> 12;
                result->mRot.mRows[0].z += (weight * animResult.mRot.mRows[0].z) >> 12;
                result->mRot.mRows[1].x += (weight * animResult.mRot.mRows[1].x) >> 12;
                result->mRot.mRows[1].y += (weight * animResult.mRot.mRows[1].y) >> 12;
                result->mRot.mRows[1].z += (weight * animResult.mRot.mRows[1].z) >> 12;
            } else {
                result->mRot.mRows[0].x += weight;
                result->mRot.mRows[1].y += weight;
            }
            result->mFlag &= animResult.mFlag;
        }
        anmObj = anmObj->mNext;
    } while (anmObj != 0);
    VEC_CrossProduct(&result->mRot.mRows[0], &result->mRot.mRows[1], &result->mRot.mRows[2]);
    VEC_Normalize(&result->mRot.mRows[0], &result->mRot.mRows[0]);
    VEC_Normalize(&result->mRot.mRows[2], &result->mRot.mRows[2]);
    VEC_CrossProduct(&result->mRot.mRows[2], &result->mRot.mRows[0], &result->mRot.mRows[1]);
    return 1;
}

// Combines the visibility animations of every animation object of the list for one node.
BOOL NNSi_G3dAnmBlendVis(NNSG3dVisAnmResult *result, NNSG3dAnmObj *anmObj, u32 nodeId) {
    NNSG3dVisAnmResult visResult;
    BOOL ret = FALSE;

    result->mIsVisible = 0;
    do {
        u32 mapValue = anmObj->mMapData[nodeId];

        if (mapValue & 0x100) {
            anmObj->mFuncAnm(&visResult, anmObj, mapValue & 0xff);
            result->mIsVisible |= visResult.mIsVisible;
            ret = TRUE;
        }
        anmObj = anmObj->mNext;
    } while (anmObj != 0);
    return ret;
}

// Sets the global state to its defaults: command words, identity matrices, lights, colors, viewport and base transform.
void NNS_G3dGlbInit(void) {
    NNS_G3dGlb.mCmd0 = 0x17101610;
    NNS_G3dGlb.mMtxModeProj = 0;
    NNS_G3dGlb.mMtxModePosVec = 2;
    NNS_G3dGlb.mCmd1 = 0x32323232;
    NNS_G3dGlb.mCmd2 = 0x60293130;
    NNS_G3dGlb.mCmd3 = 0x33333333;
    NNS_G3dGlb.mCmd4 = 0x2a1b19;
    MTX_Identity43_(&NNS_G3dGlb.mCameraMtx);
    MTX_Identity44_(&NNS_G3dGlb.mProjMtx);
    NNS_G3dGlb.mLightVec[0] = 0x2d8b62d8;
    NNS_G3dGlb.mLightVec[1] = 0x40000200;
    NNS_G3dGlb.mLightVec[2] = 0x800001ff;
    NNS_G3dGlb.mLightVec[3] = 0xc0080000;
    NNS_G3dGlb.mPrmMatColor0 = 0x4210c210;
    NNS_G3dGlb.mPrmMatColor1 = 0x4210c210;
    NNS_G3dGlb.mPrmPolygonAttr = 0x1f008f;
    NNS_G3dGlb.mPrmViewPort = 0xbfff0000;
    NNS_G3dGlb.mLightColor[0] = 0x7fff;
    NNS_G3dGlb.mLightColor[1] = 0x4000001f;
    NNS_G3dGlb.mLightColor[2] = 0x800003e0;
    NNS_G3dGlb.mLightColor[3] = 0xc0007c00;
    NNS_G3dGlb.mPrmBaseTrans.x = 0;
    NNS_G3dGlb.mPrmBaseTrans.y = 0;
    NNS_G3dGlb.mPrmBaseTrans.z = 0;
    MTX_Identity33_(&NNS_G3dGlb.mPrmBaseRot);
    NNS_G3dGlb.mPrmBaseScale.x = 0x1000;
    NNS_G3dGlb.mPrmBaseScale.y = 0x1000;
    NNS_G3dGlb.mPrmBaseScale.z = 0x1000;
    NNS_G3dGlb.mPrmTexImageParam = 0;
    NNS_G3dGlb.mFlag = 0;
    NNS_G3dGlb.mCamPos.z = 0;
    NNS_G3dGlb.mCamPos.y = 0;
    NNS_G3dGlb.mCamPos.x = 0;
    NNS_G3dGlb.mCamUp.z = 0;
    NNS_G3dGlb.mCamUp.x = 0;
    NNS_G3dGlb.mCamUp.y = 0x1000;
    NNS_G3dGlb.mCamTarget.y = 0;
    NNS_G3dGlb.mCamTarget.x = 0;
    NNS_G3dGlb.mCamTarget.z = -0x1000;
}

// Sends the matrices, lights, colors, viewport and base transform to the geometry engine as one block.
void NNS_G3dGlbFlushP(void) {
    u32 *words = (u32 *) &NNS_G3dGlb;
    u32 command = *words++;

    NNS_G3dGeBufferOP_N(command, words, 0x3e);
    NNS_G3dGlb.mFlag &= ~1;
    NNS_G3dGlb.mFlag &= ~2;
}

// Sets the base translation and drops the cached matrices that depend on it.
void NNS_G3dGlbSetBaseTrans(const Vec3 *trans) {
    NNS_G3dGlb.mPrmBaseTrans = *trans;
    NNS_G3dGlb.mFlag &= ~0xa4;
}

// Sets the base scale and drops the cached matrices that depend on it.
void NNS_G3dGlbSetBaseScale(const Vec3 *scale) {
    NNS_G3dGlb.mPrmBaseScale = *scale;
    NNS_G3dGlb.mFlag &= ~0xa4;
}

// Sets the direction of a light.
void NNS_G3dGlbLightVector(u32 lightId, s32 x, s32 y, s32 z) {
    NNS_G3dGlb.mLightVec[lightId] =
        ((x >> 3) & 0x3ff) | (((y >> 3) & 0x3ff) << 10) | (((z >> 3) & 0x3ff) << 20) | (lightId << 30);
}

// Sets the color of a light.
void NNS_G3dGlbLightColor(u32 lightId, u32 rgb) {
    NNS_G3dGlb.mLightColor[lightId] = rgb | (lightId << 30);
}

// Sets the diffuse and ambient colors.
void NNS_G3dGlbMaterialColorDiffAmb(u32 diffuse, u32 ambient, u32 vtxColor) {
    NNS_G3dGlb.mPrmMatColor0 = diffuse | (ambient << 16) | ((vtxColor != 0) << 15);
}

// Sets the specular and emission colors.
void NNS_G3dGlbMaterialColorSpecEmi(u32 specular, u32 emission, u32 shininess) {
    NNS_G3dGlb.mPrmMatColor1 = specular | (emission << 16) | ((shininess != 0) << 15);
}

// Sets the polygon attributes.
void NNS_G3dGlbPolygonAttr(u32 light, u32 polyMode, u32 cullMode, u32 polygonId, u32 alpha, u32 extra) {
    NNS_G3dGlb.mPrmPolygonAttr =
        (extra | (light | (polyMode << 4) | (cullMode << 6))) | (polygonId << 24) | (alpha << 16);
}

// Returns the inverse of the camera matrix, computing it when it is out of date.
MtxFx43 *NNS_G3dGlbGetInvV(void) {
    if (!(NNS_G3dGlb.mFlag & 0x8)) {
        MTX_Inverse43(&NNS_G3dGlb.mCameraMtx, &NNS_G3dGlb.mInvCameraMtx);
        NNS_G3dGlb.mFlag |= 0x8;
    }
    return &NNS_G3dGlb.mInvCameraMtx;
}

// Computes the camera matrix with the base transform applied, and its inverse.
void calcSrtCameraMtx_(void) {
    MTX_Concat43((MtxFx43 *) &NNS_G3dGlb.mPrmBaseRot, &NNS_G3dGlb.mCameraMtx, &NNS_G3dGlb.mSrtCameraMtx);
    MTX_ScaleApply43(&NNS_G3dGlb.mSrtCameraMtx, &NNS_G3dGlb.mSrtCameraMtx, NNS_G3dGlb.mPrmBaseScale.x,
                     NNS_G3dGlb.mPrmBaseScale.y, NNS_G3dGlb.mPrmBaseScale.z);
    MTX_Inverse43(&NNS_G3dGlb.mSrtCameraMtx, &NNS_G3dGlb.mInvSrtCameraMtx);
}

// Returns the camera matrix with the base transform applied, computing it when it is out of date.
MtxFx43 *NNS_G3dGlbGetWV(void) {
    if (!(NNS_G3dGlb.mFlag & 0x80)) {
        calcSrtCameraMtx_();
        NNS_G3dGlb.mFlag |= 0x80;
    }
    return &NNS_G3dGlb.mSrtCameraMtx;
}

// Returns the inverse of the camera matrix with the base transform applied, computing it when it is out of date.
MtxFx43 *NNS_G3dGlbGetInvWV(void) {
    if (!(NNS_G3dGlb.mFlag & 0x80)) {
        calcSrtCameraMtx_();
        NNS_G3dGlb.mFlag |= 0x80;
    }
    return &NNS_G3dGlb.mInvSrtCameraMtx;
}

// Returns the size of an animation object for the animation and the model.
u32 NNS_G3dAnmObjCalcSizeRequired(const NNSG3dResAnmHeader *anm, const NNSG3dResMdl *mdl) {
    switch (anm->mCategory0) {
        case 'M':
            return ((mdl->mInfo.mNumMat << 1) + 0x1c) & ~3;
        case 'J':
        case 'V':
            return ((mdl->mInfo.mNumNode << 1) + 0x1c) & ~3;
        default:
            return 0;
    }
}

// Starts an animation object for the animation and selects the init function of its format.
void NNS_G3dAnmObjInit(NNSG3dAnmObj *anmObj, void *resAnm, const NNSG3dResMdl *resMdl, void *resTex) {
    const NNSG3dResAnmHeader *animHeader;
    u32 funcIndex;

    anmObj->mFrame = 0;
    anmObj->mResAnm = resAnm;
    anmObj->mNext = 0;
    anmObj->mPriority = 0x7f;
    anmObj->mRatio = 0x1000;
    anmObj->mResTex = resTex;
    animHeader = resAnm;
    for (funcIndex = 0; funcIndex < data_021617d0; funcIndex++) {
        if (animHeader->mCategory0 == data_021617f4[funcIndex].mCategory0 &&
            animHeader->mCategory1 == data_021617f4[funcIndex].mCategory1) {
            data_021617f4[funcIndex].mFunc(anmObj, resAnm, resMdl);
            return;
        }
    }
}

// Clears the render object and sets the default blend functions and the model.
void NNS_G3dRenderObjInit(NNSG3dRenderObj *renderObj, NNSG3dResMdl *resMdl) {
    volatile u32 zero = 0;

    MIi_CpuClear32(zero, renderObj, 0x54);
    renderObj->mFuncBlendMat = data_021617f0;
    renderObj->mFuncBlendJnt = data_021617ec;
    renderObj->mFuncBlendVis = data_021617e8;
    renderObj->mResMdl = resMdl;
}
