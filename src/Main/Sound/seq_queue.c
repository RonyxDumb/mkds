#include "Main/Sound/seq_queue.h"
#include "Main/Sound/sound_start.h"

#include "Main/Menu/menu_screens_work.h"
#include "sound_player_control.h"
#include "sound_player_type.h"
#include "sound_stream_control.h"
#include "sound_capture_effect.h"
#include "Main/Graphics/layout_rect_table.h"
#include "Main/Graphics/layout_entry_angle.h"
#include "Main/Graphics/layout_table_entry.h"
#include "Main/Race/race_hud_sub_screen_cells.h"
#include "sound_archive_load.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Sound/sound_set_load.h"
#include "Main/Sound/sound_ortho_quad_and_item_box_timer_globals.h"
#include "matrix44_concat.h"
#include "Main/Graphics/ortho_quad_corners.h"
#include "Main/Sound/surface_sound_ids.h"
#include "Main/Sound/sound_source_list.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Sound/sound_handle_pool.h"
#include "Main/Kart/shadow_model_draw.h"
#include "sound_archive_load_result.h"
#include "Main/Kart/kart_drift.h"
#include "fixed_vector_math.h"
#include "Main/Menu/kart_icon_row.h"
#include "Main/Sound/race_end_seq.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Kart/kart_name_tags.h"
#include "01/Race/race_hud_coin_cells.h"
#include "Main/Sound/sound_system.h"

const s32 gLapProgressSoundGapDividends[2] = {0x14000, 0x10000};
u16 gLapProgressSoundIds[2] = {0x7e, 0x7c};
u32 gThunderShrinkSoundCounter;
s32 gKartNearPlayerVolumeFactor;
s32 gKingTeresaSeqVolumeFactor;
u32 gAnySeqVariableEnabled;
s32 gKingTeresaStateFrames;
s32 gKingTeresaState;
s32 gKingTeresaStateLastFrame;
s32 gPreviousKingTeresaState;
s32 gUseKingTeresaSeqVolume;
s32 gKartNearSeqVolumeFactor;
s32 gInitialVolumePerFrame;
s32 gEmblemSoundValue;
u32 gEmblemSoundCallsSincePlay;
s32 gKingTeresaSoundVolumeFactor;
volatile s32 gReachedSeqVolume;
u32 gSeqVariableEnabled[2];
VolumeFade gVolumeFade;
s32 gLapProgressSoundGaps[2];
s32 gKingTeresaVolumePerFrame[2];
SeqPlayerControl gSeqPlayerControl;
SeqVariableReading gSeqVariableReadings[2];
SoundRequestQueue gSoundRequestQueues[7];
SeqQueue gSeqQueue;

void SetEmblemSoundValue(u32 value) {
    gEmblemSoundValue = value;
}

// Plays the stored emblem sound once, then stores 7 (none).
void UpdateEmblemSound(void) {
    s32 soundValue;
    soundValue = gEmblemSoundValue;
    if (soundValue == 7) {
        soundValue = 6;
    }
    StartEmblemSound(soundValue);
    gEmblemSoundValue = 7;
}

void ResetSeqQueue(void) {
    s32 entryIndex;
    entryIndex = 0;
    gSeqQueue.mNextStartTimer = entryIndex;
    gSeqQueue.mWriteIndex = entryIndex;
    gSeqQueue.mReadIndex = entryIndex;
    for (entryIndex = 0; entryIndex < SEQ_QUEUE_LENGTH; entryIndex++) {
        gSeqQueue.mPairNo[entryIndex] = SEQ_QUEUE_EMPTY_PAIR_NO;
        gSeqQueue.mPairSide[entryIndex] = SEQ_QUEUE_EMPTY_PAIR_SIDE;
    }
}

