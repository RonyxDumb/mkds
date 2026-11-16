#include "Main/Item/item_data_slots_update.h"
#include "Main/Net/slot_result_pending.h"
#include "Main/Net/wifi_race_sync_advance.h"
#include "Main/Item/item_koura_w.h"
#include "Main/Item/item_f_box.h"
#include "Main/Race/race_setup_block.h"
#include "touch_panel_sampling.h"
#include "Main/System/backup_net_camera_work.h"
#include "00/Lib/DWC/friends_match_session.h"
#include "cpu_copy_fill.h"
#include "Main/Save/ghost_record_file.h"

// Lowers the rank by one for each better-ranked kart whose participant dropped out of the race.
void SubtractDroppedFromRank(u32 kartIndex) {
    u8 otherKartIndex;
    u8 rank;
    u8 isDropped;
    u8 otherRank;
    s32 participantIndex;
    s32 otherParticipantIndex;
    ParticipantKartMap *participantKartMap;
    WiFiRaceSync *wiFiRaceSync;

    participantKartMap = g_GlobalRE;
    wiFiRaceSync = g_GlobalAA;
    participantIndex = GetParticipantOfKart(kartIndex);
    rank = wiFiRaceSync->mEntries[participantIndex].mRank;
    if (participantIndex < 0) {
        return;
    }
    otherKartIndex = 0;
    for (otherKartIndex = 0; otherKartIndex < (s32) g_GlobalCO->mKartCount; otherKartIndex++) {
        if (otherKartIndex != kartIndex) {
            otherParticipantIndex = participantKartMap->mParticipantOfKart[otherKartIndex];
            otherRank = wiFiRaceSync->mEntries[otherParticipantIndex].mRank;
            if (otherParticipantIndex >= 0 && otherRank < rank) {
                isDropped = 0;
                if ((wiFiRaceSync->mStartParticipantMask & (1 << (u8) otherParticipantIndex)) != 0 &&
                    (wiFiRaceSync->mParticipantMask & (1 << (u8) otherParticipantIndex)) == 0) {
                    isDropped = 1;
                }
                if (isDropped != 0) {
                    rank = rank - 1;
                }
            }
        }
    }
    wiFiRaceSync->mEntries[participantIndex].mRank = rank;
}

void ResetItemDataSlots(void) {
    s32 slotIndex;
    s32 participantIndex;
    ItemDataSlot *slot;

    for (slotIndex = 0; slotIndex < ITEM_DATA_SLOT_COUNT; slotIndex++) {
        for (participantIndex = 0; participantIndex < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participantIndex++) {
            slot = &g_GlobalAA->mReceivedItemDataSlots[slotIndex][participantIndex];
            slot->mState = ITEM_DATA_SLOT_STATE_FREE;
            slot->mSendUntilSyncFrame = 0;
            slot->mItemKind = ITEM_DATA_KIND_NONE;
            slot->mMessageKind = 0;
            slot->mDataSize = 0;
            Mem_CpuFill8(slot->mData, 0, ITEM_DATA_SLOT_BUFFER_SIZE);
            g_GlobalAA->mItemDataHandled[slotIndex][participantIndex] = 0;
        }
        slot = &g_GlobalAA->mItemDataSlots[slotIndex];
        slot->mState = ITEM_DATA_SLOT_STATE_FREE;
        slot->mSendUntilSyncFrame = 0;
        slot->mItemKind = ITEM_DATA_KIND_NONE;
        slot->mMessageKind = 0;
        slot->mDataSize = 0;
        Mem_CpuFill8(slot->mData, 0, ITEM_DATA_SLOT_BUFFER_SIZE);
    }
    g_GlobalAA->mUnusedItemDataBytes = ITEM_DATA_BYTES;
}

BOOL IsAnyItemDataSlotFree(void) {
    u16 slotIndex;

    for (slotIndex = 0; slotIndex < ITEM_DATA_SLOT_COUNT; slotIndex++) {
        if (g_GlobalAA->mItemDataSlots[slotIndex].mState == ITEM_DATA_SLOT_STATE_FREE) {
            return TRUE;
        }
    }
    return FALSE;
}

void WriteItemDataSlotsToSendBuffer(void) {
    u16 slotIndex;
    u8 *headerCursor;
    u8 *dataCursor;
    u16 usedSize;
    ItemDataSlot *slot;
    WiFiRaceSyncRecord *payload;
    u8 headerByte;

    usedSize = 0;
    payload = (void *) &g_GlobalAA->mSendBuffer->mRecord;
    headerCursor = payload->mItemDataHeaders;
    dataCursor = headerCursor + ITEM_DATA_SLOT_COUNT;
    for (slotIndex = 0; slotIndex < ITEM_DATA_SLOT_COUNT; slotIndex++) {
        slot = &g_GlobalAA->mItemDataSlots[slotIndex];
        if (slot->mState == ITEM_DATA_SLOT_STATE_FREE || slot->mState == ITEM_DATA_SLOT_STATE_SENT ||
            slot->mItemKind == ITEM_DATA_KIND_NONE) {
            headerByte = ITEM_DATA_KIND_NONE;
        } else {
            headerByte =
                (slot->mItemKind & ITEM_DATA_HEADER_KIND_MASK) |
                ((slot->mMessageKind << ITEM_DATA_HEADER_MESSAGE_KIND_SHIFT) & ITEM_DATA_HEADER_MESSAGE_KIND_MASK);
        }
        *headerCursor++ = headerByte;
        switch (slot->mState) {
            case ITEM_DATA_SLOT_STATE_FREE:
                break;
            case ITEM_DATA_SLOT_STATE_SENDING:
                if (slot->mDataSize != 0 && ITEM_DATA_BYTES - (usedSize + slot->mDataSize) >= 0) {
                    Mem_CpuCopy8(slot->mData, dataCursor, slot->mDataSize);
                    usedSize = usedSize + slot->mDataSize;
                    dataCursor += slot->mDataSize;
                }
                break;
            case ITEM_DATA_SLOT_STATE_SENT:
                break;
        }
    }
    g_GlobalAA->mUnusedItemDataBytes = ITEM_DATA_BYTES - usedSize;
}

