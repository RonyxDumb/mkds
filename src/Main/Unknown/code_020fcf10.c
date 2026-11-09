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
    s32 s;

    kart = item->mKartItems->mKart;
    item->mKartForward = kart->mSignedTurnedForward;
    pos = &item->mUnk_000.mUnk_000.mUnk_000.mPos;
    velocity = &item->mUnk_000.mUnk_000.mUnk_000.mVelocity;
    toTarget = &item->mToTarget;
    if (kart->mUnk_44 & 0x100) {
        item->mKartForward.x = -item->mKartForward.x;
        item->mKartForward.y = -item->mKartForward.y;
        item->mKartForward.z = -item->mKartForward.z;
    }
    Vec3CrossUnrounded(&item->mKartForward, &kart->mGroundNormal, &t);
    s = MUL_FIXED12_NO_ROUND(radius, gPairsByAngle[(angle >> 4) * 2 + 1]);
    item->mAnglePointOffset.x = MUL_FIXED12_NO_ROUND(t.x, s);
    item->mAnglePointOffset.y = MUL_FIXED12_NO_ROUND(t.y, s);
    item->mAnglePointOffset.z = MUL_FIXED12_NO_ROUND(t.z, s);
    s = MUL_FIXED12_NO_ROUND(radius, gPairsByAngle[(angle >> 4) * 2]);
    VEC_MultAdd(s, &item->mKartForward, &item->mAnglePointOffset, &item->mAnglePointOffset);
    VEC_MultAdd(0x1e000, &item->mKartForward, &item->mAnglePointOffset, &t);
    if (func_0206c0b0(kart) == FALSE) {
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
            pos, &item->mUnk_000.mUnk_000.mUnk_000.mPrevPos, 0, item->mUnk_000.mUnk_000.mUnk_000.mCourseRadius, 4,
            item->mUnk_000.mUnk_000.mUnk_000.mCollisionSlotIndex, &t, NULL, NULL, NULL, NULL, NULL, NULL, NULL) == 0) {
        return;
    }
    if ((kart->mUnk_48 & 1) == 0) {
        pos->y += t.y;
        return;
    }
    VEC_Add(pos, &t, pos);
}
