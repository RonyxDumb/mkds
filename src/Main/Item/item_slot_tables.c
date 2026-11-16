#include "Main/Item/item_slot_tables.h"
#include "Main/System/heap.h"
#include "Main/System/heap_call.h"
#include "Main/Item/item_pool.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_item_slot_sound.h"
#include "Main/Net/slot_result_sync.h"
#include "Main/Net/slot_result_pending.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Kart/karts.h"
#include "Main/Race/race_rank_list.h"
#include "model_material_set.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/attractor_distance_flag.h"
#include "Main/MapObjects/ob_pakkun_sf.h"
#include "Main/MapObjects/attractor.h"
#include "Main/Sound/sound_data_sdat_path.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/System/result_archive_path.h"
#include "Main/Item/item_object_fade_out.h"
#include "fixed_vector_math.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/System/init_after_startup.h"

const ItemSlotRowRemap gItemSlotRowRemaps[7] = {
    {{1, 0, 0, 0, 0, 0, 0}}, {{1, 5, 0, 0, 0, 0, 0}}, {{1, 3, 6, 0, 0, 0, 0}}, {{1, 3, 5, 7, 0, 0, 0}},
    {{1, 2, 3, 5, 7, 0, 0}}, {{1, 2, 4, 5, 7, 8, 0}}, {{1, 2, 3, 4, 6, 7, 8}}};
u16 gItemSlotPossibleItemCount;
u16 gItemSlotSpinItemCount;
s32 gGessoBlockTimer;
s32 gThunderBlockTimer;
s32 gKouraWBlockTimer;
ItemSlotTable gItemSlotHumanGhostPeerTable;
ItemSlotTable gItemSlotCpuTable;
ItemSlotTable gItemSlotForcedTable;
u16 gItemWeightSums[18];
s32 gItemSlotPossibleItems[18];
s32 gItemSlotSpinItems[18];

static inline u32 ItemSlotNextRandomBelow(RandomState64 *random, u32 limit) {
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    if (limit == 0) {
        return random->mValue >> 32;
    } else {
        return ((random->mValue >> 32) * limit) >> 32;
    }
}

s32 PickItem(s32 kartVariant, s32 forcedRowHandle, s32 rankOrRow, s32 isHumanGhostOrPeer, s32 isEntryKart,
             s32 itemCount) {
    ItemSlotTable *table;
    RandomState64 *random;
    u16 *row;
    s32 variant;
    s32 poolIndex;
    u16 acc;
    s32 itemIndex;
    s32 value;
    s32 sel;
    s32 usedObjectCost;
    u16 roll;
    s32 objectKind;
    enum { SPIN_ITEM_FIRST } spinItem;

    sel = ITEM_INFO_NONE;
    if (forcedRowHandle != 0) {
        rankOrRow = (u16) (forcedRowHandle - 1);
        variant = 0;
        table = &gItemSlotForcedTable;
    } else {
        table = isHumanGhostOrPeer != 0 ? &gItemSlotHumanGhostPeerTable : &gItemSlotCpuTable;
        rankOrRow = (u16) (rankOrRow - 1);
        variant = kartVariant;
    }
    row = table->mRows[rankOrRow];
    acc = 0;
    usedObjectCost = 0;
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        for (poolIndex = 0; poolIndex < 0xe; poolIndex++) {
            usedObjectCost +=
                (u16) (gItemKinds[(s32) poolIndex].mObjectCapCost *
                       (gItemPools[(s32) poolIndex].mReservedCount - gItemPools[(s32) poolIndex].mRestingCount));
        }
    }
    for (itemIndex = 0; itemIndex < itemCount; itemIndex++) {
        objectKind = GetItemInfo(itemIndex)->mObjectKind;
        if (!((itemIndex == ITEM_INFO_THUNDER && gThunderBlockTimer > 0) ||
              (itemIndex == ITEM_INFO_KOURA_W && gKouraWBlockTimer > 0) ||
              (itemIndex == ITEM_INFO_GESSO && gGessoBlockTimer > 0))) {
            if (gItemPools[objectKind].mLimit - gItemPools[objectKind].mReservedCount > 0 &&
                GetItemInfo(itemIndex)->mEnabled != FALSE) {
                value = gItemKinds[objectKind].mObjectCapCost * GetItemInfo(itemIndex)->mObjectCount;
                if (value == 0 || value + usedObjectCost <= 0x28) {
                    if (itemIndex >= ITEM_INFO_KOURA_G_THREE && variant != 0) {
                        if (variant == 1) {
                            acc = acc + (row[itemIndex] >> 2);
                        } else {
                            acc = 3 * row[itemIndex] + acc;
                        }
                    } else {
                        acc = acc + row[itemIndex];
                    }
                }
            }
        }
        gItemWeightSums[itemIndex] = acc;
    }
    random = &gRaceProgress->mRandom;
    if (acc == 0) {
        value = 0;
    } else {
        value = ItemSlotNextRandomBelow(random, acc);
    }
    roll = value;
    for (itemIndex = 0; itemIndex < itemCount; itemIndex++) {
        if (roll < gItemWeightSums[itemIndex]) {
            sel = itemIndex;
            break;
        }
    }
    if (ReplaceUnavailableItem(&sel) != FALSE) {
        TryReleaseItemObjectsForItemInfo(sel);
    }
    if (isEntryKart != 0) {
        if (forcedRowHandle != 0) {
            gItemSlotSpinItemCount = 0;
            for (spinItem = 0; spinItem < itemCount; spinItem++) {
                if (spinItem == sel || row[spinItem] != 0) {
                    gItemSlotSpinItems[gItemSlotSpinItemCount++] = spinItem;
                }
            }
        } else {
            gItemSlotSpinItemCount = 0;
        }
    }
    return sel;
}

