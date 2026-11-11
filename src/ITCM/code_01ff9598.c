#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffad14.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0206d000.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02040de0.h"
#include "Main/Unknown/code_02061654.h"
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
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_02171000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02147cd8.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_0206f04c.h"

#pragma opt_arithtransformation off

BOOL IsLowestOffsetFarOnHitBit(Kart *kart, u32 collisionBits, Vec3 *lowestOffset) {
    BOOL farEnough = FALSE;

    if (collisionBits & 0x2000000) {
        if (HORIZONTAL_LENGTH_SQUARED(*lowestOffset) > 0x1000000) {
            farEnough = TRUE;
        }
    }
    return farEnough != FALSE;
}

BOOL IsLowestOffsetFarOnHitBitOrKartBit(Kart *kart, u32 collisionBits, Vec3 *lowestOffset) {
    BOOL result = TRUE;
    BOOL farEnough = FALSE;

    if (collisionBits & 0x2000000) {
        if (HORIZONTAL_LENGTH_SQUARED(*lowestOffset) > 0x1000000) {
            farEnough = TRUE;
        }
    }
    if (farEnough == FALSE) {
        if (!(kart->mMotionFlags & KART_MOTION_COURSE_PUSH_STRONG)) {
            result = FALSE;
        }
    }
    return result != FALSE;
}

BOOL IsLowestOffsetFarOnHitBitOrYAbove(Kart *kart, u32 collisionBits, Vec3 *lowestOffset) {
    BOOL result = TRUE;
    BOOL farEnough = FALSE;

    if (collisionBits & 0x2000000) {
        if (HORIZONTAL_LENGTH_SQUARED(*lowestOffset) > 0x1000000) {
            farEnough = TRUE;
        }
    }
    if (farEnough == FALSE) {
        if (lowestOffset->y <= MUL_FIXED12_ROUNDED(kart->mRadius, -0xb33)) {
            result = FALSE;
        }
    }
    return result != FALSE;
}

void ClearKartGroundContact(Kart *kart, u32 clearedBits) {
    kart->mMotionFlags = kart->mMotionFlags & ~clearedBits;
    kart->mCollisionHitLink->mObject = NULL;
    kart->mSurfaceGroup = -1;
    StopKartCurrentEffects(kart);
}

// Returns TRUE while the kart is below y = 0 and starts the respawn wait once; at y >= 0 it clears kart flag bits and
// returns FALSE.
BOOL StartKartRespawnWaitIfBelowZero(Kart *kart) {
    void *soundHandleEntry;
    u32 kartIndex;
    u32 respawnSlot;

    if (kart->mPos.y < 0) {
        if (!(kart->mEntryFlags & KART_ENTRY_WIFI_PEER) && !(kart->mDriveFlags & KART_DRIVE_RESPAWN_WAIT)) {
            kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_RESPAWN_WAIT;
            kartIndex = kart->mIndex;
            if (gRaceSetup->mMode == MODE_BATTLE) {
                respawnSlot = GetCourseMapRespawnSlot(0);
            } else {
                respawnSlot = GetCourseMapRespawnSlot(gRaceProgress->mKarts[kartIndex].mCheckpoint);
            }
            kart->mRespawnSlot = respawnSlot;
            if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
                if (gRaceSetup->mCourseId == COURSE_ID_RAINBOW && (gRaceSoundKind & 1)) {
                    soundHandleEntry = TakeSoundHandleEntry(GetSoundHandlePool(0));
                    if (gSoundModeHolder.mSeqStartEnabled != 0) {
                        if (*(u32 *) soundHandleEntry != 0) {
                            NNS_SndPlayerStopSeq(soundHandleEntry, 0);
                        }
                        if (*(u32 *) soundHandleEntry != 0) {
                            NNS_SndPlayerStopSeq(soundHandleEntry, 0);
                        }
                        NNS_SndArcPlayerStartSeqArc(soundHandleEntry, 0, 0x1b7);
                    }
                }
            }
        }
        return TRUE;
    }
    kart->mMotionFlags =
        kart->mMotionFlags & ~(KART_MOTION_LANDED | KART_MOTION_ATTRACTOR_PULL | KART_MOTION_DRIFT_BREAK |
                               KART_MOTION_COURSE_PUSH_STRONG | KART_MOTION_VERTICAL_CONTACT);
    kart->mDriveFlags = kart->mDriveFlags & ~(KART_DRIVE_ON_BOOST_SURFACE | KART_DRIVE_CONTACT_EFFECT |
                                              KART_DRIVE_COURSE_SOUND_PLAYED | KART_DRIVE_BOOST_SPEED_FLOOR);
    return FALSE;
}

