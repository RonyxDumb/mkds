#include "sprite_animation_control.h"
#include "cell_animation.h"
#include "print_memory_multibyte_write.h"

NNSG2dAnimDataSRT *NNS_G2dGetAnimCtrlCurrentElement(NNSG2dCellAnimation *pAnimCtrl) {
    return (NNSG2dAnimDataSRT *) pAnimCtrl->mPCurrent->mPContent;
}

static inline void CallbackFuncHandling_(const NNSG2dCellAnimation *pAnimCtrl, u16 currentFrameIdx) {
    switch (pAnimCtrl->mCallbackFunctor.mType) {
        case G2D_CALLBACK_AT_FRAME:
            if (currentFrameIdx == pAnimCtrl->mCallbackFunctor.mFrameIdx) {
                pAnimCtrl->mCallbackFunctor.mFunc(pAnimCtrl->mCallbackFunctor.mParam, currentFrameIdx);
            }
            break;
        case G2D_CALLBACK_EVERY_FRAME:
            pAnimCtrl->mCallbackFunctor.mFunc(pAnimCtrl->mCallbackFunctor.mParam, currentFrameIdx);
            break;
    }
}

static inline u32 ShouldAnmCtrlMoveNext_(NNSG2dCellAnimation *pAnimCtrl) {
    if (pAnimCtrl->mActive != 0 && pAnimCtrl->mCurrentTime >= TO_FIXED12(pAnimCtrl->mPCurrent->mFrames)) {
        return 1;
    }
    return 0;
}

u32 NNS_G2dTickAnimCtrl(NNSG2dCellAnimation *pAnimCtrl, s32 frames) {
    u32 changedFrame;
    s32 atEdge;
    NNSG2dAnimFrameData *next;
    u16 frameIdx;
    s32 *currentTime;

    changedFrame = 0;
    if (pAnimCtrl->mActive != 1) {
        return 0;
    }
    pAnimCtrl->mCurrentTime += Abs(MUL_FIXED12_ROUNDED(pAnimCtrl->mSpeed, frames));
    currentTime = &pAnimCtrl->mCurrentTime;
    while (ShouldAnmCtrlMoveNext_(pAnimCtrl)) {
        changedFrame = 1;
        *currentTime = *currentTime - TO_FIXED12(pAnimCtrl->mPCurrent->mFrames);
        if ((pAnimCtrl->mSpeed > 0) ^ pAnimCtrl->mReverse) {
            pAnimCtrl->mPCurrent++;
        } else {
            pAnimCtrl->mPCurrent--;
        }
        next = pAnimCtrl->mPCurrent;
        if ((pAnimCtrl->mSpeed > 0) ^ pAnimCtrl->mReverse) {
            atEdge = next >= &pAnimCtrl->mPAnimSequence->mPAnmFrameArray[pAnimCtrl->mPAnimSequence->mNumFrames];
        } else {
            atEdge =
                next <= &pAnimCtrl->mPAnimSequence->mPAnmFrameArray[pAnimCtrl->mPAnimSequence->mLoopStartFrameIdx] - 1;
        }
        if (atEdge) {
            SequenceEdgeHandle_(pAnimCtrl);
        }
        if (pAnimCtrl->mCallbackFunctor.mType != G2D_CALLBACK_NONE) {
            frameIdx = ((u32) pAnimCtrl->mPCurrent - (u32) pAnimCtrl->mPAnimSequence->mPAnmFrameArray) >> 3;
            CallbackFuncHandling_(pAnimCtrl, frameIdx);
        }
    }
    return changedFrame;
}

u32 NNS_G2dSetAnimCtrlCurrentFrame(NNSG2dCellAnimation *pAnimCtrl, u32 index) {
    u32 result;

    result = SetAnimCtrlCurrentFrameImpl_(pAnimCtrl, index);
    if (result != 0) {
        pAnimCtrl->mCurrentTime = 0;
    }
    return result;
}

u16 NNS_G2dGetAnimCtrlCurrentFrame(const NNSG2dCellAnimation *pAnimCtrl) {
    return ((u32) pAnimCtrl->mPCurrent - (u32) pAnimCtrl->mPAnimSequence->mPAnmFrameArray) /
           sizeof(NNSG2dAnimFrameData);
}

void NNS_G2dInitAnimCtrl(NNSG2dCellAnimation *pAnimCtrl) {
    NNS_G2dInitAnimCallBackFunctor(&pAnimCtrl->mCallbackFunctor);
    pAnimCtrl->mPCurrent = 0;
    pAnimCtrl->mReverse = 0;
    pAnimCtrl->mActive = 1;
    pAnimCtrl->mCurrentTime = 0;
    pAnimCtrl->mSpeed = FIXED12_UNIT;
    pAnimCtrl->mOverriddenPlayMode = G2D_PLAY_MODE_FROM_SEQUENCE;
    pAnimCtrl->mPAnimSequence = 0;
}

void NNS_G2dInitAnimCallBackFunctor(NNSG2dCallBackFunctor *pCallBack) {
    pCallBack->mType = G2D_CALLBACK_NONE;
    pCallBack->mParam = 0;
    pCallBack->mFunc = 0;
    pCallBack->mFrameIdx = 0;
}

void NNS_G2dResetAnimCtrlState(NNSG2dCellAnimation *pAnimCtrl) {
    if ((pAnimCtrl->mSpeed > 0) ^ pAnimCtrl->mReverse) {
        pAnimCtrl->mPCurrent =
            &pAnimCtrl->mPAnimSequence->mPAnmFrameArray[pAnimCtrl->mPAnimSequence->mLoopStartFrameIdx];
    } else {
        pAnimCtrl->mPCurrent = &pAnimCtrl->mPAnimSequence->mPAnmFrameArray[pAnimCtrl->mPAnimSequence->mNumFrames] - 1;
    }
    pAnimCtrl->mCurrentTime = 0;
}

void NNS_G2dBindAnimCtrl(NNSG2dCellAnimation *pAnimCtrl, NNSG2dAnimSequenceData *pAnimSequence) {
    pAnimCtrl->mPAnimSequence = pAnimSequence;
    NNS_G2dResetAnimCtrlState(pAnimCtrl);
}
