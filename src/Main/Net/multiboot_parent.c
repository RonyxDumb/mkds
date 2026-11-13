#include "Main/Net/multiboot_parent.h"
#include "Main/Net/participant_get_connection.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/scan_slot.h"
#include "Main/Net/connect_failed_callback.h"
#include "Main/Net/multiboot_connect.h"
#include "Main/Net/packet_port.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Net/block.h"
#include "Main/Net/scan_ghost_info.h"
#include "Main/Net/scan.h"
#include "Main/Net/connection.h"
#include "Main/Net/mp_chunk_state_machine.h"
#include "code_0214d018.h"
#include "Main/Menu/select_race_rule_state.h"

#pragma thumb on

s32 AdvanceScanConnect(u16 entryIndex) {
    s32 result = 0;
    ConnectionWork *connectionWork = gConnectionWork;

    switch (connectionWork->mStep) {
        case CONNECTION_STEP_SCAN_CONNECT_REPEATED_SCAN:
            if (TrySelectScanSlot(entryIndex) == 0) {
                SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
            }
            if (TryGetScanSlotName(entryIndex, NULL) != 0) {
                StartRequestEndScan();
            } else {
                SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
            }
            break;
        case CONNECTION_STEP_JOINING:
            connectionWork->mStepWaitFrames = connectionWork->mStepWaitFrames + 1;
            if (gConnectionWork->mStepWaitFrames > 0x4b0) {
                SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
                return 3;
            }
            break;
        case CONNECTION_STEP_SEARCHING:
            connectionWork->mRequestPending = 0;
            break;
        case CONNECTION_STEP_SCAN_CONNECT_FIND_ENTRY: {
            s32 scanEntryIndex;
            connectionWork->mStepWaitFrames = connectionWork->mStepWaitFrames + 1;
            if (gConnectionWork->mStepWaitFrames > 0x4b0) {
                SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
            } else {
                scanEntryIndex = FindScanEntryIndex(entryIndex);
                if (scanEntryIndex != -1) {
                    gConnectionWork->mScanEntryIndex = scanEntryIndex;
                    StartRequestEndScan();
                }
            }
            break;
        }
    }
    connectionWork = gConnectionWork;
    if (connectionWork->mRequestPending != 0) {
        return 0;
    }
    switch (connectionWork->mStep) {
        case CONNECTION_STEP_SEARCHING:
            connectionWork->mFlags |= CONNECTION_FLAG_MULTIBOOT_SETUP;
            EndScan();
            break;
        case CONNECTION_STEP_STOPPING_SEARCH:
            SetupScanConnect();
            break;
        case CONNECTION_STEP_SCAN_CONNECT_SETUP:
            connectionWork->mStepWaitFrames = 0;
            StartRepeatedScanStep1E();
            break;
        case CONNECTION_STEP_SCAN_CONNECT_FIND_ENTRY:
            StartRequestEndScan();
            break;
        case CONNECTION_STEP_SCAN_CONNECT_END_SCAN:
            if (connectionWork->mScanEntryIndex == -1) {
                StartConnectToScanEntry(entryIndex);
            } else {
                StartConnectToScanEntry((u16) connectionWork->mScanEntryIndex);
            }
            break;
        case CONNECTION_STEP_SCAN_CONNECT_CONNECT_ENTRY:
            if (connectionWork->mScanConnected != 0) {
                if (connectionWork->mScanEntryIndex == -1) {
                    ReadFakeParentBssDesc(entryIndex);
                } else {
                    ReadFakeParentBssDesc((u16) connectionWork->mScanEntryIndex);
                }
            } else {
                result = 2;
            }
            break;
        case CONNECTION_STEP_SCAN_CONNECT_READ_PARENT_DESC:
            StartCloseScanConnect();
            break;
        case CONNECTION_STEP_STARTING_UP:
            connectionWork->mStepWaitFrames = 0;
        case CONNECTION_STEP_RESTARTING:
            if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                ReadMultiBootParentBssDesc();
            } else {
                StartConnect(NULL, NULL, NULL, ConnectFailedCallback, NULL);
            }
            break;
        case CONNECTION_STEP_SCAN_CONNECT_CLOSE:
            if (connectionWork->mStepWaitFrames < 0x3c) {
                connectionWork->mStepWaitFrames = connectionWork->mStepWaitFrames + 1;
            } else {
                connectionWork->mStep = CONNECTION_STEP_SCAN_CONNECT_CLOSED;
            }
            break;
        case CONNECTION_STEP_MULTIBOOT_READ_PARENT_DESC:
        case CONNECTION_STEP_SCAN_CONNECT_CLOSED:
            StartRomArchiveTransfer();
            break;
        case CONNECTION_STEP_ROM_ARCHIVE_TRANSFER:
            StartConnect(NULL, NULL, NULL, ConnectFailedCallback, NULL);
            break;
        case CONNECTION_STEP_JOINING:
            StartMP();
            break;
        case CONNECTION_STEP_STARTING_EXCHANGE:
            connectionWork->mState = CONNECTION_STATE_CONNECTED;
            InitMPStateMachine();
            result = 1;
            break;
    }
    return result;
}

