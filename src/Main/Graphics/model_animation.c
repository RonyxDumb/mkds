#include "Main/Graphics/model_animation.h"
#include "Main/Graphics/nsbmd_render_obj.h"
#include "Main/System/heap.h"
#include "Main/Graphics/model_animation_loop.h"
#include "render_object_callback_link.h"
#include "model_draw_state.h"

#include "Main/Graphics/model_animation_looping.h"
#include "animation_lookup.h"
#include "animation_object_calc.h"

const AnmFrameCountGetter g_Anim_GetFrameCountFnTable[5] = {Anim_GetFrameCount_BCA, AnimFormatHandler_BTA,
                                                      AnimFormatHandler_BTP, AnimFormatHandler_BVA,
                                                      AnimFormatHandler_BMA};
u32 g_LastLoadedAnimationBlockSize;

s32 Anim_GetFrameCount_BCA(NNSG3dAnmObj *anmObj) {
    return ((NNSG3dResJntAnm *) anmObj->mResAnm)->mNumFrame;
}

s32 AnimFormatHandler_BTA(NNSG3dAnmObj *anmObj) {
    return ((NNSG3dResTexSRTAnm *) anmObj->mResAnm)->mNumFrame;
}

s32 AnimFormatHandler_BTP(NNSG3dAnmObj *anmObj) {
    return ((NNSG3dResTexPatAnm *) anmObj->mResAnm)->mNumFrame;
}

s32 AnimFormatHandler_BVA(NNSG3dAnmObj *anmObj) {
    return ((NNSG3dResVisAnm *) anmObj->mResAnm)->mNumFrame;
}

s32 AnimFormatHandler_BMA(NNSG3dAnmObj *anmObj) {
    return ((NNSG3dResMatCAnm *) anmObj->mResAnm)->mNumFrame;
}

void StructAM_CreateFrom(u32 kind, ModelAnimation *modelAnimation, Nsbmd *renderObj, u32 anmObjCount, void *heap,
                        void *file) {
    u16 objIndex;

    if (anmObjCount != 0) {
        objIndex = 0;
        if (heap != NULL) {
            modelAnimation->mAnmObjs = Mem_AllocateHeap(heap, anmObjCount * 4);
            modelAnimation->mLoopFlags = Mem_AllocateHeap(heap, anmObjCount * 4);
            for (; objIndex < anmObjCount; objIndex++) {
                modelAnimation->mAnmObjs[objIndex] = NULL;
                modelAnimation->mLoopFlags[objIndex] = 0;
            }
        }
    }
    StructAM_InitializeImpl(&modelAnimation->mHead, 0);
    renderObj->mDrawKind = 0;
    modelAnimation->mRenderObj = renderObj;
    modelAnimation->mAnmObjCount = anmObjCount;
    modelAnimation->mCurrentIndex = 0;
    modelAnimation->mKind = kind;
    modelAnimation->mBlending = FALSE;
    modelAnimation->mBlendRatioStep = MODEL_ANIMATION_BLEND_RATIO_STEP;
    modelAnimation->mPreviousAnmObj = NULL;
}

void StructAM_SomeFn_2(ModelAnimation *modelAnimation, s32 entryIndex, void *anmResource, u32 loopFlag,
                             void *heap) {
    NNSG3dAnmObj *anmObj;

    if (heap == NULL) {
        anmObj = modelAnimation->mAnmObjs[entryIndex];
        modelAnimation->mLoopFlags[entryIndex] = loopFlag;
    } else {
        g_LastLoadedAnimationBlockSize = Anim_GetNeededBlockSize(anmResource, modelAnimation->mRenderObj->mResMdl);
        anmObj = Mem_AllocateHeap(heap, g_LastLoadedAnimationBlockSize);
        modelAnimation->mAnmObjs[entryIndex] = anmObj;
        modelAnimation->mLoopFlags[entryIndex] = loopFlag;
    }
    MaybeCreateAnimationBlock(anmObj, anmResource, modelAnimation->mRenderObj->mResMdl,
                      modelAnimation->mRenderObj->mResFileEntry.mTexture);
}

void StructAM_MaybeLoadAnimation(ModelAnimation *modelAnimation, void *anmFile, void *heap) {
    void *anmResource = NULL;
    u8 objIndex = 0;
    NNSG3dAnmObj *anmObj;

    for (objIndex = 0; objIndex < modelAnimation->mAnmObjCount; objIndex++) {
        switch (modelAnimation->mKind) {
            case MODEL_ANIMATION_KIND_JOINT:
                anmResource = JNT0_LoadJointByIdx(Anim_NSBCA_LoadGetJNT0Block(anmFile), objIndex);
                break;
            case MODEL_ANIMATION_KIND_TEX_PAT:
                anmResource = BTP0_LoadRawData(MaybeLoadBTP0Format(anmFile), objIndex);
                break;
            case MODEL_ANIMATION_KIND_TEX_SRT:
                anmResource = BTA0_LoadRawData(MaybeLoadBTA0Format(anmFile), objIndex);
                break;
            case MODEL_ANIMATION_KIND_VIS:
                anmResource = BVA0_LoadRawData(MaybeLoadBVA0Format(anmFile), objIndex);
                break;
            case MODEL_ANIMATION_KIND_MAT_C:
                anmResource = BMA0_LoadRawData(MaybeLoadBMA0Format(anmFile), objIndex);
                break;
        }
        if (heap != NULL) {
            g_LastLoadedAnimationBlockSize = Anim_GetNeededBlockSize(anmResource, modelAnimation->mRenderObj->mResMdl);
            anmObj = Mem_AllocateHeap(heap, g_LastLoadedAnimationBlockSize);
            modelAnimation->mAnmObjs[objIndex] = anmObj;
            modelAnimation->mLoopFlags[objIndex] = 0;
        } else {
            anmObj = modelAnimation->mAnmObjs[objIndex];
            modelAnimation->mLoopFlags[objIndex] = 0;
        }
        MaybeCreateAnimationBlock(anmObj, anmResource, modelAnimation->mRenderObj->mResMdl,
                          modelAnimation->mRenderObj->mResFileEntry.mTexture);
    }
}

