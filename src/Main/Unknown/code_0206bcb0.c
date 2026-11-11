#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e01f0.h" // CollisionHitLink
#include "01/code_0218155c.h"
#include "code_02147cd8.h"
#include "code_0201c528.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_0206d020.h"
#include "ITCM/code_01ffba68.h"
#include "Main/Unknown/code_020681f0.h"

void AdvanceKartBoost(s32 *acceleration, Kart *kart) {
    int secondArgument;
    u32 flags;
    KartItemEffectState *itemEffectState;
    u16 diffColor;
    u16 emiColor;
    u16 ambColor;

    kart->mBoostTimer = kart->mBoostTimer - 1;
    if (kart->mBoostTimer <= 0) {
        kart->mDriveFlags &= ~(KART_DRIVE_BOOST | KART_DRIVE_RACE_START_BOOST | KART_DRIVE_ITEM_BOOST);
        kart->mBoostTimer = 0;
        if (!(kart->mEntryFlags & KART_ENTRY_SELECTED)) {
            return;
        }
        if (!(kart->mEffectFlags & KART_EFFECT_KILLER)) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
        return;
    }
    *acceleration = 0x1000;
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        secondArgument = (kart->mDriveFlags & KART_DRIVE_RACE_START_BOOST) ? 0xa0 : 0x9e;
        AddSoundRequest(gSoundRequestQueues, GetKartCameraDistanceSquared(kart->mIndex), RequestKartSound, kart,
                        secondArgument);
    }
    if (!(kart->mDriveFlags & KART_DRIVE_ITEM_BOOST)) {
        return;
    }
    SkipOrthoQuadsHoldAndSetVelocities(kart->mIndex);
    flags = kart->mEffectFlags;
    if (flags & KART_EFFECT_COURSE_COLORED) {
        return;
    }
    if (!(flags & KART_EFFECT_GESSO)) {
        return;
    }
    itemEffectState = &kart->mItemEffectData;
    if (itemEffectState->mGessoFrames > 400) {
        return;
    }
    itemEffectState->mGessoFrames = 400;
    kart->mEffectFlags |= KART_EFFECT_COURSE_COLORED;
    diffColor = GetKartCourseDiffColor();
    emiColor = GetKartCourseEmiColor();
    ambColor = GetKartCourseAmbColor();
    StartKartModelColorBlend(kart->mKartModelsEntry, diffColor, emiColor, ambColor);
}

void EndKartDrift(Kart *kart) {
    if (!(kart->mMotionFlags & KART_MOTION_ON_GROUND)) {
        kart->mMotionFlags |= KART_MOTION_DRIFT_ENDED_IN_AIR;
    }
    if (kart->mDriftCharge == 4) {
        StartKartBoost(kart, KART_BOOST_MINI_TURBO, kart->mPhysicalParam->mMiniTurboFrames);
        kart->mDriveFlags |= KART_DRIVE_MINI_TURBO;
        kart->mMiniTurboTimer = kart->mPhysicalParam->mMiniTurboFrames;
        if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
            GetEntryKartCounters()->mMiniTurboCount++;
            if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
                AddMissionRunCountForKind4();
            }
        }
    }
    kart->mMotionFlags &=
        ~(KART_MOTION_DRIFT_ARMED | KART_MOTION_HOPPING | KART_MOTION_DRIFTING | KART_MOTION_HOP_STEER);
    kart->mTurnDirection = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
}

