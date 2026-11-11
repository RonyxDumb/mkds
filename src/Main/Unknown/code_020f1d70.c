#include "Main/Unknown/code_020f1d70.h"

#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f7000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02109054.h"
#include "code_02147cd8.h"

void InitItemObjectThrow(void *objectParam, ItemInUse *inUseParam, s32 hitLimit, s32 throwForward, s32 unused,
                         s32 baseSpeed) {
    DirectedItemObject *object;
    ItemInUse *inUse;
    s32 dot;
    s32 negatedZ;
    s32 directionX;

    object = objectParam;
    inUse = inUseParam;
    if (throwForward != 0) {
        object->mSpeed = ComputeItemThrowForward(inUse, baseSpeed, 0x1000, 0x3800, &object->mDirection);
    } else {
        Vec3 *direction = &object->mDirection;
        object->mSpeed = ComputeItemThrowBackward(inUse, 0x3000, 0x1000, 0x4000, direction);
    }
    object->mSurfaceDirection = object->mDirection;
    negatedZ = -object->mDirection.z;
    directionX = object->mDirection.x;
    object->mSideDirection.z = directionX;
    object->mSideDirection.x = negatedZ;
    object->mSideDirection.y = 0;
    object->mItemObject.mVelocity.x = MUL_FIXED12_NO_ROUND(object->mDirection.x, object->mSpeed);
    object->mItemObject.mVelocity.z = MUL_FIXED12_NO_ROUND(object->mDirection.z, object->mSpeed);
    if (throwForward == 0) {
        VEC_Add(&object->mItemObject.mVelocity, &inUse->mKart->mPointMotion, &object->mItemObject.mVelocity);
    }
    if (inUse->mKart->mUnk_48 & KART_48_ON_BOOST_SURFACE) {
        dot = VEC_DotProduct(&inUse->mKartOrientation.mRows[1], &object->mItemObject.mVelocity);
        {
            s32 alongX, alongY, alongZ;

            alongX = MUL_FIXED12_NO_ROUND(inUse->mKartOrientation.mRows[1].x, dot);
            alongY = MUL_FIXED12_NO_ROUND(inUse->mKartOrientation.mRows[1].y, dot);
            alongZ = MUL_FIXED12_NO_ROUND(inUse->mKartOrientation.mRows[1].z, dot);
            object->mItemObject.mVelocity.x = (s32) (object->mItemObject.mVelocity.x - alongX);
            object->mItemObject.mVelocity.y -= alongY;
            object->mItemObject.mVelocity.z -= alongZ;
        }
        VEC_MultAdd(-0x1000, &inUse->mKartOrientation.mRows[1], &object->mItemObject.mVelocity,
                    &object->mItemObject.mVelocity);
    }
    if (object->mItemObject.mScale.z < 0xccd) {
        object->mItemObject.mScale.x = 0xccd;
        object->mItemObject.mScale.y = 0xccd;
        object->mItemObject.mScale.z = 0xccd;
        if (throwForward != 0) {
            object->mItemObject.mPos = inUse->mKart->mCollisionCenter;
            VEC_MultAdd(object->mItemObject.mScale.z * 10, &inUse->mKartOrientation.mRows[2], &object->mItemObject.mPos,
                        &object->mItemObject.mPos);
        }
    }
    if (hitLimit < 0) {
        object->mHitsRemaining = 0;
        object->mHasHitLimit = FALSE;
    } else {
        object->mHitsRemaining = hitLimit;
        object->mHasHitLimit = TRUE;
    }
    object->mItemObject.mBounce = (void (*)(ItemObject *, Vec3 *, Vec3 *)) DeflectItemObjectOnHit;
    object->mUnk_160 = TRUE;
    object->mUnk_158 = unused;
    object->mUnk_164 = 4;
}

void ComputeItemSurfaceDirection(Vec3 *direction, Vec3 *normal, Vec3 *result) {
    s32 value;

    value = normal->y * normal->y;
    if (value < 0x10) {
        result->x = -direction->x;
        result->y = -direction->y;
        result->z = -direction->z;
        return;
    }
    result->x = normal->x >> 2;
    result->y = normal->y >> 2;
    result->z = normal->z >> 2;
    result->x = direction->x - result->x;
    result->z = direction->z - result->z;
    value = MUL_FIXED12_NO_ROUND(direction->x, normal->x) + MUL_FIXED12_NO_ROUND(direction->z, normal->z);
    result->y = -(value + result->y);
    result->y = FX_Div(result->y, normal->y);
    if (LENGTH_SQUARED(*result) >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(result, result);
    }
}

