#include "Main/Sound/playing_sounds.h"

#include "Main/Sound/data_0216c000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Sound/data_0210b000.h"
#include "code_0212d214.h"
#include "player.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_sources.h"
#include "Main/Sound/three_words_clear.h"
#include "Main/Sound/playing_sound_handle_reset.h"
#include "Main/Menu/data_0217d000.h"
#include "code_0212c7a0.h"
#include "stream.h"
#include "code_0212c9d4.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "Main/Sound/sound_seq.h"
#include "code_020172d0.h"
#include "Main/Sound/sound_system.h"

#pragma opt_loop_invariants off

void ExpireWhileRequestedSounds(SoundSource *source) {
    PlayingSound *sound;
    PlayingSound *removedSound;
    u32 value;
    u32 hadBit8;

    value = 0;
    if (gSoundModeHolder.mSoundsEnabled == 0) {
        return;
    }
    if ((source->mSourceFlags & 1) == 0) {
        if (source->mSourceFlags & 2) {
            StopSoundsStartedWhileRequested(source, 0);
        }
        source->mSourceFlags &= ~2;
        if ((source->mSourceFlags & 4) == 0) {
            return;
        }
        if ((source->mSourceFlags & 1) == 0) {
            source->mSourceFlags |= 1;
        } else {
            source->mSourceFlags &= ~1;
        }
        source->mSourceFlags &= ~4;
        return;
    }
    source->mSourceFlags |= 2;
    if (source->mSourceFlags & 4) {
        if ((source->mSourceFlags & 1) == 0) {
            source->mSourceFlags |= 1;
        } else {
            source->mSourceFlags &= ~1;
        }
        source->mSourceFlags &= ~4;
    }
    sound = source->mPlayingSounds.mHead;
    while (sound != NULL) {
        hadBit8 = (sound->mFlags & 8) != 0;
        sound->mFlags &= ~8;
        if (sound->mSeqPlayer != NULL) {
            if (sound->mFlags & 4) {
                if (hadBit8 == 0) {
                    removedSound = sound;
                    sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound);
                    NNS_SndPlayerStopSeq(&removedSound->mSeqPlayer, 0);
                    removedSound->mFlags &= ~4;
                    removedSound->mFlags &= ~8;
                    removedSound->mFlags &= ~2;
                    RemoveListObject(&source->mPlayingSounds, removedSound);
                    value = 1;
                    continue;
                }
            } else if (sound->mFlags & 1) {
                if (source->mUpdateListIndex == SOUND_SOURCE_LIST_NONE) {
                    TryAppendListObject(&gSoundSourceSecondUpdateList, source);
                    source->mUpdateListIndex = SOUND_SOURCE_LIST_IN_TURNS;
                }
            }
        } else if ((sound->mFlags & 2) == 0) {
            removedSound = sound;
            sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound);
            NNS_SndPlayerStopSeq(&removedSound->mSeqPlayer, 0);
            removedSound->mFlags &= ~4;
            removedSound->mFlags &= ~8;
            removedSound->mFlags &= ~2;
            RemoveListObject(&source->mPlayingSounds, removedSound);
            value = 1;
            continue;
        }
        sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound);
    }
    if (value == 0) {
        return;
    }
    value = SOUND_SOURCE_LIST_NONE;
    for (sound = source->mPlayingSounds.mHead; sound != NULL;
         sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound)) {
        if (sound->mFlags & 2) {
            value = SOUND_SOURCE_LIST_EVERY_CALL;
            break;
        }
        if (sound->mFlags & 8 || sound->mFlags & 1) {
            value = SOUND_SOURCE_LIST_IN_TURNS;
        }
    }
    if (source->mUpdateListIndex != value) {
        if (source->mUpdateListIndex != SOUND_SOURCE_LIST_NONE) {
            RemoveListObject(&gSoundSourceUpdateLists[source->mUpdateListIndex], source);
            source->mUpdateListIndex = SOUND_SOURCE_LIST_NONE;
        }
        if (value != SOUND_SOURCE_LIST_NONE) {
            TryAppendListObject(&gSoundSourceUpdateLists[value], source);
            source->mUpdateListIndex = value;
        }
    }
}

static inline s32 ComputeSoundPriority(u32 volumeForPriority, u8 seqArcNo, u16 soundId) {
    s32 priority = volumeForPriority + (NNS_SndArcGetSeqArcParam(seqArcNo, soundId)->mPlayerPrio - 0x40);
    if (priority > 0) {
        if (priority >= 0x7f) {
            priority = 0x7f;
        }
        return priority;
    }
    return 0;
}

