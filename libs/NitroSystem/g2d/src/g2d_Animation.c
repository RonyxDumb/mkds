#include "g2d_Animation.h"
#include "code_020222ec.h"
#include "code_02134398.h"

NNSG2dAnimDataSRT *NNS_G2dGetAnimCtrlCurrentElement(Unk02022030 *pAnimCtrl) {
    return (NNSG2dAnimDataSRT *) pAnimCtrl->mPCurrent->mPContent;
}

static inline void CallbackFuncHandling_(const Unk02022030 *pAnimCtrl, u16 currentFrameIdx) {
    switch (pAnimCtrl->mCallbackFunctor.mType) {
        case 2:
            if (currentFrameIdx == pAnimCtrl->mCallbackFunctor.mFrameIdx) {
                pAnimCtrl->mCallbackFunctor.mFunc(pAnimCtrl->mCallbackFunctor.mParam, currentFrameIdx);
            }
            break;
        case 3:
            pAnimCtrl->mCallbackFunctor.mFunc(pAnimCtrl->mCallbackFunctor.mParam, currentFrameIdx);
            break;
    }
}

static inline u32 ShouldAnmCtrlMoveNext_(Unk02022030 *pAnimCtrl) {
    if (pAnimCtrl->mActive != 0 && pAnimCtrl->mCurrentTime >= TO_FIXED12(pAnimCtrl->mPCurrent->mFrames)) {
        return 1;
    }
    return 0;
}

u32 NNS_G2dTickAnimCtrl(Unk02022030 *pAnimCtrl, s32 frames) {
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
        if (pAnimCtrl->mCallbackFunctor.mType != 0) {
            frameIdx = ((u32) pAnimCtrl->mPCurrent - (u32) pAnimCtrl->mPAnimSequence->mPAnmFrameArray) >> 3;
            CallbackFuncHandling_(pAnimCtrl, frameIdx);
        }
    }
    return changedFrame;
}

u32 NNS_G2dSetAnimCtrlCurrentFrame(Unk02022030 *pAnimCtrl, u32 index) {
    u32 result;

    result = SetAnimCtrlCurrentFrameImpl_(pAnimCtrl, index);
    if (result != 0) {
        pAnimCtrl->mCurrentTime = 0;
    }
    return result;
}

u16 NNS_G2dGetAnimCtrlCurrentFrame(const Unk02022030 *pAnimCtrl) {
    return ((u32) pAnimCtrl->mPCurrent - (u32) pAnimCtrl->mPAnimSequence->mPAnmFrameArray) /
           sizeof(NNSG2dAnimFrameData);
}

void NNS_G2dInitAnimCtrl(Unk02022030 *pAnimCtrl) {
    NNS_G2dInitAnimCallBackFunctor(&pAnimCtrl->mCallbackFunctor);
    pAnimCtrl->mPCurrent = 0;
    pAnimCtrl->mReverse = 0;
    pAnimCtrl->mActive = 1;
    pAnimCtrl->mCurrentTime = 0;
    pAnimCtrl->mSpeed = 0x1000;
    pAnimCtrl->mOverriddenPlayMode = 0;
    pAnimCtrl->mPAnimSequence = 0;
}

void NNS_G2dInitAnimCallBackFunctor(NNSG2dCallBackFunctor *pCallBack) {
    pCallBack->mType = 0;
    pCallBack->mParam = 0;
    pCallBack->mFunc = 0;
    pCallBack->mFrameIdx = 0;
}

void NNS_G2dResetAnimCtrlState(Unk02022030 *pAnimCtrl) {
    if ((pAnimCtrl->mSpeed > 0) ^ pAnimCtrl->mReverse) {
        pAnimCtrl->mPCurrent =
            &pAnimCtrl->mPAnimSequence->mPAnmFrameArray[pAnimCtrl->mPAnimSequence->mLoopStartFrameIdx];
    } else {
        pAnimCtrl->mPCurrent = &pAnimCtrl->mPAnimSequence->mPAnmFrameArray[pAnimCtrl->mPAnimSequence->mNumFrames] - 1;
    }
    pAnimCtrl->mCurrentTime = 0;
}

void NNS_G2dBindAnimCtrl(Unk02022030 *pAnimCtrl, NNSG2dAnimSequenceData *pAnimSequence) {
    pAnimCtrl->mPAnimSequence = pAnimSequence;
    NNS_G2dResetAnimCtrlState(pAnimCtrl);
}
