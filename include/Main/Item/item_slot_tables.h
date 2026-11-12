#pragma once

#include "types.h"
#include "Main/Unknown/code_020f6be8.h"

// A weight table parsed from "Item/ItemSlotList.dat": mRowCount rows of 18 halfwords (one weight per item) plus one end
// row of 0xffff. Three globals: gItemSlotHumanGhostPeerTable, gItemSlotCpuTable (row = the kart's rank) and
// gItemSlotForcedTable (row = a forced argument minus one).
typedef struct ItemSlotTable {
    /* 00 */ s32 mRowCount;
    /* 04 */ u16 (*mRows)[0x12];
} ItemSlotTable;

extern ItemSlotTable gItemSlotForcedTable;

extern ItemSlotTable gItemSlotCpuTable;

extern ItemSlotTable gItemSlotHumanGhostPeerTable;

// Element of the table behind gItemSlotRowRemaps, 0xe bytes.
typedef struct ItemSlotRowRemap {
    /* 00 */ u16 mSourceRowNumbers[7];
} ItemSlotRowRemap;

extern ItemSlotRowRemap gItemSlotRowRemaps[];

void RemapItemSlotRows(ItemSlotTable *table, s32 kartCount);
void CreateItemSlotTables(void);
u8 GetItemObjectHitType(ItemObject *itemParam, ItemObject *otherParam);
void DeflectItemObjectRandomly(ItemObject *item, Vec3 *otherPos, Vec3 *normal);
