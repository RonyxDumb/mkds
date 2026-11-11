#include "Main/Unknown/code_0206f04c.h"
#include "Main/Unknown/code_0206d000.h"
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
#include "Main/Unknown/code_02081374.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_020e73a0.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_0208c16c.h"
#include "Main/Unknown/code_020b33d8.h"
#include "ITCM/code_01ffad14.h"
#include "ITCM/code_01ffb000.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_0208d978.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020815a0.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02040de0.h"
#include "code_0212df7c.h"
#include "code_0212bcac.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_020681f0.h"
#include "Main/Unknown/code_02077bc0.h"

#pragma opt_arithtransformation off

void StartKartRespawnWait(Kart *kart, u32 collisionFlags) {
    u32 value;
    u32 respawnSlot;
    NNSSndSeqPlayer **soundHandleEntry;
    s32 effectIndex;
    s32 mode;
    u16 kartIndex;
    Vec3 waterSurfacePos;
    KartFollowEffectIds kartFollowEffectIds;

    if (kart->mUnk_7c & 0x400) {
        return;
    }
    if (collisionFlags & 0x8000) {
        if (kart->mState == KART_STATE_LAUNCH_DOUBLE_FLIP) {
            return;
        }
        value = (u16) ((PickCollisionHitValue(0x8000) & 0xe0) >> 5);
        mode = gRaceSetup->mMode;
        if (mode == MODE_BATTLE || mode == MODE_MISSION_RUN) {
            PlaceKartAtKeyedPlacement(kart, value);
            return;
        }
        kart->mUnk_48 |= 0x10000;
        ResetKartMotionState(kart, 0);
        return;
    }
    if (!(kart->mUnk_48 & KART_48_RESPAWN_WAIT)) {
        kart->mUnk_48 |= KART_48_RESPAWN_WAIT;
        kartIndex = kart->mIndex;
        if (gRaceSetup->mMode == MODE_BATTLE) {
            respawnSlot = GetCourseMapRespawnSlot(0);
        } else {
            respawnSlot = GetCourseMapRespawnSlot(gRaceProgress->mKarts[kartIndex].mCheckpoint);
        }
        kart->mRespawnSlot = respawnSlot;
        if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && gRaceSetup->mCourseId == COURSE_ID_RAINBOW &&
            (gRaceSoundKind & 1)) {
            soundHandleEntry = TakeSoundHandleEntry(GetSoundHandlePool(0));
            if (gSoundModeHolder.mSeqStartEnabled != 0) {
                if (soundHandleEntry[0] != NULL) {
                    NNS_SndPlayerStopSeq(soundHandleEntry, 0);
                }
                if (soundHandleEntry[0] != NULL) {
                    NNS_SndPlayerStopSeq(soundHandleEntry, 0);
                }
                NNS_SndArcPlayerStartSeqArc(soundHandleEntry, 0, 0x1b7);
            }
        }
    }
    if (!(collisionFlags & 0xc00)) {
        return;
    }
    if (kart->mUnk_48 & 0x1000) {
        return;
    }
    HideRaceTaKartPositions(kart->mIndex);
    kart->mUnk_48 |= 0x41000;
    kart->mUnk_48 &= 0xdfe77fdf;
    kart->mBoostTimer = 0;
    kart->mItemEffectData.mKinokoBoostTimer = 0;
    kart->mMiniTurboTimer = 0;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!(kart->mUnk_4c & 0x10000000) && !(kart->mUnk_48 & 0x4000000)) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
    }
    if (kart->mUnk_4c & 0x10000000) {
        kart->mUnk_4c &= ~0x10000000;
        ResetKartActiveItemAfterKiller(kart->mIndex);
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            ResetCameraHalfFovAngleGoal();
        }
        kart->mRadiusFactor = 0x1000;
        kart->mSurfaceGroup = -1;
        effectIndex = 0;
        kart->mItemEffect = 0;
        if (kart->mKartModelsEntry->mKartModelHidden == 0) {
            kartFollowEffectIds = gKartFollowEffectIds;
            for (effectIndex = 0; effectIndex < 3; effectIndex++) {
                SetupKartFollowEffect(StartEffect(kartFollowEffectIds.mEffectIds[effectIndex], &kart->mPos),
                                      kart->mIndex, 0x14);
            }
        }
        StopKartKillerEffect(kart->mIndex);
        StartSound(&kart->mSoundSource, 0xfd, 0x7f, 0);
    }
    StopRunningKartItemSlot(&(gKartItems)[kart->mIndex]);
    if (collisionFlags & 0x400) {
        value = PickCollisionHitValue(0x400);
        kart->mUnk_48 |= 0x2000;
        if ((u16) ((value & 0xe0) >> 5) == 4) {
            kart->mUnk_48 |= 0x800000;
        }
        return;
    }
    value = (u16) ((PickCollisionHitValue(0x800) & 0xe0) >> 5);
    kart->mRespawnWaitVelocityScale = kart->mVelocityScaleFactor;
    kart->mUnk_4c |= 0x200000;
    if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        SetEntryCameraUpdateHold(1);
    }
    if ((u16) (value + 0xffff) <= 1) {
        waterSurfacePos = kart->mPos;
        if (value == 1) {
            kart->mUnk_48 |= 0x800000;
            value = 0xce;
        } else {
            kart->mUnk_48 |= 0x1000000;
            value = 0x15d;
        }
        waterSurfacePos.y = kart->mPos.y - GetHeightAboveWaterOrEfct(kart->mPos.y);
        StartWaterEfctKind2Effects(&waterSurfacePos, (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0);
        kart->mUnk_4c |= 0x4000000;
        StartSound(&kart->mSoundSource, value, 0x7f, 0);
        kart->mGravity = 0;
    }
    StartKartSeqArcSound(kart, kart->mSoundIndex, 0);
}

