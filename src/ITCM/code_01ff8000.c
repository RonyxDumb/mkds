#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "unk_02152000_data.h"
#include "Main/Kart/data_02161000.h"
#include "data_02170000.h"
#include "data_02173000.h"
#include "gfd_LinkedListPlttVramMan.h"
#include "mic.h"
#include "gfd_LinkedListTexVramMan.h"
#include "Main/Net/data_0216f000.h"
#include "os_thread.h"
#include "mb_data.h"
#include "Main/Graphics/nsbmd_render_obj.h" // NNSG3dRenderObj
#include "code_0200c914.h"
#include "code_02010c84.h"
#include "code_0214c778.h"
#include "cp_context.h"
#include "registers.h"
#include "gecom.h"

void NNS_G3dGeSetBuffer(GxCommandBuffer *commandBuffer) {
    if (NNS_G3dGeBuffer == 0) {
        commandBuffer->mWordCount = 0;
        NNS_G3dGeBuffer = commandBuffer;
    }
}

GxCommandBuffer *NNS_G3dGeReleaseBuffer(void) {
    GxCommandBuffer *commandBuffer;

    NNS_G3dGeFlushBuffer();
    commandBuffer = NNS_G3dGeBuffer;
    NNS_G3dGeBuffer = 0;
    return commandBuffer;
}
// clang-format on

void NNS_G3dGeFlushBuffer(void) {
    if (NNS_G3dFlagGXDmaAsync != 0) {
        NNS_G3dGeWaitSendDL();
    }
    if (NNS_G3dGeBuffer == 0) {
        return;
    }
    if (NNS_G3dGeBuffer->mWordCount == 0) {
        return;
    }
    MIi_CpuSend32(NNS_G3dGeBuffer->mWords, &reg_G3X_GXFIFO, NNS_G3dGeBuffer->mWordCount * 4);
    NNS_G3dGeBuffer->mWordCount = 0;
}

void NNS_G3dGeWaitSendDL(void) {
    while (NNS_G3dFlagGXDmaAsync != 0) {
    }
}

void simpleUnlock_(u32 *target) {
    *target = 0;
}

void NNS_G3dGeSendDL(const void *commands, u32 commandLength) {
    if (commandLength < 0x100 || GXi_DmaId == 0xffffffff) {
        NNS_G3dGeBufferOP_N(*(u32 *) commands, commands + 4, (commandLength >> 2) - 1);
        return;
    }
    NNS_G3dGeFlushBuffer();
    NNS_G3dFlagGXDmaAsync = 1;
    if (NNS_G3dFlagUseFastDma != 0) {
        MI_SendGXCommandAsyncFast(GXi_DmaId, commands, commandLength, (MIDmaCallback) simpleUnlock_,
                                  &NNS_G3dFlagGXDmaAsync);
    } else {
        MI_SendGXCommandAsync(GXi_DmaId, commands, commandLength, (MIDmaCallback) simpleUnlock_,
                              &NNS_G3dFlagGXDmaAsync);
    }
}

void NNS_G3dGeBufferOP_N(u32 command, const void *parameters, u32 parameterCount) {
    u32 wordCount;

    if (NNS_G3dGeBuffer != 0) {
        if (NNS_G3dFlagGXDmaAsync != 0) {
            wordCount = NNS_G3dGeBuffer->mWordCount;
            if (wordCount + 1 + parameterCount <= 0xc0) {
                NNS_G3dGeBuffer->mWordCount = wordCount + 1;
                NNS_G3dGeBuffer->mWords[wordCount] = command;
                if (parameterCount == 0) {
                    return;
                }
                MIi_CpuCopyFast(parameters, &NNS_G3dGeBuffer->mWords[NNS_G3dGeBuffer->mWordCount], parameterCount * 4);
                NNS_G3dGeBuffer->mWordCount += parameterCount;
                return;
            }
        }
        if (NNS_G3dGeBuffer->mWordCount != 0) {
            NNS_G3dGeFlushBuffer();
        } else if (NNS_G3dFlagGXDmaAsync != 0) {
            NNS_G3dGeWaitSendDL();
        }
    } else if (NNS_G3dFlagGXDmaAsync != 0) {
        NNS_G3dGeWaitSendDL();
    }
    reg_G3X_GXFIFO = command;
    MIi_CpuSend32(parameters, &reg_G3X_GXFIFO, parameterCount * 4);
}

