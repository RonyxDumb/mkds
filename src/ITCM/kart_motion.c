#include "ITCM/kart_motion.h"
#include "ITCM/kart_ground_contact.h"
#include "ITCM/kart_with_course.h"
#include "ITCM/code_01ffb000.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Kart/karts.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "Main/Race/data_021759c0.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Kart/kart_reset.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Race/race.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Sound/code_0210ab48.h"
#include "Main/Sound/sound_request_queue.h"
#include "Main/Sound/kart_sound.h"
#include "Main/Kart/kart_effects.h"
#include "Main/Kart/code_02066ac0.h"
#include "ITCM/kart_velocity.h"
#include "code_02147cd8.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "Main/Menu/data_02175628.h"
#include "frameheap.h"
#include "os_thread.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/Sound/data_0216c000.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Sound/map_object_sound_counter.h"
#include "Main/System/init_after_startup.h"

void QuaternionMultiply(const Vec4 *left, const Vec4 *right, Vec4 *result) {
    Vec4 product;

    product.x = (left->w * right->x + left->x * right->w + (left->y * right->z - left->z * right->y)) >> 12;
    product.y = (left->w * right->y + left->y * right->w + (left->z * right->x - left->x * right->z)) >> 12;
    product.z = (left->w * right->z + left->z * right->w + (left->x * right->y - left->y * right->x)) >> 12;
    product.w = (left->w * right->w - (left->x * right->x + left->y * right->y + left->z * right->z)) >> 12;
    *result = product;
}

void QuaternionBlend(Vec4 *start, const Vec4 *end, Vec4 *result, s32 blend) {
    result->x = start->x + ((blend * (end->x - start->x)) >> 12);
    result->y = start->y + ((blend * (end->y - start->y)) >> 12);
    result->z = start->z + ((blend * (end->z - start->z)) >> 12);
    result->w = start->w + ((blend * (end->w - start->w)) >> 12);
}

void Matrix4x3FromQuaternion(MtxFx43 *mtx, const Vec4 *quat) {
    s32 *elements = &mtx->mRows[0].x;
    s32 quatX;
    s32 quatY;
    s32 quatZ;
    s32 quatW;
    s32 zx;
    s32 xx;
    s32 ww;
    s32 yy;
    s32 zw;
    s32 zy;
    s32 wx;
    s32 wy;
    s32 xy;

    quatX = quat->x;
    quatY = quat->y;
    quatZ = quat->z;
    quatW = quat->w;
    zx = quatW * quatY >> 11;
    xx = quatY * quatY >> 11;
    ww = quatX * quatX >> 11;
    yy = quatZ * quatZ >> 11;
    zw = quatW * quatX >> 11;
    zy = quatW * quatZ >> 11;
    wx = quatX * quatY >> 11;
    wy = quatX * quatZ >> 11;
    xy = quatY * quatZ >> 11;
    elements[0] = 0x1000 - (xx + yy);
    elements[1] = wx + zy;
    elements[2] = wy - zx;
    elements[3] = wx - zy;
    elements[4] = 0x1000 - (yy + ww);
    elements[5] = xy + zw;
    elements[6] = wy + zx;
    elements[7] = xy - zw;
    elements[8] = 0x1000 - (ww + xx);
    elements[9] = 0;
    elements[10] = 0;
    elements[11] = 0;
}

void Matrix3x3FromQuaternion(MtxFx33 *mtx, void *quatPtr) {
    s32 *elements = &mtx->mRows[0].x;
    const Vec4 *quat = quatPtr;
    s32 quatX;
    s32 quatY;
    s32 quatZ;
    s32 quatW;
    s32 zx;
    s32 xx;
    s32 ww;
    s32 yy;
    s32 zw;
    s32 zy;
    s32 wx;
    s32 wy;
    s32 xy;

    quatX = quat->x;
    quatY = quat->y;
    quatZ = quat->z;
    quatW = quat->w;
    zx = quatW * quatY >> 11;
    xx = quatY * quatY >> 11;
    ww = quatX * quatX >> 11;
    yy = quatZ * quatZ >> 11;
    zw = quatW * quatX >> 11;
    zy = quatW * quatZ >> 11;
    wx = quatX * quatY >> 11;
    wy = quatX * quatZ >> 11;
    xy = quatY * quatZ >> 11;
    elements[0] = 0x1000 - (xx + yy);
    elements[1] = wx + zy;
    elements[2] = wy - zx;
    elements[3] = wx - zy;
    elements[4] = 0x1000 - (yy + ww);
    elements[5] = xy + zw;
    elements[6] = wy + zx;
    elements[7] = xy - zw;
    elements[8] = 0x1000 - (ww + xx);
}

