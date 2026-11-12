#include "code_020222ec.h"
#include "g2d_NOB_load.h"
#include "code_0214cfe4.h"
#include "code_02022a60.h"
#include "g2d_Animation.h"
#include "Main/Unknown/unk_02153000.h"

static inline u32 NNSi_G2dIsCellAnimVramTransferHandleValid(const Unk02022030 *pCellAnim) {
    return pCellAnim->mCellTransferStateHandle != -1;
}

void ApplyCurrentAnimResult_(Unk02022030 *pCellAnim) {
    NNSG2dAnimDataSRT *animResult;
    Unk02021dc8 *cellBank;
    u32 animType;
    NNSG2dVramTransferData *pVramData;
    u32 valid;
    NNSG2dCellVramTransferData *pTransferData;

    if (pCellAnim->mPCurrent->mFrames == 0) {
        return;
    }
    animResult = NNS_G2dGetAnimCtrlCurrentElement(pCellAnim);
    cellBank = pCellAnim->mPCellDataBank;
    pCellAnim->mPCurrentCell = NNS_G2dGetCellDataByIdx(cellBank, animResult->mIndex);
    animType = pCellAnim->mPAnimSequence->mAnimType & 0xff;
    NNSi_G2dSrtcInitControl(&pCellAnim->mSrtCtrl, 1);
    if (animType != 0) {
        if (animType == 2) {
            NNSi_G2dSrtcSetTrans(&pCellAnim->mSrtCtrl, ((NNSG2dAnimDataT *) animResult)->mPx,
                                 ((NNSG2dAnimDataT *) animResult)->mPy);
        } else {
            NNSi_G2dSrtcSetSRTScale(&pCellAnim->mSrtCtrl, animResult->mSx, animResult->mSy);
            NNSi_G2dSrtcSetSRTRotZ(&pCellAnim->mSrtCtrl, animResult->mRotZ);
            NNSi_G2dSrtcSetTrans(&pCellAnim->mSrtCtrl, animResult->mPx, animResult->mPy);
        }
    }
    pVramData = cellBank->mPVramTransferData;
    valid = pVramData != 0;
    if (valid == 0) {
        return;
    }
    valid = NNSi_G2dIsCellAnimVramTransferHandleValid(pCellAnim);
    if (valid == 0) {
        return;
    }
    pTransferData = &pVramData->mPCellTransferDataArray[animResult->mIndex];
    NNS_G2dSetCellTransferStateRequested(pCellAnim->mCellTransferStateHandle, pTransferData->mSrcDataOffset,
                                         pTransferData->mSzByte);
}

void NNS_G2dInitCellAnimation(Unk02022030 *pCellAnim, NNSG2dAnimSequenceData *pAnimSeq, Unk02021dc8 *pCellDataBank) {
    pCellAnim->mPCellDataBank = pCellDataBank;
    pCellAnim->mCellTransferStateHandle = -1;
    NNSi_G2dSrtcInitControl(&pCellAnim->mSrtCtrl, 1);
    NNS_G2dInitAnimCtrl(pCellAnim);
    NNS_G2dSetCellAnimationSequence(pCellAnim, pAnimSeq);
}

void NNS_G2dSetCellAnimationSequence(Unk02022030 *pCellAnim, NNSG2dAnimSequenceData *pAnimSeq) {
    NNS_G2dBindAnimCtrl(pCellAnim, pAnimSeq);
    ApplyCurrentAnimResult_(pCellAnim);
}

void NNS_G2dTickCellAnimation(Unk02022030 *pCellAnim, s32 frames) {
    if (NNS_G2dTickAnimCtrl(pCellAnim, frames) == 0) {
        return;
    }
    ApplyCurrentAnimResult_(pCellAnim);
}

void NNS_G2dSetCellAnimationCurrentFrame(Unk02022030 *pCellAnim, u16 frameIndex) {
    if (NNS_G2dSetAnimCtrlCurrentFrame(pCellAnim, frameIndex) == 0) {
        return;
    }
    ApplyCurrentAnimResult_(pCellAnim);
}

void NNS_G2dSetCellAnimationSpeed(Unk02022030 *pCellAnim, s32 speed) {
    pCellAnim->mSpeed = speed;
}

static inline u32 G2_GetOBJEffect(u32 attr) {
    u32 effect = attr & 0x300;
    return (effect == 0x100 || effect == 0x300) ? effect : (effect | (attr & 0x30000000));
}

