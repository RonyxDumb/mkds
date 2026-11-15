#include "Main/Net/multiboot_connect.h"
#include "Main/Net/multiboot_parent_finish.h"
#include "mb_parent.h"
#include "code_02009928.h"
#include "code_0200ad00.h"
#include "03/Net/essid_packet_steps.h"
#include "os_thread.h"
#include "mb_data.h"
#include "code_0200c0d8.h"
#include "wm_etc.h"
#include "code_0214c778.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_0200fc8c.h"
#include "code_02142eac.h"
#include "code_0200aeb4.h"
#include "code_0200b1b0.h"
#include "Main/Net/scan_connect_callbacks.h"
#include "Main/Net/mp_link.h"
#include "Main/System/heap.h"
#include "Main/Net/multiboot_registry.h"
#include "Main/Net/participant_get_connection.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/connection.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/MapObjects/data_0217a000.h"
#include "os_tick.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

// Bytes of the scratch buffer for multiboot child data.
#define MULTIBOOT_SCRATCH_BUFFER_BYTES 0x4c0

void AllocConnectionBuffers(void *heap, u32 unused, void *bmg) {
    u32 workSize;
    gConnectionWork->mAllocHeap = heap;
    workSize = GetScanConnectWorkSize();
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT && workSize < 0xc000) {
        workSize = 0xc000;
    }
    gConnectionWork->mMultiBootWorkSize = workSize;
    gConnectionWork->mMultiBootWork =
        HeapAllocAligned(heap, gConnectionWork->mMultiBootWorkSize, HEAP_ALIGN_CACHE_LINE);
    if (gBootInfo->mBootType != BOOT_TYPE_MULTIBOOT) {
        gConnectionWork->mMultiBootSegmentSize = MB_GetSegmentLength(NULL);
        if (gConnectionWork->mMultiBootSegmentSize > 0x80000) {
            gConnectionWork->mMultiBootSegmentSize = 0x80000;
        }
        gConnectionWork->mMultiBootSegment =
            HeapAllocAligned(heap, gConnectionWork->mMultiBootSegmentSize, HEAP_ALIGN_CACHE_LINE);
        SetGameRegistryTexts(bmg);
        gConnectionWork->mMultiBootScratchBuffer =
            HeapAllocAligned(heap, MULTIBOOT_SCRATCH_BUFFER_BYTES, HEAP_ALIGN_CACHE_LINE);
    } else {
        gConnectionWork->mMultiBootSegmentSize = 0;
        gConnectionWork->mMultiBootSegment = 0;
        gConnectionWork->mMultiBootScratchBuffer = 0;
    }
    ResetConnectionBuffers(&gConnectionWork->mMultiBootState);
}