void AdvanceKartQuaternionBlendFactor(Kart *kart, const Vec3 *direction) {
    s32 dot = Vec3DotUnrounded(&kart->mGroundNormal, direction);
    s32 maxFactor;

    if (kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) {
        maxFactor = 0x4cd;
    } else {
        maxFactor = 0x1ec;
    }
    if (dot < 0) {
        dot = 0;
    }
    if (dot >= 0xe66) {
        if (kart->mMotionFlags & KART_MOTION_STILL_HOLD) {
            if (kart->mCollisionHitLink->mObject == NULL && kart->mPointMotion.x == 0 && kart->mPointMotion.y == 0 &&
                kart->mPointMotion.z == 0 && kart->mCollisionStepFrames > 100) {
                kart->mQuaternionBlendFactor = 0;
                return;
            }
        }
        if (kart->mQuaternionBlendFactor >= maxFactor) {
            return;
        }
        kart->mQuaternionBlendFactor = kart->mQuaternionBlendFactor + 0x14;
        if (kart->mQuaternionBlendFactor > maxFactor) {
            kart->mQuaternionBlendFactor = maxFactor;
        }
    } else {
        kart->mQuaternionBlendFactor = MUL_FIXED12_NO_ROUND(maxFactor, kart->mVelocityLengthRatio);
    }
}

// Counts mAirborneFrames, also clears mUnk_234, sets or clears KART_MOTION_AIRBORNE_LONG and stores mLastGroundY. Not
// run while the kart is below y = 0.
void UpdateKartAirborne(Kart *kart) {
    if (kart->mMotionFlags & KART_MOTION_ON_GROUND) {
        kart->mAirborneFrames = 0;
        kart->mAirTiltAngle = 0;
        kart->mMotionFlags = kart->mMotionFlags & ~KART_MOTION_AIRBORNE_LONG;
        kart->mLastGroundY = kart->mPos.y;
        return;
    }
    kart->mAirborneFrames = kart->mAirborneFrames + 1;
    if (kart->mAirborneFrames > 5) {
        kart->mMotionFlags = kart->mMotionFlags | KART_MOTION_AIRBORNE_LONG;
    }
}

void AdvanceKartOrientation(Kart *kart, Vec3 *direction) {
    Vec4 tiltQuaternion;
    u32 value;

    kart->mVelocityScaleFactor = 0x1000;
    if (kart->mAirborneFrames > 5) {
        kart->mQuaternionBlendFactor = 0xf6;
        ComputeKartAirTiltQuaternion(kart, &kart->mUnk_100_q);
    } else {
        AdvanceKartQuaternionFromVector(kart, direction);
    }
    QuaternionBlend(&kart->mUnk_f0_q, &kart->mUnk_100_q, &kart->mUnk_f0_q, kart->mQuaternionBlendFactor);
    QuaternionFromAxisAngle(&gKartVec3UnitY, (u16) (kart->mHeadingAngle + kart->mHeadingAngleOffset), &kart->mUnk_e0_m);
    QuaternionMultiply(&kart->mUnk_f0_q, &kart->mUnk_e0_m, &kart->mUnk_110_q);
    if (kart->mMotionFlags & KART_MOTION_HOPPING) {
        if (kart->mHopSpeed > 0) {
            kart->mHopTiltAngle = 0x9c4 - (u16) MUL_FIXED12_NO_ROUND(kart->mHopHeight, 500);
            if (kart->mHopTiltAngle > 0x6a4) {
                kart->mHopTiltAngle = 0x352;
            }
        } else {
            kart->mHopTiltAngle = 0;
        }
        QuaternionFromAxisAngle(&gKartVec3UnitX, (u16) -kart->mHopTiltAngle, &tiltQuaternion);
        QuaternionMultiply(&kart->mUnk_110_q, &tiltQuaternion, &kart->mUnk_110_q);
    } else {
        kart->mHopTiltAngle = 0;
    }
    QuaternionNormalize(&kart->mUnk_110_q, &kart->mUnk_110_q);
}