// Starts the next queued seq once the delay since the previous start has run out.
void UpdateSeqQueue(void) {
    SeqQueue *queue = &gSeqQueue;
    s32 readIndex;
    s32 pairNo;
    s32 pairSide;
    s32 seqArcNo;
    u32 seqIndex;
    if (queue->mNextStartTimer == 0) {
        readIndex = queue->mReadIndex;
        pairNo = queue->mPairNo[readIndex];
        if (pairNo != SEQ_QUEUE_EMPTY_PAIR_NO) {
            pairSide = queue->mPairSide[readIndex];
            seqArcNo = 3;
            if (pairNo == 12) {
                if (pairSide == 0) {
                    seqIndex = 0x47;
                } else {
                    seqIndex = 0x48;
                }
                seqArcNo = 0;
            } else {
                seqIndex = (u16) (pairSide + pairNo * 2);
            }
            NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, seqArcNo, seqIndex);
            if (gSharedSeqHandle != NULL) {
                SetSndHandleTrackVolume(&gSharedSeqHandle, 0x3c);
            }
            gSeqQueue.mPairNo[queue->mReadIndex] = SEQ_QUEUE_EMPTY_PAIR_NO;
            gSeqQueue.mPairSide[queue->mReadIndex] = SEQ_QUEUE_EMPTY_PAIR_SIDE;
            queue->mNextStartTimer = SEQ_QUEUE_START_DELAY_FRAMES;
            queue->mReadIndex = queue->mReadIndex + 1;
            readIndex = queue->mReadIndex;
            if (readIndex == SEQ_QUEUE_LENGTH) {
                readIndex = 0;
            }
            queue->mReadIndex = readIndex;
        }
    }
    if (queue->mNextStartTimer > 0) {
        queue->mNextStartTimer = queue->mNextStartTimer - 1;
    }
}

void AddSeqQueueEntry(u32 pairNo, u32 pairSide) {
    s32 writeIndex;
    s32 nextIndex;
    writeIndex = gSeqQueue.mWriteIndex;
    gSeqQueue.mPairNo[writeIndex] = pairNo;
    nextIndex = writeIndex + 1;
    gSeqQueue.mPairSide[writeIndex] = pairSide;
    if (nextIndex == SEQ_QUEUE_LENGTH) {
        nextIndex = 0;
    }
    gSeqQueue.mWriteIndex = nextIndex;
}

void StartSeqPair(s32 pairNo, s32 pairSide) {
    u16 seqIndex;
    u32 seqArcNo;
    seqArcNo = 3;
    if (pairNo == 0xc) {
        if (pairSide == 0) {
            seqIndex = 0x47;
        } else {
            seqIndex = 0x48;
        }
        seqArcNo = 0;
    } else {
        seqIndex = pairSide + pairNo * 2;
    }
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, seqArcNo, seqIndex);
    if (gSharedSeqHandle != NULL) {
        SetSndHandleTrackVolume(&gSharedSeqHandle, 100);
    }
    NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 4);
}

void StartCursorMoveSound(void) {
    StartSoundOncePerFrame(0);
}

s32 StepValueTowardTarget(PlayerVolumeFade *volumeFade, s32 target) {
    s32 currentValue;
    s32 nextValue;
    currentValue = FROM_FIXED12(volumeFade->mVolume);
    if (target == currentValue) {
        return -1;
    }
    if (currentValue <= target) {
        nextValue = volumeFade->mVolume + volumeFade->mVolumePerFrame;
        if (FROM_FIXED12(nextValue) > target) {
            nextValue = TO_FIXED12(target);
        }
    } else {
        nextValue = volumeFade->mVolume - volumeFade->mVolumePerFrame;
        if (FROM_FIXED12(nextValue) < target) {
            nextValue = TO_FIXED12(target);
        }
    }
    volumeFade->mVolume = nextValue;
    return FROM_FIXED12(volumeFade->mVolume);
}

void InitSoundRequestQueues(void) {
    s32 queueIndex;
    SoundRequestQueue *queue;
    for (queueIndex = 0, queue = gSoundRequestQueues; queueIndex < 7; queueIndex++, queue++) {
        s32 capacities[7] = {1, 3, 2, 1, 3, 2, 3};
        InitSoundRequestQueue(queue, capacities[queueIndex], gCurrentSndHeap);
    }
}

void ResetSoundRequestQueues(void) {
    s32 queueIndex;
    SoundRequestQueue *queue;
    for (queueIndex = 0, queue = gSoundRequestQueues; queueIndex < 7; queueIndex++, queue++) {
        ResetSoundRequestQueue(queue);
    }
}

s32 GetLapProgressSoundGap(u32 index) {
    return gLapProgressSoundGaps[index];
}

u16 GetLapProgressSoundId(int index) {
    return gLapProgressSoundIds[index];
}

