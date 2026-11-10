#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f73fc.h"
#include "Main/Unknown/code_020f81c0.h"
#include "Main/Unknown/code_020f813c.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_021001ac.h"
#include "Main/Unknown/unk_02159000.h"
#include "ITCM/code_01fff000.h"
#include "ITCM/code_01fff95c.h"
#include "Main/Unknown/code_02071000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/code_020f5000.h"
#include "Main/Unknown/code_020f6000.h"
#include "Main/Unknown/code_020f7000.h"
#include "Main/Unknown/code_020f8000.h"
#include "Main/Unknown/code_020f9000.h"
#include "Main/Unknown/code_020fa000.h"
#include "Main/Unknown/code_020fc000.h"
#include "Main/Unknown/code_020fe000.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020f5cc4.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020f8d9c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02077bc0.h"

// Hands out count objects from the pool, releasing the first active one while the pool is too full.
void TakeItemPoolObjects(ItemPool *pool, s32 count, ItemObject **out, u16 kartIndex, Vec3 *pos) {
    s32 i;

    if (pool->mTakenCount + count > pool->mObjectCount) {
        while (pool->mTakenCount + count > pool->mObjectCount) {
            if (pool->mActiveCount > 0) {
                ReleaseItemPoolObject(pool, pool->mObjects[0]);
            }
        }
    }
    i = 0;
    while (i < count) {
        out[i] = pool->mObjects[pool->mTakenCount++];
        ResetItemObjectAtPos(out[i], pool->mKind, kartIndex, pos);
        i++;
    }
}

void ReleaseItemPoolObject(ItemPool *pool, ItemObject *object) {
    s32 i;
    ItemObject **objects;
    s32 endIndex;

    i = 0;
    objects = pool->mObjects;
    while (i < pool->mTakenCount) {
        if (objects[i] == object) {
            goto found;
        }
        i++;
    }
    i = pool->mTakenCount;
found:
    if (i < pool->mRestingCount) {
        pool->mRestingCount = pool->mRestingCount - 1;
        endIndex = pool->mRestingCount;
        for (; i < endIndex; i++) {
            objects[i] = objects[i + 1];
        }
    }
    if (i < pool->mActiveCount) {
        pool->mActiveCount = pool->mActiveCount - 1;
        objects[i] = objects[pool->mActiveCount];
        i = pool->mActiveCount;
    }
    if (i < pool->mTakenCount) {
        pool->mTakenCount = pool->mTakenCount - 1;
        objects[i] = objects[pool->mTakenCount];
        i = pool->mTakenCount;
    }
    objects[i] = object;
    ReleaseItemObject(object);
    pool->mReservedCount = pool->mReservedCount - 1;
}

void StartItemObject(ItemPool *pool, ItemObject *object) {
    s32 i;
    s32 takenCount;
    ItemObject **objects;
    s32 activeCount;
    ItemKind *itemKind;
    enum { K0 } kind;

    activeCount = pool->mActiveCount;
    takenCount = pool->mTakenCount;
    i = activeCount;
    objects = pool->mObjects;
    if (activeCount < takenCount) {
        do {
            if (objects[i] == object) {
                goto found;
            }
            i++;
        } while (i < takenCount);
    }
    i = takenCount;
found:
    if (activeCount < i) {
        objects[i] = objects[activeCount];
        objects[pool->mActiveCount] = object;
    }
    pool->mActiveCount = pool->mActiveCount + 1;
    object->mFlags |= 0x2000;
    kind = pool->mKind;
    itemKind = gItemKinds + kind;
    if (itemKind->mRadius != 0) {
        CreateItemObjectCollisionSlot(object);
    }
    object->mAgeFrames = 0;
    kind = object->mKind;
    itemKind = gItemKinds + kind;
    if (itemKind->mStart != NULL) {
        itemKind->mStart(object);
    }
}

// Moves a resting object into the resting part of the pool.
void AddRestingItemPoolObject(ItemPool *pool, ItemObject *object) {
    s32 i;
    s32 n;
    ItemObject **objects;

    n = pool->mActiveCount;
    i = 0;
    objects = pool->mObjects;
    while (i < n) {
        if (objects[i] == object) {
            goto found;
        }
        i++;
    }
    i = n;
found:
    n = pool->mRestingCount;
    if (i < n) {
        return;
    }
    objects[i] = objects[n];
    objects[pool->mRestingCount] = object;
    pool->mRestingCount = pool->mRestingCount + 1;
}

void DrawItemPool(ItemPool *pool, void *viewAxis) {
    if (pool->mDraw != NULL) {
        DrawItemPoolWithCallback(pool, viewAxis, pool->mDraw);
    } else {
        DrawItemPoolModels(pool, viewAxis);
    }
}

void RoundTripItemObjectData(ItemObject *object) {
    void *(*copyData)(void *, void *, s32);
    s32 kind;
    void *data;

    data = NULL;
    kind = object->mKind;
    if ((object->mOwnerKartIndexAndFlags & 0xf00) != 0) {
        data = CopyItemObjectDataAndAdd(data, object, 1);
        CopyItemObjectDataAndAdd(data, object, 0);
        SetupItemObjectFromDataWrapper(object);
        if (object->mOwnerKartIndexAndFlags & 0x800) {
            ReplayPendingFadeOut(object);
        }
        if (object->mOwnerKartIndexAndFlags & 0x400) {
            ReplayPendingNoCallbackFadeOut(object);
        }
        if (object->mOwnerKartIndexAndFlags & 0x200) {
            StartItemObjectReleaseTimer(object);
        }
        if (object->mOwnerKartIndexAndFlags & 0x100) {
            StartItemObjectRelease(object);
        }
    } else {
        copyData = gItemKinds[kind].mCopyData;
        data = copyData(data, object, 1);
        copyData(data, object, 0);
        gItemKinds[kind].mInitFromData(object);
    }
    object->mFlags |= 0x20000000;
}

