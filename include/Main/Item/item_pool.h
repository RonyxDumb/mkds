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
// Wi-Fi race: while the result from the other machine is awaited, the spin frame is set back to the rewind frame each
// time it passes the wait limit; when the result arrives the end frame changes by mSlotFrames - (wait limit + 1), so it
// moves earlier when the limit was not yet reached.
#define KART_ITEMS_SLOT_WIFI_WAIT_LIMIT_FRAME 0x6e
#define KART_ITEMS_SLOT_WIFI_WAIT_REWIND_FRAME 0x67
// Length of the final scroll that lands on the result (KartItems.mSlotFinalScrollFrameCount, and its shift = log2).
#define KART_ITEMS_SLOT_FINAL_SCROLL_FRAMES 0x10
#define KART_ITEMS_SLOT_FINAL_SCROLL_SHIFT 4
#define KART_ITEMS_SLOT_SHORT_FINAL_SCROLL_FRAMES 8
#define KART_ITEMS_SLOT_SHORT_FINAL_SCROLL_SHIFT 3

// Set when PAD_KEY_DIRECTION_UP is held (TryAddKartItemFlags; AdvanceItemInUseOne when mIsActiveItem is set; the input
// word).
#define KART_ITEMS_THROW_FORWARD 0x10
// The down key (PAD_KEY_DIRECTION_DOWN) was held on the frame the item is used; the low byte of mFlags is cleared every
// frame. Set by TryAddKartItemFlags (race started, kart normal, no heading swing) and by AdvanceItemInUseOne when
// mIsActiveItem.
#define KART_ITEMS_DOWN 0x20
// Other bits of KartItems.mFlags; the gKartItems...Bit words set most of them. KEY_PRESSED is set with KEY_DOWN on the
// frame the item key goes down, KEY_RELEASED on the frame it comes up.
#define KART_ITEMS_SLOT 1
#define KART_ITEMS_HELD 2
#define KART_ITEMS_IN_USE 4
#define KART_ITEMS_START_USE 0x40
#define KART_ITEMS_END_USE 0x80
// Set by AdvanceItemInUseOne on every call; AddKartItemUseFlags clears it and, when the mode is MODE_WIFI or the item
// key is not down and TryAddKartItemFlags succeeds, adds KART_ITEMS_END_USE.
#define KART_ITEMS_IN_USE_ADVANCED 0x100
#define KART_ITEMS_START_ALLOWED 0x200
#define KART_ITEMS_KEY_DOWN 0x1000
#define KART_ITEMS_KEY_PRESSED 0x2000
#define KART_ITEMS_KEY_RELEASED 0x4000
// Below this many free objects (ItemPool.mLimit - mReservedCount), a pool with mLimit above 1 makes room in
// UpdateItemPool: it starts the release of an old resting object or reorders the objects for release.
#define ITEM_POOL_LOW_FREE_OBJECTS 2

