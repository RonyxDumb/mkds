#include "code_020222ec.h"
#include "g2d_NOB_load.h"
#include "code_0214cfe4.h"
#include "code_02022a60.h"
#include "code_020220b0.h"
#include "code_020222e0.h"
#include "Main/Unknown/unk_02153000.h"
#include "code_0202210c.h"

static inline u32 NNSi_G2dIsCellAnimVramTransferHandleValid(const Unk02022030 *pCellAnim) {
    return pCellAnim->field34 != -1;
}

void ApplyCurrentAnimResult_(Unk02022030 *pCellAnim) {
    Unk020229c8 *animResult;
    Unk02021dc8 *cellBank;
    u32 animType;
    Unk02021e40 *pVramData;
    u32 valid;
    Unk02021e40 *pTransferData;

    if (((Unk02022188 *) pCellAnim->field0)->field4 == 0) {
        return;
    }
    animResult = NNS_G2dGetAnimCtrlCurrentElement(pCellAnim);
    cellBank = pCellAnim->field30;
    pCellAnim->field2C = NNS_G2dGetCellDataByIdx(cellBank, animResult->field0);
    animType = pCellAnim->field18->field4 & 0xff;
    NNSi_G2dSrtcInitControl(&pCellAnim->field38, 1);
    if (animType != 0) {
        if (animType == 2) {
            NNSi_G2dSrtcSetTrans(&pCellAnim->field38, ((Unk020229b4 *) animResult)->field4,
                                 ((Unk020229b4 *) animResult)->field6);
        } else {
            NNSi_G2dSrtcSetSRTScale(&pCellAnim->field38, animResult->field4, animResult->field8);
            NNSi_G2dSrtcSetSRTRotZ(&pCellAnim->field38, animResult->field2);
            NNSi_G2dSrtcSetTrans(&pCellAnim->field38, animResult->fieldC, animResult->fieldE);
        }
    }
    pVramData = cellBank->fieldC;
    valid = pVramData != 0;
    if (valid == 0) {
        return;
    }
    valid = NNSi_G2dIsCellAnimVramTransferHandleValid(pCellAnim);
    if (valid == 0) {
        return;
    }
    pTransferData = &((Unk02021e40 *) pVramData->field4)[animResult->field0];
    NNS_G2dSetCellTransferStateRequested(pCellAnim->field34, pTransferData->field0, pTransferData->field4);
}

void NNS_G2dInitCellAnimation(Unk02022030 *pCellAnim, Unk02021dc8 *pAnimSeq, Unk02021dc8 *pCellDataBank) {
    pCellAnim->field30 = pCellDataBank;
    pCellAnim->field34 = -1;
    NNSi_G2dSrtcInitControl(&pCellAnim->field38, 1);
    NNS_G2dInitAnimCtrl(pCellAnim);
    NNS_G2dSetCellAnimationSequence(pCellAnim, pAnimSeq);
}

void NNS_G2dSetCellAnimationSequence(Unk02022030 *pCellAnim, Unk02021dc8 *pAnimSeq) {
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
    pCellAnim->field10 = speed;
}

static inline u32 G2_GetOBJEffect(u32 attr) {
    u32 effect = attr & 0x300;
    return (effect == 0x100 || effect == 0x300) ? effect : (effect | (attr & 0x30000000));
}

static inline void MulMtx22(const s32 *mtx, const s32 *pSrc, s32 *pDst) {
    s32 buffer[2];
    s32 *result;

    result = pDst;
    if (pSrc == pDst) {
        result = buffer;
    }
    result[0] = ((s64) mtx[2] * pSrc[1] + 0x1000 + (s64) mtx[0] * pSrc[0]) >> 12;
    result[1] = ((s64) mtx[3] * pSrc[1] + 0x1000 + (s64) mtx[1] * pSrc[0]) >> 12;
    if (result == buffer) {
        pDst[0] = buffer[0];
        pDst[1] = buffer[1];
    }
}