void StartItemObjectFromData(ItemPool *pool, s32 frameDifference, void *data, s32 c) {
    ItemObject *object;
    s32 takenIndex;
    s32 scanIndex;
    s32 takenCount;
    ItemObject **objects;
    s32 k;
    enum { J0 } kind;
    void (*initFunc)(void *);

    takenIndex = pool->mTakenCount;
    pool->mTakenCount = takenIndex + 1;
    object = pool->mObjects[takenIndex];
    ResetItemObjectFromData(object, pool->mKind, data, c);
    pool->mReservedCount = pool->mReservedCount + 1;
    k = pool->mActiveCount;
    takenCount = pool->mTakenCount;
    objects = pool->mObjects;
    scanIndex = k;
    if (k < takenCount) {
        do {
            if (objects[scanIndex] == object) {
                goto found;
            }
            scanIndex++;
        } while (scanIndex < takenCount);
    }
    scanIndex = takenCount;
found:
    if (k < scanIndex) {
        objects[scanIndex] = objects[k];
        objects[pool->mActiveCount] = object;
    }
    pool->mActiveCount = pool->mActiveCount + 1;
    object->mFlags |= 0x2000;
    kind = pool->mKind;
    if (gItemKinds[kind].mRadius != 0) {
        CreateItemObjectCollisionSlot(object);
    }
    object->mAgeFrames = 0;
    kind = object->mKind;
    if (gItemKinds[kind].mStart != NULL) {
        gItemKinds[kind].mStart(object);
    }
    if (c != 0) {
        initFunc = SetupItemObjectFromDataWrapper;
    } else {
        kind = object->mKind;
        initFunc = gItemKinds[kind].mInitFromData;
    }
    initFunc(object);
    object->mFlags |= 0x20000000;
    if (c != 0) {
        if (object->mOwnerKartIndexAndFlags & 0x800) {
            ReplayPendingFadeOut(object);
        }
        if (object->mOwnerKartIndexAndFlags & 0x400) {
            ReplayPendingNoCallbackFadeOut(object);
        }
        if (object->mOwnerKartIndexAndFlags & 0x200) {
            StartItemObjectReleaseTimer(object);
        }
        if (object->mOwnerKartIndexAndFlags & 0x100) {
            StartItemObjectRelease(object);
        }
    } else if ((object->mOwnerKartIndexAndFlags & 0x1000) == 0) {
        k = (u16) ((object->mOwnerKartIndexAndFlags & 0x8000) == 0 ? (u16) (object->mOwnerKartIndexAndFlags & ~0xff00)
                                                                   : 8);
        if (k != 8) {
            func_02071894(GetKart(k));
        }
    }
    if (frameDifference > 0) {
        object->mUnk_7a = frameDifference;
        object->mUnk_7a |= data_02159618;
    }
}

BOOL ApplyItemObjectEventById(ItemPool *pool, s32 eventByte, s32 objectId) {
    enum { K0 } k;
    s32 i;
    ItemObject *object;
    ItemObject **objects;
    s32 activeCount;
    BOOL found;
    BOOL z0;
    BOOL z1;
    BOOL z2;
    BOOL z3;
    BOOL z4;
    BOOL z5;
    u32 eventValue;

    k = eventByte;
    eventValue = ((u32) (k & 0xf0) << 12) >> 16;
    activeCount = pool->mActiveCount;
    objects = pool->mObjects;
    found = FALSE;
    i = 0;
    k &= 0xf;
    z0 = FALSE;
    z1 = FALSE;
    z2 = FALSE;
    z3 = FALSE;
    z4 = FALSE;
    z5 = FALSE;
    for (; i < activeCount; i++) {
        object = objects[i];
        if (objectId != object->mId) {
            continue;
        }
        found = TRUE;
        if (k < 4) {
            object->mVelocity.x = MUL_FIXED12_NO_ROUND(object->mVelocity.x, 0x4cd);
            object->mVelocity.y = MUL_FIXED12_NO_ROUND(object->mVelocity.y, 0x4cd);
            object->mVelocity.z = MUL_FIXED12_NO_ROUND(object->mVelocity.z, 0x4cd);
        }
        switch (k) {
            case 0:
                FadeOutEndedItemObject(object, z0);
                break;
            case 1:
                FadeOutItemObjectNoCallback(object, z1);
                break;
            case 2:
                FadeOutUsedUpItemObject(object, z2);
                break;
            case 3:
                if (pool->mKind == 1) {
                    if (RequestItemKouraRState5IfFar(object, eventValue) == 0) {
                        break;
                    }
                }
                FadeOutItemObjectHitByKart(object, z3, eventValue);
                break;
            case 4:
                StartItemObjectReleaseTimerSynced(object, z4);
                break;
            case 5:
                StartItemObjectReleaseSynced(object, z5);
                break;
        }
    }
    return found;
}

BOOL SetItemObjectKartFromPacket(ItemPool *pool, u8 *packet) {
    s32 objectId;
    s32 i;
    s32 activeCount;
    ItemObject *object;
    s32 value;
    ItemObject **objects;
    BOOL found;

    activeCount = pool->mActiveCount;
    i = 0;
    found = FALSE;
    objectId = packet[1];
    objects = pool->mObjects;
    for (; i < activeCount; i++) {
        object = objects[i];
        if (objectId != object->mId) {
            continue;
        }
        found = TRUE;
        value = packet[2];
        if (pool->mKind == 1) {
            RequestItemKouraRState4ForKart((ItemKouraR *) object, value);
        }
        if (pool->mKind == 5) {
            SetItemKouraWKartItemsAndStateIfNone((ItemKouraW *) object, value);
        }
        if (pool->mKind == 0xb) {
            SetItemTeresaFromPacket((ItemTeresa *) object, value, packet[3]);
        }
    }
    return found;
}

void ProcessItemPoolMessage(ItemPool *pool, s32 messageKind, s32 frameDifference, u8 *packet, s32 frameStamp) {
    enum { K0 } kind;

    switch (messageKind) {
        case 0:
            kind = pool->mKind;
            if (!gItemKinds[kind].mCopyData) {
                return;
            }
            if (packet[1] == 0xff) {
                return;
            }
            StartItemObjectFromData(pool, frameDifference, packet, 0);
            if (pool->mKind == 6) {
                StartThunderBlockTimer(0);
            }
            if (pool->mKind == 0xa) {
                StartGessoBlockTimer(0);
            }
            return;
        case 1:
            StartItemObjectFromData(pool, frameDifference, packet, 1);
            return;
        case 2:
            if (ApplyItemObjectEventById(pool, packet[2], packet[1]) != 0) {
                return;
            }
            break;
        case 3:
            if (SetItemObjectKartFromPacket(pool, packet) != 0) {
                return;
            }
            break;
        default:
            return;
    }
    DelayItemDataWithFrameStamp(pool->mKind, messageKind, frameDifference, packet, frameStamp);
}

// Moves resting objects that are old enough to release toward the front, comparing every seventh neighbouring pair.
void OrderItemPoolObjectsForRelease(ItemObject **objects, s32 pairIndex, s32 endIndex, s32 step) {
    ItemObject *previous;
    ItemObject *current;
    s32 j;

    if (pairIndex >= endIndex) {
        return;
    }
    do {
        previous = objects[pairIndex - 1];
        current = objects[pairIndex];
        if ((previous->mFlags & 0x180000) != 0) {
            goto next;
        }
        if (IsItemObjectOldAndResting(previous) != 0) {
            if (IsItemObjectOldAndResting(current) == 0) {
                goto next;
            }
            j = 0;
            do {
                if ((current->mCollisionBits & gItemCollisionBitOrder[j]) != 0) {
                    goto next;
                }
                if ((previous->mCollisionBits & gItemCollisionBitOrder[j]) != 0) {
                    objects[pairIndex - 1] = current;
                    objects[pairIndex] = previous;
                    goto next;
                }
                j++;
            } while (j < 0xd);
        } else if (IsItemObjectOldAndResting(current) != 0) {
            objects[pairIndex - 1] = current;
            objects[pairIndex] = previous;
        }
    next:
        pairIndex += step;
    } while (pairIndex < endIndex);
}