void ParentStateCallback(u32 index, u32 code, void *data) {
    MBUserInfo *childInfo = data;
    gConnectionWork->mMultiBootState.mChildStateCodes[index] = code;
    if (gConnectionWork->mStep == CONNECTION_STEP_MULTIBOOT_END_TO_IDLE && code != 0xc) {
        return;
    }
    switch (code) {
        case 10: {
            u32 accept = 1;
            if (gConnectionWork->mMultiBootRequestFlags & 1) {
                accept = 0;
            } else if ((gConnectionWork->mStatusFlags & 4) && childInfo->mPlayerNo == 0) {
                accept = 0;
            }
            if (accept != 0) {
                MB_CommResponseRequest(index, MB_RESPONSE_ACCEPT);
            } else {
                MB_CommResponseRequest(index, MB_RESPONSE_REFUSE);
            }
            return;
        }
        case 7:
            BIT_SET(gConnectionWork->mSendCompleteMask, index);
            if (gConnectionWork->mWaitToSendMask ==
                (gConnectionWork->mWaitToSendMask & gConnectionWork->mSendCompleteMask)) {
                gConnectionWork->mRequestPending = 0;
            }
            break;
        case 9:
            BIT_SET(gConnectionWork->mMultiBootChildMask, index);
            break;
        case 12:
            gConnectionWork->mRequestPending = 0;
            break;
        case 1:
            gConnectionWork->mRequestPending = 0;
            break;
        case 3:
            if (gConnectionWork->mMultiBootChildMask & (1 << index)) {
                BIT_SET(gConnectionWork->mBootRequestDoneMask, index);
                if (gConnectionWork->mWaitToSendMask ==
                    (gConnectionWork->mWaitToSendMask & gConnectionWork->mBootRequestDoneMask)) {
                    gConnectionWork->mRequestPending = 0;
                }
            }
            if (!(gConnectionWork->mMultiBootRequestFlags & 2)) {
                if (gConnectionWork->mWaitToSendCount != 0) {
                    if (gConnectionWork->mWaitToSendMask & (1 << index)) {
                        BIT_CLEAR(gConnectionWork->mWaitToSendMask, index);
                        gConnectionWork->mWaitToSendCount--;
                    }
                    if ((gConnectionWork->mMultiBootRequestFlags & 1) && gConnectionWork->mWaitToSendMask == 0) {
                        SetRequestErrorCode(CONNECTION_ERROR_COMMUNICATION_LOST);
                    }
                } else {
                    gConnectionWork->mWaitToSendMask = 0;
                    gConnectionWork->mBootRequestDoneMask = 0;
                    gConnectionWork->mMultiBootChildMask = 0;
                    gConnectionWork->mWaitToSendCount = 0;
                }
            }
            if ((gConnectionWork->mMultiBootRequestFlags & 2) &&
                gConnectionWork->mWaitToSendMask ==
                    (gConnectionWork->mWaitToSendMask & gConnectionWork->mBootRequestDoneMask) &&
                gConnectionWork->mStep == CONNECTION_STEP_MULTIBOOT_BOOT_REQUEST) {
                gConnectionWork->mRequestPending = 0;
                return;
            }
            if ((gConnectionWork->mMultiBootRequestFlags & 1) &&
                gConnectionWork->mWaitToSendMask ==
                    (gConnectionWork->mWaitToSendMask & gConnectionWork->mSendCompleteMask) &&
                gConnectionWork->mStep == CONNECTION_STEP_MULTIBOOT_SEND_TO_CHILDREN) {
                gConnectionWork->mRequestPending = 0;
                return;
            }
            break;
        case 14:
            if (!(gConnectionWork->mWaitToSendMask & (1 << index))) {
                BIT_SET(gConnectionWork->mWaitToSendMask, index);
                gConnectionWork->mWaitToSendCount++;
            }
            break;
    }
}

