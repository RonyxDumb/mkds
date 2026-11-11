#pragma once

#include "types.h"
#include "code_02022030.h" // Unk02022030, NNSG2dSRTControl, NNSG2dCellDataWithBR, GXOamAttr
#include "code_02012b30.h" // MtxFx22

u32 SetAnimCtrlCurrentFrameImpl_(Unk02022030 *pAnimCtrl, u32 index);
void SequenceEdgeHandle_(Unk02022030 *pAnimCtrl);
void NNSi_G2dSrtcSetInitialValue(NNSG2dSRTControl *pCtrl);
void NNSi_G2dSrtcInitControl(NNSG2dSRTControl *pCtrl, u32 type);
void NNSi_G2dSrtcSetSRTScale(NNSG2dSRTControl *pCtrl, s32 x, s32 y);
void NNSi_G2dSrtcSetSRTRotZ(NNSG2dSRTControl *pCtrl, u16 rotZ);
void NNSi_G2dSrtcSetTrans(NNSG2dSRTControl *pCtrl, s16 x, s16 y);
u16 NNS_G2dMakeCellToOams(GXOamAttr *pDstOams, u16 numDstOam, NNSG2dCellDataWithBR *pCell, MtxFx22 *pMtxSR,
                          s32 *pBaseTrans, u16 affineIndex, s32 bDoubleAffine);
void NNS_G2dSetCellAnimationSpeed(Unk02022030 *pCellAnim, s32 speed);
void NNS_G2dSetCellAnimationCurrentFrame(Unk02022030 *pCellAnim, u16 frameIndex);
void NNS_G2dTickCellAnimation(Unk02022030 *pCellAnim, s32 frames);
void NNS_G2dSetCellAnimationSequence(Unk02022030 *pCellAnim, NNSG2dAnimSequenceData *pAnimSeq);
void NNS_G2dInitCellAnimation(Unk02022030 *pCellAnim, NNSG2dAnimSequenceData *pAnimSeq, Unk02021dc8 *pCellDataBank);
void ApplyCurrentAnimResult_(Unk02022030 *pCellAnim);
