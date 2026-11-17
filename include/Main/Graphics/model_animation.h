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
// A change of entry can fade from the old one (StartModelAnimationBlend).
typedef struct ModelAnimationFrameLoop {
    /* 00 */ u16 mLoopMode;
    /* 02 */ u16 mDone;
    /* 04 */ s32 mFrameCountFixed;
    /* 08 */ s32 mFrameIndexFixedPerCall;
    /* 0c */ s32 mFrameIndex;
    /* 10 */ u16 mLoopsDone;
    /* 12 */ u16 mLoopCount;
} ModelAnimationFrameLoop;

// ModelAnimation.mBlendRatioStep set by InitModelAnimation: about a tenth of the full blend ratio (TO_FIXED12(1)) per
// advance call.
#define MODEL_ANIMATION_BLEND_RATIO_STEP 0x19a

// The animations of a model: the list of them, the current one and the blend from the previous one.
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

s32 GetModelAnimationFrameCountFixed(ModelAnimation *modelAnimation);
void AdvanceModelAnimationBlend(ModelAnimation *modelAnimation);
void AdvanceModelAnimation(ModelAnimation *modelAnimation);
void StartModelAnimationBlend(ModelAnimation *modelAnimation, u16 entryIndex);
void SetModelAnimation(ModelAnimation *modelAnimation, s32 entryIndex);
void InitModelAnimationEntries(ModelAnimation *modelAnimation, void *anmFile, void *heap);
void InitModelAnimationEntry(ModelAnimation *modelAnimation, s32 entryIndex, void *anmResource, u32 loopFlag,
                             void *heap);
void InitModelAnimation(u32 kind, ModelAnimation *modelAnimation, Nsbmd *renderObj, u32 anmObjCount, void *heap,
                        void *file);
s32 MatCGetAnmObjFrameCount(NNSG3dAnmObj *anmObj);
s32 VisGetAnmObjFrameCount(NNSG3dAnmObj *anmObj);
s32 TexPatGetAnmObjFrameCount(NNSG3dAnmObj *anmObj);
s32 TexSrtGetAnmObjFrameCount(NNSG3dAnmObj *anmObj);
s32 JointGetAnmObjFrameCount(NNSG3dAnmObj *anmObj);

extern u32 gAnmObjSizeRequired;

typedef s32 (*AnmFrameCountGetter)(NNSG3dAnmObj *anmObj);

extern const AnmFrameCountGetter gAnmFrameCountGetters[5];
