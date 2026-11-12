#include "Main/Unknown/code_0205a534.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_0219b580.h"
#include "code_0214d018.h"

void AddItemData(u32 itemKind, u32 messageKind, void *data, u8 size) {
    ItemDataSlot *slot;
    u16 slotIndex;

    for (slotIndex = 0; slotIndex < ITEM_DATA_SLOT_COUNT; slotIndex++) {
        slot = &gWiFiRaceSync->mItemDataSlots[slotIndex];
        if (slot->mState == ITEM_DATA_SLOT_STATE_FREE) {
            goto found;
        }
    }
    slot = NULL;
found:
    slot->mItemKind = itemKind;
    slot->mMessageKind = messageKind;
    slot->mState = ITEM_DATA_SLOT_STATE_SENDING;
    slot->mSendUntilSyncFrame = gWiFiRaceSync->mSyncFrames + ITEM_DATA_SLOT_SEND_FRAMES;
    MI_CpuFill8(slot->mData, 0, ITEM_DATA_SLOT_BUFFER_SIZE);
    if (size == 0) {
        slot->mDataSize = 0;
        return;
    }
    MI_CpuCopy8(data, slot->mData, size);
    slot->mDataSize = size;
}

void SetSendSlotResultSync(s32 participantIndex, u16 remaining, s32 itemIndex, s32 state) {
    SlotResultSyncHalfword *entry;

    entry = &((WiFiRaceSyncRecord *) (void *) &gWiFiRaceSync->mSendBuffer->mRecord)->mSlotResultSyncs[participantIndex];
    entry->mFramesRemaining = remaining;
    entry->mItemInfoIndex = itemIndex;
    entry->mState = state;
}

void ClearSendSlotResultSync(s32 participantIndex) {
    WiFiRaceSyncRecord *payload = (void *) &gWiFiRaceSync->mSendBuffer->mRecord;
    MI_CpuFill8(&payload->mSlotResultSyncs[participantIndex], 0, 2);
}

void StartOwnSlotResultSync(s32 itemIndex) {
    SlotResultSyncState *view;
    s32 syncFrames;

    view = &gWiFiRaceSync->mEntries[DWC_GetMyAID()].mSlotResultSyncState;
    view->mSendCount = 0;
    syncFrames = gWiFiRaceSync->mSyncFrames;
    view->mState = SLOT_RESULT_SYNC_STATE_SENDING;
    view->mItemInfoIndex = itemIndex;
    view->mEndSyncFrame = syncFrames + SLOT_RESULT_SYNC_SEND_FRAMES;
    view->mPendingItemInfoIndex = SLOT_RESULT_SYNC_NO_ITEM;
}

void StartParticipantResultPending(s32 participantIndex) {
    StartItemSlotResultPending(&gKartItems[(u8) gParticipantKartMap->mKartOfParticipant[participantIndex]]);
}

void InitSlotResultSyncStates(void) {
    u16 participantIndex;
    SlotResultSyncState *view;

    for (participantIndex = 0; participantIndex < WIFI_RACE_SYNC_PARTICIPANT_COUNT;) {
        view = &gWiFiRaceSync->mEntries[participantIndex].mSlotResultSyncState;
        participantIndex++;
        view->mItemInfoIndex = SLOT_RESULT_SYNC_NO_ITEM;
        view->mPendingItemInfoIndex = SLOT_RESULT_SYNC_NO_ITEM;
        view->mEndSyncFrame = 0;
        view->mState = SLOT_RESULT_SYNC_STATE_IDLE;
        view->mUnk_10 = SLOT_RESULT_SYNC_NO_ITEM;
        view->mUnk_14 = 0;
    }
}

BOOL ApplyParticipantPendingItem(s32 participantIndex) {
    BOOL result;
    s32 itemInfoIndex;

    itemInfoIndex = gWiFiRaceSync->mEntries[participantIndex].mPendingItemInfoIndex;
    result = FALSE;
    if (SetKartItemsHeldItemByInfoIndex(&gKartItems[(u8) gParticipantKartMap->mKartOfParticipant[participantIndex]],
                                        itemInfoIndex) != FALSE) {
        gWiFiRaceSync->mEntries[participantIndex].mPendingItemInfoIndex = SLOT_RESULT_SYNC_NO_ITEM;
        result = TRUE;
    }
    return result;
}

void ResetParticipantHeldItem(u32 participantIndex) {
    SlotResultSyncState *view;

    view = &gWiFiRaceSync->mEntries[participantIndex].mSlotResultSyncState;
    if (view->mState != SLOT_RESULT_SYNC_STATE_IDLE) {
        return;
    }
    view->mPendingItemInfoIndex = SLOT_RESULT_SYNC_NO_ITEM;
    ResetHeldItem(&GetKartItems(gParticipantKartMap->mKartOfParticipant[participantIndex])->mHeldItem);
}

void SetParticipantHeldItem(s32 participantIndex, s32 itemInfoIndex, s32 count) {
    SlotResultSyncState *view;

    view = &gWiFiRaceSync->mEntries[participantIndex].mSlotResultSyncState;
    view->mItemInfoIndex = itemInfoIndex;
    view->mPendingItemInfoIndex = itemInfoIndex;
    SetHeldItemWithCount(&GetKartItems(gParticipantKartMap->mKartOfParticipant[participantIndex])->mHeldItem,
                         itemInfoIndex, count);
}

void CopySlotResultToPending(SlotResultSyncState *syncState) {
    syncState->mPendingItemInfoIndex = (u32) (((u32) syncState->mItemInfoIndex));
    syncState->mState = SLOT_RESULT_SYNC_STATE_WAIT_FOR_END;
}