u32 SetPlayingSoundsParams(SoundSource *source) {
    SoundParams params;
    s32 priority;
    Vec3 *position;
    PlayingSound *sound;

    position = source->mOwnerPosSource;
    params.mSource = source;
    params.mPositionSource = position;
    params.mStartParams = NULL;
    params.mVolume = 0;
    params.mVolumeForPriority = 0;
    params.mPan = 0;
    if (params.mPositionSource == 0) {
        params.mDistance = 0;
        params.mVolume = 0x7f;
        params.mVolumeForPriority = 0x7f;
        params.mPan = 0;
    } else {
        params.mDistance = gSoundDistanceFunction(&params);
        params.mVolumeForPriority = params.mVolume = gSoundVolumeFunction(&params);
        params.mPan = gSoundPanFunction(&params);
    }
    if (params.mVolume <= 0) {
        UnlinkSoundSourceSounds(source);
        return 0;
    }
    for (sound = source->mPlayingSounds.mHead; sound != NULL;
         sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound)) {
        priority = -1;
        if (sound->mFlags & 2) {
            priority = ComputeSoundPriority(params.mVolumeForPriority, sound->mSeqArcNo, sound->mSoundId);
            source->mStartSeqFunction(source, sound, priority);
            sound->mFlags &= ~2;
        }
        if (sound->mSeqPlayer != NULL) {
            if (priority == -1) {
                priority = ComputeSoundPriority(params.mVolumeForPriority, sound->mSeqArcNo, sound->mSoundId);
            }
            NNS_SndPlayerSetVolume(&sound->mSeqPlayer, params.mVolume);
            NNS_SndPlayerSetPlayerPriority(&sound->mSeqPlayer, priority);
            NNS_SndPlayerSetTrackPan(&sound->mSeqPlayer, gSeqTrackMask, params.mPan);
            source->mTrackParamsFunction(source, sound, &params);
        }
    }
    return 1;
}

PlayingSound *StartSoundEx(SoundSource *source, u32 seqArcNo, u32 soundId, u32 volume, s16 pitch) {
    PlayingSound *sound;
    PlayingSound *candidate;
    NNSFndList *sourceList;
    u32 matches;

    sound = NULL;
    if (gSoundModeHolder.mSoundsEnabled == 0) {
        return sound;
    }
    if ((source->mSourceFlags & 1) == 0) {
        return sound;
    }
    for (candidate = source->mPlayingSounds.mHead; candidate != NULL;
         candidate = NNS_FndGetNextListObject(&source->mPlayingSounds, candidate)) {
        matches = (candidate->mSoundId == soundId) && (candidate->mSeqArcNo == seqArcNo);
        if (matches) {
            StopPlayingSound(source, candidate, 0);
            ResetPlayingSoundHandle(candidate);
            ClearThreeWords(&candidate->mUnk_08);
            candidate->mSeqArcNo = 0;
            candidate->mSoundId = 0;
            candidate->mFlags = 0;
            candidate->mPitch = 0;
            candidate->mVolume = 0x7f;
            sound = candidate;
            break;
        }
    }
    if (sound == NULL) {
        sound = TakeSoundHandleEntry(&gPlayingSoundPool);
        StopPlayingSoundSeq(sound, 0);
        sourceList = sound->mSourceList;
        if (sourceList != NULL) {
            RemoveListObject(sourceList, sound);
            RefreshSoundSourceUpdateList((SoundSource *) (sourceList - 1));
        }
        ResetPlayingSound(sound);
    }
    ResetPlayingSoundHandle(sound);
    ClearThreeWords(&sound->mUnk_08);
    sound->mSeqArcNo = 0;
    sound->mSoundId = 0;
    sound->mFlags = 0;
    sound->mPitch = 0;
    sound->mVolume = 0x7f;
    sound->mSeqArcNo = seqArcNo;
    sound->mSoundId = soundId;
    sound->mFlags |= 2;
    sound->mVolume = volume;
    sound->mPitch = pitch;
    TryAppendListObject(&source->mPlayingSounds, sound);
    if (source->mUpdateListIndex != SOUND_SOURCE_LIST_EVERY_CALL) {
        if (source->mUpdateListIndex != SOUND_SOURCE_LIST_NONE) {
            RemoveListObject(&gSoundSourceUpdateLists[source->mUpdateListIndex], source);
            source->mUpdateListIndex = SOUND_SOURCE_LIST_NONE;
        }
        TryAppendListObject(gSoundSourceUpdateLists, source);
        source->mUpdateListIndex = SOUND_SOURCE_LIST_EVERY_CALL;
    }
    return sound;
}