void SetItemObjectDirectionFromVelocity(ItemKouraR *item) {
    DirectedItemObject *object;
    Vec3 *normal;
    s32 speed;

    object = (DirectedItemObject *) item;
    speed = 0;
    normal = &object->mItemObject.mNormal;
    if ((s64) object->mItemObject.mVelocity.x * object->mItemObject.mVelocity.x +
            (s64) object->mItemObject.mVelocity.y * object->mItemObject.mVelocity.y +
            (s64) object->mItemObject.mVelocity.z * object->mItemObject.mVelocity.z >=
        0x10) {
        speed = Vec3NormalizeAndGetLengthUnchecked(&object->mItemObject.mVelocity, &object->mDirection);
    }
    object->mSpeed = speed;
    ComputeItemSurfaceDirection(&object->mDirection, normal, &object->mSurfaceDirection);
    Vec3CrossUnrounded(&object->mSurfaceDirection, normal, &object->mSideDirection);
    object->mItemObject.mBounce = (void (*)(ItemObject *, Vec3 *, Vec3 *)) DeflectItemObjectOnHit;
}

void DeflectItemObjectAlongSurfaceAndStartSound(DirectedItemObject *object, Vec3 *hitNormal) {
    Vec3 along;
    Vec3 *velocityDirection;
    Vec3 *flatDirection;
    s32 value;

    velocityDirection = &object->mSurfaceDirection;
    flatDirection = &object->mDirection;
    value = VEC_DotProduct(hitNormal, velocityDirection);
    along.x = MUL_FIXED12_NO_ROUND(hitNormal->x, value);
    along.y = MUL_FIXED12_NO_ROUND(hitNormal->y, value);
    along.z = MUL_FIXED12_NO_ROUND(hitNormal->z, value);
    object->mSurfaceDirection.x -= along.x;
    velocityDirection->y -= along.y;
    velocityDirection->z -= along.z;
    if (object->mUnk_160 != FALSE) {
        VEC_Subtract(velocityDirection, &along, velocityDirection);
    }
    if ((s64) velocityDirection->x * velocityDirection->x + (s64) velocityDirection->y * velocityDirection->y +
            (s64) velocityDirection->z * velocityDirection->z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(velocityDirection, velocityDirection);
    }
    value = velocityDirection->z;
    flatDirection->x = velocityDirection->x;
    flatDirection->y = 0;
    flatDirection->z = value;
    if ((s64) flatDirection->x * flatDirection->x + (s64) flatDirection->y * flatDirection->y +
            (s64) flatDirection->z * flatDirection->z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(flatDirection, flatDirection);
    }
    Vec3CrossUnrounded(flatDirection, &object->mItemObject.mNormal, &object->mSideDirection);
    StartSound(&object->mItemObject.mSoundSource, 0xd5, 0x7f, 0);
}

void DeflectItemObjectAndStartSound(DirectedItemObject *object, Vec3 *hitNormal, Vec3 *unused) {
    Vec3 along;
    Vec3 *direction;
    s32 normalDot;

    direction = &object->mDirection;
    normalDot = VEC_DotProduct(hitNormal, direction);
    along.x = MUL_FIXED12_NO_ROUND(hitNormal->x, normalDot);
    along.y = MUL_FIXED12_NO_ROUND(hitNormal->y, normalDot);
    along.z = MUL_FIXED12_NO_ROUND(hitNormal->z, normalDot);
    object->mDirection.x -= along.x;
    direction->y -= along.y;
    direction->z -= along.z;
    if (object->mUnk_160 != FALSE) {
        VEC_Subtract(direction, &along, direction);
    }
    if (LENGTH_SQUARED(*direction) >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(direction, direction);
    }
    object->mSurfaceDirection = *direction;
    Vec3CrossUnrounded(direction, &object->mItemObject.mNormal, &object->mSideDirection);
    object->mItemObject.mNormal.y += 1;
    StartSound(&object->mItemObject.mSoundSource, 0xd5, 0x7f, 0);
}