void AdvanceKartMotion(Kart *kart) {
    if (kart->mEntryFlags & (KART_ENTRY_REMOVED | KART_ENTRY_SCALING_IN)) {
        AdvanceKartScaleFactor(kart);
        return;
    }
    ResetKartTurnAndRadius(kart);
    UpdateKartSpeedLimitGoal(kart);
    AdvanceKartAi(kart);
    UpdateKartSpeedLimit(kart);
    UpdateKartForwardAndLengthRatio(kart);
    AdvanceKartInputAndTurn(kart);
    AdvanceKartBoosts(kart);
    if (kart->mDriveFlags & KART_DRIVE_KEYED_PLACEMENT) {
        AdvanceKartToKeyedPlacement(kart);
    } else {
        AdvanceKartByVelocity(kart);
    }
}

void AdvanceKartCollision(Kart *kart) {
    Vec3 groundNormal;

    if (kart->mEntryFlags & KART_ENTRY_REMOVED) {
        return;
    }
    if (kart->mMotionFlags & KART_MOTION_NEAR_KART) {
        kart->mMotionFlags |= KART_MOTION_NEAR_KART_HELD;
    } else {
        kart->mMotionFlags &= ~KART_MOTION_NEAR_KART_HELD;
    }
    ComputeKartCollisionCenter(&kart->mCollisionCenter, &kart->mDrawMatrixPos, 0x400, kart);
    CollideKartWithCourse(kart, &groundNormal);
    AdvanceKartOrientation(kart, &groundNormal);
    kart->mGroundNormal = groundNormal;
    kart->mCollisionStepFrames = kart->mCollisionStepFrames + 1;
    if (kart->mEffectFlags & KART_EFFECT_NEAR_PLAYER_RANK) {
        ComputeKartSidePoints(kart);
    }
    if ((kart->mEntryFlags & KART_ENTRY_SELECTED) && IsRaceStarted() == 1) {
        SetKartKind3ShapeListMask(kart->mIndex);
    }
    UpdateKartSoundWrapper(kart);
    AdvanceKartCollisionTimer(kart);
    if (kart->mEffectFlags & KART_EFFECT_MODEL_SCALE_ANIM) {
        AdvanceKartModelScaleAnimation(kart);
    }
    kart->mAdvanceOffsetCycle(kart);
}

void UpdateKartPrevValuesAndClearFlags(Kart *kart) {
    kart->mTestedKartMask = 0;
    kart->mMotionFlags &=
        ~(KART_MOTION_NEAR_KART | KART_MOTION_LOW_SPEED_TURN | KART_MOTION_AI_DRIFT_REQUEST | KART_MOTION_STATE_RESET);
    kart->mEffectFlags &=
        ~(KART_EFFECT_GROUND_SOUND_STEP | KART_EFFECT_SHRINK_ANIMATING | KART_EFFECT_NEAR_PLAYER_RANK |
          KART_EFFECT_ONE_RANK_BEHIND_PLAYER | KART_EFFECT_KART_OVERLAP);
    kart->mPrevNearKartMask = kart->mNearKartMask;
    kart->mNearKartMask = 0;
    kart->mPrevPos = kart->mPos;
    kart->mPrevPointAlongUp = kart->mPointAlongUp;
    kart->mPrevPrevHitVelocity = kart->mPrevHitVelocity;
    kart->mPrevHitVelocity = kart->mHitVelocity;
    kart->mSlotFunctions[5](kart);
}

static inline const s32 GetTurnHeadingEaseFactor(void) {
    return gTurnHeadingEaseFactor;
}

void ResetKartTurnAndRadius(Kart *kart) {
    kart->mDriveFlags &= ~(KART_DRIVE_TURN_LEFT | KART_DRIVE_TURN_RIGHT);
    kart->mRadius = MUL_FIXED12_NO_ROUND(kart->mRadiusFactor,
                                         MUL_FIXED12_NO_ROUND(kart->mPhysicalParam->mRadius, kart->mShrinkFactor));
    kart->mScaledPointAlongUpExtra = MUL_FIXED12_NO_ROUND(kart->mPhysicalParam->mPointAlongUpExtra, kart->mScale.z);
    kart->mTurnHeadingAnglePerFrameGoal = 0;
}

