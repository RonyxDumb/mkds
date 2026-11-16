#include "Main/Net/multiboot_connect.h"
#include "Main/Net/multiboot_parent_finish.h"
#include "multiboot_parent_state_machine.h"
#include "multiboot_communication.h"
#include "multiboot_mode_constants.h"
#include "03/Net/essid_packet_steps.h"
#include "thread_scheduler.h"
#include "multiboot_piece_buffers.h"
#include "multiboot_data_pieces.h"
#include "wireless_beacon_wep_settings.h"
#include "dma_copy_fill_wait.h"
#include "cpu_copy_clear_16.h"
#include "cpu_copy_fill.h"
#include "reset_interrupts_halt.h"
#include "wireless_link_control.h"
#include "multiboot_task_thread.h"
#include "multiboot_parent_desc.h"
#include "Main/Net/scan_connect_callbacks.h"
#include "Main/Net/mp_link.h"
#include "Main/System/heap.h"
#include "Main/Net/multiboot_registry.h"
#include "Main/Net/participant_get_connection.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/connection.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/System/backup_net_camera_work.h"
#include "tick_counter.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

// Bytes of the scratch buffer for multiboot child data.
#define MULTIBOOT_SCRATCH_BUFFER_BYTES 0x4c0
// Most bytes of the multiboot program segment a parent holds.
#define MULTIBOOT_SEGMENT_MAX_BYTES 0x80000

void AllocConnectionBuffers(void *heap, u32 unused, void *bmg) {
    u32 workSize;
    g_GlobalZE->mAllocHeap = heap;
    workSize = Const5F20_from_thumb();
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT && workSize < 0xc000) {
        workSize = 0xc000;
    }
    g_GlobalZE->mMultiBootWorkSize = workSize;
    g_GlobalZE->mMultiBootWork =
        Mem_AllocateHeapAligned(heap, g_GlobalZE->mMultiBootWorkSize, HEAP_ALIGN_CACHE_LINE);
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        g_GlobalZE->mMultiBootSegmentSize = ComputeRomBinarySize_from_thumb(NULL);
        if (g_GlobalZE->mMultiBootSegmentSize > MULTIBOOT_SEGMENT_MAX_BYTES) {
            g_GlobalZE->mMultiBootSegmentSize = MULTIBOOT_SEGMENT_MAX_BYTES;
        }
        g_GlobalZE->mMultiBootSegment =
            Mem_AllocateHeapAligned(heap, g_GlobalZE->mMultiBootSegmentSize, HEAP_ALIGN_CACHE_LINE);
        SetGlobalBAN_from_thumb(bmg);
        g_GlobalZE->mMultiBootScratchBuffer =
            Mem_AllocateHeapAligned(heap, MULTIBOOT_SCRATCH_BUFFER_BYTES, HEAP_ALIGN_CACHE_LINE);
    } else {
        g_GlobalZE->mMultiBootSegmentSize = 0;
        g_GlobalZE->mMultiBootSegment = 0;
        g_GlobalZE->mMultiBootScratchBuffer = 0;
    }
    StructBin_SomeFn_from_thumb(&g_GlobalZE->mMultiBootState);
}

