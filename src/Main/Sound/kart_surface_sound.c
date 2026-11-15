#include "Main/Sound/kart_surface_sound.h"
#include "Main/MapObjects/attractor.h" // MapObjectSound
#include "Main/MapObjects/view_frustum.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/sound_mode.h"
#include "Main/Graphics/cell_file_set.h"

#include "Main/Sound/sound_seq.h"
#include "Main/Sound/seq_queue.h"
#include "Main/Race/race_setup_block.h"
#include "tp.h"
#include "Main/Sound/sound_falloffs_ortho_quad_globals.h"
#include "player.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Kart/karts.h"
#include "sound_archive_load_result.h"
#include "Main/Sound/kart_sound_queue.h"
#include "Main/Sound/sound_start.h"
#include "Main/Race/race_progress_lap.h"
#include "Main/Item/pooled_item_box_init.h"
#include "Main/Sound/playing_sounds.h"
#include "Main/Menu/menu_screens_work.h"
#include "Main/Sound/sound_system.h"
#include "sound_player_type.h"
#include "stream.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "linked_list_ops.h"
#include "vector_math.h"

s32 gKartPitchPerWaterDepth;
vu32 gSoundPitchSwingAngle;
s32 gSoundPitchSwing;
KartSoundQueue gKartSoundQueue;
s32 gKouraPitchPerWaterDepth;

u32 InitSoundPitchSwing(void) {
    u32 value;
    u32 divisor;
    u32 zero;
    divisor = 0xafc8000u;
    value = 0x384000u;
    value = FX_Div(value, divisor);
    divisor = 0xafc8000u;
    gKartPitchPerWaterDepth = value;
    value = 0x1c2000u;
    value = FX_Div(value, divisor);
    zero = 0u;
    gKouraPitchPerWaterDepth = value;
    gSoundPitchSwing = zero;
    gSoundPitchSwingAngle = zero;
    return value;
}

void UpdateSoundPitchSwing(void) {
    s32 angle;
    s32 wrappedAngle;
    s32 anglePairFirst;
    s64 scaledSwing;

    angle = gSoundPitchSwingAngle + 0x1999;
    gSoundPitchSwingAngle = angle;
    wrappedAngle = angle & 0xffff;
    anglePairFirst = FX_SinIdx(wrappedAngle);
    scaledSwing = (s64) anglePairFirst * 0x90000 + 0x800;
    gSoundPitchSwingAngle = wrappedAngle;
    gSoundPitchSwing = (s32) FROM_FIXED12(scaledSwing) >> 12;
}

void StartSurfaceSound(SoundSource *source, int entryIndex, u32 surfaceKind, u32 surfaceVariant, u32 waterDepth) {
    int surfaceSoundId;
    if ((source->mSourceFlags & SOUND_SOURCE_FLAG_ENABLED) == 0) {
        return;
    }
    if (entryIndex == 2) {
        if ((0x00009c40u) < waterDepth) {
            StartSound(source, 0x70, SOUND_VOLUME_MAX, 0);
            return;
        }
        if (waterDepth != 0) {
            StartSound(source, 0x6f, SOUND_VOLUME_MAX, 0);
            return;
        }
    }
    surfaceSoundId = GetSurfaceSoundId(entryIndex, surfaceKind, surfaceVariant);
    if (surfaceSoundId != SURFACE_SOUND_NONE) {
        StartSound(source, surfaceSoundId, SOUND_VOLUME_MAX, 0);
        return;
    }
}

// Sound of the low-speed turn: the vehicle's row sound on every call, plus a surface sound when a direction key is
// held.
void StartKartLowSpeedTurnSound(Kart *kart, s32 withSurfaceSound, s32 surfaceKind, s32 surfaceVariant) {
    u32 soundId;

    switch (kart->mSound.mSoundRow.mSoundRowIndex) {
        case KART_SOUND_TABLE_ROW_FIRST:
            soundId = 0xb2;
            break;
        case KART_SOUND_TABLE_ROW_SECOND:
            soundId = 0xb9;
            break;
        case KART_SOUND_TABLE_ROW_THIRD:
            soundId = 0xc0;
            break;
    }
    if (withSurfaceSound != 0) {
        StartSoundWhileRequested(&kart->mSoundSource, GetSurfaceSoundId(1, surfaceKind, surfaceVariant), 0x5f, -0x345);
    }
    StartSoundWhileRequested(&kart->mSoundSource, soundId, SOUND_VOLUME_MAX, 0);
}

