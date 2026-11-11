#pragma once

#include "types.h"
#include "g2d_NAN_load.h" // Unk02021dc8, NNSG2dCellVramTransferData

// 0x1c bytes: NNSi_G2dSrtcSetInitialValue clears everything after the first word and sets mUnk_04 and mUnk_08 to
// 0x1000. NNSi_G2dSrtcSetSRTScale, NNSi_G2dSrtcSetSRTRotZ and NNSi_G2dSrtcSetTrans set a member and a bit of mUnk_12
// when mUnk_00 is 1.
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

typedef struct Unk02022030 {
    /* 00 */ NNSG2dAnimFrameData *mPCurrent;
    /* 04 */ u32 mReverse;
    /* 08 */ u32 mActive;
    /* 0c */ s32 mCurrentTime;
    /* 10 */ s32 mSpeed;
    /* 14 */ u32 mOverriddenPlayMode;
    /* 18 */ NNSG2dAnimSequenceData *mPAnimSequence;
    /* 1c */ NNSG2dCallBackFunctor mCallbackFunctor;
    /* 2c */ NNSG2dCellDataWithBR *mPCurrentCell;
    /* 30 */ Unk02021dc8 *mPCellDataBank;
    /* 34 */ s32 mCellTransferStateHandle;
    /* 38 */ NNSG2dSRTControl mSrtCtrl;
} Unk02022030;

// Record at the first word of the element: ApplyCurrentAnimResult_ reads these members, except when the low byte of
// mUnk_04 of the header is 2 (then Unk020229b4).
struct NNSG2dAnimDataSRT {
    /* 00 */ u16 mIndex;
    /* 02 */ u16 mRotZ;
    /* 04 */ s32 mSx;
    /* 08 */ s32 mSy;
    /* 0c */ s16 mPx;
    /* 0e */ s16 mPy;
};

typedef struct Unk020229b4 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
} Unk020229b4;

void NNS_G2dBindAnimCtrl(Unk02022030 *pAnimCtrl, NNSG2dAnimSequenceData *pAnimSequence);
void NNS_G2dResetAnimCtrlState(Unk02022030 *pAnimCtrl);