void ResetConnectionBuffers(MultiBootStateView *view) {
    s32 index;
    if (gConnectionWork->mMultiBootWork != 0) {
        MI_CpuFill8(gConnectionWork->mMultiBootWork, 0, gConnectionWork->mMultiBootWorkSize);
    }
    if (gConnectionWork->mMultiBootScratchBuffer != 0) {
        MI_CpuFill8(gConnectionWork->mMultiBootScratchBuffer, 0, MULTIBOOT_SCRATCH_BUFFER_BYTES);
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
    gConnectionWork->mStep = CONNECTION_STEP_MULTIBOOT_START_PARENT;
    gConnectionWork->mRequestPending = 1;
    ResetConnectionBuffers(&gConnectionWork->mMultiBootState);
    user.mNameLength = 10;
    user.mFavoriteColor = gStartupWork->mFavoriteColor;
    user.mPlayerNo = 8;
    MI_CpuCopy8(gBackupBuffers->mFirstBlock->mPlayerName, user.mName, sizeof(user.mName));
    gConnectionWork->mParentTgid = ComputeParentTgid(1);
    if (MB_Init(gConnectionWork->mMultiBootWork, &user, 0x25, gConnectionWork->mParentTgid, 2) != 0) {
        SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
    }
    MB_SetParentCommParam(0x1fe, 7);
    MB_CommSetParentStateCallback(ParentStateCallback);
    if (((s32(*)(u32)) MB_StartParentFromIdle)(gConnectionWork->mParentChannel) != 0) {
        SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
    }
    if (RegisterMultiBootSegment() == 0) {
        SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
    }
    gConnectionWork->mStatusFlags &= ~4;
    gConnectionWork->mRequestPending = 0;
}

void SetupScanConnect(void) {
    MBUserInfo userInfo;
    gConnectionWork->mStep = CONNECTION_STEP_SCAN_CONNECT_SETUP;
    gConnectionWork->mRequestPending = 1;
    userInfo.mFavoriteColor = gStartupWork->mFavoriteColor;
    userInfo.mNameLength = 10;
    userInfo.mPlayerNo = 9;
    MI_CpuCopy8(gBackupBuffers->mFirstBlock->mPlayerName, userInfo.mName, sizeof(userInfo.mName));
    gConnectionWork->mScanEntryIndex = -1;
    InitScanConnectWork(gConnectionWork->mMultiBootWork, &userInfo);
    SetScanConnectStateCallback(ScanConnectStateCallback);
    gConnectionWork->mRequestPending = 0;
}

void StartCloseScanConnect(void) {
    gConnectionWork->mStep = CONNECTION_STEP_SCAN_CONNECT_CLOSE;
    gConnectionWork->mRequestPending = 1;
    CloseScanConnect();
}

void StartRepeatedScanStep1D(void) {
    gConnectionWork->mStep = CONNECTION_STEP_SCAN_CONNECT_REPEATED_SCAN;
    gConnectionWork->mRequestPending = 1;
    StartRepeatedScan(RepeatedScanCallback, 0x25);
}

static inline u32 MultiBootGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

void StartRepeatedScanStep1E(void) {
    gConnectionWork->mStep = CONNECTION_STEP_SCAN_CONNECT_FIND_ENTRY;
    gConnectionWork->mRequestPending = 1;
    StartRepeatedScan(RepeatedScanCallback, 0x25);
}

// Returns the scan entry index with bytes 4..9 matching the first six of element a of mScanSlots[0].mUnk_c0, or -1.
s32 FindScanEntryIndex(u32 entryIndex) {
    s32 result;
    u16 index;
    WMBssDesc scanBlock;
    result = -1;
    if (gConnectionWork->mStep == CONNECTION_STEP_SCAN_CONNECT_FIND_ENTRY) {
        for (index = 0; index < 16; index++) {
            if (MB_FakeGetParentBssDesc(index, &scanBlock) != 0) {
                u8 *tableBytes = gConnectionWork->mScanSlots[0].mKey.mBytes;
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
            gConnectionWork->mRequestPending = 0;
            break;
    }
}

void ScanConnectStateCallback(u32 state, void *info) {
    switch (state) {
        case SCAN_CONNECT_STATE_RESET_DONE:
            gConnectionWork->mRequestPending = 0;
            break;
        case SCAN_CONNECT_STATE_FINISHED:
            gConnectionWork->mStepWaitFrames = (OS_GetTick() >> 10) % 40;
            gConnectionWork->mRequestPending = 0;
            break;
        case SCAN_CONNECT_STATE_ACCEPTED:
            gConnectionWork->mScanConnected = 1;
            gConnectionWork->mState = CONNECTION_STATE_CONNECTED;
            break;
        case SCAN_CONNECT_STATE_LINK_LOST:
            SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
            break;
        case SCAN_CONNECT_STATE_CONNECT_FAILED:
        case SCAN_CONNECT_STATE_REQUEST_REJECTED:
            gConnectionWork->mScanConnected = 0;
            gConnectionWork->mRequestPending = 0;
            break;
    }
}

s32 AdvanceMultiBootParentSetup(void) {
    BOOL result = FALSE;
    switch (gConnectionWork->mStep) {
        case CONNECTION_STEP_NOTHING:
            gConnectionWork->mFlags |= CONNECTION_FLAG_MULTIBOOT_SETUP;
            gConnectionWork->mState = CONNECTION_STATE_STARTING;
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
        switch (gConnectionWork->mStep) {
            case CONNECTION_STEP_NOTHING:
                gConnectionWork->mFlags |= CONNECTION_FLAG_MULTIBOOT_SETUP;
                gConnectionWork->mState = CONNECTION_STATE_STARTING;
                Initialize();
                break;
            case CONNECTION_STEP_STARTING_UP:
                stepDone = TRUE;
                break;
        }
    } else {
        switch (gConnectionWork->mStep) {
            case CONNECTION_STEP_NOTHING:
                gConnectionWork->mFlags |= CONNECTION_FLAG_MULTIBOOT_SETUP;
                gConnectionWork->mState = CONNECTION_STATE_STARTING;
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
        gConnectionWork->mState = CONNECTION_STATE_MULTIBOOT_SCAN_READY;
        result = TRUE;
    }
    return result;
}

s32 AdvanceMultiBootSetup(s32 isParent) {
    s32 result = 0;
    if (gConnectionWork->mRequestPending != 0) {
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
                gConnectionWork->mConnectionMode = CONNECTION_MODE_PARENT;
            } else {
                gConnectionWork->mConnectionMode = CONNECTION_MODE_CHILD;
            }
            break;
    }
    return result;
}

void StartSendingToAllChildren(void) {
    u8 index;
    u8 count;
    if (gConnectionWork->mWaitToSendMask == 0) {
        SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
        return;
    }
    gConnectionWork->mStep = CONNECTION_STEP_MULTIBOOT_SEND_TO_CHILDREN;
    index = 1;
    gConnectionWork->mRequestPending = index;
    count = 0;
    gConnectionWork->mSendCompleteMask = count;
    gConnectionWork->mMultiBootRequestFlags |= index;
    for (; index <= 15; index++) {
        if (MB_CommResponseRequest(index, MB_RESPONSE_DOWNLOAD) == 1) {
            count++;
        }
    }
    if (count == 0) {
        gConnectionWork->mMultiBootRequestFlags &= ~1;
    }
}

void StartBootRequestToAllChildren(void) {
    u8 index;
    u8 count;
    gConnectionWork->mStep = CONNECTION_STEP_MULTIBOOT_BOOT_REQUEST;
    index = 1;
    gConnectionWork->mRequestPending = index;
    gConnectionWork->mMultiBootRequestFlags |= 2;
    count = 0;
    gConnectionWork->mMultiBootChildMask = count;
    for (; index <= 15; index++) {
        if (MB_CommResponseRequest(index, MB_RESPONSE_BOOT) == 1) {
            count++;
        }
    }
    if (count == 0) {
        gConnectionWork->mMultiBootRequestFlags &= ~2;
    }
}

void StartEndToIdle(void) {
    gConnectionWork->mStep = CONNECTION_STEP_MULTIBOOT_END_TO_IDLE;
    gConnectionWork->mRequestPending = 1;
    gConnectionWork->mMultiBootRequestFlags &= ~2;
    MB_EndToIdle();
}

void StartRequestEndScan(void) {
    gConnectionWork->mStep = CONNECTION_STEP_SCAN_CONNECT_END_SCAN;
    gConnectionWork->mRequestPending = 1;
    RequestEndScan();
}

void StartConnectToScanEntry(u16 entryIndex) {
    gConnectionWork->mStep = CONNECTION_STEP_SCAN_CONNECT_CONNECT_ENTRY;
    gConnectionWork->mRequestPending = 1;
    gConnectionWork->mScanConnected = 0;
    if (StartConnectToEntry(entryIndex) == 0) {
        SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
    }
}

void ReadFakeParentBssDesc(u16 entryIndex) {
    u32 result;
    gConnectionWork->mStep = CONNECTION_STEP_SCAN_CONNECT_READ_PARENT_DESC;
    gConnectionWork->mRequestPending = 1;
    result = MB_FakeReadParentBssDesc(entryIndex, gConnectionWork->mParentBssDesc, 0x1bc, 0x36, 0, 0);
    gConnectionWork->mRequestPending = 0;
    gConnectionWork->mParentBssDesc->mGameInfo.mTgid = (gConnectionWork->mParentBssDesc->mGameInfo.mTgid + 7) & 0x7fff;
    if (result == 0) {
        SetRequestErrorCode(CONNECTION_ERROR_CONNECT_FAILED);
    }
}

void ReadMultiBootParentBssDesc(void) {
    gConnectionWork->mStep = CONNECTION_STEP_MULTIBOOT_READ_PARENT_DESC;
    gConnectionWork->mRequestPending = 1;
    MB_ReadMultiBootParentBssDesc(gConnectionWork->mParentBssDesc, 0x1bc, 0x36, 0, 0);
    gConnectionWork->mParentBssDesc->mGameInfo.mTgid = (gConnectionWork->mParentBssDesc->mGameInfo.mTgid + 7) & 0x7fff;
    gConnectionWork->mRequestPending = 0;
}

#pragma thumb off
