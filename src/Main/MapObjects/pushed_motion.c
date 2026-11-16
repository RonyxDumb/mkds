#include "Main/MapObjects/pushed_motion.h"
#include "Main/MapObjects/map_object_response_and_quaternion_math.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Kart/kart_drift.h"

#include "fixed_vector_math.h"

const Vec3 gPushedMotionFallbackDirection = {0x1000, 0, 0};
const Vec3 gVec3UnitX = {0x1000, 0, 0};
const Vec3 gPushedMotionDefaultVelocity = {0, 0, 0};

void InitPushedMotion(PushedObject *object, s32 lowestY, u32 gravity, u16 angleStep, u32 upwardSpeed, s32 pushSpeed) {
    object->mMotion.mLowestY = lowestY;
    object->mMotion.mGravity = gravity;
    object->mMotion.mAngleIncreasing = 1;
    object->mMotion.mAngle = 0;
    object->mMotion.mAngleStep = angleStep;
    object->mMotion.mUpwardSpeed = upwardSpeed;
    object->mMotion.mPushSpeed = pushSpeed;
}

BOOL AdvancePushedMotion(PushedObject *object) {
    if (object->mMotion.mAngleIncreasing) {
        object->mMotion.mAngle = object->mMotion.mAngle + object->mMotion.mAngleStep;
    } else {
        object->mMotion.mAngle = object->mMotion.mAngle - object->mMotion.mAngleStep;
    }
    object->mMapObject.mPosStep.y = object->mMapObject.mPosStep.y - object->mMotion.mGravity;
    VecFx32_Add(&object->mMapObject.mPos, &object->mMapObject.mPosStep, &object->mMapObject.mPos);
    return object->mMapObject.mPos.y < object->mMotion.mLowestY;
}

void SetPushedMotionFromKart(PushedObject *object, Kart *other) {
    Vec3 offset;
    s32 pushSpeed;

    VecFx32_Subtract(&object->mMapObject.mPos, &other->mPos, &offset);
    if ((s64) offset.z * other->mVelocity.x - (s64) offset.x * other->mVelocity.z < 0) {
        s32 forwardX = other->mTurnedForward.x;
        s32 forwardZ = other->mTurnedForward.z;
        offset.z = -forwardX;
        offset.x = forwardZ;
        offset.y = 0;
        object->mMotion.mAngleIncreasing = 1;
    } else {
        s32 forwardX = other->mTurnedForward.x;
        s32 forwardZ = -other->mTurnedForward.z;
        offset.z = forwardX;
        offset.x = forwardZ;
        offset.y = 0;
        object->mMotion.mAngleIncreasing = 0;
    }
    pushSpeed = object->mMotion.mPushSpeed;
    object->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(offset.x, pushSpeed);
    object->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(offset.y, pushSpeed);
    object->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(offset.z, pushSpeed);
    object->mMapObject.mPosStep.x = object->mMapObject.mPosStep.x + (other->mVelocity.x >> 1);
    object->mMapObject.mPosStep.z = object->mMapObject.mPosStep.z + (other->mVelocity.z >> 1);
    object->mMapObject.mPosStep.y = object->mMotion.mUpwardSpeed;
}

void SetPushedMotionFromItemObject(PushedObject *object, const ItemObject *other) {
    Vec3 out;
    Vec3 otherPoint;
    Vec3 otherVector;
    s32 pushSpeed;

    otherPoint = other ? other->mPos : object->mMapObject.mPos;
    otherVector = other ? other->mVelocity : gPushedMotionDefaultVelocity;
    VecFx32_Subtract(&object->mMapObject.mPos, &otherPoint, &out);
    if ((s64) out.z * otherVector.x - (s64) out.x * otherVector.z < 0) {
        if (Vec3NormalizeXZAndGetLengthOrZero(&otherVector, &out) == 0) {
            out = gVec3UnitX;
        } else {
            s32 directionX = out.x;
            s32 directionZ = out.z;
            out.z = -directionX;
            out.x = directionZ;
            out.y = 0;
        }
        object->mMotion.mAngleIncreasing = 1;
    } else {
        if (Vec3NormalizeXZAndGetLengthOrZero(&otherVector, &out) == 0) {
            out = gPushedMotionFallbackDirection;
        } else {
            s32 directionX = out.x;
            s32 directionZ = -out.z;
            out.z = directionX;
            out.x = directionZ;
            out.y = 0;
        }
        object->mMotion.mAngleIncreasing = 0;
    }
    pushSpeed = object->mMotion.mPushSpeed;
    object->mMapObject.mPosStep.x = MUL_FIXED12_NO_ROUND(out.x, pushSpeed);
    object->mMapObject.mPosStep.y = MUL_FIXED12_NO_ROUND(out.y, pushSpeed);
    object->mMapObject.mPosStep.z = MUL_FIXED12_NO_ROUND(out.z, pushSpeed);
    object->mMapObject.mPosStep.x = object->mMapObject.mPosStep.x + (otherVector.x >> 1);
    object->mMapObject.mPosStep.z = object->mMapObject.mPosStep.z + (otherVector.z >> 1);
    object->mMapObject.mPosStep.y = object->mMotion.mUpwardSpeed;
}
