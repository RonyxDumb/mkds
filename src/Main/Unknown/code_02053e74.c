#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204f240.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_02052000.h"
#include "Main/Unknown/code_02053000.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_02054f38.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_020562b4.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_020176c0.h"
#include "code_0214d018.h"

#pragma opt_rebuildconditionals off

static inline u32 func_02053e74_inline(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline s32 func_02053e74_inline2(void) {
    BOOL r = FALSE;
    if (func_02053e74_inline() != 0 && gConnectionWork->mState != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02053e74_inline3(void) {
    BOOL r = FALSE;
    if (func_02053e74_inline2() && !(gConnectionWork->mFlags & CONNECTION_FLAG_ENDING)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02053e74_inline4(void) {
    BOOL r = FALSE;
    if (func_02053e74_inline3() && gConnectionWork->mErrorCode != 9) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02054754_inline(SharingReceiveRecord *e) {
    BOOL r = FALSE;
    u8 f = e->mUnk_06_0;
    if (gConnectionWork->mSyncToggle == 0) {
        if (f & 1) {
            r = TRUE;
        }
    } else {
        if (f & 2) {
            r = TRUE;
        }
    }
    return r;
}

static inline s32 func_02054754_inline2(DataSharing *dataSharing, SharingReceiveRecord *e) {
    u8 mask = gConnectionWork->mChildren.mChildMask;
    u8 i;
    BOOL ok = FALSE;
    u16 m;

    for (i = 1; i < 8; i++) {
        if (mask & (1 << i)) {
            if (dataSharing->mSharedDataCopied[i] == 0) {
                ok = FALSE;
                i = 8;
            } else {
                m = gConnectionWork->mSyncToggle == 0 ? 1 : 2;
                if ((m & e[i].mUnk_06_0) == 0) {
                    ok = FALSE;
                    i = 8;
                } else {
                    ok = TRUE;
                }
            }
        }
    }
    return ok;
}

static inline u32 func_0205465c_inline(ConnectionWork *p) {
    if (p == NULL) {
        return 0;
    }
    return p->mConnectionMode;
}

// Returns 1 once the last step is issued, 2 on failure, 3 when an error has been recorded, 0 otherwise.
s32 AdvanceConnectionSetup(s32 isParent, void *b) {
    BOOL finished;

    finished = FALSE;
    if (gConnectionWork->mMPSetupActive != 0) {
        u16 ownIndex;

        ownIndex = gConnectionWork->mConnectionMode == 2 ? gConnectionWork->mOwnIndex : 0;
        if (ownIndex == 0xffff) {
            return 2;
        }
    }
    if (func_02053e74_inline4()) {
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
            FillGhostParentParameter(b);
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
                SetOwnIndexFromConnection();
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
    if (func_02053e74_inline4()) {
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
    if (func_02053e74_inline() == 1) {
        return 1;
    }
    switch (gConnectionWork->mStep) {
        case 0x28:
        case 0x29:
            StartBlockCountRequest();
            break;
        case 0x2a:
            switch (func_02053e74_inline()) {
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
        WBT_GetCurrentDownloadProgress(gConnectionWork->mBlockInfos[0]->mBlockId, 0, &receivedChunkCount, &chunkCount);
    }
    if (gConnectionWork->mSendTimer != 0) {
        gConnectionWork->mSendTimer = gConnectionWork->mSendTimer - 1;
        return;
    }
    if (func_02053e74_inline() == 0) {
        return;
    }
    QueuePacketToPort();
}

// Child side; returns 1 when done, 2 on failure, 3 when an error has been recorded, 0 otherwise (the parent returns 1
// at once).
s32 AdvanceBlockReceive(void) {
    BOOL finished;

    finished = FALSE;
    if (func_02053e74_inline4()) {
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
    if (func_02053e74_inline() == 1) {
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
    if (!func_02053e74_inline2()) {
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
        if (func_02054754_inline(dataSharing->mUnk_0c) != 0) {
            if ((connection->mFlags & CONNECTION_FLAG_RACE) != 0) {
                connection->mState = 9;
            } else {
                connection->mState = 8;
            }
            finished = TRUE;
            gConnectionWork->mUnk_15f4 = 0;
        } else if (func_02053e74_inline() == 1) {
            if (func_02054754_inline2(dataSharing, dataSharing->mUnk_0c) != 0) {
                connection->mStatusFlags |= CONNECTION_STATUS_SHARING_SYNCED;
            }
        }
    }
    return finished;
}

// Starts the wait that FinishDataSharingSync completes; always returns 1.
s32 StartDataSharingSync(void) {
    if (func_02053e74_inline2()) {
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
    if (func_0205465c_inline(connection) != 1) {
        result = 2;
    } else {
        if (func_0205465c_inline(connection) == 1) {
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
    gConnectionWork->mChildren.mUnk_38 = HeapAllocAligned(heap, 0x1c, 0x20);
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
    ParticipantTablesView *q;
    s32 i;
    s32 j;

    dataSharing->mParticipantMask = 0;
    MI_CpuFill8(gConnectionWork->mSharingSendRecord, 0, 8);
    for (i = 0; i < 8; i++) {
        dataSharing->mSharedDataCopied[i] = 0;
        MI_CpuFill8(&dataSharing->mUnk_0c[i], 0, 8);
    }
    dataSharing->mUnk_3c[0] = 0;
    for (i = 0; i < 7; i++) {
        dataSharing->mUnk_3c[i] = 0;
    }
    dataSharing->mUnk_4a = 0;
    dataSharing->mUnk_34 = 5;
    dataSharing->mUnk_38 = 0;
    dataSharing->mUnk_30 = 0;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SHARING_NOT_UPDATED;
    gConnectionWork->mStatusFlags &= ~CONNECTION_STATUS_SHARING_SYNCED;
    q = &gConnectionWork->mUnk_1e4c_view;
    q->mLeftParticipantMask = 0;
    q->mUnk_68 = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            q->mUnk_00[i].mUnk_00[j] = 0;
        }
    }
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SHARING_NOT_UPDATED;
}

void ResetConnectionData(void) {
    u8 *q;
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    for (i = 0; i < 7; i++) {
        gConnectionWork->mChildren.mEntries[i].mAid = 0xffff;
        q = gConnectionWork->mChildren.mEntries[i].mUnk_00;
        for (j = 0; j < 6; j++) {
            q[j] = 0;
        }
    }
    gConnectionWork->mChildren.mUnk_42 = 0;
    gConnectionWork->mChildren.mChildMask = 0;
    gConnectionWork->mChildren.mChildCount = 0;
    gConnectionWork->mChildren.mUnk_3c = 0;
    gConnectionWork->mChildren.mDisconnectingIndex = -1;
    gConnectionWork->mParentChannel = -1;
    gConnectionWork->mRemovedChildMask = 0;
    gConnectionWork->mStatusFlags = 0;
    gConnectionWork->mChildren.mNameSendIndex = 0;
    MI_CpuCopy8(data_0217aa08->mFirstBlock->mPlayerName, gConnectionWork->mChildren.mUnk_38, 0x14);
    gConnectionWork->mChildren.mUnk_38->mUnk_0e.mLanguageIndex = gStartupWork->mLanguageIndex;
    gConnectionWork->mChildren.mUnk_38->mUnk_0e.mChildCount = 0;
    for (j = 0; j < 4; j++) {
        gConnectionWork->mScanSlots[j].mInUse = 0;
        gConnectionWork->mScanSlots[j].mAge = 0;
        q = gConnectionWork->mScanSlots[j].mKey.mUnk_00;
        for (k = 0; k < 6; k++) {
            q[k] = 0;
        }
    }
    gConnectionWork->mOwnIndex = 0xffff;
    gConnectionWork->mUnk_0438 = 0;
    gConnectionWork->mUnk_0434 = 0;
    gConnectionWork->mUnk_0439 = 1;
    gConnectionWork->mExpectedRecordMask = 0;
    gConnectionWork->mOperationFlags = 0;
    gConnectionWork->mLanguageIndex = 0;
    gConnectionWork->mReceivedNameMask = 0;
    gConnectionWork->mKeepScanning = 0;
    q = gConnectionWork->mUnk_00ac_view.mTargetAddress;
    for (l = 0; l < 6; l++) {
        q[l] = 0;
    }
    gConnectionWork->mGroupSendMask = 0;
    gConnectionWork->mUnk_0458 = 0;
    gConnectionWork->mWaitToSendCount = 0;
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SEND_READY;
    ClearParticipantBits();
    ResetDataSharing(&gConnectionWork->mUnk_15bc_view);
}

void InitRaceConnection(void) {
    ParticipantTablesView *q;
    ConnectionWork *connection;
    RandomState *random;
    s32 i;
    s32 j;
    s32 a;
    s32 b;

    q = &gConnectionWork->mUnk_1e4c_view;
    q->mLeftParticipantMask = 0;
    q->mUnk_68 = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 3; j++) {
            q->mUnk_00[i].mUnk_00[j] = 0;
        }
    }
    gConnectionWork->mFlags &= ~CONNECTION_FLAG_SHARING_NOT_UPDATED;
    gConnectionWork->mFlags |= CONNECTION_FLAG_RACE;
    connection = gConnectionWork;
    a = 0;
    switch (func_02053e74_inline()) {
        case 1:
            a = connection->mParentParameter->mUnk_0c;
            break;
        case 2:
            a = connection->mParentBssDesc->mGameInfo.mTgid;
            break;
    }
    b = 0;
    switch (func_02053e74_inline()) {
        case 1:
            b = connection->mParentParameter->mUnk_0c;
            break;
        case 2:
            b = connection->mParentBssDesc->mGameInfo.mTgid;
            break;
    }
    connection->mRandom.mStateLow = b + (a << 10);
    random = &connection->mRandom;
    random->mStateHigh = 0;
    random->mMultiplierLow = 0x6c078965;
    random->mMultiplierHigh = 0x5d588b65;
    random->mIncrementLow = 0x269ec3;
    random->mIncrementHigh = 0;
}
