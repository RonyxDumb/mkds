#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffa4b4.h"
#include "ITCM/code_01ffb000.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0207a780.h"
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
#include "Main/Unknown/code_0207a790.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_02066ac0.h"
#include "ITCM/code_01ffb130.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

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
    if (kart->mUnk_7c & 0xa0) {
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
    if (kart->mUnk_48 & 0x10000) {
        AdvanceKartToKeyedPlacement(kart);
    } else {
        AdvanceKartByVelocity(kart);
    }
}

void AdvanceKartCollision(Kart *kart) {
    Vec3 groundNormal;

    if (kart->mUnk_7c & KART_7C_REMOVED) {
        return;
    }
    if (kart->mUnk_44 & KART_44_NEAR_KART) {
        kart->mUnk_44 |= 0x80000;
    } else {
        kart->mUnk_44 &= ~0x80000;
    }
    ComputeKartCollisionCenter(&kart->mCollisionCenter, &kart->mDrawMatrixPos, 0x400, kart);
    CollideKartWithCourse(kart, &groundNormal);
    AdvanceKartOrientation(kart, &groundNormal);
    kart->mGroundNormal = groundNormal;
    kart->mCollisionStepFrames = kart->mCollisionStepFrames + 1;
    if (kart->mUnk_4c & KART_4C_NEAR_PLAYER_RANK) {
        ComputeKartSidePoints(kart);
    }
    if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && IsRaceStarted() == 1) {
        SetKartKind3ShapeListMask(kart->mIndex);
    }
    UpdateKartSoundWrapper(kart);
    AdvanceKartCollisionTimer(kart);
    if (kart->mUnk_4c & 8) {
        AdvanceKartModelScaleAnimation(kart);
    }
    kart->mAdvanceOffsetCycle(kart);
}

void UpdateKartPrevValuesAndClearFlags(Kart *kart) {
    kart->mTestedKartMask = 0;
    kart->mUnk_44 &= 0x57ffffdf;
    kart->mUnk_4c &= 0xffeb7efd;
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
    kart->mUnk_48 &= ~(KART_48_TURN_LEFT | KART_48_TURN_RIGHT);
    kart->mRadius = MUL_FIXED12_NO_ROUND(kart->mRadiusFactor,
                                         MUL_FIXED12_NO_ROUND(kart->mPhysicalParam->mRadius, kart->mShrinkFactor));
    kart->mUnk_1d4 = MUL_FIXED12_NO_ROUND(kart->mPhysicalParam->mUnk_04, kart->mScale.z);
    kart->mTurnHeadingAnglePerFrameGoal = 0;
}

