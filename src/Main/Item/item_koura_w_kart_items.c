#include "Main/Item/item_koura_w_kart_items.h"
#include "Main/Unknown/code_020fd254.h"
#include "code_02012b30.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Unknown/code_020fcf10.h"
#include "Main/Kart/kart_drift.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02147cd8.h"
#include "Main/Item/item_pool.h"
#include "Main/Unknown/code_020fcedc.h"
#include "Main/Unknown/code_020fcbb8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Kart/karts.h"

void ClearItemKouraWKartItemsAndAngle(ItemKouraW *item) {
    item->mKartItems = NULL;
    item->mAngle = 0x0u;
}

void SteerItemKouraWToAnglePoint(ItemKouraW *item, s32 maxStep, s32 angle, s32 radius, s32 gain, s32 oldWeight,
                                 s32 shift) {
    Vec3 vector;
    Vec3 *toTarget;
    Vec3 *pos;
    Vec3 *velocity;
    Kart *kart;
    s32 scaledRadius;

    kart = item->mKartItems->mKart;
    item->mKartForward = kart->mSignedTurnedForward;
    pos = &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos;
    velocity = &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity;
    toTarget = &item->mToTarget;
    if (kart->mMotionFlags & KART_MOTION_REVERSING) {
        item->mKartForward.x = -item->mKartForward.x;
        item->mKartForward.y = -item->mKartForward.y;
        item->mKartForward.z = -item->mKartForward.z;
    }
    Vec3CrossUnrounded(&item->mKartForward, &kart->mGroundNormal, &vector);
    scaledRadius = MUL_FIXED12_NO_ROUND(radius, FX_CosIdx(angle));
    item->mAnglePointOffset.x = MUL_FIXED12_NO_ROUND(vector.x, scaledRadius);
    item->mAnglePointOffset.y = MUL_FIXED12_NO_ROUND(vector.y, scaledRadius);
    item->mAnglePointOffset.z = MUL_FIXED12_NO_ROUND(vector.z, scaledRadius);
    scaledRadius = MUL_FIXED12_NO_ROUND(radius, FX_SinIdx(angle));
    VEC_MultAdd(scaledRadius, &item->mKartForward, &item->mAnglePointOffset, &item->mAnglePointOffset);
    VEC_MultAdd(0x1e000, &item->mKartForward, &item->mAnglePointOffset, &vector);
    if (IsKartRemovedOrRespawning(kart) == FALSE) {
        item->mKartDrawPos = kart->mDrawMatrixPos;
    }
    VEC_Add(&vector, &item->mKartDrawPos, &vector);
    VEC_Subtract(&vector, pos, toTarget);
    vector.x = MUL_FIXED12_NO_ROUND(toTarget->x, gain);
    vector.y = MUL_FIXED12_NO_ROUND(toTarget->y, gain);
    vector.z = MUL_FIXED12_NO_ROUND(toTarget->z, gain);
    if (LENGTH_SQUARED(vector) >= (s64) maxStep * maxStep) {
        if (LENGTH_SQUARED(vector) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&vector, &vector);
        }
        vector.x = MUL_FIXED12_NO_ROUND(vector.x, maxStep);
        vector.y = MUL_FIXED12_NO_ROUND(vector.y, maxStep);
        vector.z = MUL_FIXED12_NO_ROUND(vector.z, maxStep);
    }
    velocity->x = (velocity->x * (s32) oldWeight + vector.x) >> shift;
    velocity->y = (velocity->y * (s32) oldWeight + vector.y) >> shift;
    velocity->z = (velocity->z * oldWeight + vector.z) >> shift;
    VEC_Add(velocity, pos, pos);
    if (CollideSphereWithCourse(pos, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPrevPos, 0,
                                item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCourseRadius, 4,
                                item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionSlotIndex,
                                &vector, NULL, NULL, NULL, NULL, NULL, NULL, NULL) == 0) {
        return;
    }
    if ((kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) == 0) {
        pos->y += vector.y;
        return;
    }
    VEC_Add(pos, &vector, pos);
}