// Runs only on a step with a ground hit (non-zero normal).
void RefreshKartSurface(Kart *kart) {
    s32 hitValue = PickCollisionHitValue(0x1e34ef);
    s32 surfaceGroup;
    s32 targetFactor;
    s32 currentFactor;
    s32 easeIndex;

    kart->mSurfaceKind = (hitValue & 0x1f00) >> 8;
    kart->mSurfaceVariant = (u32) ((hitValue & 0xe0) << 11) >> 16;
    targetFactor = 0x1000;
    surfaceGroup = gKartSurfaceFunctions[kart->mSurfaceKind](kart);
    if (surfaceGroup != 0) {
        targetFactor = kart->mPhysicalParam->mSurfaceSpeedLimitFactors[surfaceGroup];
    }
    currentFactor = kart->mSpeedLimitFactor;
    if (targetFactor >= currentFactor) {
        kart->mSpeedLimitFactor = targetFactor;
    } else {
        kart->mSpeedLimitFactor = currentFactor + MUL_FIXED12_ROUNDED(targetFactor - currentFactor, 0x4cd);
    }
    if (kart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) {
        easeIndex = 0;
    } else {
        easeIndex = surfaceGroup;
    }
    kart->mTurnedForwardEaseFactor = kart->mPhysicalParam->mSurfaceTurnedForwardEaseFactors[easeIndex];
    if (kart->mDriveFlags & KART_DRIVE_BOOST_SURFACE_HELD) {
        if (kart->mMotionFlags & KART_MOTION_ON_GROUND) {
            if (surfaceGroup != 0xb) {
                kart->mDriveFlags = kart->mDriveFlags & ~KART_DRIVE_BOOST_SURFACE_HELD;
            }
        }
    }
    kart->mSurfaceGroup = surfaceGroup;
}

void AdvanceKartBoosts(Kart *kart) {
    u32 raceUpdateFrames;
    s32 frameDifference;
    enum { K0 } entryIndex;

    if (kart->mDriveFlags & KART_DRIVE_MINI_TURBO) {
        kart->mMiniTurboTimer = kart->mMiniTurboTimer - 1;
        if (kart->mMiniTurboTimer <= 0) {
            kart->mDriveFlags = kart->mDriveFlags & ~KART_DRIVE_MINI_TURBO;
            kart->mMiniTurboTimer = 0;
        }
    }
    if (kart->mDriveFlags & KART_DRIVE_KINOKO_BOOST) {
        kart->mItemEffectData.mKinokoBoostTimer = kart->mItemEffectData.mKinokoBoostTimer - 1;
        if (kart->mItemEffectData.mKinokoBoostTimer <= 0) {
            kart->mDriveFlags = kart->mDriveFlags & ~(KART_DRIVE_KINOKO_BOOST | KART_DRIVE_ITEM_BOOST);
            kart->mItemEffectData.mKinokoBoostTimer = 0;
        }
    }
    if (!(kart->mMotionFlags & KART_MOTION_START_DONE) && !(kart->mEntryFlags & KART_ENTRY_WIFI_PEER)) {
        AdvanceKartRaceStartBoost(kart);
    }
    if (!(kart->mEffectFlags & KART_EFFECT_RESPAWN_BOOST_WINDOW)) {
        return;
    }
    raceUpdateFrames = GetRaceUpdateFrames();
    if (kart->mRespawnPressRaceFrame == 0) {
        entryIndex = kart->mEntryIndex;
        if ((u16) (gInputSlots[entryIndex].mPressedBits & PAD_KEY_A) != 0) {
            kart->mRespawnPressRaceFrame = raceUpdateFrames;
        }
    }
    if (kart->mRespawnLandRaceFrame == 0) {
        return;
    }
    if (kart->mRespawnPressRaceFrame == 0) {
        return;
    }
    frameDifference = kart->mRespawnPressRaceFrame - kart->mRespawnLandRaceFrame;
    if (frameDifference <= 0) {
        frameDifference = -frameDifference;
    }
    if (frameDifference <= 2) {
        StartKartBoost(kart, KART_BOOST_RESPAWN, 10);
    }
    kart->mEffectFlags = kart->mEffectFlags & ~KART_EFFECT_RESPAWN_BOOST_WINDOW;
}