static inline void MulMtx22(const MtxFx22 *mtx, const s32 *pSrc, s32 *pDst) {
    s32 buffer[2];
    s32 *result;

    result = pDst;
    if (pSrc == pDst) {
        result = buffer;
    }
    result[0] = ((s64) mtx->mUnk_00[2] * pSrc[1] + 0x1000 + (s64) mtx->mUnk_00[0] * pSrc[0]) >> 12;
    result[1] = ((s64) mtx->mUnk_00[3] * pSrc[1] + 0x1000 + (s64) mtx->mUnk_00[1] * pSrc[0]) >> 12;
    if (result == buffer) {
        pDst[0] = buffer[0];
        pDst[1] = buffer[1];
    }
}

u16 NNS_G2dMakeCellToOams(GXOamAttr *pDstOams, u16 numDstOam, NNSG2dCellDataWithBR *pCell, MtxFx22 *pMtxSR,
                          s32 *pBaseTrans, u16 affineIndex, s32 bDoubleAffine) {
    u16 oamIndex;
    u16 numAttrs;
    s32 oamOffset[2];
    s32 effectAfter;
    s32 shouldAdjust;
    u32 attr;
    s32 sizeBits;
    s32 shape;
    s32 size;
    GXOamAttr *dstOam;
    NNSG2dCellOAMAttrData *pSrcOam;
    s16 posX;
    s16 posY;
    s32 halfWidth;
    s32 halfHeight;

    numAttrs = pCell->mNumOAMAttrs;
    if (numDstOam >= numAttrs) {
        numDstOam = numAttrs;
    }
    for (oamIndex = 0; oamIndex < numDstOam; oamIndex++) {
        dstOam = &pDstOams[oamIndex];
        pSrcOam = &pCell->mPOamAttrArray[oamIndex];
        dstOam->mUnk_00[0] = pSrcOam->mAttr0;
        dstOam->mUnk_00[1] = pSrcOam->mAttr1;
        dstOam->mUnk_00[2] = pSrcOam->mAttr2;
        if (pMtxSR != 0 || pBaseTrans != 0) {
            attr = *(u32 *) dstOam;
            posX = (attr & 0x1ff0000) >> 16;
            if (posX > 0xff) {
                posX = posX | 0xff00;
            }
            oamOffset[0] = TO_FIXED12(posX);
            posY = *(u32 *) dstOam & 0xff;
            if (posY > 0x7f) {
                posY = posY | 0xff00;
            }
            oamOffset[1] = TO_FIXED12(posY);
            if (pMtxSR != 0) {
                attr = *(u32 *) dstOam;
                if (G2_GetOBJEffect(attr) == 0x300) {
                    sizeBits = attr & 0xc000c000;
                    shape = (sizeBits & 0xc000) >> 14;
                    size = (sizeBits & 0xc0000000) >> 30;
                    oamOffset[0] += data_021530d0[shape][size] << 11;
                    oamOffset[1] += data_021530b8[shape][size] << 11;
                }
                effectAfter = bDoubleAffine != 0 ? 0x300 : 0x100;
                shouldAdjust = effectAfter == 0x300 ? 1 : 0;
                MulMtx22(pMtxSR, oamOffset, oamOffset);
                if (effectAfter != 0x100 && effectAfter != 0x300) {
                    *(u32 *) dstOam = (*(u32 *) dstOam & 0xc1fffcff) | effectAfter;
                } else {
                    *(u32 *) dstOam = ((*(u32 *) dstOam & 0xc1fffcff) | effectAfter) | (affineIndex << 25);
                }
                attr = *(u32 *) dstOam;
                sizeBits = attr & 0xc000c000;
                shape = (sizeBits & 0xc000) >> 14;
                size = (sizeBits & 0xc0000000) >> 30;
                halfWidth = data_021530d0[shape][size] >> 1;
                halfHeight = data_021530b8[shape][size] >> 1;
                oamOffset[0] +=
                    pMtxSR->mUnk_00[0] * halfWidth + (s32) -TO_FIXED12(halfWidth) + pMtxSR->mUnk_00[2] * halfHeight;
                oamOffset[1] +=
                    pMtxSR->mUnk_00[1] * halfWidth + (s32) -TO_FIXED12(halfHeight) + pMtxSR->mUnk_00[3] * halfHeight;
                if (shouldAdjust != 0) {
                    oamOffset[0] -= TO_FIXED12(halfWidth);
                    oamOffset[1] -= TO_FIXED12(halfHeight);
                }
            }
            if (pBaseTrans != 0) {
                oamOffset[0] += pBaseTrans[0];
                oamOffset[1] += pBaseTrans[1];
            }
            *(u32 *) dstOam = (*(u32 *) dstOam & 0xfe00ff00) | (((oamOffset[1] + 0x800) >> 12) & 0xff) |
                              ((FROM_FIXED12(oamOffset[0] + 0x800) & 0x1ff) << 16);
        }
    }
    return numDstOam;
}

