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
    if (kart->mUnk_44 & KART_44_REVERSING) {
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
    if ((kart->mUnk_48 & KART_48_ON_BOOST_SURFACE) == 0) {
        pos->y += vector.y;
        return;
    }
    VEC_Add(pos, &vector, pos);
}
