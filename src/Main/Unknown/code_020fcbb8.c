#include "Main/Unknown/code_020fcbb8.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020fcf10.h"
#include "Main/Unknown/unk_027e0000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02077bc0.h"

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
