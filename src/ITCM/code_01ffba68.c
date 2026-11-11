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

void QuaternionMultiply(const Vec4 *a, const Vec4 *b, Vec4 *c) {
    Vec4 t;

    t.x = (a->w * b->x + a->x * b->w + (a->y * b->z - a->z * b->y)) >> 12;
    t.y = (a->w * b->y + a->y * b->w + (a->z * b->x - a->x * b->z)) >> 12;
    t.z = (a->w * b->z + a->z * b->w + (a->x * b->y - a->y * b->x)) >> 12;
    t.w = (a->w * b->w - (a->x * b->x + a->y * b->y + a->z * b->z)) >> 12;
    *c = t;
}

void QuaternionBlend(Vec4 *a, const Vec4 *b, Vec4 *c, s32 d) {
    c->x = a->x + ((d * (b->x - a->x)) >> 12);
    c->y = a->y + ((d * (b->y - a->y)) >> 12);
    c->z = a->z + ((d * (b->z - a->z)) >> 12);
    c->w = a->w + ((d * (b->w - a->w)) >> 12);
}

void Matrix4x3FromQuaternion(MtxFx43 *a, const Vec4 *b) {
    s32 *o = &a->mRows[0].x;
    s32 w;
    s32 x;
    s32 y;
    s32 z;
    s32 zx;
    s32 xx;
    s32 ww;
    s32 yy;
    s32 zw;
    s32 zy;
    s32 wx;
    s32 wy;
    s32 xy;

    w = b->x;
    x = b->y;
    y = b->z;
    z = b->w;
    zx = z * x >> 11;
    xx = x * x >> 11;
    ww = w * w >> 11;
    yy = y * y >> 11;
    zw = z * w >> 11;
    zy = z * y >> 11;
    wx = w * x >> 11;
    wy = w * y >> 11;
    xy = x * y >> 11;
    o[0] = 0x1000 - (xx + yy);
    o[1] = wx + zy;
    o[2] = wy - zx;
    o[3] = wx - zy;
    o[4] = 0x1000 - (yy + ww);
    o[5] = xy + zw;
    o[6] = wy + zx;
    o[7] = xy - zw;
    o[8] = 0x1000 - (ww + xx);
    o[9] = 0;
    o[10] = 0;
    o[11] = 0;
}

void Matrix3x3FromQuaternion(MtxFx33 *a, void *b) {
    s32 *o = &a->mRows[0].x;
    const Vec4 *q = b;
    s32 w;
    s32 x;
    s32 y;
    s32 z;
    s32 zx;
    s32 xx;
    s32 ww;
    s32 yy;
    s32 zw;
    s32 zy;
    s32 wx;
    s32 wy;
    s32 xy;

    w = q->x;
    x = q->y;
    y = q->z;
    z = q->w;
    zx = z * x >> 11;
    xx = x * x >> 11;
    ww = w * w >> 11;
    yy = y * y >> 11;
    zw = z * w >> 11;
    zy = z * y >> 11;
    wx = w * x >> 11;
    wy = w * y >> 11;
    xy = x * y >> 11;
    o[0] = 0x1000 - (xx + yy);
    o[1] = wx + zy;
    o[2] = wy - zx;
    o[3] = wx - zy;
    o[4] = 0x1000 - (yy + ww);
    o[5] = xy + zw;
    o[6] = wy + zx;
    o[7] = xy - zw;
    o[8] = 0x1000 - (ww + xx);
}

void AdvanceKartMotion(Kart *p) {
    if (p->mUnk_7c & 0xa0) {
        AdvanceKartScaleFactor(p);
        return;
    }
    ResetKartTurnAndRadius(p);
    UpdateKartSpeedLimitGoal(p);
    AdvanceKartAi(p);
    UpdateKartSpeedLimit(p);
    UpdateKartForwardAndLengthRatio(p);
    AdvanceKartInputAndTurn(p);
    AdvanceKartBoosts(p);
    if (p->mUnk_48 & 0x10000) {
        AdvanceKartToKeyedPlacement(p);
    } else {
        AdvanceKartByVelocity(p);
    }
}

