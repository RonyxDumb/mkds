#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/System/Heap.h"
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
#include "Main/Item/ItemInUse.h"
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
void it_itemsetAcquireItems(ItemPool *pool, s32 count, ItemObject **out, u16 kartIndex, Vec3 *pos) {
    s32 i;

    if (pool->mTakenCount + count > pool->mObjectCount) {
        while (pool->mTakenCount + count > pool->mObjectCount) {
            if (pool->mActiveCount > 0) {
                it_itemsetDestroyItem(pool, pool->mObjects[0]);
            }
        }
    }
    i = 0;
    while (i < count) {
        out[i] = pool->mObjects[pool->mTakenCount++];
        it_20F99B8(out[i], pool->mKind, kartIndex, pos);
        i++;
    }
}

void it_itemsetDestroyItem(ItemPool *pool, ItemObject *object) {
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
    if (i < pool->field18) {
        pool->field18 = pool->field18 - 1;
        endIndex = pool->field18;
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
    it_destroy(object);
    pool->mReservedCount = pool->mReservedCount - 1;
}

void it_itemsetAddItem(ItemPool *pool, ItemObject *object) {
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
    itemKind = it_sItemParams + kind;
    if (itemKind->field6C != 0) {
        CreateItemObjectCollisionSlot(object);
    }
    object->mAgeFrames = 0;
    kind = object->mKind;
    itemKind = it_sItemParams + kind;
    if (itemKind->mStart != NULL) {
        itemKind->mStart(object);
    }
}

void sub_20F0E2C(ItemPool *pool, ItemObject *object) {
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
    n = pool->field18;
    if (i < n) {
        return;
    }
    objects[i] = objects[n];
    objects[pool->field18] = object;
    pool->field18 = pool->field18 + 1;
}

void it_renderItemset(ItemPool *pool, void *viewAxis) {
    if (pool->field24 != NULL) {
        it_20ED718(pool, viewAxis, (void (*)(void *, void *, void *)) pool->field24);
    } else {
        it_20ED79C(pool, viewAxis);
    }
}

void func_020f0d04(ItemObject *object) {
    void *(*copyData)(void *, void *, s32);
    s32 kind;
    void *data;

    data = NULL;
    kind = object->mKind;
    if ((object->field78 & 0xf00) != 0) {
        data = func_020fe4c0(data, object, 1);
        func_020fe4c0(data, object, 0);
        sub_20FE4B4(object);
        if (object->field78 & 0x800) {
            sub_20F70F0(object);
        }
        if (object->field78 & 0x400) {
            sub_20F705C(object);
        }
        if (object->field78 & 0x200) {
            StartItemObjectReleaseTimer(object);
        }
        if (object->field78 & 0x100) {
            StartItemObjectRelease(object);
        }
    } else {
        copyData = it_sItemParams[kind].mCopyData;
        data = copyData(data, object, 1);
        copyData(data, object, 0);
        it_sItemParams[kind].mInitFromData(object);
    }
    object->mFlags |= 0x20000000;
}

void sub_20F0B00(ItemPool *pool, s32 a, void *data, s32 c) {
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
    if (it_sItemParams[kind].field6C != 0) {
        CreateItemObjectCollisionSlot(object);
    }
    object->mAgeFrames = 0;
    kind = object->mKind;
    if (it_sItemParams[kind].mStart != NULL) {
        it_sItemParams[kind].mStart(object);
    }
    if (c != 0) {
        initFunc = sub_20FE4B4;
    } else {
        kind = object->mKind;
        initFunc = it_sItemParams[kind].mInitFromData;
    }
    initFunc(object);
    object->mFlags |= 0x20000000;
    if (c != 0) {
        if (object->field78 & 0x800) {
            sub_20F70F0(object);
        }
        if (object->field78 & 0x400) {
            sub_20F705C(object);
        }
        if (object->field78 & 0x200) {
            StartItemObjectReleaseTimer(object);
        }
        if (object->field78 & 0x100) {
            StartItemObjectRelease(object);
        }
    } else if ((object->field78 & 0x1000) == 0) {
        k = (u16) ((object->field78 & 0x8000) == 0 ? (u16) (object->field78 & ~0xff00) : 8);
        if (k != 8) {
            driver_tryEmitItemUseVoice(driver_getById(k));
        }
    }
    if (a > 0) {
        object->field7A = a;
        object->field7A |= data_02159618;
    }
}

s32 sub_20F0950(ItemPool *pool, s32 eventByte, s32 objectId) {
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
            object->mVelocity.x = ((s64) object->mVelocity.x * 0x4cd) >> 12;
            object->mVelocity.y = ((s64) object->mVelocity.y * 0x4cd) >> 12;
            object->mVelocity.z = ((s64) object->mVelocity.z * 0x4cd) >> 12;
        }
        switch (k) {
            case 0:
                sub_20F7104(object, z0);
                break;
            case 1:
                sub_20F7070(object, z1);
                break;
            case 2:
                sub_20F6FC4(object, z2);
                break;
            case 3:
                if (pool->mKind == 1) {
                    if (sub_20F5324(object, eventValue) == 0) {
                        break;
                    }
                }
                sub_20F6F10(object, z3, eventValue);
                break;
            case 4:
                sub_20F7658(object, z4);
                break;
            case 5:
                sub_20F7430(object, z5);
                break;
        }
    }
    return found;
}

