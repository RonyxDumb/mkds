#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f7c60.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f73a4.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020f6be4.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f2dac.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_0210a598.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_020ff000.h"
#include "Main/Unknown/code_0210a000.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020f1104.h"
#include "Main/Unknown/code_020f1258.h"
#include "Main/Unknown/code_020f1a14.h"
#include "Main/Unknown/code_020f2d98.h"
#include "Main/Unknown/code_0210b850.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_020ec8bc.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020f5978.h"
#include "Main/Unknown/code_020f11f0.h"
#include "Main/Unknown/code_020f1180.h"
#include "Main/Unknown/code_020f5b74.h"
#include "Main/Unknown/code_020f5b84.h"
#include "Main/Unknown/code_020f5cc4.h"
#include "Main/Unknown/code_020f5d00.h"
#include "Main/Unknown/code_020f5d5c.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d5000.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/code_020f1000.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_020f92e8.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"

void StartItemObjectSoundOnSource(ItemObject *item, s32 soundId) {
    SoundSource *sourceCopy = &item->mSoundSource;
    s32 soundIdCopy = soundId;
    u32 volume;
    u32 zero;
    s32 soundIdCompared;
    u32 skipId;
    soundIdCompared = soundIdCopy;
    skipId = 1u;
    if (soundIdCompared == skipId) {
    }
    if (soundIdCompared == skipId) {
    }
    if (soundIdCompared == skipId) {
        return;
    }
    volume = 0x7fu;
    zero = 0u;
    StartSound(sourceCopy, soundIdCopy, volume, zero);
}

void ApplyItemObjectHitType(ItemObject *itemParam, s32 hitType, Vec3 *otherPos, Vec3 *otherVelocity,
                            MapObject *mapObject) {
    ItemObject *item = itemParam;
    Vec3 offset;
    Vec3 direction;
    Vec3 push;
    s32 soundId;
    s32 value;
    s32 radius;
    void (*soundCallback)(ItemObject *, s32);

    if (item->mFlags & 0x80000) {
        return;
    }
    soundId = mapObject ? mapObject->mKindData->mCollideItemObjectSoundId : -1;
    switch (hitType) {
        case 1:
            if (item->mFlags & 0x1000) {
                break;
            }
            VEC_Subtract(&item->mPrevPos, otherPos, &offset);
            if (!(item->mFlags & 0x8000) && (item->mFlags & 0x1000000)) {
                DeflectItemObjectRandomly(item, otherPos, &offset);
                break;
            }
            item->mFlags |= 0x4000000;
            if (Vec3DotUnrounded(&item->mVelocity, &offset) <= 0) {
                if (LENGTH_SQUARED(offset) >= 0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&offset, &offset);
                }
                item->mBounce(item, otherVelocity, &offset);
                if (item->mFlags & 0x8000) {
                    break;
                }
                radius = item->mRadius;
                if ((s64) (otherPos->x - item->mPos.x) * (otherPos->x - item->mPos.x) +
                        (s64) (otherPos->y - item->mPos.y) * (otherPos->y - item->mPos.y) +
                        (s64) (otherPos->z - item->mPos.z) * (otherPos->z - item->mPos.z) >=
                    (s64) radius * radius) {
                    break;
                }
                item->mPos.x = otherPos->x + MUL_FIXED12_NO_ROUND(radius, offset.x);
                item->mPos.z = otherPos->z + MUL_FIXED12_NO_ROUND(radius, offset.z);
                break;
            }
            if (item->mFlags & 0x8000) {
                break;
            }
            radius = item->mRadius;
            if ((s64) (otherPos->x - item->mPos.x) * (otherPos->x - item->mPos.x) +
                    (s64) (otherPos->y - item->mPos.y) * (otherPos->y - item->mPos.y) +
                    (s64) (otherPos->z - item->mPos.z) * (otherPos->z - item->mPos.z) >=
                (s64) radius * radius) {
                break;
            }
            if (LENGTH_SQUARED(offset) >= 0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&offset, &offset);
            }
            radius = item->mRadius;
            item->mPos.x = otherPos->x + MUL_FIXED12_NO_ROUND(radius, offset.x);
            item->mPos.z = otherPos->z + MUL_FIXED12_NO_ROUND(radius, offset.z);
            break;
        case 2:
            if (item->mFlags & 0x1000) {
                RemoveItemInUseObject(&GetKartItems(item->mOwnerKartIndexAndFlags & ~0xff00)->mItemInUse, item);
            }
            value = 0;
            if ((s64) otherVelocity->x * otherVelocity->x + (s64) otherVelocity->y * otherVelocity->y +
                    (s64) otherVelocity->z * otherVelocity->z >=
                0x10) {
                value = Vec3NormalizeAndGetLengthUnchecked(otherVelocity, &direction);
            }
            if (value != 0) {
                ApplyItemObjectPush(item, otherPos, otherVelocity, &direction);
            } else {
                VEC_Subtract(&item->mPos, otherPos, &direction);
                if (direction.y < 0) {
                    direction.y = 0;
                }
                if ((s64) direction.x * direction.x + (s64) direction.y * direction.y +
                        (s64) direction.z * direction.z >=
                    0x10) {
                    Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
                }
                push.x = MUL_FIXED12_NO_ROUND(direction.x, 0x1800);
                push.y = MUL_FIXED12_NO_ROUND(direction.y, 0x1800);
                push.z = MUL_FIXED12_NO_ROUND(direction.z, 0x1800);
                ApplyItemObjectPush(item, otherPos, &push, &direction);
            }
            if (soundId == -1 || (item->mFlags & 0x8000000)) {
                FadeOutUsedUpItemObject(item, 1);
            } else {
                value = item->mKind;
                FadeOutEndedItemObject(item, 1);
                if (value == 5 || value == 9) {
                    soundId = -1;
                }
            }
    }
    if (soundId == -1) {
        return;
    }
    soundCallback = (item->mFlags & 0x400000) ? StartItemObjectSoundOnSource : StartItemObjectSoundIfNear;
    soundCallback(item, soundId);
}

void StartItemObjectReleaseTimerSynced(ItemObject *item, s32 sendEvent) {
    BOOL started;
    enum { K0 } kind;

    if (!(item->mFlags & 0x8000000)) {
        if ((item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) && !(item->mFlags & 0x20000000)) {
            if (item->mOwnerKartIndexAndFlags & 0xf00) {
                return;
            }
            item->mOwnerKartIndexAndFlags |= gItemObjectReleaseTimerPendingBit;
            item->mAdvance = NULL;
            return;
        }
        if (item->mFlags & 0x180000) {
            return;
        }
        kind = item->mKind;
        if (gItemKinds[kind].mKeepsAdvanceAtEnd == 0 && !(item->mFlags & 0x180000)) {
            item->mAdvance = AdvanceItemObjectReleaseTimer;
        }
        item->mFlags |= 0x100002;
        return;
    }
    if ((item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) && !(item->mFlags & 0x20000000)) {
        if (item->mOwnerKartIndexAndFlags & 0xf00) {
            started = FALSE;
        } else {
            item->mOwnerKartIndexAndFlags |= gItemObjectReleaseTimerPendingBit;
            item->mAdvance = NULL;
            started = TRUE;
        }
    } else {
        if (item->mFlags & 0x180000) {
            started = FALSE;
        } else {
            kind = item->mKind;
            if (gItemKinds[kind].mKeepsAdvanceAtEnd == 0 && !(item->mFlags & 0x180000)) {
                item->mAdvance = AdvanceItemObjectReleaseTimer;
            }
            item->mFlags |= 0x100002;
            started = TRUE;
        }
    }
    if (started == FALSE) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, 4, 8, item->mId);
}

void StartItemObjectReleaseTimer(ItemObject *item) {
    enum { K0 } kind;

    if (item->mFlags & 0x180000) {
        return;
    }
    kind = item->mKind;
    if (gItemKinds[kind].mKeepsAdvanceAtEnd == 0 && !(item->mFlags & 0x180000)) {
        item->mAdvance = AdvanceItemObjectReleaseTimer;
    }
    item->mFlags |= 0x100002;
}