void G3dDrawInternal_Loop_(NNSG3dRS *renderState) {
    u32 commandByte;

    do {
        renderState->mFlag &= ~0x40;
        commandByte = renderState->mC[0];
        NNS_G3dFuncSbcTable[commandByte & 0x1f](renderState, commandByte & 0xe0);
    } while (!(renderState->mFlag & 0x20));
}

void G3dDrawInternal_(NNSG3dRS *renderState, NNSG3dRenderObj *renderObj) {
    MemFillWordsByBlock_inline(renderState, 0x188);
    renderState->mIsScaleCacheOne[0] = 1;
    renderState->mFlag = 1;
    if (renderObj->mPtrUserSbc != 0) {
        renderState->mC = renderObj->mPtrUserSbc;
    } else {
        renderState->mC = (u8 *) renderObj->mResMdl + renderObj->mResMdl->mOfsSbc;
    }
    renderState->mRenderObj = renderObj;
    renderState->mResNodeInfo = OFFSET_PTR(Unk02170500_d4, renderObj->mResMdl, 0x40);
    renderState->mResMat = OFFSET_PTR(NNSG3dResMat, renderObj->mResMdl, renderObj->mResMdl->mOfsMat);
    renderState->mResShp = (u8 *) renderObj->mResMdl + renderObj->mResMdl->mOfsShp;
    renderState->mFuncJntScale = NNS_G3dGetJointScale_FuncArray[renderObj->mResMdl->mInfo.mScalingRule];
    renderState->mFuncJntMtx = NNS_G3dSendJointSRT_FuncArray[renderObj->mResMdl->mInfo.mScalingRule];
    renderState->mFuncTexMtx = NNS_G3dSendTexSRT_FuncArray[renderObj->mResMdl->mInfo.mTexMtxMode];
    renderState->mPosScale = renderObj->mResMdl->mInfo.mPosScale;
    renderState->mInvPosScale = renderObj->mResMdl->mInfo.mInvPosScale;
    if (renderObj->mCbFunc != 0 && renderObj->mCbCmd < 0x20) {
        renderState->mCbVecFunc[renderObj->mCbCmd] = renderObj->mCbFunc;
        renderState->mCbVecTiming[renderObj->mCbCmd] = renderObj->mCbTiming;
    }
    if (renderObj->mFlag & 1) {
        renderState->mFlag |= 0x80;
    }
    if (renderObj->mFlag & 2) {
        renderState->mFlag |= 0x100;
    }
    if (renderObj->mFlag & 4) {
        renderState->mFlag |= 0x200;
    }
    if (renderObj->mFlag & 8) {
        renderState->mFlag |= 0x400;
    }
    if (renderObj->mCbInitFunc != 0) {
        renderObj->mCbInitFunc(renderState);
    }
    G3dDrawInternal_Loop_(renderState);
    renderObj->mFlag &= ~1;
}

void SbcUpdateHintVec_(u32 *hintVector, NNSG3dAnmObj *animObj) {
    s32 mapIndex;

    if (animObj == 0) {
        return;
    }
    do {
        for (mapIndex = 0; mapIndex < animObj->mNumMapData; mapIndex++) {
            if (animObj->mMapData[mapIndex] & 0x100) {
                hintVector[mapIndex >> 5] |= 1 << (mapIndex & 0x1f);
            }
        }
        animObj = animObj->mNext;
    } while (animObj != 0);
}

