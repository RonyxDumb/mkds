#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/sound_mode.h"
#include "code_0212d214.h"

#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Sound/sound_distance_squared_change.h"
#include "Main/Sound/playing_sounds.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_sources.h"
#include "player.h"
#include "Main/Menu/menu_screens_work.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "code_020172d0.h"
#include "Main/Sound/three_words_clear.h"
#include "code_0201750c.h"
#include "Main/Sound/sound_system.h"

u32 gSoundSourceUpdatePass[1];
s32 (*gSoundVolumeFunction)(SoundParams *);
u32 gExpireWhileRequestedSounds;
u32 gSoundSourceCountThisPass[1];
u32 (*gSoundDistanceFunction)(SoundParams *);
s32 (*gSoundPanFunction)(SoundParams *);
NNSFndList gSoundSources;
SoundHandlePool gPlayingSoundPool;

void (*gStartSoundSeqArcTable[1])(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 soundId,
                                  u32 priority) = {StartSoundSeqArc};

void ItemObjectInitAndRegisterSoundSource(SoundSource *source, Vec3 *positionSource) {
    void *startFunction;
    void *trackParamsFunction;
    NNS_FndInitList(&source->mPlayingSounds, 8);
    startFunction = (void *) StartPlayingSoundSeqArc;
    source->mRegistered = 1;
    trackParamsFunction = (void *) SetPlayingSoundTrackParams;
    source->mStartSeqFunction = startFunction;
    source->mTrackParamsFunction = trackParamsFunction;
    source->mSourceFlags = 0;
    source->mOwnerPosSource = positionSource;
    source->mUpdateListIndex = SOUND_SOURCE_LIST_NONE;
    ClearThreeWords(source->mUnk_1c);
    ClearThreeWords((u32 *) source);
    TryAppendListObject(&gSoundSources, source);
}

void UnlinkSoundSourceSounds(SoundSource *source) {
    void *sound;

    StopSoundsStartedWhileRequested(source, 0);
    for (sound = source->mPlayingSounds.mHead; sound != NULL; sound = source->mPlayingSounds.mHead) {
        RemoveListObject(&source->mPlayingSounds, sound);
    }
    if (source->mUpdateListIndex != SOUND_SOURCE_LIST_NONE) {
        RemoveListObject(&gSoundSourceUpdateLists[source->mUpdateListIndex], source);
        source->mUpdateListIndex = SOUND_SOURCE_LIST_NONE;
    }
}

void StopPlayingSoundSeq(PlayingSound *sound, u32 fadeSteps) {
    NNS_SndPlayerStopSeq(&sound->mSeqPlayer, fadeSteps);
    sound->mFlags &= ~PLAYING_SOUND_FLAG_WHILE_REQUESTED;
    sound->mFlags &= ~PLAYING_SOUND_FLAG_REQUESTED_AGAIN;
    sound->mFlags &= ~PLAYING_SOUND_FLAG_START_PENDING;
}

void RefreshSoundSourceUpdateList(SoundSource *source) {
    PlayingSound *sound;
    u32 updateListIndex;
    u8 soundFlags;

    updateListIndex = SOUND_SOURCE_LIST_NONE;
    for (sound = source->mPlayingSounds.mHead; sound != NULL;
         sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound)) {
        soundFlags = sound->mFlags;
        if (soundFlags & PLAYING_SOUND_FLAG_START_PENDING) {
            updateListIndex = SOUND_SOURCE_LIST_EVERY_CALL;
            break;
        }
        if (soundFlags & PLAYING_SOUND_FLAG_REQUESTED_AGAIN || soundFlags & PLAYING_SOUND_FLAG_UPDATE_IN_TURNS) {
            updateListIndex = SOUND_SOURCE_LIST_IN_TURNS;
        }
    }
    if (source->mUpdateListIndex != updateListIndex) {
        if (source->mUpdateListIndex != SOUND_SOURCE_LIST_NONE) {
            RemoveListObject(&gSoundSourceUpdateLists[source->mUpdateListIndex], source);
            source->mUpdateListIndex = SOUND_SOURCE_LIST_NONE;
        }
        if (updateListIndex != SOUND_SOURCE_LIST_NONE) {
            TryAppendListObject(&gSoundSourceUpdateLists[updateListIndex], source);
            source->mUpdateListIndex = updateListIndex;
        }
    }
}