void AddKartSurfaceSoundRequest(Kart *kart, s32 entryIndex) {
    s32 sortOffset;
    s32 queueIndex;
    s32 kartCameraDistanceSquared;

    queueIndex = (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 3 : 2;
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
        if (kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            SetSceneSoundRank((u8) (newRank - 1));
        }
        if (newRank < kart->mRank && newRank < gRaceSetup->mKartCount) {
            aheadKartIndex = GetKartAtRank(newRank + 1);
            if (aheadKartIndex >= 0) {
                aheadKart = GetKart((u16) aheadKartIndex);
                if (!(aheadKart->mUnk_7c & 0x402004)) {
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
    StartKartCollisionSound(kart, kart->mSoundIndex, kart->mUnk_3d0);
    kart->mKartCollisionTimer = 0;
}

void AdvanceKartInputAndTurn(Kart *kart) {
    s32 inputValue;
    s32 lowSpeedTurn;
    enum { K0 } entryIndex;

    if (kart->mUnk_48 & KART_48_STATE_END_TIMER) {
        kart->mStateEndTimer = kart->mStateEndTimer - 1;
        if (kart->mStateEndTimer <= 0) {
            kart->mStateEndTimer = 0;
            kart->mUnk_48 &= ~(KART_48_STATE_END_TIMER | KART_48_INPUT_LOCKED);
        }
    }
    if (IsRaceStarted() == 1) {
        inputValue = 0;
        if (IsKartNotNormalOrFlagged(kart) != FALSE) {
            entryIndex = kart->mEntryIndex;
            gInputSlots[entryIndex].mBitMask = 0xe04;
            if (kart->mUnk_4c & 0x10000000) {
                entryIndex = kart->mEntryIndex;
                gInputSlots[entryIndex].mBitMask = 0xe34;
            }
            if (kart->mUnk_48 & 0x2000000) {
                entryIndex = kart->mEntryIndex;
                gInputSlots[entryIndex].mBitMask = 0xe05;
            }
        } else {
            entryIndex = kart->mEntryIndex;
            gInputSlots[entryIndex].mBitMask = 0xff7;
            SetKartMissionRunInputMask(kart);
        }
        UpdateKartInputFlags(kart);
        if (kart->mState == KART_STATE_NORMAL) {
            lowSpeedTurn = 0;
            if (!(kart->mUnk_44 & KART_44_DRIFTING)) {
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
        if (kart->mUnk_48 & (KART_48_SINKING | KART_48_RESPAWN_WAIT)) {
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
        kart->mUnk_48 |= KART_48_TURN_LEFT;
    } else if ((u16) (inputValue & PAD_KEY_RIGHT)) {
        kart->mUnk_48 |= KART_48_TURN_RIGHT;
    }
    kart->mUnk_44 |= KART_44_ON_GROUND;
}

BOOL IsKartNotNormalOrFlagged(Kart *kart) {
    if (kart->mState != KART_STATE_NORMAL || (kart->mUnk_48 & 0x6052840) || (kart->mUnk_7c & 0x200000a8)) {
        return TRUE;
    }
    return FALSE;
}

void UpdateKartInputFlags(Kart *kart) {
    u32 *keyBFlagsPointer;
    u32 *flagsPointer;
    u32 flags;
    enum { K0 } entryIndex;

    kart->mUnk_48 &= ~0x186;
    kart->mUnk_44 &= ~0x40500;
    flagsPointer = (u32 *) &kart->mUnk_48;
    entryIndex = kart->mEntryIndex;
    if ((u16) (gInputSlots[entryIndex].mBits & PAD_KEY_A)) {
        *flagsPointer |= 2;
    }
    entryIndex = kart->mEntryIndex;
    if ((u16) (gInputSlots[entryIndex].mBits & PAD_KEY_B)) {
        keyBFlagsPointer = (u32 *) &kart->mUnk_48;
        kart->mUnk_48 |= 4;
        flags = kart->mUnk_48;
        if ((flags & 2) && !(flags & 0x8020)) {
            *keyBFlagsPointer &= ~6;
            *keyBFlagsPointer |= 0x80;
        }
    }
    if (kart->mForwardSpeed < 0) {
        kart->mUnk_44 |= KART_44_REVERSING;
    }
}

void SetKartMissionRunInputMask(Kart *kart) {
    RaceSetup *raceSetup;
    enum { K0 } entryIndex;

    raceSetup = gRaceSetup;
    if (raceSetup->mMode != MODE_MISSION_RUN) {
        return;
    }
    if (!(raceSetup->mMissionRunBits & MISSION_RUN_BIT_INPUT_MASK)) {
        return;
    }
    entryIndex = kart->mEntryIndex;
    gInputSlots[entryIndex].mBitMask = 0xff6;
}

void DecayValueToZero(s32 *value) {
    *value = MUL_FIXED12_NO_ROUND(*value, 0xe6a);
    if ((*value <= 0 ? -*value : *value) < 0x7b) {
        *value = 0;
    }
}

s32 ApplyKartTurnInput(Kart *kart, s32 lowSpeedTurn) {
    s32 turnRate = kart->mPhysicalParam->mUnk_30;
    BOOL airborne = FALSE;
    s32 turned = 0;
    enum { K1 } turnSign = 1;
    s32 speedMagnitude;
    s32 forwardSpeed;
    u32 kartFlags;
    u16 keyBits;
    enum { K0 } entryIndex;
    u32 kartFlagsCopy;

    if (kart->mUnk_4c & 0x30000000) {
        return 0;
    }
    forwardSpeed = kart->mForwardSpeed;
    speedMagnitude = forwardSpeed > 0 ? forwardSpeed : -forwardSpeed;
    if (speedMagnitude < 0x2000) {
        speedMagnitude = forwardSpeed <= 0 ? -forwardSpeed : forwardSpeed;
        turnRate = ((turnRate + (s16) MUL_FIXED12_NO_ROUND(turnRate, speedMagnitude >> 1)) << 15) >> 16;
    }
    kartFlags = kart->mUnk_44;
    if ((kartFlags & 0x800) && (kartFlags & 2)) {
        speedMagnitude = kart->mTurnDirection * 0x168;
        if (lowSpeedTurn == 0) {
            speedMagnitude = speedMagnitude * ((kartFlags & 0x100) ? -1 : 1);
        }
        if (kart->mUnk_7c & 2) {
            speedMagnitude = speedMagnitude << 1;
        }
        kart->mHeadingAngle = kart->mHeadingAngle - speedMagnitude;
        entryIndex = kart->mEntryIndex;
        keyBits = gInputSlots[entryIndex].mBits;
        if ((u16) (keyBits & PAD_KEY_LEFT)) {
            kart->mUnk_48 |= KART_48_TURN_LEFT;
        } else if ((u16) (keyBits & PAD_KEY_RIGHT)) {
            kart->mUnk_48 |= KART_48_TURN_RIGHT;
        }
        return 1;
    }
    if (!(kartFlags & KART_44_ON_GROUND)) {
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
    kartFlagsCopy = kart->mUnk_44;
    kartFlags = kartFlagsCopy;
    if (((kartFlags & 0x100) && (u16) (gInputSlots[entryIndex = kart->mEntryIndex].mBits & PAD_KEY_B)) ||
        ((kartFlags & 0x100) && !(kartFlags & 0xa))) {
        turnSign = -1;
        turnRate = (s16) ((s16) turnRate * (s16) turnSign);
    }
    entryIndex = kart->mEntryIndex;
    keyBits = gInputSlots[entryIndex].mBits;
    if ((u16) (keyBits & PAD_KEY_LEFT)) {
        turned = ((s32(*)(Kart *, s32, s32, s32, s32, u32)) ApplyKartTurn)(kart, turnRate, turnSign, 1, airborne,
                                                                           KART_48_TURN_LEFT);
    } else if ((u16) (keyBits & PAD_KEY_RIGHT)) {
        turned = ((s32(*)(Kart *, s32, s32, s32, s32, u32)) ApplyKartTurn)(kart, turnRate, turnSign, -1, airborne,
                                                                           KART_48_TURN_RIGHT);
    }
    return turned;
}

s32 ApplyKartTurn(Kart *kart, s16 baseTurnRate, s16 turnSign, s32 direction, s32 airborne, u32 turnFlag) {
    s16 driftAngle;
    s16 turnRate;
    u32 kartFlags;
    s32 turnProduct;

    driftAngle = kart->mDriftHeadingAnglePerFrame;
    kart->mUnk_48 |= turnFlag;
    if (airborne != 0) {
        if (!(kart->mUnk_44 & KART_44_DRIFTING)) {
            kart->mTurnHeadingAnglePerFrameGoal = 0x32 * direction;
        }
        return 1;
    }
    kartFlags = kart->mUnk_44;
    if (kartFlags & KART_44_DRIFTING) {
        turnProduct = kart->mTurnDirection * direction;
        turnRate = kart->mPhysicalParam->mUnk_32;
        if (turnProduct > 0) {
            turnRate = -driftAngle;
        } else {
            turnRate = turnRate + driftAngle;
        }
    } else {
        turnProduct = gTurnHeadingReductionAtSpeedLimit * turnSign;
        turnRate = baseTurnRate - MUL_FIXED12_NO_ROUND(turnProduct, kart->mVelocityLengthRatio);
    }
    if (kartFlags & KART_44_ON_GROUND) {
        kart->mTurnRatio += direction * 0x666;
        if (kart->mTurnRatio > 0x1000) {
            kart->mTurnRatio = 0x1000;
        } else if (kart->mTurnRatio < -0x1000) {
            kart->mTurnRatio = -0x1000;
        }
    }
    if (kart->mVelocityLength != 0 && !(kart->mUnk_44 & 0x8000000)) {
        kart->mTurnHeadingAnglePerFrameGoal = turnRate * direction;
    }
    return 1;
}

void AdvanceKartTurnHeading(Kart *kart, s32 turnApplied) {
    if (turnApplied == 0) {
        if (kart->mUnk_44 & KART_44_DRIFTING) {
            kart->mTurnHeadingAnglePerFrameGoal =
                -kart->mTurnDirection * ((kart->mPhysicalParam->mUnk_32 + kart->mDriftHeadingAnglePerFrame) >> 1);
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
    VEC_MultAdd(kart->mRadius + extra, &kart->mUnk_12c, base, result);
}

void ComputeKartCollisionCenter(Vec3 *result, const Vec3 *drawPos, s32 extra, Kart *kart) {
    Vec3 moveDelta;
    Vec3 shiftedPos;

    VEC_Subtract(&kart->mPos, &kart->mPrevPos, &moveDelta);
    VEC_Add(&moveDelta, drawPos, &shiftedPos);
    VEC_MultAdd(kart->mRadius + extra, &kart->mUnk_15c, &shiftedPos, result);
}

void SetKartPrevCollisionCenter(Kart *kart) {
    VEC_MultAdd(kart->mRadius + 0x400, &kart->mUnk_15c, &kart->mDrawMatrixPos, &kart->mPrevCollisionCenter);
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
    if (kart->mUnk_7c & 0x402000) {
        *goalPointer = kart->mPhysicalParam->mBaseSpeedLimit;
        kart->mSpeedLimitFactor = 0x1000;
    }
    if (kart->mUnk_48 & 0x10000000) {
        *goalPointer = kart->mSurfaceSpeedLimitGoal;
        kart->mSpeedLimitFactor = 0x1000;
    }
    flags = kart->mUnk_48;
    if (flags & KART_48_BOOST) {
        if ((kart->mUnk_4c & 0x10000040) || (flags & 0x20000000)) {
            *goalPointer = kart->mPhysicalParam->mBaseSpeedLimit;
            kart->mSpeedLimitFactor = 0x1000;
        }
        *goalPointer = MUL_FIXED12_NO_ROUND(*goalPointer, 0x14cd);
        if (kart->mUnk_48 & 0x400001) {
            if (*goalPointer < 0x8800) {
                *goalPointer = 0x8800;
                kart->mSpeedLimitFactor = 0x1000;
            }
        }
    } else if (kart->mUnk_4c & 0x10000040) {
        *goalPointer = MUL_FIXED12_NO_ROUND(kart->mPhysicalParam->mBaseSpeedLimit, 0x1333);
        kart->mSpeedLimitFactor = 0x1000;
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
    if (kart->mUnk_44 & KART_44_ON_GROUND) {
        Vec3CrossUnrounded(&kart->mUnk_120, &kart->mGroundNormal, &kart->mForward);
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

    notDrifting = (kart->mUnk_44 & KART_44_DRIFTING) == 0;
    if (notDrifting) {
        acceleration = kart->mPhysicalParam->mUnk_14;
        endAcceleration = kart->mPhysicalParam->mUnk_18;
        endRatio = kart->mPhysicalParam->mUnk_1c;
    } else {
        acceleration = kart->mPhysicalParam->mUnk_20;
        endAcceleration = kart->mPhysicalParam->mUnk_24;
        endRatio = kart->mPhysicalParam->mUnk_28;
    }
    baseAcceleration = acceleration;
    flags = kart->mUnk_48;
    if (flags & KART_48_BOOST) {
        AdvanceKartBoost(&acceleration, kart);
    } else if (flags & 4) {
        acceleration = -0x19a;
        if (kart->mUnk_4c & 0x40) {
            acceleration = -0x4cd;
        }
    } else if (notDrifting) {
        if (kart->mUnk_4c & 0x10000040) {
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
    if (kart->mUnk_4c & KART_4C_HEADING_SWING) {
        AdvanceKartHeadingSwing(kart);
    }
    flags = kart->mUnk_48;
    if (flags & 0x10000000) {
        kart->mForwardSpeed += 0x1000;
    } else if (kart->mUnk_44 & KART_44_ON_GROUND) {
        flagBits = kart->mUnk_4c;
        if (!(flagBits & KART_4C_HEADING_SWING)) {
            if (flags & 0x80) {
                kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, 0xfae);
            } else if (flags & 0x26) {
                kart->mForwardSpeed += acceleration;
            } else if (!(flagBits & 0x10000000)) {
                kart->mUnk_44 |= 0x400;
            }
        }
    }
    flagBits = kart->mUnk_44;
    if ((flagBits & 0x8000) && (flagBits & KART_44_ON_GROUND)) {
        kart->mUnk_44 &= ~0x8000;
    }
    if (kart->mHeadingAnglePerFrame != 0) {
        kart->mHeadingAnglePerFrame = MUL_FIXED12_NO_ROUND(kart->mHeadingAnglePerFrame, 0xe66);
        if ((kart->mHeadingAnglePerFrame <= 0 ? -kart->mHeadingAnglePerFrame : kart->mHeadingAnglePerFrame) < 0x14) {
            kart->mHeadingAnglePerFrame = 0;
        }
        kart->mHeadingAngle += (u16) kart->mHeadingAnglePerFrame;
    }
    flagBits = kart->mUnk_44;
    if (!(flagBits & KART_44_ON_GROUND) || !notDrifting || (flagBits & 0x8008002)) {
        return;
    }
    if (kart->mTurnAngle > 0) {
        kart->mTurnAngle = kart->mTurnAngle - kart->mPhysicalParam->mUnk_34;
        if (kart->mTurnAngle < 0) {
            kart->mTurnAngle = 0;
        }
    } else if (kart->mTurnAngle < 0) {
        kart->mTurnAngle = kart->mTurnAngle + kart->mPhysicalParam->mUnk_34;
        if (kart->mTurnAngle > 0) {
            kart->mTurnAngle = 0;
        }
    }
}
