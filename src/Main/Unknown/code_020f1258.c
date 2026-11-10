#include "Main/Unknown/code_020f1258.h"

#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02061654.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_020f1d70.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

// Returns TRUE when the kart is off the shell plane but near it horizontally.
BOOL SteerItemKouraRToKart(ItemKouraR *item, s32 speed, s32 gain, s32 d) {
    Vec3 t;
    Vec3 firstNormal;
    Vec3 secondNormal;
    s32 n;
    BOOL sameNormal;
    Vec3 *pos;
    Vec3 *velocity;
    Kart *kart;
    BOOL result;

    result = FALSE;
    pos = &item->mUnk_000.mUnk_000.mUnk_000.mPos;
    velocity = &item->mUnk_000.mUnk_000.mUnk_000.mVelocity;
    if ((item->mUnk_000.mUnk_000.mUnk_000.mUnk_48 & 1) == GetRaceUpdateFramesMod2()) {
        kart = item->mKartItems->mKart;
        if (!(item->mUnk_000.mUnk_000.mUnk_000.mFlags & 0x20000)) {
            if (func_0206c0e0(kart) != FALSE) {
                speed >>= 1;
            }
            VEC_Subtract(&kart->mDrawMatrixPos, pos, &t);
            t.y = Vec3DotUnrounded(&item->mUnk_000.mUnk_000.mUnk_000.mNormal, &t) >> 12;
            if (t.y * t.y > 0xbd1) {
                if (HORIZONTAL_LENGTH_SQUARED(t) < (s64) 0xe1000000u) {
                    result = TRUE;
                }
            }
            n = 0;
            t.y = 0;
            if (LENGTH_SQUARED(t) >= 0x10) {
                n = Vec3NormalizeAndGetLengthUnchecked(&t, &t);
            }
            t.x = MUL_FIXED12_NO_ROUND(t.x, speed);
            t.y = MUL_FIXED12_NO_ROUND(t.y, speed);
            t.z = MUL_FIXED12_NO_ROUND(t.z, speed);
            if (item->mUnk_000.mUnk_000.mUnk_000.mFlags & 0x8000000) {
                if (n < MUL_FIXED12_ROUNDED(kart->mPhysicalParam->mRadius, kart->mScale.z)) {
                    item->mNearKartFrames = item->mNearKartFrames + 1;
                    if (item->mNearKartFrames > 0x5a) {
                        FadeOutItemObjectNoCallback(&item->mUnk_000.mUnk_000.mUnk_000, 1);
                        return FALSE;
                    }
                    t.x = 0;
                    t.y = 0;
                    t.z = 0;
                }
            }
            VEC_Subtract(&t, &item->mTowardKartVelocity, &t);
            if (0x64000 - n > 0) {
                gain += MUL_FIXED12_NO_ROUND(0x64000 - n, 16);
            }
            t.x = MUL_FIXED12_NO_ROUND(t.x, gain);
            t.y = MUL_FIXED12_NO_ROUND(t.y, gain);
            t.z = MUL_FIXED12_NO_ROUND(t.z, gain);
            VEC_Add(&item->mTowardKartVelocity, &t, &item->mTowardKartVelocity);
            VEC_Subtract(&item->mKartItems->mKart->mVelocity, velocity, &t);
            t.y = 0;
            t.x = MUL_FIXED12_NO_ROUND(t.x, gain);
            t.y = MUL_FIXED12_NO_ROUND(t.y, gain);
            t.z = MUL_FIXED12_NO_ROUND(t.z, gain);
            VEC_Add(velocity, &t, velocity);
        }
    }
    item->mKartItems->mTargetedByKouraR = TRUE;
    VEC_Add(&item->mTowardKartVelocity, pos, pos);
    VEC_Add(velocity, pos, pos);
    if (CollideSphereWithCourse(pos, &item->mUnk_000.mUnk_000.mUnk_000.mPrevPos, 0,
                                item->mUnk_000.mUnk_000.mUnk_000.mCourseRadius, 4,
                                item->mUnk_000.mUnk_000.mUnk_000.mCollisionSlotIndex, &t, &firstNormal, &secondNormal,
                                &item->mUnk_000.mUnk_000.mUnk_000.mCollisionBits, NULL, NULL, NULL, NULL) != 0) {
        VEC_Add(&t, pos, pos);
        if (item->mUnk_000.mUnk_000.mUnk_000.mCollisionBits & 0x1e34ef) {
            n = VEC_DotProduct(&firstNormal, velocity);
            velocity->x = velocity->x - MUL_FIXED12_NO_ROUND(firstNormal.x, n);
            velocity->y = velocity->y - MUL_FIXED12_NO_ROUND(firstNormal.y, n);
            velocity->z = velocity->z - MUL_FIXED12_NO_ROUND(firstNormal.z, n);
            sameNormal = (firstNormal.x == item->mUnk_000.mUnk_000.mUnk_000.mNormal.x &&
                          firstNormal.y == item->mUnk_000.mUnk_000.mUnk_000.mNormal.y &&
                          firstNormal.z == item->mUnk_000.mUnk_000.mUnk_000.mNormal.z);
            if (sameNormal == FALSE) {
                item->mUnk_000.mUnk_000.mUnk_000.mNormal = firstNormal;
                item->mUnk_000.mUnk_000.mUnk_000.mFlags |= 0x100;
            }
        }
        if (item->mUnk_000.mUnk_000.mUnk_000.mCollisionBits & 0x214300) {
            if (item->mUnk_000.mUnk_000.mUnk_158 == 0 && d != 0) {
                n = VEC_DotProduct(&secondNormal, velocity);
                t.x = MUL_FIXED12_NO_ROUND(secondNormal.x, n);
                t.y = MUL_FIXED12_NO_ROUND(secondNormal.y, n);
                t.z = MUL_FIXED12_NO_ROUND(secondNormal.z, n);
                velocity->x = velocity->x - t.x;
                velocity->y = velocity->y - t.y;
                velocity->z = velocity->z - t.z;
                VEC_Subtract(velocity, &t, velocity);
                velocity->x = MUL_FIXED12_NO_ROUND(velocity->x, 0x23d);
                velocity->y = MUL_FIXED12_NO_ROUND(velocity->y, 0x23d);
                velocity->z = MUL_FIXED12_NO_ROUND(velocity->z, 0x23d);
                FadeOutUsedUpItemObject(&item->mUnk_000.mUnk_000.mUnk_000, 1);
                return FALSE;
            }
        }
        if (item->mUnk_000.mUnk_000.mUnk_000.mCollisionBits & 0x8000) {
            FadeOutItemObjectNoCallback(&item->mUnk_000.mUnk_000.mUnk_000, 1);
            return FALSE;
        }
    }
    ApplyItemObjectGravityWithGroundPull(&item->mUnk_000.mUnk_000.mUnk_000);
    return result;
}