PlayingSound *StartSoundWhileRequestedEx(SoundSource *source, u32 seqArcNo, u32 soundId, u32 volume, s16 pitch) {
    PlayingSound *sound;
    PlayingSound *candidate;
    NNSFndList *sourceList;
    u32 matches;

    sound = NULL;
    if (gSoundModeHolder.mSoundsEnabled == 0) {
        return sound;
    }
    if ((source->mSourceFlags & 1) == 0) {
        return sound;
    }
    for (candidate = source->mPlayingSounds.mHead; candidate != NULL;
         candidate = NNS_FndGetNextListObject(&source->mPlayingSounds, candidate)) {
        if (candidate->mFlags & 4) {
            matches = (candidate->mSoundId == soundId) && (candidate->mSeqArcNo == seqArcNo);
            if (matches) {
                if (candidate->mSeqPlayer != NULL) {
                    candidate->mFlags |= 8;
                    candidate->mVolume = volume;
                    candidate->mPitch = pitch;
                    if (source->mUpdateListIndex == SOUND_SOURCE_LIST_NONE) {
                        TryAppendListObject(&gSoundSourceSecondUpdateList, source);
                        source->mUpdateListIndex = SOUND_SOURCE_LIST_IN_TURNS;
                    }
                    return candidate;
                }
                StopPlayingSound(source, candidate, 0);
                ResetPlayingSoundHandle(candidate);
                ClearThreeWords(&candidate->mUnk_08);
                candidate->mSeqArcNo = 0;
                candidate->mSoundId = 0;
                candidate->mFlags = 0;
                candidate->mPitch = 0;
                candidate->mVolume = 0x7f;
                sound = candidate;
                break;
            }
        }
    }
    if (sound == NULL) {
        sound = TakeSoundHandleEntry(&gPlayingSoundPool);
        StopPlayingSoundSeq(sound, 0);
        sourceList = sound->mSourceList;
        if (sourceList != NULL) {
            RemoveListObject(sourceList, sound);
            RefreshSoundSourceUpdateList((SoundSource *) (sourceList - 1));
        }
        ResetPlayingSound(sound);
    }
    ResetPlayingSoundHandle(sound);
    ClearThreeWords(&sound->mUnk_08);
    sound->mSeqArcNo = 0;
    sound->mSoundId = 0;
    sound->mFlags = 0;
    sound->mPitch = 0;
    sound->mVolume = 0x7f;
    sound->mSeqArcNo = seqArcNo;
    sound->mSoundId = soundId;
    sound->mFlags |= 2;
    sound->mVolume = volume;
    sound->mPitch = pitch;
    sound->mFlags |= 4;
    sound->mFlags |= 8;
    TryAppendListObject(&source->mPlayingSounds, sound);
    if (source->mUpdateListIndex != SOUND_SOURCE_LIST_EVERY_CALL) {
        if (source->mUpdateListIndex != SOUND_SOURCE_LIST_NONE) {
            RemoveListObject(&gSoundSourceUpdateLists[source->mUpdateListIndex], source);
            source->mUpdateListIndex = SOUND_SOURCE_LIST_NONE;
        }
        TryAppendListObject(gSoundSourceUpdateLists, source);
        source->mUpdateListIndex = SOUND_SOURCE_LIST_EVERY_CALL;
    }
    return sound;
}

static inline u32 IsSameSound(PlayingSound *sound, u32 seqArcNo, u32 soundId) {
    return sound->mSoundId == soundId && sound->mSeqArcNo == seqArcNo;
}

void StopSoundEx(SoundSource *source, u32 seqArcNo, u32 soundId, u32 fadeSteps) {
    PlayingSound *sound;
    u32 matches;

    if (gSoundModeHolder.mSoundsEnabled == 0) {
        return;
    }
    sound = source->mPlayingSounds.mHead;
    while (sound != NULL) {
        matches = (sound->mSeqPlayer != NULL) && IsSameSound(sound, seqArcNo, soundId);
        if (matches) {
            StopPlayingSound(source, sound, fadeSteps);
            return;
        }
        sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound);
    }
}