s32 sub_20F0898(ItemPool *pool, u8 *packet) {
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
            sub_20F5CC4(object, value);
        }
        if (pool->mKind == 5) {
            SetItemKouraWKartItemsAndStateIfNone((ItemKouraW *) object, value);
        }
        if (pool->mKind == 0xb) {
            sub_21003E8((ItemTeresa *) object, value, packet[3]);
        }
    }
    return found;
}

void sub_20F0758(ItemPool *pool, s32 messageKind, s32 b, u8 *packet, s32 d) {
    enum { K0 } kind;

    switch (messageKind) {
        case 0:
            kind = pool->mKind;
            if (!it_sItemParams[kind].mCopyData) {
                return;
            }
            if (packet[1] == 0xff) {
                return;
            }
            sub_20F0B00(pool, b, packet, 0);
            if (pool->mKind == 6) {
                sub_20F82E8(0);
            }
            if (pool->mKind == 0xa) {
                sub_20F82A4(0);
            }
            return;
        case 1:
            sub_20F0B00(pool, b, packet, 1);
            return;
        case 2:
            if (sub_20F0950(pool, packet[2], packet[1]) != 0) {
                return;
            }
            break;
        case 3:
            if (sub_20F0898(pool, packet) != 0) {
                return;
            }
            break;
        default:
            return;
    }
    sub_20FE56C(pool->mKind, messageKind, b, packet, d);
}