void StartKartSurfaceSoundWhileRequested(Kart *kart, s32 entryIndex, s32 surfaceKind, s32 surfaceVariant,
                                         u32 waterDepth) {
    KartSound *soundState;
    s16 pitch;
    s32 volume;
    BOOL isEntryKart;
    s16 depthPitch;
    u32 soundId;
    s32 lapProgress;
    s32 lapProgressDifference;
    u32 lapSoundKind;
    u32 baseSoundId;

    if (!(kart->mSoundSource.mSourceFlags & SOUND_SOURCE_FLAG_ENABLED)) {
        return;
    }
    if (kart->mEffectFlags & KART_EFFECT_KILLER) {
        return;
    }
    soundState = &kart->mSound;
    pitch = FROM_FIXED12(soundState->mPitch);
    if (pitch > 0x1fc) {
        volume = SOUND_VOLUME_MAX;
    } else {
        volume = pitch >> 2;
    }
    if (entryIndex == 1) {
        if (waterDepth != 0) {
            pitch = pitch + 0x1c0;
        } else {
            pitch = (s16) (pitch - 0x7d0) >> 2;
        }
    }
    if (waterDepth != 0) {
        depthPitch = 0;
        isEntryKart = kart->mIndex == gRaceSetup->mEntryIndex;
        if (waterDepth > 0x11170) {
            depthPitch = 0x384;
            if (isEntryKart != FALSE) {
                depthPitch += gSoundPitchSwing;
            }
        } else if (waterDepth > 0x61a8 && waterDepth <= 0x11170) {
            depthPitch =
                FROM_FIXED12(MUL_FIXED12_ROUNDED(gKartPitchPerWaterDepth, (s32) TO_FIXED12(waterDepth - 0x61a8)));
            if (isEntryKart != FALSE) {
                depthPitch += gSoundPitchSwing >> 1;
            }
        }
        StartSoundWhileRequested(&kart->mSoundSource, 0x74, volume & 0xff, (s16) (pitch - depthPitch));
    } else {
        soundId = GetSurfaceSoundId(entryIndex, surfaceKind, surfaceVariant);
        if (soundId == SURFACE_SOUND_NONE) {
            return;
        }
        switch (soundId) {
            case SURFACE_SOUND_LAP_PROGRESS_A:
            case SURFACE_SOUND_LAP_PROGRESS_B:
                lapSoundKind = soundId & 1;
                lapProgress = GetKartLapProgress(kart->mIndex);
                lapProgressDifference = lapProgress - soundState->mLapProgressAtLastSound;
                if (lapProgressDifference < 0) {
                    lapProgressDifference = -lapProgressDifference;
                }
                if (lapProgressDifference > GetLapProgressSoundGap(lapSoundKind)) {
                    baseSoundId = GetLapProgressSoundId(lapSoundKind);
                    soundState->mLapProgressSoundCount++;
                    StartSound(&kart->mSoundSource, (u16) ((soundState->mLapProgressSoundCount & 1) + baseSoundId),
                               SOUND_VOLUME_MAX, 0);
                    soundState->mLapProgressAtLastSound = lapProgress;
                }
                break;
            default:
                StartSoundWhileRequested(&kart->mSoundSource, soundId, volume & 0xff, pitch);
                break;
        }
    }
}

void StartKartSurfaceSound(Kart *kart, s32 entryIndex, s32 surfaceKind, s32 surfaceVariant, s32 unused) {
    u32 soundId;

    if (!(kart->mSoundSource.mSourceFlags & SOUND_SOURCE_FLAG_ENABLED)) {
        return;
    }
    soundId = GetSurfaceSoundIdShortRows(entryIndex, surfaceKind, surfaceVariant);
    if (soundId == SURFACE_SOUND_NONE) {
        return;
    }
    if (gRaceSetup->mCourseId == COURSE_ID_RAINBOW) {
        soundId = 0x1b6;
    }
    StartSound(&kart->mSoundSource, soundId, SOUND_VOLUME_MAX, 0);
}

