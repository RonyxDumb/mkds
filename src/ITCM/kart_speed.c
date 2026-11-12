#include "ITCM/kart_speed.h"
#include "ITCM/kart_motion.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/collision_slots.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Unknown/unk_02154000.h"

void AdvanceKartOffsetCycleIndex(Kart *kart) {
    kart->mOffsetCycleIndex = kart->mOffsetCycleIndex + 1;
    if (kart->mOffsetCycleIndex >= 8) {
        kart->mOffsetCycleIndex = 0;
    }
    kart->mOffsetCycleAmount.x = gKartOffsetCycleX[kart->mOffsetCycleIndex];
    kart->mOffsetCycleAmount.y = gKartOffsetCycleY[kart->mOffsetCycleIndex];
    kart->mOffsetCycleAmount.z = gKartOffsetCycleZ[kart->mOffsetCycleIndex];
}

s32 LimitKartForwardSpeedAndGetScaled(Kart *kart) {
    BOOL isNegative;
    s32 speed = kart->mForwardSpeed;
    s32 value;
    s32 limit;
    s32 pullSpeed;
    u32 flags = kart->mDriveFlags;

    isNegative = speed < 0;

    speed = speed > 0 ? speed : -speed;
    pullSpeed = kart->mAttractorPullSpeed;
    value = kart->mSpeedLimit - pullSpeed;
    if ((flags & KART_DRIVE_BRAKE_HELD) && (kart->mMotionFlags & KART_MOTION_REVERSING)) {
        if (value > 0x3000) {
            value = 0x3000;
        }
    }
    limit = kart->mMapObjectVectorLength +
            (pullSpeed +
             MUL_FIXED12_NO_ROUND(value, MUL_FIXED12_NO_ROUND(kart->mSpeedLimitHitFactor, kart->mShrinkFactor)));
    if (speed > limit) {
        kart->mForwardSpeed = limit;
    } else {
        if (speed <= MUL_FIXED12_NO_ROUND(0x19a, kart->mSpeedLimitHitFactor) &&
            !(kart->mMotionFlags & KART_MOTION_NEAR_KART_HELD) &&
            !(flags & (KART_DRIVE_ACCEL_HELD | KART_DRIVE_BRAKE_HELD))) {
            kart->mForwardSpeed = 0;
        } else {
            kart->mForwardSpeed = speed;
        }
    }
    if (isNegative) {
        kart->mForwardSpeed *= -1;
    }
    limit = kart->mMapObjectVectorForwardDot;
    if (limit != 0) {
        if (limit > 0) {
            speed = kart->mForwardSpeed;
            if (speed < 0) {
                kart->mForwardSpeed = speed + limit;
                if (kart->mForwardSpeed > kart->mMapObjectVectorForwardDot) {
                    kart->mForwardSpeed = kart->mMapObjectVectorForwardDot;
                }
            } else {
                speed = speed > 0 ? speed : -speed;
                value = limit > 0 ? limit : -limit;
                if (value > speed) {
                    kart->mForwardSpeed = limit;
                }
            }
        } else {
            speed = kart->mForwardSpeed;
            if (speed > 0) {
                kart->mForwardSpeed = speed + limit;
                if (kart->mForwardSpeed < kart->mMapObjectVectorForwardDot) {
                    kart->mForwardSpeed = kart->mMapObjectVectorForwardDot;
                }
            } else {
                speed = speed > 0 ? speed : -speed;
                value = limit > 0 ? limit : -limit;
                if (value > speed) {
                    kart->mForwardSpeed = limit;
                }
            }
        }
    }
    return MUL_FIXED12_ROUNDED(kart->mForwardSpeed, 0x1000 - (kart->mAttractorPullSpeed >> 3));
}

void ScaleKartVelocityAndSetCappedLengthAndDirection(Kart *kart, s32 scale) {
    s32 length;

    kart->mVelocity.x = MUL_FIXED12_NO_ROUND(kart->mVelocity.x, scale);
    length = 0;
    kart->mVelocity.y = MUL_FIXED12_NO_ROUND(kart->mVelocity.y, scale);
    kart->mVelocity.z = MUL_FIXED12_NO_ROUND(kart->mVelocity.z, scale);
    if ((s64) kart->mVelocity.x * kart->mVelocity.x + (s64) kart->mVelocity.y * kart->mVelocity.y +
            (s64) kart->mVelocity.z * kart->mVelocity.z >=
        0x10) {
        length = Vec3NormalizeAndGetLengthUnchecked(&kart->mVelocity, &kart->mVelocityDirection);
    }
    kart->mVelocityLength = length;
    if (kart->mVelocityLength > 0xd000) {
        kart->mVelocityLength = 0xd000;
        kart->mVelocity.x = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.x, 0xd000);
        kart->mVelocity.y = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.y, 0xd000);
        kart->mVelocity.z = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.z, 0xd000);
    }
}

void AdvanceKartQuaternionFromVector(Kart *kart, Vec3 *target) {
    Vec4 fromUpQuaternion;
    Vec4 fromGroundQuaternion;
    Vec4 *kartQuaternion = &kart->mUnk_100_q;
    s32 succeeded;

    succeeded = TryQuaternionFromVectors(&fromUpQuaternion, &gKartVec3UnitY, target);
    TryQuaternionFromVectors(&fromGroundQuaternion, &kart->mGroundNormal, target);
    QuaternionMultiply(&fromGroundQuaternion, kartQuaternion, kartQuaternion);
    if (succeeded != 0) {
        if ((fromUpQuaternion.w < 0 && kartQuaternion->w > 0) || (fromUpQuaternion.w > 0 && kartQuaternion->w < 0)) {
            kartQuaternion->x = -fromUpQuaternion.x;
            kartQuaternion->y = 0;
            kartQuaternion->z = -fromUpQuaternion.z;
            kartQuaternion->w = -fromUpQuaternion.w;
            kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_QUATERNION_FLIPPED;
        } else {
            kartQuaternion->x = fromUpQuaternion.x;
            kartQuaternion->y = 0;
            kartQuaternion->z = fromUpQuaternion.z;
            kartQuaternion->w = fromUpQuaternion.w;
            kart->mDriveFlags = kart->mDriveFlags & ~KART_DRIVE_QUATERNION_FLIPPED;
        }
    }
    QuaternionNormalize(kartQuaternion, kartQuaternion);
}