void UpdateItemPool(ItemPool *pool) {
    ItemObject **objects;
    ItemObject *object;
    Kart *kart;
    s32 updateCount;
    s32 min;
    Vec3 *objectPos;
    Vec3 *kartPos;
    s32 activeCount;
    s32 i;
    s32 frameMod8;
    s32 pendingUpdateCount;
    s32 hasFlag8000;
    s32 distanceSquared;
    s32 shiftedCount;
    s32 orderEndIndex;
    s32 deltaY;
    s32 deltaZ;
    u16 kartIndex;

    objects = pool->mObjects;
    activeCount = pool->mActiveCount;
    if (pool->mLimit > 1 && pool->mLimit - pool->mReservedCount < 2) {
        orderEndIndex = pool->mRestingCount;
        if ((frameMod8 = GetRaceUpdateFramesMod8()) == 0) {
            if (pool->mLimit - pool->mReservedCount < 1 && pool->mActiveCount > 0) {
                StartItemObjectReleaseIfOldResting(pool->mObjects[0]);
            }
        } else {
            if (pool->mKind == 2) {
                orderEndIndex -= 3;
            }
            OrderItemPoolObjectsForRelease(objects, frameMod8, orderEndIndex, 7);
        }
    }
    if (gRaceSetup->mMode != 5) {
        for (i = 0; i < activeCount; i++) {
            if (UpdateItemObject(pool, objects[i], 0) != 0) {
                activeCount = pool->mActiveCount, i--;
            }
        }
        return;
    }
    for (i = 0; i < activeCount; i++) {
        object = objects[i];
        pendingUpdateCount = (u16) (object->mUnk_7a & ~0x8000);
        if (pendingUpdateCount <= 0) {
            if (UpdateItemObject(pool, object, 0) != 0) {
                activeCount = pool->mActiveCount;
                i--;
            }
        } else {
            hasFlag8000 = object->mUnk_7a & 0x8000;
            updateCount = 1;
            if (hasFlag8000 != 0) {
                min = 0x5f592e1;
                object->mUnk_7a &= ~0x8000;
                updateCount += pendingUpdateCount;
            } else {
                updateCount++;
                for (shiftedCount = pendingUpdateCount >> 2; shiftedCount != 0; shiftedCount >>= 2) {
                    updateCount++;
                }
            }
            FindCollisionSlotsAroundPos(&object->mPos, object->mRadius + updateCount * 0xa000, 0x6000);
            object->mUnk_7a++;
            do {
                object->mUnk_7a--;
                if (UpdateItemObject(pool, object, 1) != 0) {
                    activeCount = pool->mActiveCount;
                    i--;
                    break;
                }
                if (hasFlag8000 != 0) {
                    objectPos = object->mPosPointer;
                    kartIndex = object->mOwnerKartIndexAndFlags & ~0xff00;
                    kart = GetKart(kartIndex);
                    kartPos = &kart->mDrawMatrixPos;
                    distanceSquared = ((kartPos->x - objectPos->x) >> 12) * ((kartPos->x - objectPos->x) >> 12);
                    deltaY = (kartPos->y - objectPos->y) >> 12;
                    deltaZ = (kartPos->z - objectPos->z) >> 12;
                    distanceSquared += deltaY * deltaY;
                    distanceSquared += deltaZ * deltaZ;
                    if (min <= distanceSquared) {
                        break;
                    }
                    min = distanceSquared;
                }
            } while (--updateCount > 0);
        }
    }
}

BOOL TryReleaseFirstItemObject(ItemPool *pool) {
    if (pool->mActiveCount <= 0) {
        return FALSE;
    }
    ReleaseItemPoolObject(pool, pool->mObjects[0]);
    return TRUE;
}

#pragma thumb on
void CreateItemPool(ItemPool *pool, s32 kind, s32 *objectIdCounter) {
    void *heap;
    s32 objectCount;
    s32 objectSize;
    s32 objectId;
    s32 i;

    heap = GetHeap(GetCurrentHeapCall());
    objectId = *objectIdCounter;
    objectCount = gItemKinds[kind].mObjectCount;
    objectSize = gItemKinds[kind].mObjectSize;
    pool->mKind = kind;
    pool->mObjects = objectCount != 0 ? (ItemObject **) HeapAlloc(heap, objectCount * 4) : 0;
    pool->mObjectCount = objectCount;
    pool->mUnk_0c = gItemKinds[kind].mUnk_10;
    pool->mTakenCount = 0;
    pool->mActiveCount = 0;
    pool->mRestingCount = 0;
    pool->mReservedCount = 0;
    pool->mLimit = gItemKinds[kind].mLimit;
    for (i = 0; i < objectCount; i++) {
        pool->mObjects[i] = HeapAlloc(heap, objectSize);
        InitItemObject(pool->mObjects[i], objectId, kind);
        objectId++;
        pool->mObjects[i]->mPoolIndex = i;
    }
    pool->mDraw = gItemKinds[kind].mDraw;
    pool->mViewTest = gItemKinds[kind].mViewTest;
    pool->mUnk_2c = gItemKinds[kind].mUnk_70;
    pool->mUnk_30 = gItemKinds[kind].mUnk_74;
    pool->mUnk_34 = gItemKinds[kind].mUnk_78;
    pool->mUnk_38 = gItemKinds[kind].mUnk_5c;
    pool->mUnk_3c = gItemKinds[kind].mUnk_a4;
    *objectIdCounter = objectId;
}

#pragma thumb off
BOOL TryAddKartItemFlags(KartItems *kartItems) {
    Kart *kart;
    u16 padBits;
    enum { K0 } entryIndex;

    kart = kartItems->mKart;
    if (IsRaceStarted() == 0) {
        return FALSE;
    }
    if (kart->mState != KART_STATE_NORMAL) {
        return FALSE;
    }
    if ((kart->mUnk_4c & KART_4C_HEADING_SWING) != 0) {
        return FALSE;
    }
    if (kartItems->mItemInUse.mObjectKind != 0xf) {
        kartItems->mFlags |= gKartItemsInUseBit;
    } else if (kartItems->mHeldItem.mItemInfoIndex != 0x13) {
        kartItems->mFlags |= gKartItemsHeldBit;
    } else if (kartItems->mSlotState != 0) {
        kartItems->mFlags |= gKartItemsSlotBit;
    }
    entryIndex = kartItems->mEntryIndex;
    padBits = gInputSlots[entryIndex].mBits & ITEM_THROW_FORWARD_BIT;
    if (padBits != 0) {
        kartItems->mFlags |= gKartItemsThrowForwardBit;
    }
    entryIndex = kartItems->mEntryIndex;
    padBits = gInputSlots[entryIndex].mBits & PAD_KEY_DOWN;
    if (padBits != 0) {
        kartItems->mFlags |= gKartItemsDownBit;
    }
    return TRUE;
}

void StopRunningKartItemSlot(KartItems *kartItems) {
    if ((kartItems->mKart->mUnk_7c & 0x400) != 0) {
        return;
    }
    if (gRaceSetup->mMode == 5) {
        return;
    }
    if (kartItems->mSlotState == 0) {
        return;
    }
    FinishItemSlotAndStopSound(kartItems);
}

void ReleaseKartItems(KartItems *kartItems) {
    if ((kartItems->mKart->mUnk_7c & 0x400) != 0) {
        return;
    }
    if (kartItems->mHeldItem.mItemInfoIndex != 0x13) {
        ReleaseHeldItem(&kartItems->mHeldItem, 0);
    }
    if (gRaceSetup->mMode == 5) {
        return;
    }
    if (kartItems->mSlotState != 0) {
        FinishItemSlotAndStopSound(kartItems);
    }
    if (kartItems->mActiveItem != 0x13) {
        kartItems->mActiveItem = 0x13;
    }
    if (gRaceSetup->mMode == 5) {
        return;
    }
    if (kartItems->mItemInUse.mObjectKind == 0xf) {
        return;
    }
    ReleaseItemInUse(&kartItems->mItemInUse);
}