void sub_20F0684(ItemObject **objects, s32 pairIndex, s32 endIndex, s32 step) {
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
        if (sub_20F9C08(previous) != 0) {
            if (sub_20F9C08(current) == 0) {
                goto next;
            }
            j = 0;
            do {
                if ((current->mCollisionBits & data_021595e4[j]) != 0) {
                    goto next;
                }
                if ((previous->mCollisionBits & data_021595e4[j]) != 0) {
                    objects[pairIndex - 1] = current;
                    objects[pairIndex] = previous;
                    goto next;
                }
                j++;
            } while (j < 0xd);
        } else if (sub_20F9C08(current) != 0) {
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
    s32 w;
    s32 distanceSquared;
    s32 z;
    s32 m;
    s32 deltaY;
    s32 deltaZ;
    u16 kartIndex;

    objects = pool->mObjects;
    activeCount = pool->mActiveCount;
    if (pool->mLimit > 1 && pool->mLimit - pool->mReservedCount < 2) {
        m = pool->field18;
        if ((frameMod8 = race_getFrameCounterModulo8()) == 0) {
            if (pool->mLimit - pool->mReservedCount < 1 && pool->mActiveCount > 0) {
                sub_20F9BA8(pool->mObjects[0]);
            }
        } else {
            if (pool->mKind == 2) {
                m -= 3;
            }
            sub_20F0684(objects, frameMod8, m, 7);
        }
    }
    if (gRaceMultiConfig->mMode != 5) {
        for (i = 0; i < activeCount; i++) {
            if (UpdateItemObject(pool, objects[i], 0) != 0) {
                activeCount = pool->mActiveCount, i--;
            }
        }
        return;
    }
    for (i = 0; i < activeCount; i++) {
        object = objects[i];
        pendingUpdateCount = (u16) (object->field7A & ~0x8000);
        if (pendingUpdateCount <= 0) {
            if (UpdateItemObject(pool, object, 0) != 0) {
                activeCount = pool->mActiveCount;
                i--;
            }
        } else {
            w = object->field7A & 0x8000;
            updateCount = 1;
            if (w != 0) {
                min = 0x5f592e1;
                object->field7A &= ~0x8000;
                updateCount += pendingUpdateCount;
            } else {
                updateCount++;
                for (z = pendingUpdateCount >> 2; z != 0; z >>= 2) {
                    updateCount++;
                }
            }
            col_queryBySphere(&object->mPos, object->mRadius + updateCount * 0xa000, 0x6000);
            object->field7A++;
            do {
                object->field7A--;
                if (UpdateItemObject(pool, object, 1) != 0) {
                    activeCount = pool->mActiveCount;
                    i--;
                    break;
                }
                if (w != 0) {
                    objectPos = object->fieldD0;
                    kartIndex = object->field78 & ~0xff00;
                    kart = driver_getById(kartIndex);
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
    it_itemsetDestroyItem(pool, pool->mObjects[0]);
    return TRUE;
}

#pragma thumb on
void it_initItemset(ItemPool *pool, s32 kind, s32 *objectIdCounter) {
    void *heap;
    s32 objectCount;
    s32 objectSize;
    s32 objectId;
    s32 i;

    heap = proc_getHeap(proc_getCurrent());
    objectId = *objectIdCounter;
    objectCount = it_sItemParams[kind].mObjectCount;
    objectSize = it_sItemParams[kind].mObjectSize;
    pool->mKind = kind;
    pool->mObjects = objectCount != 0 ? (ItemObject **) heap_alloc(heap, objectCount * 4) : 0;
    pool->mObjectCount = objectCount;
    pool->fieldC = it_sItemParams[kind].field10;
    pool->mTakenCount = 0;
    pool->mActiveCount = 0;
    pool->field18 = 0;
    pool->mReservedCount = 0;
    pool->mLimit = it_sItemParams[kind].mLimit;
    for (i = 0; i < objectCount; i++) {
        pool->mObjects[i] = heap_alloc(heap, objectSize);
        InitItemObject(pool->mObjects[i], objectId, kind);
        objectId++;
        pool->mObjects[i]->mPoolIndex = i;
    }
    pool->field24 = it_sItemParams[kind].mDraw;
    pool->field28 = it_sItemParams[kind].mViewTest;
    pool->field2C = it_sItemParams[kind].field70;
    pool->field30 = it_sItemParams[kind].field74;
    pool->field34 = it_sItemParams[kind].field78;
    pool->field38 = it_sItemParams[kind].field5C;
    pool->field3C = it_sItemParams[kind].fieldA4;
    *objectIdCounter = objectId;
}

#pragma thumb off
BOOL func_020f0154(KartItems *kartItems) {
    Kart *kart;
    u16 padBits;
    enum { K0 } entryIndex;

    kart = kartItems->mKart;
    if (race_getState() == 0) {
        return FALSE;
    }
    if (kart->mState != KART_STATE_NORMAL) {
        return FALSE;
    }
    if ((kart->field4C & KART_4C_HEADING_SWING) != 0) {
        return FALSE;
    }
    if (kartItems->mItemInUse.mObjectKind != 0xf) {
        kartItems->mFlags |= data_021595b8;
    } else if (kartItems->mHeldItem.mItemInfoIndex != 0x13) {
        kartItems->mFlags |= data_021595bc;
    } else if (kartItems->mSlotState != 0) {
        kartItems->mFlags |= data_021595c0;
    }
    entryIndex = kartItems->mEntryIndex;
    padBits = data_0217562a[entryIndex].mBits & ITEM_THROW_FORWARD_BIT;
    if (padBits != 0) {
        kartItems->mFlags |= data_021595c4;
    }
    entryIndex = kartItems->mEntryIndex;
    padBits = data_0217562a[entryIndex].mBits & PAD_KEY_DOWN;
    if (padBits != 0) {
        kartItems->mFlags |= data_021595c8;
    }
    return TRUE;
}

void sub_20F00F0(KartItems *kartItems) {
    if ((kartItems->mKart->field7C & 0x400) != 0) {
        return;
    }
    if (gRaceMultiConfig->mMode == 5) {
        return;
    }
    if (kartItems->mSlotState == 0) {
        return;
    }
    it_resetDriverItemStatus(kartItems);
}

void ReleaseKartItems(KartItems *kartItems) {
    if ((kartItems->mKart->field7C & 0x400) != 0) {
        return;
    }
    if (kartItems->mHeldItem.mItemInfoIndex != 0x13) {
        it_destroySlotItem(&kartItems->mHeldItem, 0);
    }
    if (gRaceMultiConfig->mMode == 5) {
        return;
    }
    if (kartItems->mSlotState != 0) {
        it_resetDriverItemStatus(kartItems);
    }
    if (kartItems->mActiveItem != 0x13) {
        kartItems->mActiveItem = 0x13;
    }
    if (gRaceMultiConfig->mMode == 5) {
        return;
    }
    if (kartItems->mItemInUse.mObjectKind == 0xf) {
        return;
    }
    it_destroyDragItem(&kartItems->mItemInUse);
}

void it_dropDriverItem(KartItems *kartItems) {
    BOOL isMode5;

    isMode5 = gRaceMultiConfig->mMode == 5;
    if ((kartItems->mKart->field7C & 0x400) != 0) {
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
        it_resetDriverItemStatus(kartItems);
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

void sub_20EFEA4(KartItems *kartItems) {
    if ((u32) (kartItems->mKart->mItemEffect - 2) <= 1) {
        return;
    }
    if (gRaceMultiConfig->mMode == 5) {
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

BOOL sub_20EFD84(KartItems *kartItems, s32 itemInfoIndex) {
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
            objectKind = it_sItemConfigs[itemInfoIndex].mObjectKind;
            pool = &it_sItemsets[objectKind];
            pool->mReservedCount--;
            return TRUE;
        }
        StopItemSlot(kartItems);
        SetHeldItem(heldItem, itemInfoIndex);
    } else {
        if (heldItem->mItemInfoIndex == 0x13 && heldItem->mObjectCount == 0) {
            objectKind = it_sItemConfigs[itemInfoIndex].mObjectKind;
            pool = &it_sItemsets[objectKind];
            pool->mReservedCount--;
        }
    }
    it_takeSlotItems(heldItem, 1);
    return heldItem->mItemInfoIndex == 0x13;
}

void sub_20EFD1C(KartItems *kartItems, ItemObject *object) {
    Kart *kart;
    Vec3 *axis;

    kart = kartItems->mKart;
    if ((kart->field48 & 1) != 0) {
        axis = &kart->field15C;
    } else {
        axis = &data_021595d8;
    }
    it_20F98A0(object, &kart->mDrawMatrixPos, axis, &kart->mKartModelsEntry->field40, StructMQRacerEntry_SomeFn_71(kart));
    if ((kart->field48 & 1) != 0) {
        object->mFlags |= 0x40000000;
    }
}

void func_020efc74(KartItems *kartItems, s32 a) {
    ItemPointLinkRef *linkRef;
    Kart *kart;
    Vec3 *kartPos;
    s64 distanceSquared;
    s32 linkByIndex;
    if ((linkByIndex = func_020f4090(a)) != 0) {
        kartItems->field1F0.mLink = (ItemPointLink *) linkByIndex;
        kartItems->field1F0.mNextLinksUsed = 1;
    }
    if ((linkRef = &kartItems->field1F0)->mLink == NULL) {
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
    kartItems->mKart = driver_getById(kartIndex);
    kartItems->mEntryIndex = ((Unk021759c0_000 *) gRaceMultiConfig)->field7C[kartIndex].field0;
    InitItemSlot(kartItems, kartItems);
    it_initSlot(&kartItems->mHeldItem, kartItems);
    InitItemInUse(&kartItems->mItemInUse, kartItems);
    courseMap = (Unk02175620_060 *) gMapData;
    kartItems->field1F0.mLink = courseMap->field60 != 0 ? courseMap->fieldB0 : 0;
    kartItems->field1F0.mNextLinksUsed = 1;
    kartItems->mKinokoBoostStarted = FALSE;
    kartItems->field208 = FALSE;
    kartItems->field20C = FALSE;
}

#pragma thumb off
void StartItemInUseObject(ItemInUse *itemInUse, ItemObject *object) {
    it_itemsetAddItem(&it_sItemsets[object->mKind], object);
    sub_20EFD1C(itemInUse->mKartItems, object);
    object->mFlags &= ~0x1000;
}

// Takes the last object out of the record, starts it and runs its kind's Init; the argument says whether to call
// driver_tryEmitItemUseVoice on the kart.
void StartLastItemInUseObjectAndInit(ItemInUse *itemInUse, s32 callKart) {
    ItemObject *object;
    s32 (*initFunc)(void *, void *);
    void (*advanceFunc)(struct ItemObject *);

    itemInUse->mObjectCount--;
    object = itemInUse->mObjects[itemInUse->mObjectCount];
    initFunc = it_sItemParams[object->mKind].mInit;
    StartItemInUseObject(itemInUse, object);
    if (initFunc(itemInUse, object) == 0) {
        if (itemInUse->mKartItems->field208 != FALSE) {
            object->field78 |= data_021595ac;
            callKart = 0;
        }
    }
    object->mDistanceSquaredAndFlags =
        it_sItemParams[object->mKind].mViewTest(object->fieldD0, object->mRadius << 1, it_sItemParams[object->mKind].field5C,
                                            it_sItemParams[object->mKind].fieldA4, 0x1f);
    if (object->mFlags & 0x400000) {
        sub_20F90BC(object);
    }
    advanceFunc = it_sItemParams[object->mKind].mAdvance;
    if ((object->mFlags & 0x180000) == 0) {
        object->mAdvance = advanceFunc;
    }
    if (callKart != 0) {
        driver_tryEmitItemUseVoice(itemInUse->mKart);
    }
}

// The object must be the last one of the record.
void StartItemInUseObjectAndCountDown(ItemInUse *itemInUse, ItemObject *object) {
    itemInUse->mObjectCount = itemInUse->mObjectCount - 1;
    StartItemInUseObject(itemInUse, object);
}

// Entry 1 of gItemInUseStartTable. (the same one-line form above the other start, advance and remove entries:
// StartItemInUseOneWithOrientation :886 entry 2, StartItemInUseCircle :1233 entry 4, it_deploy_20EF4A0 :946 entry 1,
// it_20EF350 :983 entry 2,  :1056 entry 3, AdvanceItemInUseCircle :1250 entry 4,  :1162 entry
// 3, RemoveItemInUseCircle :1306 entry 4)
void StartItemInUseOne(ItemInUse *itemInUse) {
    ItemInUse *inUseAlias;
    ItemObject *object;
    Vec3 *forwardAxis;
    s32 scaleOffset;

    inUseAlias = itemInUse;
    object = itemInUse->mObjects[0];
    forwardAxis = &itemInUse->mKartOrientation.field18;
    inUseAlias->field90 = *forwardAxis;
    inUseAlias->mBehindDirection.x = -forwardAxis->x;
    inUseAlias->mBehindDirection.y = -forwardAxis->y;
    inUseAlias->mBehindDirection.z = -forwardAxis->z;
    scaleOffset = ((s64) itemInUse->mKartScaleFactorTimesBase.z << 14) >> 12;
    VEC_MultAdd(itemInUse->field78 + scaleOffset, &inUseAlias->mBehindDirection, &itemInUse->mKartDrawMatrixPos,
                &inUseAlias->mBehindPos);
    VEC_MultAdd(((s64) itemInUse->fieldE8 * itemInUse->mKartScaleFactorTimesBase.z) >> 12,
                &itemInUse->mKartOrientation.fieldC, &inUseAlias->mBehindPos, &object->mPos);
}

void StartItemInUseOneWithOrientation(ItemInUse *itemInUse) {
    ItemInUse *inUseAlias;
    ItemObject *object;
    Vec3 *forwardAxis;
    s32 scaleOffset;

    inUseAlias = itemInUse;
    object = itemInUse->mObjects[0];
    forwardAxis = &itemInUse->mKartOrientation.field18;
    inUseAlias->field90 = *forwardAxis;
    inUseAlias->mBehindDirection.x = -forwardAxis->x;
    inUseAlias->mBehindDirection.y = -forwardAxis->y;
    inUseAlias->mBehindDirection.z = -forwardAxis->z;
    scaleOffset = ((s64) itemInUse->mKartScaleFactorTimesBase.z << 14) >> 12;
    VEC_MultAdd(itemInUse->field78 + scaleOffset, &inUseAlias->mBehindDirection, &itemInUse->mKartDrawMatrixPos,
                &inUseAlias->mBehindPos);
    VEC_MultAdd(((s64) itemInUse->fieldE8 * itemInUse->mKartScaleFactorTimesBase.z) >> 12,
                &itemInUse->mKartOrientation.fieldC, &inUseAlias->mBehindPos, &object->mPos);
    object->field94.field0[1] = itemInUse->mKartOrientation.fieldC;
    object->field94.field0[2].x = -inUseAlias->mBehindDirection.x;
    object->field94.field0[2].y = -inUseAlias->mBehindDirection.y;
    object->field94.field0[2].z = -inUseAlias->mBehindDirection.z;
    vec_crossProduct(&object->field94.field0[1], &object->field94.field0[2], &object->field94.field0[0]);
}

void ComputeItemInUseObjectPosition(ItemInUse *itemInUse, Vec3 *objectPos, Vec3 *behindPos) {
    ItemInUse *inUseAlias;
    Vec3 *smoothedDirection;
    Vec3 direction;
    s32 scaleOffset;
    s64 lengthSquared;

    inUseAlias = itemInUse;
    smoothedDirection = &inUseAlias->field90;
    direction = itemInUse->mKartOrientation.field18;
    if (itemInUse->mMovingForward != 0) {
        VEC_MultAdd(0x19a, &itemInUse->mKartMovement, &direction, &direction);
    }
    smoothedDirection->x = ((s64) smoothedDirection->x * 0xccd) >> 12;
    smoothedDirection->y = ((s64) smoothedDirection->y * 0xccd) >> 12;
    smoothedDirection->z = ((s64) smoothedDirection->z * 0xccd) >> 12;
    VEC_MultAdd(0x333, &direction, smoothedDirection, smoothedDirection);
    lengthSquared = (s64) smoothedDirection->x * smoothedDirection->x +
                    (s64) smoothedDirection->y * smoothedDirection->y +
                    (s64) smoothedDirection->z * smoothedDirection->z;
    if (lengthSquared >= 0x10) {
        vec_normalize(smoothedDirection, &direction);
    }
    inUseAlias->mBehindDirection.x = -direction.x;
    inUseAlias->mBehindDirection.y = -direction.y;
    inUseAlias->mBehindDirection.z = -direction.z;
    scaleOffset = ((s64) itemInUse->mKartScaleFactorTimesBase.z << 14) >> 12;
    VEC_MultAdd(itemInUse->field78 + scaleOffset, &inUseAlias->mBehindDirection, &itemInUse->mKartDrawMatrixPos,
                behindPos);
    if (itemInUse->mObjectCount > 1) {
        inUseAlias->fieldE4 += (s32) (((s64) itemInUse->mKartHopHeight * 0x333) >> 12);
        inUseAlias->fieldE4 -= (s32) (((s64) inUseAlias->fieldE4 * 0x266) >> 12);
    } else {
        inUseAlias->fieldE4 += (s32) (((s64) itemInUse->mKartHopHeight * 0xd1f) >> 12);
        inUseAlias->fieldE4 -= (s32) (((s64) inUseAlias->fieldE4 * 0x68f) >> 12);
    }
    VEC_MultAdd(inUseAlias->fieldE4 - itemInUse->mKartHopHeight +
                    (s32) (((s64) itemInUse->fieldE8 * itemInUse->mKartScaleFactorTimesBase.z) >> 12),
                &itemInUse->mKartOrientation.fieldC, behindPos, objectPos);
}

void it_deploy_20EF4A0(ItemInUse *itemInUse) {
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
        if (GrowItemObjectScale(object, it_sItemParams[kind].field70, 0x333) != 0) {
            SetItemObjectScaleByRatios(object, itemInUse->mKartScaleFactorTimesBase.x,
                                       itemInUse->mKartScaleFactorTimesBase.y);
        }
    }
    if (previousScale < 0xccd && object->mScale.z >= 0xccd && itemInUse->mKartIndex == gRaceMultiConfig->mEntryIndex) {
        driver_emitSfx2(&kartItems->mKart->mSoundSource, 0xe7);
    }
    if ((kartItems->mFlags & 0x284) == 0x284 && itemInUse->mObjectKind != 0xf &&
        itemInUse->mObjectStartFramesLeft == 0) {
        StartLastItemInUseObjectAndInit(itemInUse, 1);
    }
    if (itemInUse->field170 != NULL) {
        kartItems->mActiveItem = 0x13;
        entryIndex = kartItems->mEntryIndex;
        if ((u16) (data_0217562a[entryIndex].mBits & ITEM_THROW_FORWARD_BIT) != 0) {
            kartItems->mFlags |= data_021595a0;
        }
        entryIndex = kartItems->mEntryIndex;
        if ((u16) (data_0217562a[entryIndex].mBits & PAD_KEY_DOWN) != 0) {
            kartItems->mFlags |= data_021595a4;
        }
        StartLastItemInUseObjectAndInit(itemInUse, 1);
    }
    kartItems->mFlags |= data_021595a8;
}

void it_20EF350(ItemInUse *itemInUse) {
    ItemInUse *inUseAlias;
    ItemObject *object;
    Vec3 direction;
    s64 t;
    s64 lengthSquared;
    enum { K0 } kind;

    inUseAlias = itemInUse;
    object = itemInUse->mObjects[0];
    it_deploy_20EF4A0(itemInUse);
    if ((object->mFlags & 0x1000) != 0) {
        direction.x = ((s64) inUseAlias->mBehindDirection.x << 13) >> 12;
        direction.y = ((s64) inUseAlias->mBehindDirection.y << 13) >> 12;
        direction.z = ((s64) inUseAlias->mBehindDirection.z << 13) >> 12;
        VEC_Add(&direction, &itemInUse->mKartOrientation.field18, &direction);
        lengthSquared =
            (s64) direction.x * direction.x + (s64) direction.y * direction.y + (s64) direction.z * direction.z;
        if (lengthSquared >= 0x10) {
            vec_normalize(&direction, &direction);
        }
        object->field94.field0[2].x = -direction.x;
        object->field94.field0[2].y = -direction.y;
        object->field94.field0[2].z = -direction.z;
        object->field94.field0[1] = itemInUse->mKartOrientation.fieldC;
        vec_crossProduct(&object->field94.field0[1], &object->field94.field0[2], &object->field94.field0[0]);
    }
    kind = object->mKind;
    if (it_sItemParams[kind].mAdvanceInUse != NULL) {
        it_sItemParams[kind].mAdvanceInUse(itemInUse, object);
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
    forwardAxis = &itemInUse->mKartOrientation.field18;
    itemInUse->field90 = *forwardAxis;
    itemInUse->mBehindDirection.x = -itemInUse->mKartOrientation.field18.x;
    itemInUse->mBehindDirection.y = -forwardAxis->y;
    itemInUse->mBehindDirection.z = -forwardAxis->z;
    scaleOffset = ((s64) itemInUse->mKartScaleFactorTimesBase.z << 14) >> 12;
    VEC_MultAdd(itemInUse->field78 + scaleOffset, &itemInUse->mBehindDirection, &itemInUse->mKartDrawMatrixPos,
                &itemInUse->mBehindPos);
    VEC_MultAdd(((s64) itemInUse->fieldE8 * itemInUse->mKartScaleFactorTimesBase.z) >> 12,
                &itemInUse->mKartOrientation.fieldC, &itemInUse->mBehindPos, objectPos);
    objects[1]->mPos = itemInUse->mObjects[0]->mPos;
    objects[2]->mPos = objects[1]->mPos;
    itemInUse->fieldB4 = itemInUse->mBehindPos;
    itemInUse->fieldC0 = itemInUse->fieldB4;
    itemInUse->fieldCC[0] = 0xee1;
    itemInUse->fieldCC[1] = itemInUse->fieldCC[0];
    itemInUse->fieldCC[2] = itemInUse->fieldCC[1];
    itemInUse->fieldD8 = itemInUse->mKartOrientation.field18;
    itemInUse->field16C = 0;
    for (i = 0; i < 0x10; i++) {
        itemInUse->fieldEC[0][i] = 0;
        itemInUse->fieldEC[1][i] = 0;
    }
    if (itemInUse->mKartIndex == gRaceMultiConfig->mEntryIndex) {
        driver_emitSfx2(&itemInUse->mKartItems->mKart->mSoundSource, 0xe7);
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
    s32 s;
    Vec3 kartVector;
    Vec3 offset;
    Vec3 v58;
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
    kartVector = kartItems->mKart->field1FC;
    objects = itemInUse->mObjects;
    minDistance = itemInUse->field78 + (s32) (((s64) itemInUse->mKartScaleFactorTimesBase.z << 14) >> 12);
    previousPos = &inUseAlias->mBehindPos;
    maxGap = ((s64) itemInUse->mKartScaleFactorTimesBase.z * 0x3000) >> 12;
    behindDirection = &inUseAlias->mBehindDirection;
    scaleLimit = it_sItemParams[object->mKind].field70;
    ComputeItemInUseObjectPosition(itemInUse, &object->mPos, previousPos);
    if (GrowItemObjectScale(object, scaleLimit, 0x19a) != 0) {
        SetItemObjectScaleByRatios(object, itemInUse->mKartScaleFactorTimesBase.x,
                                   itemInUse->mKartScaleFactorTimesBase.y);
    }
    if (objectCount > 1) {
        if (itemInUse->mMovingForward != 0) {
            VEC_Subtract(&inUseAlias->fieldD8, &inUseAlias->mBehindDirection, &v58);
            s = ((s64) itemInUse->mKartVelocityLength * itemInUse->mKartVelocityLength) >> 12;
            v58.x = ((s64) v58.x * s) >> 12;
            v58.y = ((s64) v58.y * s) >> 12;
            v58.z = ((s64) v58.z * s) >> 12;
        }
        inUseAlias->fieldD8 = inUseAlias->mBehindDirection;
        historyIndex = inUseAlias->field16C & 0xf;
        inUseAlias->field16C = inUseAlias->field16C + 1;
        inUseAlias->fieldEC[0][historyIndex] = inUseAlias->fieldE4;
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
            VEC_MultAdd(i * 0x1800, &v58, trailPos, trailPos);
        }
        if (inUseAlias->fieldCC[i] > 0) {
            VEC_MultAdd(inUseAlias->fieldCC[i], &itemInUse->mKartMovement, trailPos, trailPos);
        }
        VEC_Subtract(trailPos, &itemInUse->mKartDrawMatrixPos, &offset);
        if (i > 1) {
            minDistance -= (i - 1) << 13;
        }
        d = minDistance - vec_dotProduct(&offset, behindDirection);
        if (d > 0) {
            VEC_MultAdd(d, behindDirection, trailPos, trailPos);
        }
        d = ((s64) (previousPos->y - trailPos->y) * 0x666) >> 12;
        if (d < 0) {
            trailPos->y = trailPos->y + d;
        }
        delayedHopHeight = inUseAlias->fieldEC[i - 1][(historyIndex - 6) & 0xf];
        if (i == 1) {
            inUseAlias->fieldEC[1][historyIndex] = delayedHopHeight;
        }
        d = delayedHopHeight - itemInUse->mKartHopHeight;
        d = ((s64) d * speedFactor) >> 12;
        VEC_Subtract(trailPos, previousPos, &offset);
        if ((s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z >=
            (s64) maxGap * maxGap) {
            if ((s64) offset.x * offset.x + (s64) offset.y * offset.y + (s64) offset.z * offset.z >= 0x10) {
                vec_normalize(&offset, &offset);
            }
            VEC_MultAdd(maxGap, &offset, previousPos, trailPos);
            if (inUseAlias->fieldCC[i] > 0) {
                inUseAlias->fieldCC[i] -= 0x3d;
            }
        }
        VEC_MultAdd(d + (s32) (((s64) itemInUse->mKartScaleFactorTimesBase.z * 0x4333) >> 12),
                    &itemInUse->mKartOrientation.fieldC, trailPos, &object->mPos);
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
    s32 k;
    s32 m;
    s32 t;
    s32 u;
    s32 i;
    Vec3 *objectPos;
    Vec3 *thirdAxis;
    Vec3 *firstAxis;
    Vec3 *center;
    s32 offsetY;

    i = itemInUse->mCircleAngle >> 4;
    objectCount = itemInUse->mObjectCount;
    radius = itemInUse->mCircleRadius;
    offsetY = ((s64) radius * FX_SinCosTable_[i * 2 + 1]) >> 12;
    offsetX = ((s64) radius * FX_SinCosTable_[i * 2]) >> 12;
    t = -offsetY >> 1;
    u = -offsetX >> 1;
    objects = itemInUse->mObjects;
    thirdAxis = &itemInUse->mKartOrientation.field18;
    firstAxis = &itemInUse->mKartOrientation.field0;
    center = &itemInUse->mCircleCenter;
    k = ((s64) offsetY * 0xddb) >> 12;
    m = ((s64) offsetX * 0xddb) >> 12;
    for (i = 0; i < objectCount; i++) {
        objectPos = &objects[i]->mPos;
        if (itemInUse->mCircleSlots[i] == 0) {
            VEC_MultAdd(offsetY, thirdAxis, center, objectPos);
            VEC_MultAdd(offsetX, firstAxis, objectPos, objectPos);
        } else if (itemInUse->mCircleSlots[i] == 1) {
            VEC_MultAdd(t - m, thirdAxis, center, objectPos);
            VEC_MultAdd(u + k, firstAxis, objectPos, objectPos);
        } else {
            VEC_MultAdd(t + m, thirdAxis, center, objectPos);
            VEC_MultAdd(u - k, firstAxis, objectPos, objectPos);
        }
    }
}

void StartItemInUseCircle(ItemInUse *itemInUse) {
    u16 i;

    itemInUse->mCircleAngle = 0;
    itemInUse->mCircleAngleSpeed = 0x258;
    itemInUse->mCircleRadius = 0;
    itemInUse->field17C = 0;
    for (i = 0; i < 3; i++) {
        itemInUse->mCircleSlots[i] = i;
    }
    VEC_MultAdd(((s64) itemInUse->mKartScaleFactorTimesBase.z * 0x4333) >> 12, &itemInUse->mKartOrientation.fieldC,
                &itemInUse->mKartDrawMatrixPos, &itemInUse->mCircleCenter);
    PlaceItemInUseCircleObjects(itemInUse);
    if (itemInUse->mKartIndex == gRaceMultiConfig->mEntryIndex) {
        driver_emitSfx2(&itemInUse->mKartItems->mKart->mSoundSource, 0xe7);
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
    itemInUse->field17C = itemInUse->field17C + (s32) (((s64) itemInUse->mKartHopHeight * 0x666) >> 12);
    itemInUse->field17C = itemInUse->field17C - (s32) (((s64) itemInUse->field17C * 0x333) >> 12);
    VEC_MultAdd((itemInUse->field17C - itemInUse->mKartHopHeight) +
                    (s32) (((s64) itemInUse->mKartScaleFactorTimesBase.z * 0x4333) >> 12),
                &itemInUse->mKartOrientation.fieldC, &itemInUse->mKartDrawMatrixPos, &itemInUse->mCircleCenter);
    itemInUse->mCircleRadius =
        itemInUse->mCircleRadius +
        (s32) (((s64) ((itemInUse->field78 + (s32) (((s64) itemInUse->mKartScaleFactorTimesBase.z * 0x3000) >> 12)) -
                       itemInUse->mCircleRadius) *
                0x333) >>
               12);
    PlaceItemInUseCircleObjects(itemInUse);
    i = 0;
    kind = itemInUse->mObjectKind;
    scaleLimit = it_sItemParams[kind].field70;
    for (; i < objectCount; i++) {
        object = itemInUse->mObjects[i];
        if (GrowItemObjectScale(object, scaleLimit, 0x19a) != 0) {
            SetItemObjectScaleByRatios(object, itemInUse->mKartScaleFactorTimesBase.x,
                                       itemInUse->mKartScaleFactorTimesBase.y);
        }
    }
    if (itemInUse->mKartIndex == gRaceMultiConfig->mEntryIndex) {
        driver_emitSfx((u32) kartItems->mKart, objectCount + 0xe0);
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

void it_resetDragItem(ItemInUse *itemInUse) {
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
    it_resetDragItem(itemInUse);
}