void InitItemSlot(KartItems *slot, KartItems *kartItems) {
    slot->mSelf = kartItems;
    slot->mSlotState = KART_ITEMS_SLOT_IDLE;
    slot->mSlotFrames = 0;
    slot->mSlotShownItem = ITEM_INFO_NONE;
    slot->mSlotResult = ITEM_INFO_NONE;
    slot->mActiveItem = ITEM_INFO_NONE;
    slot->mResultPending = FALSE;
    slot->mIsPeer = gRaceSetup->mCurrentEntries[kartItems->mKartIndex].mPlayer.mKind == PLAYER_KIND_PEER;
}

void StartItemSlot(KartItems *slot, s32 forcedRowHandle, s32 rank, s32 isHumanGhostOrPeer, s32 shortSpin) {
    KartItems *kartItems;
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { ITEM_INDEX_FIRST } itemIndex, objectKind;
    BOOL isWiFiRace;
    BOOL isEntryKart;

    kartItems = slot->mSelf;
    isWiFiRace = gRaceSetup->mMode == MODE_WIFI;
    if (slot->mSlotState != KART_ITEMS_SLOT_IDLE) {
        return;
    }
    if (slot->mActiveItem != ITEM_INFO_NONE) {
        return;
    }
    slot->mSlotState = KART_ITEMS_SLOT_SPINNING;
    slot->mSlotShownItem = ITEM_INFO_NONE;
    if (!isWiFiRace) {
        StopRaceRankListItemInUse(slot->mSelf->mKartIndex);
    }
    if (isWiFiRace) {
        slot->mIsShortSpin = FALSE;
        slot->mSlotFrames = 0;
        slot->mSlotFrameCount = KART_ITEMS_SLOT_END_FRAME_WIFI;
        slot->mSlotFinalScrollFrameCount = KART_ITEMS_SLOT_FINAL_SCROLL_FRAMES;
        slot->mSlotFinalScrollFrameShift = KART_ITEMS_SLOT_FINAL_SCROLL_SHIFT;
    } else if (shortSpin != 0) {
        slot->mIsShortSpin = TRUE;
        slot->mSlotFrames = KART_ITEMS_SLOT_SHORT_SPIN_START_FRAME;
        slot->mSlotFrameCount = KART_ITEMS_SLOT_END_FRAME_SHORT;
        slot->mSlotFinalScrollFrameCount = KART_ITEMS_SLOT_SHORT_FINAL_SCROLL_FRAMES;
        slot->mSlotFinalScrollFrameShift = KART_ITEMS_SLOT_SHORT_FINAL_SCROLL_SHIFT;
    } else {
        slot->mIsShortSpin = FALSE;
        slot->mSlotFrames = 0;
        slot->mSlotFrameCount = KART_ITEMS_SLOT_END_FRAME_NORMAL;
        slot->mSlotFinalScrollFrameCount = KART_ITEMS_SLOT_FINAL_SCROLL_FRAMES;
        slot->mSlotFinalScrollFrameShift = KART_ITEMS_SLOT_FINAL_SCROLL_SHIFT;
    }
    isEntryKart = kartItems->mKartIndex == gRaceSetup->mEntryIndex;
    if (kartItems->mItemInUse.mObjectKind != ITEM_OBJECT_KIND_NONE &&
        kartItems->mItemInUse.mItemInfoIndex >= ITEM_INFO_KOURA_G_THREE) {
        slot->mSlotResult =
            PickItem(0, forcedRowHandle, rank, isHumanGhostOrPeer, isEntryKart, ITEM_INFO_KOURA_G_THREE);
    } else {
        slot->mSlotResult = PickItem(GetKartVariant(kartItems->mKartIndex), forcedRowHandle, rank, isHumanGhostOrPeer,
                                     isEntryKart, ITEM_INFO_COUNT);
    }
    if (isWiFiRace) {
        StartOwnSlotResultSync(slot->mSlotResult);
        slot->mResultPending = TRUE;
        return;
    }
    itemIndex = slot->mSlotResult;
    itemInfo = &gItemInfos[itemIndex];
    objectKind = itemInfo->mObjectKind;
    pool = &gItemPools[objectKind];
    pool->mReservedCount += itemInfo->mObjectCount;
}

