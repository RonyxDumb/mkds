#include "code_0202210c.h"
#include "code_020222ec.h"
#include "code_02134398.h"

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
    if (pAnimCtrl->mActive != 0 && pAnimCtrl->mCurrentTime >= (pAnimCtrl->mPCurrent->mFrames << 12)) {
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
        *currentTime = *currentTime - (pAnimCtrl->mPCurrent->mFrames << 12);
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