void SetLapProgressSoundGaps(u32 divisor) {
    s32 gapIndex;
    for (gapIndex = 0; gapIndex < 2; gapIndex++) {
        gLapProgressSoundGaps[gapIndex] = FX_Div(gLapProgressSoundGapDividends[gapIndex], divisor);
    }
}

void InitKingTeresaSoundState(u32 kingTeresaFlag) {
    gUseKingTeresaSeqVolume = kingTeresaFlag;
    gKingTeresaState = KING_TERESA_STATE_HIDDEN;
    gKingTeresaStateLastFrame = KING_TERESA_STATE_HIDDEN;
    gPreviousKingTeresaState = KING_TERESA_STATE_HIDDEN;
    gKingTeresaStateFrames = 0;
}

u32 InitKartNearSoundFactors(void) {
    s32 playerVolumeFactor;
    gKartNearSeqVolumeFactor = FX_Div(TO_FIXED12(gSceneSeqVolume - 0x14), 0x8340000);
    playerVolumeFactor = FX_Div(0x61000, 0x8340000);
    gKartNearPlayerVolumeFactor = playerVolumeFactor;
    return playerVolumeFactor;
}

void InitVolumeFade(void) {
    gInitialVolumePerFrame = FX_Div(0x7f000, 0x1e000);
    gKingTeresaVolumePerFrame[0] = FX_Div(0x7f000, 0x1e000);
    gKingTeresaVolumePerFrame[1] = FX_Div(0x7f000, 0x5a000);
    gKingTeresaSeqVolumeFactor = FX_Div(TO_FIXED12(gSceneSeqVolume), 0x23000);
    gKingTeresaSoundVolumeFactor = FX_Div(0x7f000, 0x19000);
    gVolumeFade.mVolumePerFrame = gInitialVolumePerFrame;
    gVolumeFade.mVolume = TO_FIXED12(SOUND_VOLUME_MAX);
    gReachedSeqVolume = gSceneSeqVolume;
}

void StartKingTeresaAlphaSound(MapObjectSound *mapSound) {
    s32 attenuation;
    attenuation =
        FROM_FIXED12(MUL_FIXED12_ROUNDED(gKingTeresaSoundVolumeFactor, 0x1f000 - GetMissionRunMapObjectAlphaLimit()));
    if (attenuation < 0) {
        attenuation = 0;
    } else if (attenuation > 0x7f) {
        attenuation = 0x7f;
    }
    StartSoundWhileRequested(&mapSound->mSoundSource, 0x231, (SOUND_VOLUME_MAX - attenuation) & 0xff, 0);
}

BOOL IsKingTeresaState0Or2Or5(void) {
    u32 result;
    u32 state;
    result = 0;
    state = gKingTeresaState;
    if (state <= KING_TERESA_STATE_GROUP_ENTRY) {
        if ((1 << state) & ((1 << KING_TERESA_STATE_WAIT_TO_APPROACH) | (1 << KING_TERESA_STATE_MOVE_TO_FORWARD_POINT) |
                            (1 << KING_TERESA_STATE_GROUP_ENTRY))) {
            result = 1;
        }
    }
    return result;
}

// Sets the volume of player 1 and the seq pitch, steps gVolumeFade towards targetVolume and sets the seq volume when it
// changed.
static inline void StepKingTeresaVolumeFade(NNSSndSeqPlayer **handle, s32 playerVolume, s32 pitch, s32 targetVolume) {
    s32 limitedVolume;
    s32 volume;
    s32 steppedVolume;
    s32 nextVolume;
    SetPlayerVolumeTarget(1, playerVolume);
    NNS_SndPlayerSetTrackPitch(handle, 0xffff, pitch);
    volume = FROM_FIXED12(gVolumeFade.mVolume);
    if (targetVolume == volume) {
        steppedVolume = -1;
    } else {
        if (volume <= targetVolume) {
            nextVolume = gVolumeFade.mVolume + gVolumeFade.mVolumePerFrame;
            if (FROM_FIXED12(nextVolume) > targetVolume) {
                nextVolume = TO_FIXED12(targetVolume);
            }
        } else {
            nextVolume = gVolumeFade.mVolume - gVolumeFade.mVolumePerFrame;
            if (FROM_FIXED12(nextVolume) < targetVolume) {
                nextVolume = TO_FIXED12(targetVolume);
            }
        }
        volume = FROM_FIXED12(nextVolume);
        steppedVolume = volume;
        gVolumeFade.mVolume = nextVolume;
    }
    gReachedSeqVolume = volume;
    limitedVolume = gSceneSeqVolume;
    if (volume <= limitedVolume) {
        if (volume < 0) {
            volume = 0;
        }
        limitedVolume = volume;
    }
    gReachedSeqVolume = limitedVolume;
    if (steppedVolume != -1) {
        NNS_SndPlayerSetVolume(handle, steppedVolume);
    }
}

