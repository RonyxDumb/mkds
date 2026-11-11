#include "code_020220f0.h"

u16 NNS_G2dGetAnimCtrlCurrentFrame(const Unk02022030 *pAnimCtrl) {
    return ((u32) pAnimCtrl->mPCurrent - (u32) pAnimCtrl->mPAnimSequence->mPAnmFrameArray) / sizeof(Unk02022188);
}
