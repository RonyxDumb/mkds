#pragma once

#include "types.h"
#include "Main/Item/kart_items_collision_hits.h"
#include "Main/Item/item_in_use.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Kart/kart_drift.h"

// Message kinds of the item data a Wi-Fi race sends (AddItemData, ProcessItemPoolMessage): the start of an object with
// its kind's data, the start with the generic copy (0x12 bytes), an event of an object (ITEM_EVENT_*; 3 bytes), and the
// kart an object follows (also the selector packets of the Boo, ITEM_TERESA_PACKET_*).
#define ITEM_DATA_MESSAGE_START 0
#define ITEM_DATA_MESSAGE_START_GENERIC 1
#define ITEM_DATA_MESSAGE_EVENT 2
#define ITEM_DATA_MESSAGE_KART 3

// Events of an item object (the low nibble of the event byte of ITEM_DATA_MESSAGE_EVENT): the fade-outs with and
// without the kind's callback, used up and hit by a kart, then the release timer and the release.
#define ITEM_EVENT_FADE_OUT_ENDED 0
#define ITEM_EVENT_FADE_OUT_NO_CALLBACK 1
#define ITEM_EVENT_FADE_OUT_USED_UP 2
#define ITEM_EVENT_FADE_OUT_HIT_BY_KART 3
#define ITEM_EVENT_RELEASE_TIMER 4
#define ITEM_EVENT_RELEASE 5

// Values of KartItems.mSlotState: no roulette, the spin through random items, the final scroll that lands on the
// result.
typedef enum { KART_ITEMS_SLOT_IDLE, KART_ITEMS_SLOT_SPINNING, KART_ITEMS_SLOT_SHOWING_RESULT } KartItemsSlotState;

// Frame counts of the roulette spin (KartItems.mSlotFrames, mSlotFrameCount). The spin cannot end before the minimum;
// the end frame depends on the start: Wi-Fi race, short spin, or normal.
#define KART_ITEMS_SLOT_MIN_SPIN_FRAMES 0x3c
#define KART_ITEMS_SLOT_END_FRAME_WIFI 0x85
#define KART_ITEMS_SLOT_END_FRAME_SHORT 0x65
#define KART_ITEMS_SLOT_END_FRAME_NORMAL 0xd5
#define KART_ITEMS_SLOT_SHORT_SPIN_START_FRAME 0x4d
// Wi-Fi race: while the result from the other machine is awaited the spin frame is wound back from the wait limit to
// the rewind frame; when the result arrives the end frame moves by the frames spent past the wait limit.
#define KART_ITEMS_SLOT_WIFI_WAIT_LIMIT_FRAME 0x6e
#define KART_ITEMS_SLOT_WIFI_WAIT_REWIND_FRAME 0x67
// Length of the final scroll that lands on the result (KartItems.mSlotFinalScrollFrameCount, and its shift = log2).
#define KART_ITEMS_SLOT_FINAL_SCROLL_FRAMES 0x10
#define KART_ITEMS_SLOT_FINAL_SCROLL_SHIFT 4
#define KART_ITEMS_SLOT_SHORT_FINAL_SCROLL_FRAMES 8
#define KART_ITEMS_SLOT_SHORT_FINAL_SCROLL_SHIFT 3

// Copy of ITEM_THROW_FORWARD_BIT in KartItems.mFlags (TryAddKartItemFlags and AdvanceItemInUseOne set it from the input
// word).
#define KART_ITEMS_THROW_FORWARD 0x10
// The down key was held when the item was used (TryAddKartItemFlags and AdvanceItemInUseOne set it).
#define KART_ITEMS_DOWN 0x20
// Set every frame by AdvanceItemInUseOne while a single item is held in use; AddKartItemUseFlags clears it and adds the
// end-use bit.
// Other bits of KartItems.mFlags, as the const words of the same names (gKartItems...Bit) set them; KEY_PRESSED is set
// with KEY_DOWN on the frame the item key goes down, KEY_RELEASED on the frame it comes up.
#define KART_ITEMS_HELD 2
#define KART_ITEMS_START_USE 0x40
#define KART_ITEMS_START_ALLOWED 0x200
#define KART_ITEMS_KEY_DOWN 0x1000
#define KART_ITEMS_KEY_PRESSED 0x2000
#define KART_ITEMS_KEY_RELEASED 0x4000
#define KART_ITEMS_IN_USE_ADVANCED 0x100
// Other bits of KartItems.mFlags, as the const words of the same names (gKartItems...Bit) set them.
#define KART_ITEMS_SLOT 1
#define KART_ITEMS_HELD 2
#define KART_ITEMS_IN_USE 4
#define KART_ITEMS_START_USE 0x40
#define KART_ITEMS_END_USE 0x80
#define KART_ITEMS_START_ALLOWED 0x200
#define KART_ITEMS_KEY_DOWN 0x1000
#define KART_ITEMS_KEY_RELEASED 0x4000
// Free objects (ItemPool.mLimit - mReservedCount) below which UpdateItemPool releases old objects to make room.
#define ITEM_POOL_LOW_FREE_OBJECTS 2

