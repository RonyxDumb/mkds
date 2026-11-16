#include "Main/Sound/kart_sound_callbacks.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Sound/sound_distance_change.h"
#include "Main/Sound/kart_sound_starts_and_track_params.h"
#include "Main/Sound/kart_sound_queue_and_kart_sound_starts.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"

void InitKartSoundCallbacks(Kart *kart, KartSound *kartSound) {
    if (kart->mEntryFlags & KART_ENTRY_GHOST) {
        kart->mSoundSource.mStartSeqFunction = (void (*)(void *, void *, u32)) GhostKartStartSeqNop;
    } else {
        kart->mSoundSource.mStartSeqFunction = (void (*)(void *, void *, u32)) StartKartPlayingSoundSeq;
    }
    kart->mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) UpdateKartPlayingSound;
    if (GetCurrentSceneNumber() == 2 || kart->mIndex != gRaceSetup->mEntryIndex) {
        kartSound->mDistanceChangeFunction = GetSoundDistanceChange;
    } else {
        kartSound->mDistanceChangeFunction = GetZeroSoundDistanceChange;
    }
}

void StartKartSeqArcSoundOffset8(Kart *kart, s32 soundIndex) {
    StartKartSeqArcSound(kart, soundIndex, 8);
}
