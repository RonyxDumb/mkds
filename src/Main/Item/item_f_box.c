#include "Main/Item/item_f_box.h"
#include "Main/Net/slot_result_pending.h"
#include "Main/Item/item_data_slots_update.h"
#include "Main/Item/item_object.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "vector_math.h"
#include "Main/Item/item_pool.h"
#include "Main/Item/held_item.h"
#include "Main/Item/dram_box.h"
#include "matrix_3x3_basic.h"
#include "cpu_copy_fill.h"
#include "Main/Item/item_slot_tables.h"
#include "Main/Item/pooled_item_box_init.h"
#include "Main/Sound/sound_start.h"
#include "Main/Race/race.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Item/item_object_bouncing.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/MapObjects/view_frustum.h"
#include "Main/Item/item_f_box_park.h"
#include "Main/Save/ghost_record_file.h"

const u16 gItemBombExcludedUntilCourseHitBit = ITEM_OWNER_EXCLUDED_UNTIL_COURSE_HIT;
const u8 gItemBombVec3UnitY[12] = {0, 0, 0, 0, 0, 0x10, 0, 0, 0, 0, 0, 0};
const ItemInfo gItemInfoFBox = {1, 1, 7, 1, 0, 2, NULL};
const ItemInfo gItemInfoKouraGThree = {1, 0, 0, 3, 0, 4, NULL};
const ItemKind gItemKindFBox = {0x144,
                                3,
                                0x20,
                                -1,
                                -1,
                                SetupItemFBoxPooledMapObjects,
                                (void (*)(void *)) ResetItemFBox,
                                (void (*)(void *)) StartItemFBox,
                                (void (*)(void *, void *)) AdvanceItemFBoxInUse,
                                (s32(*)(void *, void *)) InitItemFBox,
                                (void (*)(ItemObject *)) AdvanceItemFBox,
                                NULL,
                                (s32(*)(Vec3 *, s32, s32, s32, u16)) ComputeDistanceViewTest,
                                (s32(*)(void *)) ItemFBoxFadeOutCallback,
                                (void (*)(void *)) SetupItemFBoxAfterLaunch,
                                (void (*)(void *)) ParkItemFBoxMapObject,
                                1,
                                1,
                                (void *(*) (void *, void *, s32)) CopyItemFBoxData,
                                0,
                                (void (*)(void *)) InitItemFBoxFromData,
                                0,
                                NULL,
                                0x4b0000,
                                2,
                                0x4800,
                                0x4800,
                                0x4000,
                                0x1000,
                                0x2800,
                                0x7b,
                                0x52,
                                1,
                                1,
                                1,
                                {0, 0, 0, 0},
                                1,
                                1,
                                0xfa,
                                0xfb,
                                1,
                                0};

Vec3 gItemFBoxRotationAxis = {0x93d, 0x93d, 0x93d};
u8 gItemDataDelayedFreeHead[4];
u8 gItemDataQueueFreeHead[4];
u8 gItemDataQueueUsedHead[4];
u8 gItemDataDelayedUsedHead[4];
u8 gItemDataBuffer[20];
u8 gItemDataQueueLinks[32][2];
ItemDataRecord gItemDataQueue[32];
ItemDataRecord gItemDataDelayed[32];
u8 gItemDataDelayedLinks[32][2];

#pragma thumb off

u8 *CopyItemFBoxData(u8 *cursor, ItemFBox *fbox, void *toData) {
    u8 *nextCursor;

    if (fbox != NULL && toData != NULL) {
        StoreItemDataFlagBit(fbox->mThrownForward, &fbox->mBouncingItemObject.mItemObject.mVelocity.y);
    }
    nextCursor = CopyItemObjectData(cursor, fbox, toData);
    if (fbox != NULL && toData == NULL) {
        LoadItemDataFlagBit(fbox->mBouncingItemObject.mItemObject.mVelocity.y, &fbox->mThrownForward);
    }
    if (fbox != NULL && toData != NULL) {
        return AddItemDataSizedByKind(fbox->mBouncingItemObject.mItemObject.mKind);
    }
    return nextCursor;
}

