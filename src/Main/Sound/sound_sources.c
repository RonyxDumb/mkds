#include "Main/Sound/sound_sources.h"
#include "Main/Sound/sound_seq.h"

#include "Main/Sound/sound_request_queue.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "sound_player_control.h"
#include "Main/Sound/surface_sound_ids.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/playing_sounds.h"
#include "Main/Menu/menu_screens_work.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "linked_list_ops.h"
#include "Main/Sound/playing_sound_handle_reset.h"
#include "Main/Sound/three_words_clear.h"
#include "linked_list_init.h"
#include "Main/Sound/sound_system.h"

NNSFndList gSoundSourceSecondUpdateList;
NNSFndList gSoundSourceUpdateLists[1];

// Builds the pool of sounds, resets each one, empties the three source lists and zeroes the two pass counters.
void InitPlayingSoundPool(PlayingSound *sounds, s32 count) {
    s32 index;

    InitSoundHandlePool(&gPlayingSoundPool, sounds, count, 0x1c);
    for (index = 0; index < count; index++) {
        ResetPlayingSoundHandle(sounds);
        StructMQChild_Create(&sounds->mUnk_08);
        sounds->mSeqArcNo = 0;
        sounds->mSoundId = 0;
        sounds->mFlags = 0;
        sounds->mPitch = 0;
        sounds->mVolume = SOUND_VOLUME_MAX;
        sounds++;
    }
    IntrusiveListWrapper_InitializeEmpty(&gSoundSources, 0);
    for (index = 0; index < 2; index++) {
        IntrusiveListWrapper_InitializeEmpty(&gSoundSourceUpdateLists[index], 0x1c);
    }
    gSoundSourceUpdatePass[0] = 0;
    gSoundSourceCountThisPass[0] = 0;
}

void SoundNop(void *address) {}

// The sound pass: list 0 sources get volume and pan every call, list 1 sources in turns over four calls.
void UpdateSoundSources(void) {
    NNSFndList *updateLists;
    u32 countThisPass;
    PlayingSound *sound;
    NNSFndList *secondUpdateList;
    SoundSource *source;

    if (gSoundModeHolder.mSoundsEnabled == 0) {
        return;
    }
    if (gExpireWhileRequestedSounds != 0) {
        for (source = gSoundSources.mHead; source != NULL; source = IntrusiveListWrapper_NextItem(&gSoundSources, source)) {
            ExpireWhileRequestedSounds(source);
        }
        gExpireWhileRequestedSounds = 0;
    }
    IncrementSoundHandleAges(&gPlayingSoundPool);
    updateLists = gSoundSourceUpdateLists;
    for (source = updateLists->mHead; source != NULL; source = updateLists->mHead) {
        SetPlayingSoundsParams(source);
        if (source->mUpdateListIndex != SOUND_SOURCE_LIST_NONE) {
            RemoveListObject(&updateLists[source->mUpdateListIndex], source);
            source->mUpdateListIndex = SOUND_SOURCE_LIST_NONE;
        }
    }
    secondUpdateList = &gSoundSourceSecondUpdateList;
    source = secondUpdateList->mHead;
    countThisPass = gSoundSourceCountThisPass[0];
    if (source != NULL) {
        updateLists = gSoundSourceUpdateLists;
        do {
            if ((countThisPass++ & 3) == gSoundSourceUpdatePass[0]) {
                SetPlayingSoundsParams(source);
            } else if ((countThisPass & 1) == (gSoundSourceUpdatePass[0] & 1)) {
                for (sound = source->mPlayingSounds.mHead; sound != NULL;
                     sound = IntrusiveListWrapper_NextItem(&source->mPlayingSounds, sound)) {
                    if (sound->mSeqPlayer != NULL) {
                        source->mTrackParamsFunction(source, sound, NULL);
                    }
                }
            }
            if (source->mUpdateListIndex != SOUND_SOURCE_LIST_NONE) {
                RemoveListObject(&updateLists[source->mUpdateListIndex], source);
                source->mUpdateListIndex = SOUND_SOURCE_LIST_NONE;
            }
            source = secondUpdateList->mHead;
        } while (source != NULL);
    }
    gSoundSourceUpdatePass[0]++;
    if (gSoundSourceUpdatePass[0] == 4) {
        gSoundSourceUpdatePass[0] = 0;
    }
    gSoundSourceCountThisPass[0] = 0;
}

// Stops every sound of every source, removes the entries from the source and the source from its update list.
void StopSoundsOnAllSources(u32 fadeSteps) {
    SoundSource *source;
    PlayingSound *sound;

    source = gSoundSources.mHead;
    if (source == NULL) {
        return;
    }
    do {
        sound = source->mPlayingSounds.mHead;
        if (sound != NULL) {
            do {
                NNS_SndPlayerStopSeq(&sound->mSeqPlayer, fadeSteps);
                sound->mFlags &= ~PLAYING_SOUND_FLAG_WHILE_REQUESTED;
                sound->mFlags &= ~PLAYING_SOUND_FLAG_REQUESTED_AGAIN;
                sound->mFlags &= ~PLAYING_SOUND_FLAG_START_PENDING;
                RemoveListObject(&source->mPlayingSounds, sound);
                sound = source->mPlayingSounds.mHead;
            } while (sound != NULL);
        }
        if (source->mUpdateListIndex != SOUND_SOURCE_LIST_NONE) {
            RemoveListObject(&gSoundSourceUpdateLists[source->mUpdateListIndex], source);
            source->mUpdateListIndex = SOUND_SOURCE_LIST_NONE;
        }
        source = IntrusiveListWrapper_NextItem(&gSoundSources, source);
    } while (source != NULL);
}