void StopPlayingSound(SoundSource *source, PlayingSound *sound, u32 fadeSteps) {
    PlayingSound *entry;
    void *unused;
    u32 updateListIndex;
    u32 soundFlags;

    NNS_SndPlayerStopSeq(&sound->mSeqPlayer, fadeSteps);
    sound->mFlags &= ~4;
    sound->mFlags &= ~8;
    sound->mFlags &= ~2;
    RemoveListObject(&source->mPlayingSounds, sound);
    updateListIndex = SOUND_SOURCE_LIST_NONE;
    for (entry = source->mPlayingSounds.mHead; entry != NULL;
         entry = NNS_FndGetNextListObject(&source->mPlayingSounds, entry)) {
        soundFlags = entry->mFlags;
        if (soundFlags & 2) {
            updateListIndex = SOUND_SOURCE_LIST_EVERY_CALL;
            break;
        }
        if (soundFlags & 8 || soundFlags & 1) {
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

void StopAllSoundsAndReleaseSoundSource(SoundSource *source) {
    PlayingSound *sound;

    for (sound = source->mPlayingSounds.mHead; sound != NULL; sound = source->mPlayingSounds.mHead) {
        NNS_SndPlayerStopSeq(&sound->mSeqPlayer, 0);
        sound->mFlags &= ~4;
        sound->mFlags &= ~8;
        sound->mFlags &= ~2;
        RemoveListObject(&source->mPlayingSounds, sound);
    }
    if (source->mUpdateListIndex != SOUND_SOURCE_LIST_NONE) {
        RemoveListObject(&gSoundSourceUpdateLists[source->mUpdateListIndex], source);
        source->mUpdateListIndex = SOUND_SOURCE_LIST_NONE;
    }
    ReleaseSoundSource(source);
}

void StopSoundsStartedWhileRequested(SoundSource *source, u32 fadeSteps) {
    PlayingSound *sound;
    PlayingSound *removedSound;
    u32 value;
    u8 soundFlags;

    value = 0;
    sound = source->mPlayingSounds.mHead;
    while (sound != NULL) {
        if (sound->mFlags & 4) {
            removedSound = sound;
            sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound);
            NNS_SndPlayerStopSeq(&removedSound->mSeqPlayer, fadeSteps);
            removedSound->mFlags &= ~4;
            removedSound->mFlags &= ~8;
            removedSound->mFlags &= ~2;
            RemoveListObject(&source->mPlayingSounds, removedSound);
            value = 1;
            continue;
        }
        sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound);
    }
    if (value == 0) {
        return;
    }
    value = SOUND_SOURCE_LIST_NONE;
    for (sound = source->mPlayingSounds.mHead; sound != NULL;
         sound = NNS_FndGetNextListObject(&source->mPlayingSounds, sound)) {
        soundFlags = sound->mFlags;
        if (soundFlags & 2) {
            value = SOUND_SOURCE_LIST_EVERY_CALL;
            break;
        }
        if (soundFlags & 8 || soundFlags & 1) {
            value = SOUND_SOURCE_LIST_IN_TURNS;
        }
    }
    if (source->mUpdateListIndex != value) {
        if (source->mUpdateListIndex != SOUND_SOURCE_LIST_NONE) {
            RemoveListObject(&gSoundSourceUpdateLists[source->mUpdateListIndex], source);
            source->mUpdateListIndex = SOUND_SOURCE_LIST_NONE;
        }
        if (value != SOUND_SOURCE_LIST_NONE) {
            TryAppendListObject(&gSoundSourceUpdateLists[value], source);
            source->mUpdateListIndex = value;
        }
    }
}

void ReleaseSoundSource(SoundSource *source) {
    void *sound;

    StopSoundsStartedWhileRequested(source, 0);
    for (sound = source->mPlayingSounds.mHead; sound != NULL; sound = source->mPlayingSounds.mHead) {
        RemoveListObject(&source->mPlayingSounds, sound);
    }
    if (source->mUpdateListIndex != SOUND_SOURCE_LIST_NONE) {
        RemoveListObject(&gSoundSourceUpdateLists[source->mUpdateListIndex], source);
        source->mUpdateListIndex = SOUND_SOURCE_LIST_NONE;
    }
    RemoveListObject(&gSoundSources, source);
    source->mRegistered = 0;
}