void StartItemSlotResultPending(KartItems *slot) {
    KartItems *kartItems;
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { ITEM_INDEX_FIRST } itemIndex, objectKind;

    kartItems = slot->mSelf;
    if (kartItems->mActiveItem != ITEM_INFO_NONE) {
        kartItems->mActiveItem = ITEM_INFO_NONE;
    }
    if (slot->mSlotState != KART_ITEMS_SLOT_IDLE) {
        if (kartItems->mResultPending == FALSE) {
            itemIndex = kartItems->mSlotResult;
            itemInfo = &gItemInfos[itemIndex];
            objectKind = itemInfo->mObjectKind;
            pool = &gItemPools[objectKind];
            pool->mReservedCount -= itemInfo->mObjectCount;
        }
        kartItems->mSlotState = KART_ITEMS_SLOT_IDLE;
        kartItems->mSlotFrames = 0;
        kartItems->mSlotShownItem = ITEM_INFO_NONE;
        kartItems->mSlotResult = ITEM_INFO_NONE;
        kartItems->mActiveItem = ITEM_INFO_NONE;
        kartItems->mResultPending = FALSE;
    } else {
        if (kartItems->mHeldItem.mItemInfoIndex != ITEM_INFO_NONE) {
            ReleaseHeldItem(&kartItems->mHeldItem, 1);
        }
    }
    slot->mSlotState = KART_ITEMS_SLOT_SPINNING;
    slot->mSlotFrames = 0;
    slot->mSlotFrameCount = KART_ITEMS_SLOT_END_FRAME_WIFI;
    slot->mSlotShownItem = ITEM_INFO_NONE;
    slot->mActiveItem = ITEM_INFO_NONE;
    slot->mSlotResult = ITEM_INFO_NONE;
    slot->mResultPending = TRUE;
}

