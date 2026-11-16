#include "Main/Unknown/code_0210cf20.h"
#include "Main/Unknown/code_02105ec0.h"

#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/code_0210cfe8.h"
#include "Main/Unknown/code_0210d020.h"
#include "Main/Unknown/code_0210d078.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_0216c000.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_0210d0b4.h"
#include "Main/Unknown/code_0210d120.h"
#include "Main/Unknown/code_0210bafc.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_0210d4a0.h"
#include "Main/Unknown/code_0210d4a4.h"
#include "Main/Unknown/code_0210e328.h"
#include "Main/Unknown/code_0210bce0.h"
#include "code_0201750c.h"

// Builds the pool of sounds, resets each one, empties the three source lists and zeroes the two pass counters.
void sfx_initPool(PlayingSound *sounds, s32 count) {
    s32 i;

    sp_init(&sfx_sSfxPool, sounds, count, 0x1c);
    for (i = 0; i < count; i++) {
        sp_initHandle(sounds);
        list_initLink(&sounds->mUnk_08);
        sounds->mSeqArcNo = 0;
        sounds->mSoundId = 0;
        sounds->mFlags = 0;
        sounds->mPitch = 0;
        sounds->mVolume = 0x7f;
        sounds++;
    }
    NNS_FndInitList(&sfx_sActiveEmitterList, 0);
    for (i = 0; i < 2; i++) {
        NNS_FndInitList(&data_0217d048[i], 0x1c);
    }
    data_0217d010[0] = 0;
    data_0217d024[0] = 0;
}

u32 func_0210d4a0(u32 value) {
    return value;
}

// The sound pass: list 0 sources get volume and pan every call, list 1 sources in turns over four calls.
void sfx_update(void) {
    NNSFndList *updateLists;
    u32 countThisPass;
    PlayingSound *sound;
    NNSFndList *secondUpdateList;
    SoundSource *source;

    if (SoundHandle_217D084.mUnk_10 == 0) {
        return;
    }
    if (data_0217d020 != 0) {
        for (source = sfx_sActiveEmitterList.mHead; source != NULL; source = NNS_FndGetNextListObject(&sfx_sActiveEmitterList, source)) {
            sfx_210CC3C(source);
        }
        data_0217d020 = 0;
    }
    sp_updateAges(&sfx_sSfxPool);
    updateLists = data_0217d048;
    for (source = updateLists->mHead; source != NULL; source = updateLists->mHead) {
        sfx_updateEmitter(source);
        if (source->mUpdateListIndex != 3) {
            list_remove(&updateLists[source->mUpdateListIndex], source);
            source->mUpdateListIndex = 3;
        }
    }
    secondUpdateList = &data_0217d054;
    source = secondUpdateList->mHead;
    countThisPass = data_0217d024[0];
    if (source != NULL) {
        updateLists = data_0217d048;
        do {
            if ((countThisPass++ & 3) == data_0217d010[0]) {
                sfx_updateEmitter(source);
            } else if ((countThisPass & 1) == (data_0217d010[0] & 1)) {
                for (sound = source->mPlayingSounds.mHead; sound != NULL;
                     sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound)) {
                    if (sound->mSeqPlayer != NULL) {
                        source->mTrackParamsFunction(source, sound, NULL);
                    }
                }
            }
            if (source->mUpdateListIndex != 3) {
                list_remove(&updateLists[source->mUpdateListIndex], source);
                source->mUpdateListIndex = 3;
            }
            source = secondUpdateList->mHead;
        } while (source != NULL);
    }
    data_0217d010[0]++;
    if (data_0217d010[0] == 4) {
        data_0217d010[0] = 0;
    }
    data_0217d024[0] = 0;
}

// Stops every sound of every source, removes the entries from the source and the source from its update list.
void sfx_stopAll(u32 fadeSteps) {
    SoundSource *source;
    PlayingSound *sound;

    source = sfx_sActiveEmitterList.mHead;
    if (source == NULL) {
        return;
    }
    do {
        sound = source->mPlayingSounds.mHead;
        if (sound != NULL) {
            do {
                NNS_SndPlayerStopSeq(&sound->mSeqPlayer, fadeSteps);
                sound->mFlags &= ~4;
                sound->mFlags &= ~8;
                sound->mFlags &= ~2;
                list_remove(&source->mPlayingSounds, sound);
                sound = source->mPlayingSounds.mHead;
            } while (sound != NULL);
        }
        if (source->mUpdateListIndex != 3) {
            list_remove(&data_0217d048[source->mUpdateListIndex], source);
            source->mUpdateListIndex = 3;
        }
        source = NNS_FndGetNextListObject(&sfx_sActiveEmitterList, source);
    } while (source != NULL);
}

