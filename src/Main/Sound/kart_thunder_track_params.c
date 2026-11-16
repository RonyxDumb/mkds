#include "Main/Sound/kart_thunder_track_params.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Sound/kart_sound_starts_and_track_params.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"

void SetKartThunderShrinkTrackParamsFunction(Kart *kart) {
    kart->mSound.mThunderShrinkRaceFrame = gSceneSoundState.mRaceFrames;
    kart->mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) SetKartThunderShrinkSoundTrackParams;
}