void AddKartSurfaceSoundRequest(Kart *kart, s32 entryIndex) {
    s32 sortOffset;
    s32 queueIndex;
    s32 kartCameraDistanceSquared;

    queueIndex = (kart->mEntryFlags & KART_ENTRY_SELECTED) ? 3 : 2;
    sortOffset = gKartSurfaceSoundSortOffsets[entryIndex];
    kartCameraDistanceSquared = GetKartCameraDistanceSquared(kart->mIndex);
    AddSoundRequest(&(gSoundRequestQueues)[queueIndex], kartCameraDistanceSquared + sortOffset,
                    StartKartSurfaceSoundWhileRequestedFromKart, kart, entryIndex);
}

s32 AdvanceKartRank(Kart *kart) {
    BOOL passedKart;
    s32 newRank;
    s32 aheadKartIndex;
    Kart *aheadKart;

    passedKart = FALSE;
    newRank = GetKartRank(kart->mIndex);
    if (newRank != kart->mRank) {
        if (kart->mEntryFlags & KART_ENTRY_SELECTED) {
            SetSceneSoundRank((newRank - 1));
        }
        if (newRank < kart->mRank && newRank < gRaceSetup->mKartCount) {
            aheadKartIndex = GetKartAtRank(newRank + 1);
            if (aheadKartIndex >= 0) {
                aheadKart = GetKart((u16) aheadKartIndex);
                if (!(aheadKart->mEntryFlags & (KART_ENTRY_GHOST | KART_ENTRY_TERESA | KART_ENTRY_PARKED))) {
                    passedKart = TRUE;
                }
            }
        }
    }
    kart->mRank = newRank;
    return passedKart;
}

void UpdateKartSoundWrapper(Kart *kart) {
    UpdateKartSound(kart);
}

void AdvanceKartCollisionTimer(Kart *kart) {
    if (kart->mKartCollisionTimer <= 0) {
        return;
    }
    kart->mKartCollisionTimer = kart->mKartCollisionTimer - 1;
    if (kart->mKartCollisionTimer > 0) {
        return;
    }
    StartKartCollisionSound(kart, kart->mSoundIndex, kart->mKartIndexModThree);
    kart->mKartCollisionTimer = 0;
}

void AdvanceKartInputAndTurn(Kart *kart) {
    s32 inputValue;
    s32 lowSpeedTurn;
    enum { ENTRY_INDEX_FIRST } entryIndex;

    if (kart->mDriveFlags & KART_DRIVE_STATE_END_TIMER) {
        kart->mStateEndTimer = kart->mStateEndTimer - 1;
        if (kart->mStateEndTimer <= 0) {
            kart->mStateEndTimer = 0;
            kart->mDriveFlags &= ~(KART_DRIVE_STATE_END_TIMER | KART_DRIVE_INPUT_LOCKED);
        }
    }
    if (IsRaceStarted() == 1) {
        inputValue = 0;
        if (IsKartNotNormalOrFlagged(kart) != FALSE) {
            entryIndex = kart->mEntryIndex;
            gInputSlots[entryIndex].mBitMask = PAD_KEY_Y | PAD_KEY_X | PAD_KEY_L | PAD_KEY_SELECT;
            if (kart->mEffectFlags & KART_EFFECT_KILLER) {
                entryIndex = kart->mEntryIndex;
                gInputSlots[entryIndex].mBitMask =
                    PAD_KEY_Y | PAD_KEY_X | PAD_KEY_L | PAD_KEY_LEFT | PAD_KEY_RIGHT | PAD_KEY_SELECT;
            }
            if (kart->mDriveFlags & KART_DRIVE_RESPAWN_LANDING) {
                entryIndex = kart->mEntryIndex;
                gInputSlots[entryIndex].mBitMask = PAD_KEY_Y | PAD_KEY_X | PAD_KEY_L | PAD_KEY_SELECT | PAD_KEY_A;
            }
        } else {
            entryIndex = kart->mEntryIndex;
            gInputSlots[entryIndex].mBitMask = PAD_KEYS_NO_START;
            SetKartMissionRunInputMask(kart);
        }
        UpdateKartInputFlags(kart);
        if (kart->mState == KART_STATE_NORMAL) {
            lowSpeedTurn = 0;
            if (!(kart->mMotionFlags & KART_MOTION_DRIFTING)) {
                lowSpeedTurn = TryTurnKartAtLowSpeed(kart);
            }
            inputValue = ApplyKartTurnInput(kart, lowSpeedTurn);
            AdvanceKartDrift(kart);
            AdvanceKartForwardSpeedAndAngles(kart);
        }
        AdvanceKartTurnHeading(kart, inputValue);
        if (AdvanceKartRank(kart) == 0) {
            return;
        }
        if (kart->mDriveFlags & (KART_DRIVE_SINKING | KART_DRIVE_RESPAWN_WAIT)) {
            return;
        }
        StartKartSeqArcSound(kart, kart->mSoundIndex, 8);
        return;
    }
    AdvanceKartRank(kart);
    SetKartMissionRunInputMask(kart);
    UpdateKartInputFlags(kart);
    entryIndex = kart->mEntryIndex;
    inputValue = gInputSlots[entryIndex].mBits;
    if ((u16) (inputValue & PAD_KEY_LEFT)) {
        kart->mDriveFlags |= KART_DRIVE_TURN_LEFT;
    } else if ((u16) (inputValue & PAD_KEY_RIGHT)) {
        kart->mDriveFlags |= KART_DRIVE_TURN_RIGHT;
    }
    kart->mMotionFlags |= KART_MOTION_ON_GROUND;
}