void ApplyKartWaterDepth(Kart *kart) {
    BOOL flag;
    s32 heightAboveWater;
    s32 scaledFactorPerDepth;
    Vec3 waterSurfacePoint;

    heightAboveWater = GetHeightAboveWaterOrEfct(kart->mPos.y);
    if (heightAboveWater < 0 && !(kart->mUnk_4c & 0x4000000)) {
        flag = FALSE;
        scaledFactorPerDepth = MUL_FIXED12_NO_ROUND(kart->mSpeedLimitFactorPerDepth, kart->mScale.z);
        kart->mSpeedLimitFactor = MUL_FIXED12_NO_ROUND(scaledFactorPerDepth, heightAboveWater) + 0x1000;
        if (kart->mSpeedLimitFactor < kart->mPhysicalParam->mSurfaceSpeedLimitFactors[4]) {
            kart->mSpeedLimitFactor = kart->mPhysicalParam->mSurfaceSpeedLimitFactors[4];
        }
        IncrementEntryKartSurfaceCount(kart);
        kart->mWaterDepth = -heightAboveWater;
        if (GetHeightAboveWaterOrEfct(kart->mPos.y) <= -0xa000 &&
            GetHeightAboveWaterOrEfct(kart->mPrevPos.y) > -0xa000 && kart->mVelocity.y < -0x2000) {
            waterSurfacePoint = kart->mPos;
            waterSurfacePoint.y = kart->mPos.y - heightAboveWater;
            StartWaterEfctKind2Effects(&waterSurfacePoint, (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) != 0);
            flag = FALSE;
        }
        if (flag != FALSE) {
            return;
        }
        if (kart->mUnk_4c & 0x4000000) {
            return;
        }
        ApplyKartWaterEffects(kart);
    } else {
        kart->mWaterDepth = 0;
        StopKartWaterEffects(kart);
    }
}

