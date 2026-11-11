#include "Main/Unknown/code_02066ac0.h"
#include "Main/Unknown/code_020435c4.h"

#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_02075000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_020172d0.h"
#include "code_0212df7c.h"
#include "code_02147288.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02081120.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_0203c5f8.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"
#include "code_02147cd8.h"

s32 CollideKartWithMapObjectResponse13(Kart *kart, s32 *output) {
    *output = 0xc;
    kart->mDriveFlags &= ~(KART_DRIVE_BOOST | KART_DRIVE_RACE_START_BOOST | KART_DRIVE_MINI_TURBO |
                           KART_DRIVE_KINOKO_BOOST | KART_DRIVE_ITEM_BOOST);
    kart->mBoostTimer = 0;
    kart->mItemEffectData.mKinokoBoostTimer = 0;
    kart->mMiniTurboTimer = 0;
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        if ((kart->mEffectFlags & KART_EFFECT_KILLER) == 0 &&
            (kart->mDriveFlags & KART_DRIVE_SCALE_TABLE_EFFECT) == 0) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
    }
    kart->mForwardSpeed = 0;
    return 5;
}

s32 CollideKartWithMapObjectResponse14(Kart *kart, s32 *output) {
    *output = 0xc;
    kart->mDriveFlags &= ~(KART_DRIVE_BOOST | KART_DRIVE_RACE_START_BOOST | KART_DRIVE_MINI_TURBO |
                           KART_DRIVE_KINOKO_BOOST | KART_DRIVE_ITEM_BOOST);
    kart->mBoostTimer = 0;
    kart->mItemEffectData.mKinokoBoostTimer = 0;
    kart->mMiniTurboTimer = 0;
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        if ((kart->mEffectFlags & KART_EFFECT_KILLER) == 0 &&
            (kart->mDriveFlags & KART_DRIVE_SCALE_TABLE_EFFECT) == 0) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
    }
    if (TrySpinKart(kart, 1, 0) != FALSE) {
        StartKartSpinFollowEffect(kart->mIndex);
    }
    return 5;
}