void NNS_G3dDraw(NNSG3dRenderObj *renderObj) {
    NNSG3dRS renderState;

    if ((renderObj->mFlag & 0x10) == 0x10) {
        ClearHintBitmap(renderObj->mHintMatAnmExist);
        ClearHintBitmap(renderObj->mHintJntAnmExist);
        ClearHintBitmap(renderObj->mHintVisAnmExist);
        if (renderObj->mAnmMat != 0) {
            SbcUpdateHintVec_(renderObj->mHintMatAnmExist, renderObj->mAnmMat);
        }
        if (renderObj->mAnmJnt != 0) {
            SbcUpdateHintVec_(renderObj->mHintJntAnmExist, renderObj->mAnmJnt);
        }
        if (renderObj->mAnmVis != 0) {
            SbcUpdateHintVec_(renderObj->mHintVisAnmExist, renderObj->mAnmVis);
        }
        renderObj->mFlag &= ~0x10;
    }
    if (NNS_G3dRS != 0) {
        G3dDrawInternal_(NNS_G3dRS, renderObj);
        return;
    }
    NNS_G3dRS = &renderState;
    G3dDrawInternal_(&renderState, renderObj);
    NNS_G3dRS = 0;
}

void NNSi_G3dFuncSbc_NOP(NNSG3dRS *renderState, u32 option) {
    if (renderState->mCbVecFunc[0] != 0) {
        renderState->mCbVecFunc[0](renderState);
    }
    renderState->mC += 1;
}

void NNSi_G3dFuncSbc_RET(NNSG3dRS *renderState, u32 option) {
    if (renderState->mCbVecFunc[1] != 0) {
        renderState->mCbVecFunc[1](renderState);
    }
    renderState->mFlag |= 0x20;
}

void NNSi_G3dFuncSbc_NODE(NNSG3dRS *renderState, u32 option) {
    u32 callbackTiming;
    u32 nodeIndex;
    NNSG3dRenderObj *renderObj;

    if (!(renderState->mFlag & 0x200)) {
        renderState->mCurrentNode = renderState->mC[1];
        nodeIndex = renderState->mCurrentNode;
        renderState->mFlag |= 4;
        renderState->mVisAnmResult = &renderState->mTmpVisAnmResult;
        if (renderState->mCbVecFunc[2] != 0) {
            callbackTiming = renderState->mCbVecTiming[2];
        } else {
            callbackTiming = 0;
        }
        renderObj = renderState->mRenderObj;
        if (renderObj->mAnmVis == 0 || !(renderObj->mHintVisAnmExist[nodeIndex >> 5] & (1 << (nodeIndex & 0x1f))) ||
            renderObj->mFuncBlendVis(renderState->mVisAnmResult, renderObj->mAnmVis, nodeIndex) == 0) {
            renderState->mVisAnmResult->mIsVisible = renderState->mC[2] & 1;
        }
        if (renderState->mVisAnmResult->mIsVisible != 0) {
            renderState->mFlag |= 1;
        } else {
            renderState->mFlag &= ~1;
        }
        if (callbackTiming == 3) {
            renderState->mFlag &= ~0x40;
            renderState->mCbVecFunc[2](renderState);
        }
    }
    renderState->mC += 3;
}

void NNSi_G3dFuncSbc_MTX(NNSG3dRS *renderState, u32 option) {
    u32 callbackTiming;
    u32 restoreIndex;

    if (!(renderState->mFlag & 0x200) && (renderState->mFlag & 1)) {
        if (renderState->mCbVecFunc[3] != 0) {
            callbackTiming = renderState->mCbVecTiming[3];
        } else {
            callbackTiming = 0;
        }
        restoreIndex = renderState->mC[1];
        if (!(renderState->mFlag & 0x100)) {
            NNS_G3dGeBufferOP_N(0x14, &restoreIndex, 1);
        }
        if (callbackTiming == 3) {
            renderState->mFlag &= ~0x40;
            renderState->mCbVecFunc[3](renderState);
        }
    }
    renderState->mC += 2;
}