void AdvanceKartRaceStartBoost(Kart *kart) {
    s32 keyALevel;
    s32 levelStep;
    s32 revLevel;
    s32 boostIndex;
    u32 bits7c;
    Vec3 firstEffectPos;
    Vec3 secondEffectPos;
    KartEffectScales firstOffsets;
    KartEffectScales secondOffsets;

    if (kart->mUnk_48 & 2) {
        keyALevel = kart->mRevLevel;
        if (keyALevel < 0) {
            levelStep = 0x52;
        } else if (keyALevel > 0x1000) {
            levelStep = 8;
        } else {
            levelStep = FX_Div(0x4a, 0x1000);
            levelStep = 0x52 - MUL_FIXED12_NO_ROUND(levelStep, keyALevel);
        }
        kart->mRevLevel = kart->mRevLevel + levelStep;
        if (kart->mRevLevel > 0x1000) {
            kart->mRevLevel = 0x1000;
        }
    } else {
        kart->mRevLevel = MUL_FIXED12_NO_ROUND(kart->mRevLevel, 0xf5c);
    }
    if (!(kart->mUnk_4c & KART_4C_HEADING_SWING)) {
        if (GetRaceStartSequenceFrames() - 0xaf > 0) {
            kart->mUnk_44 |= 0x1000000;
        }
    }
    if (GetRaceStartSequenceFrames() - 0xaf == 0) {
        if (kart->mUnk_7c & 2) {
            if (GetKartAiHeadingSwingAtRaceStart(kart->mAi) != 0) {
                if (!(kart->mUnk_4c & KART_4C_HEADING_SWING)) {
                    kart->mUnk_4c |= KART_4C_HEADING_SWING;
                    kart->mRaceStartFrameCount = 0x78;
                    SetKartCharacterAnimation(kart, 1, 1);
                    firstOffsets = data_usa_02165608;
                    bits7c = kart->mUnk_7c;
                    if ((bits7c & 0x10) && kart->mKartModelsEntry->mKartModelHidden == 0) {
                        if ((bits7c & 1) || !(bits7c & 0x402000)) {
                            VEC_MultAdd(firstOffsets.mScales[kart->mKartModelsEntry->mKartIndex] << 4, &kart->mUnk_138,
                                        &kart->mPos, &firstEffectPos);
                            StartEffectWithCallback(0x72, &firstEffectPos, kart, PlaceEffectBehindKart);
                            StartEffectWithCallback(0x73, &firstEffectPos, kart, PlaceEffectBehindKart);
                        }
                    }
                    if (!(kart->mUnk_48 & (KART_48_SINKING | KART_48_RESPAWN_WAIT))) {
                        StartKartSeqArcSound(kart, kart->mSoundIndex, 3);
                    }
                    StartKartModelScaleAnimation(kart, 1);
                    kart->mModelScaleKind = 1;
                }
            } else if (GetKartAiBoostsAtRaceStart(kart->mAi) != 0) {
                boostIndex = GetKartAiRaceStartBoostChoice(kart->mAi);
                kart->mRaceStartFrameCount = data_usa_02154a48[boostIndex - 1];
                kart->mUnk_44 |= 0x1800000;
                StartKartBoost(kart, KART_BOOST_RACE_START, (s16) kart->mRaceStartFrameCount);
                if (!(kart->mUnk_48 & (KART_48_SINKING | KART_48_RESPAWN_WAIT))) {
                    StartKartSeqArcSound(kart, kart->mSoundIndex, 5);
                }
                kart->mUnk_48 |= 0x8000;
                if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                    GetEntryKartCounters()->mRaceStartBoosted = 1;
                } else {
                    StartSound(&kart->mSoundSource, 0xa1, 0x7f, 0);
                }
            }
        } else if (kart->mUnk_48 & 2) {
            revLevel = kart->mRevLevel;
            if (revLevel > 0xf34) {
                if (!(kart->mUnk_4c & KART_4C_HEADING_SWING)) {
                    kart->mUnk_4c |= KART_4C_HEADING_SWING;
                    kart->mRaceStartFrameCount = 0x78;
                    SetKartCharacterAnimation(kart, 1, 1);
                    secondOffsets = data_usa_02165608;
                    bits7c = kart->mUnk_7c;
                    if ((bits7c & 0x10) && kart->mKartModelsEntry->mKartModelHidden == 0) {
                        if ((bits7c & 1) || !(bits7c & 0x402000)) {
                            VEC_MultAdd(secondOffsets.mScales[kart->mKartModelsEntry->mKartIndex] << 4, &kart->mUnk_138,
                                        &kart->mPos, &secondEffectPos);
                            StartEffectWithCallback(0x72, &secondEffectPos, kart, PlaceEffectBehindKart);
                            StartEffectWithCallback(0x73, &secondEffectPos, kart, PlaceEffectBehindKart);
                        }
                    }
                    if (!(kart->mUnk_48 & (KART_48_SINKING | KART_48_RESPAWN_WAIT))) {
                        StartKartSeqArcSound(kart, kart->mSoundIndex, 3);
                    }
                    StartKartModelScaleAnimation(kart, 1);
                    kart->mModelScaleKind = 1;
                }
            } else if (revLevel > 0xd9a) {
                boostIndex = 5;
                if (revLevel < 0xe14) {
                    boostIndex = 1;
                } else if (revLevel < 0xe7b) {
                    boostIndex = 2;
                } else if (revLevel < 0xecd) {
                    boostIndex = 3;
                } else if (revLevel < 0xf0a) {
                    boostIndex = 4;
                }
                kart->mRaceStartFrameCount = data_usa_02154a48[boostIndex - 1];
                kart->mUnk_44 |= 0x1800000;
                StartKartBoost(kart, KART_BOOST_RACE_START, (s16) kart->mRaceStartFrameCount);
                if (!(kart->mUnk_48 & (KART_48_SINKING | KART_48_RESPAWN_WAIT))) {
                    StartKartSeqArcSound(kart, kart->mSoundIndex, 5);
                }
                kart->mUnk_48 |= 0x8000;
                if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                    GetEntryKartCounters()->mRaceStartBoosted = 1;
                } else {
                    StartSound(&kart->mSoundSource, 0xa1, 0x7f, 0);
                }
            }
        }
        kart->mAdvanceOffsetCycle = AdvanceKartOffsetCycleIndex;
        if (!(kart->mUnk_4c & KART_4C_HEADING_SWING)) {
            kart->mUnk_44 |= 0x1000000;
        }
    }
    kart->mOffsetCyclePhaseStep = kart->mRevLevel + 0x1000;
}