void AdvanceItemObjectMotion(DirectedItemObject *object, s32 targetSpeed) {
    Vec3 pushOut;
    Vec3 hitNormal;
    Vec3 unusedOut;
    Vec3 normalPart;
    Vec3 *pos;
    Vec3 *velocity;
    Vec3 *direction;
    s32 flag80000;
    s32 value;
    BOOL sameNormal;
    Vec3 *velocityAlias;

    pos = &object->mItemObject.mPos;
    velocity = &object->mItemObject.mVelocity;
    direction = &object->mDirection;
    VEC_Add(velocity, pos, pos);
    value = CollideSphereWithCourse(pos, &object->mItemObject.mPrevPos, 0, object->mItemObject.mCourseRadius,
                                    object->mUnk_164, object->mItemObject.mCollisionSlotIndex, &pushOut, &hitNormal,
                                    &unusedOut, &object->mItemObject.mCollisionBits, NULL, NULL, NULL, NULL);
    if (value != 0) {
        flag80000 = object->mItemObject.mCollisionBits & 0x80000;
        if (object->mUnk_158 != 0) {
            if (pushOut.y > 0) {
                pos->y += pushOut.y;
            }
        } else {
            VEC_Add(&pushOut, pos, pos);
        }
        if (object->mItemObject.mCollisionBits & 0x1e34ef) {
            sameNormal = hitNormal.x == object->mItemObject.mNormal.x && hitNormal.y == object->mItemObject.mNormal.y &&
                         hitNormal.z == object->mItemObject.mNormal.z;
            if (sameNormal == FALSE) {
                object->mItemObject.mNormal = hitNormal;
                object->mItemObject.mFlags |= 0x100;
                if (flag80000 != 0) {
                    value = VEC_DotProduct(&hitNormal, &object->mSurfaceDirection);
                    object->mSurfaceDirection.x =
                        (s32) (object->mSurfaceDirection.x - MUL_FIXED12_NO_ROUND(hitNormal.x, value));
                    object->mSurfaceDirection.y -= MUL_FIXED12_NO_ROUND(hitNormal.y, value);
                    object->mSurfaceDirection.z -= MUL_FIXED12_NO_ROUND(hitNormal.z, value);
                    if ((s64) object->mSurfaceDirection.x * object->mSurfaceDirection.x +
                            (s64) object->mSurfaceDirection.y * object->mSurfaceDirection.y +
                            (s64) object->mSurfaceDirection.z * object->mSurfaceDirection.z >=
                        0x10) {
                        Vec3NormalizeAndGetLengthUnchecked(&object->mSurfaceDirection, &object->mSurfaceDirection);
                    }
                    *direction = object->mSurfaceDirection;
                } else {
                    ComputeItemSurfaceDirection(direction, &hitNormal, &object->mSurfaceDirection);
                }
                Vec3CrossUnrounded(&object->mSurfaceDirection, &hitNormal, &object->mSideDirection);
            }
        }
        if (object->mItemObject.mCollisionBits & 0x214300) {
            if (object->mUnk_158 != 0) {
                pos->x += pushOut.x;
                pos->z += pushOut.z;
            }
            if (flag80000 != 0) {
                VEC_Subtract(&unusedOut, &object->mItemObject.mNormal, &unusedOut);
                DeflectItemObjectAlongSurfaceAndStartSound(object, &unusedOut);
            } else {
                unusedOut.y = 0;
                DeflectItemObjectAndStartSound(object, &unusedOut, NULL);
            }
            object->mItemObject.mOwnerKartIndexAndFlags &= ~0x4000;
            if (object->mHasHitLimit != FALSE) {
                object->mItemObject.mFlags |= 0x20;
                object->mHitsRemaining -= 1;
            }
        }
        value = object->mSpeed;
        velocity->x = MUL_FIXED12_NO_ROUND(object->mSurfaceDirection.x, value);
        velocity->y = MUL_FIXED12_NO_ROUND(object->mSurfaceDirection.y, value);
        velocity->z = MUL_FIXED12_NO_ROUND(object->mSurfaceDirection.z, value);
        if (object->mItemObject.mCollisionBits & 0x1e34ef) {
            pushOut.y = pos->y - object->mItemObject.mPrevPos.y;
            if (pushOut.y > 0x5000 && flag80000 == 0) {
                pushOut.y = 0x5000;
            }
            if (pushOut.y > velocity->y) {
                velocity->y = pushOut.y;
            }
        }
        if (object->mHitsRemaining < 0) {
            velocity->x = MUL_FIXED12_NO_ROUND(velocity->x, 0x23d);
            velocity->y = MUL_FIXED12_NO_ROUND(velocity->y, 0x23d);
            velocity->z = MUL_FIXED12_NO_ROUND(velocity->z, 0x23d);
            FadeOutUsedUpItemObject(&object->mItemObject, 1);
            return;
        }
        if ((object->mItemObject.mCollisionBits & 0x8000) && object->mItemObject.mKind != 5) {
            FadeOutItemObjectNoCallback(&object->mItemObject, 1);
            return;
        }
    }
    object->mSpeed += MUL_FIXED12_NO_ROUND(targetSpeed - object->mSpeed, 0x29);
    velocityAlias = &object->mItemObject.mVelocity;
    if (object->mItemObject.mCollisionBits & 0x1e34ef) {
        normalPart.x = object->mItemObject.mNormal.x >> 2;
        normalPart.y = object->mItemObject.mNormal.y >> 2;
        normalPart.z = object->mItemObject.mNormal.z >> 2;
        VEC_Subtract(velocityAlias, &normalPart, velocityAlias);
        return;
    }
    value = velocityAlias->y;
    if (value > 0) {
        velocityAlias->y -= 0x6b8;
        if (!(object->mItemObject.mFlags & 0x20000)) {
            return;
        }
        value = velocityAlias->y;
        if (value > 0xa000) {
            velocityAlias->y = velocityAlias->y >> 3;
            return;
        }
        velocityAlias->y = MUL_FIXED12_NO_ROUND(value, 0xe66);
    } else {
        velocityAlias->y -= 0x333;
        if (velocityAlias->y >= -0xa000) {
            return;
        }
        if (object->mItemObject.mFlags & 0x20000) {
            velocityAlias->y = -0xa000;
        }
    }
}