// Ends the hold TryHoldKartStill started: clears the hold bit and, if the hit link holds an object, moves mPos to the
// link position; also requests surface sound entry 0 while the race runs.
void StopKartStillHold(Kart *kart) {
    if (!(kart->mEffectFlags & KART_EFFECT_GROUND_SOUND_STEP)) {
        if (IsRaceStarted() == 1) {
            AddKartSurfaceSoundRequest(kart, 0);
        }
    }
    kart->mMotionFlags = kart->mMotionFlags & ~KART_MOTION_STILL_HOLD;
    if (kart->mCollisionHitLink->mObject == NULL) {
        return;
    }
    GetCollisionHitLinkPosition(kart->mCollisionHitLink, &kart->mPos);
    kart->mCollisionHitLink->mObject = NULL;
}

void SetKartCourseHitAttributeBit(Kart *kart, u32 hitValue) {
    u32 attributeBit = hitValue & 0x1000000;

    if (attributeBit != kart->mCourseHitAttributeBit) {
        kart->mCourseHitAttributeBit = attributeBit;
    }
}

void AdvanceKartHop(Kart *kart) {
    if (!(kart->mMotionFlags & KART_MOTION_HOP_ACTIVE)) {
        return;
    }
    kart->mHopSpeed = kart->mHopSpeed + kart->mGravity;
    kart->mHopHeight = kart->mHopHeight + kart->mHopSpeed;
    if (kart->mHopHeight < 0) {
        kart->mHopHeight = 0;
        kart->mHopSpeed = 0;
        kart->mMotionFlags = kart->mMotionFlags & ~(KART_MOTION_HOP_ACTIVE | KART_MOTION_HOP_STEER);
    }
}

void AdvanceKartEffects(Kart *kart) {
    KartTurnEffects *turnEffects;
    KartEffects *effects;
    u32 kartFlags;

    if (kart->mEffectFlags & KART_EFFECT_NEAR_PLAYER_RANK) {
        turnEffects = GetKartTurnEffects(kart->mIndex);
        effects = GetKartEffects(kart->mIndex);
        AdvanceKartLevel4Effects(turnEffects, kart);
        AdvanceKartTurnStartEffects(turnEffects, kart);
        AdvanceKartLevel3Effects(turnEffects, effects->mSideDirections, effects->mSidePositions);
        AdvanceKartLevel2Effects(turnEffects, effects->mSideDirections, effects->mSidePositions);
    } else {
        StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    }
    kart->mEffectVelocity = kart->mVelocity;
    kartFlags = kart->mMotionFlags;
    if (kartFlags & KART_MOTION_ON_GROUND) {
        if (!(kartFlags & KART_MOTION_STILL_HOLD)) {
            kart->mEffectVelocity.y = kart->mEffectVelocity.y - kart->mVerticalSpeed;
        }
    }
    kart->mEffectVelocity.x = kart->mEffectVelocity.x >> 4;
    kart->mEffectVelocity.y = kart->mEffectVelocity.y >> 4;
    kart->mEffectVelocity.z = kart->mEffectVelocity.z >> 4;
}

void NNSi_G3dSendJointSRTMaya(NNSG3dJntAnmResult *jntAnmResult) {
    BOOL translationPending;
    u32 resultFlags = jntAnmResult->mFlag;

    translationPending = FALSE;
    if ((resultFlags & 4) == 0) {
        translationPending = TRUE;
    }
    if ((resultFlags & 0x20) && !(resultFlags & 8)) {
        if (translationPending) {
            NNS_G3dGeBufferOP_N(0x1c, &jntAnmResult->mTrans, 3);
            translationPending = FALSE;
        }
        NNS_G3dGeBufferOP_N(0x1b, &jntAnmResult->mScaleEx0, 3);
    }
    if (!(jntAnmResult->mFlag & 2)) {
        if (translationPending) {
            NNS_G3dGeBufferOP_N(0x19, &jntAnmResult->mRot, 0xc);
        } else {
            NNS_G3dGeBufferOP_N(0x1a, &jntAnmResult->mRot, 9);
        }
    } else if (translationPending) {
        NNS_G3dGeBufferOP_N(0x1c, &jntAnmResult->mTrans, 3);
    }
    if (!(jntAnmResult->mFlag & 1)) {
        NNS_G3dGeBufferOP_N(0x1b, &jntAnmResult->mScale, 3);
    }
}

