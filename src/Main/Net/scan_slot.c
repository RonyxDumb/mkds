#include "Main/Net/scan_slot.h"
#include "Main/Race/race_keys.h"
#include "os_thread.h"
#include "Main/Net/multiboot_connect.h"
#include "Main/Net/packet_port.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Net/block.h"
#include "Main/Net/scan_ghost_info.h"
#include "Main/Scene/run_scenes.h"
#include "arena_cache_init.h"
#include "cpu_copy_fill.h"
#include "Main/Menu/select_race_rule_state.h"

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
        if (ScanSlotGetConnectionMode() != CONNECTION_MODE_CHILD) {
            entryValid = 0;
        } else if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
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
        gConnectionWork->mRememberedScanKeyHeld = 0;
        entry = &gConnectionWork->mScanSlots[entryIndex];
        gConnectionWork->mOperationFlags &= ~CONNECTION_OPERATION_SCANNING;
        if (entry->mInUse != 0) {
            MI_CpuCopy8(entry, gConnectionWork->mParentBssDesc, sizeof(WMBssDesc));
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
    if (ScanSlotGetConnectionMode() != CONNECTION_MODE_NONE && gConnectionWork->mState != CONNECTION_STATE_ENDED) {
        proceed = TRUE;
    }
    if (proceed == FALSE) {
        return;
    }
    index = 0;
    participantCount = 0;
    for (; index < 8; index++) {
        if (BIT_IS_SET(gConnectionWork->mParticipantMask, index)) {
            gConnectionWork->mParticipantPosByIndex[index].mEntryIndex = participantCount;
            gConnectionWork->mParticipantIndexByPos[participantCount] = index;
            gConnectionWork->mParticipantIndices[participantCount] = index;
            participantCount++;
        } else {
            gConnectionWork->mParticipantPosByIndex[index].mEntryIndex = PARTICIPANT_POSITION_NONE;
        }
    }
    for (; participantCount < 8; participantCount++) {
        gConnectionWork->mParticipantIndexByPos[participantCount] = PARTICIPANT_POSITION_NONE;
        gConnectionWork->mParticipantIndices[participantCount] = PARTICIPANT_POSITION_NONE;
    }
    if (GetCurrentSceneNumber() == 2) {
        ResetInputSlotsFromRaceSetup();
    } else {
        ResetInputSlotsFromParticipants();
    }
}