void AdvanceItemObjectReleaseTimer(ItemObject *item) {
    if (item->mFlags & 0x8000) {
        AdvanceRestingItemObject(item);
    }
    item->mAlpha--;
    if (item->mAlpha <= 0) {
        ReleaseItemPoolObject(&gItemPools[item->mKind], item);
    } else {
        if (item->mAlpha < 0xa) {
            FreeItemObjectCollisionSlot(item);
        }
    }
}

void StartItemObjectReleaseSynced(ItemObject *item, s32 sendEvent) {
    BOOL started;

    if (!(item->mFlags & 0x8000000)) {
        if ((item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) && !(item->mFlags & 0x20000000)) {
            if (item->mOwnerKartIndexAndFlags & 0xf00) {
                return;
            }
            item->mOwnerKartIndexAndFlags |= gItemObjectReleasePendingBit;
            item->mAdvance = NULL;
            return;
        }
        if (item->mFlags & 0x180000) {
            return;
        }
        if (!(item->mFlags & 0x180000)) {
            item->mAdvance = ReleaseItemObjectToItsPool;
        }
        item->mFlags |= 0x100002;
        return;
    }
    if ((item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) && !(item->mFlags & 0x20000000)) {
        if (item->mOwnerKartIndexAndFlags & 0xf00) {
            started = FALSE;
        } else {
            item->mOwnerKartIndexAndFlags |= gItemObjectReleasePendingBit;
            item->mAdvance = NULL;
            started = TRUE;
        }
    } else {
        if (item->mFlags & 0x180000) {
            started = FALSE;
        } else {
            if (!(item->mFlags & 0x180000)) {
                item->mAdvance = ReleaseItemObjectToItsPool;
            }
            item->mFlags |= 0x100002;
            started = TRUE;
        }
    }
    if (started == FALSE) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, 5, 8, item->mId);
}

void StartItemObjectRelease(ItemObject *item) {
    if (item->mFlags & 0x180000) {
        return;
    }
    if (!(item->mFlags & 0x180000)) {
        item->mAdvance = ReleaseItemObjectToItsPool;
    }
    item->mFlags |= 0x100002;
}

void ReleaseItemObjectToItsPool(ItemObject *item) {
    ReleaseItemPoolObject(&gItemPools[item->mKind], item);
}

Vec3 *CreateItemPushVector(void) {
    void *heap = GetHeap(GetCurrentHeapCall());
    gItemPushVector = HeapAlloc(heap, 0xc);
    return gItemPushVector;
}

s32 StartItemObjectFadeOut(ItemObject *item, s32 variant, s32 skipPending) {
    Vec3 *velocity = &item->mVelocity;
    ItemKind *kindInfo;
    s32 value;
    enum { K0 } kind;

    if (item->mFlags & 0x80000) {
        return 2;
    }
    if (skipPending == 0 && (item->mFlags & 0x8000000) && !(item->mFlags & 0x10000000) &&
        !(item->mFlags & 0x20000000)) {
        if (item->mOwnerKartIndexAndFlags & 0xf00) {
            return 2;
        }
        if (variant == 0) {
            item->mOwnerKartIndexAndFlags |= gItemObjectFadeOutPendingBit;
        } else {
            item->mOwnerKartIndexAndFlags |= gItemObjectNoCallbackFadeOutPendingBit;
            FreeItemObjectCollisionSlot(item);
        }
        item->mAdvance = NULL;
        return 1;
    }
    if (variant == 0) {
        kind = item->mKind;
        kindInfo = &gItemKinds[kind];
        if (kindInfo->mFadeOutCallback != NULL) {
            value = kindInfo->mFadeOutCallback(item);
            if (value == 0) {
                return 2;
            }
            if (value == 1) {
                return 0;
            }
        }
    }
    if (variant != 0) {
        item->mCoursePointOrParams.y = 0x266;
    } else {
        item->mCoursePointOrParams.y = 0x333;
        if (!(item->mFlags & 0x8000)) {
            item->mCoursePointOrParams.y += MUL_FIXED12_NO_ROUND(VEC_Mag(velocity), 0x15c);
            if (item->mCoursePointOrParams.y > 0x5c3) {
                item->mCoursePointOrParams.y = 0x5c3;
            }
        }
    }
    kind = item->mKind;
    kindInfo = &gItemKinds[kind];
    if (kindInfo->mKeepsAdvanceAtEnd == 0) {
        item->mAdvance = AdvanceItemObjectFadeOut;
    }
    item->mBounce = (void (*)(ItemObject *, Vec3 *, Vec3 *)) ItemObjectBounceReturnArgument;
    if (item->mNormal.y != 0) {
        Vec3 *normal = &item->mNormal;

        value = Vec3DotUnrounded(velocity, normal);
        if (value < 0x3000) {
            VEC_MultAdd(0x3000 - value, normal, velocity, velocity);
        }
    }
    item->mFlags |= 0x80001;
    FreeItemObjectCollisionSlot(item);
    value = Vec3DotUnrounded(velocity, GetViewTransposeMatrixAxis0());
    if (value > 1) {
        item->mCoursePointOrParams.x = 1;
    } else {
        item->mCoursePointOrParams.x = 0;
    }
    return 0;
}

void FadeOutEndedItemObject(ItemObject *item, s32 sendEvent) {
    s32 result;

    if (!(item->mFlags & 0x8000000)) {
        StartItemObjectFadeOut(item, 0, 0);
        return;
    }
    result = StartItemObjectFadeOut(item, 0, 0);
    if (result != 0) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, 0, 8, item->mId);
}

void ReplayPendingFadeOut(ItemObject *item) {
    StartItemObjectFadeOut(item, 0, 1);
}

void FadeOutItemObjectNoCallback(ItemObject *item, s32 sendEvent) {
    s32 result;

    if (!(item->mFlags & 0x8000000)) {
        StartItemObjectFadeOut(item, 1, 0);
        return;
    }
    result = StartItemObjectFadeOut(item, 1, 0);
    if (result != 0) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, 1, 8, item->mId);
}

void ReplayPendingNoCallbackFadeOut(ItemObject *item) {
    StartItemObjectFadeOut(item, 1, 1);
}

void FadeOutUsedUpItemObject(ItemObject *item, s32 sendEvent) {
    s32 result;
    enum { K0 } kind;

    result = StartItemObjectFadeOut(item, 0, 0);
    if (result <= 1) {
        kind = item->mKind;
        StartItemObjectSoundIfNear(item, gItemKinds[kind].mUsedUpSoundId);
    }
    if (result != 0) {
        return;
    }
    if (!(item->mFlags & 0x8000000)) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    if (item->mKind == 5) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, 2, 8, item->mId);
}

void FadeOutItemObjectHitByKart(ItemObject *item, s32 sendEvent, s32 highPart) {
    s32 result;
    enum { K0 } kind;

    result = StartItemObjectFadeOut(item, 0, 0);
    if (result <= 1) {
        kind = item->mKind;
        StartItemObjectSoundIfNear(item, gItemKinds[kind].mKartHitSoundId);
    }
    if (result != 0) {
        return;
    }
    if (!(item->mFlags & 0x8000000)) {
        return;
    }
    if (sendEvent == 0) {
        return;
    }
    if (item->mKind == 5) {
        return;
    }
    AddItemDataItemIdAndParts(item->mKind, 3, highPart, item->mId);
}

void AdvanceItemObjectFadeOut(ItemObject *item) {
    Vec3 direction;

    Vec3CrossUnrounded(&item->mNormal, GetViewTransposeMatrixAxis2(), &direction);
    VEC_MultAdd(item->mCoursePointOrParams.x != 0 ? item->mCoursePointOrParams.y : -item->mCoursePointOrParams.y,
                &direction, &item->mNormal, &item->mNormal);
    item->mFlags |= 0x80;
    item->mVelocity.y -= 0x400;
    VEC_Add(&item->mPos, &item->mVelocity, &item->mPos);
    item->mAlpha--;
    if (item->mAlpha > 0) {
        return;
    }
    ReleaseItemPoolObject(&gItemPools[item->mKind], item);
}