BOOL IsKartNotNormalOrFlagged(Kart *kart) {
    if (kart->mState != KART_STATE_NORMAL || (kart->mDriveFlags & KART_DRIVE_NOT_NORMAL) ||
        (kart->mEntryFlags &
         (KART_ENTRY_ENDED | KART_ENTRY_REMOVED | KART_ENTRY_SCALING_IN | KART_ENTRY_OUT_OF_ROUND))) {
        return TRUE;
    }
    return FALSE;
}

void UpdateKartInputFlags(Kart *kart) {
    u32 *keyBFlagsPointer;
    u32 *flagsPointer;
    u32 flags;
    enum { ENTRY_INDEX_FIRST } entryIndex;

    kart->mDriveFlags &=
        ~(KART_DRIVE_ACCEL_HELD | KART_DRIVE_BRAKE_HELD | KART_DRIVE_BRAKING | KART_DRIVE_LOW_SPEED_TURN);
    kart->mMotionFlags &= ~(KART_MOTION_REVERSING | KART_MOTION_COASTING | KART_MOTION_MOVED_BY_OBJECT);
    flagsPointer = (u32 *) &kart->mDriveFlags;
    entryIndex = kart->mEntryIndex;
    if ((u16) (gInputSlots[entryIndex].mBits & PAD_KEY_A)) {
        *flagsPointer |= KART_DRIVE_ACCEL_HELD;
    }
    entryIndex = kart->mEntryIndex;
    if ((u16) (gInputSlots[entryIndex].mBits & PAD_KEY_B)) {
        keyBFlagsPointer = (u32 *) &kart->mDriveFlags;
        kart->mDriveFlags |= KART_DRIVE_BRAKE_HELD;
        flags = kart->mDriveFlags;
        if ((flags & KART_DRIVE_ACCEL_HELD) && !(flags & (KART_DRIVE_BOOST | KART_DRIVE_RACE_START_BOOST))) {
            *keyBFlagsPointer &= ~(KART_DRIVE_ACCEL_HELD | KART_DRIVE_BRAKE_HELD);
            *keyBFlagsPointer |= KART_DRIVE_BRAKING;
        }
    }
    if (kart->mForwardSpeed < 0) {
        kart->mMotionFlags |= KART_MOTION_REVERSING;
    }
}

void SetKartMissionRunInputMask(Kart *kart) {
    RaceSetup *raceSetup;
    enum { ENTRY_INDEX_FIRST } entryIndex;

    raceSetup = gRaceSetup;
    if (raceSetup->mMode != MODE_MISSION_RUN) {
        return;
    }
    if (!(raceSetup->mMissionRunBits & MISSION_RUN_BIT_INPUT_MASK)) {
        return;
    }
    entryIndex = kart->mEntryIndex;
    gInputSlots[entryIndex].mBitMask = PAD_KEYS_NO_START & ~PAD_KEY_A;
}