void AdvanceKartDriftTurnAngle(Kart *kart, int fromLowSpeedTurn) {
    if (kart->mTurnDirection > 0) {
        if (kart->mTurnAngle > 11000) {
            kart->mTurnAngle = kart->mTurnAngle - 200;
            if (kart->mTurnAngle < 11000) {
                kart->mTurnAngle = 11000;
            }
        } else if (kart->mTurnAngle < 11000) {
            kart->mTurnAngle += 375;
            if (kart->mTurnAngle > 11000) {
                kart->mTurnAngle = 11000;
            }
        }
    } else {
        if (kart->mTurnAngle < -11000) {
            kart->mTurnAngle = kart->mTurnAngle + 200;
            if (kart->mTurnAngle > -11000) {
                kart->mTurnAngle = -11000;
            }
        } else if (kart->mTurnAngle > -11000) {
            kart->mTurnAngle -= 375;
            if (kart->mTurnAngle < -11000) {
                kart->mTurnAngle = -11000;
            }
        }
    }
    if (fromLowSpeedTurn != 0) {
        return;
    }
    if (kart->mDriftHeadingAnglePerFrame <= 50) {
        kart->mDriftHeadingAnglePerFrame = 50;
    } else {
        kart->mDriftHeadingAnglePerFrame = MUL_FIXED12_NO_ROUND(kart->mDriftHeadingAnglePerFrame, 0xf33);
    }
    AdvanceKartDriftCharge(kart);
    if (!(kart->mMotionFlags & KART_MOTION_ON_GROUND)) {
        return;
    }
    AddKartSurfaceSoundRequest(kart, 1);
    kart->mEffectFlags |= KART_EFFECT_GROUND_SOUND_STEP;
    if (kart->mDriftCharge < 3) {
        return;
    }
    if (!(kart->mEntryFlags & KART_ENTRY_SELECTED)) {
        return;
    }
    StartSoundWhileRequested(&kart->mSoundSource, 0xd1, 0x7f, 0);
}