void ParentStateCallback(u32 index, u32 code, void *data) {
    MBUserInfo *childInfo = data;
    g_GlobalZE->mMultiBootState.mChildStateCodes[index] = code;
    if (g_GlobalZE->mStep == CONNECTION_STEP_MULTIBOOT_END_TO_IDLE && code != MULTIBOOT_PARENT_ENDED) {
        return;
    }
    switch (code) {
        case MULTIBOOT_PARENT_CHILD_REQUESTED: {
            u32 accept = 1;
            if (g_GlobalZE->mMultiBootRequestFlags & CONNECTION_MULTIBOOT_REQUEST_SEND) {
                accept = 0;
            } else if ((g_GlobalZE->mStatusFlags & CONNECTION_STATUS_REFUSE_UNNUMBERED_CHILD) &&
                       childInfo->mPlayerNo == 0) {
                accept = 0;
            }
            if (accept != 0) {
                MB_CommResponseRequest(index, MULTIBOOT_RESPONSE_ACCEPT);
            } else {
                MB_CommResponseRequest(index, MULTIBOOT_RESPONSE_REFUSE);
            }
            return;
        }
        case MULTIBOOT_PARENT_DOWNLOAD_DONE:
            BIT_SET(g_GlobalZE->mSendCompleteMask, index);
            if (g_GlobalZE->mWaitToSendMask ==
                (g_GlobalZE->mWaitToSendMask & g_GlobalZE->mSendCompleteMask)) {
                g_GlobalZE->mRequestPending = 0;
            }
            break;
        case MULTIBOOT_PARENT_CHILD_BOOTED:
            BIT_SET(g_GlobalZE->mMultiBootChildMask, index);
            break;
        case MULTIBOOT_PARENT_ENDED:
            g_GlobalZE->mRequestPending = 0;
            break;
        case MULTIBOOT_PARENT_STARTED:
            g_GlobalZE->mRequestPending = 0;
            break;
        case MULTIBOOT_PARENT_CHILD_DISCONNECTED:
            if (g_GlobalZE->mMultiBootChildMask & (1 << index)) {
                BIT_SET(g_GlobalZE->mBootRequestDoneMask, index);
                if (g_GlobalZE->mWaitToSendMask ==
                    (g_GlobalZE->mWaitToSendMask & g_GlobalZE->mBootRequestDoneMask)) {
                    g_GlobalZE->mRequestPending = 0;
                }
            }
            if (!(g_GlobalZE->mMultiBootRequestFlags & CONNECTION_MULTIBOOT_REQUEST_BOOT)) {
                if (g_GlobalZE->mWaitToSendCount != 0) {
                    if (g_GlobalZE->mWaitToSendMask & (1 << index)) {
                        BIT_CLEAR(g_GlobalZE->mWaitToSendMask, index);
                        g_GlobalZE->mWaitToSendCount--;
                    }
                    if ((g_GlobalZE->mMultiBootRequestFlags & CONNECTION_MULTIBOOT_REQUEST_SEND) &&
                        g_GlobalZE->mWaitToSendMask == 0) {
                        SetRequestErrorCode(CONNECTION_ERROR_COMMUNICATION_LOST);
                    }
                } else {
                    g_GlobalZE->mWaitToSendMask = 0;
                    g_GlobalZE->mBootRequestDoneMask = 0;
                    g_GlobalZE->mMultiBootChildMask = 0;
                    g_GlobalZE->mWaitToSendCount = 0;
                }
            }
            if ((g_GlobalZE->mMultiBootRequestFlags & CONNECTION_MULTIBOOT_REQUEST_BOOT) &&
                g_GlobalZE->mWaitToSendMask ==
                    (g_GlobalZE->mWaitToSendMask & g_GlobalZE->mBootRequestDoneMask) &&
                g_GlobalZE->mStep == CONNECTION_STEP_MULTIBOOT_BOOT_REQUEST) {
                g_GlobalZE->mRequestPending = 0;
                return;
            }
            if ((g_GlobalZE->mMultiBootRequestFlags & CONNECTION_MULTIBOOT_REQUEST_SEND) &&
                g_GlobalZE->mWaitToSendMask ==
                    (g_GlobalZE->mWaitToSendMask & g_GlobalZE->mSendCompleteMask) &&
                g_GlobalZE->mStep == CONNECTION_STEP_MULTIBOOT_SEND_TO_CHILDREN) {
                g_GlobalZE->mRequestPending = 0;
                return;
            }
            break;
        case MULTIBOOT_PARENT_CHILD_WAITING:
            if (!(g_GlobalZE->mWaitToSendMask & (1 << index))) {
                BIT_SET(g_GlobalZE->mWaitToSendMask, index);
                g_GlobalZE->mWaitToSendCount++;
            }
            break;
    }
}

void StructBin_SomeFn_from_thumb(MultiBootStateView *view) {
    s32 index;
    if (g_GlobalZE->mMultiBootWork != 0) {
        Mem_CpuFill8(g_GlobalZE->mMultiBootWork, 0, g_GlobalZE->mMultiBootWorkSize);
    }
    if (g_GlobalZE->mMultiBootScratchBuffer != 0) {
        Mem_CpuFill8(g_GlobalZE->mMultiBootScratchBuffer, 0, MULTIBOOT_SCRATCH_BUFFER_BYTES);
    }
    for (index = 0; index < 8; index++) {
        view->mChildStateCodes[index] = 0;
    }
    view->mUnk_3c = 0;
    view->mUnk_3d = 0;
    view->mUnk_3e = 0;
    view->mUnk_3f = 0;
    view->mUnk_40 = 0;
    view->mUnk_41 = 0;
    view->mUnk_38 = 0;
    view->mUnk_3a = 0;
    view->mUnk_42 = -1;
    view->mUnk_44 = 0;
}