// Fades every sound in the pool to the volume over the given number of steps.
void StartPlayingSoundsFade(s32 volume, s32 steps) {
    u8 *entryAddress;
    s32 soundIndex;

    entryAddress = gPlayingSoundPool.mEntries;
    for (soundIndex = 0; soundIndex < gPlayingSoundPool.mCount; soundIndex++) {
        NNS_SndPlayerMoveVolume(&((PlayingSound *) entryAddress)->mSeqPlayer, volume, steps);
        entryAddress += gPlayingSoundPool.mEntrySize;
    }
}

void StopAllPlayingSounds(u32 fadeSteps) {
    u8 *entryAddress;
    s32 soundIndex;

    entryAddress = gPlayingSoundPool.mEntries;
    for (soundIndex = 0; soundIndex < gPlayingSoundPool.mCount; soundIndex++) {
        NNS_SndPlayerStopSeq(&((PlayingSound *) entryAddress)->mSeqPlayer, fadeSteps);
        ((PlayingSound *) entryAddress)->mFlags &= ~PLAYING_SOUND_FLAG_WHILE_REQUESTED;
        ((PlayingSound *) entryAddress)->mFlags &= ~PLAYING_SOUND_FLAG_REQUESTED_AGAIN;
        ((PlayingSound *) entryAddress)->mFlags &= ~PLAYING_SOUND_FLAG_START_PENDING;
        entryAddress += gPlayingSoundPool.mEntrySize;
    }
}

void ReleaseAllSoundSources(void) {
    while (gSoundSources.mHead != NULL) {
        StopAllSoundsAndReleaseSoundSource(gSoundSources.mHead);
    }
}

// Start slot of a source (offset 0x2c): starts the library sequence of the entry at the given priority.
void StructMQ_FnPtr1(u32 unused, PlayingSound *sound, u32 priority) {
    NNS_SndArcPlayerStartSeqArcEx(&sound->mSeqPlayer, -1, -1, priority, sound->mSeqArcNo, sound->mSoundId);
}

// Per-entry slot of a source (offset 0x30): sets track volume and pitch of a started sound.
void StructMQ_FnPtr2(u32 unused, PlayingSound *sound) {
    NNS_SndPlayerSetTrackVolume(&sound->mSeqPlayer, gSeqTrackMask, sound->mVolume);
    NNS_SndPlayerSetTrackPitch(&sound->mSeqPlayer, gSeqTrackMask, sound->mPitch);
}

void StartSoundSeqArc(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 soundId, u32 priority) {
    NNS_SndArcPlayerStartSeqArcEx(handle, -1, -1, priority, seqArcNo, soundId);
}

void SetSoundPanFunction(s32 (*panFunction)(SoundParams *)) {
    gSoundPanFunction = panFunction;
}

void SetSoundDistanceFunction(u32 (*distanceFunction)(SoundParams *)) {
    gSoundDistanceFunction = distanceFunction;
}

void SetSoundVolumeFunction(s32 (*volumeFunction)(SoundParams *)) {
    gSoundVolumeFunction = volumeFunction;
}

void ResetPlayingSound(PlayingSound *sound) {
    ResetPlayingSoundHandle(sound);
    StructMQChild_Create(&sound->mUnk_08);
    sound->mSeqArcNo = 0;
    sound->mSoundId = 0;
    sound->mFlags = 0;
    sound->mPitch = 0;
    sound->mVolume = SOUND_VOLUME_MAX;
}

// Every caller passes bit 2 with 1: the sound pass then flips bit 0 and clears bit 2.
void StructMQRacerEntry_SomeFn_47(SoundSource *source, s32 bit, s32 value) {
    if (value == 1) {
        BIT_SET(source->mSourceFlags, bit);
    } else {
        BIT_CLEAR(source->mSourceFlags, bit);
    }
}

// Bit 0 of the flag word: a sound can start on the source only while it is set.
void SetSoundSourceEnabled(SoundSource *source, s32 enabled) {
    if (enabled == 1) {
        source->mSourceFlags |= SOUND_SOURCE_FLAG_ENABLED;
    } else {
        source->mSourceFlags &= ~SOUND_SOURCE_FLAG_ENABLED;
    }
}

void StructMQRacerEntry_SomeFn_46(SoundSource *source, Vec3 *positionSource) {
    void *startFunction;
    void *trackParamsFunction;
    IntrusiveListWrapper_InitializeEmpty(&source->mPlayingSounds, 8);
    startFunction = (void *) StructMQ_FnPtr1;
    source->mRegistered = 1;
    trackParamsFunction = (void *) StructMQ_FnPtr2;
    source->mStartSeqFunction = startFunction;
    source->mTrackParamsFunction = trackParamsFunction;
    source->mSourceFlags = 0;
    source->mOwnerPosSource = positionSource;
    source->mUpdateListIndex = SOUND_SOURCE_LIST_NONE;
    StructMQChild_Create(source->mUnk_1c);
    StructMQChild_Create((u32 *) source);
    StructMQRacerEntry_MaybeInsertChildEntry(&gSoundSources, source);
}
