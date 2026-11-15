#include "Main/Net/connection_sharing.h"
#include "Main/System/heap.h"
#include "Main/Net/pending_files.h"
#include "Main/Net/participant_get_connection.h"
#include "Main/Net/connection.h"
#include "Main/Net/wbt_requests.h"
#include "Main/Net/multiboot_connect.h"
#include "Main/Net/packet_port.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Net/block.h"
#include "Main/Net/scan_ghost_info.h"
#include "Main/Net/scan.h"
#include "Main/Net/own_index.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Net/participant_bits.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Scene/display_settings.h"
#include "archive_memory_load.h"
#include "heap_frame_allocator.h"
#include "thread_scheduler.h"
#include "Main/MapObjects/map_object_park.h"
#include "power_management_commands.h"
#include "Main/Sound/sound_seq.h"
#include "expanded_heap_head.h"
#include "cpu_copy_fill.h"
#include "Main/Save/ghost_record_file.h"

#pragma opt_rebuildconditionals off

ConnectionWork *gConnectionWork;

static inline u32 ConnectionGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline s32 IsConnectionActive(void) {
    BOOL result = FALSE;
    if (ConnectionGetConnectionMode() != CONNECTION_MODE_NONE && gConnectionWork->mState != CONNECTION_STATE_ENDED) {
        result = TRUE;
    }
    return result;
}

static inline s32 IsConnectionActiveNotEnding(void) {
    BOOL result = FALSE;
    if (IsConnectionActive() && !(gConnectionWork->mFlags & CONNECTION_FLAG_ENDING)) {
        result = TRUE;
    }
    return result;
}

static inline s32 IsConnectionActiveNotEndingWithError(void) {
    BOOL result = FALSE;
    if (IsConnectionActiveNotEnding() && gConnectionWork->mErrorCode != CONNECTION_ERROR_NONE) {
        result = TRUE;
    }
    return result;
}

static inline s32 HasSharingRecordSyncToggleBit(SharingReceiveRecord *receiveRecord) {
    BOOL result = FALSE;
    u8 toggleBits = receiveRecord->mFlags;
    if (gConnectionWork->mSyncToggle == 0) {
        if (toggleBits & SHARING_RECORD_FLAG_SYNC_PHASE_A) {
            result = TRUE;
        }
    } else {
        if (toggleBits & SHARING_RECORD_FLAG_SYNC_PHASE_B) {
            result = TRUE;
        }
    }
    return result;
}

static inline s32 AreChildSharingRecordsSynced(DataSharing *dataSharing, SharingReceiveRecord *receiveRecords) {
    u8 mask = gConnectionWork->mChildren.mChildMask;
    u8 childIndex;
    BOOL result = FALSE;
    u16 toggleBit;

    for (childIndex = 1; childIndex < 8; childIndex++) {
        if (mask & (1 << childIndex)) {
            if (dataSharing->mSharedDataCopied[childIndex] == 0) {
                result = FALSE;
                childIndex = 8;
            } else {
                toggleBit = gConnectionWork->mSyncToggle == 0 ? SHARING_RECORD_FLAG_SYNC_PHASE_A
                                                              : SHARING_RECORD_FLAG_SYNC_PHASE_B;
                if ((toggleBit & receiveRecords[childIndex].mFlags) == 0) {
                    result = FALSE;
                    childIndex = 8;
                } else {
                    result = TRUE;
                }
            }
        }
    }
    return result;
}

static inline u32 GetWorkConnectionMode(ConnectionWork *connectionWork) {
    if (connectionWork == NULL) {
        return 0;
    }
    return connectionWork->mConnectionMode;
}