void ApplyItemObjectPush(ItemObject *item, Vec3 *otherPos, Vec3 *otherVelocity, Vec3 *normal) {
    Vec3 away;
    Vec3 relativeVelocity;
    Vec3 *push;
    s32 dot;
    s64 lengthSquared;

    VEC_Subtract(otherVelocity, &item->mVelocity, &relativeVelocity);
    VEC_Subtract(&item->mPos, otherPos, &away);
    dot = VEC_DotProduct(normal, &away);
    away.x -= MUL_FIXED12_NO_ROUND(normal->x, dot);
    away.y -= MUL_FIXED12_NO_ROUND(normal->y, dot);
    away.z -= MUL_FIXED12_NO_ROUND(normal->z, dot);
    lengthSquared = LENGTH_SQUARED(away);
    if (lengthSquared >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&away, &away);
    }
    if (item->mFlags & 0x8000) {
        VEC_MultAdd(0x666, &relativeVelocity, &item->mVelocity, &item->mVelocity);
        push = gItemPushVector;
        push->x = MUL_FIXED12_NO_ROUND(away.x, 0xccd);
        push->y = MUL_FIXED12_NO_ROUND(away.y, 0xccd);
        push->z = MUL_FIXED12_NO_ROUND(away.z, 0xccd);
        VEC_Add(&item->mVelocity, gItemPushVector, &item->mVelocity);
    } else {
        item->mVelocity.x = MUL_FIXED12_NO_ROUND(otherVelocity->x, 0x8cd);
        item->mVelocity.y = MUL_FIXED12_NO_ROUND(otherVelocity->y, 0x8cd);
        item->mVelocity.z = MUL_FIXED12_NO_ROUND(otherVelocity->z, 0x8cd);
        push = gItemPushVector;
        push->x = MUL_FIXED12_NO_ROUND(away.x, 0x1800);
        push->y = MUL_FIXED12_NO_ROUND(away.y, 0x1800);
        push->z = MUL_FIXED12_NO_ROUND(away.z, 0x1800);
        VEC_Add(&item->mVelocity, gItemPushVector, &item->mVelocity);
    }
}

u32 ItemObjectBounceReturnArgument(u32 value) {
    return value;
}

void StartRestingItemObject(ItemObject *item, void *collisionHitLink) {
    s32 fallSpeed;
    enum { K0 } kind;
    s32 bounceFactor;

    VEC_MultAdd(-item->mCourseRadius, &item->mNormal, &item->mPos, &item->mCoursePointOrParams);
    UpdateCollisionHitLink(collisionHitLink, item->mCollisionBits, item->mCollisionHitLink, &item->mCoursePointOrParams,
                           &item->mNormal);
    if (item->mCollisionHitLink->mObject != NULL && IsHitLinkOutsideGearRadiusOrFlagged(item->mCollisionHitLink) != 0) {
        item->mHitLinkTimer = ITEM_OBJECT_HIT_LINK_TIMER_FRAMES;
    } else {
        item->mHitLinkTimer = 0;
    }
    item->mFlags |= 0x8000;
    kind = *(vs32 *) &item->mKind;
    if (gItemKinds[kind].mKeepsAdvanceWhenResting == 0) {
        if (!(item->mFlags & 0x180000)) {
            item->mAdvance = AdvanceRestingItemObject;
        }
    }
    item->mBounce = BounceRestingItemObject;
    kind = item->mKind;
    bounceFactor = gItemKinds[kind].mBounceFactor;
    fallSpeed = item->mVelocity.y;
    if (fallSpeed <= 0) {
        fallSpeed = -fallSpeed;
    }
    item->mScaleTargetOrSpeed = -MUL_FIXED12_NO_ROUND(fallSpeed, bounceFactor);
    if (item->mScaleTargetOrSpeed < -0x5c3) {
        item->mScaleTargetOrSpeed = -0x5c3;
    }
    item->mVelocity.x = 0;
    item->mVelocity.y = 0;
    item->mVelocity.z = 0;
    StopItemObjectSoundSource(item);
    AddRestingItemPoolObject(&gItemPools[*(vs32 *) &item->mKind], item);
    kind = *(vs32 *) &item->mKind;
    StartItemObjectSoundIfNear(item, gItemKinds[kind].mRestSoundId);
}

void AdvanceRestingItemObject(ItemObject *item) {
    u32 collisionHitLink;

    if (item->mCollisionHitLink->mObject != NULL) {
        if (GetCollisionHitLinkPosAndVelocity(item->mCollisionHitLink, &item->mCoursePointOrParams, &item->mNormal) !=
            FALSE) {
            StartFallingItemObject(item);
        }
        if (item->mCollisionHitLink->mObject->mCollisionData.mUnk_130 != FALSE) {
            if (item->mNormal.y < 0xff4) {
                item->mFlags |= 0x80;
            }
        }
        VEC_MultAdd(item->mCourseRadius, &item->mNormal, &item->mCoursePointOrParams, &item->mPos);
        if (item->mHitLinkTimer > 0) {
            item->mHitLinkTimer -= 1;
            if ((item->mCreationNumber & 7) != GetRaceUpdateFramesMod8()) {
                return;
            }
            if (CollideSphereWithCourse(&item->mPos, NULL, 0, item->mCourseRadius, 0x44, item->mCollisionSlotIndex,
                                        NULL, NULL, NULL, &item->mCollisionBits, NULL, NULL, NULL,
                                        &collisionHitLink) == 0) {
                return;
            }
            if (IsCollisionHitLinkOutdated(&collisionHitLink, item->mCollisionBits, item->mCollisionHitLink) != FALSE) {
                item->mVelocity.x = 0;
                item->mVelocity.y = 0;
                item->mVelocity.z = 0;
                FadeOutUsedUpItemObject(item, 1);
            }
            if (!(item->mCollisionBits & 0x8000)) {
                return;
            }
            FadeOutItemObjectNoCallback(item, 1);
        } else {
            VEC_Subtract(&item->mPos, &item->mPrevPos, &item->mVelocity);
        }
    } else {
        if (!(item->mFlags & 0x40)) {
            return;
        }
        VEC_MultAdd(item->mCourseRadius, &item->mNormal, &item->mCoursePointOrParams, &item->mPos);
    }
}

void BounceRestingItemObject(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal) {
    s32 scaleDifference;
    s32 dot;
    u32 kind;

    scaleDifference = item->mScale.z - item->mScale.y;
    if (scaleDifference * scaleDifference >= 0x68be1) {
        return;
    }
    dot = Vec3DotUnrounded(otherVelocity, normal);
    if (dot <= 0) {
        dot = -dot;
    }
    kind = *(vs32 *) &item->mKind;
    item->mScaleTargetOrSpeed = MUL_FIXED12_NO_ROUND(dot, gItemKinds[kind].mBounceFactor);
    item->mScaleTargetOrSpeed = item->mScaleTargetOrSpeed >> 1;
}

void LaunchItemObjectFromPos(ItemObject *itemParam, s32 pushStrength, Vec3 *fromPos, Vec3 *fromVelocity, Vec3 *normal) {
    ItemObject *item;
    Vec3 away;
    Vec3 *velocity;
    s32 startsFalling;
    s32 dot;
    u32 kind;

    item = itemParam;
    velocity = &item->mVelocity;
    kind = *(vs32 *) &item->mKind;
    startsFalling = gItemKinds[kind].mStartsFalling;
    if (gRaceSetup->mMode == MODE_TIME_ATTACK || (item->mFlags & 0x8000000)) {
        startsFalling = 0;
    }
    item->mFlags |= 0x4000;
    item->mOwnerKartIndexAndFlags |= data_02159b64;
    dot = VEC_DotProduct(normal, velocity);
    velocity->x -= MUL_FIXED12_NO_ROUND(normal->x, dot);
    velocity->y -= MUL_FIXED12_NO_ROUND(normal->y, dot);
    velocity->z -= MUL_FIXED12_NO_ROUND(normal->z, dot);
    dot = Vec3DotUnrounded(fromVelocity, normal);
    if (dot < 0) {
        dot = 0;
    } else if (dot > 0x1333) {
        dot = 0x1333;
    }
    VEC_MultAdd(dot + (startsFalling != 0 ? 0x2800 : 0x3800), normal, velocity, velocity);
    if (pushStrength != 0) {
        VEC_Subtract(&item->mPos, fromPos, &away);
        if (LENGTH_SQUARED(away) >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&away, &away);
        }
        VEC_MultAdd(pushStrength * 0x14cd, &away, velocity, velocity);
    }
    if (startsFalling != 0) {
        if (!(item->mFlags & 0x180000)) {
            item->mAdvance = AdvanceFallingItemObject;
        }
        item->mBounce = FallingBounceItemObject;
        item->mFlags &= ~0x7000000;
    } else {
        item->mFlags &= ~0x4000;
        FadeOutItemObjectNoCallback(item, 1);
    }
}