void ApplyKartAttractorPull(Kart *kart, Vec3 *groundNormal, s32 bit100000WasSet) {
    Vec3 *attractorPosition;
    s32 limit;
    s32 step;
    Vec3 normalCrossOffset;
    Vec3 offsetToAttractor;

    attractorPosition = GetAttractorPosition((u16) kart->mAttractorIndex);
    limit = GetAttractorStrength((u16) kart->mAttractorIndex) * 150;
    step = 0x333;
    if (kart->mUnk_7c & 2) {
        limit >>= 1;
        step >>= 1;
    }
    if (bit100000WasSet == 0) {
        VEC_Subtract(attractorPosition, &kart->mPos, &offsetToAttractor);
        Vec3CrossUnrounded(groundNormal, &offsetToAttractor, &normalCrossOffset);
        Vec3CrossUnrounded(&normalCrossOffset, groundNormal, &offsetToAttractor);
        if (!(LENGTH_SQUARED(offsetToAttractor) < 0x10)) {
            Vec3NormalizeAndGetLengthUnchecked(&offsetToAttractor, &kart->mAttractorPullDirection);
        }
    }
    kart->mUnk_44 |= 0x100000;
    kart->mAttractorPullSpeed = kart->mAttractorPullSpeed + step;
    if (kart->mAttractorPullSpeed > limit) {
        kart->mAttractorPullSpeed = limit;
    }
}

void AdvanceKartPointMotion(Kart *kart, u32 collisionFlags, Vec3 *targetPointMotion, s32 headingDelta) {
    Vec3 motionDifference;
    Vec3 decayFactors;

    if (collisionFlags & 0x40000000) {
        kart->mUnk_44 |= 0x40000;
        kart->mHeadingAngle += headingDelta;
    } else if (collisionFlags & 0x1e34ef) {
        kart->mPointMotion.y = 0;
    }
    if (targetPointMotion->x | targetPointMotion->y | targetPointMotion->z) {
        VEC_Subtract(targetPointMotion, &kart->mPointMotion, &motionDifference);
        if (LENGTH_SQUARED(motionDifference) < 0x1000000) {
            kart->mPointMotion = *targetPointMotion;
        } else {
            VEC_MultAdd(0x199, &motionDifference, &kart->mPointMotion, &kart->mPointMotion);
        }
        kart->mVerticalSpeed = kart->mVerticalSpeed + kart->mPointMotion.y;
        kart->mPointMotion.y = 0;
    } else {
        decayFactors = data_usa_02165554;
        kart->mPointMotion.x = MUL_FIXED12_NO_ROUND(kart->mPointMotion.x, decayFactors.x);
        kart->mPointMotion.y = MUL_FIXED12_NO_ROUND(kart->mPointMotion.y, decayFactors.y);
        kart->mPointMotion.z = MUL_FIXED12_NO_ROUND(kart->mPointMotion.z, decayFactors.z);
        if ((s64) kart->mPointMotion.x * kart->mPointMotion.x + (s64) kart->mPointMotion.y * kart->mPointMotion.y +
                (s64) kart->mPointMotion.z * kart->mPointMotion.z <
            0xa429) {
            kart->mPointMotion = gKartVec3Zero;
        }
    }
}

