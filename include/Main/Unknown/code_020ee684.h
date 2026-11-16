#pragma once

#include "types.h"
#include "Main/Item/ItemInUse.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0206bcb0.h"

// Copy of ITEM_THROW_FORWARD_BIT in KartItems.mFlags (func_020f0154 and it_deploy_20EF4A0 set it from the input
// word).
#define KART_ITEMS_THROW_FORWARD 0x10
// One item record per kart (the array behind it_sDriverItemStatus, 0x210 bytes each): the item roulette in the first 0x30 bytes,
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
    /* 01c */ BOOL field1C;
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
    // Bits set from data words and masks by the kart step; 0x200 / 0x40 / 0x2 / 0x4 combine in the use tests; meanings
    // not read
    /* 1ec */ u16 mFlags;
    /* 1ee */ u8 field1EE[2];
    /* 1f0 */ ItemPointLinkRef field1F0;
    /* 1f8 */ u16 mKartIndex;
    /* 1fa */ u8 field1FA[2];
    /* 1fc */ Kart *mKart;
    /* 200 */ s32 mEntryIndex;
    /* 204 */ BOOL mKinokoBoostStarted;
    /* 208 */ BOOL field208;
    /* 20c */ BOOL field20C;
} KartItems;

// Element of the table behind data_0217562a.
typedef struct Unk0217562a {
    /* 00 */ u16 mBits;
    /* 02 */ u8 field2[0x5a];
} Unk0217562a;

extern Unk0217562a data_0217562a[];

// Element at 0x7c of the object behind gRaceMultiConfig.
typedef struct Unk021759c0_7c {
    /* 00 */ u32 field0;
    /* 04 */ u8 field4[0x2c];
} Unk021759c0_7c;

// The object behind gRaceMultiConfig from its first byte: the elements at 0x7c.
typedef struct Unk021759c0_000 {
    /* 000 */ u8 field0[0x7c];
    /* 07c */ Unk021759c0_7c field7C[17];
} Unk021759c0_000;

// The object behind gMapData from its first byte: the halfword at 0x60
// and the word at 0xb0.
typedef struct Unk02175620_060 {
    /* 000 */ u8 field0[0x60];
    /* 060 */ u16 field60;
    /* 062 */ u8 field62[0x4e];
    /* 0b0 */ void *fieldB0;
} Unk02175620_060;

void InitItemInUse(ItemInUse *itemInUse, KartItems *kartItems);
void it_resetDragItem(ItemInUse *itemInUse);
void RemoveItemInUseCircle(ItemInUse *itemInUse, s32 i, ItemObject *object);
void AdvanceItemInUseCircle(ItemInUse *itemInUse);
void StartItemInUseCircle(ItemInUse *itemInUse);
void PlaceItemInUseCircleObjects(ItemInUse *itemInUse);
void RemoveItemInUseTrail(ItemInUse *itemInUse, s32 i, ItemObject *object);
void AdvanceItemInUseTrail(ItemInUse *itemInUse);
void StartItemInUseTrail(ItemInUse *itemInUse);
void RemoveItemInUseOne(ItemInUse *itemInUse, ItemObject *index, ItemObject *object);
void it_20EF350(ItemInUse *itemInUse);
void it_deploy_20EF4A0(ItemInUse *itemInUse);
void ComputeItemInUseObjectPosition(ItemInUse *itemInUse, Vec3 *objectPos, Vec3 *behindPos);
void StartItemInUseOneWithOrientation(ItemInUse *itemInUse);
void StartItemInUseOne(ItemInUse *itemInUse);
void StartItemInUseObjectAndCountDown(ItemInUse *itemInUse, ItemObject *object);
void StartLastItemInUseObjectAndInit(ItemInUse *itemInUse, s32 callKart);
void StartItemInUseObject(ItemInUse *itemInUse, ItemObject *object);
void InitKartItems(KartItems *kartItems, s32 kartIndex);
void func_020efc74(KartItems *kartItems, s32 a);
void sub_20EFD1C(KartItems *kartItems, ItemObject *object);
BOOL sub_20EFD84(KartItems *kartItems, s32 itemInfoIndex);
void sub_20EFEA4(KartItems *kartItems);
void it_dropDriverItem(KartItems *kartItems);
void ReleaseKartItems(KartItems *kartItems);
void sub_20F00F0(KartItems *kartItems);
BOOL func_020f0154(KartItems *kartItems);
// Builds the pool of one kind: allocates the pointer array and every object, and runs InitItemObject for each.
void it_initItemset(ItemPool *pool, s32 kind, s32 *objectIdCounter);
// Releases the object at index 0 of mObjects (not necessarily the oldest: the array is reordered); FALSE when none is
// active.
BOOL TryReleaseFirstItemObject(ItemPool *tab);
// Runs UpdateItemObject for every active object (mode 5: some get several sub-steps). When mLimit is above 1 and
// mLimit - mReservedCount is below 2 it first calls sub_20F9BA8 on the first object or sorts with sub_20F0684.
void UpdateItemPool(ItemPool *pool);
void sub_20F0684(ItemObject **objects, s32 pairIndex, s32 endIndex, s32 step);
void sub_20F0758(ItemPool *pool, s32 messageKind, s32 b, u8 *packet, s32 d);
s32 sub_20F0898(ItemPool *pool, u8 *packet);
s32 sub_20F0950(ItemPool *pool, s32 eventByte, s32 objectId);
void sub_20F0B00(ItemPool *tab, s32 a, void *data, s32 c);
void func_020f0d04(ItemObject *object);
// Draws every taken object, including those only held by a kart, with the kind's draw callback or the default.
void it_renderItemset(ItemPool *tab, void *viewAxis);
void sub_20F0E2C(ItemPool *tab, ItemObject *object);
// Starts an object taken now or earlier and held by a kart: swaps it into the active part of mObjects and counts it.
void it_itemsetAddItem(ItemPool *tab, ItemObject *object);
// Hands an object back to its pool behind the active and taken parts and counts it out; what the object holds is
// freed by it_destroy.
void it_itemsetDestroyItem(ItemPool *tab, ItemObject *object);
void it_itemsetAcquireItems(ItemPool *tab, s32 count, ItemObject **out, u16 kind, Vec3 *pos);