void StartFallingItemObject(ItemObject *item) {
    u32 kind;

    item->mFlags &= ~0x8000;
    item->mFlags |= 0x4000;
    kind = *(vs32 *) &item->mKind;
    if (gItemKinds[kind].mKeepsAdvanceWhenResting == 0) {
        if (!(item->mFlags & 0x180000)) {
            item->mAdvance = AdvanceFallingItemObject;
        }
    }
    item->mBounce = FallingBounceItemObject;
    item->mFlags &= ~0x7000000;
}

void AdvanceFallingItemObject(ItemObject *item) {
    u32 collisionHitLink;
    Vec3 pushOut;
    Vec3 groundNormal;
    Vec3 bounceNormal;
    Vec3 *pos;
    Vec3 *velocity;

    pos = &item->mPos;
    velocity = &item->mVelocity;

    VEC_Add(velocity, pos, pos);
    item->mVelocity.x = MUL_FIXED12_NO_ROUND(item->mVelocity.x, 0xfec);
    velocity->z = MUL_FIXED12_NO_ROUND(velocity->z, 0xfec);
    if (CollideSphereWithCourse(pos, &item->mPrevPos, 0, item->mCourseRadius, 0x44, item->mCollisionSlotIndex, &pushOut,
                                &groundNormal, &bounceNormal, &item->mCollisionBits, NULL, NULL, NULL,
                                &collisionHitLink) != 0) {
        VEC_Add(&pushOut, pos, pos);
        if (item->mCollisionBits & 0x1e34ef) {
            LandItemObjectIfOnGround(item, pos, velocity, 0x385, &groundNormal);
        }
        if (item->mCollisionBits & 0x214300) {
            item->mFlags |= 0x20;
            BounceItemVelocityOffSurface(velocity, &bounceNormal);
            if (TryFadeOutDeflectedItemObject(item, &bounceNormal) != FALSE) {
                return;
            }
        }
        if (item->mCollisionBits & 0x8000) {
            FadeOutItemObjectNoCallback(item, 1);
            return;
        }
    }
    item->mFlags &= ~0x4000000;
    if (!(item->mCollisionBits & 0x1e34ef)) {
        velocity->y -= 0x385;
        if (velocity->y < -0xa000) {
            velocity->y = -0xa000;
        }
    }
    if (!(item->mFlags & 8)) {
        return;
    }
    if (item->mFlags & 3) {
        return;
    }
    StartRestingItemObject(item, &collisionHitLink);
}

void FallingBounceItemObject(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal) {
    BounceItemVelocityOffSurface(&item->mVelocity, normal);
    if (item->mFlags & 0x1000000) {
        return;
    }
    item->mFlags |= 0x1000000;
    item->mCoursePointOrParams.x = 0;
    item->mCoursePointOrParams.y = 0;
    item->mCoursePointOrParams.z = 0;
}

void StartItemThunder(ItemInUse *itemInUse, HeldItem *heldItem) {
    NNSSndSeqPlayer **seqPlayer;

    if (gRaceSoundKind & 1) {
        seqPlayer = TakeSoundHandleEntry(GetSoundHandlePool(0));
        if (gSoundModeHolder.mSeqStartEnabled != 0) {
            if (*seqPlayer != NULL) {
                NNS_SndPlayerStopSeq(seqPlayer, 0);
            }
            if (*seqPlayer != NULL) {
                NNS_SndPlayerStopSeq(seqPlayer, 0);
            }
            NNS_SndArcPlayerStartSeqArc(seqPlayer, 0, 0xde);
        }
    }
    StartKartThunder(heldItem->mKartItems->mKart);
    RunMapObjectListCallbacks();
    StartThunderBlockTimer(0);
    RemoveHeldItemObjects(heldItem, 1);
    if (gRaceSetup->mMode != MODE_WIFI) {
        return;
    }
    AddItemDataFrameOnly(6);
}

void StartItemStar(ItemInUse *itemInUse, HeldItem *heldItem) {
    StartKartStar(heldItem->mKartItems->mKart);
    RemoveHeldItemObjects(heldItem, 1);
    if (gRaceSetup->mMode != MODE_WIFI) {
        return;
    }
    AddItemDataFrameOnly(4);
}

void StartItemKouraGSound(void *kouraParam, s32 unused) {
    ItemKouraG *koura;

    koura = kouraParam;
    if (!(koura->mDirectedItemObject.mItemObject.mFlags & 0x400000)) {
        return;
    }
    AdvanceSoundDistanceSquaredChange(&koura->mSoundDistanceSquaredChange,
                                      koura->mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f);
    StartSoundWhileRequested(&koura->mDirectedItemObject.mItemObject.mSoundSource, 0xd7, 0x7f, 0);
}

BOOL InitItemKouraG(ItemInUse *itemInUse, ItemKouraG *koura) {
    BOOL isBattle;

    isBattle = gRaceSetup->mMode == MODE_BATTLE;
    StartItemObjectSoundSource(&koura->mDirectedItemObject.mItemObject);
    ResetSoundDistanceSquaredChange(&koura->mSoundDistanceSquaredChange);
    koura->mDirectedItemObject.mItemObject.mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) SetItemKouraSoundTrackParams;
    if (itemInUse->mKartItems->mFlags & KART_ITEMS_DOWN) {
        InitItemObjectThrow(koura, itemInUse, isBattle != FALSE ? 2 : 4, 0, 0, 0x5000);
        return FALSE;
    }
    InitItemObjectThrow(koura, itemInUse, isBattle != FALSE ? 5 : 9, 1, 0, 0x5000);
    return TRUE;
}

void AdvanceItemKouraG(ItemKouraG *koura) {
    if (koura->mDirectedItemObject.mItemObject.mAgeFrames > 0x258) {
        koura->mDirectedItemObject.mHitsRemaining = 0;
    }
    AdvanceItemObjectMotion(&koura->mDirectedItemObject, 0x84cd);
    if (koura->mDirectedItemObject.mItemObject.mFlags & 1) {
        return;
    }
    AddSoundRequest(&gKouraSoundRequestQueue,
                    (koura->mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f) + 0x9c40,
                    StartItemKouraGSound, koura, 0);
}

void *CopyItemKouraGData(void *buffer, ItemKouraG *koura, void *toBuffer) {
    void *result;

    if (koura != NULL && toBuffer != NULL) {
        StoreItemDataFlagBit(Vec3DotUnrounded(&koura->mDirectedItemObject.mItemObject.mVelocity,
                                              &koura->mDirectedItemObject.mDirection) < 0,
                             &koura->mDirectedItemObject.mItemObject.mVelocity.y);
    }
    result = CopyItemObjectData(buffer, koura, toBuffer);
    if (koura != NULL && toBuffer == NULL) {
        LoadItemDataFlagBit(koura->mDirectedItemObject.mItemObject.mVelocity.y, &koura->mReverse);
    }
    if (koura != NULL && toBuffer != NULL) {
        return AddItemDataSizedByKind(koura->mDirectedItemObject.mItemObject.mKind);
    }
    return result;
}

void InitItemKouraGFromData(ItemKouraG *koura) {
    SetupItemObjectFromData(&koura->mDirectedItemObject.mItemObject);
    ResetSoundDistanceSquaredChange(&koura->mSoundDistanceSquaredChange);
    koura->mDirectedItemObject.mItemObject.mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) SetItemKouraSoundTrackParams;
    InitItemObjectMotion(koura, 9, koura->mReverse, 0);
}

void StartItemKouraRSound(void *kouraParam, s32 unused) {
    ItemKouraR *kouraR;

    kouraR = kouraParam;
    if (!(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x400000)) {
        return;
    }
    AdvanceSoundDistanceSquaredChange(
        &kouraR->mSoundDistanceSquaredChange,
        kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags & ~0xc000001f);
    StartSoundWhileRequested(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource, 0xd8, 0x7f,
                             0);
}

