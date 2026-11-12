#include "Main/Sound/kart_thunder_track_params.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Sound/kart_surface_sound.h"
#include "Main/Unknown/code_02105ec0.h"

void SetKartThunderShrinkTrackParamsFunction(Kart *kart) {
    kart->mSound.mThunderShrinkRaceFrame = gSceneSoundState.mRaceFrames;
    kart->mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) SetKartThunderShrinkSoundTrackParams;
}