void StartKartItemObjectCountdowns(KartItems *kartItems) {
    BOOL isMode5;

    isMode5 = gRaceSetup->mMode == 5;
    if ((kartItems->mKart->mUnk_7c & 0x400) != 0) {
        return;
    }
    if ((u32) (kartItems->mKart->mItemEffect - 2) <= 1) {
        return;
    }
    if (isMode5 && kartItems->mActiveItem != 0x13) {
        return;
    }
    if (kartItems->mHeldItem.mItemInfoIndex != 0x13 && kartItems->mHeldItem.mObjectStartFramesLeft == 0) {
        StartHeldItemObjects(&kartItems->mHeldItem);
    }
    if (isMode5) {
        return;
    }
    if (kartItems->mSlotState != 0) {
        FinishItemSlotAndStopSound(kartItems);
    }
    if (isMode5) {
        return;
    }
    if (kartItems->mItemInUse.mObjectKind == 0xf) {
        return;
    }
    if (kartItems->mItemInUse.mObjectStartFramesLeft != 0) {
        return;
    }
    StartItemInUseObjectCountdown(&kartItems->mItemInUse);
}

void StartKartItemInUseOneCountdown(KartItems *kartItems) {
    if ((u32) (kartItems->mKart->mItemEffect - 2) <= 1) {
        return;
    }
    if (gRaceSetup->mMode == 5) {
        return;
    }
    if (kartItems->mItemInUse.mObjectKind == 0xf) {
        return;
    }
    if (kartItems->mItemInUse.mObjectStartFramesLeft != 0) {
        return;
    }
    if (kartItems->mItemInUse.mUseKind != ITEM_USE_KIND_ONE &&
        kartItems->mItemInUse.mUseKind != ITEM_USE_KIND_ONE_WITH_ORIENTATION) {
        return;
    }
    StartItemInUseObjectCountdown(&kartItems->mItemInUse);
}

BOOL func_020efd84(KartItems *kartItems, s32 itemInfoIndex) {
    HeldItem *heldItem;
    ItemPool *pool;
    enum { K0 } objectKind;

    heldItem = &kartItems->mHeldItem;
    if (itemInfoIndex == 0x13) {
        return TRUE;
    }
    if (kartItems->mActiveItem != 0x13) {
        kartItems->mActiveItem = 0x13;
    }
    if (kartItems->mSlotState != 0) {
        if (kartItems->mSlotState == 1 && kartItems->mSlotFrames < 0x3c) {
            objectKind = gItemInfos[itemInfoIndex].mObjectKind;
            pool = &gItemPools[objectKind];
            pool->mReservedCount--;
            return TRUE;
        }
        StopItemSlot(kartItems);
        SetHeldItem(heldItem, itemInfoIndex);
    } else {
        if (heldItem->mItemInfoIndex == 0x13 && heldItem->mObjectCount == 0) {
            objectKind = gItemInfos[itemInfoIndex].mObjectKind;
            pool = &gItemPools[objectKind];
            pool->mReservedCount--;
        }
    }
    RemoveHeldItemObjects(heldItem, 1);
    return heldItem->mItemInfoIndex == 0x13;
}

void CopyKartPlacementToItemObject(KartItems *kartItems, ItemObject *object) {
    Kart *kart;
    Vec3 *axis;

    kart = kartItems->mKart;
    if ((kart->mUnk_48 & 1) != 0) {
        axis = &kart->mUnk_15c;
    } else {
        axis = &gKartItemsVec3UnitY;
    }
    SetItemObjectPlacement(object, &kart->mDrawMatrixPos, axis, &kart->mKartModelsEntry->mCourseColorBlend,
                           func_0206c0a8(kart));
    if ((kart->mUnk_48 & 1) != 0) {
        object->mFlags |= 0x40000000;
    }
}

void SetKartItemLinkFromHitValue(KartItems *kartItems, s32 hitValue) {
    ItemPointLinkRef *linkRef;
    Kart *kart;
    Vec3 *kartPos;
    s64 distanceSquared;
    s32 linkByIndex;
    if ((linkByIndex = GetItemPointLinkByIndex(hitValue)) != 0) {
        kartItems->mItemLink.mLink = (ItemPointLink *) linkByIndex;
        kartItems->mItemLink.mNextLinksUsed = 1;
    }
    if ((linkRef = &kartItems->mItemLink)->mLink == NULL) {
        return;
    }
    kart = kartItems->mKart;
    kartPos = &kart->mDrawMatrixPos;
    PickNearestNearbyItemPointLink(linkRef, linkRef, kartPos);
    distanceSquared = (s64) (linkRef->mLink->mPointPos->x - kartPos->x) * (linkRef->mLink->mPointPos->x - kartPos->x);
    distanceSquared += (s64) (linkRef->mLink->mPointPos->z - kartPos->z) * (linkRef->mLink->mPointPos->z - kartPos->z);
    if (distanceSquared < ((s64) 0x15f9 << 32)) {
        return;
    }
    FollowItemPointLinksToPos(linkRef, linkRef, kartPos);
}

#pragma thumb on
void InitKartItems(KartItems *kartItems, s32 kartIndex) {
    Unk02175620_060 *courseMap;

    kartItems->mKartIndex = kartIndex;
    kartItems->mKart = GetKart(kartIndex);
    kartItems->mEntryIndex = gRaceSetup->mCurrentEntries[kartIndex].mPlayer.mIndex;
    InitItemSlot(kartItems, kartItems);
    InitHeldItem(&kartItems->mHeldItem, kartItems);
    InitItemInUse(&kartItems->mItemInUse, kartItems);
    courseMap = (Unk02175620_060 *) gCourseMap;
    kartItems->mItemLink.mLink = courseMap->mUnk_060 != 0 ? courseMap->mUnk_0b0 : 0;
    kartItems->mItemLink.mNextLinksUsed = 1;
    kartItems->mKinokoBoostStarted = FALSE;
    kartItems->mTargetedByKouraR = FALSE;
    kartItems->mUnk_20c = FALSE;
}

#pragma thumb off
void StartItemInUseObject(ItemInUse *itemInUse, ItemObject *object) {
    StartItemObject(&gItemPools[object->mKind], object);
    CopyKartPlacementToItemObject(itemInUse->mKartItems, object);
    object->mFlags &= ~0x1000;
}