void DeflectItemKouraROnHit(ItemKouraR *kouraR, Vec3 *otherVelocity, Vec3 *normal) {
    SetItemObjectDirectionFromVelocity(kouraR);
    DeflectItemObjectOnHit(&kouraR->mLinkFollowingItemObject.mDirectedItemObject, otherVelocity, normal);
    kouraR->mStateMachine.mNextState = 1;
    kouraR->mStateMachine.mNextStateRequested = 1;
}

// Called when an object is taken off the kart item list: sets up its state machine and first state.
s32 InitItemKouraR(ItemInUse *itemInUse, ItemKouraR *kouraR) {
    u16 ownerKartIndex;
    u16 targetKartIndex;
    u16 rankAhead;

    StartItemObjectSoundSource(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    ResetSoundDistanceSquaredChange(&kouraR->mSoundDistanceSquaredChange);
    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) SetItemKouraSoundTrackParams;
    InitStateMachine(&kouraR->mStateMachine, gItemKouraRStateTable, 7, kouraR);
    if (itemInUse->mKartItems->mFlags & KART_ITEMS_DOWN) {
        kouraR->mThrowForward = 0;
        InitItemObjectThrow(kouraR, itemInUse, 0, 0, 0, 0x5000);
        kouraR->mStateMachine.mNextState = 1;
        kouraR->mStateMachine.mNextStateRequested = 1;
        kouraR->mLinkFollowingItemObject.mPreviousLink.mLink = NULL;
        kouraR->mLinkFollowingItemObject.mPreviousLink.mNextLinksUsed = 1;
    } else {
        kouraR->mThrowForward = 1;
        if (gRaceSetup->mMode != MODE_BATTLE && itemInUse->mKartItems->mItemLink.mLink != NULL) {
            ownerKartIndex =
                !(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags & 0x8000)
                    ? (u16) (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags &
                             ~0xff00)
                    : 8;
            if (ownerKartIndex >= 8) {
                targetKartIndex = 8;
            } else {
                rankAhead = GetKartRank(ownerKartIndex) - 1;
                if (rankAhead < 1) {
                    rankAhead = gRaceSetup->mKartCount;
                }
                targetKartIndex = GetKartAtRank(rankAhead);
            }
            InitLinkFollowingItemFromInUse(&kouraR->mLinkFollowingItemObject, itemInUse, 0x2d, 0x5b, 1, 0, 1, 0x5000,
                                           targetKartIndex, 0);
            kouraR->mStateMachine.mNextState = 3;
            kouraR->mStateMachine.mNextStateRequested = 1;
        } else {
            InitItemObjectThrow(kouraR, itemInUse, 0, 1, 0, 0x5000);
            kouraR->mStateMachine.mNextState = 2;
            kouraR->mStateMachine.mNextStateRequested = 1;
            kouraR->mLinkFollowingItemObject.mPreviousLink.mLink = NULL;
            kouraR->mLinkFollowingItemObject.mPreviousLink.mNextLinksUsed = 1;
        }
        kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags |= 0x200000;
    }
    ResetItemKouraRKartItems(kouraR);
    if (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000) {
        kouraR->mStateMachine.mNextState = 0;
        kouraR->mStateMachine.mNextStateRequested = 1;
    }
    return kouraR->mThrowForward;
}

void AdvanceItemKouraR(ItemKouraR *kouraR) {
    AdvanceStateMachine(&kouraR->mStateMachine);
}

void UpdateItemKouraRState0And1(ItemKouraR *kouraR) {
    AdvanceItemObjectMotion(&kouraR->mLinkFollowingItemObject.mDirectedItemObject, 0x8800);
    if (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1) {
        return;
    }
    AddSoundRequest(&gKouraSoundRequestQueue,
                    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags &
                        ~0xc000001f,
                    StartItemKouraRSound, kouraR, 0);
}

void RequestItemKouraRState4ForKart(ItemKouraR *kouraR, u32 kartIndex) {
    u32 value = kartIndex;
    u32 minusOne;
    u32 collisionSlotIndex;
    u32 collisionSlotCompared;
    u32 minusOneCompared;
    collisionSlotIndex = kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionSlotIndex;
    minusOne = ~(0u);
    collisionSlotCompared = collisionSlotIndex;
    minusOneCompared = minusOne;
    if (collisionSlotCompared == minusOneCompared) {
    }
    if (collisionSlotCompared == minusOneCompared) {
        return;
    }
    SetItemKouraRKartItemsAndClearTowardKartVelocity(kouraR, value);
    value = 4u;
    kouraR->mStateMachine.mNextState = value;
    value = 1u;
    kouraR->mStateMachine.mNextStateRequested = value;
}

