#include "code_0212f864.h"

void NNSi_SndFaderInit(NNSSndFader *fader) {
    NNSSndFader *unusedFader = fader;
    u32 copiedValue;
    u32 zeroValue;
    zeroValue = 0u;
    fader->mTarget = zeroValue;
    copiedValue = fader->mTarget;
    fader->mOrigin = copiedValue;
    fader->mFrame = zeroValue;
    copiedValue = fader->mFrame;
    fader->mCounter = copiedValue;
}
