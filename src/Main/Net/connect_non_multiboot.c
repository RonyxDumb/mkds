#include "Main/Net/connect_non_multiboot.h"
#include "bios_calls.h"
#include "Main/Net/multiboot_parent_finish.h"
#include "Main/Net/multiboot_connect.h"
#include "Main/Net/packet_port.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Net/block.h"
#include "Main/Net/scan_ghost_info.h"
#include "Main/Net/scan_slot.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/scan.h"
#include "Main/Net/connection.h"
#include "Main/Net/non_multiboot_own_index.h"
#include "Main/Net/participant_bits.h"
#include "Main/Net/mp_chunk_state_machine.h"
#include "Main/Menu/select_race_rule_state.h"

static inline u32 ConnectGetConnectionMode(void) {
    if (g_GlobalZE == NULL) {
        return 0;
    }
    return g_GlobalZE->mConnectionMode;
}

static inline s32 ConnectIsConnectionActive(void) {
    BOOL result = FALSE;
    if (ConnectGetConnectionMode() != CONNECTION_MODE_NONE && g_GlobalZE->mState != CONNECTION_STATE_ENDED) {
        result = TRUE;
    }
    return result;
}

static inline s32 ConnectIsConnectionActiveNotEnding(void) {
    BOOL result = FALSE;
    if (ConnectIsConnectionActive() && !(g_GlobalZE->mFlags & CONNECTION_FLAG_ENDING)) {
        result = TRUE;
    }
    return result;
}

static inline s32 ConnectIsConnectionActiveNotEndingWithError(void) {
    BOOL result = FALSE;
    if (ConnectIsConnectionActiveNotEnding() && g_GlobalZE->mErrorCode != CONNECTION_ERROR_NONE) {
        result = TRUE;
    }
    return result;
}

s32 AdvanceNonMultiBootConnect(s32 entryIndex) {
    s32 status;

    status = 0;
    if (g_GlobalZE->mRequestPending != 0) {
        if (g_GlobalZE->mStep == CONNECTION_STEP_SEARCHING && g_GlobalZE->mKeepScanning == 1) {
            if (TrySelectScanSlot(entryIndex) == 0) {
                SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
            }
        }
        return 0;
    }
    if (ConnectIsConnectionActiveNotEndingWithError()) {
        return 3;
    }
    switch (g_GlobalZE->mStep) {
        case CONNECTION_STEP_SEARCHING:
            EndScan();
            break;
        case CONNECTION_STEP_STOPPING_SEARCH:
            StartConnect(NULL, NULL, NULL, NonMultiBootResetOwnIndex, NULL);
            break;
        case CONNECTION_STEP_RESTARTING:
        case CONNECTION_STEP_JOINING:
            if (g_GlobalZE->mOwnIndex == CONNECTION_OWN_INDEX_NONE) {
                if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                    SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
                    return 3;
                }
                status = 2;
            } else {
                StartMP();
            }
            break;
        case CONNECTION_STEP_STARTING_EXCHANGE:
            g_GlobalZE->mState = CONNECTION_STATE_CONNECTED;
            InitMPStateMachine();
            status = 1;
            break;
    }
    return status;
}

s32 AdvanceGameInfoOnChildChange(void) {
    if (g_GlobalZE->mRequestPending != 0) {
        return 0;
    }
    switch (g_GlobalZE->mStep) {
        case CONNECTION_STEP_STARTING_EXCHANGE:
            if (g_GlobalZE->mStatusFlags & CONNECTION_STATUS_CHILDREN_CHANGED) {
                SetGameInfo();
            }
            break;
        case CONNECTION_STEP_PUBLISHING_GAME_INFO:
            g_GlobalZE->mStatusFlags &= ~CONNECTION_STATUS_CHILDREN_CHANGED;
            g_GlobalZE->mStep = CONNECTION_STEP_STARTING_EXCHANGE;
            break;
    }
    return 0;
}