void InitItemFBoxFromData(ItemFBox *fbox) {
    SetupItemObjectFromData(&fbox->mBouncingItemObject.mItemObject);
    StartItemObjectBouncing(&fbox->mBouncingItemObject, 0);
    if ((fbox->mBouncingItemObject.mItemObject.mFlags & ITEM_OBJECT_FLAG_FROM_DATA) == 0) {
        return;
    }
    if (fbox->mThrownForward == 0) {
        return;
    }
    StartSound(&fbox->mBouncingItemObject.mItemObject.mSoundSource, 0xda, 0x7f, 0);
}

#pragma thumb on

void SetupItemFBoxPooledMapObjects(void) {
    Vec3 axis;
    ItemPool *pool;
    ItemFBox *fbox;
    ItemObject **objectCursor;
    s32 objectCount;
    s32 index;

    if (gItemInfos[ITEM_INFO_F_BOX].mEnabled == FALSE) {
        return;
    }
    axis = gItemFBoxRotationAxis;
    MTX_RotAxis33(&gItemFBoxRotation, &axis, 0xb50, 0xb50);
    pool = &gItemPools[7];
    objectCursor = pool->mObjects;
    objectCount = pool->mObjectCount;
    for (index = 0; index < objectCount; index++) {
        fbox = (ItemFBox *) objectCursor[0];
        fbox->mPooledMapObject = (ItemBox *) AllocPooledMapObject();
        fbox->mPooledMapObject->mPositionSource = &fbox->mBouncingItemObject.mItemObject.mPos;
        objectCursor++;
    }
    pool->mDrawnByMapObjects = 1;
}

#pragma thumb off

void StoreItemDataFlagBit(s32 flag, s32 *word) {
    if (flag != 0) {
        *word |= 0x200;
    } else {
        *word &= ~0x200;
    }
}

void LoadItemDataFlagBit(s32 word, s32 *flag) {
    if (word & 0x200) {
        *flag = 1;
    } else {
        *flag = 0;
    }
}

s32 ComputeItemObjectId(ItemObject *item) {
    return (s16) (((s16) (u16) (item->mOwnerKartIndexAndFlags & ~ITEM_OWNER_FLAGS_MASK) << 4) | item->mPoolIndex);
}

static inline u8 *CopyItemShiftedByteInline(u8 *cursor, volatile s32 *value, void *toData, s32 shift) {
    if (toData != NULL) {
        *cursor = *value >> shift;
    } else {
        *value = *(s8 *) cursor << shift;
    }
    return cursor + 1;
}

u8 *CopyItemPrevPosOffset(u8 *cursor, Vec3 *position, Vec3 *prevPosition, void *toData) {
    volatile s32 offset[3];

    if (prevPosition != NULL) {
        if (toData != NULL) {
            VEC_Subtract(prevPosition, position, (Vec3 *) offset);
        }
        cursor = CopyItemShiftedByteInline(cursor, &offset[0], toData, 10);
        cursor = CopyItemShiftedByteInline(cursor, &offset[1], toData, 9);
        cursor = CopyItemShiftedByteInline(cursor, &offset[2], toData, 10);
        if (toData == NULL) {
            VEC_Add((Vec3 *) offset, position, prevPosition);
        }
    } else {
        cursor++;
        cursor = (u8 *) cursor + 1;
        cursor++;
    }
    return cursor;
}

u8 *CopyItemPointLinkIndex(u8 *cursor, void *pointLink, void *toData) {
    volatile u8 pointLinkIndex;

    if (pointLink != NULL) {
        if (toData != NULL) {
            pointLinkIndex = GetItemPointLinkIndex(pointLink);
        }
        if (toData != NULL) {
            *(u8 *) cursor = pointLinkIndex;
        } else {
            pointLinkIndex = *(u8 *) cursor;
        }
        cursor++;
        if (toData == NULL) {
            SetItemPointLinkRefFromIndex(pointLinkIndex, pointLink);
        }
    } else {
        cursor++;
    }
    return cursor;
}

