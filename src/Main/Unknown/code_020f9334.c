#include "Main/Unknown/code_020f9334.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d6000.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_02109000.h"
#include "code_02147cd8.h"

BOOL IsItemObjectOldAndResting(ItemObject *item) {
    if (item->mAgeFrames > 0x12c && (item->mFlags & 0x8000) != 0 && item->mAdvance == AdvanceRestingItemObject) {
        return TRUE;
    }
    return FALSE;
}

void StartItemObjectReleaseIfOldResting(ItemObject *item) {
    if (item->mAgeFrames <= 0x12c) {
        return;
    }
    if ((item->mFlags & 0x8000) == 0) {
        return;
    }
    if (item->mAdvance != AdvanceRestingItemObject) {
        return;
    }
    StartItemObjectReleaseTimerSynced(item, 1);
}

void StartItemObjectReleaseOnTimeout(ItemObject *item) {
    if ((item->mFlags & 0x8000) != 0) {
        StartItemObjectReleaseTimerSynced(item, 1);
        return;
    }
    item->mVelocity.x = MUL_FIXED12_NO_ROUND(item->mVelocity.x, 0x99a);
    item->mVelocity.y = MUL_FIXED12_NO_ROUND(item->mVelocity.y, 0x99a);
    item->mVelocity.z = MUL_FIXED12_NO_ROUND(item->mVelocity.z, 0x99a);
    FadeOutUsedUpItemObject(item, 1);
}

void ResetItemObject(ItemObject *item, s32 kind) {
    void (*reset)(void *);

    reset = gItemKinds[kind].mReset;
    item->mKind = kind;
    item->mFlags = 0;
    item->mPendingUpdateCount = 0;
    item->mScale.x = 0;
    item->mScale.y = 0;
    item->mScale.z = 0;
    item->mUnk_100 = 0;
    item->mCourseRadius = 0x7b;
    item->mRadius = 0x7b;
    item->mAlpha = 0x1f;
    item->mCollisionBits = 0;
    item->mCourseReleaseTimer = 0;
    item->mFramesSinceCourseHit = 5;
    item->mBounce = NULL;
    item->mPosPointer = &item->mPos;
    item->mCollisionSlotIndex = -1;
    item->mCollisionHitLink->mObject = NULL;
    if (gRaceSetup->mMode == 5) {
        item->mFlags |= 0x8000000;
    }
    item->mOwnerKartIndexAndFlags |= gItemObjectOwnerExcludedBit;
    InitCourseColorBlend(&item->mColorBlend, 1);
    item->mKartLightColor = NULL;
    if (reset != NULL) {
        reset(item);
    }
    item->mKartSoundMask = 0;
}

void ResetItemObjectAtPos(ItemObject *item, s32 kind, u16 ownerAndFlags, Vec3 *pos) {
    item->mPos = *pos;
    item->mOwnerKartIndexAndFlags = ownerAndFlags;
    ResetItemObject(item, kind);
    if ((item->mFlags & 0x8000000) == 0) {
        return;
    }
    item->mId = ComputeItemObjectId(item);
}

void ReleaseItemObject(ItemObject *item) {
    enum { K0 } kind;

    if (item->mCollisionSlotIndex != -1) {
        item->mCollisionSlotIndex = FreeCollisionSlot(item->mCollisionSlotIndex);
    }
    if ((item->mFlags & 0x400000) != 0) {
        ReleaseSoundSourceWrapper(&item->mSoundSource);
        item->mSoundSource.mTrackParamsFunction = NULL;
        item->mFlags &= ~0x400000;
    }
    item->mFlags |= 4;
    kind = item->mKind;
    if (gItemKinds[kind].mRelease != NULL) {
        gItemKinds[kind].mRelease(item);
    }
}

void SetItemObjectPlacement(ItemObject *itemParam, Vec3 *prevPos, Vec3 *normal, CourseColorBlend *colorBlend,
                            s32 param_5) {
    ItemObject *item = itemParam;
    item->mPrevPos = *prevPos;
    if (colorBlend != NULL) {
        item->mColorBlend = *colorBlend;
    } else {
        InitCourseColorBlend(&item->mColorBlend, 1);
    }
    item->mNormal = *normal;
    item->mUnk_116 = param_5 != 0 ? 0 : 5;
}

s32 DoesItemObjectHurtKart(ItemObject *item) {
    return gItemKinds[item->mKind].mHurtsKart;
}

BOOL IsItemObjectOverlappingKart(ItemObject *item, Kart *kart) {
    Vec3 offset;
    s32 hitRadius;

    if (item->mCollisionSlotIndex == -1 || kart->mIndex == (u16) ((item->mOwnerKartIndexAndFlags & 0x4000) != 0
                                                                      ? (u16) (item->mOwnerKartIndexAndFlags & ~0xff00)
                                                                      : 8)) {
        return FALSE;
    }
    hitRadius = kart->mRadius + item->mRadius;
    offset.x = item->mPos.x - kart->mPointAlongUp.x;
    offset.y = item->mPos.y - kart->mPointAlongUp.y;
    offset.z = item->mPos.z - kart->mPointAlongUp.z;
    return LENGTH_SQUARED(offset) < (s64) hitRadius * hitRadius;
}