// Takes the last object out of the record, starts it and runs its kind's Init; the argument says whether to call
// func_02071894 on the kart.
void StartLastItemInUseObjectAndInit(ItemInUse *itemInUse, s32 callKart) {
    ItemObject *object;
    s32 (*initFunc)(void *, void *);
    void (*advanceFunc)(struct ItemObject *);

    itemInUse->mObjectCount--;
    object = itemInUse->mObjects[itemInUse->mObjectCount];
    initFunc = gItemKinds[object->mKind].mInit;
    StartItemInUseObject(itemInUse, object);
    if (initFunc(itemInUse, object) == 0) {
        if (itemInUse->mKartItems->mTargetedByKouraR != FALSE) {
            object->mOwnerKartIndexAndFlags |= data_021595ac;
            callKart = 0;
        }
    }
    object->mDistanceSquaredAndFlags =
        gItemKinds[object->mKind].mViewTest(object->mPosPointer, object->mRadius << 1,
                                            gItemKinds[object->mKind].mUnk_5c, gItemKinds[object->mKind].mUnk_a4, 0x1f);
    if (object->mFlags & 0x400000) {
        UpdateItemObjectSoundSource(object);
    }
    advanceFunc = gItemKinds[object->mKind].mAdvance;
    if ((object->mFlags & 0x180000) == 0) {
        object->mAdvance = advanceFunc;
    }
    if (callKart != 0) {
        func_02071894(itemInUse->mKart);
    }
}

// The object must be the last one of the record.
void StartItemInUseObjectAndCountDown(ItemInUse *itemInUse, ItemObject *object) {
    itemInUse->mObjectCount = itemInUse->mObjectCount - 1;
    StartItemInUseObject(itemInUse, object);
}

// Entry 1 of gItemInUseStartTable. (the same one-line form above the other start, advance and remove entries:
// StartItemInUseOneWithOrientation :886 entry 2, StartItemInUseCircle :1233 entry 4, AdvanceItemInUseOne :946 entry 1,
// AdvanceItemInUseOneWithOrientation :983 entry 2,  :1056 entry 3, AdvanceItemInUseCircle :1250 entry 4,  :1162 entry
// 3, RemoveItemInUseCircle :1306 entry 4)
void StartItemInUseOne(ItemInUse *itemInUse) {
    ItemInUse *inUseAlias;
    ItemObject *object;
    Vec3 *forwardAxis;
    s32 scaleOffset;

    inUseAlias = itemInUse;
    object = itemInUse->mObjects[0];
    forwardAxis = &itemInUse->mKartOrientation.mUnk_00[2];
    inUseAlias->mUnk_090 = *forwardAxis;
    inUseAlias->mBehindDirection.x = -forwardAxis->x;
    inUseAlias->mBehindDirection.y = -forwardAxis->y;
    inUseAlias->mBehindDirection.z = -forwardAxis->z;
    scaleOffset = ((s64) itemInUse->mKartScaleFactorTimesBase.z << 14) >> 12;
    VEC_MultAdd(itemInUse->mUnk_078 + scaleOffset, &inUseAlias->mBehindDirection, &itemInUse->mKartDrawMatrixPos,
                &inUseAlias->mBehindPos);
    VEC_MultAdd(MUL_FIXED12_NO_ROUND(itemInUse->mUnk_0e8, itemInUse->mKartScaleFactorTimesBase.z),
                &itemInUse->mKartOrientation.mUnk_00[1], &inUseAlias->mBehindPos, &object->mPos);
}

void StartItemInUseOneWithOrientation(ItemInUse *itemInUse) {
    ItemInUse *inUseAlias;
    ItemObject *object;
    Vec3 *forwardAxis;
    s32 scaleOffset;

    inUseAlias = itemInUse;
    object = itemInUse->mObjects[0];
    forwardAxis = &itemInUse->mKartOrientation.mUnk_00[2];
    inUseAlias->mUnk_090 = *forwardAxis;
    inUseAlias->mBehindDirection.x = -forwardAxis->x;
    inUseAlias->mBehindDirection.y = -forwardAxis->y;
    inUseAlias->mBehindDirection.z = -forwardAxis->z;
    scaleOffset = ((s64) itemInUse->mKartScaleFactorTimesBase.z << 14) >> 12;
    VEC_MultAdd(itemInUse->mUnk_078 + scaleOffset, &inUseAlias->mBehindDirection, &itemInUse->mKartDrawMatrixPos,
                &inUseAlias->mBehindPos);
    VEC_MultAdd(MUL_FIXED12_NO_ROUND(itemInUse->mUnk_0e8, itemInUse->mKartScaleFactorTimesBase.z),
                &itemInUse->mKartOrientation.mUnk_00[1], &inUseAlias->mBehindPos, &object->mPos);
    object->mUnk_94.mUnk_00[1] = itemInUse->mKartOrientation.mUnk_00[1];
    object->mUnk_94.mUnk_00[2].x = -inUseAlias->mBehindDirection.x;
    object->mUnk_94.mUnk_00[2].y = -inUseAlias->mBehindDirection.y;
    object->mUnk_94.mUnk_00[2].z = -inUseAlias->mBehindDirection.z;
    Vec3CrossUnrounded(&object->mUnk_94.mUnk_00[1], &object->mUnk_94.mUnk_00[2], &object->mUnk_94.mUnk_00[0]);
}

void ComputeItemInUseObjectPosition(ItemInUse *itemInUse, Vec3 *objectPos, Vec3 *behindPos) {
    ItemInUse *inUseAlias;
    Vec3 *smoothedDirection;
    Vec3 direction;
    s32 scaleOffset;
    s64 lengthSquared;

    inUseAlias = itemInUse;
    smoothedDirection = &inUseAlias->mUnk_090;
    direction = itemInUse->mKartOrientation.mUnk_00[2];
    if (itemInUse->mMovingForward != 0) {
        VEC_MultAdd(0x19a, &itemInUse->mKartMovement, &direction, &direction);
    }
    smoothedDirection->x = MUL_FIXED12_NO_ROUND(smoothedDirection->x, 0xccd);
    smoothedDirection->y = MUL_FIXED12_NO_ROUND(smoothedDirection->y, 0xccd);
    smoothedDirection->z = MUL_FIXED12_NO_ROUND(smoothedDirection->z, 0xccd);
    VEC_MultAdd(0x333, &direction, smoothedDirection, smoothedDirection);
    lengthSquared = (s64) smoothedDirection->x * smoothedDirection->x +
                    (s64) smoothedDirection->y * smoothedDirection->y +
                    (s64) smoothedDirection->z * smoothedDirection->z;
    if (lengthSquared >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(smoothedDirection, &direction);
    }
    inUseAlias->mBehindDirection.x = -direction.x;
    inUseAlias->mBehindDirection.y = -direction.y;
    inUseAlias->mBehindDirection.z = -direction.z;
    scaleOffset = ((s64) itemInUse->mKartScaleFactorTimesBase.z << 14) >> 12;
    VEC_MultAdd(itemInUse->mUnk_078 + scaleOffset, &inUseAlias->mBehindDirection, &itemInUse->mKartDrawMatrixPos,
                behindPos);
    if (itemInUse->mObjectCount > 1) {
        inUseAlias->mUnk_0e4 += MUL_FIXED12_NO_ROUND(itemInUse->mKartHopHeight, 0x333);
        inUseAlias->mUnk_0e4 -= MUL_FIXED12_NO_ROUND(inUseAlias->mUnk_0e4, 0x266);
    } else {
        inUseAlias->mUnk_0e4 += MUL_FIXED12_NO_ROUND(itemInUse->mKartHopHeight, 0xd1f);
        inUseAlias->mUnk_0e4 -= MUL_FIXED12_NO_ROUND(inUseAlias->mUnk_0e4, 0x68f);
    }
    VEC_MultAdd(inUseAlias->mUnk_0e4 - itemInUse->mKartHopHeight +
                    MUL_FIXED12_NO_ROUND(itemInUse->mUnk_0e8, itemInUse->mKartScaleFactorTimesBase.z),
                &itemInUse->mKartOrientation.mUnk_00[1], behindPos, objectPos);
}