void StructAM_SomeFn_MaybeLoadFrame(ModelAnimation *modelAnimation, s32 entryIndex) {
    s32 frameCountFixed;

    if (modelAnimation->mAnmObjs[entryIndex] == NULL) {
        return;
    }
    modelAnimation->mBlending = FALSE;
    if (modelAnimation->mPreviousAnmObj != NULL) {
        StructML_SomeFn_2(&modelAnimation->mRenderObj->mRenderObj, modelAnimation->mPreviousAnmObj);
        modelAnimation->mPreviousAnmObj = NULL;
    }
    StructML_SomeFn_2(&modelAnimation->mRenderObj->mRenderObj,
                                 modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]);
    modelAnimation->mCurrentIndex = entryIndex;
    StructML_SomeFn_3(&modelAnimation->mRenderObj->mRenderObj,
                              modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]);
    modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio = TO_FIXED12(1);
    frameCountFixed = TO_FIXED12(
        g_Anim_GetFrameCountFnTable[modelAnimation->mKind](modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]));
    StructAM_SomeFn_0(&modelAnimation->mHead, frameCountFixed,
                                    modelAnimation->mLoopFlags[modelAnimation->mCurrentIndex]);
}

// Switches to entry a by fading from the current one; does nothing when a is already playing.
void StructAM_SomeFn_MaybeForceLoadBlock(ModelAnimation *modelAnimation, u16 entryIndex) {
    s32 frameCountFixed;

    if (modelAnimation->mAnmObjs[entryIndex] == NULL) {
        return;
    }
    if (modelAnimation->mCurrentIndex == entryIndex) {
        return;
    }
    modelAnimation->mBlending = TRUE;
    if (modelAnimation->mPreviousAnmObj != NULL) {
        StructML_SomeFn_2(&modelAnimation->mRenderObj->mRenderObj, modelAnimation->mPreviousAnmObj);
        modelAnimation->mPreviousAnmObj = NULL;
    }
    modelAnimation->mPreviousAnmObj = modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex];
    modelAnimation->mPreviousAnmObj->mRatio = TO_FIXED12(1);
    modelAnimation->mCurrentIndex = entryIndex;
    StructML_SomeFn_3(&modelAnimation->mRenderObj->mRenderObj,
                              modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]);
    modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio = 0;
    frameCountFixed = TO_FIXED12(
        g_Anim_GetFrameCountFnTable[modelAnimation->mKind](modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]));
    StructAM_SomeFn_0(&modelAnimation->mHead, frameCountFixed,
                                    modelAnimation->mLoopFlags[modelAnimation->mCurrentIndex]);
}

void StructAM_SomeFn_MaybeMoveNextFrame(ModelAnimation *modelAnimation) {

    if (modelAnimation->mBlending != FALSE) {
        modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio += modelAnimation->mBlendRatioStep;
        modelAnimation->mPreviousAnmObj->mRatio -= modelAnimation->mBlendRatioStep;
        if (modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio >= TO_FIXED12(1)) {
            modelAnimation->mBlending = FALSE;
            modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio = TO_FIXED12(1);
            StructML_SomeFn_2(&modelAnimation->mRenderObj->mRenderObj, modelAnimation->mPreviousAnmObj);
            modelAnimation->mPreviousAnmObj = NULL;
        }
    }
    StructAM_SomeFn_7(&modelAnimation->mHead);
    modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mFrame = modelAnimation->mHead.mFrameIndex;
}

// Moves only the blend; the caller sets the frame.
void StructAM_SomeFn_5(ModelAnimation *modelAnimation) {
    if (modelAnimation->mBlending == FALSE) {
        return;
    }
    modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio += modelAnimation->mBlendRatioStep;
    modelAnimation->mPreviousAnmObj->mRatio -= modelAnimation->mBlendRatioStep;
    if (modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio >= TO_FIXED12(1)) {
        modelAnimation->mBlending = FALSE;
        modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio = TO_FIXED12(1);
        StructML_SomeFn_2(&modelAnimation->mRenderObj->mRenderObj, modelAnimation->mPreviousAnmObj);
        modelAnimation->mPreviousAnmObj = NULL;
    }
}

// Frame count of the playing entry in 20.12 fixed point.
s32 StructAM_GetFrameCount_Times4096(ModelAnimation *modelAnimation) {
    enum { KIND_FIRST } kind = modelAnimation->mKind;

    return TO_FIXED12(g_Anim_GetFrameCountFnTable[kind](modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]));
}