void DecayValueToZero(s32 *value) {
    *value = MUL_FIXED12_NO_ROUND(*value, 0xe6a);
    if ((*value <= 0 ? -*value : *value) < 0x7b) {
        *value = 0;
    }
}

s32 ApplyKartTurnInput(Kart *kart, s32 lowSpeedTurn) {
    s32 turnRate = kart->mPhysicalParam->mTurnRate;
    BOOL airborne = FALSE;
    s32 turned = 0;
    enum { TURN_SIGN_NEUTRAL } turnSign = 1;
    s32 speedMagnitude;
    s32 forwardSpeed;
    u32 kartFlags;
    u16 keyBits;
    enum { ENTRY_INDEX_FIRST } entryIndex;
    u32 kartFlagsCopy;

    if (kart->mEffectFlags & (KART_EFFECT_KILLER | KART_EFFECT_HEADING_SWING)) {
        return 0;
    }
    forwardSpeed = kart->mForwardSpeed;
    speedMagnitude = forwardSpeed > 0 ? forwardSpeed : -forwardSpeed;
    if (speedMagnitude < 0x2000) {
        speedMagnitude = forwardSpeed <= 0 ? -forwardSpeed : forwardSpeed;
        turnRate = ((turnRate + (s16) MUL_FIXED12_NO_ROUND(turnRate, speedMagnitude >> 1)) << 15) >> 16;
    }
    kartFlags = kart->mMotionFlags;
    if ((kartFlags & KART_MOTION_HOP_STEER) && (kartFlags & KART_MOTION_HOPPING)) {
        speedMagnitude = kart->mTurnDirection * 0x168;
        if (lowSpeedTurn == 0) {
            speedMagnitude = speedMagnitude * ((kartFlags & KART_MOTION_REVERSING) ? -1 : 1);
        }
        if (kart->mEntryFlags & KART_ENTRY_CPU) {
            speedMagnitude = speedMagnitude << 1;
        }
        kart->mHeadingAngle = kart->mHeadingAngle - speedMagnitude;
        entryIndex = kart->mEntryIndex;
        keyBits = gInputSlots[entryIndex].mBits;
        if ((u16) (keyBits & PAD_KEY_LEFT)) {
            kart->mDriveFlags |= KART_DRIVE_TURN_LEFT;
        } else if ((u16) (keyBits & PAD_KEY_RIGHT)) {
            kart->mDriveFlags |= KART_DRIVE_TURN_RIGHT;
        }
        return 1;
    }
    if (!(kartFlags & KART_MOTION_ON_GROUND)) {
        entryIndex = kart->mEntryIndex;
        keyBits = gInputSlots[entryIndex].mBits;
        if ((u16) (keyBits & PAD_KEY_UP)) {
            kart->mAirTiltAngle += 0x96;
            if (kart->mAirTiltAngle > 0x157c) {
                kart->mAirTiltAngle = 0x157c;
            }
        } else if ((u16) (keyBits & PAD_KEY_DOWN)) {
            kart->mAirTiltAngle -= 0x12c;
            if (kart->mAirTiltAngle < -0x157c) {
                kart->mAirTiltAngle = -0x157c;
            }
        }
        airborne = TRUE;
    }
    kartFlagsCopy = kart->mMotionFlags;
    kartFlags = kartFlagsCopy;
    if (((kartFlags & KART_MOTION_REVERSING) &&
         (u16) (gInputSlots[entryIndex = kart->mEntryIndex].mBits & PAD_KEY_B)) ||
        ((kartFlags & KART_MOTION_REVERSING) && !(kartFlags & (KART_MOTION_HOPPING | KART_MOTION_DRIFTING)))) {
        turnSign = -1;
        turnRate = (s16) ((s16) turnRate * (s16) turnSign);
    }
    entryIndex = kart->mEntryIndex;
    keyBits = gInputSlots[entryIndex].mBits;
    if ((u16) (keyBits & PAD_KEY_LEFT)) {
        turned = ((s32(*)(Kart *, s32, s32, s32, s32, u32)) ApplyKartTurn)(kart, turnRate, turnSign, 1, airborne,
                                                                           KART_DRIVE_TURN_LEFT);
    } else if ((u16) (keyBits & PAD_KEY_RIGHT)) {
        turned = ((s32(*)(Kart *, s32, s32, s32, s32, u32)) ApplyKartTurn)(kart, turnRate, turnSign, -1, airborne,
                                                                           KART_DRIVE_TURN_RIGHT);
    }
    return turned;
}