// One item record per kart (gKartItems): the item roulette, the held item, the item in use and the kart.
typedef struct KartItems {
    /* 000 */ s32 mSlotState;
    // Counts up per UpdateItemSlot call in the spin and again in the final scroll (set to 0 between them); a short spin
    // (not in a Wi-Fi race) starts at KART_ITEMS_SLOT_SHORT_SPIN_START_FRAME; in a Wi-Fi race, while the result is
    // awaited, it is set back to KART_ITEMS_SLOT_WIFI_WAIT_REWIND_FRAME each time it passes
    // KART_ITEMS_SLOT_WIFI_WAIT_LIMIT_FRAME.
    /* 004 */ u32 mSlotFrames;
    // The spin ends when mSlotFrames passes it: KART_ITEMS_SLOT_END_FRAME_WIFI in a Wi-Fi race, else
    // KART_ITEMS_SLOT_END_FRAME_SHORT for a short spin or KART_ITEMS_SLOT_END_FRAME_NORMAL. Outside a Wi-Fi race and
    // without a short spin it can also end earlier, once past KART_ITEMS_SLOT_MIN_SPIN_FRAMES, while the start-allowed,
    // start-use and roulette bits of mFlags are all set. In a Wi-Fi race it is moved by mSlotFrames -
    // (KART_ITEMS_SLOT_WIFI_WAIT_LIMIT_FRAME + 1) when the result arrives (zero or less, so never later).
    /* 008 */ u32 mSlotFrameCount;
    /* 00c */ s32 mSlotShownItem;
    // ITEM_INFO_NONE while idle and while a Wi-Fi result is awaited (StartItemSlotResultPending); otherwise the item
    // PickItem chose; in a Wi-Fi race the result that arrives overwrites it.
    /* 010 */ s32 mSlotResult;
    // The item whose effect keeps running after the held item was spent (ITEM_INFO_NONE = none). Set to
    // ITEM_INFO_KILLER by StartItemKiller, to ITEM_INFO_TERESA by InitItemTeresa, InitItemTeresaFromData and the Teresa
    // data message, and to ItemInUse.mItemInfoIndex by StartItemInUse when a use hook marked mIsActiveItem. Cleared
    // when the roulette ends or stops, when the in-use item is released or its objects start counting down, by
    // ReleaseKartItems (not in a Wi-Fi race), ResetKartActiveItemAfterKiller and SetKartItemsHeldItemByInfoIndex.
    // Blocks StartItemSlot; the HUD draws it when nothing is held.
    /* 014 */ s32 mActiveItem;
    // Always the record itself (the roulette functions take a part that points to its owner)
    /* 018 */ struct KartItems *mSelf;
    /* 01c */ BOOL mIsShortSpin;
    /* 020 */ BOOL mResultPending;
    /* 024 */ s32 mIsPeer;
    /* 028 */ u32 mSlotFinalScrollFrameCount;
    /* 02c */ s32 mSlotFinalScrollFrameShift;
    /* 030 */ HeldItem mHeldItem;
    // Record of the item in use (ItemInUse: object kind at 0, 0xf = none; item index at 4; use state at 8; Kart at
    // 0x10; three object pointers at 0x14)
    /* 058 */ ItemInUse mItemInUse;
    // Bits of KART_ITEMS_*: the roulette, held and in-use item, start allowed, start use and end use, the item key down
    // / pressed / released, the in-use advance, and the throw-forward and down keys held at use.
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
// Builds the pool of one kind: allocates the pointer array (only when the kind has objects) and every object, runs
// InitItemObject for each, and copies the kind's limit and callbacks into the pool.
void CreateItemPool(ItemPool *pool, s32 kind, s32 *objectIdCounter);
// Releases the object at index 0 of mObjects (not necessarily the oldest: the array is reordered); FALSE when none is
// active.
BOOL TryReleaseFirstItemObject(ItemPool *tab);
// Runs UpdateItemObject for every active object (in a Wi-Fi race the objects with a pending update count get several
// sub-steps). When mLimit is above 1 and mLimit - mReservedCount is below ITEM_POOL_LOW_FREE_OBJECTS it first makes
// room: on frames divisible by 8, with no free object and an active object, it calls StartItemObjectReleaseIfOldResting
// on the first object; on the other frames it reorders the resting objects with OrderItemPoolObjectsForRelease.
void UpdateItemPool(ItemPool *pool);
void OrderItemPoolObjectsForRelease(ItemObject **objects, s32 pairIndex, s32 endIndex, s32 step);
void ProcessItemPoolMessage(ItemPool *pool, s32 messageKind, s32 frameDifference, u8 *packet, s32 frameStamp);
BOOL SetItemObjectKartFromPacket(ItemPool *pool, u8 *packet);
BOOL ApplyItemObjectEventById(ItemPool *pool, s32 eventByte, s32 objectId);
void StartItemObjectFromData(ItemPool *tab, s32 frameDifference, void *data, s32 useGenericCopy);
void RoundTripItemObjectData(ItemObject *object);
// Draws every taken object that is not out of view, including those only held by a kart, with the kind's draw callback
// or the default models.
void DrawItemPool(ItemPool *tab, void *viewAxis);
void AddRestingItemPoolObject(ItemPool *tab, ItemObject *object);
// Starts an object: moves it into the active part of mObjects and counts it, sets its active flag, gives it a collision
// slot when its kind has a radius, resets its age and calls the kind's start callback.
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