void StartMultiBootParent(void) {
    MBUserInfo user;
    g_GlobalZE->mStep = CONNECTION_STEP_MULTIBOOT_START_PARENT;
    g_GlobalZE->mRequestPending = 1;
    StructBin_SomeFn_from_thumb(&g_GlobalZE->mMultiBootState);
    user.mNameLength = MULTIBOOT_USER_NAME_LENGTH;
    user.mFavoriteColor = g_GlobalP->mFavoriteColor;
    user.mPlayerNo = MULTIBOOT_PARENT_PLAYER_NUMBER;
    Mem_CpuCopy8(g_SaveDataHolder->mFirstBlock->mPlayerName, user.mName, sizeof(user.mName));
    g_GlobalZE->mParentTgid = ComputeParentTgid(1);
    if (SetupSomePointer_from_thumb(g_GlobalZE->mMultiBootWork, &user, CONNECTION_GAME_GROUP_ID, g_GlobalZE->mParentTgid, 2) !=
        0) {
        SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
    }
    MB_SetParentCommParam(0x1fe, 7);
    MB_CommSetParentStateCallback(ParentStateCallback);
    if (((s32(*)(u32)) MB_StartParentFromIdle)(g_GlobalZE->mParentChannel) != 0) {
        SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
    }
    if (RegisterMultiBootSegment() == 0) {
        SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
    }
    g_GlobalZE->mStatusFlags &= ~CONNECTION_STATUS_REFUSE_UNNUMBERED_CHILD;
    g_GlobalZE->mRequestPending = 0;
}

void SetupScanConnect(void) {
    MBUserInfo userInfo;
    g_GlobalZE->mStep = CONNECTION_STEP_SCAN_CONNECT_SETUP;
    g_GlobalZE->mRequestPending = 1;
    userInfo.mFavoriteColor = g_GlobalP->mFavoriteColor;
    userInfo.mNameLength = MULTIBOOT_USER_NAME_LENGTH;
    userInfo.mPlayerNo = SCAN_CONNECT_PLAYER_NUMBER;
    Mem_CpuCopy8(g_SaveDataHolder->mFirstBlock->mPlayerName, userInfo.mName, sizeof(userInfo.mName));
    g_GlobalZE->mScanEntryIndex = -1;
    InitScanConnectWork(g_GlobalZE->mMultiBootWork, &userInfo);
    SetScanConnectStateCallback(ScanConnectStateCallback);
    g_GlobalZE->mRequestPending = 0;
}

void StructZE_StateFn_28_29_30_33_34_35_from_thumb(void) {
    g_GlobalZE->mStep = CONNECTION_STEP_SCAN_CONNECT_CLOSE;
    g_GlobalZE->mRequestPending = 1;
    CloseScanConnect();
}

void StartRepeatedScanStep1D(void) {
    g_GlobalZE->mStep = CONNECTION_STEP_SCAN_CONNECT_REPEATED_SCAN;
    g_GlobalZE->mRequestPending = 1;
    StartRepeatedScan(RepeatedScanCallback, CONNECTION_GAME_GROUP_ID);
}

static inline u32 MultiBootGetConnectionMode(void) {
    if (g_GlobalZE == NULL) {
        return 0;
    }
    return g_GlobalZE->mConnectionMode;
}

void StartRepeatedScanStep1E(void) {
    g_GlobalZE->mStep = CONNECTION_STEP_SCAN_CONNECT_FIND_ENTRY;
    g_GlobalZE->mRequestPending = 1;
    StartRepeatedScan(RepeatedScanCallback, CONNECTION_GAME_GROUP_ID);
}

// Returns the scan entry index with bytes 4..9 matching the first six of element a of mScanSlots[0].mUnk_c0, or -1.
s32 FindScanEntryIndex(u32 entryIndex) {
    s32 result;
    u16 index;
    WMBssDesc scanBlock;
    result = -1;
    if (g_GlobalZE->mStep == CONNECTION_STEP_SCAN_CONNECT_FIND_ENTRY) {
        for (index = 0; index < 16; index++) {
            if (MB_FakeGetParentBssDesc(index, &scanBlock) != 0) {
                u8 *tableBytes = g_GlobalZE->mScanSlots[0].mKey.mBytes;
                u8 *entryBytes = tableBytes + entryIndex * 0xe0;
                if (scanBlock.mBssid[0] == tableBytes[entryIndex * 0xe0] && scanBlock.mBssid[1] == entryBytes[1] &&
                    scanBlock.mBssid[2] == entryBytes[2] && scanBlock.mBssid[3] == entryBytes[3] &&
                    scanBlock.mBssid[4] == entryBytes[4] && scanBlock.mBssid[5] == entryBytes[5]) {
                    result = (s8) index;
                    break;
                }
            }
        }
    }
    return result;
}

