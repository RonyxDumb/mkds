#pragma once

#include "types.h"
#include "Main/Item/item_objects_and_race_progress.h"

typedef struct ItemObject ItemObject;
typedef struct ItemFBox ItemFBox;

// One item data record: the bytes passed on, then its kind, message kind and the frame stamp (only set in a delayed
// record).
typedef struct ItemDataRecord {
    /* 00 */ u8 mData[0x14];
    /* 14 */ vu32 mKind;
    /* 18 */ u32 mMessageKind;
    /* 1c */ u32 mRaceUpdateFramesStamp;
} ItemDataRecord;

u8 *CopyItemFBoxData(u8 *cursor, ItemFBox *fbox, void *toData);
void InitItemFBoxFromData(ItemFBox *fbox);
void SetupItemFBoxPooledMapObjects(void);
void StoreItemDataFlagBit(s32 flag, s32 *word);
void LoadItemDataFlagBit(s32 word, s32 *flag);
s32 ComputeItemObjectId(ItemObject *item);
u8 *CopyItemPrevPosOffset(u8 *cursor, Vec3 *position, Vec3 *prevPosition, void *toData);
u8 *CopyItemPointLinkIndex(u8 *cursor, void *pointLink, void *toData);
u8 *CopyItemShiftedByte(u8 *cursor, s32 *valueSlot, void *toData);
u8 *CopyItemObjectData(u8 *cursor, void *object, void *toData);
void AddQueuedItemData(void);
void ProcessDelayedItemData(void);
void QueueItemData(u32 kind, u32 messageKind, void *packet, u8 size);
void DelayItemData(u32 kind, u32 messageKind, s32 frameDifference, void *packet, u32 frameStamp);
u8 *AddItemDataFrameOnly(u32 kind);
u8 *AddItemDataSizedByKind(u32 kind);
u8 *AddItemDataNoItemId(u32 kind);
u8 *AddItemDataItemIdAndParts(u32 kind, u32 lowPart, u32 highPart, u32 itemId);
u8 *AddItemDataItemIdAndKart(u32 kind, u32 kartIndex, u32 itemId);
u8 *AddItemDataItemIdAndBytes(u32 kind, u32 itemId, u32 thirdByte, u32 fourthByte);
void ProcessItemDataMessage(u32 kind, u32 messageKind, u8 *packet, u32 kartIndex);
void DelayItemDataWithFrameStamp(u32 kind, u32 messageKind, u32 frameDifference, void *packet, u32 frameStamp);
void *CopyItemObjectDataAndAdd(void *cursor, void *object, s32 toData);
void SetupItemObjectFromDataWrapper(void *object);

extern Vec3 gItemFBoxRotationAxis;

extern u8 gItemDataBuffer[20];
extern u8 gItemDataQueueLinks[32][2];
extern ItemDataRecord gItemDataQueue[32];
extern ItemDataRecord gItemDataDelayed[32];
extern u8 gItemDataDelayedLinks[32][2];

extern const u16 gItemBombExcludedUntilCourseHitBit;
extern const u8 gItemBombVec3UnitY[12];
extern const ItemInfo gItemInfoKouraGThree;
extern const ItemInfo gItemInfoFBox;
extern const ItemKind gItemKindFBox;
