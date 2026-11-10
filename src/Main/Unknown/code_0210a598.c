#include "Main/Unknown/code_0210a598.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0210a63c.h"
#include "Main/Unknown/code_0210aa0c.h"
#include "Main/Unknown/code_0210ab30.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_0210aa14.h"
#include "Main/Unknown/unk_021759c0.h"

void InitKartSoundCallbacks(Kart *kart, KartSound *kartSound) {
    if (kart->mUnk_7c & KART_7C_ENTRY_IS_GHOST) {
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