void AdvanceItemInUseOne(ItemInUse *itemInUse) {
    ItemObject *object;
    KartItems *kartItems;
    s32 previousScale;
    enum { K0 } kind, entryIndex;

    object = itemInUse->mObjects[0];
    kartItems = itemInUse->mKartItems;
    previousScale = object->mScale.z;
    ComputeItemInUseObjectPosition(itemInUse, &object->mPos, &itemInUse->mBehindPos);
    if (object->mAgeFrames > 0xc) {
        kind = object->mKind;
        if (GrowItemObjectScale(object, gItemKinds[kind].mUnk_70, 0x333) != 0) {
            SetItemObjectScaleByRatios(object, itemInUse->mKartScaleFactorTimesBase.x,
                                       itemInUse->mKartScaleFactorTimesBase.y);
        }
    }
    if (previousScale < 0xccd && object->mScale.z >= 0xccd && itemInUse->mKartIndex == gRaceSetup->mEntryIndex) {
        StartSoundFullVolume(&kartItems->mKart->mSoundSource, 0xe7);
    }
    if ((kartItems->mFlags & 0x284) == 0x284 && itemInUse->mObjectKind != 0xf &&
        itemInUse->mObjectStartFramesLeft == 0) {
        StartLastItemInUseObjectAndInit(itemInUse, 1);
    }
    if (itemInUse->mIsActiveItem != FALSE) {
        kartItems->mActiveItem = 0x13;
        entryIndex = kartItems->mEntryIndex;
        if ((u16) (gInputSlots[entryIndex].mBits & ITEM_THROW_FORWARD_BIT) != 0) {
            kartItems->mFlags |= data_021595a0;
        }
        entryIndex = kartItems->mEntryIndex;
        if ((u16) (gInputSlots[entryIndex].mBits & PAD_KEY_DOWN) != 0) {
            kartItems->mFlags |= data_021595a4;
        }
        StartLastItemInUseObjectAndInit(itemInUse, 1);
    }
    kartItems->mFlags |= data_021595a8;
}

void AdvanceItemInUseOneWithOrientation(ItemInUse *itemInUse) {
    ItemInUse *inUseAlias;
    ItemObject *object;
    Vec3 direction;
    s64 t;
    s64 lengthSquared;
    enum { K0 } kind;

    inUseAlias = itemInUse;
    object = itemInUse->mObjects[0];
    AdvanceItemInUseOne(itemInUse);
    if ((object->mFlags & 0x1000) != 0) {
        direction.x = ((s64) inUseAlias->mBehindDirection.x << 13) >> 12;
        direction.y = ((s64) inUseAlias->mBehindDirection.y << 13) >> 12;
        direction.z = ((s64) inUseAlias->mBehindDirection.z << 13) >> 12;
        VEC_Add(&direction, &itemInUse->mKartOrientation.mUnk_00[2], &direction);
        lengthSquared = LENGTH_SQUARED(direction);
        if (lengthSquared >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&direction, &direction);
        }
        object->mUnk_94.mUnk_00[2].x = -direction.x;
        object->mUnk_94.mUnk_00[2].y = -direction.y;
        object->mUnk_94.mUnk_00[2].z = -direction.z;
        object->mUnk_94.mUnk_00[1] = itemInUse->mKartOrientation.mUnk_00[1];
        Vec3CrossUnrounded(&object->mUnk_94.mUnk_00[1], &object->mUnk_94.mUnk_00[2], &object->mUnk_94.mUnk_00[0]);
    }
    kind = object->mKind;
    if (gItemKinds[kind].mAdvanceInUse != NULL) {
        gItemKinds[kind].mAdvanceInUse(itemInUse, object);
    }
}

// Entry 1 and 2 of gItemInUseRemoveTable.
void RemoveItemInUseOne(ItemInUse *itemInUse, ItemObject *index, ItemObject *object) {
    StartItemInUseObjectAndCountDown(itemInUse, object);
}

void StartItemInUseTrail(ItemInUse *itemInUse) {
    ItemObject *object;
    Vec3 *objectPos;
    s32 scaleOffset;
    s32 i;
    Vec3 *forwardAxis;
    ItemObject **objects;

    objects = itemInUse->mObjects;
    object = objects[0];
    objectPos = &object->mPos;
    forwardAxis = &itemInUse->mKartOrientation.mUnk_00[2];
    itemInUse->mUnk_090 = *forwardAxis;
    itemInUse->mBehindDirection.x = -itemInUse->mKartOrientation.mUnk_00[2].x;
    itemInUse->mBehindDirection.y = -forwardAxis->y;
    itemInUse->mBehindDirection.z = -forwardAxis->z;
    scaleOffset = ((s64) itemInUse->mKartScaleFactorTimesBase.z << 14) >> 12;
    VEC_MultAdd(itemInUse->mUnk_078 + scaleOffset, &itemInUse->mBehindDirection, &itemInUse->mKartDrawMatrixPos,
                &itemInUse->mBehindPos);
    VEC_MultAdd(MUL_FIXED12_NO_ROUND(itemInUse->mUnk_0e8, itemInUse->mKartScaleFactorTimesBase.z),
                &itemInUse->mKartOrientation.mUnk_00[1], &itemInUse->mBehindPos, objectPos);
    objects[1]->mPos = itemInUse->mObjects[0]->mPos;
    objects[2]->mPos = objects[1]->mPos;
    itemInUse->mUnk_0b4 = itemInUse->mBehindPos;
    itemInUse->mUnk_0c0 = itemInUse->mUnk_0b4;
    itemInUse->mUnk_0cc[0] = 0xee1;
    itemInUse->mUnk_0cc[1] = itemInUse->mUnk_0cc[0];
    itemInUse->mUnk_0cc[2] = itemInUse->mUnk_0cc[1];
    itemInUse->mUnk_0d8 = itemInUse->mKartOrientation.mUnk_00[2];
    itemInUse->mUnk_16c = 0;
    for (i = 0; i < 0x10; i++) {
        itemInUse->mUnk_0ec[0][i] = 0;
        itemInUse->mUnk_0ec[1][i] = 0;
    }
    if (itemInUse->mKartIndex == gRaceSetup->mEntryIndex) {
        StartSoundFullVolume(&itemInUse->mKartItems->mKart->mSoundSource, 0xe7);
    }
}