u16 NNS_G2dMakeCellToOams(GXOamAttr *pDstOams, u16 numDstOam, Unk020224e0_c *pCell, s32 *pMtxSR, s32 *pBaseTrans,
                          u16 affineIndex, s32 bDoubleAffine) {
    u16 i;
    u16 numAttrs;
    s32 oamOffset[2];
    s32 effectAfter;
    s32 shouldAdjust;
    u32 attr;
    s32 sizeBits;
    s32 shape;
    s32 size;
    GXOamAttr *dstOam;
    Unk020224e0_s *pSrcOam;
    s16 posX;
    s16 posY;
    s32 halfWidth;
    s32 halfHeight;

    numAttrs = pCell->field0;
    if (numDstOam >= numAttrs) {
        numDstOam = numAttrs;
    }
    for (i = 0; i < numDstOam; i++) {
        dstOam = &pDstOams[i];
        pSrcOam = &pCell->field4[i];
        dstOam->field0[0] = pSrcOam->field0;
        dstOam->field0[1] = pSrcOam->field2;
        dstOam->field0[2] = pSrcOam->field4;
        if (pMtxSR != 0 || pBaseTrans != 0) {
            attr = *(u32 *) dstOam;
            posX = (attr & 0x1ff0000) >> 16;
            if (posX > 0xff) {
                posX = posX | 0xff00;
            }
            oamOffset[0] = posX << 12;
            posY = *(u32 *) dstOam & 0xff;
            if (posY > 0x7f) {
                posY = posY | 0xff00;
            }
            oamOffset[1] = posY << 12;
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
                oamOffset[0] += pMtxSR[0] * halfWidth + (s32) - (halfWidth << 12) + pMtxSR[2] * halfHeight;
                oamOffset[1] += pMtxSR[1] * halfWidth + (s32) - (halfHeight << 12) + pMtxSR[3] * halfHeight;
                if (shouldAdjust != 0) {
                    oamOffset[0] -= halfWidth << 12;
                    oamOffset[1] -= halfHeight << 12;
                }
            }
            if (pBaseTrans != 0) {
                oamOffset[0] += pBaseTrans[0];
                oamOffset[1] += pBaseTrans[1];
            }
            *(u32 *) dstOam = (*(u32 *) dstOam & 0xfe00ff00) | (((oamOffset[1] + 0x800) >> 12) & 0xff) |
                              ((((oamOffset[0] + 0x800) >> 12) & 0x1ff) << 16);
        }
    }
    return numDstOam;
}

void NNSi_G2dSrtcSetTrans(Unk02022438 *pCtrl, s16 x, s16 y) {
    if (pCtrl->field0 == 1) {
        pCtrl->field12 |= 8;
        pCtrl->fieldC = x;
        pCtrl->fieldE = y;
    }
}

void NNSi_G2dSrtcSetSRTRotZ(Unk02022438 *pCtrl, u16 rotZ) {
    if (pCtrl->field0 == 1) {
        pCtrl->field12 |= 4;
        pCtrl->field10 = rotZ;
    }
}

void NNSi_G2dSrtcSetSRTScale(Unk02022438 *pCtrl, s32 x, s32 y) {
    if (pCtrl->field0 == 1) {
        pCtrl->field12 |= 2;
        pCtrl->field4 = x;
        pCtrl->field8 = y;
    }
}

void NNSi_G2dSrtcInitControl(Unk02022438 *pCtrl, u32 type) {
    pCtrl->field0 = type;
    NNSi_G2dSrtcSetInitialValue(pCtrl);
}

void NNSi_G2dSrtcSetInitialValue(Unk02022438 *pCtrl) {
    volatile u16 zero;

    zero = 0;
    MIi_CpuClear16(zero, &pCtrl->field4, 0x18);
    pCtrl->field4 = 0x1000;
    pCtrl->field8 = 0x1000;
}

void SequenceEdgeHandle_(Unk02022030 *pAnimCtrl) {
    u32 playMode;
    Unk02021e40 *current;
    Unk02021e40 *last;

    playMode = pAnimCtrl->field14;
    if (playMode == 0) {
        playMode = pAnimCtrl->field18->field8;
    }
    switch (playMode) {
        case 3:
        case 4:
            pAnimCtrl->field4 = pAnimCtrl->field4 ^ 1;
            if (pAnimCtrl->field0 <= &pAnimCtrl->field18->fieldC[pAnimCtrl->field18->field2] - 1) {
                if (pAnimCtrl->mCallbackFunctor.mType == 1) {
                    pAnimCtrl->mCallbackFunctor.mFunc(pAnimCtrl->mCallbackFunctor.mParam, pAnimCtrl->fieldC);
                }
                playMode = pAnimCtrl->field14;
                if (playMode == 0) {
                    playMode = pAnimCtrl->field18->field8;
                }
                if (playMode != 2 && playMode != 4) {
                    pAnimCtrl->field8 = 0;
                } else {
                    NNS_G2dResetAnimCtrlState(pAnimCtrl);
                }
            }
            break;
        default:
            if (pAnimCtrl->mCallbackFunctor.mType == 1) {
                pAnimCtrl->mCallbackFunctor.mFunc(pAnimCtrl->mCallbackFunctor.mParam, pAnimCtrl->fieldC);
            }
            playMode = pAnimCtrl->field14;
            if (playMode == 0) {
                playMode = pAnimCtrl->field18->field8;
            }
            if (playMode != 2 && playMode != 4) {
                pAnimCtrl->field8 = 0;
            } else {
                NNS_G2dResetAnimCtrlState(pAnimCtrl);
            }
            break;
    }
    current = pAnimCtrl->field0;
    last = &pAnimCtrl->field18->fieldC[pAnimCtrl->field18->field0] - 1;
    if (current > last) {
        pAnimCtrl->field0 = last;
        return;
    }
    if (current < pAnimCtrl->field18->fieldC) {
        pAnimCtrl->field0 = pAnimCtrl->field18->fieldC;
    }
}

u32 SetAnimCtrlCurrentFrameImpl_(Unk02022030 *pAnimCtrl, u32 index) {
    if (index < pAnimCtrl->field18->field0) {
        pAnimCtrl->field0 = &pAnimCtrl->field18->fieldC[index];
        return 1;
    }
    return 0;
}