// Drift step: the hop, the turn held after it, the charge, and the release with the mini-turbo.
void AdvanceKartDrift(Kart *kart) {
    u32 bits44 = kart->mMotionFlags;
    BOOL hasB = (bits44 & KART_MOTION_HOPPING) != 0;
    u32 value;
    KartTurnEffects *turnEffects;
    int distanceSquared;
    enum { K0 } entryIndex;

    if (kart->mEntryFlags & KART_ENTRY_WIFI_PEER) {
        return;
    }
    if (kart->mAirborneFrames >= 5 &&
        !(bits44 & (KART_MOTION_HOPPING | KART_MOTION_DRIFTING | KART_MOTION_ON_GROUND))) {
        entryIndex = kart->mEntryIndex;
        if ((u16) (gInputSlots[entryIndex].mBits & PAD_KEY_R)) {
            if (bits44 & KART_MOTION_DRIFT_ARMED) {
                goto recheck;
            }
            if (kart->mTurnDirection != 0) {
                goto recheck;
            }
            value = kart->mDriveFlags;
            if (value & KART_DRIVE_TURN_RIGHT) {
                kart->mTurnDirection = 1;
                kart->mMotionFlags |= KART_MOTION_DRIFT_ARMED;
            } else if (value & KART_DRIVE_TURN_LEFT) {
                kart->mTurnDirection = -1;
                kart->mMotionFlags |= KART_MOTION_DRIFT_ARMED;
            }
        } else {
            kart->mMotionFlags &= ~KART_MOTION_DRIFT_ARMED;
        }
    }
recheck:
    if (kart->mMotionFlags & KART_MOTION_HOPPING) {
        if (kart->mTurnDirection == 0) {
            value = kart->mDriveFlags;
            if (value & KART_DRIVE_TURN_RIGHT) {
                kart->mTurnDirection = 1;
            } else if (value & KART_DRIVE_TURN_LEFT) {
                kart->mTurnDirection = -1;
            }
        }
    }
    bits44 = kart->mMotionFlags;
    value = kart->mTurnDirection;
    if (!(bits44 & KART_MOTION_DRIFTING) && (bits44 & KART_MOTION_ON_GROUND)) {
        if ((bits44 & (KART_MOTION_DRIFT_ARMED | KART_MOTION_HOPPING)) &&
            kart->mVelocityLength > MUL_FIXED12_NO_ROUND(kart->mPhysicalParam->mBaseSpeedLimit, 0x8cd) && value != 0 &&
            (u16) (gInputSlots[entryIndex = kart->mEntryIndex].mBits & PAD_KEY_R)) {
            kart->mMotionFlags |= KART_MOTION_DRIFTING;
            kart->mDriftCharge = 1;
            if (kart->mTurnDirection > 0) {
                kart->mAwayTurnCounter = &kart->mLeftTurnCount;
                kart->mTowardTurnCounter = &kart->mRightTurnCount;
            } else {
                kart->mAwayTurnCounter = &kart->mRightTurnCount;
                kart->mTowardTurnCounter = &kart->mLeftTurnCount;
            }
            if (kart->mEffectFlags & KART_EFFECT_NEAR_PLAYER_RANK) {
                turnEffects = GetKartTurnEffects(kart->mIndex);
                ResetKartLevel4Effects(turnEffects);
                StartKartTurnStartEffects(turnEffects);
            }
        } else {
            kart->mTurnDirection = 0;
        }
        kart->mMotionFlags &= ~(KART_MOTION_DRIFT_ARMED | KART_MOTION_HOPPING | KART_MOTION_HOP_STEER);
    }
    bits44 = kart->mMotionFlags;
    if (bits44 & KART_MOTION_DRIFTING) {
        entryIndex = kart->mEntryIndex;
        if (!((u16) (gInputSlots[entryIndex].mBits & PAD_KEY_R) && (kart->mDriveFlags & KART_DRIVE_ACCEL_HELD) &&
              kart->mVelocityLength >= kart->mPhysicalParam->mBaseSpeedLimit / 2 &&
              !(bits44 & (KART_MOTION_OBJECT_CONTACT | KART_MOTION_COURSE_CONTACT | KART_MOTION_DRIFT_BREAK)))) {
            if (!(bits44 & KART_MOTION_ON_GROUND)) {
                kart->mMotionFlags |= KART_MOTION_DRIFT_ENDED_IN_AIR;
            }
            if (kart->mDriftCharge == 4) {
                StartKartBoost(kart, KART_BOOST_MINI_TURBO, kart->mPhysicalParam->mMiniTurboFrames);
                kart->mDriveFlags |= KART_DRIVE_MINI_TURBO;
                kart->mMiniTurboTimer = kart->mPhysicalParam->mMiniTurboFrames;
                if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
                    GetEntryKartCounters()->mMiniTurboCount++;
                    if (gRaceSetup->mMode == MODE_MISSION_RUN && gRaceSetup->mMode == MODE_MISSION_RUN) {
                        AddMissionRunCountForKind4();
                    }
                }
            }
            kart->mMotionFlags &=
                ~(KART_MOTION_DRIFT_ARMED | KART_MOTION_HOPPING | KART_MOTION_DRIFTING | KART_MOTION_HOP_STEER);
            kart->mTurnDirection = 0;
            kart->mDriftCharge = 0;
            kart->mRightTurnCount = 0;
            kart->mLeftTurnCount = kart->mRightTurnCount;
            kart->mTurnCountTimer = 0;
            StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
        } else if (bits44 & KART_MOTION_ON_GROUND) {
            AdvanceKartDriftTurnAngle(kart, 0);
        }
    }
    if (hasB && (kart->mMotionFlags & KART_MOTION_ON_GROUND)) {
        int turn = 0;
        int dot;
        int ang;
        int len;
        Vec3 projectedForward;
        Vec3 crossVector;
        Vec3 *forward = &kart->mUnk_138;

        dot = VEC_DotProduct(&kart->mHopStartUp, forward);
        projectedForward.x = kart->mUnk_138.x - MUL_FIXED12_NO_ROUND(kart->mHopStartUp.x, dot);
        projectedForward.y = forward->y - MUL_FIXED12_NO_ROUND(kart->mHopStartUp.y, dot);
        projectedForward.z = forward->z - MUL_FIXED12_NO_ROUND(kart->mHopStartUp.z, dot);
        if (LENGTH_SQUARED(projectedForward) >= 16
                ? Vec3NormalizeAndGetLengthUnchecked(&projectedForward, &projectedForward)
                : 0) {
            Vec3CrossUnrounded(&kart->mHopStartForward, &projectedForward, &crossVector);
            len = VEC_Mag(&crossVector);
            ang = FX_Atan2(len, Vec3DotUnrounded(&kart->mHopStartForward, &projectedForward));
            turn = (s16) (((s64) ang * 0x28be60db9391LL + 0x80000000LL) >> 44);
        }
        if (kart->mForwardSpeed < 0) {
            value = -value;
        }
        kart->mTurnAngle += (s16) (turn * value);
        if (kart->mTurnAngle > 0x2af8) {
            kart->mTurnAngle = 0x2af8;
        } else if (kart->mTurnAngle < -0x2af8) {
            kart->mTurnAngle = -0x2af8;
        }
        if (!(kart->mMotionFlags & KART_MOTION_DRIFTING)) {
            return;
        }
        kart->mDriftHeadingAnglePerFrame = MUL_FIXED12_NO_ROUND(kart->mVelocityLength, 0x1a);
        return;
    }
    entryIndex = kart->mEntryIndex;
    if (!(u16) (gInputSlots[entryIndex].mPressedBits & PAD_KEY_R)) {
        if (!(kart->mMotionFlags & KART_MOTION_AI_DRIFT_REQUEST)) {
            return;
        }
    }
    if (kart->mEffectFlags & KART_EFFECT_KILLER) {
        return;
    }
    if (!(kart->mMotionFlags & KART_MOTION_ON_GROUND)) {
        return;
    }
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        distanceSquared = GetKartCameraDistanceSquared(kart->mIndex);
        AddSoundRequest(&data_0217d284, distanceSquared + GetKartFullVolumeSoundSortOffset(), KartStartSoundFullVolume,
                        kart, 0xcf);
    }
    kart->mMotionFlags |= KART_MOTION_HOPPING | KART_MOTION_HOP_ACTIVE | KART_MOTION_HOP_STEER;
    kart->mMotionFlags &= ~(KART_MOTION_DRIFTING | KART_MOTION_DRIFT_ENDED_IN_AIR);
    kart->mHopSpeed = 0x1405;
    kart->mVerticalSpeed += 0x21a2;
    kart->mHopHeight = 0;
    kart->mTurnDirection = 0;
    kart->mDriftHeadingAnglePerFrame = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    GetKartForward(kart, &kart->mHopStartForward);
    GetKartUp(kart, &kart->mHopStartUp);
    if (kart->mCollisionHitLink->mObject != NULL) {
        kart->mCollisionHitLink->mObject = NULL;
    }
    if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        kart->mParticipantRecordData->mEventToggleFlags ^= 0x1;
    }
}