void ApplyItemObjectGravity(void *objectParam) {
    ItemObject *object;
    Vec3 *velocity;
    s32 verticalSpeed;

    object = objectParam;
    velocity = &object->mVelocity;
    verticalSpeed = velocity->y;
    if (verticalSpeed > 0) {
        velocity->y -= 0x6b8;
        if (!(object->mFlags & 0x20000)) {
            return;
        }
        verticalSpeed = velocity->y;
        if (verticalSpeed > 0xa000) {
            velocity->y = velocity->y >> 3;
            return;
        }
        velocity->y = MUL_FIXED12_NO_ROUND(verticalSpeed, 0xe66);
    } else {
        velocity->y -= 0x333;
        if (velocity->y >= -0xa000) {
            return;
        }
        if (object->mFlags & 0x20000) {
            velocity->y = -0xa000;
        }
    }
}

void ApplyItemObjectGravityWithGroundPull(ItemObject *object) {
    Vec3 *velocity;
    Vec3 normalPart;
    s32 verticalSpeed;

    velocity = &object->mVelocity;
    if (object->mCollisionBits & 0x1e34ef) {
        normalPart.x = object->mNormal.x >> 2;
        normalPart.y = object->mNormal.y >> 2;
        normalPart.z = object->mNormal.z >> 2;
        VEC_Subtract(velocity, &normalPart, velocity);
        return;
    }
    verticalSpeed = velocity->y;
    if (verticalSpeed > 0) {
        velocity->y -= 0x6b8;
        if (!(object->mFlags & 0x20000)) {
            return;
        }
        verticalSpeed = velocity->y;
        if (verticalSpeed > 0xa000) {
            velocity->y = velocity->y >> 3;
            return;
        }
        velocity->y = MUL_FIXED12_NO_ROUND(verticalSpeed, 0xe66);
    } else {
        velocity->y -= 0x333;
        if (velocity->y >= -0xa000) {
            return;
        }
        if (object->mFlags & 0x20000) {
            velocity->y = -0xa000;
        }
    }
}