BOOL UpdateItemSlot(KartItems *slot, KartItems *kartItems) {
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { OBJECT_KIND_FIRST } objectKind;
    s32 mode;
    u32 value;

    switch (slot->mSlotState) {
        case KART_ITEMS_SLOT_SPINNING:
            slot->mSlotFrames++;
            mode = gRaceSetup->mMode;
            if (mode == MODE_WIFI && slot->mResultPending != FALSE) {
                value = kartItems->mKartIndex & 0xff;
                if (IsParticipantSlotResultSyncing(((u8 *) gParticipantKartMap)[value]) == 0) {
                    value = GetParticipantSlotResult(((u8 *) gParticipantKartMap)[value]);
                    if (IsItemInfoObjectCountFree(value) != FALSE) {
                        TryReleaseItemObjectsForItemInfo(value);
                    }
                    itemInfo = &gItemInfos[value];
                    objectKind = itemInfo->mObjectKind;
                    pool = &gItemPools[objectKind];
                    pool->mReservedCount += itemInfo->mObjectCount;
                    slot->mSlotResult = value;
                    slot->mResultPending = FALSE;
                    slot->mSlotFrameCount += slot->mSlotFrames - (KART_ITEMS_SLOT_WIFI_WAIT_LIMIT_FRAME + 1);
                } else if (slot->mSlotFrames > KART_ITEMS_SLOT_WIFI_WAIT_LIMIT_FRAME) {
                    slot->mSlotFrames = KART_ITEMS_SLOT_WIFI_WAIT_REWIND_FRAME;
                }
                return FALSE;
            }
            if (slot->mSlotFrames > KART_ITEMS_SLOT_MIN_SPIN_FRAMES &&
                (((kartItems->mFlags & (KART_ITEMS_START_ALLOWED | KART_ITEMS_START_USE | KART_ITEMS_SLOT)) ==
                      (KART_ITEMS_START_ALLOWED | KART_ITEMS_START_USE | KART_ITEMS_SLOT) &&
                  mode != MODE_WIFI && slot->mIsShortSpin == FALSE) ||
                 slot->mSlotFrames > slot->mSlotFrameCount)) {
                slot->mSlotFrames = 0;
                slot->mSlotState = KART_ITEMS_SLOT_SHOWING_RESULT;
            }
            break;
        case KART_ITEMS_SLOT_SHOWING_RESULT:
            slot->mSlotFrames++;
            if (slot->mSlotFrames > slot->mSlotFinalScrollFrameCount * 2) {
                return TRUE;
            }
            break;
    }
    return FALSE;
}

void FinishItemSlot(KartItems *slot) {
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { ITEM_INDEX_FIRST } itemIndex, objectKind;

    itemIndex = slot->mSlotResult;
    itemInfo = &gItemInfos[itemIndex];
    objectKind = itemInfo->mObjectKind;
    pool = &gItemPools[objectKind];
    pool->mReservedCount -= itemInfo->mObjectCount;
    slot->mSlotState = KART_ITEMS_SLOT_IDLE;
    slot->mSlotFrames = 0;
    slot->mSlotShownItem = ITEM_INFO_NONE;
    slot->mSlotResult = ITEM_INFO_NONE;
    slot->mActiveItem = ITEM_INFO_NONE;
    slot->mResultPending = FALSE;
}

void StopItemSlot(KartItems *slot) {
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { ITEM_INDEX_FIRST } itemIndex, objectKind;

    if (slot->mResultPending == FALSE) {
        itemIndex = slot->mSlotResult;
        itemInfo = &gItemInfos[itemIndex];
        objectKind = itemInfo->mObjectKind;
        pool = &gItemPools[objectKind];
        pool->mReservedCount -= itemInfo->mObjectCount;
    }
    slot->mSlotState = KART_ITEMS_SLOT_IDLE;
    slot->mSlotFrames = 0;
    slot->mSlotShownItem = ITEM_INFO_NONE;
    slot->mSlotResult = ITEM_INFO_NONE;
    slot->mActiveItem = ITEM_INFO_NONE;
    slot->mResultPending = FALSE;
}

static inline u16 ItemSlotNextRandomBelowU16(RandomState64 *random, u32 limit) {
    u32 value;
    if (limit == 0) {
        value = 0;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        if (limit == 0) {
            value = random->mValue >> 32;
        } else {
            value = ((random->mValue >> 32) * limit) >> 32;
        }
    }
    return value;
}