void AdvanceItemInUseTrail(ItemInUse *itemInUse) {
    KartItems *kartItems;
    ItemObject **objects;
    s32 objectCount;
    s32 historyIndex;
    Vec3 *behindDirection;
    s32 speedFactor;
    s32 scaleLimit;
    s32 maxGap;
    s32 d;
    s32 delayedHopHeight;
    s32 velocityLengthSquared;
    Vec3 kartVector;
    Vec3 offset;
    Vec3 directionChange;
    Vec3 *previousPos;
    s32 i;
    s32 minDistance;
    Vec3 *trailPos;
    ItemObject *object;
    ItemInUse *inUseAlias;

    inUseAlias = itemInUse;
    kartItems = itemInUse->mKartItems;
    object = itemInUse->mObjects[0];
    objectCount = itemInUse->mObjectCount;
    kartVector = kartItems->mKart->mUnk_1fc;
    objects = itemInUse->mObjects;
    minDistance = itemInUse->mUnk_078 + (s32) (((s64) itemInUse->mKartScaleFactorTimesBase.z << 14) >> 12);
    previousPos = &inUseAlias->mBehindPos;
    maxGap = MUL_FIXED12_NO_ROUND(itemInUse->mKartScaleFactorTimesBase.z, 0x3000);
    behindDirection = &inUseAlias->mBehindDirection;
    scaleLimit = gItemKinds[object->mKind].mUnk_70;
    ComputeItemInUseObjectPosition(itemInUse, &object->mPos, previousPos);
    if (GrowItemObjectScale(object, scaleLimit, 0x19a) != 0) {
        SetItemObjectScaleByRatios(object, itemInUse->mKartScaleFactorTimesBase.x,
                                   itemInUse->mKartScaleFactorTimesBase.y);
    }
    if (objectCount > 1) {
        if (itemInUse->mMovingForward != 0) {
            VEC_Subtract(&inUseAlias->mUnk_0d8, &inUseAlias->mBehindDirection, &directionChange);
            velocityLengthSquared =
                MUL_FIXED12_NO_ROUND(itemInUse->mKartVelocityLength, itemInUse->mKartVelocityLength);
            directionChange.x = MUL_FIXED12_NO_ROUND(directionChange.x, velocityLengthSquared);
            directionChange.y = MUL_FIXED12_NO_ROUND(directionChange.y, velocityLengthSquared);
            directionChange.z = MUL_FIXED12_NO_ROUND(directionChange.z, velocityLengthSquared);
        }
        inUseAlias->mUnk_0d8 = inUseAlias->mBehindDirection;
        historyIndex = inUseAlias->mUnk_16c & 0xf;
        inUseAlias->mUnk_16c = inUseAlias->mUnk_16c + 1;
        inUseAlias->mUnk_0ec[0][historyIndex] = inUseAlias->mUnk_0e4;
        speedFactor = ((s64) itemInUse->mKartVelocityLength << 9) >> 12;
        if (speedFactor > 0x1000) {
            speedFactor = 0x1000;
        }
    }
    for (i = 1; i < objectCount; i++) {
        object = objects[i];
        trailPos = &(&inUseAlias->mBehindPos)[i];
        VEC_Add(trailPos, &kartVector, trailPos);
        if (itemInUse->mObjectStartFramesLeft != 0) {
            VEC_Add(&objects[i - 1]->mVelocity, &object->mVelocity, &object->mVelocity);
        }
        if (itemInUse->mMovingForward != 0) {
            VEC_MultAdd(i * 0x1800, &directionChange, trailPos, trailPos);
        }
        if (inUseAlias->mUnk_0cc[i] > 0) {
            VEC_MultAdd(inUseAlias->mUnk_0cc[i], &itemInUse->mKartMovement, trailPos, trailPos);
        }
        VEC_Subtract(trailPos, &itemInUse->mKartDrawMatrixPos, &offset);
        if (i > 1) {
            minDistance -= (i - 1) << 13;
        }
        d = minDistance - Vec3DotUnrounded(&offset, behindDirection);
        if (d > 0) {
            VEC_MultAdd(d, behindDirection, trailPos, trailPos);
        }
        d = MUL_FIXED12_NO_ROUND(previousPos->y - trailPos->y, 0x666);
        if (d < 0) {
            trailPos->y = trailPos->y + d;
        }
        delayedHopHeight = inUseAlias->mUnk_0ec[i - 1][(historyIndex - 6) & 0xf];
        if (i == 1) {
            inUseAlias->mUnk_0ec[1][historyIndex] = delayedHopHeight;
        }
        d = delayedHopHeight - itemInUse->mKartHopHeight;
        d = MUL_FIXED12_NO_ROUND(d, speedFactor);
        VEC_Subtract(trailPos, previousPos, &offset);
        if (LENGTH_SQUARED(offset) >= (s64) maxGap * maxGap) {
            if (LENGTH_SQUARED(offset) >= 0x10) {
                Vec3NormalizeAndGetLengthUnchecked(&offset, &offset);
            }
            VEC_MultAdd(maxGap, &offset, previousPos, trailPos);
            if (inUseAlias->mUnk_0cc[i] > 0) {
                inUseAlias->mUnk_0cc[i] -= 0x3d;
            }
        }
        VEC_MultAdd(d + MUL_FIXED12_NO_ROUND(itemInUse->mKartScaleFactorTimesBase.z, 0x4333),
                    &itemInUse->mKartOrientation.mUnk_00[1], trailPos, &object->mPos);
        previousPos = trailPos;
        if (GrowItemObjectScale(object, scaleLimit, 0x19a + i * 0xcd) != 0) {
            SetItemObjectScaleByRatios(object, itemInUse->mKartScaleFactorTimesBase.x,
                                       itemInUse->mKartScaleFactorTimesBase.y);
        }
    }
    if ((kartItems->mFlags & 0x244) == 0x244 && itemInUse->mObjectKind != 0xf &&
        itemInUse->mObjectStartFramesLeft == 0) {
        StartLastItemInUseObjectAndInit(itemInUse, 1);
    }
}

void RemoveItemInUseTrail(ItemInUse *itemInUse, s32 i, ItemObject *object) {
    s32 releaseCount;
    ItemObject *released;
    s32 sum;
    s32 b;
    s32 d;

    releaseCount = 0;
    sum = 0;
    d = i;
    d = d + 1;
    if (itemInUse->mObjectCount > (b = d)) {
        s32 f = 0;
        d = f;
        do {
            released = itemInUse->mObjects[itemInUse->mObjectCount - 1];
            StartLastItemInUseObjectAndInit(itemInUse, 0);
            f = f + 0x4cd;
            if (releaseCount++ > 0) {
                VEC_MultAdd(f, &released->mNormal, &released->mVelocity, &released->mVelocity);
            }
        } while (itemInUse->mObjectCount > (b = i + 1));
        f = d + 1;
    }
    StartItemInUseObjectAndCountDown(itemInUse, object);
}