void DeflectItemObjectOnHit(DirectedItemObject *object, Vec3 *otherVelocity, Vec3 *awayDirection) {
    Vec3 flatDirection;
    s32 speed;

    if (awayDirection->y > 0) {
        DeflectItemObjectAndStartSound(object, awayDirection, awayDirection);
    } else {
        flatDirection = *awayDirection;
        flatDirection.y = 0;
        DeflectItemObjectAndStartSound(object, &flatDirection, NULL);
    }
    speed = object->mSpeed;
    object->mItemObject.mVelocity.x = MUL_FIXED12_NO_ROUND(object->mSurfaceDirection.x, speed);
    object->mItemObject.mVelocity.y = MUL_FIXED12_NO_ROUND(object->mSurfaceDirection.y, speed);
    object->mItemObject.mVelocity.z = MUL_FIXED12_NO_ROUND(object->mSurfaceDirection.z, speed);
}

void InitItemObjectMotion(void *objectParam, s32 hitLimit, s32 reverse, s32 unused) {
    DirectedItemObject *object;
    s32 speed;
    s32 negatedZ;
    s32 directionX;

    object = objectParam;
    speed = 0;
    if ((s64) object->mItemObject.mVelocity.x * object->mItemObject.mVelocity.x +
            (s64) object->mItemObject.mVelocity.y * object->mItemObject.mVelocity.y +
            (s64) object->mItemObject.mVelocity.z * object->mItemObject.mVelocity.z >=
        0x10) {
        speed = Vec3NormalizeAndGetLengthUnchecked(&object->mItemObject.mVelocity, &object->mDirection);
    }
    object->mSpeed = speed;
    if (reverse != 0) {
        object->mSpeed = -object->mSpeed;
        object->mDirection.x = -object->mDirection.x;
        object->mDirection.y = -object->mDirection.y;
        object->mDirection.z = -object->mDirection.z;
    }
    object->mSurfaceDirection = object->mDirection;
    negatedZ = -object->mDirection.z;
    directionX = object->mDirection.x;
    object->mSideDirection.z = directionX;
    object->mSideDirection.x = negatedZ;
    object->mSideDirection.y = 0;
    if (hitLimit < 0) {
        object->mHitsRemaining = 0;
        object->mHasHitLimit = FALSE;
    } else {
        object->mHitsRemaining = hitLimit;
        object->mHasHitLimit = TRUE;
    }
    object->mItemObject.mBounce = (void (*)(ItemObject *, Vec3 *, Vec3 *)) DeflectItemObjectOnHit;
    object->mUnk_160 = TRUE;
    object->mUnk_158 = unused;
}

void SetItemObjectDirection(void *objectParam, const Vec3 *direction) {
    DirectedItemObject *object;
    Vec3 *normal;
    Vec3 projected;
    s32 dot;
    s32 speed;

    object = objectParam;
    object->mDirection.x = direction->x;
    object->mDirection.z = direction->z;
    normal = &object->mItemObject.mNormal;
    dot = VEC_DotProduct(normal, direction);
    projected.x = direction->x - MUL_FIXED12_NO_ROUND(normal->x, dot);
    projected.y = direction->y - MUL_FIXED12_NO_ROUND(normal->y, dot);
    projected.z = direction->z - MUL_FIXED12_NO_ROUND(normal->z, dot);
    object->mSurfaceDirection.x = normal->x >> 2;
    object->mSurfaceDirection.y = normal->y >> 2;
    object->mSurfaceDirection.z = normal->z >> 2;
    VEC_Subtract(&projected, &object->mSurfaceDirection, &object->mSurfaceDirection);
    if ((s64) object->mSurfaceDirection.x * object->mSurfaceDirection.x +
            (s64) object->mSurfaceDirection.y * object->mSurfaceDirection.y +
            (s64) object->mSurfaceDirection.z * object->mSurfaceDirection.z >=
        0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&object->mSurfaceDirection, &object->mSurfaceDirection);
    }
    speed = object->mSpeed;
    object->mItemObject.mVelocity.x = MUL_FIXED12_NO_ROUND(object->mSurfaceDirection.x, speed);
    object->mItemObject.mVelocity.z = MUL_FIXED12_NO_ROUND(object->mSurfaceDirection.z, speed);
    Vec3CrossUnrounded(direction, normal, &object->mSideDirection);
}
