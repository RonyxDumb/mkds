#include "Main/Item/item_koura_r_kart_items.h"
#include "Main/Unknown/code_020f1a14.h"
#include "Main/Item/item_kinoko.h"
#include "Main/Unknown/code_020f1258.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Race/race.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Item/item_object_throw.h"
#include "code_02147cd8.h"
#include "Main/Item/item_pool.h"
#include "Main/Race/race_clock.h"
#include "Main/Kart/karts.h"
#include "Main/Unknown/code_020f11f0.h"
#include "Main/Unknown/code_020f1180.h"

void ResetItemKouraRKartItems(ItemKouraR *item) {
    item->mKartItems = NULL;
    item->mNearKartFrames = 0;
}

// Returns TRUE when the kart is off the shell plane but near it horizontally.
BOOL SteerItemKouraRToKart(ItemKouraR *item, s32 speed, s32 gain, s32 flag) {
    Vec3 offset;
    Vec3 firstNormal;
    Vec3 secondNormal;
    s32 value;
    BOOL sameNormal;
    Vec3 *pos;
    Vec3 *velocity;
    Kart *kart;
    BOOL result;

    result = FALSE;
    pos = &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos;
    velocity = &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity;
    if ((item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCreationNumber & 1) ==
        GetRaceUpdateFramesMod2()) {
        kart = item->mKartItems->mKart;
        if (!(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x20000)) {
            if (IsKartNotNormal(kart) != FALSE) {
                speed >>= 1;
            }
            VEC_Subtract(&kart->mDrawMatrixPos, pos, &offset);
            offset.y =
                Vec3DotUnrounded(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mNormal, &offset) >>
                12;
            if (offset.y * offset.y > 0xbd1) {
                if (HORIZONTAL_LENGTH_SQUARED(offset) < (s64) 0xe1000000u) {
                    result = TRUE;
                }
            }
            value = 0;
            offset.y = 0;
            if (LENGTH_SQUARED(offset) >= 0x10) {
                value = Vec3NormalizeAndGetLengthUnchecked(&offset, &offset);
            }
            offset.x = MUL_FIXED12_NO_ROUND(offset.x, speed);
            offset.y = MUL_FIXED12_NO_ROUND(offset.y, speed);
            offset.z = MUL_FIXED12_NO_ROUND(offset.z, speed);
            if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000) {
                if (value < MUL_FIXED12_ROUNDED(kart->mPhysicalParam->mRadius, kart->mScale.z)) {
                    item->mNearKartFrames = item->mNearKartFrames + 1;
                    if (item->mNearKartFrames > 0x5a) {
                        FadeOutItemObjectNoCallback(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 1);
                        return FALSE;
                    }
                    offset.x = 0;
                    offset.y = 0;
                    offset.z = 0;
                }
            }
            VEC_Subtract(&offset, &item->mTowardKartVelocity, &offset);
            if (0x64000 - value > 0) {
                gain += MUL_FIXED12_NO_ROUND(0x64000 - value, 16);
            }
            offset.x = MUL_FIXED12_NO_ROUND(offset.x, gain);
            offset.y = MUL_FIXED12_NO_ROUND(offset.y, gain);
            offset.z = MUL_FIXED12_NO_ROUND(offset.z, gain);
            VEC_Add(&item->mTowardKartVelocity, &offset, &item->mTowardKartVelocity);
            VEC_Subtract(&item->mKartItems->mKart->mVelocity, velocity, &offset);
            offset.y = 0;
            offset.x = MUL_FIXED12_NO_ROUND(offset.x, gain);
            offset.y = MUL_FIXED12_NO_ROUND(offset.y, gain);
            offset.z = MUL_FIXED12_NO_ROUND(offset.z, gain);
            VEC_Add(velocity, &offset, velocity);
        }
    }
    item->mKartItems->mTargetedByKouraR = TRUE;
    VEC_Add(&item->mTowardKartVelocity, pos, pos);
    VEC_Add(velocity, pos, pos);
    if (CollideSphereWithCourse(pos, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPrevPos, 0,
                                item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCourseRadius, 4,
                                item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionSlotIndex,
                                &offset, &firstNormal, &secondNormal,
                                &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionBits, NULL,
                                NULL, NULL, NULL) != 0) {
        VEC_Add(&offset, pos, pos);
        if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionBits & 0x1e34ef) {
            value = VEC_DotProduct(&firstNormal, velocity);
            velocity->x = velocity->x - MUL_FIXED12_NO_ROUND(firstNormal.x, value);
            velocity->y = velocity->y - MUL_FIXED12_NO_ROUND(firstNormal.y, value);
            velocity->z = velocity->z - MUL_FIXED12_NO_ROUND(firstNormal.z, value);
            sameNormal = (firstNormal.x == item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mNormal.x &&
                          firstNormal.y == item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mNormal.y &&
                          firstNormal.z == item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mNormal.z);
            if (sameNormal == FALSE) {
                item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mNormal = firstNormal;
                item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags |= 0x100;
            }
        }
        if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionBits & 0x214300) {
            if (item->mLinkFollowingItemObject.mDirectedItemObject.mUnk_158 == 0 && flag != 0) {
                value = VEC_DotProduct(&secondNormal, velocity);
                offset.x = MUL_FIXED12_NO_ROUND(secondNormal.x, value);
                offset.y = MUL_FIXED12_NO_ROUND(secondNormal.y, value);
                offset.z = MUL_FIXED12_NO_ROUND(secondNormal.z, value);
                velocity->x = velocity->x - offset.x;
                velocity->y = velocity->y - offset.y;
                velocity->z = velocity->z - offset.z;
                VEC_Subtract(velocity, &offset, velocity);
                velocity->x = MUL_FIXED12_NO_ROUND(velocity->x, 0x23d);
                velocity->y = MUL_FIXED12_NO_ROUND(velocity->y, 0x23d);
                velocity->z = MUL_FIXED12_NO_ROUND(velocity->z, 0x23d);
                FadeOutUsedUpItemObject(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 1);
                return FALSE;
            }
        }
        if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionBits & 0x8000) {
            FadeOutItemObjectNoCallback(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 1);
            return FALSE;
        }
    }
    ApplyItemObjectGravityWithGroundPull(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
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
    ownerIndex =
        !(item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags & 0x8000)
            ? (u16) (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags & ~0xff00)
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
    if ((kart->mEntryFlags & KART_ENTRY_REMOVED_PARKED_OR_TERESA) || (kart->mEffectFlags & KART_EFFECT_RESPAWN_DROP) ||
        (kartRank != 1 && kart->mState != KART_STATE_NORMAL)) {
        return 0;
    }
    GetKartPos(&offset, kartIndex);
    VEC_Subtract(&offset, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos, &offset);
    distanceSquared = FROM_FIXED12(offset.x) * FROM_FIXED12(offset.x);
    distanceSquared += FROM_FIXED12(offset.z) * FROM_FIXED12(offset.z);
    if (distanceSquared > 0x27100 || (maxDistanceSquared != 0 && distanceSquared > maxDistanceSquared)) {
        return 0;
    }
    dot = Vec3DotUnrounded(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity, &offset);
    if (dot < 0) {
        return 0;
    }
    offsetSquared = FROM_FIXED12(Vec3DotUnrounded(&offset, &offset));
    velocitySquared = Vec3DotUnrounded(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity,
                                       &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity);
    lengthProduct = (s64) velocitySquared * offsetSquared;
    dotSquared = (s64) dot * FROM_FIXED12(dot);
    if ((s32) FROM_FIXED12(dotSquared) < MUL_FIXED12_NO_ROUND((s32) FROM_FIXED12(lengthProduct), 0x400)) {
        return 0;
    }
    dot = Vec3DotUnrounded(&item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mNormal, &offset);
    if (FROM_FIXED12(dot) * FROM_FIXED12(dot) > 0x9c4) {
        return 0;
    }
    if (item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x10000000) {
        return 0;
    }
    item->mKartItems = &gKartItems[kartIndex];
    item->mTowardKartVelocity.x = 0;
    item->mTowardKartVelocity.y = 0;
    item->mTowardKartVelocity.z = 0;
    item->mNearKartFrames = 0;
    return distanceSquared;
}

