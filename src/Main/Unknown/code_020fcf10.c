#include "Main/Unknown/code_020fcf10.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"

void SteerItemKouraWToAnglePoint(ItemKouraW *item, s32 maxStep, s32 angle, s32 radius, s32 gain, s32 oldWeight,
                                 s32 shift) {
    Vec3 t;
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
    if (kart->mUnk_44 & KART_44_REVERSING) {
        item->mKartForward.x = -item->mKartForward.x;
        item->mKartForward.y = -item->mKartForward.y;
        item->mKartForward.z = -item->mKartForward.z;
    }
    Vec3CrossUnrounded(&item->mKartForward, &kart->mGroundNormal, &t);
    scaledRadius = MUL_FIXED12_NO_ROUND(radius, gPairsByAngle[(angle >> 4) * 2 + 1]);
    item->mAnglePointOffset.x = MUL_FIXED12_NO_ROUND(t.x, scaledRadius);
    item->mAnglePointOffset.y = MUL_FIXED12_NO_ROUND(t.y, scaledRadius);
    item->mAnglePointOffset.z = MUL_FIXED12_NO_ROUND(t.z, scaledRadius);
    scaledRadius = MUL_FIXED12_NO_ROUND(radius, gPairsByAngle[(angle >> 4) * 2]);
    VEC_MultAdd(scaledRadius, &item->mKartForward, &item->mAnglePointOffset, &item->mAnglePointOffset);
    VEC_MultAdd(0x1e000, &item->mKartForward, &item->mAnglePointOffset, &t);
    if (IsKartRemovedOrRespawning(kart) == FALSE) {
        item->mKartDrawPos = kart->mDrawMatrixPos;
    }
    VEC_Add(&t, &item->mKartDrawPos, &t);
    VEC_Subtract(&t, pos, toTarget);
    t.x = MUL_FIXED12_NO_ROUND(toTarget->x, gain);
    t.y = MUL_FIXED12_NO_ROUND(toTarget->y, gain);
    t.z = MUL_FIXED12_NO_ROUND(toTarget->z, gain);
    if (LENGTH_SQUARED(t) >= (s64) maxStep * maxStep) {
        if (LENGTH_SQUARED(t) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&t, &t);
        }
        t.x = MUL_FIXED12_NO_ROUND(t.x, maxStep);
        t.y = MUL_FIXED12_NO_ROUND(t.y, maxStep);
        t.z = MUL_FIXED12_NO_ROUND(t.z, maxStep);
    }
    velocity->x = (velocity->x * (s32) oldWeight + t.x) >> shift;
    velocity->y = (velocity->y * (s32) oldWeight + t.y) >> shift;
    velocity->z = (velocity->z * oldWeight + t.z) >> shift;
    VEC_Add(velocity, pos, pos);
    if (CollideSphereWithCourse(
            pos, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPrevPos, 0, item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCourseRadius, 4,
            item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionSlotIndex, &t, NULL, NULL, NULL, NULL, NULL, NULL, NULL) == 0) {
        return;
    }
    if ((kart->mUnk_48 & KART_48_ON_BOOST_SURFACE) == 0) {
        pos->y += t.y;
        return;
    }
    VEC_Add(pos, &t, pos);
}
