#include "ITCM/code_01ffa4b4.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffdee4.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0206f04c.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_0210f230.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_020d3d94.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206e874.h"

void CollideKartWithCourse(Kart *kart, Vec3 *groundNormal) {
    u16 headingDelta;
    u32 collisionFlags;
    u32 hitObjects;
    Vec3 pushOut;
    Vec3 secondNormal;
    Vec3 lowestOffset;
    Vec3 pointMotion;
    Vec3 normal;
    Vec3 pushVector;
    Vec3 landingPushVector;
    s32 bit100000WasSet;
    s32 bit200000WasSet;
    u32 collisionMask;
    s32 lowestOffsetLength;
    s32 pushStrength;
    s32 dot;
    s32 value;
    BOOL rotationExceeded;

    secondNormal = gKartVec3UnitY;
    bit100000WasSet = (kart->mUnk_44 & 0x100000) ? 1 : 0;
    bit200000WasSet = (kart->mUnk_48 & 0x200000) ? 1 : 0;
    *groundNormal = kart->mGroundNormal;
    if (StartKartRespawnWaitIfBelowZero(kart) != FALSE) {
        return;
    }
    if (CollideSphereWithCourse(&kart->mCollisionCenter, &kart->mPrevCollisionCenter, &kart->mTurnedForward,
                                kart->mRadius, 1, kart->mCollisionSlot, &pushOut, &normal, &secondNormal,
                                &collisionFlags, &lowestOffset, &pointMotion, &headingDelta, &hitObjects) != 0) {
        collisionMask = collisionFlags & 0x1e34ef;
        VEC_Add(&kart->mPos, &pushOut, &kart->mPos);
        AdvanceCourseColorBlend(&kart->mKartModelsEntry->mCourseColorBlend, (collisionFlags & 0x3c000000) >> 26,
                                kart->mVelocityLength);
        SetKartCourseHitAttributeBit(kart, collisionFlags);
        AdvanceKartPointMotion(kart, collisionFlags, &pointMotion, headingDelta);
        if (collisionFlags & 0x200300) {
            ApplyKartCourseContact(kart, collisionFlags, &secondNormal);
            if (collisionMask != 0) {
                dot = VEC_DotProduct(&normal, &kart->mHitVelocity);
                kart->mHitVelocity.x -= MUL_FIXED12_NO_ROUND(normal.x, dot);
                kart->mHitVelocity.y -= MUL_FIXED12_NO_ROUND(normal.y, dot);
                kart->mHitVelocity.z -= MUL_FIXED12_NO_ROUND(normal.z, dot);
                dot = VEC_DotProduct(&normal, &kart->mPrevHitVelocity);
                kart->mPrevHitVelocity.x -= MUL_FIXED12_NO_ROUND(normal.x, dot);
                kart->mPrevHitVelocity.y -= MUL_FIXED12_NO_ROUND(normal.y, dot);
                kart->mPrevHitVelocity.z -= MUL_FIXED12_NO_ROUND(normal.z, dot);
            }
            kart->mCourseHitTimer = 3;
            if (((s32(*)(Kart *, u32, Vec3 *)) data_0217ac14)(kart, collisionFlags, &lowestOffset) != 0 ||
                (kart->mUnk_44 & 0x4000000)) {
                lowestOffsetLength = 0;
                if (LENGTH_SQUARED(lowestOffset) >= 0x10) {
                    lowestOffsetLength = Vec3NormalizeAndGetLengthUnchecked(&lowestOffset, &pushVector);
                }
                if (lowestOffsetLength != 0) {
                    pushStrength = 0x802;
                    if (kart->mUnk_44 & 0x4000000) {
                        pushStrength *= 3;
                    }
                    pushVector.x = -pushVector.x;
                    pushVector.y = -pushVector.y;
                    pushVector.z = -pushVector.z;
                    pushVector.x = MUL_FIXED12_NO_ROUND(pushVector.x, pushStrength);
                    pushVector.y = MUL_FIXED12_NO_ROUND(pushVector.y, pushStrength);
                    pushVector.z = MUL_FIXED12_NO_ROUND(pushVector.z, pushStrength);
                    kart->mCollisionPushVelocity = pushVector;
                    kart->mCollisionPushVelocity.y = -0x19a;
                }
                kart->mUnk_44 |= 0x200;
            } else {
                kart->mCollisionPushVelocity = gKartVec3Zero;
                kart->mUnk_44 &= ~0x200;
            }
        } else {
            kart->mUnk_44 &= ~0x80;
            if (kart->mCourseHitTimer > 0) {
                kart->mCourseHitTimer--;
            }
        }
        if (collisionFlags & 0x8c10) {
            if ((kart->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && (collisionFlags & 0x10)) {
                if (bit200000WasSet == 0) {
                    ApplyCourseSoundTableEntry((u16) ((PickCollisionHitValue(0x10) & 0xe0) >> 5));
                }
                kart->mUnk_48 |= 0x200000;
            }
            if (collisionFlags & 0x8c00) {
                if (!(collisionFlags & 0x400) || !(kart->mUnk_44 & 0x80) || (collisionFlags & 0x800)) {
                    StartKartRespawnWait(kart, collisionFlags);
                }
            }
        }
        if (collisionFlags & 0x400000) {
            SetKartItemLinkFromHitValue(&(gKartItems)[kart->mIndex],
                                        (u16) ((PickCollisionHitValue(0x400000) & 0xe0) >> 5));
            if (kart->mUnk_4c & 0x10000000) {
                ResetKartKillerCursorTo(&kart->mItemEffectData.mKillerCursor,
                                        (RacePointLink *) (gKartItems)[kart->mIndex].mItemLink.mLink);
            }
            if ((kart->mUnk_7c & 2) && (collisionFlags & 0x400000) && kart->mState != KART_STATE_LAUNCH_DOUBLE_FLIP) {
                CallKartAiRequestLink(kart->mAi);
            }
        }
        if (collisionMask != 0) {
            *groundNormal = normal;
            if (LENGTH_SQUARED(*groundNormal) >= 0x10) {
                kart->mUnk_48 &= ~0x10000000;
                kart->mAirTiltAngleOffset = 0;
                RefreshKartSurface(kart);
                if ((collisionFlags & 0x20000) && !(kart->mUnk_4c & 0x10000040) && !(kart->mUnk_7c & 0x402000)) {
                    kart->mUnk_4c |= 0x40000000;
                    kart->mAttractorIndex = (PickCollisionHitValue(0x20000) & 0xe0) >> 5;
                } else {
                    kart->mUnk_4c &= ~0x40000000;
                }
                AdvanceKartQuaternionBlendFactor(kart, groundNormal);
                if (kart->mVerticalSpeed < 0) {
                    kart->mVerticalSpeed = (kart->mUnk_48 & KART_48_ON_BOOST_SURFACE) ? -0x2b9 : -0xd9d;
                }
                ApplyKartLanding(kart, groundNormal);
                if (collisionFlags & 0x80000000) {
                    kart->mPointMotion.y = 0;
                }
                kart->mUnk_44 |= KART_44_ON_GROUND;
                if (kart->mForwardSpeed != 0 || TryHoldKartStill(kart, collisionFlags, &hitObjects) == FALSE) {
                    StopKartStillHold(kart);
                    if (((s32(*)(Kart *, u32, Vec3 *)) data_0217ac14)(kart, collisionFlags, &lowestOffset) != 0) {
                        lowestOffsetLength = 0;
                        if (LENGTH_SQUARED(lowestOffset) >= 0x10) {
                            lowestOffsetLength = Vec3NormalizeAndGetLengthUnchecked(&lowestOffset, &landingPushVector);
                        }
                        if (lowestOffsetLength != 0) {
                            pushStrength = 0x802;
                            if (kart->mUnk_44 & 0x4000000) {
                                pushStrength *= 3;
                            }
                            landingPushVector.x = -landingPushVector.x;
                            landingPushVector.y = -landingPushVector.y;
                            landingPushVector.z = -landingPushVector.z;
                            landingPushVector.x = MUL_FIXED12_NO_ROUND(landingPushVector.x, pushStrength);
                            landingPushVector.y = MUL_FIXED12_NO_ROUND(landingPushVector.y, pushStrength);
                            landingPushVector.z = MUL_FIXED12_NO_ROUND(landingPushVector.z, pushStrength);
                            kart->mCollisionPushVelocity = landingPushVector;
                            kart->mCollisionPushVelocity.y = -0x19a;
                        }
                        kart->mUnk_44 |= 0x200;
                    } else {
                        kart->mCollisionPushVelocity = gKartVec3Zero;
                        kart->mUnk_44 &= ~0x200;
                    }
                }
            }
        } else {
            ClearKartGroundContact(kart, 0x10);
        }
    } else {
        ClearKartGroundContact(kart, 0x90);
    }
    if (kart->mLandingTimer > 0) {
        kart->mLandingTimer--;
    }
    if (IsWaterHeightUsed()) {
        ApplyKartWaterDepth(kart);
    }
    if ((kart->mUnk_4c & 0x40000000) && kart->mState == KART_STATE_NORMAL) {
        ApplyKartAttractorPull(kart, groundNormal, bit100000WasSet);
    }
    kart->mAttractorPullSpeed = MUL_FIXED12_NO_ROUND(kart->mAttractorPullSpeed, 0xf33);
    value = kart->mAttractorPullSpeed;
    if ((value > 0 ? value : -value) < 0x29) {
        kart->mAttractorPullSpeed = 0;
    }
    UpdateKartAirborne(kart);
    if (!(kart->mUnk_4c & 0x20)) {
        return;
    }
    kart->mYRotationAngleSum += kart->mYRotationAnglePerFrame;
    rotationExceeded = FALSE;
    value = kart->mYRotationAngleSum;
    if ((value > 0 ? value : -value) > kart->mYRotationCount * 0xffff) {
        kart->mYRotationAngle = 0;
        rotationExceeded = TRUE;
    } else {
        kart->mYRotationAngle += kart->mYRotationAnglePerFrame;
    }
    kart->mUnk_4c |= 2;
    if (rotationExceeded == FALSE) {
        return;
    }
    kart->mYRotationAngle = 0;
    kart->mUnk_4c &= ~0x20;
}
