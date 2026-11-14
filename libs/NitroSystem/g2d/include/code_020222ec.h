#pragma once

#include "types.h"
#include "g2d_Animation.h" // NNSG2dCellAnimation, NNSG2dSRTControl, NNSG2dCellDataWithBR, GXOamAttr
#include "code_02012b30.h" // MtxFx22

u32 SetAnimCtrlCurrentFrameImpl_(NNSG2dCellAnimation *pAnimCtrl, u32 index);
void SequenceEdgeHandle_(NNSG2dCellAnimation *pAnimCtrl);
void NNSi_G2dSrtcSetInitialValue(NNSG2dSRTControl *pCtrl);
void NNSi_G2dSrtcInitControl(NNSG2dSRTControl *pCtrl, u32 type);
void NNSi_G2dSrtcSetSRTScale(NNSG2dSRTControl *pCtrl, s32 x, s32 y);
void NNSi_G2dSrtcSetSRTRotZ(NNSG2dSRTControl *pCtrl, u16 rotZ);
void NNSi_G2dSrtcSetTrans(NNSG2dSRTControl *pCtrl, s16 x, s16 y);
u16 NNS_G2dMakeCellToOams(GXOamAttr *pDstOams, u16 numDstOam, NNSG2dCellDataWithBR *pCell, MtxFx22 *pMtxSR,
                          s32 *pBaseTrans, u16 affineIndex, s32 bDoubleAffine);
void NNS_G2dSetCellAnimationSpeed(NNSG2dCellAnimation *pCellAnim, s32 speed);
void NNS_G2dSetCellAnimationCurrentFrame(NNSG2dCellAnimation *pCellAnim, u16 frameIndex);
void NNS_G2dTickCellAnimation(NNSG2dCellAnimation *pCellAnim, s32 frames);
void NNS_G2dSetCellAnimationSequence(NNSG2dCellAnimation *pCellAnim, NNSG2dAnimSequenceData *pAnimSeq);
void NNS_G2dInitCellAnimation(NNSG2dCellAnimation *pCellAnim, NNSG2dAnimSequenceData *pAnimSeq,
                              NNSG2dCellDataBank *pCellDataBank);
void ApplyCurrentAnimResult_(NNSG2dCellAnimation *pCellAnim);

extern const u16 gObjShapeHeight[3][4];
extern const u16 gObjShapeWidth[3][4];
