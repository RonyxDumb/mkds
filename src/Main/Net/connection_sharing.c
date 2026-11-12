#include "Main/Net/connection_sharing.h"
#include "Main/System/heap.h"
#include "Main/Net/pending_files.h"
#include "Main/Net/participant_get_connection.h"
#include "Main/Net/connection.h"
#include "Main/Net/wbt_requests.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Net/scan.h"
#include "Main/Unknown/code_02052000.h"
#include "Main/Unknown/code_02053000.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Net/own_index.h"
#include "Main/Net/connect_non_multiboot.h"
#include "Main/Net/participant_bits.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_020176c0.h"
#include "code_0214d018.h"

#pragma opt_rebuildconditionals off

static inline u32 ConnectionGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline s32 IsConnectionActive(void) {
    BOOL result = FALSE;
    if (ConnectionGetConnectionMode() != 0 && gConnectionWork->mState != 13) {
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
    if (IsConnectionActiveNotEnding() && gConnectionWork->mErrorCode != 9) {
        result = TRUE;
    }
    return result;
}

static inline s32 HasSharingRecordSyncToggleBit(SharingReceiveRecord *receiveRecord) {
    BOOL result = FALSE;
    u8 toggleBits = receiveRecord->mUnk_06_0;
    if (gConnectionWork->mSyncToggle == 0) {
        if (toggleBits & 1) {
            result = TRUE;
        }
    } else {
        if (toggleBits & 2) {
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
                toggleBit = gConnectionWork->mSyncToggle == 0 ? 1 : 2;
                if ((toggleBit & receiveRecords[childIndex].mUnk_06_0) == 0) {
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

        ownIndex = gConnectionWork->mConnectionMode == 2 ? gConnectionWork->mOwnIndex : 0;
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
        case 0:
        case 21:
            gConnectionWork->mFlags &= ~CONNECTION_FLAG_MULTIBOOT_SETUP;
            gConnectionWork->mState = 1;
            Initialize();
            break;
        case 1:
            gConnectionWork->mState = 11;
            if (isParent != 0) {
                SetLifeTime(0x28);
            } else {
                StartScan(0, NULL, NULL);
            }
            break;
        case 2:
            if (isParent != 0) {
                SetLifeTime(0x28);
            } else {
                StartScan(0, NULL, NULL);
            }
            break;
        case 3:
            MeasureChannel(0);
            break;
        case 4:
            SetParentChannelLowestSum();
            FillGhostParentParameter(ghostSource);
            SetParentParameter();
            break;
        case 5:
            StartParent(NULL);
            break;
        case 6:
            StartMPWithBuffers();
            break;
        case 7:
            if (gConnectionWork->mSelectedScanEntry == -1) {
                StartScan(0, NULL, NULL);
            } else {
                EndScan();
            }
            break;
        case 9:
            StartConnect(NULL, NULL, NULL, NULL, ResetOwnIndex);
            break;
        case 10:
            gConnectionWork->mMPSetupActive = 1;
            StartMPWithBuffers();
            break;
        case 11:
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

        ownIndex = gConnectionWork->mConnectionMode == 2 ? gConnectionWork->mOwnIndex : 0;
        if (ownIndex == 0xffff) {
            return 2;
        }
    }
    if (gConnectionWork->mRequestPending != 0) {
        return 0;
    }
    if (ConnectionGetConnectionMode() == 1) {
        return 1;
    }
    switch (gConnectionWork->mStep) {
        case 0x28:
        case 0x29:
            StartBlockCountRequest();
            break;
        case 0x2a:
            switch (ConnectionGetConnectionMode()) {
                case 1:
                    gConnectionWork->mStep = 0x28;
                    break;
                case 2:
                    gConnectionWork->mStep = 0x29;
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

    if (gConnectionWork->mState != 11) {
        return;
    }
    if (gConnectionWork->mStep == 0x2c) {
        WBT_GetCurrentDownloadProgress(gConnectionWork->mBlockInfos[0]->mId, 0, &receivedChunkCount, &chunkCount);
    }
    if (gConnectionWork->mSendTimer != 0) {
        gConnectionWork->mSendTimer = gConnectionWork->mSendTimer - 1;
        return;
    }
    if (ConnectionGetConnectionMode() == 0) {
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

        ownIndex = gConnectionWork->mConnectionMode == 2 ? gConnectionWork->mOwnIndex : 0;
        if (ownIndex == 0xffff) {
            return 2;
        }
    }
    if (gConnectionWork->mRequestPending != 0) {
        return 0;
    }
    if (ConnectionGetConnectionMode() == 1) {
        return 1;
    }
    switch (gConnectionWork->mStep) {
        case 0x28:
        case 0x29:
        case 0x2a:
            gConnectionWork->mBlockIndex = 0;
            StartBlockNodeRequest();
            break;
        case 0x2b:
            StartBlockDataRequest();
            break;
        case 0x2c:
            StartSendWordRequest(1, 0);
            break;
        case 0x2e:
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
    dataSharing = &gConnectionWork->mUnk_15bc_view;
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
                connection->mState = 9;
            } else {
                connection->mState = 8;
            }
            finished = TRUE;
            gConnectionWork->mUnk_15f4 = 0;
        } else if (ConnectionGetConnectionMode() == 1) {
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
        gConnectionWork->mState = 7;
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

    result = 0;
    connection = gConnectionWork;
    if (GetWorkConnectionMode(connection) != 1) {
        result = 2;
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
                result = 1;
            } else {
                result = 2;
            }
        }
    }
    return result;
}

void InitConnection(void *heap) {
    gConnectionWork = HeapAllocAligned(heap, 0x1f00, 0x20);
    gConnectionWork->mConnectionMode = 0;
    gConnectionWork->mState = 0;
    gConnectionWork->mErrorCode = 9;
    gConnectionWork->mStep = 0;
    gConnectionWork->mRequestPending = 0;
    gConnectionWork->mFlags = 0;
    gConnectionWork->mUnk_0456_0 = 0;
}

void InitConnectionBuffers(void *heap) {
    gConnectionWork->mWmWorkBuffer = HeapAllocAligned(heap, 0xf00, 0x20);
    gConnectionWork->mParentParameter = HeapAllocAligned(heap, 0x40, 0x20);
    gConnectionWork->mScanParams = HeapAllocAligned(heap, 0x20, 0x20);
    gConnectionWork->mParentBssDesc = HeapAllocAligned(heap, 0xc0, 0x20);
    gConnectionWork->mScanBssDescBuffer = HeapAllocAligned(heap, 0xc0, 0x20);
    gConnectionWork->mScanExParams = HeapAllocAligned(heap, 0x44, 0x20);
    gConnectionWork->mScanExBuffer = HeapAllocAligned(heap, 0x400, 0x20);
    gConnectionWork->mStartMPSendBufferSize = 0x1c0;
    gConnectionWork->mStartMPSendBuffer = HeapAllocAligned(heap, gConnectionWork->mStartMPSendBufferSize, 0x20);
    gConnectionWork->mStartMPReceiveBufferSize = 0x400;
    gConnectionWork->mStartMPReceiveBuffer = HeapAllocAligned(heap, gConnectionWork->mStartMPReceiveBufferSize, 0x20);
    gConnectionWork->mSharingInfo = HeapAllocAligned(heap, 0x820, 0x20);
    gConnectionWork->mSharingDataSet = HeapAllocAligned(heap, 0x200, 0x20);
    gConnectionWork->mSharingSendRecord = HeapAllocAligned(heap, 8, 0x20);
    gConnectionWork->mSharingReceiveRecords = HeapAllocAligned(heap, 0x40, 0x20);
    gConnectionWork->mMPDataBuffer = HeapAllocAligned(heap, 0x18, 0x20);
    gConnectionWork->mAllocHeap = 0;
    gConnectionWork->mMultiBootWork = 0;
    gConnectionWork->mMultiBootSegment = 0;
    gConnectionWork->mChildren.mGameInfo = HeapAllocAligned(heap, 0x1c, 0x20);
    gConnectionWork->mHeap = NNS_FndCreateExpHeapEx(HeapAlloc(heap, 0x7800), 0x7800, 1);
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
    dataSharing->mSharingPhase = 5;
    dataSharing->mUnk_38 = 0;
    dataSharing->mUnk_30 = 0;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SHARING_NOT_UPDATED;
    gConnectionWork->mStatusFlags &= ~CONNECTION_STATUS_SHARING_SYNCED;
    tables = &gConnectionWork->mUnk_1e4c_view;
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
        gConnectionWork->mChildren.mEntries[childIndex].mAid = 0xffff;
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
    MI_CpuCopy8(gBackupBuffers->mFirstBlock->mPlayerName, gConnectionWork->mChildren.mGameInfo, 0x14);
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
    gConnectionWork->mOwnIndex = 0xffff;
    gConnectionWork->mRememberedScanKeyHeld = 0;
    gConnectionWork->mUnk_0434 = 0;
    gConnectionWork->mUnk_0439 = 1;
    gConnectionWork->mExpectedRecordMask = 0;
    gConnectionWork->mOperationFlags = 0;
    gConnectionWork->mLanguageIndex = 0;
    gConnectionWork->mReceivedNameMask = 0;
    gConnectionWork->mKeepScanning = 0;
    bytes = gConnectionWork->mUnk_00ac_view.mTargetAddress;
    for (targetByteIndex = 0; targetByteIndex < 6; targetByteIndex++) {
        bytes[targetByteIndex] = 0;
    }
    gConnectionWork->mGroupSendMask = 0;
    gConnectionWork->mUnk_0458 = 0;
    gConnectionWork->mWaitToSendCount = 0;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SEND_READY;
    ClearParticipantBits();
    ResetDataSharing(&gConnectionWork->mUnk_15bc_view);
}

void InitRaceConnection(void) {
    ParticipantTablesView *tables;
    ConnectionWork *connection;
    RandomState *random;
    s32 index;
    s32 valueIndex;
    s32 shiftedValue;
    s32 addedValue;

    tables = &gConnectionWork->mUnk_1e4c_view;
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
        case 1:
            shiftedValue = connection->mParentParameter->mTgid;
            break;
        case 2:
            shiftedValue = connection->mParentBssDesc->mGameInfo.mTgid;
            break;
    }
    addedValue = 0;
    switch (ConnectionGetConnectionMode()) {
        case 1:
            addedValue = connection->mParentParameter->mTgid;
            break;
        case 2:
            addedValue = connection->mParentBssDesc->mGameInfo.mTgid;
            break;
    }
    connection->mRandom.mStateLow = addedValue + (shiftedValue << 10);
    random = &connection->mRandom;
    random->mStateHigh = 0;
    random->mMultiplierLow = 0x6c078965;
    random->mMultiplierHigh = 0x5d588b65;
    random->mIncrementLow = 0x269ec3;
    random->mIncrementHigh = 0;
}