u8 *CopyItemShiftedByte(u8 *cursor, s32 *valueSlot, void *toData) {
    volatile s32 value;

    if (valueSlot != NULL) {
        if (toData != NULL) {
            value = *valueSlot;
        }
        if (toData != NULL) {
            *(u8 *) cursor = value >> 9;
        } else {
            value = *(s8 *) cursor << 9;
        }
        cursor++;
        if (toData == NULL) {
            *valueSlot = value;
        }
    } else {
        cursor++;
    }
    return cursor;
}

static inline u8 *CopyItemIdByte(u8 *cursor, s16 *valueSlot, void *toData) {
    volatile u8 byteValue;
    u8 *nextCursor;

    if (valueSlot != NULL) {
        if (toData != NULL) {
            byteValue = *valueSlot;
        }
        if (toData != NULL) {
            *cursor = byteValue;
        } else {
            byteValue = *cursor;
        }
        nextCursor = cursor + 1;
        if (toData == NULL) {
            *valueSlot = byteValue;
        }
        return nextCursor;
    }
    return cursor + 1;
}

static inline u8 *CopyItemFlagsHalfword(u8 *cursor, u32 *valueSlot, void *toData) {
    volatile u16 halfword;

    if (valueSlot != NULL) {
        if (toData != NULL) {
            halfword = *valueSlot >> 12;
        }
        if (toData != NULL) {
            *(u16 *) cursor = halfword;
        } else {
            halfword = *(u16 *) cursor;
        }
        if (toData == NULL) {
            *valueSlot = TO_FIXED12(halfword);
        }
        return cursor + 2;
    }
    return cursor + 2;
}

static inline u8 *CopyItemPosHalfword(u8 *cursor, s32 *valueSlot, void *toData) {
    if (valueSlot != NULL) {
        if (toData != NULL) {
            *(s16 *) cursor = *valueSlot >> 9;
        } else {
            *valueSlot = *(s16 *) cursor << 9;
        }
    }
    return cursor + 2;
}

static inline u8 *CopyItemVelocityByte(u8 *cursor, s32 *valueSlot, void *toData, s32 shift) {
    if (valueSlot != NULL) {
        if (toData != NULL) {
            *cursor = *valueSlot >> shift;
        } else {
            *valueSlot = *(s8 *) cursor << shift;
        }
    }
    return cursor + 1;
}

u8 *CopyItemObjectData(u8 *cursor, void *object, void *toData) {
    ItemObject *item;
    u16 *ownerKartIndexAndFlags;

    item = object;

    if (object != NULL) {
        if (toData != NULL) {
            cursor = gItemDataBuffer;
        }
        cursor++;
    }
    cursor = CopyItemIdByte(cursor, object != NULL ? &item->mId : 0, toData);
    cursor = CopyItemFlagsHalfword(cursor, object != NULL ? &item->mFlags : 0, toData);
    cursor = CopyItemPosHalfword(
        cursor, (object != NULL ? &item->mPos : 0) != NULL ? &(object != NULL ? &item->mPos : 0)->x : 0, toData);
    cursor = CopyItemPosHalfword(
        cursor, (object != NULL ? &item->mPos : 0) != NULL ? &(object != NULL ? &item->mPos : 0)->y : 0, toData);
    cursor = CopyItemPosHalfword(
        cursor, (object != NULL ? &item->mPos : 0) != NULL ? &(object != NULL ? &item->mPos : 0)->z : 0, toData);
    cursor =
        CopyItemPrevPosOffset(cursor, object != NULL ? &item->mPos : 0, object != NULL ? &item->mPrevPos : 0, toData);
    cursor = CopyItemVelocityByte(
        cursor, (object != NULL ? &item->mVelocity : 0) != NULL ? &(object != NULL ? &item->mVelocity : 0)->x : 0,
        toData, 10);
    cursor = CopyItemVelocityByte(
        cursor, (object != NULL ? &item->mVelocity : 0) != NULL ? &(object != NULL ? &item->mVelocity : 0)->y : 0,
        toData, 9);
    cursor = CopyItemVelocityByte(
        cursor, (object != NULL ? &item->mVelocity : 0) != NULL ? &(object != NULL ? &item->mVelocity : 0)->z : 0,
        toData, 10);
    ownerKartIndexAndFlags = object != NULL ? &item->mOwnerKartIndexAndFlags : 0;
    if (ownerKartIndexAndFlags != NULL) {
        if (toData != NULL) {
            *(u16 *) cursor = *ownerKartIndexAndFlags;
        } else {
            *ownerKartIndexAndFlags = *(u16 *) cursor;
        }
    }
    return cursor + 2;
}

