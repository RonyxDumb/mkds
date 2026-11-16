#include "Main/Net/scan_slot.h"
#include "Main/Race/race_keys.h"
#include "thread_scheduler.h"
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
    if (g_GlobalZE == NULL) {
        return 0;
    }
    return g_GlobalZE->mConnectionMode;
}

u32 TrySelectScanSlot(u32 entryIndex) {
    u32 result = 0;
    ScanSlot *entry;
    ConnectionWork *connectionWork;
    u32 entryValid;

    if (entryIndex >= 4) {
        return 0;
    }
    if ((g_GlobalZE->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
        entryValid = result;
        if (ScanSlotGetConnectionMode() != CONNECTION_MODE_CHILD) {
            entryValid = 0;
        } else if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
            entryValid = 0;
        } else if (g_GlobalZE->mScanSlots[entryIndex].mInUse != 0) {
            entryValid = 1;
        }
        if (entryValid != 0) {
            StartRequestEndScan();
            result = 1;
        }
    } else {
        g_GlobalZE->mKeepScanning = 0;
        g_GlobalZE->mRememberedScanKeyHeld = 0;
        entry = &g_GlobalZE->mScanSlots[entryIndex];
        g_GlobalZE->mOperationFlags &= ~CONNECTION_OPERATION_SCANNING;
        if (entry->mInUse != 0) {
            Mem_CpuCopy8(entry, g_GlobalZE->mParentBssDesc, sizeof(WMBssDesc));
            DC_SomeClean(g_GlobalZE->mParentBssDesc, 0xc0);
            connectionWork = g_GlobalZE;
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
    if (ScanSlotGetConnectionMode() != CONNECTION_MODE_NONE && g_GlobalZE->mState != CONNECTION_STATE_ENDED) {
        proceed = TRUE;
    }
    if (proceed == FALSE) {
        return;
    }
    index = 0;
    participantCount = 0;
    for (; index < 8; index++) {
        if (BIT_IS_SET(g_GlobalZE->mParticipantMask, index)) {
            g_GlobalZE->mParticipantPosByIndex[index].mEntryIndex = participantCount;
            g_GlobalZE->mParticipantIndexByPos[participantCount] = index;
            g_GlobalZE->mParticipantIndices[participantCount] = index;
            participantCount++;
        } else {
            g_GlobalZE->mParticipantPosByIndex[index].mEntryIndex = PARTICIPANT_POSITION_NONE;
        }
    }
    for (; participantCount < 8; participantCount++) {
        g_GlobalZE->mParticipantIndexByPos[participantCount] = PARTICIPANT_POSITION_NONE;
        g_GlobalZE->mParticipantIndices[participantCount] = PARTICIPANT_POSITION_NONE;
    }
    if (GetCurrentSceneId() == 2) {
        ResetInputSlotsFromRaceSetup();
    } else {
        ResetInputSlotsFromParticipants();
    }
}