s32 ApplyKartTurn(Kart *kart, s16 baseTurnRate, s16 turnSign, s32 direction, s32 airborne, u32 turnFlag) {
    s16 driftAngle;
    s16 turnRate;
    u32 kartFlags;
    s32 turnProduct;

    driftAngle = kart->mDriftHeadingAnglePerFrame;
    kart->mDriveFlags |= turnFlag;
    if (airborne != 0) {
        if (!(kart->mMotionFlags & KART_MOTION_DRIFTING)) {
            kart->mTurnHeadingAnglePerFrameGoal = 0x32 * direction;
        }
        return 1;
    }
    kartFlags = kart->mMotionFlags;
    if (kartFlags & KART_MOTION_DRIFTING) {
        turnProduct = kart->mTurnDirection * direction;
        turnRate = kart->mPhysicalParam->mDriftTurnRate;
        if (turnProduct > 0) {
            turnRate = -driftAngle;
        } else {
            turnRate = turnRate + driftAngle;
        }
    } else {
        turnProduct = gTurnHeadingReductionAtSpeedLimit * turnSign;
        turnRate = baseTurnRate - MUL_FIXED12_NO_ROUND(turnProduct, kart->mVelocityLengthRatio);
    }
    if (kartFlags & KART_MOTION_ON_GROUND) {
        kart->mTurnRatio += direction * 0x666;
        if (kart->mTurnRatio > 0x1000) {
            kart->mTurnRatio = 0x1000;
        } else if (kart->mTurnRatio < -0x1000) {
            kart->mTurnRatio = -0x1000;
        }
    }
    if (kart->mVelocityLength != 0 && !(kart->mMotionFlags & KART_MOTION_LOW_SPEED_TURN)) {
        kart->mTurnHeadingAnglePerFrameGoal = turnRate * direction;
    }
    return 1;
}

void AdvanceKartTurnHeading(Kart *kart, s32 turnApplied) {
    if (turnApplied == 0) {
        if (kart->mMotionFlags & KART_MOTION_DRIFTING) {
            kart->mTurnHeadingAnglePerFrameGoal =
                -kart->mTurnDirection *
                ((kart->mPhysicalParam->mDriftTurnRate + kart->mDriftHeadingAnglePerFrame) >> 1);
        }
        DecayValueToZero(&kart->mTurnRatio);
    }
    if (kart->mTurnHeadingAnglePerFrameGoal == 0 &&
        (kart->mTurnHeadingAnglePerFrame <= 0 ? -kart->mTurnHeadingAnglePerFrame : kart->mTurnHeadingAnglePerFrame) <
            5) {
        kart->mTurnHeadingAnglePerFrame = 0;
    } else {
        kart->mTurnHeadingAnglePerFrame =
            kart->mTurnHeadingAnglePerFrame +
            MUL_FIXED12_ROUNDED(kart->mTurnHeadingAnglePerFrameGoal - kart->mTurnHeadingAnglePerFrame,
                                GetTurnHeadingEaseFactor());
    }
    kart->mHeadingAngle += (u16) kart->mTurnHeadingAnglePerFrame;
}

// Writes base + (mRadius + extra) * up to the out vector, where up is row 1 of the matrix at 0x120 (the vector
// GetKartUp returns), and nothing else.
void ComputeKartPointAlongUp(Vec3 *result, const Vec3 *base, s32 extra, Kart *kart) {
    VEC_MultAdd(kart->mRadius + extra, &kart->mRotationRow1, base, result);
}

void ComputeKartCollisionCenter(Vec3 *result, const Vec3 *drawPos, s32 extra, Kart *kart) {
    Vec3 moveDelta;
    Vec3 shiftedPos;

    VEC_Subtract(&kart->mPos, &kart->mPrevPos, &moveDelta);
    VEC_Add(&moveDelta, drawPos, &shiftedPos);
    VEC_MultAdd(kart->mRadius + extra, &kart->mDrawBaseRow1, &shiftedPos, result);
}