void StartSoundOnPoolEntry(u32 seqArcNo, u32 soundId, Vec3 *positionSource, void *request) {
    PlayingSound *sound;
    NNSFndList *sourceList;

    if (gSoundModeHolder.mSoundsEnabled == 0) {
        return;
    }
    sound = TakeSoundHandleEntry(&gPlayingSoundPool);
    StopPlayingSoundSeq(sound, 0);
    sourceList = sound->mSourceList;
    if (sourceList != NULL) {
        RemoveListObject(sourceList, sound);
        RefreshSoundSourceUpdateList((SoundSource *) (sourceList - 1));
    }
    ResetPlayingSound(sound);
    StartOrUpdateSndHandleSound(seqArcNo, soundId, positionSource, &sound->mSeqPlayer, request);
}

u32 StartOrUpdateSndHandleSoundIfEnabled(u32 seqArcNo, u32 soundId, Vec3 *positionSource, NNSSndSeqPlayer **handle,
                                         void *request) {
    if (gSoundModeHolder.mSoundsEnabled == 0) {
        return seqArcNo;
    }
    return StartOrUpdateSndHandleSound(seqArcNo, soundId, positionSource, handle, request);
}

u32 StartOrUpdateSndHandleSound(u32 seqArcNo, u32 soundId, Vec3 *positionSource, NNSSndSeqPlayer **handle,
                                void *request) {
    SoundParams params;
    u32 startsNewSound;
    u32 runThisCall;
    u32 countThisPass;
    s32 priority;
    s32 volumeForPriority;

    startsNewSound = 0;
    runThisCall = startsNewSound;
    if (gSoundModeHolder.mMode == SCENE_SOUND_MODE_FADED_OUT) {
        return startsNewSound;
    }
    if (gSoundModeHolder.mMode == SCENE_SOUND_MODE_STOPPED) {
        return startsNewSound;
    }
    if (*handle == NULL) {
        startsNewSound = 1;
        runThisCall = startsNewSound;
    } else {
        countThisPass = gSoundSourceCountThisPass[0];
        gSoundSourceCountThisPass[0] = countThisPass + 1;
        if ((countThisPass & 3) == gSoundSourceUpdatePass[0]) {
            runThisCall = 1;
        }
    }
    if (runThisCall == 0) {
        return runThisCall;
    }
    params.mSource = NULL;
    params.mPositionSource = positionSource;
    params.mStartParams = request;
    params.mVolume = 0;
    params.mVolumeForPriority = 0;
    params.mPan = 0;
    if (positionSource == 0) {
        params.mDistance = 0;
        params.mVolume = SOUND_VOLUME_MAX;
        params.mVolumeForPriority = SOUND_VOLUME_MAX;
        params.mPan = 0;
    } else {
        params.mDistance = gSoundDistanceFunction(&params);
        params.mVolumeForPriority = params.mVolume = gSoundVolumeFunction(&params);
        params.mPan = gSoundPanFunction(&params);
    }
    if (params.mVolume <= 0) {
        if (*handle == NULL) {
            return (u32) *handle;
        }
        return NNS_SndPlayerStopSeq(handle, 0);
    }
    volumeForPriority = params.mVolumeForPriority;
    priority = volumeForPriority + (NNS_SndArcGetSeqArcParam(seqArcNo, soundId)->mPlayerPrio - 0x40);
    if (priority > 0) {
        if (priority >= 0x7f) {
            priority = 0x7f;
        }
    } else {
        priority = 0;
    }
    if (startsNewSound != 0) {
        gStartSoundSeqArcTable[0](handle, seqArcNo, soundId, priority);
    }
    NNS_SndPlayerSetVolume(handle, params.mVolume);
    NNS_SndPlayerSetPlayerPriority(handle, priority);
    return NNS_SndPlayerSetTrackPan(handle, gSeqTrackMask, params.mPan);
}
