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

    for (slotIndex = 0; slotIndex < 16; slotIndex++) {
        slot = &gWiFiRaceSync->mItemDataSlots[slotIndex];
        if (slot->mState == 0) {
            goto found;
        }
    }
    slot = NULL;
found:
    slot->mItemKind = itemKind;
    slot->mMessageKind = messageKind;
    slot->mState = 1;
    slot->mSendUntilSyncFrame = gWiFiRaceSync->mSyncFrames + 0x28;
    MI_CpuFill8(slot->mData, 0, 20);
    if (size == 0) {
        slot->mDataSize = 0;
        return;
    }
    MI_CpuCopy8(data, slot->mData, size);
    slot->mDataSize = size;
}

void SetSendSlotResultSync(s32 participantIndex, u16 remaining, s32 itemIndex, s32 state) {
    SlotResultSyncHalfword *entry;

    entry = &((WiFiRaceSyncRecord *) (void *) &gWiFiRaceSync->mSendBuffer->mUnk_04)->mSlotResultSyncs[participantIndex];
    entry->mFramesRemaining = remaining;
    entry->mItemInfoIndex = itemIndex;
    entry->mState = state;
}

void ClearSendSlotResultSync(s32 participantIndex) {
    WiFiRaceSyncRecord *payload = (void *) &gWiFiRaceSync->mSendBuffer->mUnk_04;
    MI_CpuFill8(&payload->mSlotResultSyncs[participantIndex], 0, 2);
}

void StartOwnSlotResultSync(s32 itemIndex) {
    SlotResultSyncState *view;
    s32 syncFrames;

    view = &gWiFiRaceSync->mEntries[GetOwnParticipantIndex()].mUnk_68_view;
    view->mSendCount = 0;
    syncFrames = gWiFiRaceSync->mSyncFrames;
    view->mState = 2;
    view->mItemInfoIndex = itemIndex;
    view->mEndSyncFrame = syncFrames + 0x78;
    view->mPendingItemInfoIndex = 0x13;
}

void StartParticipantResultPending(s32 participantIndex) {
    StartItemSlotResultPending(&gKartItems[(u8) gParticipantKartMap->mKartOfParticipant[participantIndex]]);
}

void InitSlotResultSyncStates(void) {
    u16 participantIndex;
    SlotResultSyncState *view;

    for (participantIndex = 0; participantIndex < 4;) {
        view = &gWiFiRaceSync->mEntries[participantIndex].mUnk_68_view;
        participantIndex++;
        view->mItemInfoIndex = 0x13;
        view->mPendingItemInfoIndex = 0x13;
        view->mEndSyncFrame = 0;
        view->mState = 0;
        view->mUnk_10 = 0x13;
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
        gWiFiRaceSync->mEntries[participantIndex].mPendingItemInfoIndex = 0x13;
        result = TRUE;
    }
    return result;
}

void ResetParticipantHeldItem(u32 participantIndex) {
    SlotResultSyncState *view;

    view = &gWiFiRaceSync->mEntries[participantIndex].mUnk_68_view;
    if (view->mState != 0) {
        return;
    }
    view->mPendingItemInfoIndex = 0x13;
    ResetHeldItem(&gKartItems[(u16) gParticipantKartMap->mKartOfParticipant[participantIndex]].mHeldItem);
}

void SetParticipantHeldItem(s32 participantIndex, s32 itemInfoIndex, s32 count) {
    SlotResultSyncState *view;

    view = &gWiFiRaceSync->mEntries[participantIndex].mUnk_68_view;
    view->mItemInfoIndex = itemInfoIndex;
    view->mPendingItemInfoIndex = itemInfoIndex;
    SetHeldItemWithCount(&gKartItems[(u16) gParticipantKartMap->mKartOfParticipant[participantIndex]].mHeldItem,
                         itemInfoIndex, count);
}
