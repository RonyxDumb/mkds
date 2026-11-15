#include "Main/Graphics/model_animation.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/System/heap.h"
#include "Main/Graphics/model_animation_loop.h"
#include "code_020109c4.h"
#include "code_02010c84.h"

#include "Main/Graphics/model_animation_looping.h"
#include "code_02013740.h"
#include "code_02013bdc.h"

const AnmFrameCountGetter gAnmFrameCountGetters[5] = {JointGetAnmObjFrameCount, TexSrtGetAnmObjFrameCount,
                                                      TexPatGetAnmObjFrameCount, VisGetAnmObjFrameCount,
                                                      MatCGetAnmObjFrameCount};
u32 gAnmObjSizeRequired;

s32 JointGetAnmObjFrameCount(NNSG3dAnmObj *anmObj) {
    return ((NNSG3dResJntAnm *) anmObj->mResAnm)->mNumFrame;
}

s32 TexSrtGetAnmObjFrameCount(NNSG3dAnmObj *anmObj) {
    return ((NNSG3dResTexSRTAnm *) anmObj->mResAnm)->mNumFrame;
}

s32 TexPatGetAnmObjFrameCount(NNSG3dAnmObj *anmObj) {
    return ((NNSG3dResTexPatAnm *) anmObj->mResAnm)->mNumFrame;
}

s32 VisGetAnmObjFrameCount(NNSG3dAnmObj *anmObj) {
    return ((NNSG3dResVisAnm *) anmObj->mResAnm)->mNumFrame;
}

s32 MatCGetAnmObjFrameCount(NNSG3dAnmObj *anmObj) {
    return ((NNSG3dResMatCAnm *) anmObj->mResAnm)->mNumFrame;
}

void InitModelAnimation(u32 kind, ModelAnimation *modelAnimation, Nsbmd *renderObj, u32 anmObjCount, void *heap,
                        void *file) {
    u16 objIndex;

    if (anmObjCount != 0) {
        objIndex = 0;
        if (heap != NULL) {
            modelAnimation->mAnmObjs = HeapAlloc(heap, anmObjCount * 4);
            modelAnimation->mLoopFlags = HeapAlloc(heap, anmObjCount * 4);
            for (; objIndex < anmObjCount; objIndex++) {
                modelAnimation->mAnmObjs[objIndex] = NULL;
                modelAnimation->mLoopFlags[objIndex] = 0;
            }
        }
    }
    ResetModelAnimationLooping(&modelAnimation->mHead, 0);
    renderObj->mDrawKind = 0;
    modelAnimation->mRenderObj = renderObj;
    modelAnimation->mAnmObjCount = anmObjCount;
    modelAnimation->mCurrentIndex = 0;
    modelAnimation->mKind = kind;
    modelAnimation->mBlending = FALSE;
    modelAnimation->mBlendRatioStep = MODEL_ANIMATION_BLEND_RATIO_STEP;
    modelAnimation->mPreviousAnmObj = NULL;
}

void InitModelAnimationEntry(ModelAnimation *modelAnimation, s32 entryIndex, void *anmResource, u32 loopFlag,
                             void *heap) {
    NNSG3dAnmObj *anmObj;

    if (heap == NULL) {
        anmObj = modelAnimation->mAnmObjs[entryIndex];
        modelAnimation->mLoopFlags[entryIndex] = loopFlag;
    } else {
        gAnmObjSizeRequired = NNS_G3dAnmObjCalcSizeRequired(anmResource, modelAnimation->mRenderObj->mResMdl);
        anmObj = HeapAlloc(heap, gAnmObjSizeRequired);
        modelAnimation->mAnmObjs[entryIndex] = anmObj;
        modelAnimation->mLoopFlags[entryIndex] = loopFlag;
    }
    NNS_G3dAnmObjInit(anmObj, anmResource, modelAnimation->mRenderObj->mResMdl,
                      modelAnimation->mRenderObj->mResFileEntry.mTexture);
}

void InitModelAnimationEntries(ModelAnimation *modelAnimation, void *anmFile, void *heap) {
    void *anmResource = NULL;
    u8 objIndex = 0;
    NNSG3dAnmObj *anmObj;

    for (objIndex = 0; objIndex < modelAnimation->mAnmObjCount; objIndex++) {
        switch (modelAnimation->mKind) {
            case MODEL_ANIMATION_KIND_JOINT:
                anmResource = NNS_G3dGetJntAnmByIdx(NNS_G3dGetJntAnmSet(anmFile), objIndex);
                break;
            case MODEL_ANIMATION_KIND_TEX_PAT:
                anmResource = NNS_G3dGetTexPatAnmByIdx(NNS_G3dGetTexPatAnmSet(anmFile), objIndex);
                break;
            case MODEL_ANIMATION_KIND_TEX_SRT:
                anmResource = NNS_G3dGetTexSRTAnmByIdx(NNS_G3dGetTexSRTAnmSet(anmFile), objIndex);
                break;
            case MODEL_ANIMATION_KIND_VIS:
                anmResource = NNS_G3dGetVisAnmByIdx(NNS_G3dGetVisAnmSet(anmFile), objIndex);
                break;
            case MODEL_ANIMATION_KIND_MAT_C:
                anmResource = NNS_G3dGetMatCAnmByIdx(NNS_G3dGetMatCAnmSet(anmFile), objIndex);
                break;
        }
        if (heap != NULL) {
            gAnmObjSizeRequired = NNS_G3dAnmObjCalcSizeRequired(anmResource, modelAnimation->mRenderObj->mResMdl);
            anmObj = HeapAlloc(heap, gAnmObjSizeRequired);
            modelAnimation->mAnmObjs[objIndex] = anmObj;
            modelAnimation->mLoopFlags[objIndex] = 0;
        } else {
            anmObj = modelAnimation->mAnmObjs[objIndex];
            modelAnimation->mLoopFlags[objIndex] = 0;
        }
        NNS_G3dAnmObjInit(anmObj, anmResource, modelAnimation->mRenderObj->mResMdl,
                          modelAnimation->mRenderObj->mResFileEntry.mTexture);
    }
}

