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
    /* 08 */ s32 mFrameStep;
    /* 0c */ s32 mFrameIndex;
    /* 10 */ u16 mLoopsDone;
    /* 12 */ u16 mLoopCount;
} ModelAnimationFrameLoop;

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

extern s32 (*gAnmFrameCountGetters[])(NNSG3dAnmObj *a);

typedef struct Unk020882fc_08 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mFrameCount;
} Unk020882fc_08;

typedef struct Unk020882fc {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Unk020882fc_08 *mUnk_08;
} Unk020882fc;

extern u32 gAnmObjSizeRequired;

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
unsigned int MatCGetAnmObjFrameCount(Unk020882fc *anmObj);
unsigned int VisGetAnmObjFrameCount(Unk020882fc *anmObj);
unsigned int TexPatGetAnmObjFrameCount(Unk020882fc *anmObj);
unsigned int TexSrtGetAnmObjFrameCount(Unk020882fc *anmObj);
unsigned int JointGetAnmObjFrameCount(Unk020882fc *anmObj);
