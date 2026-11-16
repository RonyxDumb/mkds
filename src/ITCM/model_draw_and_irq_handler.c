#include "ITCM/model_draw_and_irq_handler.h"
#include "color_mask_tables.h"
#include "Main/Graphics/animation_function_pointers.h"
#include "system_state_globals.h"
#include "particle_random_state.h"
#include "linked_palette_vram_alloc.h"
#include "microphone_sampling.h"
#include "linked_texture_vram_alloc.h"
#include "Main/Net/block_transfer_and_thread_globals.h"
#include "irq_wait_handler.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "interrupt_control.h"
#include "model_draw_state.h"
#include "dma_copy_fill_wait.h"
#include "coprocessor_context_save.h"
#include "registers.h"
#include "geometry_function_tables_and_fast_dma.h"
#include "vram_bank_display_setup.h"
#include "animation_object_calc.h"
#include "model_material_set.h"

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

void simpleUnlock_(void *target) {
    u32 *flag = target;
    *flag = 0;
}

void NNS_G3dGeSendDL(const void *commands, u32 commandLength) {
    if (commandLength < 0x100 || GXi_DmaId == 0xffffffff) {
        NNS_G3dGeBufferOP_N(*(u32 *) commands, commands + 4, (commandLength >> 2) - 1);
        return;
    }
    NNS_G3dGeFlushBuffer();
    NNS_G3dFlagGXDmaAsync = 1;
    if (NNS_G3dFlagUseFastDma != 0) {
        MI_SendGXCommandAsyncFast(GXi_DmaId, commands, commandLength, simpleUnlock_,
                                  &NNS_G3dFlagGXDmaAsync);
    } else {
        MI_SendGXCommandAsync(GXi_DmaId, commands, commandLength, simpleUnlock_,
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
        renderState->mFlag &= ~RENDER_STATE_SKIP_COMMAND;
        commandByte = renderState->mC[0];
        NNS_G3dFuncSbcTable[commandByte & 0x1f](renderState, commandByte & 0xe0);
    } while (!(renderState->mFlag & RENDER_STATE_DONE));
}

void G3dDrawInternal_(NNSG3dRS *renderState, NNSG3dRenderObj *renderObj) {
    MemFillWordsByBlock_inline(renderState, 0x188);
    renderState->mIsScaleCacheOne[0] = 1;
    renderState->mFlag = RENDER_STATE_NODE_VISIBLE;
    if (renderObj->mPtrUserSbc != 0) {
        renderState->mC = renderObj->mPtrUserSbc;
    } else {
        renderState->mC = OFFSET_PTR(u8, renderObj->mResMdl, renderObj->mResMdl->mOfsSbc);
    }
    renderState->mRenderObj = renderObj;
    renderState->mResNodeInfo = &renderObj->mResMdl->mNodeInfo;
    renderState->mResMat = OFFSET_PTR(NNSG3dResMat, renderObj->mResMdl, renderObj->mResMdl->mOfsMat);
    renderState->mResShp = OFFSET_PTR(void, renderObj->mResMdl, renderObj->mResMdl->mOfsShp);
    renderState->mFuncJntScale = NNS_G3dGetJointScale_FuncArray[renderObj->mResMdl->mInfo.mScalingRule];
    renderState->mFuncJntMtx = NNS_G3dSendJointSRT_FuncArray[renderObj->mResMdl->mInfo.mScalingRule];
    renderState->mFuncTexMtx = NNS_G3dSendTexSRT_FuncArray[renderObj->mResMdl->mInfo.mTexMtxMode];
    renderState->mPosScale = renderObj->mResMdl->mInfo.mPosScale;
    renderState->mInvPosScale = renderObj->mResMdl->mInfo.mInvPosScale;
    if (renderObj->mCbFunc != 0 && renderObj->mCbCmd < G3D_CALLBACK_VECTOR_COUNT) {
        renderState->mCbVecFunc[renderObj->mCbCmd] = renderObj->mCbFunc;
        renderState->mCbVecTiming[renderObj->mCbCmd] = renderObj->mCbTiming;
    }
    if (renderObj->mFlag & RENDER_OBJ_RECORD) {
        renderState->mFlag |= RENDER_STATE_RECORD;
    }
    if (renderObj->mFlag & RENDER_OBJ_NO_GE_COMMANDS) {
        renderState->mFlag |= RENDER_STATE_NO_GE_COMMANDS;
    }
    if (renderObj->mFlag & RENDER_OBJ_SKIP_DRAW) {
        renderState->mFlag |= RENDER_STATE_SKIP_DRAW;
    }
    if (renderObj->mFlag & RENDER_OBJ_SKIP_MATRIX) {
        renderState->mFlag |= RENDER_STATE_SKIP_MATRIX;
    }
    if (renderObj->mCbInitFunc != 0) {
        renderObj->mCbInitFunc(renderState);
    }
    G3dDrawInternal_Loop_(renderState);
    renderObj->mFlag &= ~RENDER_OBJ_RECORD;
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

    if ((renderObj->mFlag & RENDER_OBJ_HINTS_STALE) == RENDER_OBJ_HINTS_STALE) {
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
        renderObj->mFlag &= ~RENDER_OBJ_HINTS_STALE;
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
    renderState->mFlag |= RENDER_STATE_DONE;
}

void NNSi_G3dFuncSbc_NODE(NNSG3dRS *renderState, u32 option) {
    u32 callbackTiming;
    u32 nodeIndex;
    NNSG3dRenderObj *renderObj;

    if (!(renderState->mFlag & RENDER_STATE_SKIP_DRAW)) {
        renderState->mCurrentNode = renderState->mC[1];
        nodeIndex = renderState->mCurrentNode;
        renderState->mFlag |= RENDER_STATE_NODE_SET;
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
            renderState->mFlag |= RENDER_STATE_NODE_VISIBLE;
        } else {
            renderState->mFlag &= ~RENDER_STATE_NODE_VISIBLE;
        }
        if (callbackTiming == 3) {
            renderState->mFlag &= ~RENDER_STATE_SKIP_COMMAND;
            renderState->mCbVecFunc[2](renderState);
        }
    }
    renderState->mC += 3;
}

void NNSi_G3dFuncSbc_MTX(NNSG3dRS *renderState, u32 option) {
    u32 callbackTiming;
    u32 restoreIndex;

    if (!(renderState->mFlag & RENDER_STATE_SKIP_DRAW) && (renderState->mFlag & RENDER_STATE_NODE_VISIBLE)) {
        if (renderState->mCbVecFunc[3] != 0) {
            callbackTiming = renderState->mCbVecTiming[3];
        } else {
            callbackTiming = 0;
        }
        restoreIndex = renderState->mC[1];
        if (!(renderState->mFlag & RENDER_STATE_NO_GE_COMMANDS)) {
            NNS_G3dGeBufferOP_N(0x14, &restoreIndex, 1);
        }
        if (callbackTiming == 3) {
            renderState->mFlag &= ~RENDER_STATE_SKIP_COMMAND;
            renderState->mCbVecFunc[3](renderState);
        }
    }
    renderState->mC += 2;
}

void NNSi_G3dFuncSbc_MAT_InternalDefault(NNSG3dRS *renderState, u32 option, const NNSG3dResMatData *matData,
                                         u32 materialIndex) {
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
    renderState->mFlag |= RENDER_STATE_MATERIAL_SET;
    renderState->mMatAnmResult = &renderState->mTmpMatAnmResult;
    if (renderState->mCbVecFunc[4] != 0) {
        callbackTiming = renderState->mCbVecTiming[4];
    } else {
        callbackTiming = 0;
    }
    matAnm = renderState->mRenderObj->mRecMatAnm;
    if (matAnm != 0 && !(renderState->mFlag & RENDER_STATE_RECORD)) {
        result = matAnm + materialIndex;
        goto done;
    }
    if (option == 0x20 || option == 0x40) {
        cachedBit = 1 << (materialIndex & 0x1f);
        if (renderState->mIsMatCached[materialIndex >> 5] & cachedBit) {
            if (matAnm != 0) {
                result = matAnm + materialIndex;
            } else {
                result = NNS_G3dRSOnGlb.mMatCache + materialIndex;
            }
            goto done;
        }
    }
    if (matAnm != 0) {
        renderState->mIsMatCached[materialIndex >> 5] |= 1 << (materialIndex & 0x1f);
        result = renderState->mRenderObj->mRecMatAnm + materialIndex;
    } else if (option == 0x40) {
        renderState->mIsMatCached[materialIndex >> 5] |= 1 << (materialIndex & 0x1f);
        result = NNS_G3dRSOnGlb.mMatCache + materialIndex;
    } else {
        result = &renderState->mTmpMatAnmResult;
    }
    result->mFlag = 0;
    resMat = (u8 *) renderState->mResMat;
    dictBase = resMat + 4;
    entrySize = *(u16 *) (dictBase + *(u16 *) (resMat + 0xa));
    if (*(u16 *) (resMat + *(u32 *) (dictBase + *(u16 *) (resMat + 0xa) + entrySize * materialIndex + 4) + 0x1e) &
        G3D_MAT_FLAG_CLEAR_ALPHA) {
        result->mFlag |= MAT_RESULT_CLEAR_ALPHA;
    }
    matFlags = matData->mFlag;
    mask = ((u32 *) matColorMask_)[(matFlags >> 6) & 7];
    result->mPrmMatColor0 = (NNS_G3dGlb.mPrmMatColor0 & ~mask) | (matData->mDiffAmb & mask);
    secondMask = ((u32 *) matColorMask_)[(matData->mFlag >> 9) & 7];
    result->mPrmMatColor1 = (NNS_G3dGlb.mPrmMatColor1 & ~secondMask) | (matData->mSpecEmi & secondMask);
    mask = matData->mPolyAttrMask;
    result->mPrmPolygonAttr = (NNS_G3dGlb.mPrmPolygonAttr & ~mask) | (matData->mPolyAttr & mask);
    result->mPrmTexImage = matData->mTexImageParam;
    result->mPrmTexPltt = matData->mTexPlttBase;
    matFlags = matData->mFlag;
    if (matFlags & G3D_MAT_FLAG_HAS_TEX_MTX) {
        texMtxData = (u32 *) matData->mTexMtxData;
        if (!(matFlags & G3D_MAT_FLAG_NO_TEX_SCALE)) {
            result->mScaleST[0] = texMtxData[0];
            result->mScaleST[1] = texMtxData[1];
            texMtxData += 2;
        } else {
            result->mFlag |= MAT_RESULT_TEX_UNIT_SCALE;
        }
        if (!(matData->mFlag & G3D_MAT_FLAG_NO_TEX_ROT)) {
            result->mSinCosR[0] = ((s16 *) texMtxData)[0];
            result->mSinCosR[1] = ((s16 *) texMtxData)[1];
            texMtxData = (u32 *) ((s16 *) texMtxData + 2);
        } else {
            result->mFlag |= MAT_RESULT_TEX_NO_ROTATION;
        }
        if (!(matData->mFlag & G3D_MAT_FLAG_NO_TEX_TRANS)) {
            result->mTransST[0] = texMtxData[0];
            result->mTransST[1] = texMtxData[1];
        } else {
            result->mFlag |= MAT_RESULT_TEX_NO_TRANSLATION;
        }
        result->mFlag |= MAT_RESULT_TEX_MATRIX_SET;
    }
    if (renderState->mRenderObj->mAnmMat != 0 &&
        (renderState->mRenderObj->mHintMatAnmExist[materialIndex >> 5] & (1 << (materialIndex & 0x1f)))) {
        renderState->mRenderObj->mFuncBlendMat(result, renderState->mRenderObj->mAnmMat, materialIndex);
    }
    if (result->mFlag & (MAT_RESULT_TEX_MATRIX_SET | MAT_RESULT_TEX_MATRIX_MULTIPLY)) {
        result->mOrigWidth = matData->mOrigWidth;
        result->mOrigHeight = matData->mOrigHeight;
        result->mMagW = matData->mMagW;
        result->mMagH = matData->mMagH;
    }
done:
    renderState->mMatAnmResult = result;
    matAnm = renderState->mMatAnmResult;
    if (matAnm->mPrmPolygonAttr & G3D_POLY_ATTR_ALPHA_MASK) {
        if (matAnm->mFlag & MAT_RESULT_CLEAR_ALPHA) {
            matAnm->mPrmPolygonAttr &= ~G3D_POLY_ATTR_ALPHA_MASK;
        }
        renderState->mFlag &= ~RENDER_STATE_NO_ALPHA;
        if (!(renderState->mFlag & RENDER_STATE_NO_GE_COMMANDS)) {
            commandWords[0] = 0x293130;
            commandWords[1] = matAnm->mPrmMatColor0;
            commandWords[2] = matAnm->mPrmMatColor1;
            commandWords[3] = matAnm->mPrmPolygonAttr;
            commandWords[4] = 0x2b2a;
            commandWords[5] = matAnm->mPrmTexImage;
            commandWords[6] = matAnm->mPrmTexPltt;
            NNS_G3dGeBufferOP_N(commandWords[0], &commandWords[1], 6);
            if (matAnm->mFlag & (MAT_RESULT_TEX_MATRIX_SET | MAT_RESULT_TEX_MATRIX_MULTIPLY)) {
                renderState->mFuncTexMtx(matAnm);
            }
        }
    } else {
        renderState->mFlag |= RENDER_STATE_NO_ALPHA;
    }
    if (callbackTiming == 3) {
        renderState->mFlag &= ~RENDER_STATE_SKIP_COMMAND;
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
    if (!(stateFlags & RENDER_STATE_SKIP_DRAW)) {
        materialIndex = renderState->mC[1];
        if ((stateFlags & RENDER_STATE_NODE_VISIBLE) || !(stateFlags & RENDER_STATE_MATERIAL_SET) ||
            materialIndex != renderState->mCurrentMat) {
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
    if (!(renderState->mFlag & RENDER_STATE_NO_GE_COMMANDS)) {
        NNS_G3dGeSendDL((u8 *) shpData + shpData->mOfsDL, shpData->mSizeDL);
    }
    if (callbackTiming == 3) {
        renderState->mFlag &= ~RENDER_STATE_SKIP_COMMAND;
        renderState->mCbVecFunc[5](renderState);
    }
}

void NNSi_G3dFuncSbc_SHP(NNSG3dRS *renderState, u32 option) {
    u32 stateFlags;
    NNSG3dResDict *resShp;
    u8 *shpData;
    u8 *entries;
    u32 shapeIndex;

    stateFlags = renderState->mFlag;
    if (!(stateFlags & RENDER_STATE_SKIP_DRAW) && (stateFlags & RENDER_STATE_NODE_VISIBLE) &&
        !(stateFlags & RENDER_STATE_NO_ALPHA)) {
        resShp = renderState->mResShp;
        shapeIndex = renderState->mC[1];
        entries = (u8 *) resShp + resShp->mOfsEntry;
        shpData = (u8 *) resShp + *(u32 *) (entries + *(u16 *) entries * shapeIndex + 4);
        NNS_G3dFuncSbcShpTable[*(u16 *) shpData](renderState, option, shpData, shapeIndex);
    }
    renderState->mC += 2;
}

void NNSi_G3dFuncSbc_NODEDESC(NNSG3dRS *renderState, u32 option) {
    s32 firstValue;
    s32 secondValue;
    enum { CALLBACK_TIMING_NONE } callbackTiming;
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
    renderState->mFlag |= RENDER_STATE_NODE_DESC_SET;
    stateFlags = renderState->mFlag;
    if (stateFlags & RENDER_STATE_SKIP_MATRIX) {
        if (option == 0x40 || option == 0x60) {
            commandLength += 1;
        }
        if (option == 0x20 || option == 0x60) {
            commandLength += 1;
            if (!(stateFlags & RENDER_STATE_NO_GE_COMMANDS)) {
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
        if (!(renderState->mFlag & RENDER_STATE_NO_GE_COMMANDS)) {
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
        flag = (renderState->mFlag & RENDER_STATE_RECORD) == 0;
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
        if (!(*nodeHeader & G3D_NODE_TRANS_IDENTITY)) {
            jntAnmResult->mTrans.x = ((s32 *) dataPointer)[0];
            jntAnmResult->mTrans.y = ((s32 *) dataPointer)[1];
            jntAnmResult->mTrans.z = ((s32 *) dataPointer)[2];
            dataPointer += 6;
        } else {
            jntAnmResult->mFlag |= G3D_JNT_ANM_TRANS_IS_IDENTITY;
        }
        flags = *nodeHeader;
        if (flags & G3D_NODE_ROT_IDENTITY) {
            jntAnmResult->mFlag |= G3D_JNT_ANM_ROT_IS_IDENTITY;
        } else if (flags & G3D_NODE_ROT_PIVOT) {
            pivotIndex = (flags & G3D_NODE_ROT_PIVOT_MASK) >> 4;
            secondValue = ((s16 *) dataPointer)[1];
            firstValue = ((s16 *) dataPointer)[0];
            MI_Zero36B(&jntAnmResult->mRot);
            dataPointer += 2;
            pivotValue = (*nodeHeader & G3D_NODE_ROT_PIVOT_NEGATIVE) ? -0x1000 : 0x1000;
            jntAnmResult->mRot.mElements[pivotIndex] = pivotValue;
            jntAnmResult->mRot.mElements[pivotUtil_[pivotIndex][0]] = firstValue;
            jntAnmResult->mRot.mElements[((const u8 (*)[4]) &pivotUtil_[0][1])[pivotIndex][0]] = secondValue;
            if (*nodeHeader & G3D_NODE_ROT_NEGATE_SECOND) {
                secondValue = -secondValue;
            }
            jntAnmResult->mRot.mElements[((const u8 (*)[4]) &pivotUtil_[0][2])[pivotIndex][0]] = secondValue;
            if (*nodeHeader & G3D_NODE_ROT_NEGATE_FIRST) {
                firstValue = -firstValue;
            }
            jntAnmResult->mRot.mElements[((const u8 (*)[4]) &pivotUtil_[0][3])[pivotIndex][0]] = firstValue;
        } else {
            jntAnmResult->mRot.mElements[0] = ((s16 *) nodeHeader)[1];
            jntAnmResult->mRot.mElements[1] = ((s16 *) dataPointer)[0];
            jntAnmResult->mRot.mElements[2] = ((s16 *) dataPointer)[1];
            jntAnmResult->mRot.mElements[3] = ((s16 *) dataPointer)[2];
            jntAnmResult->mRot.mElements[4] = ((s16 *) dataPointer)[3];
            jntAnmResult->mRot.mElements[5] = ((s16 *) dataPointer)[4];
            jntAnmResult->mRot.mElements[6] = ((s16 *) dataPointer)[5];
            jntAnmResult->mRot.mElements[7] = ((s16 *) dataPointer)[6];
            jntAnmResult->mRot.mElements[8] = ((s16 *) dataPointer)[7];
            dataPointer += 8;
        }
        renderState->mFuncJntScale(jntAnmResult, dataPointer, renderState->mC, *nodeHeader);
    }
done:
    renderState->mJntAnmResult = jntAnmResult;
    if (!(renderState->mFlag & RENDER_STATE_NO_GE_COMMANDS)) {
        renderState->mFuncJntMtx(renderState->mJntAnmResult);
    }
    flag = 0;
    renderState->mJntAnmResult = 0;
    if (callbackTiming == 3) {
        renderState->mFlag &= ~RENDER_STATE_SKIP_COMMAND;
        renderState->mCbVecFunc[6](renderState);
        flag = renderState->mFlag & RENDER_STATE_SKIP_COMMAND;
    }
    if (option == 0x20 || option == 0x60) {
        commandLength += 1;
        if (flag == 0 && !(renderState->mFlag & RENDER_STATE_NO_GE_COMMANDS)) {
            storeIndex = renderState->mC[4];
            NNS_G3dGeBufferOP_N(0x13, &storeIndex, 1);
        }
    }
    renderState->mC += commandLength;
}

void NNSi_G3dFuncSbc_POSSCALE(NNSG3dRS *renderState, u32 option) {
    s32 scale[3];
    s32 scaleValue;

    if (!(renderState->mFlag & RENDER_STATE_NO_GE_COMMANDS) && !(renderState->mFlag & RENDER_STATE_SKIP_DRAW)) {
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
// Interrupt dispatch: returns at once if reg_OS_IME is zero or no enabled interrupt is pending; otherwise takes the
// lowest pending bit of reg_OS_IE and reg_OS_IF (found with clz), acknowledges it in reg_OS_IF, and runs the function
// in OS_IRQTable for that bit with lr set to OS_IrqHandler_ThreadSwitch; the function is entered by bx after
// ldr lr, not by a call.
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
// OSThread switch after an interrupt: makes the threads queued at OSi_IrqThreadQueue runnable and empties the queue,
// then, if a reschedule is asked for and the first runnable thread is a different one, saves the registers of the
// running thread in its context and loads those of that thread; it switches processor modes (msr, mrs) and moves the
// whole register set with the user-bank forms of stm and ldm (^).
asm void OS_IrqHandler_ThreadSwitch(void) {
    mov r2, #0x1
    mov r3, #0x0
    ldr ip, =OSi_IrqThreadQueue
    ldr ip, [ip, #0x0]
    cmp ip, #0x0
    beq L_CheckRescheduleFlag
L_WakeQueuedThreads:
    str r2, [ip, #0x64]
    str r3, [ip, #0x78]
    str r3, [ip, #0x7c]
    ldr r0, [ip, #0x80]
    str r3, [ip, #0x80]
    mov ip, r0
    cmp ip, #0x0
    bne L_WakeQueuedThreads
    ldr ip, =OSi_IrqThreadQueue
    str r3, [ip, #0x0]
    str r3, [ip, #0x4]
    ldr ip, =OSi_ThreadInfo
    mov r1, #0x1
    strh r1, [ip, #0x0]
L_CheckRescheduleFlag:
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
L_FindRunnableThread:
    cmp r1, #0x0
    ldrneh r0, [r1, #0x64]
    cmpne r0, #0x1
    ldrne r1, [r1, #0x68]
    bne L_FindRunnableThread
    cmp r1, #0x0
    bne L_CheckThreadChanged
L_KeepCurrentThread:
    mov r3, #0x92
    msr cpsr_c, r3
    ldr pc, [sp], #0x4
L_CheckThreadChanged:
    ldr r0, [ip, #0x4]
    cmp r1, r0
    beq L_KeepCurrentThread
    ldr r3, [ip, #0xc]
    cmp r3, #0x0
    beq L_SaveRunningContext
    stmdb sp!, {r0, r1, ip}
    mov lr, pc
    bx r3
    ldmia sp!, {r0, r1, ip}
L_SaveRunningContext:
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
