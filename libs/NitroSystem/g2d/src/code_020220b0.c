#include "code_020220b0.h"
#include "code_02022098.h"

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