u8 CompactMaskBits(u8 mask) {
    u8 packed = mask & 1;
    u32 bitIndex = 1;
    u32 nextBit = 1;

    for (; bitIndex < 8; bitIndex++) {
        if (((1 << bitIndex) & mask) != 0) {
            packed = packed | (1 << nextBit);
            nextBit++;
        }
    }
    return packed;
}

s32 AdvanceChildMaskCovered(void) {
    BOOL result = FALSE;
    ConnectionWork *connectionWork = gConnectionWork;
    u32 maskCopy = connectionWork->mMultiBootChildMask;
    u8 childMask = connectionWork->mChildren.mChildMask;

    if (maskCopy == (maskCopy & childMask)) {
        result = TRUE;
    } else if (connectionWork->mStepWaitFrames > 0x708) {
        if (childMask == 0) {
            SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
        } else {
            gConnectionWork->mMultiBootChildMask = CompactMaskBits(childMask);
            result = TRUE;
        }
    } else {
        connectionWork->mStepWaitFrames = connectionWork->mStepWaitFrames + 1;
    }
    return result;
}

s32 AdvanceMultiBootParent(void) {
    BOOL result = FALSE;
    switch (gConnectionWork->mState) {
        case CONNECTION_STATE_MULTIBOOT_PARENT_READY:
            gConnectionWork->mState = CONNECTION_STATE_MULTIBOOT_PARENT_ACTIVE;
            break;
        case CONNECTION_STATE_MULTIBOOT_PARENT_ACTIVE:
            break;
        case CONNECTION_STATE_ENTRY_EXCHANGE:
            return 1;
        default:
            return 3;
    }
    if (gConnectionWork->mRequestPending != 0) {
        return 0;
    }
    switch (gConnectionWork->mStep) {
        case CONNECTION_STEP_MULTIBOOT_START_PARENT:
            StartSendingToAllChildren();
            break;
        case CONNECTION_STEP_MULTIBOOT_SEND_TO_CHILDREN:
            StartBootRequestToAllChildren();
            break;
        case CONNECTION_STEP_MULTIBOOT_BOOT_REQUEST:
            StartEndToIdle();
            break;
        case CONNECTION_STEP_MULTIBOOT_END_TO_IDLE:
            StartRomArchiveTransfer();
            break;
        case CONNECTION_STEP_ROM_ARCHIVE_TRANSFER:
            SetLifeTime(0x14);
            break;
        case CONNECTION_STEP_SETTING_TIMEOUT:
            FillParentParameter(1);
            SetParentParameter();
            break;
        case CONNECTION_STEP_CHECKING_CHANNELS:
            SetParentChannelLowestSum();
            FillParentParameter(1);
            SetParentParameter();
            break;
        case CONNECTION_STEP_CONFIGURING_HOST:
            StartParent(NULL);
            break;
        case CONNECTION_STEP_OPENING_HOST:
            gConnectionWork->mMultiBootChildMask = CompactMaskBits(gConnectionWork->mMultiBootChildMask);
            gConnectionWork->mStepWaitFrames = 0;
            StartMP();
            break;
        case CONNECTION_STEP_STARTING_EXCHANGE:
        case CONNECTION_STEP_PUBLISHING_GAME_INFO:
            if (AdvanceChildMaskCovered() != 0) {
                InitMPStateMachine();
                result = TRUE;
            }
            break;
    }
    return result;
}

#pragma thumb off

s32 RomArchiveReadCallback(FSArchive *archive, void *dst, u32 src, u32 length) {
    MI_CpuCopy8((const void *) src, dst, length);
    return 0;
}
