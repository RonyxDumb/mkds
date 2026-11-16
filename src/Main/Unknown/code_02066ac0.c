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
#include "Main/Kart/KartAiCallbacks.h"
#include "Main/Kart/KartTurnEffects.h"
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
#include "Main/Kart/KartTimes.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_02077bc0.h"
#include "code_021471bc.h"

s32 driver_initReaction13(Kart *kart, s32 *output) {
    *output = 0xc;
    kart->field48 &= 0xdfe77fdf;
    kart->mBoostTimer = 0;
    kart->field538.field0 = 0;
    kart->mMiniTurboTimer = 0;
    if ((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        if ((kart->field4C & 0x10000000) == 0 && (kart->field48 & 0x4000000) == 0) {
            cam_resetPlayerCameraTargetFov();
        }
        dce_stopBlur();
    }
    kart->mForwardSpeed = 0;
    return 5;
}

s32 driver_initSingleSpinElectricityReaction(Kart *kart, s32 *output) {
    *output = 0xc;
    kart->field48 &= 0xdfe77fdf;
    kart->mBoostTimer = 0;
    kart->field538.field0 = 0;
    kart->mMiniTurboTimer = 0;
    if ((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        if ((kart->field4C & 0x10000000) == 0 && (kart->field48 & 0x4000000) == 0) {
            cam_resetPlayerCameraTargetFov();
        }
        dce_stopBlur();
    }
    if (driver_tryStartSpinOut(kart, 1, 0) != FALSE) {
        rptc_startElectricEffect(kart->mIndex);
    }
    return 5;
}

s32 driver_initDossunSmashReaction(Kart *kart, s32 *output, s32 mapObject) {
    if (driver_startDossunFlatEffect(kart) != FALSE && kart->field44C != (struct MapObject *) mapObject &&
        (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        driver_getPlayerStatistics()->field14++;
    }
    *output = 0;
    return 0;
}

s32 driver_handleDefaultFloorCollision(Kart *kart) {
    rptc_collisionParticleRender((u16) data_02154a84[kart->mSurfaceVariant], kart);
    return 0;
}

s32 driver_handleStickyCollision(Kart *kart) {
    rptc_collisionParticleRender((u16) gKartSurfaceKind20Effects[kart->mSurfaceVariant], kart);
    return 0;
}

s32 driver_handleSlippery1Collision(Kart *kart) {
    rptc_collisionParticleRender((u16) gKartSurfaceKind1Effects[kart->mSurfaceVariant], kart);
    return 5;
}

s32 driver_handleWeakOffRoadCollision(Kart *kart) {
    driver_notifyOffRoad(kart);
    rptc_collisionParticleRender((u16) gKartSurfaceKind2Effects[kart->mSurfaceVariant], kart);
    return 2;
}

s32 driver_handleOffRoadCollision(Kart *kart) {
    driver_notifyOffRoad(kart);
    rptc_collisionParticleRender((u16) gKartSurfaceKind3Effects[kart->mSurfaceVariant], kart);
    return 3;
}

s32 driver_handleHeavyOffRoadCollision(Kart *kart) {
    driver_notifyOffRoad(kart);
    rptc_collisionParticleRender((u16) gKartSurfaceKind5Effects[kart->mSurfaceVariant], kart);
    return 4;
}

s32 driver_handleSlippery2Collision(Kart *kart) {
    rptc_collisionParticleRender((u16) gKartSurfaceKind6Effects[kart->mSurfaceVariant], kart);
    return 6;
}

s32 driver_handleBoostPadCollision(Kart *kart) {
    KartSurfaceSoundIds soundIds;
    PlayingSound *sound;

    if (kart->mSurfaceGroup != 8 || (kart->field44 & 0x80000000) != 0) {
        driver_addBoost(kart, KART_BOOST_ITEM_OR_SURFACE, 0x3c);
        soundIds = gKartSurfaceSoundIds;
        if (kart->mSurfaceVariant > 0 && (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
            sound = sfx_21090C4(&kart->mSoundSource, soundIds.mSoundIds[kart->mSurfaceVariant - 1], 0x7f, 0);
            if (sound != NULL) {
                sound->mFlags = sound->mFlags | 0x10;
            }
        }
    } else {
        kart->mBoostTimer = 0x3c;
    }
    rptc_killDriverEffects_copy(kart);
    return 8;
}

s32 driver_handleJumpPadCollision(Kart *kart) {
    if (kart->mSurfaceGroup != 8 || (kart->field44 & 0x80000000) != 0) {
        if (gRaceMultiConfig->mCourseId == COURSE_ID_OLD_KOOPA_AGB || gRaceMultiConfig->mCourseId == COURSE_ID_OLD_SKY_AGB) {
            sfx_21090C4(&kart->mSoundSource, 0x15e, 0x7f, 0);
        }
    }
    kart->field48 = kart->field48 | 0x10000000;
    kart->mVerticalSpeed = gKartSurfaceKind12VerticalSpeeds[kart->mSurfaceVariant];
    kart->field4C4 = data_0216559c[kart->mSurfaceVariant];
    rptc_killDriverEffects_copy(kart);
    return 8;
}

s32 driver_handleBoostPad2Collision(Kart *kart) {
    KartSurfaceSoundIds soundIds;
    PlayingSound *sound;

    if (kart->mSurfaceGroup != 8 || (kart->field44 & 0x80000000) != 0) {
        driver_addBoost(kart, KART_BOOST_ITEM_OR_SURFACE, 0x3c);
        soundIds = gKartSurfaceSoundIds;
        if (kart->mSurfaceVariant > 0 && (kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
            sound = sfx_21090C4(&kart->mSoundSource, soundIds.mSoundIds[kart->mSurfaceVariant - 1], 0x7f, 0);
            if (sound != NULL) {
                sound->mFlags = sound->mFlags | 0x10;
            }
        }
    } else {
        kart->mBoostTimer = 0x3c;
    }
    rptc_killDriverEffects_copy(kart);
    kart->field48 = kart->field48 | 0x400000;
    return 8;
}

s32 driver_handleCannonCollision(Kart *kart) {
    u16 surfaceVariant;

    rptc_collisionParticleRender(0, kart);
    if ((kart->field48 & 0x10000) == 0) {
        surfaceVariant = kart->mSurfaceVariant;
        if (gRaceMultiConfig->mMode == MODE_BATTLE || gRaceMultiConfig->mMode == MODE_MISSION_RUN) {
            driver_pipeTeleport(kart, surfaceVariant);
        } else {
            kart->field48 = kart->field48 | 0x10000;
            driver_cannonLaunch(kart, 0);
        }
    }
    return 9;
}

s32 driver_handleFallsWaterCollision(Kart *kart) {
    rptc_collisionParticleRender((u16) gKartSurfaceKind17Effects[kart->mSurfaceVariant], kart);
    return 0xa;
}

s32 driver_handleLoopingCollision(Kart *kart) {
    PlayingSound *sound;

    if (kart->mSurfaceGroup != 0xb || (kart->field44 & 0x80000000) != 0) {
        driver_addBoost(kart, KART_BOOST_ITEM_OR_SURFACE, 0x3c);
        if ((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
            sound = sfx_21090C4(&kart->mSoundSource, 0x1b9, 0x7f, 0);
            if (sound != NULL) {
                sound->mFlags = sound->mFlags | 0x10;
            }
        }
    } else {
        kart->mBoostTimer = 0x3c;
    }
    kart->field48 = kart->field48 | 0x40000001;
    rptc_killDriverEffects_copy(kart);
    return 0xb;
}

s32 driver_handleOobCollision(Kart *kart) {
    rptc_collisionParticleRender((u16) gKartSurfaceKind10Effects[kart->mSurfaceVariant], kart);
    return 0;
}

u32 IsKartTurnEffectsActive(Kart *kart) {
    KartTurnEffects *turnEffects;
    u32 level4Present;

    turnEffects = dptc_getControllerForDriver(kart->mIndex);
    if (turnEffects->mLevel4StopRequested != FALSE) {
        level4Present = 0;
    } else {
        level4Present = turnEffects->mLevel4Present;
    }
    return (turnEffects->mLevel3Present | (turnEffects->mTurnStartPresent | level4Present)) != 0 ? 1 : 0;
}

void driver_updateEnemy(Kart *kart) {
    Vec3 offset;
    Kart *entryKart;
    u32 kartBits;

    kartBits = kart->field7C;
    if ((kartBits & 2) == 0) {
        return;
    }
    if ((kartBits & 0x200000) != 0) {
        return;
    }
    if (race_getState() != 1) {
        return;
    }
    if (gMapData->mRaceRouteCount == 0 && gMapData->mBattleRouteCount == 0) {
        return;
    }
    enmy_update(kart->mAi);
    if (kart->mIndex != race_getFrameCounterModulo8()) {
        return;
    }
    if (gRaceMultiConfig->mMode != MODE_GRAND_PRIX) {
        return;
    }
    entryKart = driver_getById(gRaceMultiConfig->mEntryIndex);
    VEC_Subtract(&kart->mPos, &entryKart->mPos, &offset);
    offset.x = offset.x >> 12;
    offset.y = offset.y >> 12;
    offset.z = offset.z >> 12;
    if (offset.x * offset.x + offset.y * offset.y + offset.z * offset.z > 0x271000) {
        kart->field48 = kart->field48 | 0x8000000;
    } else {
        kart->field48 = kart->field48 & ~0x8000000;
    }
}

void func_02066fe0(Kart *kart) {
    RaceSetup *raceSetup;
    CourseMap *courseMap;
    KartEntryPlayer *player;
    u32 c;
    s32 d;
    u16 i;
    s32 framesSinceEntryEnd;
    KartItemEffectState *effectState;
    u32 g;

    if ((kart->field7C & 0x1000) != 0) {
        return;
    }
    kart->field7C = kart->field7C | 0x1000;
    if ((kart->field7C & 0x400) == 0) {
        courseMap = gMapData;
        if ((courseMap->mRaceRouteCount != 0 || courseMap->mBattleRouteCount != 0) && rstat_hasDriverFinished(kart->mIndex) != 0) {
            raceSetup = gRaceMultiConfig;
            i = kart->mIndex;
            player = &raceSetup->mCurrentEntries[i].mPlayer;
            c = 0;
            if (player->mKind <= 3 && ((1 << player->mKind) & PLAYER_KIND_MASK_HUMAN_GHOST_PEER) != 0) {
                c = 1;
            }
            if (c != 0) {
                c = kart->field7C;
                if ((c & 6) == 0 && (c & 8) == 0) {
                    data_02175664[kart->mEntryIndex].mSourceKind = 3;
                    if (gRaceStatus->field0[kart->mIndex].mStatus == 1) {
                        enmy_init(kart->mAi, kart->mIndex);
                        kart->field7C = kart->field7C | 2;
                        if ((kart->field7C & 2) != 0) {
                            for (i = 0; i < 12; i++) {
                                if (i != 0) {
                                    kart->mPhysicalParam->field38[i] = kart->mPhysicalParam->field38[i] << 2;
                                    if (kart->mPhysicalParam->field38[i] > kart->mPhysicalParam->field38[0]) {
                                        kart->mPhysicalParam->field38[i] = kart->mPhysicalParam->field38[0];
                                    }
                                }
                            }
                        }
                    } else {
                        kart->field7C = kart->field7C | 8;
                    }
                }
            } else if (raceSetup->mRuleKind == 1 && gRaceStatus->field0[kart->mIndex].mStatus != 1) {
                kart->field7C = kart->field7C | 0x200000;
            } else if (raceSetup->mMode == MODE_MISSION_RUN) {
                kart->field7C = kart->field7C | 0x200000;
                kart->field48 = kart->field48 | 0x2000;
            }
            if ((kart->field7C & KART_7C_ENTRY_KIND_2) != 0) {
                func_02068ec0(kart, 0);
            }
        }
    }
    StartKartWinOrLoseAnimation(kart);
    cspl_killSplashes(kart->mIndex);
    rptc_stopRainbowEffectDirect(kart->mIndex);
    if ((kart->field4C & 0x40) != 0) {
        kart->field4C = kart->field4C & ~0x40;
        driver_disableStarToonMode(kart);
        kart->mItemEffect = 0;
        rptc_stopRainbowEffect(kart->mIndex);
        driver_2068A64(kart, 0, 1);
        if ((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0 && gRaceMultiConfig->mRaceKind == RACE_KIND_NORMAL) {
            snd_stopStarMusic();
        }
        if ((kart->field4C & 0x2000) != 0) {
            driver_enableSlipStreamToonMode(kart);
        }
    }
    effectState = &kart->field538;
    if ((kart->field4C & 0x10000000) != 0 && effectState->mKillerEnding == FALSE) {
        effectState->mKillerEnding = TRUE;
        if ((kart->field7C & 0x200) != 0) {
            kart->field514->field2C ^= 0x200000;
        }
    }
    if ((kart->field7C & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0) {
        race_20617D8();
        raceSetup = gRaceMultiConfig;
        if (raceSetup->mMode != MODE_GRAND_PRIX && raceSetup->mMode != MODE_TIME_ATTACK &&
            ((raceSetup->mRuleKind == 1 && gRaceStatus->field0[kart->mIndex].mStatus != 1) ||
             ((i = raceSetup->mKartCount) > 1 && (c = rstat_getPlace(kart->mIndex), c == i)))) {
            cam_2075CF0();
        } else {
            cam_2075EB8();
            rptc_2081F30();
        }
    } else if (gRaceMultiConfig->mMode == MODE_VS || gRaceMultiConfig->mMode == 5) {
        if (gRaceStatus->field0[kart->mIndex].mStatus == 1) {
            framesSinceEntryEnd = 0;
            if (race_20617A8((u32 *) &framesSinceEntryEnd) != 0 &&
                (u32) framesSinceEntryEnd > 0xb4) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x45);
            }
        }
    }
    raceSetup = gRaceMultiConfig;
    if (raceSetup->mMode == MODE_BATTLE) {
        return;
    }
    g = 1;
    if (SoundHandle_217D084.mMode != 2 && SoundHandle_217D084.mMode != 3) {
        g = 0;
    }
    if (g == 0) {
        return;
    }
    if (kart->mIndex == raceSetup->mEntryIndex) {
        c = func_02110e58();
        switch (c) {
            case 0:
                d = 9;
                break;
            case 1:
                d = 0xa;
                break;
            case 2:
                d = 0xb;
                break;
        }
        func_0210b198(kart->mSoundIndex, d, 0x6e, 7, -1);
        return;
    }
    d = func_02110fb8(rstat_getPlace(kart->mIndex));
    if ((kart->field48 & 0x840) != 0) {
        return;
    }
    sfx_emitDriverVoice(kart, kart->mSoundIndex, d);
}

void AdvanceKartWobble(Kart *kart) {
    MtxFx43 rotationMatrix;
    s32 angleAmplitude;
    s32 angleValue;
    u16 angle;
    s32 amplitudeDelta;

    kart->mWobbleAngle = kart->mWobbleAngle + gKartWobbleAnglePerCall;
    kart->mWobbleSine = FX_SinCosTable_[(kart->mWobbleAngle >> 4) * 2];
    if (kart->mWobbleAmplitude > 0) {
        kart->mWobbleAmplitude = (s64) kart->mWobbleAmplitude * gKartWobbleAmplitudeDecay + 0x800 >> 12;
        kart->mWobbleAmplitude = kart->mWobbleAmplitude - 0x64;
        if ((kart->field44 & KART_44_ON_GROUND) == 0 ||
            (kart->mForwardSpeed > 0 ? kart->mForwardSpeed : -kart->mForwardSpeed) < 0x3000) {
            kart->mWobbleAmplitude = (s64) kart->mWobbleAmplitude * 0xe66 + 0x800 >> 12;
        }
        if (kart->mWobbleAmplitude < 0) {
            kart->mWobbleAmplitude = 0;
        }
    }
    amplitudeDelta = kart->mWobbleDirection * kart->mWobbleAmplitude - kart->mWobbleEasedAmplitude;
    kart->mWobbleEasedAmplitude =
        kart->mWobbleEasedAmplitude + (s32) ((s64) amplitudeDelta * gKartWobbleEaseFactor + 0x800 >> 12);
    angleAmplitude = (s64) kart->mWobbleEasedAmplitude * gKartWobbleAngleFactor + 0x800 >> 12;
    angleValue = (s64) angleAmplitude * kart->mWobbleSine + 0x800 >> 12;
    angle = angleValue;
    MTX_RotY43_(&rotationMatrix, FX_SinCosTable_[(angle >> 4) * 2], FX_SinCosTable_[(angle >> 4) * 2 + 1]);
    MTX_Concat43(&rotationMatrix, &kart->mUnk_150_m, &kart->mWobbleMatrix);
    if ((kart->mWobbleEasedAmplitude > 0 ? kart->mWobbleEasedAmplitude : -kart->mWobbleEasedAmplitude) >= 0x29) {
        return;
    }
    kart->field4C = kart->field4C & ~0x2000000;
    kart->mWobbleAngle = 0;
    kart->mWobbleSine = 0;
    kart->mWobbleAmplitude = 0;
    kart->mWobbleDirection = 0;
}

void func_02066ac0(Kart *kart) {
    ParticipantKartRecordState *state;
    ParticipantKartRecordNode *node;
    ParticipantKartRecordState *stateAgain;
    Unk0217aa14_104 *entry;
    ParticipantKartRecord *record;
    s32 difference;
    s32 appliedNow;
    s16 negatedDifference;
    u32 h;
    ParticipantKartRecordNode *pendingNode;
    ParticipantKartRecordNode *nextNode;

    state = kart->field514;
    appliedNow = 0;
    h = func_0205b954(((u8 *) gStruct217AA18)[kart->mIndex & 0xff]);
    state->field24 = race_getState() == 1 ? 0x333 : appliedNow;
    if (h > state->field20) {
        entry = func_0205b978(((u8 *) gStruct217AA18)[kart->mIndex & 0xff], h);
        record = entry != NULL ? (ParticipantKartRecord *) entry->field8 : 0;
        if (record != NULL) {
            difference = gStruct217AA14->field728 - h;
            if (difference < 0) {
                negatedDifference = -difference;
                node = NNS_FndGetNthListObject(&state->mFreeRecords, 0);
                if (node != NULL) {
                    NNS_FndRemoveListObject(&state->mFreeRecords, node);
                    node->mRecord = *record;
                    node->mApplyTimer = negatedDifference + 1;
                    NNS_FndAppendListObject(&state->mPendingRecords, node);
                }
                stateAgain = kart->field514;
                stateAgain->mEasedTurnAngle =
                    stateAgain->mEasedTurnAngle +
                    (s32) ((s64) (stateAgain->mTargetTurnAngle - stateAgain->mEasedTurnAngle) * 0x333 + 0x800 >> 12);
                kart->mTurnAngle = stateAgain->mEasedTurnAngle;
            } else {
                if (difference > 0x19) {
                    difference = 0x19;
                }
                func_020653d0(kart, record, difference);
                appliedNow = 1;
            }
        }
        state->field20 = h;
    } else {
        stateAgain = kart->field514;
        stateAgain->mEasedTurnAngle =
            stateAgain->mEasedTurnAngle +
            (s32) ((s64) (stateAgain->mTargetTurnAngle - stateAgain->mEasedTurnAngle) * 0x333 + 0x800 >> 12);
        kart->mTurnAngle = stateAgain->mEasedTurnAngle;
    }
    stateAgain = kart->field514;
    pendingNode = NNS_FndGetNextListObject(&stateAgain->mPendingRecords, NULL);
    while (pendingNode != NULL) {
        nextNode = NNS_FndGetNextListObject(&stateAgain->mPendingRecords, pendingNode);
        pendingNode->mApplyTimer = pendingNode->mApplyTimer - 1;
        if (pendingNode->mApplyTimer <= 0) {
            if (appliedNow == 0) {
                func_020653d0(kart, &pendingNode->mRecord, 0);
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
    if ((kart->field514->field44 & 2) != 0) {
        input_pressVirtualPadKeys(kart->mEntryIndex, PAD_KEY_A);
    }
    if ((kart->field514->field44 & 4) != 0) {
        input_pressVirtualPadKeys(kart->mEntryIndex, PAD_KEY_B);
    }
    if ((kart->field514->field44 & 8) != 0) {
        input_pressVirtualPadKeys(kart->mEntryIndex, PAD_KEY_LEFT);
    }
    if ((kart->field514->field44 & 0x10) != 0) {
        input_pressVirtualPadKeys(kart->mEntryIndex, PAD_KEY_RIGHT);
    }
    if ((kart->field514->field44 & 1) != 0) {
        kart->field44 = kart->field44 | KART_44_ON_GROUND;
    }
    if ((kart->field514->field44 & 0x20) != 0) {
        kart->mBoostTimer = 3;
        kart->field48 = kart->field48 | KART_48_BOOST;
    } else {
        kart->mBoostTimer = 0;
        kart->field48 = kart->field48 & ~KART_48_BOOST;
    }
}