BOOL IsItemObjectOverlappingSphere(ItemObject *item, Vec3 *center, s32 radius) {
    Vec3 offset;
    s32 sumRadius;

    sumRadius = radius + item->mRadius;
    offset.x = item->mPos.x - center->x;
    offset.y = item->mPos.y - center->y;
    offset.z = item->mPos.z - center->z;
    return LENGTH_SQUARED(offset) < (s64) sumRadius * sumRadius;
}

void CollideItemObjectWithItemObject(ItemObject *item, ItemObject *other) {
    Vec3 itemVelocity;
    s32 hitType;
    s32 otherHitType;

    if (other->mCollisionSlotIndex == -1) {
        return;
    }
    if ((other->mFlags & 0x1000) != 0) {
        return;
    }
    if ((other->mFlags & 0x8000) == 0) {
        if (item->mCreationNumber > other->mCreationNumber) {
            return;
        }
    }
    if ((item->mFlags & 0x10000000) != 0 && (other->mFlags & 0x10000000) != 0) {
        if (GetItemObjectHitType(item, other) != 1 && GetItemObjectHitType(other, item) != 1) {
            return;
        }
    }
    if (IsItemObjectOverlappingSphere(item, &other->mPos, other->mRadius) == FALSE) {
        if (IsItemObjectOverlappingSphere(item, &other->mPrevPos, other->mRadius) == FALSE) {
            return;
        }
        if (IsItemObjectOverlappingSphere(other, &item->mPrevPos, item->mRadius) == FALSE) {
            return;
        }
    }
    itemVelocity = item->mVelocity;
    hitType = GetItemObjectHitType(item, other);
    otherHitType = GetItemObjectHitType(other, item);
    ApplyItemObjectHitType(item, hitType, &other->mPos, &other->mVelocity, NULL);
    ApplyItemObjectHitType(other, otherHitType, &item->mPos, &itemVelocity, NULL);
    if (item->mKind == 1) {
        StartTargetKartSoundOnOwnItemHit(item, hitType, other);
    }
    if (other->mKind != 1) {
        return;
    }
    StartTargetKartSoundOnOwnItemHit(other, otherHitType, item);
}

void ApplyMapObjectHitToItemObject(ItemObject *itemParam, MapObject *mapObjectParam) {
    Vec3 a;
    Vec3 otherPos;
    s32 firstResponse;
    MapObject *reportedMapObject;
    ItemObject *item = itemParam;
    MapObject *mapObject = mapObjectParam;

    if (IsSphereHittingMapObject(&item->mPos, item->mRadius, mapObject, &a) == FALSE) {
        return;
    }
    if ((mapObject->mFlags & 0x40) == 0 && (item->mFlags & 0x80000) == 0 &&
        DoesItemObjectRespondToMapObject(item->mKind, mapObject) != 0) {
        VEC_Add(&item->mPos, &a, &item->mPos);
    }
    switch (CollideItemObjectWithMapObject(item, mapObject, &firstResponse)) {
        case 1:
            otherPos.x = mapObject->mPos.x;
            otherPos.y = item->mPos.y;
            otherPos.z = mapObject->mPos.z;
            a = otherPos;
            if (firstResponse == 1 || (mapObject->mDistanceSquaredAndFlags & 0x80000000) != 0) {
                mapObject->mDistanceSquaredAndFlags &= ~0x80000000;
                reportedMapObject = mapObject;
            } else {
                mapObject->mDistanceSquaredAndFlags &= ~0x80000000;
                reportedMapObject = NULL;
            }
            ApplyItemObjectHitType(item, 1, &a, &mapObject->mUnk_10, reportedMapObject);
            item->mOwnerKartIndexAndFlags &= ~0x4000;
            return;
        case 2:
            if (firstResponse == 1 || (mapObject->mDistanceSquaredAndFlags & 0x80000000) != 0) {
                mapObject->mDistanceSquaredAndFlags &= ~0x80000000;
                reportedMapObject = mapObject;
            } else {
                mapObject->mDistanceSquaredAndFlags &= ~0x80000000;
                reportedMapObject = NULL;
            }
            ApplyItemObjectHitType(item, 2, &mapObject->mPos, &mapObject->mUnk_10, reportedMapObject);
            return;
    }
}

void LandItemObjectIfOnGround(ItemObject *item, Vec3 *pos, Vec3 *velocity, s32 minFallSpeed, Vec3 *normal) {
    Vec3 lowerPos;
    u32 collisionBits;
    s32 x;
    s32 y;
    s32 z;

    collisionBits = 0;
    z = pos->z;
    y = pos->y - item->mCourseRadius;
    x = pos->x;
    lowerPos.x = x;
    lowerPos.y = y;
    lowerPos.z = z;

    CollideSphereWithCourse(&lowerPos, pos, 0, item->mCourseRadius >> 1, 0x24, item->mCollisionSlotIndex, NULL, NULL,
                            NULL, &collisionBits, NULL, NULL, NULL, NULL);
    if ((collisionBits & 0x1e34ef) != 0 || (item->mCollisionBits & 0x80000) != 0) {
        if ((item->mFlags & 0x4000000) != 0) {
            return;
        }
        item->mFlags |= 8;
        item->mNormal = *normal;
        return;
    }
    velocity->z = 0;
    velocity->x = velocity->z;
    if (velocity->y > 0) {
        velocity->y = 0;
        return;
    }
    if (velocity->y > -minFallSpeed) {
        velocity->y = -minFallSpeed;
    }
}