s32 CollideKartWithMapObjectResponse11(Kart *kart, s32 *output, s32 mapObject) {
    if (TryStartKartScaleTableEffect(kart) != FALSE && kart->mScaleEffectMapObject != (struct MapObject *) mapObject &&
        (kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        GetEntryKartCounters()->mMapObjectHitCount++;
    }
    *output = 0;
    return 0;
}

s32 ApplyKartSurfaceStopEffects(Kart *kart) {
    ApplyKartSurfaceEffect((u16) gKartSurfaceStopEffects[kart->mSurfaceVariant], kart);
    return 0;
}

s32 ApplyKartSurfaceKind20(Kart *kart) {
    ApplyKartSurfaceEffect((u16) gKartSurfaceKind20Effects[kart->mSurfaceVariant], kart);
    return 0;
}

s32 ApplyKartSurfaceKind1(Kart *kart) {
    ApplyKartSurfaceEffect((u16) gKartSurfaceKind1Effects[kart->mSurfaceVariant], kart);
    return 5;
}

s32 ApplyKartSurfaceKind2(Kart *kart) {
    IncrementEntryKartSurfaceCount(kart);
    ApplyKartSurfaceEffect((u16) gKartSurfaceKind2Effects[kart->mSurfaceVariant], kart);
    return 2;
}

s32 ApplyKartSurfaceKind3(Kart *kart) {
    IncrementEntryKartSurfaceCount(kart);
    ApplyKartSurfaceEffect((u16) gKartSurfaceKind3Effects[kart->mSurfaceVariant], kart);
    return 3;
}

s32 ApplyKartSurfaceKind5(Kart *kart) {
    IncrementEntryKartSurfaceCount(kart);
    ApplyKartSurfaceEffect((u16) gKartSurfaceKind5Effects[kart->mSurfaceVariant], kart);
    return 4;
}

s32 ApplyKartSurfaceKind6(Kart *kart) {
    ApplyKartSurfaceEffect((u16) gKartSurfaceKind6Effects[kart->mSurfaceVariant], kart);
    return 6;
}

s32 ApplyKartSurfaceKind7(Kart *kart) {
    KartSurfaceSoundIds soundIds;
    PlayingSound *sound;

    if (kart->mSurfaceGroup != 8 || (kart->mMotionFlags & KART_MOTION_STATE_RESET) != 0) {
        StartKartBoost(kart, KART_BOOST_ITEM_OR_SURFACE, 0x3c);
        soundIds = gKartSurfaceSoundIds;
        if (kart->mSurfaceVariant > 0 && (kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
            sound = StartSound(&kart->mSoundSource, soundIds.mSoundIds[kart->mSurfaceVariant - 1], 0x7f, 0);
            if (sound != NULL) {
                sound->mFlags = sound->mFlags | 0x10;
            }
        }
    } else {
        kart->mBoostTimer = 0x3c;
    }
    StopKartCurrentEffects(kart);
    return 8;
}

s32 ApplyKartSurfaceKind12(Kart *kart) {
    if (kart->mSurfaceGroup != 8 || (kart->mMotionFlags & KART_MOTION_STATE_RESET) != 0) {
        if (gRaceSetup->mCourseId == COURSE_ID_OLD_KOOPA_AGB || gRaceSetup->mCourseId == COURSE_ID_OLD_SKY_AGB) {
            StartSound(&kart->mSoundSource, 0x15e, 0x7f, 0);
        }
    }
    kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_JUMP_PAD;
    kart->mVerticalSpeed = gKartSurfaceKind12VerticalSpeeds[kart->mSurfaceVariant];
    kart->mSurfaceSpeedLimitGoal = data_0216559c[kart->mSurfaceVariant];
    StopKartCurrentEffects(kart);
    return 8;
}

s32 ApplyKartSurfaceKind18(Kart *kart) {
    KartSurfaceSoundIds soundIds;
    PlayingSound *sound;

    if (kart->mSurfaceGroup != 8 || (kart->mMotionFlags & KART_MOTION_STATE_RESET) != 0) {
        StartKartBoost(kart, KART_BOOST_ITEM_OR_SURFACE, 0x3c);
        soundIds = gKartSurfaceSoundIds;
        if (kart->mSurfaceVariant > 0 && (kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
            sound = StartSound(&kart->mSoundSource, soundIds.mSoundIds[kart->mSurfaceVariant - 1], 0x7f, 0);
            if (sound != NULL) {
                sound->mFlags = sound->mFlags | 0x10;
            }
        }
    } else {
        kart->mBoostTimer = 0x3c;
    }
    StopKartCurrentEffects(kart);
    kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_BOOST_SPEED_FLOOR;
    return 8;
}

s32 ApplyKartSurfaceKind15(Kart *kart) {
    u16 surfaceVariant;

    ApplyKartSurfaceEffect(0, kart);
    if ((kart->mDriveFlags & KART_DRIVE_KEYED_PLACEMENT) == 0) {
        surfaceVariant = kart->mSurfaceVariant;
        if (gRaceSetup->mMode == MODE_BATTLE || gRaceSetup->mMode == MODE_MISSION_RUN) {
            PlaceKartAtKeyedPlacement(kart, surfaceVariant);
        } else {
            kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_KEYED_PLACEMENT;
            ResetKartMotionState(kart, 0);
        }
    }
    return 9;
}

s32 ApplyKartSurfaceKind17(Kart *kart) {
    ApplyKartSurfaceEffect((u16) gKartSurfaceKind17Effects[kart->mSurfaceVariant], kart);
    return 0xa;
}

s32 ApplyKartSurfaceKind19(Kart *kart) {
    PlayingSound *sound;

    if (kart->mSurfaceGroup != 0xb || (kart->mMotionFlags & KART_MOTION_STATE_RESET) != 0) {
        StartKartBoost(kart, KART_BOOST_ITEM_OR_SURFACE, 0x3c);
        if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
            sound = StartSound(&kart->mSoundSource, 0x1b9, 0x7f, 0);
            if (sound != NULL) {
                sound->mFlags = sound->mFlags | 0x10;
            }
        }
    } else {
        kart->mBoostTimer = 0x3c;
    }
    kart->mDriveFlags = kart->mDriveFlags | (KART_DRIVE_ON_BOOST_SURFACE | KART_DRIVE_BOOST_SURFACE_HELD);
    StopKartCurrentEffects(kart);
    return 0xb;
}

s32 ApplyKartSurfaceKind10(Kart *kart) {
    ApplyKartSurfaceEffect((u16) gKartSurfaceKind10Effects[kart->mSurfaceVariant], kart);
    return 0;
}

u32 IsKartTurnEffectsActive(Kart *kart) {
    KartTurnEffects *turnEffects;
    u32 level4Present;

    turnEffects = GetKartTurnEffects(kart->mIndex);
    if (turnEffects->mLevel4StopRequested != FALSE) {
        level4Present = 0;
    } else {
        level4Present = turnEffects->mLevel4Present;
    }
    return (turnEffects->mLevel3Present | (turnEffects->mTurnStartPresent | level4Present)) != 0 ? 1 : 0;
}

void AdvanceKartAi(Kart *kart) {
    Vec3 offset;
    Kart *entryKart;
    u32 kartBits;

    kartBits = kart->mEntryFlags;
    if ((kartBits & KART_ENTRY_CPU) == 0) {
        return;
    }
    if ((kartBits & KART_ENTRY_DID_NOT_FINISH) != 0) {
        return;
    }
    if (IsRaceStarted() != 1) {
        return;
    }
    if (gCourseMap->mRaceRouteCount == 0 && gCourseMap->mBattleRouteCount == 0) {
        return;
    }
    CallKartAiAdvance(kart->mAi);
    if (kart->mIndex != GetRaceUpdateFramesMod8()) {
        return;
    }
    if (gRaceSetup->mMode != MODE_GRAND_PRIX) {
        return;
    }
    entryKart = GetKart(gRaceSetup->mEntryIndex);
    VEC_Subtract(&kart->mPos, &entryKart->mPos, &offset);
    offset.x = FROM_FIXED12(offset.x);
    offset.y = FROM_FIXED12(offset.y);
    offset.z = FROM_FIXED12(offset.z);
    if (offset.x * offset.x + offset.y * offset.y + offset.z * offset.z > 0x271000) {
        kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_FAR_FROM_ENTRY;
    } else {
        kart->mDriveFlags = kart->mDriveFlags & ~KART_DRIVE_FAR_FROM_ENTRY;
    }
}

void StartKartRaceEnd(Kart *kart) {
    RaceSetup *raceSetup;
    CourseMap *courseMap;
    KartEntryPlayer *player;
    u32 value;
    s32 soundOffset;
    u16 index;
    s32 framesSinceEntryEnd;
    KartItemEffectState *effectState;
    u32 flag;

    if ((kart->mEntryFlags & KART_ENTRY_RACE_END_STARTED) != 0) {
        return;
    }
    kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_RACE_END_STARTED;
    if ((kart->mEntryFlags & KART_ENTRY_WIFI_PEER) == 0) {
        courseMap = gCourseMap;
        if ((courseMap->mRaceRouteCount != 0 || courseMap->mBattleRouteCount != 0) && IsKartEnded(kart->mIndex) != 0) {
            raceSetup = gRaceSetup;
            index = kart->mIndex;
            player = &raceSetup->mCurrentEntries[index].mPlayer;
            value = 0;
            if (player->mKind <= 3 && ((1 << player->mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                value = 1;
            }
            if (value != 0) {
                value = kart->mEntryFlags;
                if ((value & (KART_ENTRY_CPU | KART_ENTRY_GHOST)) == 0 && (value & KART_ENTRY_ENDED) == 0) {
                    gInputSlots[kart->mEntryIndex].mSourceKind = 3;
                    if (gRaceProgress->mKarts[kart->mIndex].mStatus == RACE_PROGRESS_KART_STATUS_GOAL_REACHED) {
                        CallKartAiSetup(kart->mAi, kart->mIndex);
                        kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_CPU;
                        if ((kart->mEntryFlags & KART_ENTRY_CPU) != 0) {
                            for (index = 0; index < 12; index++) {
                                if (index != 0) {
                                    kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[index] =
                                        kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[index] << 2;
                                    if (kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[index] >
                                        kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[0]) {
                                        kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[index] =
                                            kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[0];
                                    }
                                }
                            }
                        }
                    } else {
                        kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_ENDED;
                    }
                }
            } else if (raceSetup->mRuleKind == 1 &&
                       gRaceProgress->mKarts[kart->mIndex].mStatus != RACE_PROGRESS_KART_STATUS_GOAL_REACHED) {
                kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_DID_NOT_FINISH;
            } else if (raceSetup->mMode == MODE_MISSION_RUN) {
                kart->mEntryFlags = kart->mEntryFlags | KART_ENTRY_DID_NOT_FINISH;
                kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_SLOWING_STOP;
            }
            if ((kart->mEntryFlags & KART_ENTRY_GHOST) != 0) {
                StartKartRemoval(kart, 0);
            }
        }
    }
    StartKartWinOrLoseAnimation(kart);
    StopOrthoQuads(kart->mIndex);
    ReleaseKartStarEffects(kart->mIndex);
    if ((kart->mEffectFlags & KART_EFFECT_STAR) != 0) {
        kart->mEffectFlags = kart->mEffectFlags & ~KART_EFFECT_STAR;
        StopKartStarModels(kart);
        kart->mItemEffect = 0;
        StopKartStarEffects(kart->mIndex);
        SetKartCharacterAnimation(kart, 0, 1);
        if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0 && gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
            StopKartStarSeq();
        }
        if ((kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) != 0) {
            SetKartModelsGrayColors(kart);
        }
    }
    effectState = &kart->mItemEffectData;
    if ((kart->mEffectFlags & KART_EFFECT_KILLER) != 0 && effectState->mKillerEnding == FALSE) {
        effectState->mKillerEnding = TRUE;
        if ((kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) != 0) {
            kart->mParticipantRecordData->mEventToggleFlags ^= 0x200000;
        }
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) != 0) {
        SetRaceUpdateFramesAtEntryEnd();
        raceSetup = gRaceSetup;
        if (raceSetup->mMode != MODE_GRAND_PRIX && raceSetup->mMode != MODE_TIME_ATTACK &&
            ((raceSetup->mRuleKind == 1 &&
              gRaceProgress->mKarts[kart->mIndex].mStatus != RACE_PROGRESS_KART_STATUS_GOAL_REACHED) ||
             ((index = raceSetup->mKartCount) > 1 && (value = GetKartRank(kart->mIndex), value == index)))) {
            DisableEntryCameraUpdate();
        } else {
            StartEntryCameraKind6Entry();
            SwitchCourseCameraEffectsToCurrentCamera();
        }
    } else if (gRaceSetup->mMode == MODE_VS || gRaceSetup->mMode == MODE_WIFI) {
        if (gRaceProgress->mKarts[kart->mIndex].mStatus == RACE_PROGRESS_KART_STATUS_GOAL_REACHED) {
            framesSinceEntryEnd = 0;
            if (TryGetRaceUpdateFramesSinceEntryEnd((u32 *) &framesSinceEntryEnd) != 0 &&
                (u32) framesSinceEntryEnd > 0xb4) {
                NNS_SndArcPlayerStartSeqArc(&gSharedSeqHandle, 0, 0x45);
            }
        }
    }
    raceSetup = gRaceSetup;
    if (raceSetup->mMode == MODE_BATTLE) {
        return;
    }
    flag = 1;
    if (gSoundModeHolder.mMode != 2 && gSoundModeHolder.mMode != 3) {
        flag = 0;
    }
    if (flag == 0) {
        return;
    }
    if (kart->mIndex == raceSetup->mEntryIndex) {
        value = GetRaceEndResultKind();
        switch (value) {
            case 0:
                soundOffset = 9;
                break;
            case 1:
                soundOffset = 0xa;
                break;
            case 2:
                soundOffset = 0xb;
                break;
        }
        StartKartSeqArcSoundWithVolume(kart->mSoundIndex, soundOffset, 0x6e, 7, -1);
        return;
    }
    soundOffset = GetKartSeqArcSoundOffsetByRank(GetKartRank(kart->mIndex));
    if ((kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT)) != 0) {
        return;
    }
    StartKartSeqArcSound(kart, kart->mSoundIndex, soundOffset);
}

void AdvanceKartWobble(Kart *kart) {
    MtxFx43 rotationMatrix;
    s32 angleAmplitude;
    s32 angleValue;
    u16 angle;
    s32 amplitudeDelta;

    kart->mWobbleAngle = kart->mWobbleAngle + gKartWobbleAnglePerCall;
    kart->mWobbleSine = FX_SinIdx(kart->mWobbleAngle);
    if (kart->mWobbleAmplitude > 0) {
        kart->mWobbleAmplitude = MUL_FIXED12_ROUNDED(kart->mWobbleAmplitude, gKartWobbleAmplitudeDecay);
        kart->mWobbleAmplitude = kart->mWobbleAmplitude - 0x64;
        if ((kart->mMotionFlags & KART_MOTION_ON_GROUND) == 0 ||
            (kart->mForwardSpeed > 0 ? kart->mForwardSpeed : -kart->mForwardSpeed) < 0x3000) {
            kart->mWobbleAmplitude = MUL_FIXED12_ROUNDED(kart->mWobbleAmplitude, 0xe66);
        }
        if (kart->mWobbleAmplitude < 0) {
            kart->mWobbleAmplitude = 0;
        }
    }
    amplitudeDelta = kart->mWobbleDirection * kart->mWobbleAmplitude - kart->mWobbleEasedAmplitude;
    kart->mWobbleEasedAmplitude =
        kart->mWobbleEasedAmplitude + MUL_FIXED12_ROUNDED(amplitudeDelta, gKartWobbleEaseFactor);
    angleAmplitude = MUL_FIXED12_ROUNDED(kart->mWobbleEasedAmplitude, gKartWobbleAngleFactor);
    angleValue = MUL_FIXED12_ROUNDED(angleAmplitude, kart->mWobbleSine);
    angle = angleValue;
    MTX_RotY43_(&rotationMatrix, FX_SinIdx(angle), FX_CosIdx(angle));
    MTX_Concat43(&rotationMatrix, &kart->mUnk_150_m, &kart->mWobbleMatrix);
    if ((kart->mWobbleEasedAmplitude > 0 ? kart->mWobbleEasedAmplitude : -kart->mWobbleEasedAmplitude) >= 0x29) {
        return;
    }
    kart->mEffectFlags = kart->mEffectFlags & ~KART_EFFECT_WOBBLE;
    kart->mWobbleAngle = 0;
    kart->mWobbleSine = 0;
    kart->mWobbleAmplitude = 0;
    kart->mWobbleDirection = 0;
}

// Applies the newest record of a peer kart, or queues it for its frame, and turns its bits into key requests.
void AdvanceParticipantKartRecords(Kart *kart) {
    ParticipantKartRecordState *state;
    ParticipantKartRecordNode *node;
    ParticipantKartRecordState *stateAgain;
    WiFiRaceSyncEntry *entry;
    ParticipantKartRecord *record;
    s32 difference;
    s32 appliedNow;
    s16 negatedDifference;
    u32 participantSyncFrames;
    ParticipantKartRecordNode *pendingNode;
    ParticipantKartRecordNode *nextNode;

    state = kart->mParticipantRecordData;
    appliedNow = 0;
    participantSyncFrames = GetParticipantSyncFrames(((u8 *) gParticipantKartMap)[kart->mIndex & 0xff]);
    state->mPosBlendFactor = IsRaceStarted() == 1 ? 0x333 : appliedNow;
    if (participantSyncFrames > state->mLastSyncCount) {
        entry =
            GetParticipantEntryAtSyncFrames(((u8 *) gParticipantKartMap)[kart->mIndex & 0xff], participantSyncFrames);
        record = entry != NULL ? &entry->mKartRecord : 0;
        if (record != NULL) {
            difference = gWiFiRaceSync->mSyncFrames - participantSyncFrames;
            if (difference < 0) {
                negatedDifference = -difference;
                node = NNS_FndGetNthListObject(&state->mFreeRecords, 0);
                if (node != NULL) {
                    NNS_FndRemoveListObject(&state->mFreeRecords, node);
                    node->mRecord = *record;
                    node->mApplyTimer = negatedDifference + 1;
                    NNS_FndAppendListObject(&state->mPendingRecords, node);
                }
                stateAgain = kart->mParticipantRecordData;
                stateAgain->mEasedTurnAngle =
                    stateAgain->mEasedTurnAngle +
                    MUL_FIXED12_ROUNDED(stateAgain->mTargetTurnAngle - stateAgain->mEasedTurnAngle, 0x333);
                kart->mTurnAngle = stateAgain->mEasedTurnAngle;
            } else {
                if (difference > 0x19) {
                    difference = 0x19;
                }
                ApplyParticipantKartRecord(kart, record, difference);
                appliedNow = 1;
            }
        }
        state->mLastSyncCount = participantSyncFrames;
    } else {
        stateAgain = kart->mParticipantRecordData;
        stateAgain->mEasedTurnAngle =
            stateAgain->mEasedTurnAngle +
            MUL_FIXED12_ROUNDED(stateAgain->mTargetTurnAngle - stateAgain->mEasedTurnAngle, 0x333);
        kart->mTurnAngle = stateAgain->mEasedTurnAngle;
    }
    stateAgain = kart->mParticipantRecordData;
    pendingNode = NNS_FndGetNextListObject(&stateAgain->mPendingRecords, NULL);
    while (pendingNode != NULL) {
        nextNode = NNS_FndGetNextListObject(&stateAgain->mPendingRecords, pendingNode);
        pendingNode->mApplyTimer = pendingNode->mApplyTimer - 1;
        if (pendingNode->mApplyTimer <= 0) {
            if (appliedNow == 0) {
                ApplyParticipantKartRecord(kart, &pendingNode->mRecord, 0);
            }
            NNS_FndRemoveListObject(&stateAgain->mPendingRecords, pendingNode);
            NNS_FndAppendListObject(&stateAgain->mFreeRecords, pendingNode);
            if (nextNode == NULL) {
                break;
            }
            pendingNode = nextNode;
        }
        pendingNode = NNS_FndGetNextListObject(&stateAgain->mPendingRecords, pendingNode);
    }
    if ((kart->mParticipantRecordData->mRecordBits & 2) != 0) {
        RequestBits(kart->mEntryIndex, PAD_KEY_A);
    }
    if ((kart->mParticipantRecordData->mRecordBits & 4) != 0) {
        RequestBits(kart->mEntryIndex, PAD_KEY_B);
    }
    if ((kart->mParticipantRecordData->mRecordBits & 8) != 0) {
        RequestBits(kart->mEntryIndex, PAD_KEY_LEFT);
    }
    if ((kart->mParticipantRecordData->mRecordBits & 0x10) != 0) {
        RequestBits(kart->mEntryIndex, PAD_KEY_RIGHT);
    }
    if ((kart->mParticipantRecordData->mRecordBits & 1) != 0) {
        kart->mMotionFlags = kart->mMotionFlags | KART_MOTION_ON_GROUND;
    }
    if ((kart->mParticipantRecordData->mRecordBits & 0x20) != 0) {
        kart->mBoostTimer = 3;
        kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_BOOST;
    } else {
        kart->mBoostTimer = 0;
        kart->mDriveFlags = kart->mDriveFlags & ~KART_DRIVE_BOOST;
    }
}