void SetKartPrevCollisionCenter(Kart *kart) {
    VEC_MultAdd(kart->mRadius + 0x400, &kart->mDrawBaseRow1, &kart->mDrawMatrixPos, &kart->mPrevCollisionCenter);
}

// Called once per step of the driving states (AdvanceKartMotion, AdvancePeerKartMotion); also writes mUnk_dc in five
// branches.
void UpdateKartSpeedLimitGoal(Kart *kart) {
    s32 *goalPointer;
    u32 flags;

    kart->mSpeedLimitGoal =
        MUL_FIXED12_NO_ROUND(MUL_FIXED12_NO_ROUND(kart->mPhysicalParam->mBaseSpeedLimit, kart->mSpeedLimitFactor),
                             MUL_FIXED12_NO_ROUND((s32) kart->mSpeedLimitGroundFactor, kart->mAheadSpeedLimitFactor));
    goalPointer = &kart->mSpeedLimitGoal;
    if (kart->mEntryFlags & KART_ENTRY_TERESA_OR_PARKED) {
        *goalPointer = kart->mPhysicalParam->mBaseSpeedLimit;
        kart->mSpeedLimitFactor = TO_FIXED12(1);
    }
    if (kart->mDriveFlags & KART_DRIVE_JUMP_PAD) {
        *goalPointer = kart->mSurfaceSpeedLimitGoal;
        kart->mSpeedLimitFactor = TO_FIXED12(1);
    }
    flags = kart->mDriveFlags;
    if (flags & KART_DRIVE_BOOST) {
        if ((kart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) || (flags & KART_DRIVE_ITEM_BOOST)) {
            *goalPointer = kart->mPhysicalParam->mBaseSpeedLimit;
            kart->mSpeedLimitFactor = TO_FIXED12(1);
        }
        *goalPointer = MUL_FIXED12_NO_ROUND(*goalPointer, 0x14cd);
        if (kart->mDriveFlags & (KART_DRIVE_ON_BOOST_SURFACE | KART_DRIVE_BOOST_SPEED_FLOOR)) {
            if (*goalPointer < 0x8800) {
                *goalPointer = 0x8800;
                kart->mSpeedLimitFactor = TO_FIXED12(1);
            }
        }
    } else if (kart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) {
        *goalPointer = MUL_FIXED12_NO_ROUND(kart->mPhysicalParam->mBaseSpeedLimit, 0x1333);
        kart->mSpeedLimitFactor = TO_FIXED12(1);
    }
}

// Called right after UpdateKartSpeedLimitGoal: the limit falls by 0xf37/0x1000 per step down to the goal and rises to
// it at once.
void UpdateKartSpeedLimit(Kart *kart) {
    if (kart->mSpeedLimit > kart->mSpeedLimitGoal) {
        kart->mSpeedLimit = MUL_FIXED12_NO_ROUND(kart->mSpeedLimit, 0xf37);
        if (kart->mSpeedLimit < kart->mSpeedLimitGoal) {
            kart->mSpeedLimit = kart->mSpeedLimitGoal;
        }
    } else {
        kart->mSpeedLimit = kart->mSpeedLimitGoal;
    }
}

void UpdateKartForwardAndLengthRatio(Kart *kart) {
    FX_DivAsync(kart->mVelocityLength, kart->mSpeedLimit);
    if (kart->mMotionFlags & KART_MOTION_ON_GROUND) {
        Vec3CrossUnrounded(&kart->mRotationRow0, &kart->mGroundNormal, &kart->mForward);
    } else {
        GetKartForward(kart, &kart->mForward);
    }
    kart->mVelocityLengthRatio = FX_GetDivResult();
    if (kart->mVelocityLengthRatio > 0x1000) {
        kart->mVelocityLengthRatio = 0x1000;
        kart->mVelocityLength = kart->mSpeedLimit;
    }
}