// One item record per kart (the array behind gKartItems, 0x210 bytes each): the item roulette in the first 0x30 bytes,
// the held item at 0x30, the item in use at 0x58, the course reference at 0x1f0, the kart index and the Kart at 0x1f8 /
// 0x1fc and four words of use state at 0x200..0x20c. A bag named after whose item state it is: no single role. Race
// code only.
typedef struct KartItems {
    /* 000 */ s32 mSlotState;
    // Counts up per UpdateItemSlot call; starts at 0x4d when the fifth start argument is non-zero; wound back to 0x67
    // while the mode-5 result is awaited
    /* 004 */ u32 mSlotFrames;
    // The spin stops when mSlotFrames passes it (0x85 in mode 5, 0x65 when the fifth start argument is non-zero, else
    // 0xd5); in mode 5 it is lengthened once when the outside result arrives. Causes of the three values not read.
    /* 008 */ u32 mSlotFrameCount;
    /* 00c */ s32 mSlotShownItem;
    // Idle value 0x13; set by PickItem, never 0x13 while a roulette runs; overwritten by the outside result in mode 5
    /* 010 */ s32 mSlotResult;
    // The item whose effect is still running after the held item was spent (0x13 = none): set by item 14's hook to 0xe,
    // by item 16's object to 0x10, by the use code to the used item when it left an object; cleared by every roulette
    // reset and at respawn; blocks a new roulette; the HUD draws it when nothing is held.
    /* 014 */ s32 mActiveItem;
    // Always the record itself (the roulette functions take a part that points to its owner)
    /* 018 */ struct KartItems *mSelf;
    /* 01c */ BOOL mIsShortSpin;
    /* 020 */ BOOL mResultPending;
    /* 024 */ s32 mIsPeer;
    /* 028 */ u32 mSlotFinalScrollFrameCount;
    /* 02c */ s32 mSlotFinalScrollFrameShift;
    // Record of the held item (HeldItem: item at 0, 0x13 = none, uses left at 8)
    /* 030 */ HeldItem mHeldItem;
    // The item in use. (replaces the three-line comment above mItemInUse)
    // Record of the item in use (ItemInUse: object kind at 0, 0xf = none; item index at 4; use state at 8; Kart at
    // 0x10; three object pointers at 0x14)
    /* 058 */ ItemInUse mItemInUse;
    // Item key and use bits: 0x1000 / 0x2000 / 0x4000 key down / pressed / released, 0x100 the in-use advance,
    // 0x40 start use, 0x80 end use; 0x10 / 0x20 throw-forward and down keys held at use
    /* 1ec */ u16 mFlags;
    /* 1ee */ u8 mUnk_1ee[2];
    /* 1f0 */ ItemPointLinkRef mItemLink;
    /* 1f8 */ u16 mKartIndex;
    /* 1fa */ u8 mUnk_1fa[2];
    /* 1fc */ Kart *mKart;
    /* 200 */ s32 mEntryIndex;
    /* 204 */ BOOL mKinokoBoostStarted;
    /* 208 */ BOOL mTargetedByKouraR;
    /* 20c */ BOOL mItemUseFlagsBlocked;
} KartItems;
extern struct ItemKind *gItemKinds;

static inline KartItems *GetKartItems(u16 kartIndex) {
    return &gKartItems[kartIndex];
}

