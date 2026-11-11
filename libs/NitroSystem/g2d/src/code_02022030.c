#include "code_02022030.h"

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