void PickItemSlotShownItem(KartItems *slot) {
    RandomState64 *random;
    s32 *items;
    u16 itemCount;
    u16 index;

    switch (slot->mSlotState) {
        case KART_ITEMS_SLOT_IDLE:
            return;
        case KART_ITEMS_SLOT_SPINNING:
            if (gItemSlotSpinItemCount != 0) {
                itemCount = gItemSlotSpinItemCount;
                items = gItemSlotSpinItems;
            } else {
                itemCount = gItemSlotPossibleItemCount;
                items = gItemSlotPossibleItems;
            }
            random = &gRaceProgress->mLocalRandom;
            index = ItemSlotNextRandomBelowU16(random, itemCount);
            if (slot->mSlotShownItem == items[index]) {
                index++;
                if (index >= itemCount) {
                    index = 0;
                }
            }
            slot->mSlotShownItem = items[index];
            break;
        case KART_ITEMS_SLOT_SHOWING_RESULT:
            slot->mSlotShownItem = slot->mSlotResult;
            break;
    }
}

void StartThunderBlockTimer(s32 isRaceStart) {
    gThunderBlockTimer = 1800;
    if (isRaceStart != 0) {
        gThunderBlockTimer += 300;
    }
}

void StartKouraWBlockTimer(s32 isRaceStart) {
    gKouraWBlockTimer = 1800;
    if (isRaceStart != 0) {
        gKouraWBlockTimer += 300;
    }
}

void StartGessoBlockTimer(s32 isRaceStart) {
    gGessoBlockTimer = 0x384;
    if (isRaceStart != 0) {
        gGessoBlockTimer += 0x12c;
    }
}

void AdvanceItemBlockTimers(void) {
    if (gThunderBlockTimer > 0) {
        gThunderBlockTimer = gThunderBlockTimer - 1;
    }
    if (gKouraWBlockTimer > 0) {
        gKouraWBlockTimer = gKouraWBlockTimer - 1;
    }
    if (gGessoBlockTimer > 0) {
        gGessoBlockTimer = gGessoBlockTimer - 1;
    }
}

void FinishItemSlotAndStopSound(KartItems *slot) {
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { ITEM_INDEX_FIRST } itemIndex, objectKind;

    if (slot->mSelf->mKartIndex == gRaceSetup->mEntryIndex) {
        StopRaceItemSlotSound();
    }
    itemIndex = slot->mSlotResult;
    itemInfo = &gItemInfos[itemIndex];
    objectKind = itemInfo->mObjectKind;
    pool = &gItemPools[objectKind];
    pool->mReservedCount -= itemInfo->mObjectCount;
    slot->mSlotState = KART_ITEMS_SLOT_IDLE;
    slot->mSlotFrames = 0;
    slot->mSlotShownItem = ITEM_INFO_NONE;
    slot->mSlotResult = ITEM_INFO_NONE;
    slot->mActiveItem = ITEM_INFO_NONE;
    slot->mResultPending = FALSE;
}

void SetActiveItem(KartItems *kartItems, u32 itemIndex) {
    kartItems->mActiveItem = itemIndex;
}

#pragma thumb on

u8 *LoadItemSlotTableData(ItemSlotTable *table, u8 *data) {
    s32 rowCount;
    s32 columnCount;
    s32 columnIndex;
    s32 rowIndex;
    u16(*tab)[0x12];

    rowCount = *data++;
    columnCount = *data++;
    table->mRowCount = rowCount;
    table->mRows = HeapAlloc(GetHeap(GetCurrentHeapCall()), (rowCount + 1) * 0x24);
    tab = table->mRows;
    for (columnIndex = 0; columnIndex < columnCount; columnIndex++) {
        for (rowIndex = 0; rowIndex < rowCount; rowIndex++) {
            tab[rowIndex][columnIndex] = *data++;
        }
        tab[rowIndex][columnIndex] = 0xffff;
    }
    return data;
}

u8 *ComputeItemSlotTableDataEnd(u8 *data) {
    return data + 2 + data[1] * data[0];
}

void RemapItemSlotRows(ItemSlotTable *table, s32 kartCount) {
    u16(*tab)[0x12];
    s32 rowIndex;
    s32 columnIndex;
    u16 sourceRow;
    const u16 *sourceRows;

    sourceRows = gItemSlotRowRemaps[kartCount - 1].mSourceRowNumbers;
    tab = table->mRows;
    if (kartCount == 8) {
        return;
    }
    for (rowIndex = 0; rowIndex < kartCount; rowIndex++) {
        sourceRow = sourceRows[rowIndex] - 1;
        for (columnIndex = 0; columnIndex < 0x12; columnIndex++) {
            tab[rowIndex][columnIndex] = tab[sourceRow][columnIndex];
        }
    }
    for (; rowIndex < 8; rowIndex++) {
        for (columnIndex = 0; columnIndex < 0x12; columnIndex++) {
            tab[rowIndex][columnIndex] = 0;
        }
    }
}

