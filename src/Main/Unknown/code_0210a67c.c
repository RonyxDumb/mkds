#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObjectSound
#include "Main/Unknown/code_020d3c94.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"

#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0210fad4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0210aa0c.h"
#include "Main/Unknown/code_0210aa14.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_0210f000.h"
#include "Main/Unknown/code_0210faac.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0210ab30.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0203c5ac.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_0211057c.h"
#include "Main/Unknown/code_02110590.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_0210b564.h"
#include "Main/Unknown/code_0210b610.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_0210b6a0.h"
#include "code_02147cd8.h"

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
    gSoundPitchSwing = (s32) (scaledSwing >> 12) >> 12;
}

void StartSurfaceSound(SoundSource *source, int entryIndex, u32 surfaceKind, u32 surfaceVariant, u32 waterDepth) {
    int surfaceSoundId;
    if ((source->mSourceFlags & 1) == 0) {
        return;
    }
    if (entryIndex == 2) {
        if ((0x00009c40u) < waterDepth) {
            StartSound(source, 0x70, 0x7f, 0);
            return;
        }
        if (waterDepth != 0) {
            StartSound(source, 0x6f, 0x7f, 0);
            return;
        }
    }
    surfaceSoundId = GetSurfaceSoundId(entryIndex, surfaceKind, surfaceVariant);
    if (surfaceSoundId != 0xffff) {
        StartSound(source, surfaceSoundId, 0x7f, 0);
        return;
    }
}

