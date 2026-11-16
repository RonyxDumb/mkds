#include "Main/Sound/kart_track_params_reset.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Sound/kart_surface_sound.h"

void ResetKartTrackParamsFunction(Kart *kart) {
    kart->mSound.mThunderShrinkRaceFrame = (~(0x0u));
    kart->mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) MQ_FnPtr2;
}