void AdvanceConnection(void) {
    u8 participantMask;
    u8 childMask;
    u8 participantIndex;

    if (!ConnectIsConnectionActive()) {
        return;
    }
    switch (g_GlobalZE->mState) {
        case CONNECTION_STATE_SYNC_WAIT:
        case CONNECTION_STATE_SYNCED:
        case CONNECTION_STATE_SYNCED_RACE:
            if (UpdateDataSharing() == FALSE) {
                g_GlobalZE->mFlags |= CONNECTION_FLAG_SHARING_NOT_UPDATED;
            }
            if (g_GlobalZE->mState != CONNECTION_STATE_SYNCED_RACE) {
                return;
            }
            if (ConnectGetConnectionMode() != CONNECTION_MODE_PARENT) {
                return;
            }
            DisconnectRemovedChildren();
            break;
        case CONNECTION_STATE_MULTIBOOT_PARENT_READY:
            childMask = g_GlobalZE->mChildren.mChildMask;
            participantMask = childMask | 1;
            if (g_GlobalZE->mChildren.mNameSendIndex >= CHILD_LIST_NAME_SEND_PAUSE_FIRST) {
                g_GlobalZE->mChildren.mNameSendIndex++;
                if ((s32) g_GlobalZE->mChildren.mNameSendIndex > CHILD_LIST_NAME_SEND_PAUSE_LAST) {
                    g_GlobalZE->mChildren.mNameSendIndex = 0;
                }
                return;
            }
            participantIndex = g_GlobalZE->mChildren.mNameSendIndex % 8;
            if (participantMask & (1 << participantIndex)) {
                if (QueueMPDataPlayerName(participantIndex, childMask) == FALSE) {
                    return;
                }
                g_GlobalZE->mChildren.mNameSendIndex++;
            } else {
                g_GlobalZE->mChildren.mNameSendIndex++;
            }
            break;
    }
}

s32 AdvanceConnectionEnd(void) {
    BOOL finished;

    finished = FALSE;
    if (g_GlobalZE->mState == CONNECTION_STATE_IDLE) {
        g_GlobalZE->mFlags &= ~CONNECTION_FLAG_ENDING;
        return 1;
    }
    switch (g_GlobalZE->mStep) {
        case CONNECTION_STEP_SCAN_CONNECT_REPEATED_SCAN:
        case CONNECTION_STEP_SCAN_CONNECT_FIND_ENTRY:
            StartRequestEndScan();
            break;
        case CONNECTION_STEP_SCAN_CONNECT_CONNECT_ENTRY:
            StructZE_StateFn_28_29_30_33_34_35_from_thumb();
            break;
        case CONNECTION_STEP_MULTIBOOT_START_PARENT:
        case CONNECTION_STEP_MULTIBOOT_UNUSED:
        case CONNECTION_STEP_MULTIBOOT_SEND_TO_CHILDREN:
        case CONNECTION_STEP_MULTIBOOT_BOOT_REQUEST:
        case CONNECTION_STEP_CHILD_ARCHIVE_SYNC:
        case CONNECTION_STEP_PARENT_BLOCK_TRANSFER:
        case CONNECTION_STEP_CHILD_BLOCK_TRANSFER:
        case CONNECTION_STEP_BLOCK_COUNT_REQUEST:
        case CONNECTION_STEP_BLOCK_NODE_REQUEST:
        case CONNECTION_STEP_BLOCK_DATA_REQUEST:
        case CONNECTION_STEP_SEND_WORD_REQUEST:
            g_GlobalZE->mRequestPending = 0;
            break;
    }
    if (g_GlobalZE->mRequestPending != 0 && g_GlobalZE->mStep == CONNECTION_STEP_SEARCHING &&
        g_GlobalZE->mKeepScanning == 1) {
        g_GlobalZE->mKeepScanning = 0;
    }
    if (g_GlobalZE->mRequestPending != 0) {
        return 0;
    }
    if (ConnectIsConnectionActiveNotEndingWithError()) {
        return 3;
    }
    switch (g_GlobalZE->mStep) {
        case CONNECTION_STEP_ROM_ARCHIVE_STOP:
            End();
            break;
        case CONNECTION_STEP_SHUTTING_DOWN:
            g_GlobalZE->mStep = CONNECTION_STEP_NOTHING;
            break;
        case CONNECTION_STEP_NOTHING:
            CleanSaveDataHolderFlagBytes_from_thumb();
            g_GlobalZE->mState = CONNECTION_STATE_IDLE;
            finished = TRUE;
            g_GlobalZE->mFlags &= ~CONNECTION_FLAG_ENDING;
            break;
        case CONNECTION_STEP_STARTING_UP:
        case CONNECTION_STEP_RESTARTING:
        case CONNECTION_STEP_SETTING_TIMEOUT:
        case CONNECTION_STEP_CHECKING_CHANNELS:
        case CONNECTION_STEP_CONFIGURING_HOST:
        case CONNECTION_STEP_STOPPING_SEARCH:
        case CONNECTION_STEP_CLOSING_HOST:
        case CONNECTION_STEP_LEAVING:
        case CONNECTION_STEP_MULTIBOOT_END_TO_IDLE:
        case CONNECTION_STEP_SCAN_CONNECT_CLOSE:
        case CONNECTION_STEP_SCAN_CONNECT_CLOSED:
        case CONNECTION_STEP_ROM_ARCHIVE_TRANSFER:
            StopRomArchiveTransfer();
            break;
        case CONNECTION_STEP_SEARCHING:
        case CONNECTION_STEP_SEARCHING_UNUSED:
            EndScan();
            break;
        case CONNECTION_STEP_STARTING_EXCHANGE:
        case CONNECTION_STEP_SETTING_EXCHANGE_RATE:
        case CONNECTION_STEP_REGISTERING_ENTRY:
        case CONNECTION_STEP_STOPPING_SHARING:
            EndMP();
            break;
        case CONNECTION_STEP_OPENING_HOST:
        case CONNECTION_STEP_JOINING:
        case CONNECTION_STEP_DROPPING_CHILDREN:
        case CONNECTION_STEP_STOPPING_EXCHANGE:
            switch (ConnectGetConnectionMode()) {
                case CONNECTION_MODE_PARENT:
                    EndParent();
                    break;
                case CONNECTION_MODE_CHILD:
                    Disconnect();
                    break;
            }
            break;
        case CONNECTION_STEP_STARTING_SHARING:
        case CONNECTION_STEP_PUBLISHING_GAME_INFO:
        case CONNECTION_STEP_ROM_ARCHIVE_SEND:
            EndDataSharing();
            break;
        case CONNECTION_STEP_MULTIBOOT_START_PARENT:
        case CONNECTION_STEP_MULTIBOOT_UNUSED:
        case CONNECTION_STEP_MULTIBOOT_SEND_TO_CHILDREN:
        case CONNECTION_STEP_MULTIBOOT_BOOT_REQUEST:
            StructZE_StateFn22_23_24_25_from_thumb();
            break;
        case CONNECTION_STEP_SCAN_CONNECT_SETUP:
        case CONNECTION_STEP_SCAN_CONNECT_REPEATED_SCAN:
        case CONNECTION_STEP_SCAN_CONNECT_FIND_ENTRY:
        case CONNECTION_STEP_SCAN_CONNECT_END_SCAN:
        case CONNECTION_STEP_SCAN_CONNECT_CONNECT_ENTRY:
        case CONNECTION_STEP_SCAN_CONNECT_READ_PARENT_DESC:
            StructZE_StateFn_28_29_30_33_34_35_from_thumb();
            break;
        case CONNECTION_STEP_CHILD_ARCHIVE_SYNC:
        case CONNECTION_STEP_PARENT_BLOCK_TRANSFER:
        case CONNECTION_STEP_CHILD_BLOCK_TRANSFER:
        case CONNECTION_STEP_BLOCK_COUNT_REQUEST:
        case CONNECTION_STEP_BLOCK_NODE_REQUEST:
        case CONNECTION_STEP_BLOCK_DATA_REQUEST:
        case CONNECTION_STEP_SEND_WORD_REQUEST:
            EndWbtStep();
            break;
        case CONNECTION_STEP_STOPPING_BLOCK_TRANSFER:
            EndMP();
            break;
        default:
            StopConnection();
            break;
    }
    return finished;
}