void ApplyKartCourseContact(Kart *kart, u32 collisionFlags, Vec3 *contactNormal) {
    s32 baseSpeedLimitHitFactor;
    s32 absNormalY;
    u32 hitValue;

    if (collisionFlags & 0x200000) {
        baseSpeedLimitHitFactor = 0x1000;
    } else {
        baseSpeedLimitHitFactor = 0xccd;
    }
    hitValue = PickCollisionHitValue(0x214300);
    ApplyKartContact(kart, contactNormal, (kart->mUnk_44 & 0x80) != 0, baseSpeedLimitHitFactor,
                     (s32) (hitValue & 0x1f00) >> 8, ((hitValue & 0xe0) << 11) >> 16, 2);
    kart->mUnk_44 |= 0x80;
    kart->mCourseContactNormal = *contactNormal;
    if (kart->mState == KART_STATE_LAUNCH_DOUBLE_FLIP && contactNormal->y < -0x800 && kart->mVerticalSpeed > 0) {
        kart->mVerticalSpeed = -kart->mVerticalSpeed;
    }
    absNormalY = contactNormal->y;
    if (absNormalY <= 0) {
        absNormalY = -absNormalY;
    }
    if (absNormalY > 0x3e8) {
        kart->mUnk_44 |= 0x40000000;
    }
    if (!(collisionFlags & 0x2000000)) {
        return;
    }
    if (data_0217ac10 == 0) {
        return;
    }
    if (collisionFlags & 0x10000) {
        kart->mUnk_44 |= 0x4000000;
    }
}

