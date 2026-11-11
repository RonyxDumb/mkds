#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0211d4a8.h"

#pragma opt_rebuildconditionals off

static inline u32 ScanSlotGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

u32 TrySelectScanSlot(u32 entryIndex) {
    u32 result = 0;
    ScanSlot *entry;
    ConnectionWork *connectionWork;
    u32 entryValid;

    if (entryIndex >= 4) {
        return 0;
    }
    if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        entryValid = result;
        if (ScanSlotGetConnectionMode() != 2) {
            entryValid = 0;
        } else if (gBootInfo->mBootType == 2) {
            entryValid = 0;
        } else if (gConnectionWork->mScanSlots[entryIndex].mInUse != 0) {
            entryValid = 1;
        }
        if (entryValid != 0) {
            StartRequestEndScan();
            result = 1;
        }
    } else {
        gConnectionWork->mKeepScanning = 0;
        gConnectionWork->mUnk_0438 = 0;
        entry = &gConnectionWork->mScanSlots[entryIndex];
        gConnectionWork->mOperationFlags &= ~CONNECTION_OPERATION_SCANNING;
        if (entry->mInUse != 0) {
            MI_CpuCopy8(entry, gConnectionWork->mParentBssDesc, 0xc0);
            DC_StoreRange(gConnectionWork->mParentBssDesc, 0xc0);
            connectionWork = gConnectionWork;
            connectionWork->mRememberedScanKey = entry->mKey;
            connectionWork->mLanguageIndex = entry->mLanguageIndex;
            result = 1;
        }
    }
    return result;
}

void RefreshParticipantTables(void) {
    BOOL proceed;
    u16 index;
    u16 participantCount;

    proceed = FALSE;
    if (ScanSlotGetConnectionMode() != 0 && gConnectionWork->mState != 13) {
        proceed = TRUE;
    }
    if (proceed == FALSE) {
        return;
    }
    index = 0;
    participantCount = 0;
    for (; index < 8; index++) {
        if ((gConnectionWork->mParticipantMask & (1 << index)) != 0) {
            gConnectionWork->mParticipantPosByIndex[index].mEntryIndex = participantCount;
            gConnectionWork->mParticipantIndexByPos[participantCount] = index;
            gConnectionWork->mParticipantIndices[participantCount] = index;
            participantCount++;
        } else {
            gConnectionWork->mParticipantPosByIndex[index].mEntryIndex = 0xffff;
        }
    }
    for (; participantCount < 8; participantCount++) {
        gConnectionWork->mParticipantIndexByPos[participantCount] = 0xffff;
        gConnectionWork->mParticipantIndices[participantCount] = 0xffff;
    }
    if (GetCurrentSceneNumber() == 2) {
        ResetInputSlotsFromRaceSetup();
    } else {
        ResetInputSlotsFromParticipants();
    }
}
