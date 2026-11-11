#include "Main/Unknown/code_020f813c.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f7c90.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f81c0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020bb5cc.h"
#include "Main/Unknown/code_020f82c4.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_0205a000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02079b40.h"
#include "Main/Unknown/code_020be930.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_020f9c6c.h"

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
    enum { K0 } spinItem;

    sel = 0x13;
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
        if (!((itemIndex == 8 && gThunderBlockTimer > 0) || (itemIndex == 7 && gKouraWBlockTimer > 0) ||
              (itemIndex == 0xf && gGessoBlockTimer > 0))) {
            if (gItemPools[objectKind].mLimit - gItemPools[objectKind].mReservedCount > 0 &&
                GetItemInfo(itemIndex)->mEnabled != FALSE) {
                value = gItemKinds[objectKind].mObjectCapCost * GetItemInfo(itemIndex)->mObjectCount;
                if (value == 0 || value + usedObjectCost <= 0x28) {
                    if (itemIndex >= 9 && variant != 0) {
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
    slot->mSlotState = 0;
    slot->mSlotFrames = 0;
    slot->mSlotShownItem = 0x13;
    slot->mSlotResult = 0x13;
    slot->mActiveItem = 0x13;
    slot->mResultPending = FALSE;
    slot->mIsPeer = gRaceSetup->mCurrentEntries[kartItems->mKartIndex].mPlayer.mKind == PLAYER_KIND_PEER;
}

void StartItemSlot(KartItems *slot, s32 forcedRowHandle, s32 rank, s32 isHumanGhostOrPeer, s32 shortSpin) {
    KartItems *kartItems;
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { K0 } itemIndex, objectKind;
    BOOL isWiFiRace;
    BOOL isEntryKart;

    kartItems = slot->mSelf;
    isWiFiRace = gRaceSetup->mMode == MODE_WIFI;
    if (slot->mSlotState != 0) {
        return;
    }
    if (slot->mActiveItem != 0x13) {
        return;
    }
    slot->mSlotState = 1;
    slot->mSlotShownItem = 0x13;
    if (!isWiFiRace) {
        StopRaceRankListItemInUse(slot->mSelf->mKartIndex);
    }
    if (isWiFiRace) {
        slot->mIsShortSpin = FALSE;
        slot->mSlotFrames = 0;
        slot->mSlotFrameCount = 0x85;
        slot->mSlotFinalScrollFrameCount = 0x10;
        slot->mSlotFinalScrollFrameShift = 4;
    } else if (shortSpin != 0) {
        slot->mIsShortSpin = TRUE;
        slot->mSlotFrames = 0x4d;
        slot->mSlotFrameCount = 0x65;
        slot->mSlotFinalScrollFrameCount = 8;
        slot->mSlotFinalScrollFrameShift = 3;
    } else {
        slot->mIsShortSpin = FALSE;
        slot->mSlotFrames = 0;
        slot->mSlotFrameCount = 0xd5;
        slot->mSlotFinalScrollFrameCount = 0x10;
        slot->mSlotFinalScrollFrameShift = 4;
    }
    isEntryKart = kartItems->mKartIndex == gRaceSetup->mEntryIndex;
    if (kartItems->mItemInUse.mObjectKind != 0xf && kartItems->mItemInUse.mItemInfoIndex >= 9) {
        slot->mSlotResult = PickItem(0, forcedRowHandle, rank, isHumanGhostOrPeer, isEntryKart, 9);
    } else {
        slot->mSlotResult = PickItem(GetKartVariant(kartItems->mKartIndex), forcedRowHandle, rank, isHumanGhostOrPeer,
                                     isEntryKart, 0x12);
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
    enum { K0 } itemIndex, objectKind;

    kartItems = slot->mSelf;
    if (kartItems->mActiveItem != 0x13) {
        kartItems->mActiveItem = 0x13;
    }
    if (slot->mSlotState != 0) {
        if (kartItems->mResultPending == FALSE) {
            itemIndex = kartItems->mSlotResult;
            itemInfo = &gItemInfos[itemIndex];
            objectKind = itemInfo->mObjectKind;
            pool = &gItemPools[objectKind];
            pool->mReservedCount -= itemInfo->mObjectCount;
        }
        kartItems->mSlotState = 0;
        kartItems->mSlotFrames = 0;
        kartItems->mSlotShownItem = 0x13;
        kartItems->mSlotResult = 0x13;
        kartItems->mActiveItem = 0x13;
        kartItems->mResultPending = FALSE;
    } else {
        if (kartItems->mHeldItem.mItemInfoIndex != 0x13) {
            ReleaseHeldItem(&kartItems->mHeldItem, 1);
        }
    }
    slot->mSlotState = 1;
    slot->mSlotFrames = 0;
    slot->mSlotFrameCount = 0x85;
    slot->mSlotShownItem = 0x13;
    slot->mActiveItem = 0x13;
    slot->mSlotResult = 0x13;
    slot->mResultPending = TRUE;
}

BOOL UpdateItemSlot(KartItems *slot, KartItems *kartItems) {
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { K0 } objectKind;
    s32 mode;
    u32 value;

    switch (slot->mSlotState) {
        case 1:
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
                    slot->mSlotFrameCount += slot->mSlotFrames - 0x6f;
                } else if (slot->mSlotFrames > 0x6e) {
                    slot->mSlotFrames = 0x67;
                }
                return FALSE;
            }
            if (slot->mSlotFrames > 0x3c &&
                (((kartItems->mFlags & 0x241) == 0x241 && mode != MODE_WIFI && slot->mIsShortSpin == FALSE) ||
                 slot->mSlotFrames > slot->mSlotFrameCount)) {
                slot->mSlotFrames = 0;
                slot->mSlotState = 2;
            }
            break;
        case 2:
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
    enum { K0 } itemIndex, objectKind;

    itemIndex = slot->mSlotResult;
    itemInfo = &gItemInfos[itemIndex];
    objectKind = itemInfo->mObjectKind;
    pool = &gItemPools[objectKind];
    pool->mReservedCount -= itemInfo->mObjectCount;
    slot->mSlotState = 0;
    slot->mSlotFrames = 0;
    slot->mSlotShownItem = 0x13;
    slot->mSlotResult = 0x13;
    slot->mActiveItem = 0x13;
    slot->mResultPending = FALSE;
}

void StopItemSlot(KartItems *slot) {
    ItemInfo *itemInfo;
    ItemPool *pool;
    enum { K0 } itemIndex, objectKind;

    if (slot->mResultPending == FALSE) {
        itemIndex = slot->mSlotResult;
        itemInfo = &gItemInfos[itemIndex];
        objectKind = itemInfo->mObjectKind;
        pool = &gItemPools[objectKind];
        pool->mReservedCount -= itemInfo->mObjectCount;
    }
    slot->mSlotState = 0;
    slot->mSlotFrames = 0;
    slot->mSlotShownItem = 0x13;
    slot->mSlotResult = 0x13;
    slot->mActiveItem = 0x13;
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
    u32 index;

    switch (slot->mSlotState) {
        case 0:
            return;
        case 1:
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
                index = (u16) (index + 1);
                if (index >= itemCount) {
                    index = 0;
                }
            }
            slot->mSlotShownItem = items[index];
            break;
        case 2:
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
    enum { K0 } itemIndex, objectKind;

    if (slot->mSelf->mKartIndex == gRaceSetup->mEntryIndex) {
        StopRaceItemSlotSound();
    }
    itemIndex = slot->mSlotResult;
    itemInfo = &gItemInfos[itemIndex];
    objectKind = itemInfo->mObjectKind;
    pool = &gItemPools[objectKind];
    pool->mReservedCount -= itemInfo->mObjectCount;
    slot->mSlotState = 0;
    slot->mSlotFrames = 0;
    slot->mSlotShownItem = 0x13;
    slot->mSlotResult = 0x13;
    slot->mActiveItem = 0x13;
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

#pragma thumb off

#pragma thumb on
u8 *ComputeItemSlotTableDataEnd(u8 *data) {
    return data + 2 + data[1] * data[0];
}
#pragma thumb off
