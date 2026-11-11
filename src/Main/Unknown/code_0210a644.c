#include "Main/Unknown/code_0210a644.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_02105ec0.h"

void SetKartThunderShrinkTrackParamsFunction(Kart *kart) {
    kart->mSound.mThunderShrinkRaceFrame = gSceneSoundState.mRaceFrames;
    kart->mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) SetKartThunderShrinkSoundTrackParams;
}