void AddQueuedItemData(void) {
    u32 index;
    s32 available;
    u32 nextIndex;
    ItemDataRecord *record;

    index = gItemDataQueueUsedHead[0];
    if (index == 0xff) {
        return;
    }
    do {
        available = gWiFiRaceSync->mUnusedItemDataBytes;
        nextIndex = gItemDataQueueLinks[index][0];
        if (available < gItemDataQueueLinks[index][1]) {
            return;
        }
        if (IsAnyItemDataSlotFree() == FALSE) {
            return;
        }
        gItemDataQueueUsedHead[0] = nextIndex;
        gItemDataQueueLinks[index][0] = gItemDataQueueFreeHead[0];
        gItemDataQueueFreeHead[0] = index;
        record = &gItemDataQueue[index];
        AddItemData(record->mKind, record->mMessageKind, record, gItemDataQueueLinks[index][1]);
        index = nextIndex;
    } while (nextIndex != 0xff);
}

void ProcessDelayedItemData(void) {
    u32 raceUpdateFrames;
    u32 index;
    u32 previousIndex;
    u32 nextIndex;
    u32 countdown;
    u32 freeHead;
    ItemDataRecord *record;

    raceUpdateFrames = GetRaceUpdateFrames();
    index = gItemDataDelayedUsedHead[0];
    previousIndex = 0xff;
    while (index != 0xff) {
        countdown = gItemDataDelayedLinks[index][1];
        nextIndex = gItemDataDelayedLinks[index][0];
        gItemDataDelayedLinks[index][1]--;
        if (countdown == 0) {
            freeHead = gItemDataDelayedFreeHead[0];
            gItemDataDelayedLinks[index][0] = freeHead;
            gItemDataDelayedFreeHead[0] = index;
            if (previousIndex == 0xff) {
                gItemDataDelayedUsedHead[0] = nextIndex;
            } else {
                gItemDataDelayedLinks[previousIndex][0] = nextIndex;
            }
            record = &gItemDataDelayed[index];
            if (record->mRaceUpdateFramesStamp == 0 || (record->mRaceUpdateFramesStamp + 0x100) >= raceUpdateFrames) {
                u32 kind = record->mKind;
                ProcessItemPoolMessage(gItemPools + kind, record->mMessageKind, 0, (u8 *) record,
                                       record->mRaceUpdateFramesStamp);
            }
        } else {
            previousIndex = index;
        }
        index = nextIndex;
    }
}

// Keeps a packet for AddQueuedItemData when the sync has no free slot.
void QueueItemData(u32 kind, u32 messageKind, void *packet, u8 size) {
    u32 index;
    ItemDataRecord *record;

    index = gItemDataQueueFreeHead[0];
    if (index == 0xff) {
        return;
    }
    record = &gItemDataQueue[index];
    record->mKind = kind;
    record->mMessageKind = messageKind;
    MI_CpuCopy8(packet, record, size);
    gItemDataQueueFreeHead[0] = gItemDataQueueLinks[index][0];
    if (gItemDataQueueUsedHead[0] == 0xff) {
        gItemDataQueueUsedHead[0] = index;
    } else {
        u32 walkIndex;
        u8 nextIndex;

        walkIndex = gItemDataQueueUsedHead[0];
        nextIndex = gItemDataQueueLinks[walkIndex][0];
        while (nextIndex != 0xff) {
            walkIndex = nextIndex;
            nextIndex = gItemDataQueueLinks[walkIndex][0];
        }
        gItemDataQueueLinks[walkIndex][0] = index;
    }
    gItemDataQueueLinks[index][0] = 0xff;
    gItemDataQueueLinks[index][1] = size;
}