void SteerItemKouraWAtAngleZero(ItemKouraW *item, u32 gain, u32 maxStep, u32 radius) {
    SteerItemKouraWToAnglePoint(item, maxStep, 0, radius, gain, 7, 3);
}

void SteerItemKouraWToNextAnglePoint(ItemKouraW *item, s32 gain, s32 maxStep, s32 radius, u16 angleStep) {
    item->mAngle += angleStep;
    SteerItemKouraWToAnglePoint(item, maxStep, (u16) item->mAngle, radius, gain, 1, 1);
}

void SteerItemKouraWToKartForward(ItemKouraW *item, s32 gain, s32 lift) {
    Vec3 vector;
    s32 onBoostSurface;
    Vec3 *pos;
    Vec3 *velocity;
    Kart *kart;

    kart = item->mKartItems->mKart;
    onBoostSurface = (kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE) ? 1 : 0;
    item->mKartForward = kart->mSignedTurnedForward;
    pos = &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos;
    velocity = &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity;
    if (kart->mMotionFlags & KART_MOTION_REVERSING) {
        item->mKartForward.x = -item->mKartForward.x;
        item->mKartForward.y = -item->mKartForward.y;
        item->mKartForward.z = -item->mKartForward.z;
    }
    if (IsKartRemovedOrRespawning(kart) == FALSE) {
        item->mKartDrawPos = kart->mDrawMatrixPos;
    }
    VEC_MultAdd(0x14ffa, &item->mKartForward, &item->mKartDrawPos, &vector);
    if (onBoostSurface == 0) {
        vector.y += lift;
    } else {
        VEC_MultAdd(lift, &kart->mGroundNormal, &vector, &vector);
    }
    VEC_Subtract(&vector, pos, &vector);
    velocity->x = MUL_FIXED12_NO_ROUND(vector.x, gain);
    velocity->y = MUL_FIXED12_NO_ROUND(vector.y, gain);
    velocity->z = MUL_FIXED12_NO_ROUND(vector.z, gain);
    VEC_Add(velocity, pos, pos);
    if (onBoostSurface == 0) {
        return;
    }
    if (CollideSphereWithCourse(pos, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPrevPos, 0,
                                item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCourseRadius, 4,
                                item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionSlotIndex,
                                &vector, NULL, NULL, NULL, NULL, NULL, NULL, NULL) == 0) {
        return;
    }
    VEC_Add(pos, &vector, pos);
}

BOOL TrySetItemKouraWKartItems(ItemKouraW *item, s32 kartIndex) {
    Kart *kart;
    KartItems *kartItems;
    Vec3 kartOffset;
    Vec3 *kartPos;
    s32 shortRange;
    s32 normalDistance;
    s32 offsetX;
    s32 offsetZ;

    kart = GetKart(kartIndex);
    if (IsKartRemovedOrRespawning(kart) != FALSE) {
        return FALSE;
    }
    kartItems = &(gKartItems)[kartIndex];
    kartPos = &kart->mDrawMatrixPos;
    if (kartItems->mItemLink.mLink != item->mLinkFollowingItemObject.mTargetLink.mLink) {
        shortRange = ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x40000000) ||
                      (kart->mDriveFlags & KART_DRIVE_ON_BOOST_SURFACE))
                         ? 1
                         : 0;
        VEC_Subtract(kartPos, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos, &kartOffset);
        offsetX = FROM_FIXED12(kartOffset.x);
        offsetZ = FROM_FIXED12(kartOffset.z);
        if (offsetX * offsetX + offsetZ * offsetZ > (shortRange ? 0x9c40 : 0x27100)) {
            return FALSE;
        }
        normalDistance =
            Vec3DotUnrounded(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mNormal, &kartOffset) >>
            12;
        if (normalDistance * normalDistance > 0x9c4) {
            return FALSE;
        }
    }
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x10000000) {
        return FALSE;
    }
    item->mKartItems = kartItems;
    item->mKartDrawPos = *kartPos;
    return TRUE;
}

void SetItemKouraWKartItems(ItemKouraW *itemKouraW, int kartIndex) {
    itemKouraW->mKartItems = &gKartItems[kartIndex];
}