u32 TrySetItemKouraRKartItemsByFrame(ItemKouraR *item, u32 checkRank) {
    u16 kartIndex;
    int distanceSquared;
    kartIndex = GetRaceUpdateFramesMod8();
    if (((u32) kartIndex < gRaceSetup->mKartCount) &&
        (distanceSquared = TrySetItemKouraRKartItems(item, kartIndex, 0, checkRank), distanceSquared != 0)) {
        return 1;
    }
    return 0;
}

BOOL TrySetItemKouraRNearestKartItems(ItemKouraR *item, u32 checkRank) {
    u16 kartIndex;
    u32 nearestDistanceSquared;
    u32 kartCount;
    int distanceSquared;

    nearestDistanceSquared = 0;
    kartCount = gRaceSetup->mKartCount;
    for (kartIndex = 0; kartIndex < kartCount; kartIndex++) {
        distanceSquared = TrySetItemKouraRKartItems(item, kartIndex, nearestDistanceSquared, checkRank);
        if (distanceSquared != 0) {
            nearestDistanceSquared = distanceSquared;
        }
    }
    return nearestDistanceSquared != 0;
}

void SetItemKouraRKartItemsAndClearTowardKartVelocity(ItemKouraR *item, int kartIndex) {
    item->mKartItems = &gKartItems[kartIndex];
    item->mTowardKartVelocity.x = 0;
    item->mTowardKartVelocity.y = 0;
    item->mTowardKartVelocity.z = 0;
    item->mNearKartFrames = 0;
}

void SetItemKouraRKartItems(ItemKouraR *item, int kartIndex) {
    item->mKartItems = &gKartItems[kartIndex];
    item->mNearKartFrames = 0;
}

void AddItemKouraRTowardKartToVelocity(ItemKouraR *item) {
    VEC_Add(&item->mTowardKartVelocity, &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity,
            &item->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity);
    SetItemObjectDirectionFromVelocity(item);
}
