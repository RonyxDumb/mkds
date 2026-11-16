#include "Main/Sound/kart_sound_callbacks.h"
#include "Main/Scene/run_scenes.h"
#include "Main/Sound/sound_distance_change.h"
#include "Main/Sound/kart_surface_sound.h"
#include "Main/Sound/kart_sound_queue.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"

void StructMQRacerEntry_SomeFn_76(Kart *kart, KartSound *kartSound) {
    if (kart->mEntryFlags & KART_ENTRY_GHOST) {
        kart->mSoundSource.mStartSeqFunction = (void (*)(void *, void *, u32)) MQ_FnPtr1_1;
    } else {
        kart->mSoundSource.mStartSeqFunction = (void (*)(void *, void *, u32)) MQ_FnPtr1_2;
    }
    kart->mSoundSource.mTrackParamsFunction = (void (*)(void *, void *, void *)) MQ_FnPtr2;
    if (GetCurrentSceneId() == 2 || kart->mIndex != g_GlobalCO->mEntryIndex) {
        kartSound->mDistanceChangeFunction = GetSoundDistanceChange;
    } else {
        kartSound->mDistanceChangeFunction = GetZeroSoundDistanceChange;
    }
}

void StructMQRacerEntry_SomeFn_66(Kart *kart, s32 soundIndex) {
    StructMQRacerEntry_SomeFn_5(kart, soundIndex, 8);
}
