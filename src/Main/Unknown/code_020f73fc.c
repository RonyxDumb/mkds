#include "Main/Unknown/code_020f73fc.h"

#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f6be8.h"
#include "Main/Unknown/code_020f73a4.h"
#include "Main/Unknown/code_020f7c60.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_020f8e78.h"
#include "Main/Unknown/code_020f9c40.h"
#include "code_02147cd8.h"

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