void NNSi_G3dFuncSbc_MAT_InternalDefault(NNSG3dRS *renderState, u32 option, const u8 *matData, u32 materialIndex) {
    u32 callbackTiming;
    u32 cachedBit;
    u32 *texMtxData;
    NNSG3dMatAnmResult *result;
    NNSG3dMatAnmResult *matAnm;
    u8 *resMat;
    u8 *dictBase;
    s32 matFlags;
    u32 mask;
    u32 secondMask;
    u32 commandWords[8];
    s32 entrySize;

    renderState->mCurrentMat = materialIndex;
    renderState->mFlag |= 8;
    renderState->mMatAnmResult = &renderState->mTmpMatAnmResult;
    if (renderState->mCbVecFunc[4] != 0) {
        callbackTiming = renderState->mCbVecTiming[4];
    } else {
        callbackTiming = 0;
    }
    matAnm = renderState->mRenderObj->mRecMatAnm;
    if (matAnm != 0 && !(renderState->mFlag & 0x80)) {
        result = matAnm + materialIndex;
        goto done;
    }
    if (option == 0x20 || option == 0x40) {
        cachedBit = 1 << (materialIndex & 0x1f);
        if (renderState->mIsMatCached[materialIndex >> 5] & cachedBit) {
            if (matAnm != 0) {
                result = matAnm + materialIndex;
            } else {
                result = NNS_G3dRSOnGlb + materialIndex;
            }
            goto done;
        }
    }
    if (matAnm != 0) {
        renderState->mIsMatCached[materialIndex >> 5] |= 1 << (materialIndex & 0x1f);
        result = renderState->mRenderObj->mRecMatAnm + materialIndex;
    } else if (option == 0x40) {
        renderState->mIsMatCached[materialIndex >> 5] |= 1 << (materialIndex & 0x1f);
        result = NNS_G3dRSOnGlb + materialIndex;
    } else {
        result = &renderState->mTmpMatAnmResult;
    }
    result->mFlag = 0;
    resMat = (u8 *) renderState->mResMat;
    dictBase = resMat + 4;
    entrySize = *(u16 *) (dictBase + *(u16 *) (resMat + 0xa));
    if (*(u16 *) (resMat + *(u32 *) (dictBase + *(u16 *) (resMat + 0xa) + entrySize * materialIndex + 4) + 0x1e) &
        0x20) {
        result->mFlag |= 0x20;
    }
    matFlags = *OFFSET_PTR(u16, matData, 0x1e);
    mask = ((u32 *) matColorMask_)[(matFlags >> 6) & 7];
    result->mPrmMatColor0 = (NNS_G3dGlb.mPrmMatColor0 & ~mask) | (*OFFSET_PTR(u32, matData, 4) & mask);
    secondMask = ((u32 *) matColorMask_)[(*OFFSET_PTR(u16, matData, 0x1e) >> 9) & 7];
    result->mPrmMatColor1 = (NNS_G3dGlb.mPrmMatColor1 & ~secondMask) | (*OFFSET_PTR(u32, matData, 8) & secondMask);
    mask = *OFFSET_PTR(u32, matData, 0x10);
    result->mPrmPolygonAttr = (NNS_G3dGlb.mPrmPolygonAttr & ~mask) | (*OFFSET_PTR(u32, matData, 0xc) & mask);
    result->mPrmTexImage = *OFFSET_PTR(u32, matData, 0x14);
    result->mPrmTexPltt = *OFFSET_PTR(u16, matData, 0x1c);
    matFlags = *OFFSET_PTR(u16, matData, 0x1e);
    if (matFlags & 1) {
        texMtxData = OFFSET_PTR(u32, matData, 0x2c);
        if (!(matFlags & 2)) {
            result->mScaleST[0] = texMtxData[0];
            result->mScaleST[1] = texMtxData[1];
            texMtxData += 2;
        } else {
            result->mFlag |= 1;
        }
        if (!(*OFFSET_PTR(u16, matData, 0x1e) & 4)) {
            result->mSinCosR[0] = ((s16 *) texMtxData)[0];
            result->mSinCosR[1] = ((s16 *) texMtxData)[1];
            texMtxData = (u32 *) ((s16 *) texMtxData + 2);
        } else {
            result->mFlag |= 2;
        }
        if (!(*OFFSET_PTR(u16, matData, 0x1e) & 8)) {
            result->mTransST[0] = texMtxData[0];
            result->mTransST[1] = texMtxData[1];
        } else {
            result->mFlag |= 4;
        }
        result->mFlag |= 8;
    }
    if (renderState->mRenderObj->mAnmMat != 0 &&
        (renderState->mRenderObj->mHintMatAnmExist[materialIndex >> 5] & (1 << (materialIndex & 0x1f)))) {
        renderState->mRenderObj->mFuncBlendMat(result, renderState->mRenderObj->mAnmMat, materialIndex);
    }
    if (result->mFlag & 0x18) {
        result->mOrigWidth = *OFFSET_PTR(u16, matData, 0x20);
        result->mOrigHeight = *OFFSET_PTR(u16, matData, 0x22);
        result->mMagW = *OFFSET_PTR(u32, matData, 0x24);
        result->mMagH = *OFFSET_PTR(u32, matData, 0x28);
    }
done:
    renderState->mMatAnmResult = result;
    matAnm = renderState->mMatAnmResult;
    if (matAnm->mPrmPolygonAttr & 0x1f0000) {
        if (matAnm->mFlag & 0x20) {
            matAnm->mPrmPolygonAttr &= ~0x1f0000;
        }
        renderState->mFlag &= ~2;
        if (!(renderState->mFlag & 0x100)) {
            commandWords[0] = 0x293130;
            commandWords[1] = matAnm->mPrmMatColor0;
            commandWords[2] = matAnm->mPrmMatColor1;
            commandWords[3] = matAnm->mPrmPolygonAttr;
            commandWords[4] = 0x2b2a;
            commandWords[5] = matAnm->mPrmTexImage;
            commandWords[6] = matAnm->mPrmTexPltt;
            NNS_G3dGeBufferOP_N(commandWords[0], &commandWords[1], 6);
            if (matAnm->mFlag & 0x18) {
                renderState->mFuncTexMtx(matAnm);
            }
        }
    } else {
        renderState->mFlag |= 2;
    }
    if (callbackTiming == 3) {
        renderState->mFlag &= ~0x40;
        renderState->mCbVecFunc[4](renderState);
    }
}