s32 ApplyKartContact(Kart *kart, Vec3 *contactNormal, s32 wasTouching, s32 baseSpeedLimitHitFactor, s32 surfaceKind,
                     s32 surfaceVariant, s32 value) {
    BOOL isFirstContact;
    s32 dotValue;
    s32 forwardDot;
    s32 forwardFactor;
    s32 factor;
    s16 headingAnglePerFrame;
    Vec3 normalVelocity;
    Vec3 crossVector;
    Vec3 effectPos;

    isFirstContact = FALSE;
    forwardFactor = Vec3DotUnrounded(&kart->mSignedTurnedForward, contactNormal) + 0x1000;
    if (forwardFactor > 0x1000) {
        forwardFactor = 0x1000;
    } else if (forwardFactor < 0x29) {
        forwardFactor = 0x29;
    }
    dotValue = VEC_DotProduct(contactNormal, &kart->mHitVelocity);
    kart->mHitVelocity.x = kart->mHitVelocity.x - MUL_FIXED12_NO_ROUND(contactNormal->x, dotValue);
    kart->mHitVelocity.y = kart->mHitVelocity.y - MUL_FIXED12_NO_ROUND(contactNormal->y, dotValue);
    kart->mHitVelocity.z = kart->mHitVelocity.z - MUL_FIXED12_NO_ROUND(contactNormal->z, dotValue);
    dotValue = VEC_DotProduct(contactNormal, &kart->mPrevHitVelocity);
    kart->mPrevHitVelocity.x = kart->mPrevHitVelocity.x - MUL_FIXED12_NO_ROUND(contactNormal->x, dotValue);
    kart->mPrevHitVelocity.y = kart->mPrevHitVelocity.y - MUL_FIXED12_NO_ROUND(contactNormal->y, dotValue);
    factor = MUL_FIXED12_NO_ROUND(baseSpeedLimitHitFactor, forwardFactor);
    kart->mPrevHitVelocity.z = kart->mPrevHitVelocity.z - MUL_FIXED12_NO_ROUND(contactNormal->z, dotValue);
    kart->mSpeedLimitHitFactor = factor;
    if (Vec3DotUnrounded(&kart->mPointMotion, contactNormal) < -0x800) {
        kart->mPointMotion = gKartVec3Zero;
    }
    if (wasTouching == 0) {
        forwardDot = Vec3DotUnrounded(&kart->mUnk_138, contactNormal);
        isFirstContact = TRUE;
        dotValue = VEC_DotProduct(contactNormal, &kart->mVelocity);
        normalVelocity.x = MUL_FIXED12_NO_ROUND(contactNormal->x, dotValue);
        normalVelocity.y = MUL_FIXED12_NO_ROUND(contactNormal->y, dotValue);
        normalVelocity.z = MUL_FIXED12_NO_ROUND(contactNormal->z, dotValue);
        kart->mDriftCharge = 0;
        kart->mRightTurnCount = 0;
        kart->mLeftTurnCount = kart->mRightTurnCount;
        kart->mTurnCountTimer = 0;
        kart->mHeadingAnglePerFrame = 0;
        if (kart->mVelocityLength > 0x1800) {
            if (!(kart->mUnk_48 & KART_48_BOOST) &&
                (normalVelocity.x != 0 || normalVelocity.y != 0 || normalVelocity.z != 0) &&
                baseSpeedLimitHitFactor != 0x1000) {
                BounceVelocityOffSurface(&normalVelocity, contactNormal, 0, 0x4cd, 0, &normalVelocity);
                kart->mHitVelocity.x = normalVelocity.x;
                kart->mHitVelocity.z = normalVelocity.z;
                kart->mVerticalSpeed = kart->mVerticalSpeed + normalVelocity.y;
            }
            if (kart->mCourseHitTimer <= 0) {
                if (surfaceKind >= 0) {
                    StartKartSurfaceSound(kart, 0, surfaceKind, surfaceVariant, 0);
                }
                if (value == 2 && surfaceVariant != 5 && kart->mKartModelsEntry->mKartModelHidden == 0) {
                    factor = kart->mUnk_7c;
                    dotValue = 0;
                    if (!(factor & 1) && (factor & 0x402000)) {
                        dotValue = 1;
                    }
                    if (dotValue == 0) {
                        effectPos = kart->mPos;
                        dotValue = 0x800;
                        if (kart->mUnk_4c & 0x10000) {
                            dotValue = 0x4cd;
                        }
                        VEC_MultAdd(-kart->mRadius, contactNormal, &kart->mPos, &effectPos);
                        VEC_MultAdd(MUL_FIXED12_ROUNDED(kart->mScale.y, dotValue << 4), &kart->mUnk_12c, &effectPos,
                                    &effectPos);
                        StartEffectWithCallback(0x3b, &effectPos, kart, SetEffectScaleFromKart);
                    }
                }
                StartKartModelScaleAnimation(kart, 2);
            }
        }
        if (forwardDot > 0) {
            kart->mSpeedLimitHitFactor = 0x4cd;
            if (kart->mSurfaceGroup != 0xb && kart->mSurfaceGroup != 8) {
                kart->mUnk_48 &= 0xdfe77fdf;
                kart->mBoostTimer = 0;
                kart->mItemEffectData.mKinokoBoostTimer = 0;
                kart->mMiniTurboTimer = 0;
                if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                    if (!(kart->mUnk_4c & 0x10000000) && !(kart->mUnk_48 & 0x4000000)) {
                        ResetCameraHalfFovAngleGoal();
                    }
                    StopDispCapBlend();
                }
            }
            if (kart->mVelocityLength > 0x2000 && baseSpeedLimitHitFactor != 0x1000) {
                headingAnglePerFrame = (kart->mVelocityLength >> 12) * 100;
                if ((u16) kart->mTurnAngle > 0x7fff) {
                    headingAnglePerFrame = headingAnglePerFrame * -1;
                }
                kart->mHeadingAnglePerFrame = headingAnglePerFrame;
            }
        } else if (kart->mVelocityLength > 0x2000 && baseSpeedLimitHitFactor != 0x1000) {
            factor = 0x1000 - forwardFactor;
            if (kart->mVelocityLength > 0x1800 && factor > 0x19a) {
                headingAnglePerFrame = (MUL_FIXED12_NO_ROUND(kart->mVelocityLength, factor) >> 12) * 30;
                Vec3CrossUnrounded(&kart->mSignedTurnedForward, contactNormal, &crossVector);
                if (Vec3DotUnrounded(&crossVector, &kart->mUnk_12c) < 0) {
                    headingAnglePerFrame = headingAnglePerFrame * -1;
                }
                kart->mHeadingAnglePerFrame = headingAnglePerFrame;
            }
        }
        if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && kart->mVelocityLength > 0x3000 && value == 2) {
            GetEntryKartCounters()->mUnk_10++;
        }
        kart->mTurnAngle = 0;
    } else if (surfaceVariant == 4) {
        StartAndPlaceKartContactEffect(kart->mIndex, contactNormal);
    }
    if (kart->mState != KART_STATE_NORMAL) {
        kart->mHeadingAnglePerFrame = 0;
    }
    return isFirstContact;
}