// At low speed, with the A and B keys held and no boost running, steers the kart with the left and right keys; TRUE
// when it acts.
int TryTurnKartAtLowSpeed(Kart *kart) {
    BOOL result = FALSE;
    BOOL pending = TRUE;
    BOOL dir = FALSE;
    int delta;
    u16 bits;
    KartTurnEffects *turnEffects;
    enum { K0 } entryIndex;

    if (kart->mVelocityLength < 0x1800 && (kart->mDriveFlags & KART_DRIVE_BRAKING)) {
        kart->mTurnDirection = 0;
        result = TRUE;
        pending = FALSE;
        entryIndex = kart->mEntryIndex;
        bits = gInputSlots[entryIndex].mBits;
        if ((u16) (bits & PAD_KEY_LEFT)) {
            dir = TRUE;
            kart->mTurnDirection = -1;
            delta = 500;
        } else if ((u16) (bits & PAD_KEY_RIGHT)) {
            dir = TRUE;
            kart->mTurnDirection = 1;
            delta = -500;
        }
        if (kart->mMotionFlags & KART_MOTION_ON_GROUND) {
            if (GetKartTurnEffects(kart->mIndex)->mTurnStartPresent == 0 &&
                (kart->mEffectFlags & KART_EFFECT_NEAR_PLAYER_RANK)) {
                turnEffects = GetKartTurnEffects(kart->mIndex);
                ResetKartLevel4Effects(turnEffects);
                StartKartTurnStartEffects(turnEffects);
            }
            kart->mDriveFlags |= KART_DRIVE_LOW_SPEED_TURN;
            if (kart->mTurnDirection != 0) {
                kart->mMotionFlags |= KART_MOTION_LOW_SPEED_TURN;
                kart->mHeadingAngle += delta;
                AdvanceKartDriftTurnAngle(kart, 1);
            }
        }
        StartKartLowSpeedTurnSound(kart, dir, kart->mSurfaceKind, kart->mSurfaceVariant);
    }
    if (pending) {
        StopKartTurnStartEffects(GetKartTurnEffects(kart->mIndex));
    }
    return result;
}

