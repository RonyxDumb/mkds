#pragma once

#include "types.h"

typedef struct ItemObject ItemObject;
typedef struct ItemFBox ItemFBox;

// Element of the two tables gItemDataDelayed and gItemDataQueue: 0x14 bytes of
// bytes passed on followed by three words.
typedef struct ItemDataRecord {
    /* 00 */ u8 mData[0x14];
    /* 14 */ u32 mKind;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mRaceUpdateFramesStamp;
} ItemDataRecord;

extern ItemDataRecord gItemDataDelayed[];

extern ItemDataRecord gItemDataQueue[];

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