void NNSi_G3dFuncSbc_MAT(NNSG3dRS *renderState, u32 option) {
    u32 stateFlags;
    u8 *resMat;
    u8 *matData;
    u32 materialIndex;
    u8 *dictBase;
    s32 entrySize;

    stateFlags = renderState->mFlag;
    if (!(stateFlags & 0x200)) {
        materialIndex = renderState->mC[1];
        if ((stateFlags & 1) || !(stateFlags & 8) || materialIndex != renderState->mCurrentMat) {
            resMat = (u8 *) renderState->mResMat;
            dictBase = resMat + 4;
            entrySize = *(u16 *) (dictBase + *(u16 *) (resMat + 0xa));
            matData = resMat + *(u32 *) (dictBase + *(u16 *) (resMat + 0xa) + entrySize * materialIndex + 4);
            NNS_G3dFuncSbcMatTable[*(u16 *) matData](renderState, option, matData, materialIndex);
        }
    }
    renderState->mC += 2;
}

void NNSi_G3dFuncSbc_SHP_InternalDefault(NNSG3dRS *renderState, u32 option, NNSG3dResShpData *shpData) {
    u32 callbackTiming;

    if (renderState->mCbVecFunc[5] != 0) {
        callbackTiming = renderState->mCbVecTiming[5];
    } else {
        callbackTiming = 0;
    }
    if (!(renderState->mFlag & 0x100)) {
        NNS_G3dGeSendDL((u8 *) shpData + shpData->mOfsDL, shpData->mSizeDL);
    }
    if (callbackTiming == 3) {
        renderState->mFlag &= ~0x40;
        renderState->mCbVecFunc[5](renderState);
    }
}

void NNSi_G3dFuncSbc_SHP(NNSG3dRS *renderState, u32 option) {
    u32 stateFlags;
    Unk02170500_d4 *resShp;
    u8 *shpData;
    u8 *dictBase;
    u32 shapeIndex;

    stateFlags = renderState->mFlag;
    if (!(stateFlags & 0x200) && (stateFlags & 1) && !(stateFlags & 2)) {
        resShp = renderState->mResShp;
        shapeIndex = renderState->mC[1];
        dictBase = (u8 *) resShp + resShp->mUnk_06;
        shpData = (u8 *) resShp + *(u32 *) (dictBase + *(u16 *) dictBase * shapeIndex + 4);
        NNS_G3dFuncSbcShpTable[*(u16 *) shpData](renderState, option, shpData, shapeIndex);
    }
    renderState->mC += 2;
}