void AdvanceKartCollision(Kart *kart) {
    Vec3 v;

    if (kart->mUnk_7c & KART_7C_REMOVED) {
        return;
    }
    if (kart->mUnk_44 & KART_44_NEAR_KART) {
        kart->mUnk_44 |= 0x80000;
    } else {
        kart->mUnk_44 &= ~0x80000;
    }
    ComputeKartCollisionCenter(&kart->mCollisionCenter, &kart->mDrawMatrixPos, 0x400, kart);
    CollideKartWithCourse(kart, &v);
    AdvanceKartOrientation(kart, &v);
    kart->mGroundNormal = v;
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

void UpdateKartPrevValuesAndClearFlags(Kart *p) {
    p->mTestedKartMask = 0;
    p->mUnk_44 &= 0x57ffffdf;
    p->mUnk_4c &= 0xffeb7efd;
    p->mPrevNearKartMask = p->mNearKartMask;
    p->mNearKartMask = 0;
    p->mPrevPos = p->mPos;
    p->mPrevPointAlongUp = p->mPointAlongUp;
    p->mPrevPrevHitVelocity = p->mPrevHitVelocity;
    p->mPrevHitVelocity = p->mHitVelocity;
    p->mSlotFunctions[5](p);
}

static inline const s32 func_01ffc090_inline(void) {
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

s32 AdvanceKartRank(Kart *p) {
    BOOL b;
    s32 a;
    s32 c;
    Kart *o;

    b = FALSE;
    a = GetKartRank(p->mIndex);
    if (a != p->mRank) {
        if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            SetSceneSoundRank((u8) (a - 1));
        }
        if (a < p->mRank && a < gRaceSetup->mKartCount) {
            c = gRaceProgress->mKartAtRank[(u8) (a + 1) - 1];
            if (c >= 0) {
                o = GetKart((u16) c);
                if (!(o->mUnk_7c & 0x402004)) {
                    b = TRUE;
                }
            }
        }
    }
    p->mRank = a;
    return b;
}

void UpdateKartSoundWrapper(Kart *kart) {
    UpdateKartSound(kart);
}

void AdvanceKartCollisionTimer(Kart *p) {
    if (p->mKartCollisionTimer <= 0) {
        return;
    }
    p->mKartCollisionTimer = p->mKartCollisionTimer - 1;
    if (p->mKartCollisionTimer > 0) {
        return;
    }
    StartKartCollisionSound(p, p->mSoundIndex, p->mUnk_3d0);
    p->mKartCollisionTimer = 0;
}

void AdvanceKartInputAndTurn(Kart *kart) {
    s32 a;
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
        a = 0;
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
            a = ApplyKartTurnInput(kart, lowSpeedTurn);
            AdvanceKartDrift(kart);
            AdvanceKartForwardSpeedAndAngles(kart);
        }
        AdvanceKartTurnHeading(kart, a);
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
    a = gInputSlots[entryIndex].mBits;
    if ((u16) (a & PAD_KEY_LEFT)) {
        kart->mUnk_48 |= KART_48_TURN_LEFT;
    } else if ((u16) (a & PAD_KEY_RIGHT)) {
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
    if (!(raceSetup->mUnk_044 & 1)) {
        return;
    }
    entryIndex = kart->mEntryIndex;
    gInputSlots[entryIndex].mBitMask = 0xff6;
}

void DecayValueToZero(s32 *p) {
    *p = MUL_FIXED12_NO_ROUND(*p, 0xe6a);
    if ((*p <= 0 ? -*p : *p) < 0x7b) {
        *p = 0;
    }
}

s32 ApplyKartTurnInput(Kart *kart, s32 lowSpeedTurn) {
    s32 x = kart->mPhysicalParam->mUnk_30;
    BOOL airborne = FALSE;
    s32 turned = 0;
    enum { K1 } b = 1;
    s32 t;
    s32 forwardSpeed;
    u32 f;
    u16 keyBits;
    enum { K0 } entryIndex;
    u32 c;

    if (kart->mUnk_4c & 0x30000000) {
        return 0;
    }
    forwardSpeed = kart->mForwardSpeed;
    t = forwardSpeed > 0 ? forwardSpeed : -forwardSpeed;
    if (t < 0x2000) {
        t = forwardSpeed <= 0 ? -forwardSpeed : forwardSpeed;
        x = ((x + (s16) MUL_FIXED12_NO_ROUND(x, t >> 1)) << 15) >> 16;
    }
    f = kart->mUnk_44;
    if ((f & 0x800) && (f & 2)) {
        t = kart->mTurnDirection * 0x168;
        if (lowSpeedTurn == 0) {
            t = t * ((f & 0x100) ? -1 : 1);
        }
        if (kart->mUnk_7c & 2) {
            t = t << 1;
        }
        kart->mHeadingAngle = kart->mHeadingAngle - t;
        entryIndex = kart->mEntryIndex;
        keyBits = gInputSlots[entryIndex].mBits;
        if ((u16) (keyBits & PAD_KEY_LEFT)) {
            kart->mUnk_48 |= KART_48_TURN_LEFT;
        } else if ((u16) (keyBits & PAD_KEY_RIGHT)) {
            kart->mUnk_48 |= KART_48_TURN_RIGHT;
        }
        return 1;
    }
    if (!(f & KART_44_ON_GROUND)) {
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
    c = kart->mUnk_44;
    f = c;
    if (((f & 0x100) && (u16) (gInputSlots[entryIndex = kart->mEntryIndex].mBits & PAD_KEY_B)) ||
        ((f & 0x100) && !(f & 0xa))) {
        b = -1;
        x = (s16) ((s16) x * (s16) b);
    }
    entryIndex = kart->mEntryIndex;
    keyBits = gInputSlots[entryIndex].mBits;
    if ((u16) (keyBits & PAD_KEY_LEFT)) {
        turned = ((s32(*)(Kart *, s32, s32, s32, s32, u32)) ApplyKartTurn)(kart, x, b, 1, airborne, KART_48_TURN_LEFT);
    } else if ((u16) (keyBits & PAD_KEY_RIGHT)) {
        turned =
            ((s32(*)(Kart *, s32, s32, s32, s32, u32)) ApplyKartTurn)(kart, x, b, -1, airborne, KART_48_TURN_RIGHT);
    }
    return turned;
}

s32 ApplyKartTurn(Kart *p, s16 a, s16 b, s32 c, s32 d, u32 e) {
    s16 k;
    s16 x;
    u32 f;
    s32 m;

    k = p->mDriftHeadingAnglePerFrame;
    p->mUnk_48 |= e;
    if (d != 0) {
        if (!(p->mUnk_44 & KART_44_DRIFTING)) {
            p->mTurnHeadingAnglePerFrameGoal = 0x32 * c;
        }
        return 1;
    }
    f = p->mUnk_44;
    if (f & KART_44_DRIFTING) {
        m = p->mTurnDirection * c;
        x = p->mPhysicalParam->mUnk_32;
        if (m > 0) {
            x = -k;
        } else {
            x = x + k;
        }
    } else {
        m = gTurnHeadingReductionAtSpeedLimit * b;
        x = a - MUL_FIXED12_NO_ROUND(m, p->mVelocityLengthRatio);
    }
    if (f & KART_44_ON_GROUND) {
        p->mTurnRatio += c * 0x666;
        if (p->mTurnRatio > 0x1000) {
            p->mTurnRatio = 0x1000;
        } else if (p->mTurnRatio < -0x1000) {
            p->mTurnRatio = -0x1000;
        }
    }
    if (p->mVelocityLength != 0 && !(p->mUnk_44 & 0x8000000)) {
        p->mTurnHeadingAnglePerFrameGoal = x * c;
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
                                func_01ffc090_inline());
    }
    kart->mHeadingAngle += (u16) kart->mTurnHeadingAnglePerFrame;
}

// Writes base + (mRadius + extra) * up to the out vector, where up is row 1 of the matrix at 0x120 (the vector
// GetKartUp returns), and nothing else.
void ComputeKartPointAlongUp(Vec3 *a, const Vec3 *b, s32 c, Kart *p) {
    VEC_MultAdd(p->mRadius + c, &p->mUnk_12c, b, a);
}

void ComputeKartCollisionCenter(Vec3 *a, const Vec3 *b, s32 c, Kart *p) {
    Vec3 d;
    Vec3 e;

    VEC_Subtract(&p->mPos, &p->mPrevPos, &d);
    VEC_Add(&d, b, &e);
    VEC_MultAdd(p->mRadius + c, &p->mUnk_15c, &e, a);
}

void SetKartPrevCollisionCenter(Kart *p) {
    VEC_MultAdd(p->mRadius + 0x400, &p->mUnk_15c, &p->mDrawMatrixPos, &p->mPrevCollisionCenter);
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
void UpdateKartSpeedLimit(Kart *p) {
    if (p->mSpeedLimit > p->mSpeedLimitGoal) {
        p->mSpeedLimit = MUL_FIXED12_NO_ROUND(p->mSpeedLimit, 0xf37);
        if (p->mSpeedLimit < p->mSpeedLimitGoal) {
            p->mSpeedLimit = p->mSpeedLimitGoal;
        }
    } else {
        p->mSpeedLimit = p->mSpeedLimitGoal;
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
    s32 a;
    s32 b;
    s32 baseAcceleration;
    BOOL notDrifting;
    s32 e;
    s32 f;
    u32 g;

    notDrifting = (kart->mUnk_44 & KART_44_DRIFTING) == 0;
    if (notDrifting) {
        acceleration = kart->mPhysicalParam->mUnk_14;
        a = kart->mPhysicalParam->mUnk_18;
        b = kart->mPhysicalParam->mUnk_1c;
    } else {
        acceleration = kart->mPhysicalParam->mUnk_20;
        a = kart->mPhysicalParam->mUnk_24;
        b = kart->mPhysicalParam->mUnk_28;
    }
    baseAcceleration = acceleration;
    f = kart->mUnk_48;
    if (f & KART_48_BOOST) {
        AdvanceKartBoost(&acceleration, kart);
    } else if (f & 4) {
        acceleration = -0x19a;
        if (kart->mUnk_4c & 0x40) {
            acceleration = -0x4cd;
        }
    } else if (notDrifting) {
        if (kart->mUnk_4c & 0x10000040) {
            acceleration = 0x4cd;
        } else {
            e = kart->mForwardSpeed;
            f = kart->mVelocityLengthRatio;
            if (e < 0) {
                acceleration = baseAcceleration + MUL_FIXED12_ROUNDED(-e, 0x52);
            } else if (f < 0x800) {
                acceleration = baseAcceleration;
            } else if (f > b) {
                acceleration = a;
            } else {
                e = FX_Div(baseAcceleration - a, b - 0x800);
                f = f - 0x800;
                acceleration = baseAcceleration - MUL_FIXED12_NO_ROUND(e, f);
            }
        }
    }
    if (kart->mUnk_4c & KART_4C_HEADING_SWING) {
        AdvanceKartHeadingSwing(kart);
    }
    f = kart->mUnk_48;
    if (f & 0x10000000) {
        kart->mForwardSpeed += 0x1000;
    } else if (kart->mUnk_44 & KART_44_ON_GROUND) {
        g = kart->mUnk_4c;
        if (!(g & KART_4C_HEADING_SWING)) {
            if (f & 0x80) {
                kart->mForwardSpeed = MUL_FIXED12_NO_ROUND(kart->mForwardSpeed, 0xfae);
            } else if (f & 0x26) {
                kart->mForwardSpeed += acceleration;
            } else if (!(g & 0x10000000)) {
                kart->mUnk_44 |= 0x400;
            }
        }
    }
    g = kart->mUnk_44;
    if ((g & 0x8000) && (g & KART_44_ON_GROUND)) {
        kart->mUnk_44 &= ~0x8000;
    }
    if (kart->mHeadingAnglePerFrame != 0) {
        kart->mHeadingAnglePerFrame = MUL_FIXED12_NO_ROUND(kart->mHeadingAnglePerFrame, 0xe66);
        if ((kart->mHeadingAnglePerFrame <= 0 ? -kart->mHeadingAnglePerFrame : kart->mHeadingAnglePerFrame) < 0x14) {
            kart->mHeadingAnglePerFrame = 0;
        }
        kart->mHeadingAngle += (u16) kart->mHeadingAnglePerFrame;
    }
    g = kart->mUnk_44;
    if (!(g & KART_44_ON_GROUND) || !notDrifting || (g & 0x8008002)) {
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