// Fades every sound in the pool to the volume over the given number of steps.
void sfx_moveVolume(s32 volume, s32 steps) {
    u8 *entryAddress;
    s32 i;

    entryAddress = sfx_sSfxPool.mEntries;
    for (i = 0; i < sfx_sSfxPool.mCount; i++) {
        NNS_SndPlayerMoveVolume(&((PlayingSound *) entryAddress)->mSeqPlayer, volume, steps);
        entryAddress += sfx_sSfxPool.mEntrySize;
    }
}

void sfx_stopAllSfxStandalone(u32 fadeSteps) {
    u8 *entryAddress;
    s32 i;

    entryAddress = sfx_sSfxPool.mEntries;
    for (i = 0; i < sfx_sSfxPool.mCount; i++) {
        NNS_SndPlayerStopSeq(&((PlayingSound *) entryAddress)->mSeqPlayer, fadeSteps);
        ((PlayingSound *) entryAddress)->mFlags &= ~4;
        ((PlayingSound *) entryAddress)->mFlags &= ~8;
        ((PlayingSound *) entryAddress)->mFlags &= ~2;
        entryAddress += sfx_sSfxPool.mEntrySize;
    }
}

void ReleaseAllSoundSources(void) {
    while (sfx_sActiveEmitterList.mHead != NULL) {
        sfx_210C3A8(sfx_sActiveEmitterList.mHead);
    }
}

// Start slot of a source (offset 0x2c): starts the library sequence of the entry at the given priority.
void sfx_startSeqArcEx(u32 a, PlayingSound *sound, u32 priority) {
    NNS_SndArcPlayerStartSeqArcEx(&sound->mSeqPlayer, -1, -1, priority, sound->mSeqArcNo, sound->mSoundId);
}

// Per-entry slot of a source (offset 0x30): sets track volume and pitch of a started sound.
void sfx_updateVolumePitch(u32 a, PlayingSound *sound) {
    NNS_SndPlayerSetTrackVolume(&sound->mSeqPlayer, data_0216cb20, sound->mVolume);
    NNS_SndPlayerSetTrackPitch(&sound->mSeqPlayer, data_0216cb20, sound->mPitch);
}

void sound_startSeqArcWithPriority(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 soundId, u32 priority) {
    NNS_SndArcPlayerStartSeqArcEx(handle, -1, -1, priority, seqArcNo, soundId);
}

void sfx_210D040(s32 (*panFunction)(SoundParams *)) {
    sfx_sCalcPanFunc = panFunction;
}

void sfx_210D030(u32 (*distanceFunction)(SoundParams *)) {
    data_0217d018 = distanceFunction;
}

void sfx_210D020(s32 (*volumeFunction)(SoundParams *)) {
    sfx_sCalcVolumeFunc = volumeFunction;
}

void sfx_initSfx(PlayingSound *sound) {
    sp_initHandle(sound);
    list_initLink(&sound->mUnk_08);
    sound->mSeqArcNo = 0;
    sound->mSoundId = 0;
    sound->mFlags = 0;
    sound->mPitch = 0;
    sound->mVolume = 0x7f;
}

// Every caller passes bit 2 with 1: the sound pass then flips bit 0 and clears bit 2.
void SetSoundSourceFlagBit(SoundSource *source, s32 bit, s32 value) {
    if (value == 1) {
        source->mSourceFlags |= 1 << bit;
    } else {
        source->mSourceFlags &= ~(1 << bit);
    }
}

// Bit 0 of the flag word: a sound can start on the source only while it is set.
void sfx_210CF9C(SoundSource *source, s32 enabled) {
    if (enabled == 1) {
        source->mSourceFlags |= 1;
    } else {
        source->mSourceFlags &= ~1;
    }
}

void sfx_initEmitter(SoundSource *source, u32 positionSource) {
    void *startFunction;
    void *trackParamsFunction;
    NNS_FndInitList(&source->mPlayingSounds, 8);
    startFunction = (void *) sfx_startSeqArcEx;
    source->mUnk_38 = 1;
    trackParamsFunction = (void *) sfx_updateVolumePitch;
    source->mStartSeqFunction = startFunction;
    source->mTrackParamsFunction = trackParamsFunction;
    source->mSourceFlags = 0;
    source->mOwnerPosSource = positionSource;
    source->mUpdateListIndex = 3;
    list_initLink(source->mUnk_1c);
    list_initLink((u32 *) source);
    list_append(&sfx_sActiveEmitterList, source);
}