void AdvanceKartForwardSpeedAndAngles(Kart *kart) {
    s32 acceleration;
    s32 endAcceleration;
    s32 endRatio;
    s32 baseAcceleration;
    BOOL notDrifting;
    s32 value;
    s32 flags;
    u32 flagBits;

    notDrifting = (kart->mMotionFlags & KART_MOTION_DRIFTING) == 0;
    if (notDrifting) {
        acceleration = kart->mPhysicalParam->mAcceleration;
        endAcceleration = kart->mPhysicalParam->mEndAcceleration;
        endRatio = kart->mPhysicalParam->mEndRatio;
    } else {
        acceleration = kart->mPhysicalParam->mDriftAcceleration;
        endAcceleration = kart->mPhysicalParam->mDriftEndAcceleration;
        endRatio = kart->mPhysicalParam->mDriftEndRatio;
    }
    baseAcceleration = acceleration;
    flags = kart->mDriveFlags;
    if (flags & KART_DRIVE_BOOST) {
        AdvanceKartBoost(&acceleration, kart);
    } else if (flags & KART_DRIVE_BRAKE_HELD) {
        acceleration = -0x19a;
        if (kart->mEffectFlags & KART_EFFECT_STAR) {
            acceleration = -0x4cd;
        }
    } else if (notDrifting) {
        if (kart->mEffectFlags & KART_EFFECT_STAR_OR_KILLER) {
            acceleration = 0x4cd;
        } else {
            value = kart->mForwardSpeed;
            flags = kart->mVelocityLengthRatio;
            if (value < 0) {
                acceleration = baseAcceleration + MUL_FIXED12_ROUNDED(-value, 0x52);
            } else if (flags < 0x800) {
                acceleration = baseAcceleration;
            } else if (flags > endRatio) {
                acceleration = endAcceleration;
            } else {
                value = FX_Div(baseAcceleration - endAcceleration, endRatio - 0x800);
                flags = flags - 0x800;
                acceleration = baseAcceleration - MUL_FIXED12_NO_ROUND(value, flags);
            }
        }
    }
    if (kart->mEffectFlags & KART_EFFECT_HEADING_SWING) {
        AdvanceKartHeadingSwing(kart);
    }
    flags = kart->mDriveFlags;
    if (flags & KART_DRIVE_JUMP_PAD) {
        kart->mForwardSpeed += 0x1000;
    } else if (kart->mMotionFlags & KART_MOTION_ON_GROUND) {
        flagBits = kart->mEffectFlags;
        if (!(flagBits & KART_EFFECT_HEADING_SWING)) {
            if (flags & KART_DRIVE_BRAKING) {
                kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, 0xfae);
            } else if (flags & (KART_DRIVE_ACCEL_HELD | KART_DRIVE_BRAKE_HELD | KART_DRIVE_BOOST)) {
                kart->mForwardSpeed += acceleration;
            } else if (!(flagBits & KART_EFFECT_KILLER)) {
                kart->mMotionFlags |= KART_MOTION_COASTING;
            }
        }
    }
    flagBits = kart->mMotionFlags;
    if ((flagBits & KART_MOTION_DRIFT_ENDED_IN_AIR) && (flagBits & KART_MOTION_ON_GROUND)) {
        kart->mMotionFlags &= ~KART_MOTION_DRIFT_ENDED_IN_AIR;
    }
    if (kart->mHeadingAnglePerFrame != 0) {
        kart->mHeadingAnglePerFrame = MUL_FIXED12_NO_ROUND(kart->mHeadingAnglePerFrame, 0xe66);
        if ((kart->mHeadingAnglePerFrame <= 0 ? -kart->mHeadingAnglePerFrame : kart->mHeadingAnglePerFrame) < 0x14) {
            kart->mHeadingAnglePerFrame = 0;
        }
        kart->mHeadingAngle += (u16) kart->mHeadingAnglePerFrame;
    }
    flagBits = kart->mMotionFlags;
    if (!(flagBits & KART_MOTION_ON_GROUND) || !notDrifting ||
        (flagBits & (KART_MOTION_HOPPING | KART_MOTION_DRIFT_ENDED_IN_AIR | KART_MOTION_LOW_SPEED_TURN))) {
        return;
    }
    if (kart->mTurnAngle > 0) {
        kart->mTurnAngle = kart->mTurnAngle - kart->mPhysicalParam->mTurnAngleStep;
        if (kart->mTurnAngle < 0) {
            kart->mTurnAngle = 0;
        }
    } else if (kart->mTurnAngle < 0) {
        kart->mTurnAngle = kart->mTurnAngle + kart->mPhysicalParam->mTurnAngleStep;
        if (kart->mTurnAngle > 0) {
            kart->mTurnAngle = 0;
        }
    }
}