void NNSi_G2dSrtcSetTrans(NNSG2dSRTControl *pCtrl, s16 x, s16 y) {
    if (pCtrl->mType == 1) {
        pCtrl->mSRTEnableFlag |= 8;
        pCtrl->mTransX = x;
        pCtrl->mTransY = y;
    }
}

void NNSi_G2dSrtcSetSRTRotZ(NNSG2dSRTControl *pCtrl, u16 rotZ) {
    if (pCtrl->mType == 1) {
        pCtrl->mSRTEnableFlag |= 4;
        pCtrl->mRotZ = rotZ;
    }
}

void NNSi_G2dSrtcSetSRTScale(NNSG2dSRTControl *pCtrl, s32 x, s32 y) {
    if (pCtrl->mType == 1) {
        pCtrl->mSRTEnableFlag |= 2;
        pCtrl->mScaleX = x;
        pCtrl->mScaleY = y;
    }
}

void NNSi_G2dSrtcInitControl(NNSG2dSRTControl *pCtrl, u32 type) {
    pCtrl->mType = type;
    NNSi_G2dSrtcSetInitialValue(pCtrl);
}

void NNSi_G2dSrtcSetInitialValue(NNSG2dSRTControl *pCtrl) {
    volatile u16 zero;

    zero = 0;
    MIi_CpuClear16(zero, &pCtrl->mScaleX, 0x18);
    pCtrl->mScaleX = 0x1000;
    pCtrl->mScaleY = 0x1000;
}

void SequenceEdgeHandle_(Unk02022030 *pAnimCtrl) {
    u32 playMode;
    NNSG2dAnimFrameData *current;
    NNSG2dAnimFrameData *last;

    playMode = pAnimCtrl->mOverriddenPlayMode;
    if (playMode == 0) {
        playMode = pAnimCtrl->mPAnimSequence->mPlayMode;
    }
    switch (playMode) {
        case 3:
        case 4:
            pAnimCtrl->mReverse = pAnimCtrl->mReverse ^ 1;
            if (pAnimCtrl->mPCurrent <=
                &pAnimCtrl->mPAnimSequence->mPAnmFrameArray[pAnimCtrl->mPAnimSequence->mLoopStartFrameIdx] - 1) {
                if (pAnimCtrl->mCallbackFunctor.mType == 1) {
                    pAnimCtrl->mCallbackFunctor.mFunc(pAnimCtrl->mCallbackFunctor.mParam, pAnimCtrl->mCurrentTime);
                }
                playMode = pAnimCtrl->mOverriddenPlayMode;
                if (playMode == 0) {
                    playMode = pAnimCtrl->mPAnimSequence->mPlayMode;
                }
                if (playMode != 2 && playMode != 4) {
                    pAnimCtrl->mActive = 0;
                } else {
                    NNS_G2dResetAnimCtrlState(pAnimCtrl);
                }
            }
            break;
        default:
            if (pAnimCtrl->mCallbackFunctor.mType == 1) {
                pAnimCtrl->mCallbackFunctor.mFunc(pAnimCtrl->mCallbackFunctor.mParam, pAnimCtrl->mCurrentTime);
            }
            playMode = pAnimCtrl->mOverriddenPlayMode;
            if (playMode == 0) {
                playMode = pAnimCtrl->mPAnimSequence->mPlayMode;
            }
            if (playMode != 2 && playMode != 4) {
                pAnimCtrl->mActive = 0;
            } else {
                NNS_G2dResetAnimCtrlState(pAnimCtrl);
            }
            break;
    }
    current = pAnimCtrl->mPCurrent;
    last = &pAnimCtrl->mPAnimSequence->mPAnmFrameArray[pAnimCtrl->mPAnimSequence->mNumFrames] - 1;
    if (current > last) {
        pAnimCtrl->mPCurrent = last;
        return;
    }
    if (current < pAnimCtrl->mPAnimSequence->mPAnmFrameArray) {
        pAnimCtrl->mPCurrent = pAnimCtrl->mPAnimSequence->mPAnmFrameArray;
    }
}

u32 SetAnimCtrlCurrentFrameImpl_(Unk02022030 *pAnimCtrl, u32 index) {
    if (index < pAnimCtrl->mPAnimSequence->mNumFrames) {
        pAnimCtrl->mPCurrent = &pAnimCtrl->mPAnimSequence->mPAnmFrameArray[index];
        return 1;
    }
    return 0;
}