void CreateItemSlotTables(void) {
    u8 *data;
    enum { ITEM_INDEX_FIRST } itemIndex;
    s32 rowIndex;
    s32 rowCount;
    s32 *entry;
    enum { COMPACT_INDEX_FIRST } compactIndex;

    data = FindMainRaceOrMainEffectFile("Item/ItemSlotList.dat");
    switch (gRaceSetup->mMode) {
        case MODE_GRAND_PRIX:
        case MODE_TIME_ATTACK:
        case MODE_MISSION_RUN:
            data = LoadItemSlotTableData(&gItemSlotHumanGhostPeerTable, data + 1);
            data = LoadItemSlotTableData(&gItemSlotCpuTable, data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&gItemSlotForcedTable, data);
            break;
        case MODE_BATTLE:
            data = ComputeItemSlotTableDataEnd(data + 1);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&gItemSlotForcedTable, data);
            switch (gRaceSetup->mBattleKind) {
                case BATTLE_KIND_BALLOON:
                default:
                    data = LoadItemSlotTableData(&gItemSlotHumanGhostPeerTable, data);
                    data = LoadItemSlotTableData(&gItemSlotCpuTable, data);
                    break;
                case BATTLE_KIND_SHINE:
                    data = ComputeItemSlotTableDataEnd(data);
                    data = ComputeItemSlotTableDataEnd(data);
                    data = LoadItemSlotTableData(&gItemSlotHumanGhostPeerTable, data);
                    data = LoadItemSlotTableData(&gItemSlotCpuTable, data);
                    break;
            }
            break;
        case MODE_VS:
            data = ComputeItemSlotTableDataEnd(data + 1);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&gItemSlotHumanGhostPeerTable, data);
            data = LoadItemSlotTableData(&gItemSlotCpuTable, data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&gItemSlotForcedTable, data);
            if (gRaceSetup->mCpuDifficulty == 0) {
                RemapItemSlotRows(&gItemSlotHumanGhostPeerTable, gRaceSetup->mKartCount);
                RemapItemSlotRows(&gItemSlotCpuTable, gRaceSetup->mKartCount);
            }
            break;
        case MODE_WIFI:
            data = ComputeItemSlotTableDataEnd(data + 1);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&gItemSlotHumanGhostPeerTable, data);
            data = LoadItemSlotTableData(&gItemSlotCpuTable, data);
            data = LoadItemSlotTableData(&gItemSlotForcedTable, data);
            if (gRaceSetup->mCpuDifficulty == 0) {
                RemapItemSlotRows(&gItemSlotHumanGhostPeerTable, gRaceSetup->mKartCount);
                RemapItemSlotRows(&gItemSlotCpuTable, gRaceSetup->mKartCount);
            }
            break;
    }
    rowCount = gItemSlotHumanGhostPeerTable.mRowCount;
    for (itemIndex = 0; itemIndex < ITEM_INFO_COUNT; itemIndex++) {
        gItemSlotPossibleItems[itemIndex] = 0x12;
        for (rowIndex = 0; rowIndex < rowCount; rowIndex++) {
            if (gItemSlotHumanGhostPeerTable.mRows[rowIndex][itemIndex] != 0 ||
                gItemSlotCpuTable.mRows[rowIndex][itemIndex] != 0) {
                gItemSlotPossibleItems[itemIndex] = itemIndex;
            }
        }
    }
    gItemSlotPossibleItemCount = 0;
    for (compactIndex = 0; compactIndex < 0x12; compactIndex++) {
        entry = &gItemSlotPossibleItems[compactIndex];
        if (gItemSlotPossibleItems[compactIndex] != 0x12) {
            gItemSlotPossibleItems[gItemSlotPossibleItemCount++] = *entry;
        }
    }
    gItemSlotSpinItemCount = 0;
}

#pragma thumb off