void InitItemInUse(ItemInUse *itemInUse, KartItems *kartItems);
void ResetItemInUse(ItemInUse *itemInUse);
void RemoveItemInUseCircle(ItemInUse *itemInUse, s32 objectIndex, ItemObject *object);
void AdvanceItemInUseCircle(ItemInUse *itemInUse);
void StartItemInUseCircle(ItemInUse *itemInUse);
void PlaceItemInUseCircleObjects(ItemInUse *itemInUse);
void RemoveItemInUseTrail(ItemInUse *itemInUse, s32 objectIndex, ItemObject *object);
void AdvanceItemInUseTrail(ItemInUse *itemInUse);
void StartItemInUseTrail(ItemInUse *itemInUse);
void RemoveItemInUseOne(ItemInUse *itemInUse, s32 index, ItemObject *object);
void AdvanceItemInUseOneWithOrientation(ItemInUse *itemInUse);
void AdvanceItemInUseOne(ItemInUse *itemInUse);
void ComputeItemInUseObjectPosition(ItemInUse *itemInUse, Vec3 *objectPos, Vec3 *behindPos);
void StartItemInUseOneWithOrientation(ItemInUse *itemInUse);
void StartItemInUseOne(ItemInUse *itemInUse);
void StartItemInUseObjectAndCountDown(ItemInUse *itemInUse, ItemObject *object);
void StartLastItemInUseObjectAndInit(ItemInUse *itemInUse, s32 callKart);
void StartItemInUseObject(ItemInUse *itemInUse, ItemObject *object);
void InitKartItems(KartItems *kartItems, u16 kartIndex);
void SetKartItemLinkFromHitValue(KartItems *kartItems, u16 hitValue);
void CopyKartPlacementToItemObject(KartItems *kartItems, ItemObject *object);
BOOL SetKartItemsHeldItemByInfoIndex(KartItems *kartItems, s32 itemInfoIndex);
void StartKartItemInUseOneCountdown(KartItems *kartItems);
void StartKartItemObjectCountdowns(KartItems *kartItems);
void ReleaseKartItems(KartItems *kartItems);
void StopRunningKartItemSlot(KartItems *kartItems);
BOOL TryAddKartItemFlags(KartItems *kartItems);
// Builds the pool of one kind: allocates the pointer array and every object, and runs InitItemObject for each.
void CreateItemPool(ItemPool *pool, s32 kind, s32 *objectIdCounter);
// Releases the object at index 0 of mObjects (not necessarily the oldest: the array is reordered); FALSE when none is
// active.
BOOL TryReleaseFirstItemObject(ItemPool *tab);
// Runs UpdateItemObject for every active object (mode 5: some get several sub-steps). When mLimit is above 1 and
// mLimit - mReservedCount is below 2 it first calls StartItemObjectReleaseIfOldResting on the first object or sorts
// with OrderItemPoolObjectsForRelease.
void UpdateItemPool(ItemPool *pool);
void OrderItemPoolObjectsForRelease(ItemObject **objects, s32 pairIndex, s32 endIndex, s32 step);
void ProcessItemPoolMessage(ItemPool *pool, s32 messageKind, s32 frameDifference, u8 *packet, s32 frameStamp);
BOOL SetItemObjectKartFromPacket(ItemPool *pool, u8 *packet);
BOOL ApplyItemObjectEventById(ItemPool *pool, s32 eventByte, s32 objectId);
void StartItemObjectFromData(ItemPool *tab, s32 frameDifference, void *data, s32 useGenericCopy);
void RoundTripItemObjectData(ItemObject *object);
// Draws every taken object, including those only held by a kart, with the kind's draw callback or the default.
void DrawItemPool(ItemPool *tab, void *viewAxis);
void AddRestingItemPoolObject(ItemPool *tab, ItemObject *object);
// Starts an object taken now or earlier and held by a kart: swaps it into the active part of mObjects and counts it.
void StartItemObject(ItemPool *tab, ItemObject *object);
// Hands an object back to its pool behind the active and taken parts and counts it out; what the object holds is
// freed by ReleaseItemObject.
void ReleaseItemPoolObject(ItemPool *tab, ItemObject *object);
void TakeItemPoolObjects(ItemPool *pool, s32 count, ItemObject **out, u16 kartIndex, Vec3 *pos);

extern const u16 gItemInUseDownBit;
extern const u16 gKartItemsStartAllowedBit;
extern const u16 gKartItemsKeyReleasedBit;
extern const u16 gKartItemsKeyDownBit;
extern const u16 gKartItemsDownBit;
extern const u16 gKartItemsThrowForwardBit;
extern const u16 gKartItemsSlotBit;
extern const u32 gItemCollisionBitOrder[13];
extern const u16 gKartItemsInUseBit;
extern const Vec3 gKartItemsVec3UnitY;
extern const u16 gKartItemsStartUseBit;
extern const u16 gItemObjectKouraRTargetedBit;
extern const u16 gKartItemsHeldBit;
extern const u16 gKartItemsEndUseBit;
extern const u16 gItemInUseAdvancedBit;
extern const u16 gItemInUseThrowForwardBit;
