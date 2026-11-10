#include "Main/Unknown/code_0205a92c.h"
#include "Main/Unknown/code_0205a548.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020fe4b4.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_0219b580.h"
#include "code_0214d018.h"

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

    participantKartMap = gParticipantKartMap;
    wiFiRaceSync = gWiFiRaceSync;
    participantIndex = participantKartMap->mParticipantOfKart[(u8) kartIndex];
    rank = wiFiRaceSync->mEntries[participantIndex].mRank;
    if (participantIndex < 0) {
        return;
    }
    otherKartIndex = 0;
    for (otherKartIndex = 0; otherKartIndex < (s32) gRaceSetup->mKartCount; otherKartIndex++) {
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

    for (slotIndex = 0; slotIndex < 16; slotIndex++) {
        for (participantIndex = 0; participantIndex < 4; participantIndex++) {
            slot = &gWiFiRaceSync->mReceivedItemDataSlots[slotIndex][participantIndex];
            slot->mState = 0;
            slot->mSendUntilSyncFrame = 0;
            slot->mItemKind = 15;
            slot->mMessageKind = 0;
            slot->mDataSize = 0;
            MI_CpuFill8(slot->mData, 0, 20);
            gWiFiRaceSync->mItemDataHandled[slotIndex][participantIndex] = 0;
        }
        slot = &gWiFiRaceSync->mItemDataSlots[slotIndex];
        slot->mState = 0;
        slot->mSendUntilSyncFrame = 0;
        slot->mItemKind = 15;
        slot->mMessageKind = 0;
        slot->mDataSize = 0;
        MI_CpuFill8(slot->mData, 0, 20);
    }
    gWiFiRaceSync->mUnusedItemDataBytes = 0x30;
}

BOOL IsAnyItemDataSlotFree(void) {
    u16 slotIndex;

    for (slotIndex = 0; slotIndex < 16; slotIndex++) {
        if (gWiFiRaceSync->mItemDataSlots[slotIndex].mState == 0) {
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
    payload = (void *) &gWiFiRaceSync->mSendBuffer->mUnk_04;
    headerCursor = payload->mItemDataHeaders;
    dataCursor = headerCursor + 16;
    for (slotIndex = 0; slotIndex < 16; slotIndex++) {
        slot = &gWiFiRaceSync->mItemDataSlots[slotIndex];
        if (slot->mState == 0 || slot->mState == 2 || slot->mItemKind == 15) {
            headerByte = 15;
        } else {
            headerByte = (slot->mItemKind & 0x1f) | ((slot->mMessageKind << 5) & 0xe0);
        }
        *headerCursor++ = headerByte;
        switch (slot->mState) {
            case 0:
                break;
            case 1:
                if (slot->mDataSize != 0 && 0x30 - (usedSize + slot->mDataSize) >= 0) {
                    MI_CpuCopy8(slot->mData, dataCursor, slot->mDataSize);
                    usedSize = usedSize + slot->mDataSize;
                    dataCursor += slot->mDataSize;
                }
                break;
            case 2:
                break;
        }
    }
    gWiFiRaceSync->mUnusedItemDataBytes = 0x30 - usedSize;
}

void ExpireItemDataSlots(void) {
    u16 slotIndex;
    ItemDataSlot *slot;

    for (slotIndex = 0; slotIndex < 16; slotIndex++) {
        slot = &gWiFiRaceSync->mItemDataSlots[slotIndex];
        if (slot->mItemKind == 15) {
            continue;
        }
        switch (slot->mState) {
            case 0:
                break;
            case 2:
                if (slot->mSendUntilSyncFrame + 30 < (u32) gWiFiRaceSync->mSyncFrames) {
                    slot->mState = 0;
                    slot->mSendUntilSyncFrame = 0;
                    slot->mItemKind = 15;
                    slot->mMessageKind = 0;
                    slot->mDataSize = 0;
                    MI_CpuFill8(slot->mData, 0, 20);
                }
                break;
            case 1:
                if (slot->mSendUntilSyncFrame < (u32) gWiFiRaceSync->mSyncFrames) {
                    slot->mState = 2;
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

    for (participantIndex = 0; participantIndex < 4; participantIndex++) {
        if (participantIndex != GetOwnParticipantIndex() &&
            (gWiFiRaceSync->mParticipantMask & (1 << participantIndex)) != 0 &&
            gWiFiRaceSync->mEntries[participantIndex].mUnk_86_0 != 0) {
            headerCursor = (u8 *) &gWiFiRaceSync->mEntries[participantIndex] + 0x28;
            dataCursor = headerCursor + 16;
            for (slotIndex = 0; slotIndex < 16; slotIndex++) {
                headerByte = *headerCursor++;
                slot = &gWiFiRaceSync->mReceivedItemDataSlots[slotIndex][participantIndex];
                slot->mItemKind = headerByte & 0x1f;
                slot->mMessageKind = (headerByte & 0xe0) >> 5;
                if (slot->mItemKind == 15) {
                    slot->mDataSize = 0;
                } else {
                    slot->mDataSize = GetItemDataSize(slot->mItemKind, slot->mMessageKind);
                }
                if (slot->mDataSize != 0) {
                    MI_CpuCopy8(dataCursor, slot->mData, slot->mDataSize);
                    dataCursor += slot->mDataSize;
                }
            }
        }
    }
}

void ProcessOtherParticipantItemData(void) {
    u8 participantIndex;
    u16 slotIndex;
    WiFiRaceSync *p;
    ItemDataSlot *slot;
    u8 *handledFlag;
    u8 *data;

    for (participantIndex = 0; participantIndex < 4; participantIndex++) {
        if (participantIndex != GetOwnParticipantIndex() &&
            (gWiFiRaceSync->mParticipantMask & (1 << participantIndex)) != 0 &&
            gWiFiRaceSync->mEntries[participantIndex].mUnk_86_0 != 0) {
            for (slotIndex = 0; slotIndex < 16; slotIndex++) {
                p = gWiFiRaceSync;
                slot = &p->mReceivedItemDataSlots[slotIndex][participantIndex];
                handledFlag = &p->mItemDataHandled[slotIndex][participantIndex];
                if (slot->mItemKind == 15) {
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
                                           gParticipantKartMap->mKartOfParticipant[participantIndex]);
                    *handledFlag = 1;
                }
            }
        }
    }
}