void SetModelAnimation(ModelAnimation *modelAnimation, s32 entryIndex) {
    s32 frameCountFixed;

    if (modelAnimation->mAnmObjs[entryIndex] == NULL) {
        return;
    }
    modelAnimation->mBlending = FALSE;
    if (modelAnimation->mPreviousAnmObj != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(&modelAnimation->mRenderObj->mRenderObj, modelAnimation->mPreviousAnmObj);
        modelAnimation->mPreviousAnmObj = NULL;
    }
    NNS_G3dRenderObjRemoveAnmObj(&modelAnimation->mRenderObj->mRenderObj,
                                 modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]);
    modelAnimation->mCurrentIndex = entryIndex;
    NNS_G3dRenderObjAddAnmObj(&modelAnimation->mRenderObj->mRenderObj,
                              modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]);
    modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio = TO_FIXED12(1);
    frameCountFixed = TO_FIXED12(
        gAnmFrameCountGetters[modelAnimation->mKind](modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]));
    ResetModelAnimationWithLoopFlag(&modelAnimation->mHead, frameCountFixed,
                                    modelAnimation->mLoopFlags[modelAnimation->mCurrentIndex]);
}

// Switches to entry a by fading from the current one; does nothing when a is already playing.
void StartModelAnimationBlend(ModelAnimation *modelAnimation, u16 entryIndex) {
    s32 frameCountFixed;

    if (modelAnimation->mAnmObjs[entryIndex] == NULL) {
        return;
    }
    if (modelAnimation->mCurrentIndex == entryIndex) {
        return;
    }
    modelAnimation->mBlending = TRUE;
    if (modelAnimation->mPreviousAnmObj != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(&modelAnimation->mRenderObj->mRenderObj, modelAnimation->mPreviousAnmObj);
        modelAnimation->mPreviousAnmObj = NULL;
    }
    modelAnimation->mPreviousAnmObj = modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex];
    modelAnimation->mPreviousAnmObj->mRatio = TO_FIXED12(1);
    modelAnimation->mCurrentIndex = entryIndex;
    NNS_G3dRenderObjAddAnmObj(&modelAnimation->mRenderObj->mRenderObj,
                              modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]);
    modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio = 0;
    frameCountFixed = TO_FIXED12(
        gAnmFrameCountGetters[modelAnimation->mKind](modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]));
    ResetModelAnimationWithLoopFlag(&modelAnimation->mHead, frameCountFixed,
                                    modelAnimation->mLoopFlags[modelAnimation->mCurrentIndex]);
}

void AdvanceModelAnimation(ModelAnimation *modelAnimation) {

    if (modelAnimation->mBlending != FALSE) {
        modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio += modelAnimation->mBlendRatioStep;
        modelAnimation->mPreviousAnmObj->mRatio -= modelAnimation->mBlendRatioStep;
        if (modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio >= TO_FIXED12(1)) {
            modelAnimation->mBlending = FALSE;
            modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio = TO_FIXED12(1);
            NNS_G3dRenderObjRemoveAnmObj(&modelAnimation->mRenderObj->mRenderObj, modelAnimation->mPreviousAnmObj);
            modelAnimation->mPreviousAnmObj = NULL;
        }
    }
    AdvanceModelAnimationFrame(&modelAnimation->mHead);
    modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mFrame = modelAnimation->mHead.mFrameIndex;
}

// Moves only the blend; the caller sets the frame.
void AdvanceModelAnimationBlend(ModelAnimation *modelAnimation) {
    if (modelAnimation->mBlending == FALSE) {
        return;
    }
    modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio += modelAnimation->mBlendRatioStep;
    modelAnimation->mPreviousAnmObj->mRatio -= modelAnimation->mBlendRatioStep;
    if (modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio >= TO_FIXED12(1)) {
        modelAnimation->mBlending = FALSE;
        modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio = TO_FIXED12(1);
        NNS_G3dRenderObjRemoveAnmObj(&modelAnimation->mRenderObj->mRenderObj, modelAnimation->mPreviousAnmObj);
        modelAnimation->mPreviousAnmObj = NULL;
    }
}

// Frame count of the playing entry in 20.12 fixed point.
s32 GetModelAnimationFrameCountFixed(ModelAnimation *modelAnimation) {
    enum { KIND_FIRST } kind = modelAnimation->mKind;

    return TO_FIXED12(gAnmFrameCountGetters[kind](modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]));
}