// Sound of the low-speed turn: the vehicle's row sound on every call, plus a surface sound when a direction key is
// held.
void StartKartLowSpeedTurnSound(Kart *kart, s32 withSurfaceSound, s32 surfaceKind, s32 surfaceVariant) {
    u32 soundId;

    switch (kart->mSound.mSoundRow.mSoundRowIndex) {
        case 0:
            soundId = 0xb2;
            break;
        case 1:
            soundId = 0xb9;
            break;
        case 2:
            soundId = 0xc0;
            break;
    }
    if (withSurfaceSound != 0) {
        StartSoundWhileRequested(&kart->mSoundSource, GetSurfaceSoundId(1, surfaceKind, surfaceVariant), 0x5f, -0x345);
    }
    StartSoundWhileRequested(&kart->mSoundSource, soundId, 0x7f, 0);
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

    if (!(kart->mSoundSource.mSourceFlags & 1)) {
        return;
    }
    if (kart->mUnk_4c & 0x10000000) {
        return;
    }
    soundState = &kart->mSound;
    pitch = soundState->mPitch >> 12;
    if (pitch > 0x1fc) {
        volume = 0x7f;
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
            depthPitch = (MUL_FIXED12_ROUNDED(gKartPitchPerWaterDepth, (s32) ((waterDepth - 0x61a8) << 12))) >> 12;
            if (isEntryKart != FALSE) {
                depthPitch += gSoundPitchSwing >> 1;
            }
        }
        StartSoundWhileRequested(&kart->mSoundSource, 0x74, volume & 0xff, (s16) (pitch - depthPitch));
    } else {
        soundId = GetSurfaceSoundId(entryIndex, surfaceKind, surfaceVariant);
        if (soundId == 0xffff) {
            return;
        }
        switch (soundId) {
            case 0xffd0:
            case 0xffd1:
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
                               0x7f, 0);
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

    if (!(kart->mSoundSource.mSourceFlags & 1)) {
        return;
    }
    soundId = GetSurfaceSoundIdShortRows(entryIndex, surfaceKind, surfaceVariant);
    if (soundId == 0xffff) {
        return;
    }
    if (gRaceSetup->mCourseId == COURSE_ID_RAINBOW) {
        soundId = 0x1b6;
    }
    StartSound(&kart->mSoundSource, soundId, 0x7f, 0);
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
    if (gSceneSoundState.mRaceFrames < 0x78) {
        return;
    }
    playingSound = StartSoundEx(&kart->mSoundSource, 0, soundId, 0x7f, 0);
    if (playingSound == NULL) {
        return;
    }
    playingSound->mFlags |= 0x20;
    playingSound->mFlags |= 0x40;
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
    if (!(kart->mSoundSource.mSourceFlags & 1)) {
        return;
    }
    soundState = &kart->mSound;
    if (kart->mUnk_4c & 0x10000000) {
        return;
    }
    if (kart->mUnk_7c & KART_7C_ENTRY_IS_GHOST) {
        return;
    }
    if (gSceneSoundState.mRaceState != 1) {
        if (gSceneSoundState.mRaceState != 0) {
            return;
        }
        volume = 0x7f;
        isEntryKart = kart->mIndex == gRaceSetup->mEntryIndex;
        if (soundOffset == 5) {
            volume = 0x7f;
        } else if (soundOffset == 3) {
            volume = 0x7f;
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
            StartSoundEx(&kart->mSoundSource, 2, soundIndex * 0xe + (soundOffset + 1), 0x73, 0);
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
        StartSoundEx(&kart->mSoundSource, 2, soundIndex * 0xe + soundOffset, 0x7f, 0);
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
    queue->mVolume = 0x5f;
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
        if (queue->mDelayFrames >= 0x19) {
            queue->mDelayFrames = -1;
        }
        return;
    }
    for (slotIndex = 0; slotIndex < 8; slotIndex++) {
        if (queue->mKarts[slotIndex] == NULL) {
            continue;
        }
        if (queue->mFramesSinceStart[slotIndex] == 0) {
            if (slotIndex != 0 && queue->mFramesSinceStart[slotIndex - 1] < 0x14) {
                continue;
            }
            if (slotIndex != 0 && queue->mFramesSinceStart[slotIndex - 1] == 0x14) {
                queue->mVolume -= 0xf;
            } else {
                queue->mVolume = 0x5f;
            }
            if (queue->mVolume < 0x1e) {
                queue->mVolume = 0x1e;
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
    enum { K0 } soundOffset;

    playingSound = kart->mSoundSource.mPlayingSounds.mHead;
    if (playingSound != NULL) {
        do {
            if (playingSound->mSeqArcNo == 2) {
                stoppedSound = playingSound;
                playingSound = NNS_FndGetNextListObject(&kart->mSoundSource.mPlayingSounds, playingSound);
                StopPlayingSound(&kart->mSoundSource, stoppedSound, 0);
            } else {
                playingSound = NNS_FndGetNextListObject(&kart->mSoundSource.mPlayingSounds, playingSound);
            }
        } while (playingSound != NULL);
    }
    modeAllowsSound = TRUE;
    if (gSoundModeHolder.mMode != 2 && gSoundModeHolder.mMode != 3) {
        modeAllowsSound = FALSE;
    }
    if (modeAllowsSound == FALSE) {
        return;
    }
    soundOffset = 0xd;
    if (useKartSource != 0) {
        StartSoundEx(&kart->mSoundSource, 2, soundIndex * 0xe + soundOffset, 0x7f, 0);
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
    if ((playingSound->mFlags & 0x20) && (playingSound->mFlags & 0x40)) {
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

u32 GetZeroSoundDistanceChange(void) {
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
    if (playingSound->mSeqArcNo != 2) {
        waterDepth = kart->mWaterDepth;
        depthPitch = 0;
        isEntryKart = kart->mIndex == gRaceSetup->mEntryIndex;
        if (waterDepth > 0x11170) {
            depthPitch = 0x384;
            if (isEntryKart != FALSE) {
                depthPitch += gSoundPitchSwing;
            }
        } else if (waterDepth > 0x61a8 && waterDepth <= 0x11170) {
            depthPitch = (MUL_FIXED12_ROUNDED(gKartPitchPerWaterDepth, (s32) ((waterDepth - 0x61a8) << 12))) >> 12;
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
    if (kartArg->mUnk_44 == 0) {
        vector = (Vec3 *) &kartArg->mUnk_168.y;
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
            depthPitch = (MUL_FIXED12_ROUNDED(gKouraPitchPerWaterDepth, (s32) ((depth - 0x61a8) << 12))) >> 12;
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
    if (!(flags & 0x10) && gSceneSoundState.mRaceFrames > kart->mSound.mThunderShrinkRaceFrame + 1) {
        pitchOffset = 0x180;
        if (flags & 0x80) {
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