// Returns 1 once the last step is issued, 2 on failure, 3 when an error has been recorded, 0 otherwise.
s32 AdvanceConnectionSetup(s32 isParent, void *ghostSource) {
    BOOL finished;

    finished = FALSE;
    if (gConnectionWork->mMPSetupActive != 0) {
        u16 ownIndex;

        ownIndex = gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD ? gConnectionWork->mOwnIndex : 0;
        if (ownIndex == 0xffff) {
            return 2;
        }
    }
    if (IsConnectionActiveNotEndingWithError()) {
        return 3;
    }
    if (gConnectionWork->mRequestPending != 0) {
        return 0;
    }
    switch (gConnectionWork->mStep) {
        case CONNECTION_STEP_NOTHING:
        case CONNECTION_STEP_SHUTTING_DOWN:
            gConnectionWork->mFlags &= ~CONNECTION_FLAG_MULTIBOOT_SETUP;
            gConnectionWork->mState = CONNECTION_STATE_STARTING;
            Initialize();
            break;
        case CONNECTION_STEP_STARTING_UP:
            gConnectionWork->mState = CONNECTION_STATE_GATHERING;
            if (isParent != 0) {
                SetLifeTime(0x28);
            } else {
                StartScan(0, NULL, NULL);
            }
            break;
        case CONNECTION_STEP_RESTARTING:
            if (isParent != 0) {
                SetLifeTime(0x28);
            } else {
                StartScan(0, NULL, NULL);
            }
            break;
        case CONNECTION_STEP_SETTING_TIMEOUT:
            MeasureChannel(0);
            break;
        case CONNECTION_STEP_CHECKING_CHANNELS:
            SetParentChannelLowestSum();
            FillGhostParentParameter(ghostSource);
            SetParentParameter();
            break;
        case CONNECTION_STEP_CONFIGURING_HOST:
            StartParent(NULL);
            break;
        case CONNECTION_STEP_OPENING_HOST:
            StartMPWithBuffers();
            break;
        case CONNECTION_STEP_SEARCHING:
            if (gConnectionWork->mSelectedScanEntry == -1) {
                StartScan(0, NULL, NULL);
            } else {
                EndScan();
            }
            break;
        case CONNECTION_STEP_STOPPING_SEARCH:
            StartConnect(NULL, NULL, NULL, NULL, ResetOwnIndex);
            break;
        case CONNECTION_STEP_JOINING:
            gConnectionWork->mMPSetupActive = 1;
            StartMPWithBuffers();
            break;
        case CONNECTION_STEP_STARTING_EXCHANGE:
            if (isParent != 0) {
                StartParentSideBlockTransfer();
            } else {
                StartChildSideBlockTransfer();
                SetWbtOwnAidFromConnection();
            }
            finished = TRUE;
            break;
        default:
            StopConnection();
            break;
    }
    return finished;
}

// Child side; returns 1 when done, 2 on failure, 3 when an error has been recorded, 0 otherwise (the parent returns 1
// at once).
s32 AdvanceBlockCountRequest(void) {
    BOOL finished;

    finished = FALSE;
    if (IsConnectionActiveNotEndingWithError()) {
        return 3;
    }
    if (gConnectionWork->mMPSetupActive != 0) {
        u16 ownIndex;

        ownIndex = gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD ? gConnectionWork->mOwnIndex : 0;
        if (ownIndex == 0xffff) {
            return 2;
        }
    }
    if (gConnectionWork->mRequestPending != 0) {
        return 0;
    }
    if (ConnectionGetConnectionMode() == CONNECTION_MODE_PARENT) {
        return 1;
    }
    switch (gConnectionWork->mStep) {
        case CONNECTION_STEP_PARENT_BLOCK_TRANSFER:
        case CONNECTION_STEP_CHILD_BLOCK_TRANSFER:
            StartBlockCountRequest();
            break;
        case CONNECTION_STEP_BLOCK_COUNT_REQUEST:
            switch (ConnectionGetConnectionMode()) {
                case CONNECTION_MODE_PARENT:
                    gConnectionWork->mStep = CONNECTION_STEP_PARENT_BLOCK_TRANSFER;
                    break;
                case CONNECTION_MODE_CHILD:
                    gConnectionWork->mStep = CONNECTION_STEP_CHILD_BLOCK_TRANSFER;
                    break;
            }
            finished = TRUE;
            break;
    }
    return finished;
}

void UpdateConnectionSendTimer(void) {
    s32 receivedChunkCount;
    s32 chunkCount;

    if (gConnectionWork->mState != CONNECTION_STATE_GATHERING) {
        return;
    }
    if (gConnectionWork->mStep == CONNECTION_STEP_BLOCK_DATA_REQUEST) {
        WBT_GetCurrentDownloadProgress(gConnectionWork->mBlockInfos[0]->mId, 0, &receivedChunkCount, &chunkCount);
    }
    if (gConnectionWork->mSendTimer != 0) {
        gConnectionWork->mSendTimer = gConnectionWork->mSendTimer - 1;
        return;
    }
    if (ConnectionGetConnectionMode() == CONNECTION_MODE_NONE) {
        return;
    }
    QueuePacketToPort();
}