void UpdateKingTeresaSeqVolume(NNSSndSeqPlayer **handle) {
    s32 targetVolume;
    s32 value;
    value = gKingTeresaState;
    targetVolume = gSceneSeqVolume;
    switch (value) {
        case KING_TERESA_STATE_WAIT_TO_APPROACH:
            value = FROM_FIXED12(
                MUL_FIXED12_ROUNDED(gKingTeresaSeqVolumeFactor, 0x29000 - GetMissionRunMapObjectAlphaLimit()));
            targetVolume = 0;
            if (value >= 0) {
                targetVolume = gSceneSeqVolume;
                if (value <= targetVolume) {
                    targetVolume = value;
                }
            }
            break;
        case KING_TERESA_STATE_APPROACH_KART:
            targetVolume = 0;
            break;
        case KING_TERESA_STATE_MOVE_TO_FORWARD_POINT:
            targetVolume = 0;
            break;
        case KING_TERESA_STATE_GROUP_ENTRY:
            if (gPreviousKingTeresaState == KING_TERESA_STATE_MOVE_TO_FORWARD_POINT) {
                if (gKingTeresaStateFrames < 0x14) {
                    targetVolume = 0;
                }
            }
            break;
        case KING_TERESA_STATE_END_REACHED:
            break;
    }
    if (gKingTeresaStateLastFrame != gKingTeresaState) {
        gKingTeresaStateFrames = 0;
    } else {
        gKingTeresaStateFrames++;
    }
    if (targetVolume != gSceneSeqVolume) {
        gVolumeFade.mVolumePerFrame = gKingTeresaVolumePerFrame[0];
    } else {
        gVolumeFade.mVolumePerFrame = gKingTeresaVolumePerFrame[1];
    }
    StepKingTeresaVolumeFade(handle, 0x7f, 0, targetVolume);
}

u32 IsSndHandleSet(NNSSndSeqPlayer **handle) {
    if (*handle != NULL) {
        return 1;
    }
    return 0;
}

u32 IsSndHandleSeq(NNSSndSeqPlayer **handle, u32 seqArcNo, u32 index) {
    NNSSndSeqPlayer *player = *handle;
    u32 result = 0;
    if (player->mSeqArcIndex != index) {
        return result;
    }
    if (player->mSeqNo == seqArcNo) {
        result = 1;
    }
    return result;
}

void StopSndHandleSeq(NNSSndSeqPlayer **handle, u32 fadeSteps) {
    NNS_SndPlayerStopSeq(handle, fadeSteps);
}