void NNSi_G3dGetJointScaleMaya(NNSG3dJntAnmResult *jntAnmResult, JointScaleValues *scaleValues,
                               JointScaleCommand *command, u32 srtFlags) {
    u8 optionFlags = command->mOptionFlags;
    u32 nodeIndex;

    if (srtFlags & 4) {
        jntAnmResult->mFlag |= 1;
        if (optionFlags & 2) {
            nodeIndex = command->mNodeId;
            NNS_G3dRS->mIsScaleCacheOne[nodeIndex >> 5] |= 1 << (nodeIndex & 0x1f);
        }
    } else {
        jntAnmResult->mScale.x = scaleValues->mScale.x;
        jntAnmResult->mScale.y = scaleValues->mScale.y;
        jntAnmResult->mScale.z = scaleValues->mScale.z;
        if (optionFlags & 2) {
            nodeIndex = command->mNodeId;
            NNS_G3dRS->mIsScaleCacheOne[nodeIndex >> 5] &= ~(1 << (nodeIndex & 0x1f));
            data_usa_021712f0[nodeIndex].mUnk_00.x = scaleValues->mScaleInverse.x;
            data_usa_021712f0[nodeIndex].mUnk_00.y = scaleValues->mScaleInverse.y;
            data_usa_021712f0[nodeIndex].mUnk_00.z = scaleValues->mScaleInverse.z;
        }
    }
    if (optionFlags & 1) {
        nodeIndex = command->mParentId;
        jntAnmResult->mFlag |= 0x20;
        if (NNS_G3dRS->mIsScaleCacheOne[nodeIndex >> 5] & (1 << (nodeIndex & 0x1f))) {
            jntAnmResult->mFlag |= 8;
        } else {
            jntAnmResult->mScaleEx0 = data_usa_021712f0[nodeIndex].mUnk_00;
        }
    }
    jntAnmResult->mFlag |= 0x10;
}

void texmtxCalc_flag_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult) {
    s32 widthFixed = TO_FIXED12(matAnmResult->mUnk_2c);
    s32 heightFixed = TO_FIXED12(matAnmResult->mUnk_2e);
    s32 cosR;
    s32 scaleS;
    s32 sinR;
    s32 scaleT;
    s32 scaleSCos;
    s32 scaleSSin;
    s32 scaleTSin;
    s32 scaleTCos;

    FX_DivAsync(heightFixed, widthFixed);
    cosR = matAnmResult->mUnk_20[1];
    scaleS = matAnmResult->mUnk_18[0];
    sinR = matAnmResult->mUnk_20[0];
    scaleT = matAnmResult->mUnk_18[1];
    scaleSSin = MUL_FIXED12_NO_ROUND(scaleS, sinR);
    scaleSCos = MUL_FIXED12_NO_ROUND(scaleS, cosR);
    scaleTSin = MUL_FIXED12_NO_ROUND(scaleT, sinR);
    scaleTCos = MUL_FIXED12_NO_ROUND(scaleT, cosR);
    matrix->mUnk_00[0].x = scaleSCos;
    matrix->mUnk_00[1].y = scaleTCos;
    matrix->mUnk_00[0].y = -scaleTSin * FX_GetDivResult() >> 12;
    FX_DivAsync(widthFixed, heightFixed);
    matrix->mUnk_00[3].x =
        (matAnmResult->mUnk_2c * (matAnmResult->mUnk_18[0] - (scaleSSin + scaleSCos)) << 3) -
        matAnmResult->mUnk_2c * (s32) ((s64) matAnmResult->mUnk_18[0] * matAnmResult->mUnk_24[0] >> 8);
    matrix->mUnk_00[3].y =
        matAnmResult->mUnk_2e * (s32) ((s64) matAnmResult->mUnk_18[1] * matAnmResult->mUnk_24[1] >> 8) +
        (matAnmResult->mUnk_2e * (scaleTSin - scaleTCos - matAnmResult->mUnk_18[1] + 0x2000) << 3);
    matrix->mUnk_00[1].x = scaleSSin * FX_GetDivResult() >> 12;
}