void SetEffectScaleFromKart(ParticleEmitter *emitter, Kart *kart) {
    SetEffectScaleFromKartScaleZ(emitter, kart);
}

void SetEffectVelocityFromKart(ParticleEmitter *emitter, Kart *kart) {
    emitter->mVelocity = kart->mEffectVelocity;
    SetEffectScaleFromKartScaleZ(emitter, kart);
}

// Starts the effects of a kart-kart hit at the contact point; flag picks the four-effect set.
BOOL TryStartKartCollisionEffects(Kart *kart, const Vec3 *overlapDirection, int flag) {
    if (kart->mEntryFlags & KART_ENTRY_HAS_CHARACTER_ANIMATION) {
        int fourEffectIds[4] = {0x77, 0x76, 0x78, 0x79};
        u16 effectIndex = 0;
        u32 effectCount = 1;
        int *effectIds = data_02154f10;
        Vec3 contactPoint;

        if (flag) {
            effectIds = fourEffectIds;
            effectCount = 4;
        }
        VEC_MultAdd(-kart->mRadius, overlapDirection, &kart->mPos, &contactPoint);
        VEC_MultAdd(MUL_FIXED12_ROUNDED(kart->mScale.y, 0x8000), &kart->mUnk_12c, &contactPoint, &contactPoint);
        for (; effectIndex < effectCount; effectIndex++) {
            StartEffectWithCallback(effectIds[effectIndex], &contactPoint, kart, SetEffectVelocityFromKart);
        }
        return TRUE;
    }
    return FALSE;
}

void SetEffectFlatVelocityFromKart(ParticleEmitter *emitter, Kart *kart) {
    Vec3 velocity = kart->mEffectVelocity;

    velocity.y = 0;
    velocity.x = MUL_FIXED12_NO_ROUND(velocity.x, 0xe66);
    velocity.y = MUL_FIXED12_NO_ROUND(velocity.y, 0xe66);
    velocity.z = MUL_FIXED12_NO_ROUND(velocity.z, 0xe66);
    emitter->mVelocity = velocity;
}

void PlaceEffectBehindKart(ParticleEmitter *emitter, Kart *kart) {
    Vec3 position = kart->mPos;
    Vec3s16 rot;
    Vec3 *forward;

    VEC_MultAdd(MUL_FIXED12_ROUNDED(kart->mRadius, -0x1333), &kart->mUnk_138, &position, &position);
    position.x >>= 4;
    position.y >>= 4;
    position.z >>= 4;
    emitter->mUnk_28.x = emitter->mUnk_20->mUnk_00->mUnk_04.x + position.x;
    emitter->mUnk_28.y = position.y + emitter->mUnk_20->mUnk_00->mUnk_04.y;
    emitter->mUnk_28.z = position.z + emitter->mUnk_20->mUnk_00->mUnk_04.z;
    forward = &kart->mUnk_138;
    rot.x = forward->x;
    rot.y = forward->y;
    rot.z = forward->z;
    emitter->mDirection = rot;
}