void NNSi_G3dFuncSbc_NODEDESC(NNSG3dRS *renderState, u32 option) {
    s32 firstValue;
    s32 secondValue;
    enum { K0 } callbackTiming;
    u32 restoreIndexSkip;
    u32 restoreIndex;
    u32 storeIndex;
    u32 commandLength;
    NNSG3dJntAnmResult *jntAnmResult;
    u16 *dataPointer;
    s32 pivotIndex;
    u32 nodeDescIndex;
    u32 stateFlags;
    u32 flag;
    s32 flags;
    s32 pivotValue;
    u16 *nodeHeader;
    u8 *resNodeInfo;
    u8 *nodeData;
    NNSG3dRenderObj *renderObj;
    u32 entrySize;

    nodeDescIndex = renderState->mC[1];
    commandLength = 4;
    renderState->mCurrentNodeDesc = nodeDescIndex;
    renderState->mFlag |= 0x10;
    stateFlags = renderState->mFlag;
    if (stateFlags & 0x400) {
        if (option == 0x40 || option == 0x60) {
            commandLength += 1;
        }
        if (option == 0x20 || option == 0x60) {
            commandLength += 1;
            if (!(stateFlags & 0x100)) {
                restoreIndexSkip = renderState->mC[4];
                NNS_G3dGeBufferOP_N(0x14, &restoreIndexSkip, 1);
            }
        }
        renderState->mC += commandLength;
        return;
    }
    if (option == 0x40 || option == 0x60) {
        commandLength += 1;
        if (option == 0x40) {
            restoreIndex = renderState->mC[4];
        } else {
            restoreIndex = renderState->mC[5];
        }
        if (!(renderState->mFlag & 0x100)) {
            NNS_G3dGeBufferOP_N(0x14, &restoreIndex, 1);
        }
    }
    renderState->mJntAnmResult = &renderState->mTmpJntAnmResult;
    if (renderState->mCbVecFunc[6] != 0) {
        callbackTiming = renderState->mCbVecTiming[6];
    } else {
        callbackTiming = 0;
    }
    if (renderState->mRenderObj->mRecJntAnm != 0) {
        jntAnmResult = renderState->mRenderObj->mRecJntAnm + nodeDescIndex;
        flag = (renderState->mFlag & 0x80) == 0;
    } else {
        jntAnmResult = &renderState->mTmpJntAnmResult;
        flag = 0;
    }
    if (flag == 0) {
        jntAnmResult->mFlag = 0;
        renderObj = renderState->mRenderObj;
        if (renderObj->mAnmJnt != 0) {
            if (renderObj->mFuncBlendJnt(jntAnmResult, renderObj->mAnmJnt, nodeDescIndex) != 0) {
                goto done;
            }
        }
        resNodeInfo = renderState->mResNodeInfo;
        entrySize = *(u16 *) (resNodeInfo + *(u16 *) (resNodeInfo + 6));
        nodeData = resNodeInfo + *(u32 *) (resNodeInfo + *(u16 *) (resNodeInfo + 6) + entrySize * nodeDescIndex + 4);
        nodeHeader = (u16 *) nodeData;
        dataPointer = OFFSET_PTR(u16, nodeData, 4);
        if (!(*nodeHeader & 1)) {
            jntAnmResult->mTrans.x = ((s32 *) dataPointer)[0];
            jntAnmResult->mTrans.y = ((s32 *) dataPointer)[1];
            jntAnmResult->mTrans.z = ((s32 *) dataPointer)[2];
            dataPointer += 6;
        } else {
            jntAnmResult->mFlag |= 4;
        }
        flags = *nodeHeader;
        if (flags & 2) {
            jntAnmResult->mFlag |= 2;
        } else if (flags & 8) {
            pivotIndex = (flags & 0xf0) >> 4;
            secondValue = ((s16 *) dataPointer)[1];
            firstValue = ((s16 *) dataPointer)[0];
            MI_Zero36B(&jntAnmResult->mRot);
            dataPointer += 2;
            pivotValue = (*nodeHeader & 0x100) ? -0x1000 : 0x1000;
            jntAnmResult->mRot.a[pivotIndex] = pivotValue;
            jntAnmResult->mRot.a[pivotUtil_[pivotIndex][0]] = firstValue;
            jntAnmResult->mRot.a[pivotUtilSecondColumn_[pivotIndex][0]] = secondValue;
            if (*nodeHeader & 0x200) {
                secondValue = -secondValue;
            }
            jntAnmResult->mRot.a[pivotUtilThirdColumn_[pivotIndex][0]] = secondValue;
            if (*nodeHeader & 0x400) {
                firstValue = -firstValue;
            }
            jntAnmResult->mRot.a[pivotUtilFourthColumn_[pivotIndex][0]] = firstValue;
        } else {
            jntAnmResult->mRot.a[0] = ((s16 *) nodeHeader)[1];
            jntAnmResult->mRot.a[1] = ((s16 *) dataPointer)[0];
            jntAnmResult->mRot.a[2] = ((s16 *) dataPointer)[1];
            jntAnmResult->mRot.a[3] = ((s16 *) dataPointer)[2];
            jntAnmResult->mRot.a[4] = ((s16 *) dataPointer)[3];
            jntAnmResult->mRot.a[5] = ((s16 *) dataPointer)[4];
            jntAnmResult->mRot.a[6] = ((s16 *) dataPointer)[5];
            jntAnmResult->mRot.a[7] = ((s16 *) dataPointer)[6];
            jntAnmResult->mRot.a[8] = ((s16 *) dataPointer)[7];
            dataPointer += 8;
        }
        renderState->mFuncJntScale(jntAnmResult, dataPointer, renderState->mC, *nodeHeader);
    }
done:
    renderState->mJntAnmResult = jntAnmResult;
    if (!(renderState->mFlag & 0x100)) {
        renderState->mFuncJntMtx(renderState->mJntAnmResult);
    }
    flag = 0;
    renderState->mJntAnmResult = 0;
    if (callbackTiming == 3) {
        renderState->mFlag &= ~0x40;
        renderState->mCbVecFunc[6](renderState);
        flag = renderState->mFlag & 0x40;
    }
    if (option == 0x20 || option == 0x60) {
        commandLength += 1;
        if (flag == 0 && !(renderState->mFlag & 0x100)) {
            storeIndex = renderState->mC[4];
            NNS_G3dGeBufferOP_N(0x13, &storeIndex, 1);
        }
    }
    renderState->mC += commandLength;
}