// Child side; returns 1 when done, 2 on failure, 3 when an error has been recorded, 0 otherwise (the parent returns 1
// at once).
s32 AdvanceBlockReceive(void) {
    BOOL finished;

    finished = FALSE;
    if (IsConnectionActiveNotEndingWithError()) {
        return 3;
    }
    if (gConnectionWork->mMPSetupActive != 0) {
        u16 ownIndex;

        ownIndex = gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD ? gConnectionWork->mOwnIndex : 0;
        if (ownIndex == 0xffff) {
            return 2;
        }
    }
    if (gConnectionWork->mRequestPending != 0) {
        return 0;
    }
    if (ConnectionGetConnectionMode() == CONNECTION_MODE_PARENT) {
        return 1;
    }
    switch (gConnectionWork->mStep) {
        case CONNECTION_STEP_PARENT_BLOCK_TRANSFER:
        case CONNECTION_STEP_CHILD_BLOCK_TRANSFER:
        case CONNECTION_STEP_BLOCK_COUNT_REQUEST:
            gConnectionWork->mBlockIndex = 0;
            StartBlockNodeRequest();
            break;
        case CONNECTION_STEP_BLOCK_NODE_REQUEST:
            StartBlockDataRequest();
            break;
        case CONNECTION_STEP_BLOCK_DATA_REQUEST:
            StartSendWordRequest(1, 0);
            break;
        case CONNECTION_STEP_SEND_WORD_REQUEST:
            gConnectionWork->mMPSetupActive = 0;
            finished = TRUE;
            break;
    }
    return finished;
}

// Polled until it returns TRUE.
BOOL FinishDataSharingSync(void) {
    BOOL finished;
    DataSharing *dataSharing;

    finished = FALSE;
    dataSharing = &gConnectionWork->mDataSharing;
    if (!IsConnectionActive()) {
        return TRUE;
    }
    if (!(gConnectionWork->mFlags & CONNECTION_FLAG_SCENE_RUNNING)) {
        return TRUE;
    }
    if (IsDataSharingSyncDone() != 0) {
        return TRUE;
    }
    if (dataSharing->mSharedDataCopied[0] != 0) {
        ConnectionWork *connection;

        connection = gConnectionWork;
        if (HasSharingRecordSyncToggleBit(dataSharing->mReceivedRecords) != 0) {
            if ((connection->mFlags & CONNECTION_FLAG_RACE) != 0) {
                connection->mState = CONNECTION_STATE_SYNCED_RACE;
            } else {
                connection->mState = CONNECTION_STATE_SYNCED;
            }
            finished = TRUE;
            gConnectionWork->mUnk_15f4 = 0;
        } else if (ConnectionGetConnectionMode() == CONNECTION_MODE_PARENT) {
            if (AreChildSharingRecordsSynced(dataSharing, dataSharing->mReceivedRecords) != 0) {
                connection->mStatusFlags |= CONNECTION_STATUS_SHARING_SYNCED;
            }
        }
    }
    return finished;
}

// Starts the wait that FinishDataSharingSync completes; always returns 1.
s32 StartDataSharingSync(void) {
    if (IsConnectionActive()) {
        gConnectionWork->mState = CONNECTION_STATE_SYNC_WAIT;
        gConnectionWork->mStatusFlags &= ~CONNECTION_STATUS_SHARING_SYNCED;
        if (gConnectionWork->mSyncToggle == 0) {
            gConnectionWork->mSyncToggle = 1;
        } else {
            gConnectionWork->mSyncToggle = 0;
        }
    }
    return 1;
}