void StartKartBlink(Kart *kart) {
    if (kart->mEntryFlags & KART_ENTRY_BATTLE_REMOVAL) {
        return;
    }
    kart->mEffectFlags |= KART_EFFECT_BLINK_GUARD;
    kart->mBlinkCycleFrames = 0;
    kart->mBlinkFrames = kart->mBlinkCycleFrames;
}

void SetupKartAiHeldItemEntry(Kart *kart) {
    if (kart->mEntryFlags & KART_ENTRY_CPU) {
        CallKartAiSetupHeldItemEntry(kart->mAi);
    }
}

void SetupKartAiItemInUseEntry(Kart *kart) {
    if (kart->mEntryFlags & KART_ENTRY_CPU) {
        CallKartAiSetupItemInUseEntry(kart->mAi);
    }
}

// TRUE for a removed, Boo or respawning kart, or any state but normal driving.
BOOL IsKartNotNormal(Kart *kart) {
    if ((kart->mEntryFlags & KART_ENTRY_REMOVED_PARKED_OR_TERESA) || (kart->mEffectFlags & KART_EFFECT_RESPAWN_DROP) ||
        kart->mState != KART_STATE_NORMAL) {
        return TRUE;
    }
    return FALSE;
}

// TRUE for a removed kart or one in the respawn drop.
BOOL IsKartRemovedOrRespawning(Kart *kart) {
    if ((kart->mEntryFlags & KART_ENTRY_REMOVED_OR_PARKED) || (kart->mEffectFlags & KART_EFFECT_RESPAWN_DROP)) {
        return TRUE;
    }
    return FALSE;
}

int GetKartCourseHitAttributeBit(Kart *kart) {
    return kart->mCourseHitAttributeBit;
}

BOOL IsKartOutOfView(Kart *kart) {
    return (kart->mEffectFlags & KART_EFFECT_OUT_OF_VIEW) != 0;
}

void StartKartState(Kart *kart, KartState mode) {
    kart->mDriveFlags &= ~(KART_DRIVE_BOOST | KART_DRIVE_RACE_START_BOOST | KART_DRIVE_MINI_TURBO |
                           KART_DRIVE_KINOKO_BOOST | KART_DRIVE_ITEM_BOOST);
    kart->mBoostTimer = 0;
    kart->mItemEffectData.mKinokoBoostTimer = 0;
    kart->mMiniTurboTimer = 0;
    if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
        if (!(kart->mEffectFlags & KART_EFFECT_KILLER) && !(kart->mDriveFlags & KART_DRIVE_SCALE_TABLE_EFFECT)) {
            ResetCameraHalfFovAngleGoal();
        }
        StopDispCapBlend();
    }
    SetKartCharacterAnimation(kart, 1, 0);
    kart->mState = mode;
    kart->mMotionFlags &=
        ~(KART_MOTION_DRIFT_ARMED | KART_MOTION_HOPPING | KART_MOTION_DRIFTING | KART_MOTION_HOP_STEER);
    kart->mTurnDirection = 0;
    kart->mDriftCharge = 0;
    kart->mRightTurnCount = 0;
    kart->mLeftTurnCount = kart->mRightTurnCount;
    kart->mTurnCountTimer = 0;
    StopKartTurnEffects(GetKartTurnEffects(kart->mIndex));
    if (kart->mEffectFlags & KART_EFFECT_AHEAD_BOOST) {
        kart->mEffectFlags &= ~KART_EFFECT_AHEAD_BOOST;
        kart->mAheadSpeedLimitFactor = 0x1000;
        if (!(kart->mEffectFlags & KART_EFFECT_GESSO)) {
            ResetKartModelsCourseColors(kart);
        }
        StopKartNearRankEffect(kart);
    }
}

