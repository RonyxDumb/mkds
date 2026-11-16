#include "Main/Sound/kart_track_params_reset.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Sound/kart_sound_starts_and_track_params.h"

void ResetKartTrackParamsFunction(Kart *kart) {
    kart->mSound.mThunderShrinkRaceFrame = (~(0x0u));
    kart->mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) UpdateKartPlayingSound;
}
