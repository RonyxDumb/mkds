#pragma once

#include "types.h"
#include "Main/Item/item_object_fade_out.h"

// A weight table parsed from Item/ItemSlotList.dat: rows of one weight per item.
typedef struct ItemSlotTable {
    /* 00 */ s32 mRowCount;
    /* 04 */ u16 (*mRows)[0x12];
} ItemSlotTable;




// For a race of N karts: the 1-based source row of the item slot table that each of the first N rows is copied from
// (gItemSlotRowRemaps[N - 1]).
typedef struct ItemSlotRowRemap {
    /* 00 */ u16 mSourceRowNumbers[7];
} ItemSlotRowRemap;

extern const ItemSlotRowRemap gItemSlotRowRemaps[7];

void RemapItemSlotRows(ItemSlotTable *table, s32 kartCount);
void CreateItemSlotTables(void);

typedef struct ItemSlotTable ItemSlotTable;

typedef struct KartItems KartItems;

// Address after one table: start + 2 + rows * columns from the two header bytes
u8 *ComputeItemSlotTableDataEnd(u8 *data);
u8 *LoadItemSlotTableData(ItemSlotTable *table, u8 *data);
void SetActiveItem(KartItems *kartItems, unsigned int itemIndex);
// HUD tick: picks the item shown now (a random entry of the spin list, or of the possible-items list when the spin list
// is empty, moving to the next entry when it draws the one already shown; the result during the final scroll). The HUD
// calls it on the frames where the shown item changes (RACE_ITEM_SLOT_CHANGE_FRAME_CASES) while a roulette runs.
void PickItemSlotShownItem(KartItems *slot);
void StopItemSlot(KartItems *slot);
// After the roulette ran to its end: releases the reservation of the result's objects in their pool
// (ItemPool.mReservedCount), resets the state, mSlotFrames, the shown and result items, mActiveItem and mResultPending;
// the caller gives the item.
void FinishItemSlot(KartItems *slot);
BOOL UpdateItemSlot(KartItems *slot, KartItems *kartItems);
void StartItemSlotResultPending(KartItems *slot);
// Returns without starting when the roulette runs or mActiveItem is set
void StartItemSlot(KartItems *slot, s32 forcedRowHandle, s32 rank, s32 isHumanGhostOrPeer, s32 shortSpin);
void InitItemSlot(KartItems *slot, KartItems *kartItems);
// Weighted roll of one item from a row (the kart's rank, or a forced row): sums the weights of the allowed items, draws
// with the race random, and when ReplaceUnavailableItem replaces a nothing-rolled or unavailable item by
// ITEM_INFO_BANANA (ITEM_INFO_KINOKO in a Wi-Fi race) it frees pool objects until that item fits. With isEntryKart and
// a forced row it writes the spin list; with isEntryKart and no forced row it clears it. Also called by a course object
// (the wooden box).
s32 PickItem(s32 kartVariant, s32 forcedRowHandle, s32 rankOrRow, s32 isHumanGhostOrPeer, s32 isEntryKart,
             s32 itemCount);

void StartGessoBlockTimer(s32 isRaceStart);
void AdvanceItemBlockTimers(void);
void FinishItemSlotAndStopSound(KartItems *slot);

void StartKouraWBlockTimer(s32 isRaceStart);
void StartThunderBlockTimer(s32 isRaceStart);

extern s32 gItemSlotPossibleItems[18];
extern s32 gItemSlotSpinItems[18];
extern u16 gItemWeightSums[18];
extern ItemSlotTable gItemSlotForcedTable;
extern ItemSlotTable gItemSlotHumanGhostPeerTable;
extern ItemSlotTable gItemSlotCpuTable;
