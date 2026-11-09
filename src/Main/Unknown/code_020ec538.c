#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0206bcb0.h"

#include "Main/Unknown/code_020d6000.h"
#include "code_02147cd8.h"

const Vec3 data_02159588 = {0x1000, 0, 0};
const Vec3 gVec3UnitX = {0x1000, 0, 0};
const Vec3 data_02159594 = {0, 0, 0};

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
    object->mMapObject.mUnk_10.y = object->mMapObject.mUnk_10.y - object->mMotion.mGravity;
    VEC_Add(&object->mMapObject.mPos, &object->mMapObject.mUnk_10, &object->mMapObject.mPos);
    return object->mMapObject.mPos.y < object->mMotion.mLowestY;
}

void SetPushedMotionFromKart(PushedObject *object, Kart *other) {
    Vec3 offset;
    s32 pushSpeed;

    VEC_Subtract(&object->mMapObject.mPos, &other->mPos, &offset);
    if ((s64) offset.z * other->mVelocity.x - (s64) offset.x * other->mVelocity.z < 0) {
        s32 x = other->mTurnedForward.x;
        s32 z = other->mTurnedForward.z;
        offset.z = -x;
        offset.x = z;
        offset.y = 0;
        object->mMotion.mAngleIncreasing = 1;
    } else {
        s32 x = other->mTurnedForward.x;
        s32 z = -other->mTurnedForward.z;
        offset.z = x;
        offset.x = z;
        offset.y = 0;
        object->mMotion.mAngleIncreasing = 0;
    }
    pushSpeed = object->mMotion.mPushSpeed;
    object->mMapObject.mUnk_10.x = ((s64) offset.x * pushSpeed) >> 12;
    object->mMapObject.mUnk_10.y = ((s64) offset.y * pushSpeed) >> 12;
    object->mMapObject.mUnk_10.z = ((s64) offset.z * pushSpeed) >> 12;
    object->mMapObject.mUnk_10.x = object->mMapObject.mUnk_10.x + (other->mVelocity.x >> 1);
    object->mMapObject.mUnk_10.z = object->mMapObject.mUnk_10.z + (other->mVelocity.z >> 1);
    object->mMapObject.mUnk_10.y = object->mMotion.mUpwardSpeed;
}

void SetPushedMotionFromItemObject(PushedObject *object, const ItemObject *other) {
    Vec3 out;
    Vec3 otherPoint;
    Vec3 otherVector;
    s32 pushSpeed;

    otherPoint = other ? other->mPos : object->mMapObject.mPos;
    otherVector = other ? other->mVelocity : data_02159594;
    VEC_Subtract(&object->mMapObject.mPos, &otherPoint, &out);
    if ((s64) out.z * otherVector.x - (s64) out.x * otherVector.z < 0) {
        if (Vec3NormalizeXZAndGetLengthOrZero(&otherVector, &out) == 0) {
            out = gVec3UnitX;
        } else {
            s32 x = out.x;
            s32 z = out.z;
            out.z = -x;
            out.x = z;
            out.y = 0;
        }
        object->mMotion.mAngleIncreasing = 1;
    } else {
        if (Vec3NormalizeXZAndGetLengthOrZero(&otherVector, &out) == 0) {
            out = data_02159588;
        } else {
            s32 x = out.x;
            s32 z = -out.z;
            out.z = x;
            out.x = z;
            out.y = 0;
        }
        object->mMotion.mAngleIncreasing = 0;
    }
    pushSpeed = object->mMotion.mPushSpeed;
    object->mMapObject.mUnk_10.x = ((s64) out.x * pushSpeed) >> 12;
    object->mMapObject.mUnk_10.y = ((s64) out.y * pushSpeed) >> 12;
    object->mMapObject.mUnk_10.z = ((s64) out.z * pushSpeed) >> 12;
    object->mMapObject.mUnk_10.x = object->mMapObject.mUnk_10.x + (otherVector.x >> 1);
    object->mMapObject.mUnk_10.z = object->mMapObject.mUnk_10.z + (otherVector.z >> 1);
    object->mMapObject.mUnk_10.y = object->mMotion.mUpwardSpeed;
}