// Codes: 2 is an error, 3 the end of the scan; 0 and 1 carry a table entry and are ignored.
void RepeatedScanCallback(u32 code, void *args) {
    switch (code) {
        case SCAN_EVENT_ENTRY_NEW:
        case SCAN_EVENT_ENTRY_UPDATED:
            break;
        case SCAN_EVENT_ERROR:
            SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
            break;
        case SCAN_EVENT_END:
            g_GlobalZE->mRequestPending = 0;
            break;
    }
}

void ScanConnectStateCallback(u32 state, void *info) {
    switch (state) {
        case SCAN_CONNECT_STATE_RESET_DONE:
            g_GlobalZE->mRequestPending = 0;
            break;
        case SCAN_CONNECT_STATE_FINISHED:
            g_GlobalZE->mStepWaitFrames = (Os_GetTick() >> 10) % 40;
            g_GlobalZE->mRequestPending = 0;
            break;
        case SCAN_CONNECT_STATE_ACCEPTED:
            g_GlobalZE->mScanConnected = 1;
            g_GlobalZE->mState = CONNECTION_STATE_CONNECTED;
            break;
        case SCAN_CONNECT_STATE_LINK_LOST:
            SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
            break;
        case SCAN_CONNECT_STATE_CONNECT_FAILED:
        case SCAN_CONNECT_STATE_REQUEST_REJECTED:
            g_GlobalZE->mScanConnected = 0;
            g_GlobalZE->mRequestPending = 0;
            break;
    }
}

s32 AdvanceMultiBootParentSetup(void) {
    BOOL result = FALSE;
    switch (g_GlobalZE->mStep) {
        case CONNECTION_STEP_NOTHING:
            g_GlobalZE->mFlags |= CONNECTION_FLAG_MULTIBOOT_SETUP;
            g_GlobalZE->mState = CONNECTION_STATE_STARTING;
            Initialize();
            break;
        case CONNECTION_STEP_STARTING_UP:
            MeasureChannel(result);
            break;
        case CONNECTION_STEP_CHECKING_CHANNELS:
            SetParentChannelLowestSum();
            StartMultiBootParent();
            break;
        case CONNECTION_STEP_MULTIBOOT_START_PARENT:
            FinishMultiBootParentSetup();
            result = TRUE;
            break;
    }
    return result;
}

s32 AdvanceMultiBootScanSetup(void) {
    BOOL stepDone = FALSE;
    BOOL result = FALSE;
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        switch (g_GlobalZE->mStep) {
            case CONNECTION_STEP_NOTHING:
                g_GlobalZE->mFlags |= CONNECTION_FLAG_MULTIBOOT_SETUP;
                g_GlobalZE->mState = CONNECTION_STATE_STARTING;
                Initialize();
                break;
            case CONNECTION_STEP_STARTING_UP:
                stepDone = TRUE;
                break;
        }
    } else {
        switch (g_GlobalZE->mStep) {
            case CONNECTION_STEP_NOTHING:
                g_GlobalZE->mFlags |= CONNECTION_FLAG_MULTIBOOT_SETUP;
                g_GlobalZE->mState = CONNECTION_STATE_STARTING;
                Initialize();
                break;
            case CONNECTION_STEP_STARTING_UP:
                SetupScanConnect();
                break;
            case CONNECTION_STEP_SCAN_CONNECT_SETUP:
                StartRepeatedScanStep1D();
                stepDone = TRUE;
                break;
        }
    }
    if (stepDone != FALSE) {
        g_GlobalZE->mState = CONNECTION_STATE_MULTIBOOT_SCAN_READY;
        result = TRUE;
    }
    return result;
}

s32 AdvanceMultiBootSetup(s32 isParent) {
    s32 result = 0;
    if (g_GlobalZE->mRequestPending != 0) {
        return 0;
    }
    switch (MultiBootGetConnectionMode()) {
        case CONNECTION_MODE_PARENT:
            result = AdvanceMultiBootParentSetup();
            break;
        case CONNECTION_MODE_CHILD:
            result = AdvanceMultiBootScanSetup();
            break;
        case CONNECTION_MODE_NONE:
            if (isParent != 0) {
                g_GlobalZE->mConnectionMode = CONNECTION_MODE_PARENT;
            } else {
                g_GlobalZE->mConnectionMode = CONNECTION_MODE_CHILD;
            }
            break;
    }
    return result;
}