// Keeps a packet that arrived early; ProcessDelayedItemData passes it on when its countdown ends.
void DelayItemData(u32 kind, u32 messageKind, s32 frameDifference, void *packet, u32 frameStamp) {
    u32 index;
    ItemDataRecord *record;

    index = gItemDataDelayedFreeHead[0];
    if (index == 0xff) {
        return;
    }
    record = &gItemDataDelayed[index];
    record->mKind = kind;
    record->mMessageKind = messageKind;
    record->mRaceUpdateFramesStamp = frameStamp;
    MI_CpuCopy8(packet, record, sizeof(record->mData));
    gItemDataDelayedFreeHead[0] = gItemDataDelayedLinks[index][0];
    gItemDataDelayedLinks[index][0] = gItemDataDelayedUsedHead[0];
    if (frameStamp != 0) {
        gItemDataDelayedLinks[index][1] = 4;
    } else {
        gItemDataDelayedLinks[index][1] = -frameDifference;
    }
    gItemDataDelayedUsedHead[0] = index;
}

u8 *AddItemDataFrameOnly(u32 kind) {
    s32 available;

    gItemDataBuffer[0] = GetRaceUpdateFrames();
    available = gWiFiRaceSync->mUnusedItemDataBytes;
    if (available >= 1 && IsAnyItemDataSlotFree() != FALSE) {
        AddItemData(kind, ITEM_DATA_MESSAGE_START, gItemDataBuffer, 1);
    } else {
        QueueItemData(kind, ITEM_DATA_MESSAGE_START, gItemDataBuffer, 1);
    }
    return gItemDataBuffer;
}

u8 *AddItemDataSizedByKind(u32 kind) {
    u32 dataSize;
    s32 available;

    dataSize = gItemKinds[kind].mDataSize & 0xff;
    gItemDataBuffer[0] = GetRaceUpdateFrames();
    available = gWiFiRaceSync->mUnusedItemDataBytes;
    if (available >= (u8) (dataSize + 1) && IsAnyItemDataSlotFree() != FALSE) {
        AddItemData(kind, ITEM_DATA_MESSAGE_START, gItemDataBuffer, dataSize + 1);
    } else {
        QueueItemData(kind, ITEM_DATA_MESSAGE_START, gItemDataBuffer, dataSize + 1);
    }
    return gItemDataBuffer;
}

u8 *AddItemDataNoItemId(u32 kind) {
    s32 available;

    gItemDataBuffer[1] = 0xff;
    gItemDataBuffer[0] = GetRaceUpdateFrames();
    available = gWiFiRaceSync->mUnusedItemDataBytes;
    if (available >= 2 && IsAnyItemDataSlotFree() != FALSE) {
        AddItemData(kind, ITEM_DATA_MESSAGE_START, gItemDataBuffer, 2);
    } else {
        QueueItemData(kind, ITEM_DATA_MESSAGE_START, gItemDataBuffer, 2);
    }
    return gItemDataBuffer;
}

u8 *AddItemDataItemIdAndParts(u32 kind, u32 lowPart, u32 highPart, u32 itemId) {
    s32 available;

    gItemDataBuffer[1] = itemId;
    gItemDataBuffer[2] = lowPart | (highPart << 4);
    gItemDataBuffer[0] = GetRaceUpdateFrames();
    available = gWiFiRaceSync->mUnusedItemDataBytes;
    if (available >= 3 && IsAnyItemDataSlotFree() != FALSE) {
        AddItemData(kind, ITEM_DATA_MESSAGE_EVENT, gItemDataBuffer, 3);
    } else {
        QueueItemData(kind, ITEM_DATA_MESSAGE_EVENT, gItemDataBuffer, 3);
    }
    return gItemDataBuffer;
}

