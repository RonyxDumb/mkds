#pragma once

#include "types.h"

typedef struct NNSG3dAnmObj NNSG3dAnmObj;
typedef struct Nsbmd Nsbmd;

// Values of ModelAnimation.mKind: the kind of animation the entries hold.
typedef enum {
    MODEL_ANIMATION_KIND_JOINT,
    MODEL_ANIMATION_KIND_TEX_SRT,
    MODEL_ANIMATION_KIND_TEX_PAT,
    MODEL_ANIMATION_KIND_VIS,
    MODEL_ANIMATION_KIND_MAT_C
} ModelAnimationKind;

// One model's animations: a table of animation objects and one loop flag per entry; one entry plays at a time.
// A change of entry can fade from the old one (StructAM_SomeFn_MaybeForceLoadBlock).
typedef struct ModelAnimationFrameLoop {
    /* 00 */ u16 mLoopMode;
    /* 02 */ u16 mDone;
    /* 04 */ s32 mFrameCountFixed;
    /* 08 */ s32 mFrameStep;
    /* 0c */ s32 mFrameIndex;
    /* 10 */ u16 mLoopsDone;
    /* 12 */ u16 mLoopCount;
} ModelAnimationFrameLoop;

// ModelAnimation.mBlendRatioStep set by the animation reset: about a tenth of the whole blend ratio per frame.
#define MODEL_ANIMATION_BLEND_RATIO_STEP 0x19a

// The animations of a model: the list of them, the current one and the blend into the previous one.
typedef struct ModelAnimation {
    /* 00 */ ModelAnimationFrameLoop mHead;
    /* 14 */ Nsbmd *mRenderObj;
    /* 18 */ u16 mAnmObjCount;
    /* 1a */ u16 mCurrentIndex;
    /* 1c */ NNSG3dAnmObj **mAnmObjs;
    /* 20 */ u32 *mLoopFlags;
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ u32 mKind;
    /* 2c */ BOOL mBlending;
    /* 30 */ s32 mBlendRatioStep;
    /* 34 */ NNSG3dAnmObj *mPreviousAnmObj;
} ModelAnimation;

s32 StructAM_GetFrameCount_Times4096(ModelAnimation *modelAnimation);
void StructAM_SomeFn_5(ModelAnimation *modelAnimation);
void StructAM_SomeFn_MaybeMoveNextFrame(ModelAnimation *modelAnimation);
void StructAM_SomeFn_MaybeForceLoadBlock(ModelAnimation *modelAnimation, u16 entryIndex);
void StructAM_SomeFn_MaybeLoadFrame(ModelAnimation *modelAnimation, s32 entryIndex);
void StructAM_MaybeLoadAnimation(ModelAnimation *modelAnimation, void *anmFile, void *heap);
void StructAM_SomeFn_2(ModelAnimation *modelAnimation, s32 entryIndex, void *anmResource, u32 loopFlag,
                             void *heap);
void StructAM_CreateFrom(u32 kind, ModelAnimation *modelAnimation, Nsbmd *renderObj, u32 anmObjCount, void *heap,
                        void *file);
s32 AnimFormatHandler_BMA(NNSG3dAnmObj *anmObj);
s32 AnimFormatHandler_BVA(NNSG3dAnmObj *anmObj);
s32 AnimFormatHandler_BTP(NNSG3dAnmObj *anmObj);
s32 AnimFormatHandler_BTA(NNSG3dAnmObj *anmObj);
s32 Anim_GetFrameCount_BCA(NNSG3dAnmObj *anmObj);

extern u32 g_LastLoadedAnimationBlockSize;

typedef s32 (*AnmFrameCountGetter)(NNSG3dAnmObj *anmObj);

extern const AnmFrameCountGetter g_Anim_GetFrameCountFnTable[5];