BOOL TryStartKartState(Kart *kart, KartState newState) {
    BOOL ok;
    BOOL res;
    BOOL flag;
    int currentState;
    u32 bits4c = kart->mEffectFlags;

    if (bits4c & KART_EFFECT_BLINK_GUARD) {
        ok = FALSE;
    } else if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING) &&
            !(bits4c & KART_EFFECT_STAR_OR_KILLER)) {
            ok = TRUE;
        } else {
            ok = FALSE;
        }
    } else {
        switch (newState) {
            case KART_STATE_1:
            case KART_STATE_SPIN:
                res = TRUE;
                if (!(bits4c & KART_EFFECT_STAR_OR_KILLER) && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING)) {
                    currentState = kart->mState;
                    flag = FALSE;
                    if (currentState != KART_STATE_NORMAL && currentState != KART_STATE_1 &&
                        currentState != KART_STATE_SPIN) {
                        flag = TRUE;
                    }
                    if (flag == FALSE) {
                        res = FALSE;
                    }
                }
                ok = res == FALSE;
                break;
            default:
                res = TRUE;
                if (!(bits4c & KART_EFFECT_STAR_OR_KILLER) && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING)) {
                    currentState = kart->mState;
                    flag = FALSE;
                    if (currentState != KART_STATE_NORMAL && currentState != KART_STATE_1 &&
                        currentState != KART_STATE_SPIN) {
                        flag = TRUE;
                    }
                    if (flag == FALSE) {
                        res = FALSE;
                    }
                }
                ok = res == FALSE;
                break;
        }
    }
    if (!ok) {
        return FALSE;
    }
    StartKartState(kart, newState);
    return TRUE;
}

// Starts a spin, or adds a turn to the spin already running.
BOOL TrySpinKart(Kart *kart, int rotationCount, int skipSound) {
    int currentState = kart->mState;
    BOOL notSpinning;
    BOOL ok;
    BOOL res;
    BOOL flag;
    int state;
    u32 bits4c;

    notSpinning = currentState != KART_STATE_1 && currentState != KART_STATE_SPIN;
    if (notSpinning == FALSE) {
        if (kart->mYRotationCount * 0xffff - kart->mYRotationAngleSum > 0xffff ||
            (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL)) {
            return FALSE;
        }
    }
    bits4c = kart->mEffectFlags;
    if (bits4c & KART_EFFECT_BLINK_GUARD) {
        ok = FALSE;
    } else if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
        if (kart->mState == KART_STATE_NORMAL && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING) &&
            !(bits4c & KART_EFFECT_STAR_OR_KILLER)) {
            ok = TRUE;
        } else {
            ok = FALSE;
        }
    } else {
        res = TRUE;
        if (!(bits4c & KART_EFFECT_STAR_OR_KILLER) && !(kart->mDriveFlags & KART_DRIVE_RESPAWNING)) {
            state = kart->mState;
            flag = FALSE;
            if (state != KART_STATE_NORMAL && currentState != KART_STATE_1 && currentState != KART_STATE_SPIN) {
                flag = TRUE;
            }
            if (flag == FALSE) {
                res = FALSE;
            }
        }
        ok = res == FALSE;
    }
    if (!ok) {
        return FALSE;
    }
    if (notSpinning) {
        StartKartState2(kart, rotationCount, skipSound);
        if (skipSound == 0) {
            if (rotationCount == 1) {
                if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
                    kart->mParticipantRecordData->mEventToggleFlags ^= 0x4;
                }
            } else if (rotationCount == 2) {
                if (kart->mEntryFlags & KART_ENTRY_WIFI_LOCAL) {
                    kart->mParticipantRecordData->mEventToggleFlags ^= 0x8;
                }
            }
        }
    } else {
        kart->mYRotationCount++;
    }
    return TRUE;
}