void texmtxCalc_flagS_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult) {
    s32 widthFixed = TO_FIXED12(matAnmResult->mUnk_2c);
    s32 heightFixed = TO_FIXED12(matAnmResult->mUnk_2e);
    s32 sinPlusCos;

    FX_DivAsync(heightFixed, widthFixed);
    matrix->mUnk_00[0].x = matAnmResult->mUnk_20[1];
    matrix->mUnk_00[1].y = matAnmResult->mUnk_20[1];
    matrix->mUnk_00[0].y = -matAnmResult->mUnk_20[0] * FX_GetDivResult() >> 12;
    FX_DivAsync(widthFixed, heightFixed);
    sinPlusCos = matAnmResult->mUnk_20[0] + matAnmResult->mUnk_20[1];
    matrix->mUnk_00[3].x =
        (matAnmResult->mUnk_2c * (-sinPlusCos + 0x1000) << 3) - (matAnmResult->mUnk_24[0] * matAnmResult->mUnk_2c << 4);
    matrix->mUnk_00[3].y =
        (matAnmResult->mUnk_2e * (matAnmResult->mUnk_20[0] - matAnmResult->mUnk_20[1] + 0x1000) << 3) +
        (matAnmResult->mUnk_24[1] * matAnmResult->mUnk_2e << 4);
    matrix->mUnk_00[1].x = matAnmResult->mUnk_20[0] * FX_GetDivResult() >> 12;
}

void texmtxCalc_flagR_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult) {
    matrix->mUnk_00[0].x = matAnmResult->mUnk_18[0];
    matrix->mUnk_00[1].y = matAnmResult->mUnk_18[1];
    matrix->mUnk_00[0].y = 0;
    matrix->mUnk_00[3].x =
        matAnmResult->mUnk_2c * -(s32) ((s64) matAnmResult->mUnk_18[0] * matAnmResult->mUnk_24[0] >> 8);
    matrix->mUnk_00[3].y =
        matAnmResult->mUnk_2e * (s32) ((s64) matAnmResult->mUnk_18[1] * matAnmResult->mUnk_24[1] >> 8) +
        (matAnmResult->mUnk_2e * (matAnmResult->mUnk_18[1] * -2 + 0x2000) << 3);
    matrix->mUnk_00[1].x = 0;
}

void texmtxCalc_flagRS_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult) {
    matrix->mUnk_00[0].x = 0x1000;
    matrix->mUnk_00[1].y = 0x1000;
    matrix->mUnk_00[0].y = 0;
    matrix->mUnk_00[3].x = -(matAnmResult->mUnk_24[0] * matAnmResult->mUnk_2c) << 4;
    matrix->mUnk_00[3].y = matAnmResult->mUnk_24[1] * matAnmResult->mUnk_2e << 4;
    matrix->mUnk_00[1].x = 0;
}

void texmtxCalc_flagT_(MtxFx44 *matrix, NNSG3dMatAnmResult *matAnmResult) {
    s32 widthFixed = TO_FIXED12(matAnmResult->mUnk_2c);
    s32 heightFixed = TO_FIXED12(matAnmResult->mUnk_2e);
    s32 cosR;
    s32 scaleS;
    s32 sinR;
    s32 scaleT;
    s32 scaleSCos;
    s32 scaleSSin;
    s32 scaleTSin;
    s32 scaleTCos;

    FX_DivAsync(heightFixed, widthFixed);
    cosR = matAnmResult->mUnk_20[1];
    scaleS = matAnmResult->mUnk_18[0];
    sinR = matAnmResult->mUnk_20[0];
    scaleT = matAnmResult->mUnk_18[1];
    scaleSSin = MUL_FIXED12_NO_ROUND(scaleS, sinR);
    scaleSCos = MUL_FIXED12_NO_ROUND(scaleS, cosR);
    scaleTSin = MUL_FIXED12_NO_ROUND(scaleT, sinR);
    scaleTCos = MUL_FIXED12_NO_ROUND(scaleT, cosR);
    matrix->mUnk_00[0].x = scaleSCos;
    matrix->mUnk_00[1].y = scaleTCos;
    matrix->mUnk_00[0].y = -scaleTSin * FX_GetDivResult() >> 12;
    FX_DivAsync(widthFixed, heightFixed);
    matrix->mUnk_00[3].x = matAnmResult->mUnk_2c * (matAnmResult->mUnk_18[0] - (scaleSSin + scaleSCos)) << 3;
    matrix->mUnk_00[3].y = matAnmResult->mUnk_2e * (scaleTSin - scaleTCos - matAnmResult->mUnk_18[1] + 0x2000) << 3;
    matrix->mUnk_00[1].x = scaleSSin * FX_GetDivResult() >> 12;
}