void StartSendingToAllChildren(void) {
    u8 index;
    u8 count;
    if (g_GlobalZE->mWaitToSendMask == 0) {
        SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
        return;
    }
    g_GlobalZE->mStep = CONNECTION_STEP_MULTIBOOT_SEND_TO_CHILDREN;
    index = 1;
    g_GlobalZE->mRequestPending = index;
    count = 0;
    g_GlobalZE->mSendCompleteMask = count;
    g_GlobalZE->mMultiBootRequestFlags |= CONNECTION_MULTIBOOT_REQUEST_SEND;
    for (; index <= 15; index++) {
        if (MB_CommResponseRequest(index, MULTIBOOT_RESPONSE_SEND) == 1) {
            count++;
        }
    }
    if (count == 0) {
        g_GlobalZE->mMultiBootRequestFlags &= ~CONNECTION_MULTIBOOT_REQUEST_SEND;
    }
}

void StartBootRequestToAllChildren(void) {
    u8 index;
    u8 count;
    g_GlobalZE->mStep = CONNECTION_STEP_MULTIBOOT_BOOT_REQUEST;
    index = 1;
    g_GlobalZE->mRequestPending = index;
    g_GlobalZE->mMultiBootRequestFlags |= CONNECTION_MULTIBOOT_REQUEST_BOOT;
    count = 0;
    g_GlobalZE->mMultiBootChildMask = count;
    for (; index <= 15; index++) {
        if (MB_CommResponseRequest(index, MULTIBOOT_RESPONSE_BOOT) == 1) {
            count++;
        }
    }
    if (count == 0) {
        g_GlobalZE->mMultiBootRequestFlags &= ~CONNECTION_MULTIBOOT_REQUEST_BOOT;
    }
}

void StructZE_StateFn22_23_24_25_from_thumb(void) {
    g_GlobalZE->mStep = CONNECTION_STEP_MULTIBOOT_END_TO_IDLE;
    g_GlobalZE->mRequestPending = 1;
    g_GlobalZE->mMultiBootRequestFlags &= ~CONNECTION_MULTIBOOT_REQUEST_BOOT;
    MB_EndToIdle();
}

void StartRequestEndScan(void) {
    g_GlobalZE->mStep = CONNECTION_STEP_SCAN_CONNECT_END_SCAN;
    g_GlobalZE->mRequestPending = 1;
    RequestEndScan();
}

void StartConnectToScanEntry(u16 entryIndex) {
    g_GlobalZE->mStep = CONNECTION_STEP_SCAN_CONNECT_CONNECT_ENTRY;
    g_GlobalZE->mRequestPending = 1;
    g_GlobalZE->mScanConnected = 0;
    if (StartConnectToEntry(entryIndex) == 0) {
        SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
    }
}

void ReadFakeParentBssDesc(u16 entryIndex) {
    u32 result;
    g_GlobalZE->mStep = CONNECTION_STEP_SCAN_CONNECT_READ_PARENT_DESC;
    g_GlobalZE->mRequestPending = 1;
    result = MB_FakeReadParentBssDesc(entryIndex, g_GlobalZE->mParentBssDesc, 0x1bc, 0x36, 0, 0);
    g_GlobalZE->mRequestPending = 0;
    g_GlobalZE->mParentBssDesc->mGameInfo.mTgid = (g_GlobalZE->mParentBssDesc->mGameInfo.mTgid + 7) & 0x7fff;
    if (result == 0) {
        SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
    }
}

void ReadMultiBootParentBssDesc(void) {
    g_GlobalZE->mStep = CONNECTION_STEP_MULTIBOOT_READ_PARENT_DESC;
    g_GlobalZE->mRequestPending = 1;
    MB_ReadMultiBootParentBssDesc(g_GlobalZE->mParentBssDesc, 0x1bc, 0x36, 0, 0);
    g_GlobalZE->mParentBssDesc->mGameInfo.mTgid = (g_GlobalZE->mParentBssDesc->mGameInfo.mTgid + 7) & 0x7fff;
    g_GlobalZE->mRequestPending = 0;
}

#pragma thumb off