int TrySetItemKouraRKartItems(ItemKouraR *item, int kartIndex, s32 maxDistanceSquared, u32 checkRank) {
    u16 ownerIndex;
    Kart *kart;
    u32 kartRank;
    s32 ownerRank;
    Vec3 offset;
    s32 distanceSquared;
    s32 dot;
    s32 offsetSquared;
    s32 velocitySquared;
    s64 dotSquared;
    s64 lengthProduct;

    kart = GetKart(kartIndex);
    ownerIndex = !(item->mUnk_000.mUnk_000.mUnk_000.mOwnerKartIndexAndFlags & 0x8000)
                     ? (u16) (item->mUnk_000.mUnk_000.mUnk_000.mOwnerKartIndexAndFlags & ~0xff00)
                     : 8;
    kartRank = GetKartRank(kartIndex);
    if (ownerIndex < 8 && checkRank != 0) {
        ownerRank = GetKartRank(ownerIndex);
        if (ownerRank <= kartRank) {
            if (ownerRank != 1) {
                return 0;
            }
            if (kartRank > 3) {
                return 0;
            }
        }
    }
    if ((kart->mUnk_7c & 0x402020) || (kart->mUnk_4c & 0x800) || (kartRank != 1 && kart->mState != KART_STATE_NORMAL)) {
        return 0;
    }
    GetKartPos(&offset, kartIndex);
    VEC_Subtract(&offset, &item->mUnk_000.mUnk_000.mUnk_000.mPos, &offset);
    distanceSquared = (offset.x >> 12) * (offset.x >> 12);
    distanceSquared += (offset.z >> 12) * (offset.z >> 12);
    if (distanceSquared > 0x27100 || (maxDistanceSquared != 0 && distanceSquared > maxDistanceSquared)) {
        return 0;
    }
    dot = Vec3DotUnrounded(&item->mUnk_000.mUnk_000.mUnk_000.mVelocity, &offset);
    if (dot < 0) {
        return 0;
    }
    offsetSquared = Vec3DotUnrounded(&offset, &offset) >> 12;
    velocitySquared =
        Vec3DotUnrounded(&item->mUnk_000.mUnk_000.mUnk_000.mVelocity, &item->mUnk_000.mUnk_000.mUnk_000.mVelocity);
    lengthProduct = (s64) velocitySquared * offsetSquared;
    dotSquared = (s64) dot * (dot >> 12);
    if ((s32) (dotSquared >> 12) < MUL_FIXED12_NO_ROUND((s32) (lengthProduct >> 12), 0x400)) {
        return 0;
    }
    dot = Vec3DotUnrounded(&item->mUnk_000.mUnk_000.mUnk_000.mNormal, &offset);
    if ((dot >> 12) * (dot >> 12) > 0x9c4) {
        return 0;
    }
    if (item->mUnk_000.mUnk_000.mUnk_000.mFlags & 0x10000000) {
        return 0;
    }
    item->mKartItems = &gKartItems[kartIndex];
    item->mTowardKartVelocity.x = 0;
    item->mTowardKartVelocity.y = 0;
    item->mTowardKartVelocity.z = 0;
    item->mNearKartFrames = 0;
    return distanceSquared;
}