void UpdateItemKouraRState2(ItemKouraR *kouraR) {
    AdvanceItemObjectMotion(&kouraR->mLinkFollowingItemObject.mDirectedItemObject, 0x8800);
    if (!(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1)) {
        AddSoundRequest(&gKouraSoundRequestQueue,
                        kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags &
                            ~0xc000001f,
                        StartItemKouraRSound, kouraR, 0);
    }
    if (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1) {
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > 0x10) {
        if (TrySetItemKouraRKartItemsByFrame(kouraR, 0) == 0) {
            return;
        }
        kouraR->mStateMachine.mNextState = 4;
        kouraR->mStateMachine.mNextStateRequested = 1;
        if (!(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000)) {
            return;
        }
        AddItemDataItemIdAndKart(1, kouraR->mKartItems->mKartIndex,
                                 kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > 4) {
        if (TrySetItemKouraRNearestKartItems(kouraR, 0) == FALSE) {
            return;
        }
        kouraR->mStateMachine.mNextState = 4;
        kouraR->mStateMachine.mNextStateRequested = 1;
        if (!(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000)) {
            return;
        }
        AddItemDataItemIdAndKart(1, kouraR->mKartItems->mKartIndex,
                                 kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
    }
}

void EnterItemKouraRState3(ItemKouraR *kouraR) {
    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mBounce =
        (void (*)(ItemObject *, Vec3 *, Vec3 *)) DeflectItemKouraROnHit;
}

void UpdateItemKouraRState3(ItemKouraR *kouraR) {
    u16 ownerKartIndex;
    u16 targetKartIndex;
    u16 rankAhead;

    ownerKartIndex =
        !(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags & 0x8000)
            ? (u16) (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags & ~0xff00)
            : 8;
    if (ownerKartIndex >= 8) {
        targetKartIndex = 8;
    } else {
        rankAhead = GetKartRank(ownerKartIndex) - 1;
        if (rankAhead < 1) {
            rankAhead = gRaceSetup->mKartCount;
        }
        targetKartIndex = GetKartAtRank(rankAhead);
    }
    AdvanceLinkFollowingItem(&kouraR->mLinkFollowingItemObject, 0xd000, 0x29, targetKartIndex, 0);
    if (!(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1)) {
        AddSoundRequest(&gKouraSoundRequestQueue,
                        kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags &
                            ~0xc000001f,
                        StartItemKouraRSound, kouraR, 0);
    }
    if (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1) {
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > 0x708) {
        SetItemObjectDirectionFromVelocity(kouraR);
        kouraR->mStateMachine.mNextState = 1;
        kouraR->mStateMachine.mNextStateRequested = 1;
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > 0x10) {
        if (TrySetItemKouraRKartItemsByFrame(kouraR, 1) == 0) {
            return;
        }
        kouraR->mStateMachine.mNextState = 4;
        kouraR->mStateMachine.mNextStateRequested = 1;
        if (!(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000)) {
            return;
        }
        AddItemDataItemIdAndKart(1, kouraR->mKartItems->mKartIndex,
                                 kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
        return;
    }
    if (kouraR->mStateMachine.mStateFrames > 4) {
        if (TrySetItemKouraRNearestKartItems(kouraR, 1) == FALSE) {
            return;
        }
        kouraR->mStateMachine.mNextState = 4;
        kouraR->mStateMachine.mNextStateRequested = 1;
        if (!(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 0x8000000)) {
            return;
        }
        AddItemDataItemIdAndKart(1, kouraR->mKartItems->mKartIndex,
                                 kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mId);
    }
}

void EnterItemKouraRState4(ItemKouraR *kouraR) {
    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mBounce =
        (void (*)(ItemObject *, Vec3 *, Vec3 *)) DeflectItemKouraROnHit;
}

// Runs the two 0x7c/0x4c checks of the object in the 0x1fc word of the 0x1c pointer, then
// one of the four SteerItemKouraRToKart calls, and stores the 0x24c/0x24e halfwords it picks.
void UpdateItemKouraRState4(ItemKouraR *kouraR) {
    KartItems *kartItems;
    Kart *kart;
    BOOL kartFlagged;
    u32 kartBits;
    s32 value;

    kartItems = kouraR->mKartItems;
    kart = kartItems->mKart;
    kartBits = kart->mEntryFlags;
    kartFlagged = TRUE;
    if ((kartBits & KART_ENTRY_REMOVED_PARKED_OR_TERESA) == 0) {
        if ((kart->mEffectFlags & KART_EFFECT_RESPAWN_DROP) == 0) {
            kartFlagged = FALSE;
        }
    }
    if (kartFlagged != FALSE) {
        AddItemKouraRTowardKartToVelocity(kouraR);
        kouraR->mStateMachine.mNextState = 6;
        kouraR->mStateMachine.mNextStateRequested = 1;
    } else {
        value = kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags;
        if (value & 0x10000000) {
            if (kartBits & KART_ENTRY_SELECTED) {
                value = SteerItemKouraRToKart(kouraR, 0x5333, 0x19a, 1);
            } else {
                value = SteerItemKouraRToKart(kouraR, 0x4b33, 0x19a, 0);
            }
        } else {
            value = SteerItemKouraRToKart(kouraR, 0x4800, 0x19a, (value & 0x8000000) == 0);
        }
        if (value != 0) {
            AddItemKouraRTowardKartToVelocity(kouraR);
            kouraR->mStateMachine.mNextState = 2;
            kouraR->mStateMachine.mNextStateRequested = 1;
            kouraR->mLinkFollowingItemObject.mPreviousLink.mLink = NULL;
            kouraR->mLinkFollowingItemObject.mPreviousLink.mNextLinksUsed = 1;
        }
    }
    if (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1) {
        return;
    }
    AddSoundRequest(&gKouraSoundRequestQueue,
                    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags &
                        ~0xc000001f,
                    StartItemKouraRSound, kouraR, 0);
}

// Checks IsKartNotNormal of the Kart, then the 0x240 counter and the sum of the two
// squares of the 0x50/0x54/0x58 differences against the 0x1d0/0x1d4/0x1e0 square.
void UpdateItemKouraRState5(ItemKouraR *kouraR) {
    KartItems *kartItems;
    Kart *kart;
    s32 deltaZ;
    s32 hitRadius;
    s32 deltaX;

    kartItems = kouraR->mKartItems;
    kart = kartItems->mKart;
    if (IsKartNotNormal(kart) != FALSE) {
        FadeOutItemObjectHitByKart(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 0, 8);
    } else {
        SteerItemKouraRToKart(kouraR, 0x10000, 0x333, 0);
    }
    if ((kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1) == 0) {
        AddSoundRequest(&gKouraSoundRequestQueue,
                        kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags &
                            ~0xc000001f,
                        StartItemKouraRSound, kouraR, 0);
    }
    if (kouraR->mStateMachine.mStateFrames <= 0x14) {
        hitRadius =
            kart->mRadius + ((kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mRadius * 3) >> 1);
        deltaZ = kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.z - kart->mPointAlongUp.z;
        deltaX = kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.x - kart->mPointAlongUp.x;
        if ((s64) deltaX * deltaX + (s64) deltaZ * deltaZ >= (s64) hitRadius * hitRadius) {
            return;
        }
    }
    FadeOutItemObjectHitByKart(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject, 0, 8);
}

// Runs AdvanceItemObjectMotion and hands StartItemKouraRSound to AddSoundRequest when the 0x74 bit 0 is clear.
void UpdateItemKouraRState6(ItemKouraR *kouraR) {
    AdvanceItemObjectMotion(&kouraR->mLinkFollowingItemObject.mDirectedItemObject, 0xc000);
    if (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags & 1) {
        return;
    }
    AddSoundRequest(&gKouraSoundRequestQueue,
                    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mDistanceSquaredAndFlags &
                        ~0xc000001f,
                    StartItemKouraRSound, kouraR, 0);
}

// Runs StartKartSeqArcSoundOffset8 with the 0x3bc word of the 0x1fc object when the 0x78 high bits of the
// third parameter match that object's 0x74 halfword and the 0x74/0x78/0xdc tests pass.
void StartTargetKartSoundOnOwnItemHit(void *kouraParam, s32 hitType, ItemObject *otherParam) {
    ItemKouraR *kouraR;
    ItemObject *other;
    KartItems *kartItems;
    Kart *kart;
    u16 otherOwnerIndex;
    u32 otherFlags;

    kouraR = kouraParam;
    other = otherParam;
    if ((u32) (hitType - 1) > 1) {
        return;
    }
    kartItems = kouraR->mKartItems;
    otherOwnerIndex = !(other->mOwnerKartIndexAndFlags & 0x8000) ? (u16) (other->mOwnerKartIndexAndFlags & ~0xff00) : 8;
    if (kartItems == NULL) {
        return;
    }
    kart = kartItems->mKart;
    if (otherOwnerIndex != kart->mIndex) {
        return;
    }
    otherFlags = other->mFlags;
    if ((otherFlags & 0x1000) == 0) {
        if ((otherFlags & 0x2000) == 0) {
            return;
        }
        if ((other->mOwnerKartIndexAndFlags & 0x1000) == 0) {
            return;
        }
        if (other->mAgeFrames >= 0x78) {
            return;
        }
    }
    StartKartSeqArcSoundOffset8(kart, kart->mSoundIndex);
}

// Hands the 0x44 word and the 0x5c/0x130/0x250/0x254/0x60/0x54 addresses of b to
// CopyItemObjectData, CopyItemPointLinkIndex, StoreItemDataFlagBit, LoadItemDataFlagBit and AddItemDataSizedByKind.
void *CopyItemKouraRData(void *buffer, ItemKouraR *kouraR, void *toBuffer) {
    s32 dot;
    void *result;

    if (kouraR != NULL && toBuffer != NULL) {
        dot = Vec3DotUnrounded(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity,
                               &kouraR->mLinkFollowingItemObject.mDirectedItemObject.mDirection);
        StoreItemDataFlagBit(dot < 0, &kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y);
        StoreItemDataFlagBit(kouraR->mThrowForward,
                             &kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.y);
    }
    result = CopyItemObjectData(buffer, kouraR, toBuffer);
    result =
        CopyItemPointLinkIndex(result, kouraR != NULL ? &kouraR->mLinkFollowingItemObject.mPreviousLink : 0, toBuffer);
    if (kouraR != NULL && toBuffer == NULL) {
        LoadItemDataFlagBit(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mVelocity.y,
                            &kouraR->mReverse);
        LoadItemDataFlagBit(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.y,
                            &kouraR->mThrowForward);
    }
    if (kouraR != NULL && toBuffer != NULL) {
        return AddItemDataSizedByKind(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mKind);
    }
    return result;
}

// Stores SetItemKouraSoundTrackParams in the 0x30 word, moves the seven words of gItemKouraRStateTable to 0x23c,
// then picks one of three calls from the 0x254/0x21c words.
void InitItemKouraRFromData(ItemKouraR *kouraR) {
    u16 ownerKartIndex;
    u32 rank;
    u16 targetKartIndex;
    u16 rankAhead;

    SetupItemObjectFromData(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    ResetSoundDistanceSquaredChange(&kouraR->mSoundDistanceSquaredChange);
    kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mSoundSource.mTrackParamsFunction =
        (void (*)(void *, void *, void *)) SetItemKouraSoundTrackParams;
    InitStateMachine(&kouraR->mStateMachine, gItemKouraRStateTable, 7, kouraR);
    if (kouraR->mThrowForward != 0) {
        if (kouraR->mLinkFollowingItemObject.mPreviousLink.mLink != NULL) {
            kouraR->mStateMachine.mNextState = 3;
            kouraR->mStateMachine.mNextStateRequested = 1;
            ownerKartIndex =
                !(kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags & 0x8000)
                    ? (u16) (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mOwnerKartIndexAndFlags &
                             ~0xff00)
                    : 8;
            if (ownerKartIndex >= 8) {
                targetKartIndex = 8;
            } else {
                rank = GetKartRank(ownerKartIndex);
                rankAhead = rank - 1;
                if (rankAhead < 1) {
                    rankAhead = gRaceSetup->mKartCount;
                }
                targetKartIndex = gRaceProgress->mKartAtRank[(rankAhead & 0xff) - 1];
            }
            InitLinkFollowingItem(&kouraR->mLinkFollowingItemObject, 0x2d, 0x5b, 0, 1, kouraR->mReverse,
                                  targetKartIndex, 0);
        } else {
            kouraR->mStateMachine.mNextState = 2;
            kouraR->mStateMachine.mNextStateRequested = 1;
            InitItemObjectMotion(kouraR, 0, kouraR->mReverse, 0);
        }
        kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mFlags |= 0x200000;
    } else {
        kouraR->mStateMachine.mNextState = 1;
        kouraR->mStateMachine.mNextStateRequested = 1;
        InitItemObjectMotion(kouraR, 0, kouraR->mReverse, 0);
    }
    ResetItemKouraRKartItems(kouraR);
}

// Returns 1 while GetKart(b) is within the 0x1d0/0x1d4 radius of the 0x50/0x54/0x58
// words, or when the 0xda halfword is -1; otherwise sets the 0x24c/0x24e halfwords, returns 0.
// Returns FALSE when it requested state 5 because the shell is not yet at the kart.
BOOL RequestItemKouraRState5IfFar(void *kouraParam, s32 kartIndex) {
    ItemKouraR *kouraR;
    Kart *kart;
    s32 deltaZ;
    s32 hitRadius;
    s32 deltaX;

    kouraR = kouraParam;
    kart = GetKart(kartIndex);
    hitRadius = kart->mRadius + ((kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mRadius * 3) >> 1);
    deltaZ = kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.z - kart->mPointAlongUp.z;
    deltaX = kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mPos.x - kart->mPointAlongUp.x;
    if ((s64) deltaX * deltaX + (s64) deltaZ * deltaZ < (s64) hitRadius * hitRadius) {
        return TRUE;
    }
    if (kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject.mCollisionSlotIndex == -1) {
        return TRUE;
    }
    FreeItemObjectCollisionSlot(&kouraR->mLinkFollowingItemObject.mDirectedItemObject.mItemObject);
    kouraR->mStateMachine.mNextState = 5;
    kouraR->mStateMachine.mNextStateRequested = 1;
    SetItemKouraRKartItems(kouraR, kartIndex);
    return FALSE;
}

// Runs StartItemObjectSoundSource, ors data_02159834 into the 0x78 halfword, then makes one of two
// ThrowBouncingItem calls depending on the 0x1ec halfword of the 0x0c pointer, and returns the
// 0x130 word it stores.
s32 InitItemBanana(ItemInUse *itemInUse, ItemBanana *banana) {
    KartItems *kartItems;
    s32 unused;

    StartItemObjectSoundSource(&banana->mBouncingItemObject.mItemObject);
    banana->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags |= data_02159834;
    kartItems = itemInUse->mKartItems;
    if (kartItems->mFlags & KART_ITEMS_THROW_FORWARD) {
        ThrowBouncingItem(&banana->mBouncingItemObject, itemInUse, 0, 1, 0x4000, 0x3000, 0x59a);
        StartSound(&banana->mBouncingItemObject.mItemObject.mSoundSource, 0xda, 0x7f, 0);
        banana->mThrowForward = 1;
        return banana->mThrowForward;
    }
    ThrowBouncingItem(&banana->mBouncingItemObject, itemInUse, 0, 0, 0x4000, 0x3000, 0x59a);
    banana->mThrowForward = 0;
    return banana->mThrowForward;
}

// Calls AdvanceBouncingItem with one of two pairs of numbers, and when the 0x74 bits allow it
// doubles the 0x60 word and runs StopSound and StartRestingItemObject.
void AdvanceItemBanana(ItemBanana *banana) {
    u32 collisionHitLink;
    u32 flags;

    if (banana->mThrowForward != 0) {
        AdvanceBouncingItem(&banana->mBouncingItemObject, 0x1ec, 0xfec, 0, &collisionHitLink);
    } else {
        AdvanceBouncingItem(&banana->mBouncingItemObject, 0x2e1, 0xf85, 0, &collisionHitLink);
    }
    flags = banana->mBouncingItemObject.mItemObject.mFlags;
    if ((flags & 8) == 0) {
        return;
    }
    if (flags & 3) {
        return;
    }
    if (banana->mThrowForward != 0) {
        banana->mBouncingItemObject.mItemObject.mVelocity.y = banana->mBouncingItemObject.mItemObject.mVelocity.y * 2;
    }
    StopSound(&banana->mBouncingItemObject.mItemObject.mSoundSource, 0xda);
    StartRestingItemObject(&banana->mBouncingItemObject.mItemObject, &collisionHitLink);
}

// Hands the 0x130 word and the 0x60 word to StoreItemDataFlagBit/LoadItemDataFlagBit around the
// CopyItemObjectData call, and returns AddItemDataSizedByKind's value when b and c are both set.
void *CopyItemBananaData(void *buffer, ItemBanana *banana, void *toBuffer) {
    void *result;

    if (banana != NULL && toBuffer != NULL) {
        StoreItemDataFlagBit(banana->mThrowForward, &banana->mBouncingItemObject.mItemObject.mVelocity.y);
    }
    result = CopyItemObjectData(buffer, banana, toBuffer);
    if (banana != NULL && toBuffer == NULL) {
        LoadItemDataFlagBit(banana->mBouncingItemObject.mItemObject.mVelocity.y, &banana->mThrowForward);
    }
    if (banana != NULL && toBuffer != NULL) {
        return AddItemDataSizedByKind(banana->mBouncingItemObject.mItemObject.mKind);
    }
    return result;
}

// Runs SetupItemObjectFromData and StartItemObjectBouncing, then StartSound when the two 0x74/0x130 tests pass.
void InitItemBananaFromData(ItemBanana *banana) {
    SetupItemObjectFromData(&banana->mBouncingItemObject.mItemObject);
    StartItemObjectBouncing(&banana->mBouncingItemObject, 0);
    if ((banana->mBouncingItemObject.mItemObject.mFlags & 0x10000000) == 0) {
        return;
    }
    if (banana->mThrowForward == 0) {
        return;
    }
    StartSound(&banana->mBouncingItemObject.mItemObject.mSoundSource, 0xda, 0x7f, 0);
}

// Item hook of the mushroom: starts the kart boost, uses up one held object, marks the use,
// and makes the event call when the mode is 5.
void StartItemKinokoBoost(ItemInUse *itemInUse, HeldItem *heldItem) {
    StartKartKinokoBoost(heldItem->mKartItems->mKart);
    RemoveHeldItemObjects(heldItem, 1);
    itemInUse->mKartItems->mKinokoBoostStarted = TRUE;
    if (gRaceSetup->mMode != MODE_WIFI) {
        return;
    }
    AddItemDataFrameOnly(3);
}

void ResetItemKinoko(ItemKinoko *kinoko) {
    kinoko->mVisible = TRUE;
}

#pragma thumb off

// Runs DrawItemObjectModel with the last two parameters swapped when the 0x134 word is set.
void DrawItemKinoko(ItemKinoko *kinoko, void *viewAxis, void *model) {
    if (kinoko->mVisible == FALSE) {
        return;
    }
    DrawItemObjectModel(&kinoko->mBouncingItemObject.mItemObject, model, viewAxis);
}

// Decreases the 0x130 word by one; when it goes below zero StartItemObjectReleaseTimerSynced runs first.
void AdvanceRestingItemKinoko(ItemKinoko *kinoko) {
    kinoko->mTimer--;
    if (kinoko->mTimer < 0) {
        StartItemObjectReleaseTimerSynced(&kinoko->mBouncingItemObject.mItemObject, 0);
    }
    AdvanceRestingItemObject(&kinoko->mBouncingItemObject.mItemObject);
}

// Sets the object up through AdvanceBouncingItem when the 0x74 word allows it.
void AdvanceBouncingItemKinoko(ItemKinoko *kinoko) {
    u32 collisionHitLink;

    AdvanceBouncingItem(&kinoko->mBouncingItemObject, 0x385, 0xff8, 0x733, &collisionHitLink);
    if ((kinoko->mBouncingItemObject.mItemObject.mFlags & 8) == 0) {
        return;
    }
    if ((kinoko->mBouncingItemObject.mItemObject.mFlags & 3) != 0) {
        return;
    }
    StopSound(&kinoko->mBouncingItemObject.mItemObject.mSoundSource, 0xda);
    StartRestingItemObject(&kinoko->mBouncingItemObject.mItemObject, &collisionHitLink);
    if ((kinoko->mBouncingItemObject.mItemObject.mFlags & 0x180000) == 0) {
        kinoko->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceRestingItemKinoko;
    }
}

// Returns what StartItemObjectOrZero gives, with its 0x134 and 0x130 words cleared.
ItemKinoko *StartItemKinokoOrZero(void) {
    ItemKinoko *kinoko;

    kinoko = StartItemObjectOrZero(3, 8, &data_02159764, &data_02159764);
    if (kinoko == NULL) {
        return NULL;
    }
    if ((kinoko->mBouncingItemObject.mItemObject.mFlags & 0x180000) == 0) {
        kinoko->mBouncingItemObject.mItemObject.mAdvance = NULL;
    }
    FreeItemObjectCollisionSlot(&kinoko->mBouncingItemObject.mItemObject);
    kinoko->mVisible = FALSE;
    kinoko->mTimer = 0;
    return kinoko;
}

// Stores the two Vec3s in the object and sets the word at 0x80.
void ShowItemKinokoAt(ItemKinoko *kinoko, Vec3 *normal, Vec3 *pos) {
    kinoko->mVisible = TRUE;
    SetCourseColorBlendColor(&kinoko->mBouncingItemObject.mItemObject.mColorBlend, 1);
    if (normal != NULL) {
        kinoko->mBouncingItemObject.mItemObject.mNormal = *normal;
        kinoko->mBouncingItemObject.mItemObject.mFlags |= 0x80;
    }
    if (pos == NULL) {
        return;
    }
    kinoko->mBouncingItemObject.mItemObject.mPos = *pos;
    VEC_Subtract(&kinoko->mBouncingItemObject.mItemObject.mPos, &kinoko->mBouncingItemObject.mItemObject.mPrevPos,
                 &kinoko->mBouncingItemObject.mItemObject.mVelocity);
}

// Runs the object's first word and stores the 0x120 and 0x130 words.
void StartBouncingItemKinoko(void **kinokoSlot, Vec3 *velocity, s32 timer) {
    ItemKinoko *kinoko;

    kinoko = kinokoSlot[0];
    kinoko->mBouncingItemObject.mItemObject.mOwnerKartIndexAndFlags |= data_0215969c;
    CreateItemObjectCollisionSlot(&kinoko->mBouncingItemObject.mItemObject);
    StartItemObjectSoundSource(&kinoko->mBouncingItemObject.mItemObject);
    InitBouncingItem(&kinoko->mBouncingItemObject, 0, velocity);
    if ((kinoko->mBouncingItemObject.mItemObject.mFlags & 0x180000) == 0) {
        kinoko->mBouncingItemObject.mItemObject.mAdvance = (void (*)(ItemObject *)) AdvanceBouncingItemKinoko;
    }
    kinoko->mTimer = timer;
    kinokoSlot[0] = NULL;
}

#pragma thumb on

// Fills a table of eighteen 0x1c-byte objects allocated here.
void CreateItemInfos(void) {
    ItemInfo *infos;
    s32 infoIndex;

    infos = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x1f8);
    gItemInfos = infos;
    infos[0] = data_02159918;
    infos[1] = data_02159838;
    infos[2] = data_02159770;
    infos[3] = data_02159f68;
    infos[4] = data_021596a0;
    infos[5] = data_02159664;
    infos[6] = data_02159e54;
    infos[7] = data_02159cc0;
    infos[8] = data_02159aa0;
    infos[9] = data_02159f4c;
    infos[10] = data_02159680;
    infos[11] = data_021598fc;
    infos[12] = data_021599dc;
    infos[13] = data_02159d90;
    infos[14] = gItemInfoKiller;
    infos[15] = data_0215a2ec;
    infos[16] = data_0215a174;
    infos[17] = data_0215a4c0;
    switch (gRaceSetup->mMode) {
        case MODE_BATTLE:
            infos[17].mEnabled = TRUE;
            break;
        case MODE_WIFI:
            for (infoIndex = 0; infoIndex < 0x12; infoIndex++) {
                if (GetItemInfo(infoIndex)->mEnabled != FALSE && GetItemInfo(infoIndex)->mEnabledInWiFi == 0) {
                    gItemInfos[infoIndex].mEnabled = FALSE;
                }
            }
            break;
    }
    if (gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        gItemInfos[15].mEnabled = FALSE;
    }
}

#pragma thumb off

void InitHeldItem(HeldItem *heldItem, KartItems *kartItems) {
    s32 slotIndex;

    heldItem->mKartItems = kartItems;
    heldItem->mItemInfoIndex = 0x13;
    heldItem->mObjectCount = 0;
    heldItem->mObjectStartFramesLeft = 0;
    heldItem->mUsesTimer = 0;
    heldItem->mTimer = 0;
    heldItem->mUseTimerLimit = 0;
    for (slotIndex = 0; slotIndex < 3; slotIndex++) {
        heldItem->mObjects[slotIndex] = NULL;
    }
    heldItem->mIsPeerEntry = gRaceSetup->mCurrentEntries[kartItems->mKartIndex].mPlayer.mKind == PLAYER_KIND_PEER;
}

// Starts one held object at counts 7, 5 and 3 of the countdown that StartHeldItemObjects sets.
void StartNextHeldItemObject(HeldItem *heldItem) {
    ItemObject *item;
    Kart *kart;
    Vec3 *kartDrawPos;
    Vec3 *kartVelocity;
    void (*kindCallback)(void *);
    s32 slotIndex;
    enum { K0 } kind;

    if (heldItem->mObjectStartFramesLeft <= 0) {
        return;
    }
    heldItem->mObjectStartFramesLeft--;
    if (heldItem->mObjectStartFramesLeft != 7 && heldItem->mObjectStartFramesLeft != 5 &&
        heldItem->mObjectStartFramesLeft != 3) {
        return;
    }
    kart = heldItem->mKartItems->mKart;
    heldItem->mObjectCount--;
    item = heldItem->mObjects[heldItem->mObjectCount];
    kartDrawPos = &kart->mDrawMatrixPos;
    kartVelocity = &kart->mVelocity;
    StartItemObject(gItemPools + item->mKind, item);
    CopyKartPlacementToItemObject(heldItem->mKartItems, item);
    VEC_MultAdd(0xb33, kartVelocity, &item->mVelocity, &item->mVelocity);
    item->mPos = *kartDrawPos;
    LaunchItemObjectFromPos(item, 0, kartDrawPos, kartVelocity, &kart->mGroundNormal);
    kind = item->mKind;
    kindCallback = gItemKinds[kind].mAfterLaunchCallback;
    if (kindCallback != NULL) {
        kindCallback(item);
    }
    if (heldItem->mObjectCount != 0) {
        return;
    }
    heldItem->mItemInfoIndex = 0x13;
    heldItem->mObjectCount = 0;
    heldItem->mObjectStartFramesLeft = 0;
    heldItem->mUsesTimer = 0;
    heldItem->mTimer = 0;
    heldItem->mUseTimerLimit = 0;
    for (slotIndex = 0; slotIndex < 3; slotIndex++) {
        heldItem->mObjects[slotIndex] = NULL;
    }
}