s32 GetZeroWordResult(void) {
    ConnectionWork *connection;
    s32 result;
    s32 count;

    result = WORD_WAIT_RESULT_WAITING;
    connection = gConnectionWork;
    if (GetWorkConnectionMode(connection) != 1) {
        result = WORD_WAIT_RESULT_NOT_RECEIVED;
    } else {
        if (GetWorkConnectionMode(connection) == 1) {
            if ((connection->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
                count = connection->mWaitToSendCount;
            } else {
                count = connection->mChildren.mChildCount;
            }
        } else {
            count = 0;
        }
        if (count == 0) {
            if (connection->mZeroWordReceived != 0) {
                result = WORD_WAIT_RESULT_RECEIVED;
            } else {
                result = WORD_WAIT_RESULT_NOT_RECEIVED;
            }
        }
    }
    return result;
}

void InitConnection(void *heap) {
    gConnectionWork = HeapAllocAligned(heap, sizeof(ConnectionWork), HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mConnectionMode = CONNECTION_MODE_NONE;
    gConnectionWork->mState = CONNECTION_STATE_IDLE;
    gConnectionWork->mErrorCode = CONNECTION_ERROR_NONE;
    gConnectionWork->mStep = CONNECTION_STEP_NOTHING;
    gConnectionWork->mRequestPending = 0;
    gConnectionWork->mFlags = 0;
    gConnectionWork->mUnk_0456_0 = 0;
}

// Bytes of the exp heap that the connection code allocates its buffers from.
#define CONNECTION_HEAP_BYTES 0x7800

void InitConnectionBuffers(void *heap) {
    gConnectionWork->mWmWorkBuffer = HeapAllocAligned(heap, 0xf00, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mParentParameter = HeapAllocAligned(heap, 0x40, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mScanParams = HeapAllocAligned(heap, 0x20, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mParentBssDesc = HeapAllocAligned(heap, 0xc0, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mScanBssDescBuffer = HeapAllocAligned(heap, 0xc0, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mScanExParams = HeapAllocAligned(heap, 0x44, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mScanExBuffer = HeapAllocAligned(heap, CONNECTION_SCAN_BUFFER_SIZE, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mStartMPSendBufferSize = CONNECTION_MP_SEND_BUFFER_SIZE;
    gConnectionWork->mStartMPSendBuffer =
        HeapAllocAligned(heap, gConnectionWork->mStartMPSendBufferSize, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mStartMPReceiveBufferSize = CONNECTION_MP_RECEIVE_BUFFER_SIZE;
    gConnectionWork->mStartMPReceiveBuffer =
        HeapAllocAligned(heap, gConnectionWork->mStartMPReceiveBufferSize, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mSharingInfo = HeapAllocAligned(heap, 0x820, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mSharingDataSet = HeapAllocAligned(heap, 0x200, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mSharingSendRecord = HeapAllocAligned(heap, 8, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mSharingReceiveRecords = HeapAllocAligned(heap, 0x40, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mMPDataBuffer = HeapAllocAligned(heap, 0x18, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mAllocHeap = 0;
    gConnectionWork->mMultiBootWork = 0;
    gConnectionWork->mMultiBootSegment = 0;
    gConnectionWork->mChildren.mGameInfo = HeapAllocAligned(heap, 0x1c, HEAP_ALIGN_CACHE_LINE);
    gConnectionWork->mHeap = NNS_FndCreateExpHeapEx(HeapAlloc(heap, CONNECTION_HEAP_BYTES), CONNECTION_HEAP_BYTES, 1);
    gConnectionWork->mMPReceiveBuffer = 0;
    gConnectionWork->mMPReceiveBufferSize = 0;
    gConnectionWork->mMPSendBuffer = 0;
    gConnectionWork->mMPSendBufferSize = 0;
    gConnectionWork->mUnk_0456_0 = 1;
    ResetConnection();
}

void FinishConnectionEnd(void) {
    while (AdvanceConnectionEndStopOnError() != 1) {
    }
    gConnectionWork->mUnk_0456_0 = 0;
}

void ResetDataSharing(DataSharing *dataSharing) {
    ParticipantTablesView *tables;
    s32 index;
    s32 valueIndex;

    dataSharing->mParticipantMask = 0;
    MI_CpuFill8(gConnectionWork->mSharingSendRecord, 0, 8);
    for (index = 0; index < 8; index++) {
        dataSharing->mSharedDataCopied[index] = 0;
        MI_CpuFill8(&dataSharing->mReceivedRecords[index], 0, 8);
    }
    dataSharing->mUnk_3c[0] = 0;
    for (index = 0; index < 7; index++) {
        dataSharing->mUnk_3c[index] = 0;
    }
    dataSharing->mUnk_4a = 0;
    dataSharing->mSharingPhase = DATA_SHARING_PHASE_AFTER_RESET;
    dataSharing->mUnk_38 = 0;
    dataSharing->mUnk_30 = 0;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SHARING_NOT_UPDATED;
    gConnectionWork->mStatusFlags &= ~CONNECTION_STATUS_SHARING_SYNCED;
    tables = &gConnectionWork->mParticipantTables;
    tables->mLeftParticipantMask = 0;
    tables->mUnk_68 = 0;
    for (index = 0; index < 8; index++) {
        for (valueIndex = 0; valueIndex < 3; valueIndex++) {
            tables->mUnk_00[index].mUnk_00[valueIndex] = 0;
        }
    }
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SHARING_NOT_UPDATED;
}

void ResetConnectionData(void) {
    u8 *bytes;
    s32 childIndex;
    s32 innerIndex;
    s32 byteIndex;
    s32 targetByteIndex;

    for (childIndex = 0; childIndex < 7; childIndex++) {
        gConnectionWork->mChildren.mEntries[childIndex].mAid = CHILD_ENTRY_NO_AID;
        bytes = gConnectionWork->mChildren.mEntries[childIndex].mBytes;
        for (innerIndex = 0; innerIndex < 6; innerIndex++) {
            bytes[innerIndex] = 0;
        }
    }
    gConnectionWork->mChildren.mExpectedRecordMask = 0;
    gConnectionWork->mChildren.mChildMask = 0;
    gConnectionWork->mChildren.mChildCount = 0;
    gConnectionWork->mChildren.mUnk_3c = 0;
    gConnectionWork->mChildren.mDisconnectingIndex = -1;
    gConnectionWork->mParentChannel = -1;
    gConnectionWork->mRemovedChildMask = 0;
    gConnectionWork->mStatusFlags = 0;
    gConnectionWork->mChildren.mNameSendIndex = 0;
    MI_CpuCopy8(gBackupBuffers->mFirstBlock->mPlayerName, gConnectionWork->mChildren.mGameInfo, PLAYER_NAME_BYTES);
    gConnectionWork->mChildren.mGameInfo->mGameInfoPart.mLanguageIndex = gStartupWork->mLanguageIndex;
    gConnectionWork->mChildren.mGameInfo->mGameInfoPart.mChildCount = 0;
    for (innerIndex = 0; innerIndex < 4; innerIndex++) {
        gConnectionWork->mScanSlots[innerIndex].mInUse = 0;
        gConnectionWork->mScanSlots[innerIndex].mAge = 0;
        bytes = gConnectionWork->mScanSlots[innerIndex].mKey.mBytes;
        for (byteIndex = 0; byteIndex < 6; byteIndex++) {
            bytes[byteIndex] = 0;
        }
    }
    gConnectionWork->mOwnIndex = CONNECTION_OWN_INDEX_NONE;
    gConnectionWork->mRememberedScanKeyHeld = 0;
    gConnectionWork->mUnk_0434 = 0;
    gConnectionWork->mScanMissCount = 1;
    gConnectionWork->mExpectedRecordMask = 0;
    gConnectionWork->mOperationFlags = 0;
    gConnectionWork->mLanguageIndex = LANGUAGE_UNSUFFIXED;
    gConnectionWork->mReceivedNameMask = 0;
    gConnectionWork->mKeepScanning = 0;
    bytes = gConnectionWork->mScanState.mTargetAddress;
    for (targetByteIndex = 0; targetByteIndex < 6; targetByteIndex++) {
        bytes[targetByteIndex] = 0;
    }
    gConnectionWork->mGroupSendMask = 0;
    gConnectionWork->mUnk_0458 = 0;
    gConnectionWork->mWaitToSendCount = 0;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SEND_READY;
    ClearParticipantBits();
    ResetDataSharing(&gConnectionWork->mDataSharing);
}

void InitRaceConnection(void) {
    ParticipantTablesView *tables;
    ConnectionWork *connection;
    RandomState *random;
    s32 index;
    s32 valueIndex;
    s32 shiftedValue;
    s32 addedValue;

    tables = &gConnectionWork->mParticipantTables;
    tables->mLeftParticipantMask = 0;
    tables->mUnk_68 = 0;
    for (index = 0; index < 8; index++) {
        for (valueIndex = 0; valueIndex < 3; valueIndex++) {
            tables->mUnk_00[index].mUnk_00[valueIndex] = 0;
        }
    }
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SHARING_NOT_UPDATED;
    gConnectionWork->mFlags |= CONNECTION_FLAG_RACE;
    connection = gConnectionWork;
    shiftedValue = 0;
    switch (ConnectionGetConnectionMode()) {
        case CONNECTION_MODE_PARENT:
            shiftedValue = connection->mParentParameter->mTgid;
            break;
        case CONNECTION_MODE_CHILD:
            shiftedValue = connection->mParentBssDesc->mGameInfo.mTgid;
            break;
    }
    addedValue = 0;
    switch (ConnectionGetConnectionMode()) {
        case CONNECTION_MODE_PARENT:
            addedValue = connection->mParentParameter->mTgid;
            break;
        case CONNECTION_MODE_CHILD:
            addedValue = connection->mParentBssDesc->mGameInfo.mTgid;
            break;
    }
    connection->mRandom.mStateLow = addedValue + (shiftedValue << 10);
    random = &connection->mRandom;
    random->mStateHigh = 0;
    random->mMultiplierLow = CONNECTION_RANDOM_MULTIPLIER_LOW;
    random->mMultiplierHigh = CONNECTION_RANDOM_MULTIPLIER_HIGH;
    random->mIncrementLow = CONNECTION_RANDOM_INCREMENT_LOW;
    random->mIncrementHigh = 0;
}