void ExpireItemDataSlots(void) {
    u16 slotIndex;
    ItemDataSlot *slot;

    for (slotIndex = 0; slotIndex < ITEM_DATA_SLOT_COUNT; slotIndex++) {
        slot = &g_GlobalAA->mItemDataSlots[slotIndex];
        if (slot->mItemKind == ITEM_DATA_KIND_NONE) {
            continue;
        }
        switch (slot->mState) {
            case ITEM_DATA_SLOT_STATE_FREE:
                break;
            case ITEM_DATA_SLOT_STATE_SENT:
                if (slot->mSendUntilSyncFrame + ITEM_DATA_SLOT_KEEP_FRAMES < (u32) g_GlobalAA->mSyncFrames) {
                    slot->mState = ITEM_DATA_SLOT_STATE_FREE;
                    slot->mSendUntilSyncFrame = 0;
                    slot->mItemKind = ITEM_DATA_KIND_NONE;
                    slot->mMessageKind = 0;
                    slot->mDataSize = 0;
                    Mem_CpuFill8(slot->mData, 0, ITEM_DATA_SLOT_BUFFER_SIZE);
                }
                break;
            case ITEM_DATA_SLOT_STATE_SENDING:
                if (slot->mSendUntilSyncFrame < (u32) g_GlobalAA->mSyncFrames) {
                    slot->mState = ITEM_DATA_SLOT_STATE_SENT;
                }
                break;
        }
    }
}

void StoreReceivedItemDataSlots(void) {
    u8 participantIndex;
    u16 slotIndex;
    u8 *headerCursor;
    u8 *dataCursor;
    ItemDataSlot *slot;
    u8 headerByte;

    for (participantIndex = 0; participantIndex < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participantIndex++) {
        if (participantIndex != DWC_GetMyAID() && BIT_IS_SET(g_GlobalAA->mParticipantMask, participantIndex) &&
            g_GlobalAA->mEntries[participantIndex].mRecordReceived != 0) {
            headerCursor = (u8 *) &g_GlobalAA->mEntries[participantIndex] + 0x28;
            dataCursor = headerCursor + ITEM_DATA_SLOT_COUNT;
            for (slotIndex = 0; slotIndex < ITEM_DATA_SLOT_COUNT; slotIndex++) {
                headerByte = *headerCursor++;
                slot = &g_GlobalAA->mReceivedItemDataSlots[slotIndex][participantIndex];
                slot->mItemKind = headerByte & ITEM_DATA_HEADER_KIND_MASK;
                slot->mMessageKind =
                    (headerByte & ITEM_DATA_HEADER_MESSAGE_KIND_MASK) >> ITEM_DATA_HEADER_MESSAGE_KIND_SHIFT;
                if (slot->mItemKind == ITEM_DATA_KIND_NONE) {
                    slot->mDataSize = 0;
                } else {
                    slot->mDataSize = GetItemDataSize(slot->mItemKind, slot->mMessageKind);
                }
                if (slot->mDataSize != 0) {
                    Mem_CpuCopy8(dataCursor, slot->mData, slot->mDataSize);
                    dataCursor += slot->mDataSize;
                }
            }
        }
    }
}

void ProcessOtherParticipantItemData(void) {
    u8 participantIndex;
    u16 slotIndex;
    WiFiRaceSync *wiFiRaceSync;
    ItemDataSlot *slot;
    u8 *handledFlag;
    u8 *data;

    for (participantIndex = 0; participantIndex < WIFI_RACE_SYNC_PARTICIPANT_COUNT; participantIndex++) {
        if (participantIndex != DWC_GetMyAID() && BIT_IS_SET(g_GlobalAA->mParticipantMask, participantIndex) &&
            g_GlobalAA->mEntries[participantIndex].mRecordReceived != 0) {
            for (slotIndex = 0; slotIndex < ITEM_DATA_SLOT_COUNT; slotIndex++) {
                wiFiRaceSync = g_GlobalAA;
                slot = &wiFiRaceSync->mReceivedItemDataSlots[slotIndex][participantIndex];
                handledFlag = &wiFiRaceSync->mItemDataHandled[slotIndex][participantIndex];
                if (slot->mItemKind == ITEM_DATA_KIND_NONE) {
                    *handledFlag = 0;
                } else if (*handledFlag == 0) {
                    data = NULL;
                    GetParticipantSyncFrames(participantIndex);
                    if (slot->mDataSize != 0) {
                        data = slot->mData;
                    }
                    if (slot->mMessageKind <= 1) {
                        ApplyParticipantPendingItem(participantIndex);
                    }
                    ProcessItemDataMessage(slot->mItemKind, slot->mMessageKind, data,
                                           g_GlobalRE->mKartOfParticipant[participantIndex]);
                    *handledFlag = 1;
                }
            }
        }
    }
}

void UpdateItemDataSlots(void) {
    ExpireItemDataSlots();
    WriteItemDataSlotsToSendBuffer();
    StoreReceivedItemDataSlots();
    ProcessOtherParticipantItemData();
}