void StartSeqOnHandleIfEnabled(u32 soundId, NNSSndSeqPlayer **handle) {
    if ((gRaceSoundKind & 1) == 0) {
        return;
    }
    if (gSoundModeHolder.mSeqStartEnabled == 0) {
        return;
    }
    if (*handle != NULL) {
        NNS_SndPlayerStopSeq(handle, 0);
    }
    if (*handle != NULL) {
        NNS_SndPlayerStopSeq(handle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(handle, 0, soundId);
}

// Sets the volume of player 1 and the seq pitch, steps gVolumeFade towards targetVolume and sets the seq volume when it
// changed.
static inline void StepSeqPlayerVolumeFade(NNSSndSeqPlayer **handle, s32 playerVolume, s32 pitch, s32 targetVolume) {
    s32 limitedVolume;
    s32 volume;
    s32 steppedVolume;
    s32 nextVolume;
    SetPlayerVolumeTarget(1, playerVolume);
    NNS_SndPlayerSetTrackPitch(handle, 0xffff, pitch);
    volume = FROM_FIXED12(gVolumeFade.mVolume);
    if (targetVolume == volume) {
        steppedVolume = -1;
    } else {
        if (volume <= targetVolume) {
            nextVolume = gVolumeFade.mVolume + gVolumeFade.mVolumePerFrame;
            if (FROM_FIXED12(nextVolume) > targetVolume) {
                nextVolume = TO_FIXED12(targetVolume);
            }
        } else {
            nextVolume = gVolumeFade.mVolume - gVolumeFade.mVolumePerFrame;
            if (FROM_FIXED12(nextVolume) < targetVolume) {
                nextVolume = TO_FIXED12(targetVolume);
            }
        }
        volume = FROM_FIXED12(nextVolume);
        steppedVolume = volume;
        gVolumeFade.mVolume = nextVolume;
    }
    gReachedSeqVolume = volume;
    limitedVolume = gSceneSeqVolume;
    if (volume <= limitedVolume) {
        if (volume < 0) {
            volume = 0;
        }
        limitedVolume = volume;
    }
    gReachedSeqVolume = limitedVolume;
    if (steppedVolume != -1) {
        NNS_SndPlayerSetVolume(handle, steppedVolume);
    }
}

void UpdateSeqPlayerControl(SeqPlayerControl *control, NNSSndSeqPlayer **handle) {
    u32 slotVolume;
    s32 targetVolume;
    s32 pitch;
    s32 value;
    s32 slotSeqIndex;
    s32 minKartDistanceSquared;
    s32 scaledDistance;
    s64 scaledDistanceWide;
    s32 volume;
    NNSSndSeqPlayer **slotHandle;
    pitch = 0;
    slotVolume = pitch;
    value = 0x7f;
    slotSeqIndex = -1;
    if (control->mVolumeOverride > SEQ_VOLUME_OVERRIDE_NONE) {
        switch (control->mVolumeOverride) {
            case SEQ_VOLUME_OVERRIDE_ZERO:
                value = pitch;
                break;
            case SEQ_VOLUME_OVERRIDE_FULL:
                break;
        }
        StepSeqPlayerVolumeFade(handle, 0x7f, 0, value);
        return;
    }
    if (gUseKingTeresaSeqVolume != 0) {
        UpdateKingTeresaSeqVolume(handle);
        return;
    }
    control->mKartNear =
        (TryGetMinKartDistanceSquared(&minKartDistanceSquared) != FALSE && minKartDistanceSquared < 0x8d04) ? 1 : 0;
    if ((control->mFlags >> SEQ_PLAYER_BIT_TERESA) & 1) {
        targetVolume = 0;
        value = 0x1e;
        slotSeqIndex = 0xff;
        slotVolume = 0x7f;
    } else if (control->mKartNear != 0) {
        scaledDistance = TO_FIXED12(minKartDistanceSquared - 2500);
        scaledDistanceWide = scaledDistance;
        volume = FROM_FIXED12(MUL_FIXED12_ROUNDED(gKartNearPlayerVolumeFactor, scaledDistance));
        volume += 0x1e;
        if (volume < 0) {
            volume = 0;
        } else if (volume > 0x7f) {
            volume = 0x7f;
        }
        value = volume & 0xff;
        volume = (s32) ((gKartNearSeqVolumeFactor * scaledDistanceWide + 0x800) >> 12) >> 12;
        slotVolume = (0x9d - value) & 0xff;
        targetVolume = volume + 0x14;
        slotSeqIndex = 0xfe;
        if (targetVolume < 0) {
            targetVolume = 0;
        } else if (targetVolume > 0x7f) {
            targetVolume = 0x7f;
        }
    } else {
        targetVolume = gSceneSeqVolume;
    }
    if (gSceneSoundState.mRaceState != SCENE_RACE_STATE_RUNNING) {
        pitch = 0;
    } else if ((control->mFlags >> SEQ_PLAYER_BIT_THUNDER_SHRINK) & 1) {
        control->mPitchAngle += 0x1111;
        control->mPitchAngle &= 0xffff;
        pitch = FROM_FIXED12(MUL_FIXED12_ROUNDED(FX_SinIdx(control->mPitchAngle), 0x30000));
        pitch += 0x80;
        if (targetVolume > 0x3c) {
            targetVolume = 0x3c;
        }
    } else if ((control->mFlags >> SEQ_PLAYER_BIT_RESTARTED) & 1) {
        pitch = 0x40;
        if (targetVolume == gSceneSeqVolume) {
            targetVolume = gSceneSeqVolume - 10;
        }
    }
    StepSeqPlayerVolumeFade(handle, value, pitch, targetVolume);
    slotHandle = GetSndHandleSlot(5);
    if (slotSeqIndex != -1 && slotVolume != 0) {
        value = IsSndHandleSet(slotHandle);
        if (value != 0 && IsSndHandleSeq(slotHandle, 0, slotSeqIndex) == 0) {
            StopSndHandleSeq(slotHandle, 0);
            StartSeqOnHandleIfEnabled(slotSeqIndex & 0xff, slotHandle);
        } else if (value == 0) {
            StartSeqOnHandleIfEnabled(slotSeqIndex & 0xff, slotHandle);
        }
        if (IsSndHandleSet(slotHandle) == 0) {
            return;
        }
        if (slotVolume > 0x7f) {
            slotVolume = 0x7f;
        }
        SetSndHandleTrackVolume(slotHandle, slotVolume);
    } else {
        if (IsSndHandleSet(slotHandle) == 0) {
            return;
        }
        StopSndHandleSeq(slotHandle, 0x1e);
    }
}

SeqPlayerControl *ResetSeqPlayerControl(void) {
    SeqPlayerControl *control;
    u32 zero;
    control = &gSeqPlayerControl;
    zero = 0u;
    gSeqPlayerControl.mPitchAngle = zero;
    gSeqPlayerControl.mFlags = zero;
    gSeqPlayerControl.mKartNear = zero;
    gSeqPlayerControl.mVolumeOverride = SEQ_VOLUME_OVERRIDE_NONE;
    return control;
}

SeqPlayerControl *FadeSeqVolumeToZeroAfterKartRemoval(void) {
    SeqPlayerControl *control;
    u32 overrideValue;
    control = &gSeqPlayerControl;
    overrideValue = SEQ_VOLUME_OVERRIDE_ZERO;
    gSeqPlayerControl.mVolumeOverride = overrideValue;
    return control;
}

void StartKartRemovalSeqEffect(void) {
    NNSSndSeqPlayer **handle;
    handle = &gScenePlayers.mSeqPlayer;
    gSeqPlayerControl.mVolumeOverride = SEQ_VOLUME_OVERRIDE_FULL;
    NNS_SndPlayerSetTrackMuteEx(handle, 1, 1);
    NNS_SndPlayerSetTempoRatio(&gScenePlayers.mSeqPlayer, 0xd9);
}

void UpdateSceneSeqPlayerControl(void) {
    UpdateSeqPlayerControl(&gSeqPlayerControl, &gScenePlayers.mSeqPlayer);
}

u32 IsTeresaSoundFlagSet(void) {
    if ((gSeqPlayerControl.mFlags >> SEQ_PLAYER_BIT_TERESA) & 1) {
        return 1;
    }
    return 0;
}

u32 IsKartNear(void) {
    u32 kartNear;
    kartNear = gSeqPlayerControl.mKartNear;
    return kartNear;
}

// Sets the flag that makes UpdateSeqPlayerControl give the scene seq pitch 0x40 and a volume target of 10 less while
// mRaceState is 1.
SeqPlayerControl *SetRestartedSeqPitchFlag(void) {
    SeqPlayerControl *control;
    u32 flags;
    control = &gSeqPlayerControl;
    flags = gSeqPlayerControl.mFlags;
    flags = (flags) | (SEQ_PLAYER_FLAG_RESTARTED);
    gSeqPlayerControl.mFlags = flags;
    return control;
}

void SetThunderShrinkSoundFlag(u32 enabled) {
    if (enabled == 1) {
        gSeqPlayerControl.mFlags |= SEQ_PLAYER_FLAG_THUNDER_SHRINK;
    } else {
        gSeqPlayerControl.mFlags &= ~SEQ_PLAYER_FLAG_THUNDER_SHRINK;
    }
    gSeqPlayerControl.mPitchAngle = 0;
}

void SetTeresaSoundFlag(u32 enabled, u32 isSelectedEntry) {
    if (isSelectedEntry == 0) {
        return;
    }
    if (enabled == 1) {
        gSeqPlayerControl.mFlags |= SEQ_PLAYER_FLAG_TERESA;
    } else {
        gSeqPlayerControl.mFlags &= ~SEQ_PLAYER_FLAG_TERESA;
    }
}

void KartThunderShrinkNop(void) {}

u32 *ResetThunderShrinkSoundCounter(void) {
    gThunderShrinkSoundCounter = 0;
    return &gThunderShrinkSoundCounter;
}

void StartThunderShrinkSound(void *kartAddress, int secondArgument) {
    Kart *kart = kartAddress;
    u32 counter = gThunderShrinkSoundCounter;
    gThunderShrinkSoundCounter = counter + 1;
    StartSound(&kart->mSoundSource, counter + 0xea, SOUND_VOLUME_MAX, 0);
}

void RequestThunderShrinkSound(Kart *kart) {
    AddSoundRequest(&gSoundRequestQueues[4], GetKartCameraDistanceSquared(kart->mIndex),
                    StartThunderShrinkSound, kart, 0);
}

void InitSoundSetPlayerWithVariables(SoundSetPlayer *player, s32 seqId, s32 firstBankId) {
    u8 variableIndex;
    s32 enabledIndex;
    ReleaseLoadedSoundSet();
    if (seqId == 4) {
        firstBankId = 0x23;
    }
    InitSoundSetPlayer(player, seqId, firstBankId, SOUND_ID_NONE, GetLoadedSoundSet());
    for (variableIndex = 0; variableIndex < 2; variableIndex++) {
        gSeqVariableReadings[variableIndex].mValue = -1;
        gSeqVariableReadings[variableIndex].mPrevValue = -1;
        gSeqVariableReadings[variableIndex].mSinceChangeFrames = -1;
        gSeqVariableReadings[variableIndex].mVariableNo[0] = variableIndex;
    }
    gSeqVariableEnabled[0] = 1;
    for (enabledIndex = 0; enabledIndex < 2; enabledIndex++) {
        if (gSeqVariableEnabled[enabledIndex] == 1) {
            break;
        }
    }
    gSeqVariableEnabled[1] = 1;
    for (enabledIndex = 0; enabledIndex < 2; enabledIndex++) {
        if (gSeqVariableEnabled[enabledIndex] == 1) {
            gAnySeqVariableEnabled = 1;
            return;
        }
    }
    gAnySeqVariableEnabled = 0;
}

void SetSeqVariableEnabled(u32 slot, u32 enabled) {
    s32 variableIndex;
    gSeqVariableEnabled[slot] = enabled;
    for (variableIndex = 0; variableIndex < 2; variableIndex++) {
        if (gSeqVariableEnabled[variableIndex] == 1) {
            gAnySeqVariableEnabled = 1;
            return;
        }
    }
    gAnySeqVariableEnabled = 0;
}

u32 IsAnySeqVariableEnabled(void) {
    return gAnySeqVariableEnabled;
}

void ResetSeqVariableReadings(void) {
    u8 variableIndex;

    for (variableIndex = 0; variableIndex < 2; variableIndex++) {
        gSeqVariableReadings[variableIndex].mValue = -1;
        gSeqVariableReadings[variableIndex].mPrevValue = -1;
        gSeqVariableReadings[variableIndex].mSinceChangeFrames = -1;
        gSeqVariableReadings[variableIndex].mVariableNo[0] = variableIndex;
    }
}

// Reads each enabled slot's sequence variable and counts the updates since it last changed.
void UpdateSeqVariableReadings(NNSSndSeqPlayer **handle) {
    SeqVariableReading *reading;
    s32 variableIndex;

    for (variableIndex = 0; variableIndex < 2; variableIndex++) {
        reading = &gSeqVariableReadings[variableIndex];
        if (gSeqVariableEnabled[variableIndex] == 0) {
            continue;
        }
        if (NNS_SndPlayerReadVariable(handle, reading->mVariableNo[0], (s16 *) reading) == 0) {
            continue;
        }
        if (reading->mPrevValue != reading->mValue) {
            reading->mSinceChangeFrames = 0;
        } else {
            if (reading->mSinceChangeFrames >= 0) {
                reading->mSinceChangeFrames++;
            }
        }
        reading->mPrevValue = reading->mValue;
    }
}

u32 IsSeqVariableChanged(u32 slot) {
    return gSeqVariableReadings[slot].mSinceChangeFrames == 0;
}

u32 GetSeqVariableSinceChangeFrames(u32 slot) {
    return gSeqVariableReadings[slot].mSinceChangeFrames;
}