u8 *AddItemDataItemIdAndKart(u32 kind, u32 kartIndex, u32 itemId) {
    s32 available;

    gItemDataBuffer[1] = itemId;
    gItemDataBuffer[2] = kartIndex;
    gItemDataBuffer[0] = GetRaceUpdateFrames();
    available = gWiFiRaceSync->mUnusedItemDataBytes;
    if (available >= 3 && IsAnyItemDataSlotFree() != FALSE) {
        AddItemData(kind, ITEM_DATA_MESSAGE_KART, gItemDataBuffer, 3);
    } else {
        QueueItemData(kind, ITEM_DATA_MESSAGE_KART, gItemDataBuffer, 3);
    }
    return gItemDataBuffer;
}

u8 *AddItemDataItemIdAndBytes(u32 kind, u32 itemId, u32 thirdByte, u32 fourthByte) {
    s32 available;

    gItemDataBuffer[1] = itemId;
    gItemDataBuffer[2] = thirdByte;
    gItemDataBuffer[3] = fourthByte;
    gItemDataBuffer[0] = GetRaceUpdateFrames();
    available = gWiFiRaceSync->mUnusedItemDataBytes;
    if (available >= 4 && IsAnyItemDataSlotFree() != FALSE) {
        AddItemData(kind, ITEM_DATA_MESSAGE_KART, gItemDataBuffer, 4);
    } else {
        QueueItemData(kind, ITEM_DATA_MESSAGE_KART, gItemDataBuffer, 4);
    }
    return gItemDataBuffer;
}

void ProcessItemDataMessage(u32 kind, u32 messageKind, u8 *packet, u32 kartIndex) {
    s8 frameDifference;

    frameDifference = (u8) GetRaceUpdateFrames() - packet[0];
    if (frameDifference >= 0) {
        ProcessItemPoolMessage(gItemPools + kind, messageKind, frameDifference, packet, 0);
    } else {
        DelayItemData(kind, messageKind, frameDifference, packet, 0);
    }
    if (kind != 0xb) {
        return;
    }
    if (messageKind != 0) {
        return;
    }
    if (packet[1] == 0xff) {
        return;
    }
    SetActiveItem(GetKartItems(kartIndex), 0x10);
}

void DelayItemDataWithFrameStamp(u32 kind, u32 messageKind, u32 frameDifference, void *packet, u32 frameStamp) {
    u32 storedFrameStamp;

    storedFrameStamp = frameStamp;
    if (storedFrameStamp == 0) {
        storedFrameStamp = GetRaceUpdateFrames();
    }
    DelayItemData(kind, messageKind, frameDifference, packet, storedFrameStamp);
}

void *CopyItemObjectDataAndAdd(void *cursor, void *object, s32 toData) {
    ItemObject *item;
    u8 *nextCursor;
    s32 kind;
    s32 available;

    item = object;
    nextCursor = CopyItemObjectData(cursor, object, (void *) toData);
    if (object == NULL) {
        return nextCursor;
    }
    if (toData == 0) {
        return nextCursor;
    }
    kind = item->mKind;
    gItemDataBuffer[0] = GetRaceUpdateFrames();
    available = gWiFiRaceSync->mUnusedItemDataBytes;
    if (available >= 0x12 && IsAnyItemDataSlotFree() != FALSE) {
        AddItemData(kind, ITEM_DATA_MESSAGE_START_GENERIC, gItemDataBuffer, 0x12);
    } else {
        QueueItemData(kind, ITEM_DATA_MESSAGE_START_GENERIC, gItemDataBuffer, 0x12);
    }
    return gItemDataBuffer;
}

void SetupItemObjectFromDataWrapper(void *object) {
    SetupItemObjectFromData(object);
}
