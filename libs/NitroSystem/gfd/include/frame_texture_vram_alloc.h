#pragma once

#include "types.h"

// End of a region at reset: 128 KB, or 64 KB when mBHalfSize is set.
#define FRM_TEX_REGION_FULL_END 0x20000
#define FRM_TEX_REGION_HALF_END 0x10000

// Values of NNSGfdFrmTexRegionState.mIndex of the two regions listed in tex4x4SearchArray_, the ones
// NNS_GfdAllocFrmTexVram uses when is4x4comp is set; each is paired with a half-size region (palRegion) whose mHead
// NNS_GfdAllocFrmTexVram advances by half the size.
#define FRM_TEX_REGION_4X4_FIRST 0
#define FRM_TEX_REGION_4X4_SECOND 3

// One texture VRAM region of the frame manager.
typedef struct NNSGfdFrmTexRegionState {
    /* 00 */ u32 mHead;
    /* 04 */ u32 mTail;
    /* 08 */ u32 mBActive;
    /* 0c */ u32 mBHalfSize;
    /* 10 */ u16 mIndex;
    /* 12 */ u16 mPad16;
    /* 14 */ u32 mBaseAddress;
} NNSGfdFrmTexRegionState;

extern NNSGfdFrmTexRegionState *tex4x4SearchArray_[2];
extern NNSGfdFrmTexRegionState *texNrmSearchArray_[5];
extern NNSGfdFrmTexRegionState vramRegions_[5];
extern u16 frmExVramMan_;

s32 NNS_GfdFreeFrmTexVram(u32 texKey);
u32 NNS_GfdAllocFrmTexVram(u32 szByte, u32 is4x4comp, u32 opt);
void NNS_GfdResetFrmTexVramState(void);
void NNS_GfdInitFrmTexVramManager(u16 numBanks, BOOL useAsDefault);
void NNSi_GfdSetTexNrmSearchArray(int idx1st, int idx2nd, int idx3rd, int idx4th, int idx5th);

extern s32 (*NNS_GfdDefaultFuncFreeTexVram)(u32);
extern s32 (*NNS_GfdDefaultFuncFreePlttVram)(u32);
extern u32 (*NNS_GfdDefaultFuncAllocTexVram)(s32 szByte, s32 is4x4comp, s32 opt);
extern u32 (*NNS_GfdDefaultFuncAllocPlttVram)(s32 szByte, s32 is4pltt, s32 opt);