void PlaceItemInUseCircleObjects(ItemInUse *itemInUse) {
    ItemObject **objects;
    s32 objectCount;
    s32 radius;
    s32 offsetX;
    s32 offsetYScaled;
    s32 offsetXScaled;
    s32 negativeHalfOffsetY;
    s32 negativeHalfOffsetX;
    s32 i;
    Vec3 *objectPos;
    Vec3 *thirdAxis;
    Vec3 *firstAxis;
    Vec3 *center;
    s32 offsetY;

    i = itemInUse->mCircleAngle >> 4;
    objectCount = itemInUse->mObjectCount;
    radius = itemInUse->mCircleRadius;
    offsetY = MUL_FIXED12_NO_ROUND(radius, gPairsByAngle[i * 2 + 1]);
    offsetX = MUL_FIXED12_NO_ROUND(radius, gPairsByAngle[i * 2]);
    negativeHalfOffsetY = -offsetY >> 1;
    negativeHalfOffsetX = -offsetX >> 1;
    objects = itemInUse->mObjects;
    thirdAxis = &itemInUse->mKartOrientation.mUnk_00[2];
    firstAxis = &itemInUse->mKartOrientation.mUnk_00[0];
    center = &itemInUse->mCircleCenter;
    offsetYScaled = MUL_FIXED12_NO_ROUND(offsetY, 0xddb);
    offsetXScaled = MUL_FIXED12_NO_ROUND(offsetX, 0xddb);
    for (i = 0; i < objectCount; i++) {
        objectPos = &objects[i]->mPos;
        if (itemInUse->mCircleSlots[i] == 0) {
            VEC_MultAdd(offsetY, thirdAxis, center, objectPos);
            VEC_MultAdd(offsetX, firstAxis, objectPos, objectPos);
        } else if (itemInUse->mCircleSlots[i] == 1) {
            VEC_MultAdd(negativeHalfOffsetY - offsetXScaled, thirdAxis, center, objectPos);
            VEC_MultAdd(negativeHalfOffsetX + offsetYScaled, firstAxis, objectPos, objectPos);
        } else {
            VEC_MultAdd(negativeHalfOffsetY + offsetXScaled, thirdAxis, center, objectPos);
            VEC_MultAdd(negativeHalfOffsetX - offsetYScaled, firstAxis, objectPos, objectPos);
        }
    }
}

void StartItemInUseCircle(ItemInUse *itemInUse) {
    u16 i;

    itemInUse->mCircleAngle = 0;
    itemInUse->mCircleAngleSpeed = 0x258;
    itemInUse->mCircleRadius = 0;
    itemInUse->mUnk_17c = 0;
    for (i = 0; i < 3; i++) {
        itemInUse->mCircleSlots[i] = i;
    }
    VEC_MultAdd(MUL_FIXED12_NO_ROUND(itemInUse->mKartScaleFactorTimesBase.z, 0x4333),
                &itemInUse->mKartOrientation.mUnk_00[1], &itemInUse->mKartDrawMatrixPos, &itemInUse->mCircleCenter);
    PlaceItemInUseCircleObjects(itemInUse);
    if (itemInUse->mKartIndex == gRaceSetup->mEntryIndex) {
        StartSoundFullVolume(&itemInUse->mKartItems->mKart->mSoundSource, 0xe7);
    }
}

void AdvanceItemInUseCircle(ItemInUse *itemInUse) {
    KartItems *kartItems;
    s32 i;
    s32 objectCount;
    s32 scaleLimit;
    u32 speedAngle;
    ItemObject *object;
    enum { K0 } kind;

    kartItems = itemInUse->mKartItems;
    objectCount = itemInUse->mObjectCount;
    speedAngle = (u16) (((u32) (itemInUse->mKartVelocityLength * 0x1e)) >> 12);
    if (itemInUse->mKart->mState != KART_STATE_NORMAL) {
        itemInUse->mCircleAngleSpeed = 0;
    } else {
        if (itemInUse->mCircleAngleSpeed < 0x578) {
            itemInUse->mCircleAngleSpeed = itemInUse->mCircleAngleSpeed + 0x46;
        }
        itemInUse->mCircleAngle = itemInUse->mCircleAngle + itemInUse->mCircleAngleSpeed;
        if (speedAngle >= 0x12c) {
            speedAngle = 0x12c;
        }
        itemInUse->mCircleAngle = itemInUse->mCircleAngle + speedAngle;
    }
    itemInUse->mUnk_17c = itemInUse->mUnk_17c + MUL_FIXED12_NO_ROUND(itemInUse->mKartHopHeight, 0x666);
    itemInUse->mUnk_17c = itemInUse->mUnk_17c - MUL_FIXED12_NO_ROUND(itemInUse->mUnk_17c, 0x333);
    VEC_MultAdd((itemInUse->mUnk_17c - itemInUse->mKartHopHeight) +
                    MUL_FIXED12_NO_ROUND(itemInUse->mKartScaleFactorTimesBase.z, 0x4333),
                &itemInUse->mKartOrientation.mUnk_00[1], &itemInUse->mKartDrawMatrixPos, &itemInUse->mCircleCenter);
    itemInUse->mCircleRadius =
        itemInUse->mCircleRadius +
        MUL_FIXED12_NO_ROUND(
            (itemInUse->mUnk_078 + MUL_FIXED12_NO_ROUND(itemInUse->mKartScaleFactorTimesBase.z, 0x3000)) -
                itemInUse->mCircleRadius,
            0x333);
    PlaceItemInUseCircleObjects(itemInUse);
    i = 0;
    kind = itemInUse->mObjectKind;
    scaleLimit = gItemKinds[kind].mUnk_70;
    for (; i < objectCount; i++) {
        object = itemInUse->mObjects[i];
        if (GrowItemObjectScale(object, scaleLimit, 0x19a) != 0) {
            SetItemObjectScaleByRatios(object, itemInUse->mKartScaleFactorTimesBase.x,
                                       itemInUse->mKartScaleFactorTimesBase.y);
        }
    }
    if (itemInUse->mKartIndex == gRaceSetup->mEntryIndex) {
        StartSoundWhileRequestedFullVolume(&kartItems->mKart->mSoundSource, objectCount + 0xe0);
    }
    if ((kartItems->mFlags & 0x244) != 0x244) {
        return;
    }
    if (itemInUse->mObjectKind == 0xf) {
        return;
    }
    if (itemInUse->mObjectStartFramesLeft != 0) {
        return;
    }
    StartLastItemInUseObjectAndInit(itemInUse, 1);
}

void RemoveItemInUseCircle(ItemInUse *itemInUse, s32 i, ItemObject *object) {
    s32 lastIndex;
    u16 lastSlot;
    ItemObject *lastObject;

    lastIndex = itemInUse->mObjectCount - 1;
    if (i != lastIndex) {
        lastObject = itemInUse->mObjects[lastIndex];
        lastSlot = itemInUse->mCircleSlots[lastIndex];
        itemInUse->mObjects[lastIndex] = object;
        itemInUse->mCircleSlots[lastIndex] = itemInUse->mCircleSlots[i];
        itemInUse->mObjects[i] = lastObject;
        itemInUse->mCircleSlots[i] = lastSlot;
    }
    StartItemInUseObjectAndCountDown(itemInUse, object);
}

void ResetItemInUse(ItemInUse *itemInUse) {
    s32 i;

    itemInUse->mObjectKind = 0xf;
    itemInUse->mUseKind = 5;
    itemInUse->mItemInfoIndex = 0x13;
    for (i = 0; i < 3; i++) {
        itemInUse->mObjects[i] = NULL;
    }
    itemInUse->mObjectCount = 0;
    itemInUse->mObjectStartFramesLeft = 0;
}

void InitItemInUse(ItemInUse *itemInUse, KartItems *kartItems) {
    itemInUse->mKartItems = kartItems;
    itemInUse->mKart = kartItems->mKart;
    itemInUse->mKartIndex = kartItems->mKartIndex;
    ResetItemInUse(itemInUse);
}