s32 AdvanceConnectionEndStopOnError(void) {
    s32 status;
    s32 result;

    status = 0;
    result = AdvanceConnectionEnd();
    if (result == 3) {
        switch (g_GlobalZE->mStep) {
            case CONNECTION_STEP_MULTIBOOT_START_PARENT:
            case CONNECTION_STEP_MULTIBOOT_UNUSED:
            case CONNECTION_STEP_MULTIBOOT_SEND_TO_CHILDREN:
            case CONNECTION_STEP_MULTIBOOT_BOOT_REQUEST:
                StructZE_StateFn22_23_24_25_from_thumb();
                break;
            case CONNECTION_STEP_CHILD_ARCHIVE_SYNC:
            case CONNECTION_STEP_PARENT_BLOCK_TRANSFER:
            case CONNECTION_STEP_CHILD_BLOCK_TRANSFER:
            case CONNECTION_STEP_BLOCK_COUNT_REQUEST:
            case CONNECTION_STEP_BLOCK_NODE_REQUEST:
            case CONNECTION_STEP_BLOCK_DATA_REQUEST:
            case CONNECTION_STEP_SEND_WORD_REQUEST:
                EndWbtStep();
                break;
            case CONNECTION_STEP_SCAN_CONNECT_SETUP:
            case CONNECTION_STEP_SCAN_CONNECT_REPEATED_SCAN:
            case CONNECTION_STEP_SCAN_CONNECT_FIND_ENTRY:
            case CONNECTION_STEP_SCAN_CONNECT_END_SCAN:
            case CONNECTION_STEP_SCAN_CONNECT_CONNECT_ENTRY:
            case CONNECTION_STEP_SCAN_CONNECT_READ_PARENT_DESC:
                StructZE_StateFn_28_29_30_33_34_35_from_thumb();
                break;
            default:
                StopConnection();
                break;
        }
        g_GlobalZE->mErrorCode = CONNECTION_ERROR_NONE;
    } else {
        status = result;
    }
    return status;
}
