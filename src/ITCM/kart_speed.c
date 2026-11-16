#include "ITCM/kart_speed.h"
#include "ITCM/kart_motion.h"
#include "ITCM/collision_slots.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Kart/kart_scale_surface_tables.h"
#include "Main/Kart/kart_participant_record.h"
#include "Main/Kart/kart_reset.h"

void AdvanceKartOffsetCycleIndex(Kart *kart) {
    kart->mOffsetCycleIndex = kart->mOffsetCycleIndex + 1;
    if (kart->mOffsetCycleIndex >= KART_OFFSET_CYCLE_COUNT) {
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
    if (SQUARE_SUM3(kart->mVelocity.x, kart->mVelocity.y, kart->mVelocity.z) >=
        0x10) {
        length = Vector3_MaybeNormalize(&kart->mVelocity, &kart->mVelocityDirection);
    }
    kart->mVelocityLength = length;
    if (kart->mVelocityLength > KART_VELOCITY_LENGTH_MAX) {
        kart->mVelocityLength = KART_VELOCITY_LENGTH_MAX;
        kart->mVelocity.x = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.x, KART_VELOCITY_LENGTH_MAX);
        kart->mVelocity.y = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.y, KART_VELOCITY_LENGTH_MAX);
        kart->mVelocity.z = MUL_FIXED12_NO_ROUND(kart->mVelocityDirection.z, KART_VELOCITY_LENGTH_MAX);
    }
}

void AdvanceKartQuaternionFromVector(Kart *kart, Vec3 *target) {
    Vec4 fromUpQuaternion;
    Vec4 fromGroundQuaternion;
    Vec4 *kartQuaternion = &kart->mAirTiltQuaternion;
    s32 succeeded;

    succeeded = TryQuaternionFromVectors(&fromUpQuaternion, &g_UnitY_VecFx32, target);
    TryQuaternionFromVectors(&fromGroundQuaternion, &kart->mGroundNormal, target);
    QuaternionMultiply(&fromGroundQuaternion, kartQuaternion, kartQuaternion);
    if (succeeded != 0) {
        if ((fromUpQuaternion.wComponent < 0 && kartQuaternion->wComponent > 0) ||
            (fromUpQuaternion.wComponent > 0 && kartQuaternion->wComponent < 0)) {
            kartQuaternion->x = -fromUpQuaternion.x;
            kartQuaternion->y = 0;
            kartQuaternion->z = -fromUpQuaternion.z;
            kartQuaternion->wComponent = -fromUpQuaternion.wComponent;
            kart->mDriveFlags = kart->mDriveFlags | KART_DRIVE_QUATERNION_FLIPPED;
        } else {
            kartQuaternion->x = fromUpQuaternion.x;
            kartQuaternion->y = 0;
            kartQuaternion->z = fromUpQuaternion.z;
            kartQuaternion->wComponent = fromUpQuaternion.wComponent;
            kart->mDriveFlags = kart->mDriveFlags & ~KART_DRIVE_QUATERNION_FLIPPED;
        }
    }
    QuaternionNormalize(kartQuaternion, kartQuaternion);
}