void NNSi_G3dFuncSbc_POSSCALE(NNSG3dRS *renderState, u32 option) {
    s32 scale[3];
    s32 scaleValue;

    if (!(renderState->mFlag & 0x100) && !(renderState->mFlag & 0x200)) {
        if (option == 0) {
            scaleValue = renderState->mPosScale;
            scale[2] = scaleValue;
            scale[1] = scaleValue;
            scale[0] = scaleValue;
        } else {
            scaleValue = renderState->mInvPosScale;
            scale[2] = scaleValue;
            scale[1] = scaleValue;
            scale[0] = scaleValue;
        }
        NNS_G3dGeBufferOP_N(0x1b, scale, 3);
    }
    renderState->mC += 1;
}

// clang-format off
// Interrupt dispatch: reads the interrupt flag and enable registers (0x04000210), takes the highest set bit with clz,
// acknowledges it, and runs the function in OS_IRQTable for that bit with lr set to OS_IrqHandler_ThreadSwitch.
// Not compiled code: it jumps with a set return address instead of a call (ldr lr, bx).
asm void OS_IrqHandler(void) {
    stmdb sp!, {lr}
    mov ip, #0x4000000
    add ip, ip, #0x210
    ldr r1, [ip, #-0x8]
    cmp r1, #0x0
    ldmeqia sp!, {pc}
    ldmia ip, {r1, r2}
    ands r1, r1, r2
    ldmeqia sp!, {pc}
    mov r3, #0x80000000
L_loop:
    clz r0, r1
    bics r1, r1, r3, lsr r0
    bne L_loop
    mov r1, r3, lsr r0
    str r1, [ip, #0x4]
    rsbs r0, r0, #0x1f
    ldr r1, =OS_IRQTable
    ldr r0, [r1, r0, lsl #0x2]
    ldr lr, =OS_IrqHandler_ThreadSwitch
    bx r0
}
// clang-format on

// clang-format off
// OSThread switch after an interrupt: clears the pending flags of the thread list at gDtcmData, then saves the
// registers of the running thread in its context and loads those of the first runnable thread.
// Not compiled code: it switches processor modes and moves the whole register set with the user-bank forms of stm and
// ldm (msr, mrs, ^).
asm void OS_IrqHandler_ThreadSwitch(void) {
    mov r2, #0x1
    mov r3, #0x0
    ldr ip, =gDtcmData
    ldr ip, [ip, #0x0]
    cmp ip, #0x0
    beq L_01ff80a8
L_01ff8070:
    str r2, [ip, #0x64]
    str r3, [ip, #0x78]
    str r3, [ip, #0x7c]
    ldr r0, [ip, #0x80]
    str r3, [ip, #0x80]
    mov ip, r0
    cmp ip, #0x0
    bne L_01ff8070
    ldr ip, =gDtcmData
    str r3, [ip, #0x0]
    str r3, [ip, #0x4]
    ldr ip, =OSi_ThreadInfo
    mov r1, #0x1
    strh r1, [ip, #0x0]
L_01ff80a8:
    ldr ip, =OSi_ThreadInfo
    ldrh r1, [ip, #0x0]
    cmp r1, #0x0
    ldreq pc, [sp], #0x4
    mov r1, #0x0
    strh r1, [ip, #0x0]
    mov r3, #0xd2
    msr cpsr_c, r3
    add r2, ip, #0x8
    ldr r1, [r2, #0x0]
L_01ff80d0:
    cmp r1, #0x0
    ldrneh r0, [r1, #0x64]
    cmpne r0, #0x1
    ldrne r1, [r1, #0x68]
    bne L_01ff80d0
    cmp r1, #0x0
    bne L_01ff80f8
L_01ff80ec:
    mov r3, #0x92
    msr cpsr_c, r3
    ldr pc, [sp], #0x4
L_01ff80f8:
    ldr r0, [ip, #0x4]
    cmp r1, r0
    beq L_01ff80ec
    ldr r3, [ip, #0xc]
    cmp r3, #0x0
    beq L_01ff8120
    stmdb sp!, {r0, r1, ip}
    mov lr, pc
    bx r3
    ldmia sp!, {r0, r1, ip}
L_01ff8120:
    str r1, [ip, #0x4]
    mrs r2, spsr
    str r2, [r0, #0x0]!
    stmdb sp!, {r0, r1}
    add r0, r0, #0x0
    add r0, r0, #0x48
    ldr r1, =CP_SaveContext
    blx r1
    ldmia sp!, {r0, r1}
    ldmib sp!, {r2, r3}
    stmib r0!, {r2, r3}
    ldmib sp!, {r2, r3, ip, lr}
    stmib r0!, {r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, ip, sp, lr}^
    stmib r0!, {lr}
    mov r3, #0xd3
    msr cpsr_c, r3
    stmib r0!, {sp}
    stmdb sp!, {r1}
    add r0, r1, #0x0
    add r0, r0, #0x48
    ldr r1, =CPi_RestoreContext
    blx r1
    ldmia sp!, {r1}
    ldr sp, [r1, #0x44]
    mov r3, #0xd2
    msr cpsr_c, r3
    ldr r2, [r1, #0x0]!
    msr spsr_fc, r2
    ldr lr, [r1, #0x40]
    ldmib r1!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, ip, sp, lr}^
    mov r0, r0
    stmda sp!, {r0, r1, r2, r3, ip, lr}
    ldmia sp!, {pc}
}
// clang-format on
