#pragma once

#include "types.h"
#include "g2d_NAN_load.h" // NNSG2dCellDataBank, NNSG2dCellVramTransferData

typedef struct NNSG2dSRTControl {
    /* 00 */ u32 mType;
    /* 04 */ s32 mScaleX;
    /* 08 */ s32 mScaleY;
    /* 0c */ s16 mTransX;
    /* 0e */ s16 mTransY;
    /* 10 */ u16 mRotZ;
    /* 12 */ u16 mSRTEnableFlag;
    /* 14 */ u8 mUnk_14[8];
} NNSG2dSRTControl;

typedef struct NNSG2dCallBackFunctor {
    /* 00 */ u32 mType;
    /* 04 */ u32 mParam;
    /* 08 */ UnkFunc *mFunc;
    /* 0c */ u16 mFrameIdx;
} NNSG2dCallBackFunctor;

typedef struct NNSG2dCellOAMAttrData {
    /* 00 */ u16 mAttr0;
    /* 02 */ u16 mAttr1;
    /* 04 */ u16 mAttr2;
} NNSG2dCellOAMAttrData;

typedef struct GXOamAttr {
    /* 00 */ u16 mUnk_00[4];
} GXOamAttr;

// Rotation and scaling parameters: four OAM entries whose last halfwords hold PA, PB, PC and PD.
typedef struct GXOamAffine {
    /* 00 */ u16 mUnk_00[3];
    /* 06 */ s16 mPA;
    /* 08 */ u16 mUnk_08[3];
    /* 0e */ s16 mPB;
    /* 10 */ u16 mUnk_10[3];
    /* 16 */ s16 mPC;
    /* 18 */ u16 mUnk_18[3];
    /* 1e */ s16 mPD;
} GXOamAffine;

// Cell of a cell bank: the count, the attribute entries, then the bounds (absent when bit 0 of the bank's mUnk_02 is
// clear).
typedef struct NNSG2dCellDataWithBR {
    /* 00 */ u16 mNumOAMAttrs;
    /* 02 */ u16 mCellAttr;
    /* 04 */ NNSG2dCellOAMAttrData *mPOamAttrArray;
    /* 08 */ s16 mMaxX;
    /* 0a */ s16 mMaxY;
    /* 0c */ s16 mMinX;
    /* 0e */ s16 mMinY;
} NNSG2dCellDataWithBR;

typedef struct NNSG2dCellAnimation {
    /* 00 */ NNSG2dAnimFrameData *mPCurrent;
    /* 04 */ u32 mReverse;
    /* 08 */ u32 mActive;
    /* 0c */ s32 mCurrentTime;
    /* 10 */ s32 mSpeed;
    /* 14 */ u32 mOverriddenPlayMode;
    /* 18 */ NNSG2dAnimSequenceData *mPAnimSequence;
    /* 1c */ NNSG2dCallBackFunctor mCallbackFunctor;
    /* 2c */ NNSG2dCellDataWithBR *mPCurrentCell;
    /* 30 */ NNSG2dCellDataBank *mPCellDataBank;
    /* 34 */ s32 mCellTransferStateHandle;
    /* 38 */ NNSG2dSRTControl mSrtCtrl;
} NNSG2dCellAnimation;

// Record at the first word of the element: ApplyCurrentAnimResult_ reads these members, except when the low byte of
// mUnk_04 of the header is 2 (then NNSG2dAnimDataT).
struct NNSG2dAnimDataSRT {
    /* 00 */ u16 mIndex;
    /* 02 */ u16 mRotZ;
    /* 04 */ s32 mSx;
    /* 08 */ s32 mSy;
    /* 0c */ s16 mPx;
    /* 0e */ s16 mPy;
};

typedef struct NNSG2dAnimDataT {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mPad;
    /* 04 */ s16 mPx;
    /* 06 */ s16 mPy;
} NNSG2dAnimDataT;

void NNS_G2dBindAnimCtrl(NNSG2dCellAnimation *pAnimCtrl, NNSG2dAnimSequenceData *pAnimSequence);
void NNS_G2dResetAnimCtrlState(NNSG2dCellAnimation *pAnimCtrl);

void NNS_G2dInitAnimCallBackFunctor(NNSG2dCallBackFunctor *pCallBack);

void NNS_G2dInitAnimCtrl(NNSG2dCellAnimation *pAnimCtrl);

u16 NNS_G2dGetAnimCtrlCurrentFrame(const NNSG2dCellAnimation *pAnimCtrl);

u32 NNS_G2dSetAnimCtrlCurrentFrame(NNSG2dCellAnimation *pAnimCtrl, u32 index);
u32 NNS_G2dTickAnimCtrl(NNSG2dCellAnimation *pAnimCtrl, s32 frames);

NNSG2dAnimDataSRT *NNS_G2dGetAnimCtrlCurrentElement(NNSG2dCellAnimation *pAnimCtrl);
