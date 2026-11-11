#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_02152000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_02173000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_020846c0.h" // NNSG3dRenderObj
#include "code_0200c914.h"
#include "code_02010c84.h"
#include "code_0214c778.h"
#include "cp_context.h"
#include "registers.h"

void NNS_G3dGeSetBuffer(GxCommandBuffer *a) {
    if (NNS_G3dGeBuffer == 0) {
        a->mWordCount = 0;
        NNS_G3dGeBuffer = a;
    }
}

GxCommandBuffer *NNS_G3dGeReleaseBuffer(void) {
    GxCommandBuffer *p;

    NNS_G3dGeFlushBuffer();
    p = NNS_G3dGeBuffer;
    NNS_G3dGeBuffer = 0;
    return p;
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

void simpleUnlock_(u32 *a) {
    *a = 0;
}

void NNS_G3dGeSendDL(const void *commands, u32 commandLength) {
    if (commandLength < 0x100 || data_0216f074[0] == 0xffffffff) {
        NNS_G3dGeBufferOP_N(*(u32 *) commands, commands + 4, (commandLength >> 2) - 1);
        return;
    }
    NNS_G3dGeFlushBuffer();
    NNS_G3dFlagGXDmaAsync = 1;
    if (NNS_G3dFlagUseFastDma != 0) {
        MI_SendGXCommandAsyncFast(data_0216f074[0], commands, commandLength, (MIDmaCallback) simpleUnlock_,
                                  &NNS_G3dFlagGXDmaAsync);
    } else {
        MI_SendGXCommandAsync(data_0216f074[0], commands, commandLength, (MIDmaCallback) simpleUnlock_,
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
    renderState->mUnk_e8 = NNS_G3dGetJointScale_FuncArray[renderObj->mResMdl->mInfo.mScalingRule];
    renderState->mUnk_ec = NNS_G3dSendJointSRT_FuncArray[renderObj->mResMdl->mInfo.mScalingRule];
    renderState->mUnk_f0 = NNS_G3dSendTexSRT_FuncArray[renderObj->mResMdl->mInfo.mTexMtxMode];
    renderState->mUnk_e0 = renderObj->mResMdl->mInfo.mPosScale;
    renderState->mUnk_e4 = renderObj->mResMdl->mInfo.mInvPosScale;
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
    s32 i;

    if (animObj == 0) {
        return;
    }
    do {
        for (i = 0; i < animObj->mNumMapData; i++) {
            if (animObj->mMapData[i] & 0x100) {
                hintVector[i >> 5] |= 1 << (i & 0x1f);
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
        renderState->mVisAnmResult = &renderState->mUnk_184;
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
    NNSG3dMatAnmResult *v1;
    u8 *resMat;
    u8 *t;
    s32 matFlags;
    u32 x;
    u32 y;
    u32 commandWords[8];
    s32 c;

    renderState->mCurrentMat = materialIndex;
    renderState->mFlag |= 8;
    renderState->mMatAnmResult = &renderState->mUnk_f4;
    if (renderState->mCbVecFunc[4] != 0) {
        callbackTiming = renderState->mCbVecTiming[4];
    } else {
        callbackTiming = 0;
    }
    v1 = renderState->mRenderObj->mRecMatAnm;
    if (v1 != 0 && !(renderState->mFlag & 0x80)) {
        result = v1 + materialIndex;
        goto done;
    }
    if (option == 0x20 || option == 0x40) {
        cachedBit = 1 << (materialIndex & 0x1f);
        if (renderState->mIsMatCached[materialIndex >> 5] & cachedBit) {
            if (v1 != 0) {
                result = v1 + materialIndex;
            } else {
                result = NNS_G3dRSOnGlb + materialIndex;
            }
            goto done;
        }
    }
    if (v1 != 0) {
        renderState->mIsMatCached[materialIndex >> 5] |= 1 << (materialIndex & 0x1f);
        result = renderState->mRenderObj->mRecMatAnm + materialIndex;
    } else if (option == 0x40) {
        renderState->mIsMatCached[materialIndex >> 5] |= 1 << (materialIndex & 0x1f);
        result = NNS_G3dRSOnGlb + materialIndex;
    } else {
        result = &renderState->mUnk_f4;
    }
    result->mUnk_00 = 0;
    resMat = (u8 *) renderState->mResMat;
    t = resMat + 4;
    c = *(u16 *) (t + *(u16 *) (resMat + 0xa));
    if (*(u16 *) (resMat + *(u32 *) (t + *(u16 *) (resMat + 0xa) + c * materialIndex + 4) + 0x1e) & 0x20) {
        result->mUnk_00 |= 0x20;
    }
    matFlags = *OFFSET_PTR(u16, matData, 0x1e);
    x = ((u32 *) matColorMask_)[(matFlags >> 6) & 7];
    result->mUnk_04 = (data_0217029c.mPrmMatColor0 & ~x) | (*OFFSET_PTR(u32, matData, 4) & x);
    y = ((u32 *) matColorMask_)[(*OFFSET_PTR(u16, matData, 0x1e) >> 9) & 7];
    result->mUnk_08 = (data_0217029c.mPrmMatColor1 & ~y) | (*OFFSET_PTR(u32, matData, 8) & y);
    x = *OFFSET_PTR(u32, matData, 0x10);
    result->mUnk_0c = (data_0217029c.mPrmPolygonAttr & ~x) | (*OFFSET_PTR(u32, matData, 0xc) & x);
    result->mUnk_10 = *OFFSET_PTR(u32, matData, 0x14);
    result->mUnk_14 = *OFFSET_PTR(u16, matData, 0x1c);
    matFlags = *OFFSET_PTR(u16, matData, 0x1e);
    if (matFlags & 1) {
        texMtxData = OFFSET_PTR(u32, matData, 0x2c);
        if (!(matFlags & 2)) {
            result->mUnk_18[0] = texMtxData[0];
            result->mUnk_18[1] = texMtxData[1];
            texMtxData += 2;
        } else {
            result->mUnk_00 |= 1;
        }
        if (!(*OFFSET_PTR(u16, matData, 0x1e) & 4)) {
            result->mUnk_20[0] = ((s16 *) texMtxData)[0];
            result->mUnk_20[1] = ((s16 *) texMtxData)[1];
            texMtxData = (u32 *) ((s16 *) texMtxData + 2);
        } else {
            result->mUnk_00 |= 2;
        }
        if (!(*OFFSET_PTR(u16, matData, 0x1e) & 8)) {
            result->mUnk_24[0] = texMtxData[0];
            result->mUnk_24[1] = texMtxData[1];
        } else {
            result->mUnk_00 |= 4;
        }
        result->mUnk_00 |= 8;
    }
    if (renderState->mRenderObj->mAnmMat != 0 &&
        (renderState->mRenderObj->mHintMatAnmExist[materialIndex >> 5] & (1 << (materialIndex & 0x1f)))) {
        renderState->mRenderObj->mFuncBlendMat(result, renderState->mRenderObj->mAnmMat, materialIndex);
    }
    if (result->mUnk_00 & 0x18) {
        result->mUnk_2c = *OFFSET_PTR(u16, matData, 0x20);
        result->mUnk_2e = *OFFSET_PTR(u16, matData, 0x22);
        result->mUnk_30 = *OFFSET_PTR(u32, matData, 0x24);
        result->mUnk_34 = *OFFSET_PTR(u32, matData, 0x28);
    }
done:
    renderState->mMatAnmResult = result;
    v1 = renderState->mMatAnmResult;
    if (v1->mUnk_0c & 0x1f0000) {
        if (v1->mUnk_00 & 0x20) {
            v1->mUnk_0c &= ~0x1f0000;
        }
        renderState->mFlag &= ~2;
        if (!(renderState->mFlag & 0x100)) {
            commandWords[0] = 0x293130;
            commandWords[1] = v1->mUnk_04;
            commandWords[2] = v1->mUnk_08;
            commandWords[3] = v1->mUnk_0c;
            commandWords[4] = 0x2b2a;
            commandWords[5] = v1->mUnk_10;
            commandWords[6] = v1->mUnk_14;
            NNS_G3dGeBufferOP_N(commandWords[0], &commandWords[1], 6);
            if (v1->mUnk_00 & 0x18) {
                renderState->mUnk_f0(v1);
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
    u8 *t;
    s32 b;

    stateFlags = renderState->mFlag;
    if (!(stateFlags & 0x200)) {
        materialIndex = renderState->mC[1];
        if ((stateFlags & 1) || !(stateFlags & 8) || materialIndex != renderState->mCurrentMat) {
            resMat = (u8 *) renderState->mResMat;
            t = resMat + 4;
            b = *(u16 *) (t + *(u16 *) (resMat + 0xa));
            matData = resMat + *(u32 *) (t + *(u16 *) (resMat + 0xa) + b * materialIndex + 4);
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
    u8 *t;
    u32 shapeIndex;

    stateFlags = renderState->mFlag;
    if (!(stateFlags & 0x200) && (stateFlags & 1) && !(stateFlags & 2)) {
        resShp = renderState->mResShp;
        shapeIndex = renderState->mC[1];
        t = (u8 *) resShp + resShp->mUnk_06;
        shpData = (u8 *) resShp + *(u32 *) (t + *(u16 *) t * shapeIndex + 4);
        NNS_G3dFuncSbcShpTable[*(u16 *) shpData](renderState, option, shpData, shapeIndex);
    }
    renderState->mC += 2;
}

void NNSi_G3dFuncSbc_NODEDESC(NNSG3dRS *renderState, u32 option) {
    s32 b0;
    s32 b1;
    enum { K0 } callbackTiming;
    u32 t;
    u32 q;
    u32 t2;
    u32 commandLength;
    NNSG3dJntAnmResult *jntAnmResult;
    u16 *r;
    s32 k;
    u32 nodeDescIndex;
    u32 stateFlags;
    u32 c;
    s32 v2;
    s32 m;
    u16 *p;
    u8 *resNodeInfo;
    u8 *nodeData;
    NNSG3dRenderObj *renderObj;
    u32 b;

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
                t = renderState->mC[4];
                NNS_G3dGeBufferOP_N(0x14, &t, 1);
            }
        }
        renderState->mC += commandLength;
        return;
    }
    if (option == 0x40 || option == 0x60) {
        commandLength += 1;
        if (option == 0x40) {
            q = renderState->mC[4];
        } else {
            q = renderState->mC[5];
        }
        if (!(renderState->mFlag & 0x100)) {
            NNS_G3dGeBufferOP_N(0x14, &q, 1);
        }
    }
    renderState->mJntAnmResult = &renderState->mUnk_12c;
    if (renderState->mCbVecFunc[6] != 0) {
        callbackTiming = renderState->mCbVecTiming[6];
    } else {
        callbackTiming = 0;
    }
    if (renderState->mRenderObj->mRecJntAnm != 0) {
        jntAnmResult = renderState->mRenderObj->mRecJntAnm + nodeDescIndex;
        c = (renderState->mFlag & 0x80) == 0;
    } else {
        jntAnmResult = &renderState->mUnk_12c;
        c = 0;
    }
    if (c == 0) {
        jntAnmResult->mFlag = 0;
        renderObj = renderState->mRenderObj;
        if (renderObj->mAnmJnt != 0) {
            if (renderObj->mFuncBlendJnt(jntAnmResult, renderObj->mAnmJnt, nodeDescIndex) != 0) {
                goto done;
            }
        }
        resNodeInfo = renderState->mResNodeInfo;
        b = *(u16 *) (resNodeInfo + *(u16 *) (resNodeInfo + 6));
        nodeData = resNodeInfo + *(u32 *) (resNodeInfo + *(u16 *) (resNodeInfo + 6) + b * nodeDescIndex + 4);
        p = (u16 *) nodeData;
        r = OFFSET_PTR(u16, nodeData, 4);
        if (!(*p & 1)) {
            jntAnmResult->mTrans.x = ((s32 *) r)[0];
            jntAnmResult->mTrans.y = ((s32 *) r)[1];
            jntAnmResult->mTrans.z = ((s32 *) r)[2];
            r += 6;
        } else {
            jntAnmResult->mFlag |= 4;
        }
        v2 = *p;
        if (v2 & 2) {
            jntAnmResult->mFlag |= 2;
        } else if (v2 & 8) {
            k = (v2 & 0xf0) >> 4;
            b1 = ((s16 *) r)[1];
            b0 = ((s16 *) r)[0];
            MI_Zero36B(&jntAnmResult->mRot);
            r += 2;
            m = (*p & 0x100) ? -0x1000 : 0x1000;
            jntAnmResult->mRot.a[k] = m;
            jntAnmResult->mRot.a[pivotUtil_[k][0]] = b0;
            jntAnmResult->mRot.a[pivotUtilSecondColumn_[k][0]] = b1;
            if (*p & 0x200) {
                b1 = -b1;
            }
            jntAnmResult->mRot.a[pivotUtilThirdColumn_[k][0]] = b1;
            if (*p & 0x400) {
                b0 = -b0;
            }
            jntAnmResult->mRot.a[pivotUtilFourthColumn_[k][0]] = b0;
        } else {
            jntAnmResult->mRot.a[0] = ((s16 *) p)[1];
            jntAnmResult->mRot.a[1] = ((s16 *) r)[0];
            jntAnmResult->mRot.a[2] = ((s16 *) r)[1];
            jntAnmResult->mRot.a[3] = ((s16 *) r)[2];
            jntAnmResult->mRot.a[4] = ((s16 *) r)[3];
            jntAnmResult->mRot.a[5] = ((s16 *) r)[4];
            jntAnmResult->mRot.a[6] = ((s16 *) r)[5];
            jntAnmResult->mRot.a[7] = ((s16 *) r)[6];
            jntAnmResult->mRot.a[8] = ((s16 *) r)[7];
            r += 8;
        }
        renderState->mUnk_e8(jntAnmResult, r, renderState->mC, *p);
    }
done:
    renderState->mJntAnmResult = jntAnmResult;
    if (!(renderState->mFlag & 0x100)) {
        renderState->mUnk_ec(renderState->mJntAnmResult);
    }
    c = 0;
    renderState->mJntAnmResult = 0;
    if (callbackTiming == 3) {
        renderState->mFlag &= ~0x40;
        renderState->mCbVecFunc[6](renderState);
        c = renderState->mFlag & 0x40;
    }
    if (option == 0x20 || option == 0x60) {
        commandLength += 1;
        if (c == 0 && !(renderState->mFlag & 0x100)) {
            t2 = renderState->mC[4];
            NNS_G3dGeBufferOP_N(0x13, &t2, 1);
        }
    }
    renderState->mC += commandLength;
}

void NNSi_G3dFuncSbc_POSSCALE(NNSG3dRS *renderState, u32 option) {
    s32 scale[3];
    s32 scaleValue;

    if (!(renderState->mFlag & 0x100) && !(renderState->mFlag & 0x200)) {
        if (option == 0) {
            scaleValue = renderState->mUnk_e0;
            scale[2] = scaleValue;
            scale[1] = scaleValue;
            scale[0] = scaleValue;
        } else {
            scaleValue = renderState->mUnk_e4;
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
// OSThread switch after an interrupt: clears the pending flags of the thread list at data_027e0000, then saves the
// registers of the running thread in its context and loads those of the first runnable thread.
// Not compiled code: it switches processor modes and moves the whole register set with the user-bank forms of stm and
// ldm (msr, mrs, ^).
asm void OS_IrqHandler_ThreadSwitch(void) {
    mov r2, #0x1
    mov r3, #0x0
    ldr ip, =data_027e0000
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
    ldr ip, =data_027e0000
    str r3, [ip, #0x0]
    str r3, [ip, #0x4]
    ldr ip, =data_0216ff5c
    mov r1, #0x1
    strh r1, [ip, #0x0]
L_01ff80a8:
    ldr ip, =data_0216ff5c
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