void StartKartSeqArcSoundWithVolume(s32 soundIndex, s32 soundOffset, u32 volume, s32 playerNo, s32 playerPrio) {
    NNSSndSeqPlayer *sndHandle;
    u16 sequenceNo;

    if (IsRaceSceneNormalOrReplay() == 0) {
        return;
    }
    NNS_SndHandleInit(&sndHandle);
    sequenceNo = soundIndex * 0xe + soundOffset;
    if (sndHandle != NULL) {
        NNS_SndPlayerStopSeq(&sndHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArcEx(&sndHandle, playerNo, -1, playerPrio, 2, sequenceNo);
    SetSndHandleTrackVolume(&sndHandle, volume);
    NNS_SndHandleReleaseSeq(&sndHandle);
}

void StartKartCollisionSound(Kart *kart, s32 soundIndex, s16 unused) {
    PlayingSound *playingSound;
    s32 soundId;

    soundId = soundIndex + 0xc1;
    if (gSceneSoundState.mRaceFrames < KART_COLLISION_SOUND_MIN_RACE_FRAMES) {
        return;
    }
    playingSound = StartSoundEx(&kart->mSoundSource, 0, soundId, SOUND_VOLUME_MAX, 0);
    if (playingSound == NULL) {
        return;
    }
    playingSound->mFlags |= PLAYING_SOUND_FLAG_KART_COLLISION;
    playingSound->mFlags |= PLAYING_SOUND_FLAG_KART_COLLISION_VARIANT;
}

void StartKartSeqArcSound(Kart *kart, s32 soundIndex, s32 soundOffset) {
    NNSSndSeqPlayer *sndHandle;
    KartSound *soundState;
    u32 raceFrames;
    s32 volume;
    BOOL isEntryKart;
    u16 sequenceNo;
    s32 minFrames;
    s32 minFrameGap;

    raceFrames = gSceneSoundState.mRaceFrames;
    if (!(kart->mSoundSource.mSourceFlags & SOUND_SOURCE_FLAG_ENABLED)) {
        return;
    }
    soundState = &kart->mSound;
    if (kart->mEffectFlags & KART_EFFECT_KILLER) {
        return;
    }
    if (kart->mEntryFlags & KART_ENTRY_GHOST) {
        return;
    }
    if (gSceneSoundState.mRaceState != SCENE_RACE_STATE_RUNNING) {
        if (gSceneSoundState.mRaceState != SCENE_RACE_STATE_BEFORE_START) {
            return;
        }
        volume = SOUND_VOLUME_MAX;
        isEntryKart = kart->mIndex == gRaceSetup->mEntryIndex;
        if (soundOffset == 5) {
            volume = SOUND_VOLUME_MAX;
        } else if (soundOffset == 3) {
            volume = SOUND_VOLUME_MAX;
        }
        if (isEntryKart != FALSE) {
            if (IsRaceSceneNormalOrReplay() == 0) {
                return;
            }
            NNS_SndHandleInit(&sndHandle);
            sequenceNo = soundIndex * 0xe + soundOffset;
            if (sndHandle != NULL) {
                NNS_SndPlayerStopSeq(&sndHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArcEx(&sndHandle, 1, -1, 0x7f, 2, sequenceNo);
            SetSndHandleTrackVolume(&sndHandle, volume);
            NNS_SndHandleReleaseSeq(&sndHandle);
        } else {
            if (soundOffset != 3 && soundOffset != 5) {
                return;
            }
            StartSoundEx(&kart->mSoundSource, PLAYING_SOUND_SEQ_ARC_PER_CHARACTER, soundIndex * 0xe + (soundOffset + 1),
                         0x73, 0);
        }
    } else {
        minFrames = 0xf0;
        minFrameGap = 0x1e;
        if (soundOffset == 1 || soundOffset == 2) {
            minFrames = 0x3c;
            minFrameGap = 0;
        }
        if (raceFrames < minFrames) {
            return;
        }
        if (raceFrames - soundState->mLastSeqArcSoundRaceFrame < minFrameGap) {
            return;
        }
        StartSoundEx(&kart->mSoundSource, PLAYING_SOUND_SEQ_ARC_PER_CHARACTER, soundIndex * 0xe + soundOffset,
                     SOUND_VOLUME_MAX, 0);
        soundState->mLastSeqArcSoundRaceFrame = raceFrames;
    }
}

void InitKartSoundQueue(void) {
    s32 slotIndex;
    KartSoundQueue *queue = &gKartSoundQueue;

    queue->mCount = 0;
    queue->mDisabled = FALSE;
    for (slotIndex = 0; slotIndex < 8; slotIndex++) {
        queue->mKarts[slotIndex] = NULL;
        queue->mFramesSinceStart[slotIndex] = 0;
    }
    queue->mVolume = KART_SOUND_QUEUE_VOLUME_START;
    queue->mDelayFrames = -1;
}

void UpdateKartSoundQueue(void) {
    KartSoundQueue *queue = &gKartSoundQueue;
    s32 slotIndex;

    if (queue->mDisabled != FALSE) {
        return;
    }
    if (queue->mDelayFrames != -1) {
        queue->mDelayFrames++;
        if (queue->mDelayFrames >= KART_SOUND_QUEUE_DELAY_FRAMES) {
            queue->mDelayFrames = -1;
        }
        return;
    }
    for (slotIndex = 0; slotIndex < 8; slotIndex++) {
        if (queue->mKarts[slotIndex] == NULL) {
            continue;
        }
        if (queue->mFramesSinceStart[slotIndex] == 0) {
            if (slotIndex != 0 && queue->mFramesSinceStart[slotIndex - 1] < KART_SOUND_QUEUE_GAP_FRAMES) {
                continue;
            }
            if (slotIndex != 0 && queue->mFramesSinceStart[slotIndex - 1] == KART_SOUND_QUEUE_GAP_FRAMES) {
                queue->mVolume -= KART_SOUND_QUEUE_VOLUME_STEP;
            } else {
                queue->mVolume = KART_SOUND_QUEUE_VOLUME_START;
            }
            if (queue->mVolume < KART_SOUND_QUEUE_VOLUME_MIN) {
                queue->mVolume = KART_SOUND_QUEUE_VOLUME_MIN;
            }
            StartQueuedKartSound(queue->mKarts[slotIndex], queue->mSoundIndices[slotIndex], 0, queue->mVolume);
            queue->mFramesSinceStart[slotIndex]++;
        } else {
            queue->mFramesSinceStart[slotIndex]++;
        }
    }
}

void QueueKartSound(Kart *kart, s32 soundIndex) {
    KartSoundQueue *queue = &gKartSoundQueue;

    if (queue->mDisabled != FALSE) {
        return;
    }
    if (kart->mIndex == gRaceSetup->mEntryIndex) {
        StartQueuedKartSound(kart, soundIndex, 1, 0x6e);
        queue->mDelayFrames = 0;
        return;
    }
    queue->mKarts[queue->mCount] = kart;
    queue->mSoundIndices[queue->mCount] = soundIndex;
    queue->mCount++;
}

void StartQueuedKartSound(Kart *kart, s32 soundIndex, s32 useKartSource, s32 volume) {
    NNSSndSeqPlayer *sndHandle;
    PlayingSound *playingSound;
    PlayingSound *stoppedSound;
    BOOL modeAllowsSound;
    u16 sequenceNo;
    enum { SOUND_OFFSET_FIRST } soundOffset;

    playingSound = kart->mSoundSource.mPlayingSounds.mHead;
    if (playingSound != NULL) {
        do {
            if (playingSound->mSeqArcNo == PLAYING_SOUND_SEQ_ARC_PER_CHARACTER) {
                stoppedSound = playingSound;
                playingSound = NNS_FndGetNextListObject(&kart->mSoundSource.mPlayingSounds, playingSound);
                StopPlayingSound(&kart->mSoundSource, stoppedSound, 0);
            } else {
                playingSound = NNS_FndGetNextListObject(&kart->mSoundSource.mPlayingSounds, playingSound);
            }
        } while (playingSound != NULL);
    }
    modeAllowsSound = TRUE;
    if (gSoundModeHolder.mMode != SCENE_SOUND_MODE_PLAYING &&
        gSoundModeHolder.mMode != SCENE_SOUND_MODE_MAIN_SEQUENCE_ONLY) {
        modeAllowsSound = FALSE;
    }
    if (modeAllowsSound == FALSE) {
        return;
    }
    soundOffset = 0xd;
    if (useKartSource != 0) {
        StartSoundEx(&kart->mSoundSource, PLAYING_SOUND_SEQ_ARC_PER_CHARACTER, soundIndex * 0xe + soundOffset,
                     SOUND_VOLUME_MAX, 0);
        return;
    }
    if (IsRaceSceneNormalOrReplay() == 0) {
        return;
    }
    NNS_SndHandleInit(&sndHandle);
    sequenceNo = soundIndex * 0xe + soundOffset;
    if (sndHandle != NULL) {
        NNS_SndPlayerStopSeq(&sndHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArcEx(&sndHandle, -1, -1, 0x6e, 2, sequenceNo);
    SetSndHandleTrackVolume(&sndHandle, volume);
    NNS_SndHandleReleaseSeq(&sndHandle);
}

// Plays the winner or loser sound of the character in the battle end; also disables the kart sound queue.
void StartBattleWinOrLoseSound(s32 soundIndex, s32 isWinner) {
    NNSSndSeqPlayer *sndHandle;
    s32 soundOffset;
    u16 sequenceNo;

    soundOffset = isWinner != 0 ? 0xc : 0xd;
    gKartSoundQueue.mDisabled = TRUE;
    if (IsRaceSceneNormalOrReplay() == 0) {
        return;
    }
    NNS_SndHandleInit(&sndHandle);
    sequenceNo = soundIndex * 0xe + soundOffset;
    if (sndHandle != NULL) {
        NNS_SndPlayerStopSeq(&sndHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArcEx(&sndHandle, 7, -1, -1, 2, sequenceNo);
    SetSndHandleTrackVolume(&sndHandle, 0x6e);
    NNS_SndHandleReleaseSeq(&sndHandle);
}

void GhostKartStartSeqNop(Kart *kart, PlayingSound *playingSound, s32 unused) {}

void RemovedKartStartSeqNop(Kart *kart, PlayingSound *playingSound, s32 unused) {}

void SetKartStartSeqNop(Kart *kart) {
    kart->mSoundSource.mStartSeqFunction = (void (*)(void *, void *, u32)) RemovedKartStartSeqNop;
}

void StartKartPlayingSoundSeq(Kart *kart, PlayingSound *playingSound, s32 playerPrio) {
    u32 seqArcNo;
    u32 soundId;
    s32 playerNo;
    NNSSndSeqParam *seqParam;
    u32 value;

    seqArcNo = playingSound->mSeqArcNo;
    soundId = playingSound->mSoundId;
    playerNo = -1;
    if (kart->mIndex == gRaceSetup->mEntryIndex) {
        seqParam = NNS_SndArcGetSeqArcParam(seqArcNo, soundId);
        value = seqParam->mPlayerNo;
        if (value == 2) {
            playerNo = 4;
        } else if (value == 3) {
            playerNo = 5;
        } else if (value == 6) {
            if (IsTeresaSoundFlagSet() != 0 || IsKartNear() != 0) {
                playerNo = 7;
            }
        }
    }
    if ((playingSound->mFlags & PLAYING_SOUND_FLAG_KART_COLLISION) &&
        (playingSound->mFlags & PLAYING_SOUND_FLAG_KART_COLLISION_VARIANT)) {
        value = GetKartVariant(kart->mIndex) + 0x2d;
        NNS_SndArcPlayerStartSeqArcEx(&playingSound->mSeqPlayer, playerNo, value, playerPrio, seqArcNo, soundId);
        if (playingSound == NULL) {
            return;
        }
        NNS_SndPlayerWriteVariable(&playingSound->mSeqPlayer, 0, kart->mSound.mSoundIndex);
    } else {
        NNS_SndArcPlayerStartSeqArcEx(&playingSound->mSeqPlayer, playerNo, -1, playerPrio, seqArcNo, soundId);
    }
}

u32 GetZeroSoundDistanceChange(SoundDistanceSquaredChange *change) {
    return 0x0u;
}

void SetKartPlayingSoundVolumePitch(Kart *kart, PlayingSound *playingSound, s32 pitchOffset) {
    s32 totalPitchOffset;
    u32 volume;
    u32 waterDepth;
    BOOL isEntryKart;
    s16 depthPitch;

    volume = playingSound->mVolume;
    totalPitchOffset = pitchOffset + kart->mSound.mDistanceChangeFunction(&kart->mSoundDistanceSquaredChange);
    if (playingSound->mSeqArcNo != PLAYING_SOUND_SEQ_ARC_PER_CHARACTER) {
        waterDepth = kart->mWaterDepth;
        depthPitch = 0;
        isEntryKart = kart->mIndex == gRaceSetup->mEntryIndex;
        if (waterDepth > 0x11170) {
            depthPitch = 0x384;
            if (isEntryKart != FALSE) {
                depthPitch += gSoundPitchSwing;
            }
        } else if (waterDepth > 0x61a8 && waterDepth <= 0x11170) {
            depthPitch =
                FROM_FIXED12(MUL_FIXED12_ROUNDED(gKartPitchPerWaterDepth, (s32) TO_FIXED12(waterDepth - 0x61a8)));
            if (isEntryKart != FALSE) {
                depthPitch += gSoundPitchSwing >> 1;
            }
        }
        totalPitchOffset -= depthPitch;
    } else {
        waterDepth = kart->mWaterDepth;
        depthPitch = 0;
        if (waterDepth > 0x11170) {
            depthPitch += gSoundPitchSwing;
        } else if (waterDepth > 0x61a8 && waterDepth <= 0x11170) {
            depthPitch += gSoundPitchSwing;
        }
        totalPitchOffset -= depthPitch;
    }
    SetSndHandleTrackVolume(&playingSound->mSeqPlayer, volume);
    SetSndHandleTrackPitch(&playingSound->mSeqPlayer, playingSound->mPitch + totalPitchOffset);
}

void SetItemKouraSoundTrackParams(Kart *kartArg, PlayingSound *playingSound) {
    Vec3 *vector;
    u32 volume;
    s32 pitchOffset;
    s16 depthPitch;
    u32 depth;
    s32 heightAboveWater;

    pitchOffset = 0;
    volume = playingSound->mVolume;
    if (kartArg->mMotionFlags == 0) {
        vector = (Vec3 *) &kartArg->mDrawBaseRow2.y;
    } else {
        vector = (Vec3 *) &kartArg->mCourseContactNormal.z;
    }
    pitchOffset += vector->z;
    heightAboveWater = GetHeightAboveWaterOrEfct(kartArg->mTurnedForward.y);
    if (heightAboveWater < 0) {
        depth = -heightAboveWater;
        depthPitch = 0;
        if (depth > 0x11170) {
            depthPitch = 0x1c2;
            depthPitch += gSoundPitchSwing;
        } else if (depth > 0x61a8 && depth <= 0x11170) {
            depthPitch = FROM_FIXED12(MUL_FIXED12_ROUNDED(gKouraPitchPerWaterDepth, (s32) TO_FIXED12(depth - 0x61a8)));
            depthPitch += gSoundPitchSwing >> 1;
        }
        pitchOffset -= depthPitch;
    }
    SetSndHandleTrackVolume(&playingSound->mSeqPlayer, volume);
    SetSndHandleTrackPitch(&playingSound->mSeqPlayer, playingSound->mPitch + pitchOffset);
}

void UpdateKartPlayingSound(Kart *kart, PlayingSound *playingSound) {
    SetKartPlayingSoundVolumePitch(kart, playingSound, 0);
}

void SetKartThunderShrinkSoundTrackParams(Kart *kart, PlayingSound *playingSound) {
    u32 flags;
    s32 pitchOffset;

    flags = playingSound->mFlags;
    pitchOffset = 0;
    if (!(flags & PLAYING_SOUND_FLAG_SKIP_SHRINK_PITCH) &&
        gSceneSoundState.mRaceFrames > kart->mSound.mThunderShrinkRaceFrame + 1) {
        pitchOffset = 0x180;
        if (flags & PLAYING_SOUND_FLAG_KART_SOUND_RECORD) {
            pitchOffset += 0x100;
        }
    }
    SetKartPlayingSoundVolumePitch(kart, playingSound, pitchOffset);
}

void SetVehicleSoundTrackParams(struct MapObjectSound *soundSource, PlayingSound *playingSound) {
    u32 distanceChange;

    distanceChange = soundSource->mSoundDistanceSquaredChange.mDifference;
    SetSndHandleTrackVolume(&playingSound->mSeqPlayer, playingSound->mVolume);
    SetSndHandleTrackPitch(&playingSound->mSeqPlayer, playingSound->mPitch + distanceChange);
}

void SetNsKiller2SoundTrackParams(struct MapObjectSound *soundSource, PlayingSound *playingSound) {
    u32 distanceChange;

    distanceChange = soundSource->mSoundDistanceSquaredChange.mDifference;
    SetSndHandleTrackVolume(&playingSound->mSeqPlayer, playingSound->mVolume);
    SetSndHandleTrackPitch(&playingSound->mSeqPlayer, playingSound->mPitch + distanceChange);
}

void SetItemKouraWSoundTrackParams(Kart *kart, PlayingSound *playingSound) {
    s32 distanceChange;

    distanceChange = (s32) kart->mTowardTurnCounter;
    SetSndHandleTrackVolume(&playingSound->mSeqPlayer, playingSound->mVolume);
    SetSndHandleTrackPitch(&playingSound->mSeqPlayer, playingSound->mPitch + distanceChange);
}
