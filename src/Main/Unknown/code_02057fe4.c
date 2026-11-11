#include "Main/Unknown/code_02057fe4.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_020562b4.h"
#include "Main/Unknown/code_02056464.h"
#include "Main/Unknown/code_02058000.h"
#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/code_02058efc.h"
#include "Main/Unknown/code_02059000.h"

#include "Main/Unknown/code_02050000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02051000.h"
#include "Main/Unknown/code_02052000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "code_0200eddc.h"
#include "code_02142eac.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02059920.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204bca0.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02050034.h"
#include "Main/Unknown/code_0205928c.h"

#pragma thumb on

void RequestMPState15AfterCombine(void) {
    MPStateMachine *stateMachine;
    CombineParticipantBits();
    stateMachine = &gConnectionWork->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = 0xf;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

#pragma thumb off

#pragma thumb on

static inline u32 MPStatesGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline void MPStatesRequestMPState(u16 nextState) {
    MPStateMachine *stateMachine = &gConnectionWork->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = nextState;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

void UpdateMPState5(void) {
    u8 participantMask;
    u16 waitFrames;

    if (MPStatesGetConnectionMode() == 1) {
        participantMask = gConnectionWork->mParticipantMask;
        if (IsAllMPChildSharedDataCopied() != 0) {
            if (QueueMPDataHalfwordAndWord(1, participantMask, participantMask) != FALSE) {
                SetParticipantMask(participantMask);
            }
        } else {
            waitFrames = gConnectionWork->mMPStateMachine.mChildDataWaitFrames;
            if (waitFrames > 0xe10) {
                SetRequestErrorCode(7);
                return;
            }
            gConnectionWork->mMPStateMachine.mChildDataWaitFrames = waitFrames + 1;
        }
    }
}

void UpdateMPState6(void) {
    MPStateMachine *stateMachine;

    if (MPStatesGetConnectionMode() == 1 && (gConnectionWork->mFlags & CONNECTION_FLAG_SEND_READY)) {
        if (QueueMPDataHalfwordAndWord(2, gConnectionWork->mChildren.mChildMask, gConnectionWork->mGroupSendMask) !=
            FALSE) {
            stateMachine = &gConnectionWork->mMPStateMachine;
            stateMachine->mStateMachine.mNextState = 1;
            stateMachine->mStateMachine.mNextStateRequested = 1;
        }
    }
}

void EnterMPState3(void) {
    gConnectionWork->mSyncState = 0;
    gConnectionWork->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
}

#pragma thumb off

#pragma thumb on

void UpdateMPState3(void) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceMainAndMenuDLArchives();
    if (result == 1) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = 4;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

void UpdateMPState1(void) {
    BOOL r;
    BOOL a;
    BOOL b;
    s32 v;
    ConnectionWork *connectionWork;

    r = TRUE;
    b = FALSE;
    connectionWork = gConnectionWork;
    if (connectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) {
        a = TRUE;
        if (connectionWork == NULL) {
            v = 0;
        } else {
            v = connectionWork->mConnectionMode;
        }
        if (v != 1 && gBootInfo->mUnk_00 != 2) {
            a = FALSE;
        }
        if (a != FALSE) {
            b = TRUE;
        }
    }
    if (b != FALSE) {
        if (GetRomArchiveState() == 2) {
            SetGroupSendMaskAsParent(gConnectionWork->mGroupSendMask);
        } else {
            r = FALSE;
        }
    }
    if (r != FALSE) {
        MPStatesRequestMPState(2);
    }
}

void EnterMPState2(void) {
    if (gBootInfo->mUnk_00 == 2) {
        StartLoadOverlay(2);
    }
}

void UpdateMPState2(void) {
    if (TryFinishOverlayLoad() != 0) {
        if (gBootInfo->mUnk_00 == 2) {
            CreateOverlayFrmHeap();
            InitArchiveBuffersOnOverlayHeap();
        }
        MPStatesRequestMPState(3);
    }
}

void EnterMPState4(void) {
    gConnectionWork->mSyncState = 0;
    gConnectionWork->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    gConnectionWork->mCallbackFailed = 0;
}

#pragma thumb off

#pragma thumb on

void UpdateMPState4(void) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceSyncedCallback(LoadSndDataFromFileCallback);
    if (result == 1) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = 0xc;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

// Clears the per-slot flags of received chunks: 0x12 per slot for the parent, 2 for a child.
void EnterMPState7(void) {
    s32 slot;
    u32 flagIndex;
    u32 flagCount;

    WM_SetPortCallback(14, MPChunkPortCallback, NULL);
    if (MPStatesGetConnectionMode() == 1) {
        SetMPFrequency(0);
    }
    for (slot = 0; slot < 8; slot++) {
        if (MPStatesGetConnectionMode() == 1) {
            flagCount = 0x12;
        } else {
            flagCount = 2;
        }
        for (flagIndex = 0; flagIndex < flagCount; flagIndex++) {
            gConnectionWork->mChunkReceivedFlags[slot][flagIndex] = 0;
        }
    }
    gConnectionWork->mRecordReceivedMask = 0;
}

void UpdateMPState7(void) {
    if (gConnectionWork->mRequestPending == 0) {
        switch (gConnectionWork->mStep) {
            case 0xc:
                gConnectionWork->mStep = 0xb;
                break;
            case 0xb:
                MPStatesRequestMPState(8);
                break;
            default:
                SetRequestErrorCode(2);
                break;
        }
    }
}

void EnterMPState8(void) {
    u16 ownIndex;

    ownIndex = gConnectionWork->mConnectionMode == 2 ? gConnectionWork->mOwnIndex : 0;
    FillPlayerRecord(&gConnectionWork->mPlayerRecords[ownIndex]);
    gConnectionWork->mMPStateMachine.mChunkSendFlags |= 1;
    gConnectionWork->mEntryChunkIndex = 0;
    gConnectionWork->mMPStateMachine.mEntryWaitFrames = 0;
}

#pragma thumb off

#pragma thumb on
void QueueMPChunkCallback(void) {
    gConnectionWork->mMPStateMachine.mChunkSendFlags |= 1;
}
#pragma thumb off

#pragma thumb on

BOOL QueueMPChunk(u8 chunkNumber, u8 *data, u16 size, u8 playerIndex, u8 destBitmap) {
    u8 *packet;

    if ((gConnectionWork->mMPStateMachine.mChunkSendFlags & 1) == 0) {
        return FALSE;
    }
    packet = gConnectionWork->mChunkBuffer;
    packet[1] = chunkNumber;
    *(u16 *) (packet + 2) = size;
    packet[0] = playerIndex;
    if (data != NULL) {
        MI_CpuCopy8(data, packet + 4, size);
    } else {
        size = 0;
    }
    DC_StoreRange(packet, size + 4);
    gConnectionWork->mMPStateMachine.mChunkSendFlags &= ~1;
    if (QueueMPDataToPort(gConnectionWork->mChunkBuffer, size + 4, destBitmap, NULL, &gQueueMPChunkParams) == 0) {
        gConnectionWork->mMPStateMachine.mChunkSendFlags |= 1;
        return FALSE;
    }
    return TRUE;
}

BOOL GetEntryChunk(u8 *entry, s32 chunkIndex, s32 chunkSize, u8 **outChunk, u16 *outSize) {
    s32 n;

    chunkIndex = chunkIndex * chunkSize;
    n = 0x22c - chunkIndex;
    if (n <= 0) {
        return FALSE;
    }
    if (n > chunkSize) {
        n = chunkSize;
    }
    *outSize = n;
    *outChunk = entry + chunkIndex;
    return TRUE;
}

// Child: queues its own entry chunk by chunk, again and again. Parent: waits for the children's entries.
void UpdateMPState8(void) {
    ConnectionWork *work;
    u32 expectedMask;
    u8 receivedMask;
    u8 chunkIndex;
    u8 *chunkData;
    u16 chunkSize;
    u16 v;

    if (MPStatesGetConnectionMode() == 1) {
        work = gConnectionWork;
        expectedMask = work->mChildren.mExpectedRecordMask;
        receivedMask = work->mRecordReceivedMask;
        if (expectedMask == (expectedMask & receivedMask)) {
            if (QueueMPChunk(0xfe, NULL, (u8) (receivedMask | 1), 0, receivedMask) != FALSE) {
                MPStatesRequestMPState(9);
            }
        } else {
            if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
                v = 0x708;
            } else {
                v = 0x258;
            }
            gConnectionWork->mMPStateMachine.mEntryWaitFrames++;
            if (gConnectionWork->mMPStateMachine.mEntryWaitFrames > v) {
                gConnectionWork->mChildren.mExpectedRecordMask = gConnectionWork->mChildren.mChildMask;
            }
        }
    } else {
        if ((gConnectionWork->mMPStateMachine.mChunkSendFlags & 1) != 0) {
            chunkIndex = gConnectionWork->mEntryChunkIndex;
            v = gConnectionWork->mConnectionMode == 2 ? gConnectionWork->mOwnIndex : 0;
            if (GetEntryChunk((u8 *) &gConnectionWork->mPlayerRecords[v], chunkIndex, 0x20, &chunkData, &chunkSize) !=
                FALSE) {
                v = gConnectionWork->mConnectionMode == 2 ? gConnectionWork->mOwnIndex : 0;
                QueueMPChunk(chunkIndex, chunkData, chunkSize, v, 1);
                gConnectionWork->mEntryChunkIndex = chunkIndex + 1;
            } else {
                gConnectionWork->mEntryChunkIndex = 0;
            }
        }
    }
}

void EnterMPState9(void) {
    gConnectionWork->mState = 10;
    gConnectionWork->mMPStateMachine.mEntryWaitFrames = 0;
    gConnectionWork->mRecordReceivedMask = 0;
    gConnectionWork->mEntryChunkIndex = 0;
    gConnectionWork->mEntryChunkSlot = 0;
}

// Parent: queues the entries of all slots to the children, chunk by chunk, until the wait ends.
void UpdateMPState9(void) {
    u32 slotDone;
    u8 chunkIndex;
    u8 slot;
    u8 *chunkData;
    u16 chunkSize;
    u16 waitLimit;

    if (MPStatesGetConnectionMode() == 1) {
        if ((gConnectionWork->mMPStateMachine.mChunkSendFlags & 1) != 0) {
            slotDone = 1;
            slot = gConnectionWork->mEntryChunkSlot;
            if (((u8) (gConnectionWork->mChildren.mChildMask | 1) & (1 << slot)) != 0) {
                chunkIndex = gConnectionWork->mEntryChunkIndex;
                if (GetEntryChunk((u8 *) &gConnectionWork->mPlayerRecords[slot], chunkIndex, 0x168, &chunkData,
                                  &chunkSize) != FALSE) {
                    QueueMPChunk(chunkIndex, chunkData, chunkSize, slot, gConnectionWork->mChildren.mChildMask);
                    gConnectionWork->mEntryChunkIndex = chunkIndex + 1;
                    slotDone = 0;
                }
            }
            if (slotDone != 0) {
                gConnectionWork->mEntryChunkSlot++;
                gConnectionWork->mEntryChunkIndex = 0;
                if (gConnectionWork->mEntryChunkSlot >= 8) {
                    gConnectionWork->mEntryChunkSlot = 0;
                }
            }
        }
        if ((gConnectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0) {
            waitLimit = 0x708;
        } else {
            waitLimit = 0x258;
        }
        gConnectionWork->mMPStateMachine.mEntryWaitFrames++;
        if (gConnectionWork->mMPStateMachine.mEntryWaitFrames > waitLimit) {
            gConnectionWork->mRecordReceivedMask = gConnectionWork->mChildren.mChildMask;
            MPStatesRequestMPState(10);
        }
    }
}

void EnterMPState10(void) {
    u8 slot;

    WM_SetPortCallback(14, NULL, NULL);
    gConnectionWork->mLanguageIndex = gConnectionWork->mPlayerRecords[0].mLanguageIndex;
    if (gBootInfo->mUnk_00 == 2) {
        gStartupWork->mLanguageIndex = gConnectionWork->mLanguageIndex;
    }
    for (slot = 1; slot < 8; slot++) {
        if ((gConnectionWork->mRecordReceivedMask & (1 << slot)) == 0) {
            MI_CpuFill8(&gConnectionWork->mPlayerRecords[slot], 0, 0x22c);
        }
    }
}

void UpdateMPState10(void) {
    if (gConnectionWork->mRequestPending == 0) {
        switch (gConnectionWork->mStep) {
            case 0xb:
                StartRomArchiveSend();
                break;
            case 0x25:
                MPStatesRequestMPState(6);
                break;
        }
    }
}

void EnterMPState11(void) {
    gConnectionWork->mPlayerSendIndex = 0;
    gConnectionWork->mNamesStoredMask = 0;
}

void UpdateMPState11(void) {
    u8 a;
    u8 b;
    u32 c;

    switch (MPStatesGetConnectionMode()) {
        case 1:
            a = gConnectionWork->mPlayerSendIndex;
            b = gConnectionWork->mRecordReceivedMask;
            c = b & (1 << a);
            if (c != 0) {
                if (QueueMPDataPlayerName(a, b) != FALSE) {
                    gConnectionWork->mPlayerSendIndex++;
                }
            } else {
                gConnectionWork->mPlayerSendIndex++;
            }
            if (gConnectionWork->mPlayerSendIndex >= 8) {
                MPStatesRequestMPState(6);
            }
            break;
        case 2:
            a = gConnectionWork->mRecordReceivedMask;
            b = gConnectionWork->mNamesStoredMask;
            if (a == (a & b)) {
                MPStatesRequestMPState(6);
            }
            break;
    }
}

#pragma thumb off

#pragma thumb on

void EnterMPState12(void) {
    int v1;
    if (gConnectionWork == NULL) {
        v1 = 0;
    } else {
        v1 = gConnectionWork->mConnectionMode;
    }
    if (v1 == 1) {
        SetMPFrequency(1);
    }
}

#pragma thumb off

#pragma thumb on

void UpdateMPState12(void) {
    if (gConnectionWork->mRequestPending != 0) {
        return;
    }
    switch (gConnectionWork->mStep) {
        case 0xc:
        case 0x25:
        case 0x27:
            StartDataSharing();
            break;
        case 0xe:
            gConnectionWork->mState = 7;
            MPStatesRequestMPState(5);
            break;
    }
}

void EnterMPState13(void) {
    s32 ownIndex;

    gConnectionWork->mBitsReceivedMask = 0;
    ownIndex = 0;
    if (gConnectionWork->mConnectionMode == 2) {
        ownIndex = gConnectionWork->mOwnIndex;
    }
    MI_CpuCopy8(gBackupBuffers->mFirstBlock->mFlags, gConnectionWork->mPlayerRecords[(u16) ownIndex].mBits, 4);
    gConnectionWork->mRecordReceivedMask |= 1;
}

void UpdateMPState13(void) {
    s32 ownIndex;

    if (MPStatesGetConnectionMode() == 1) {
        if (gConnectionWork->mChildren.mChildMask ==
            (gConnectionWork->mChildren.mChildMask & gConnectionWork->mBitsReceivedMask)) {
            MPStatesRequestMPState(0xe);
        }
    } else if (gConnectionWork->mBitsReceivedMask != 0) {
        MPStatesRequestMPState(0xe);
    } else {
        if (gConnectionWork->mConnectionMode == 2) {
            ownIndex = gConnectionWork->mOwnIndex;
        } else {
            ownIndex = 0;
        }
        QueueMPDataPlayerBits((u8) (u16) ownIndex, 1);
    }
}
#pragma thumb off

#pragma thumb on
void EnterMPState14(void) {
    gConnectionWork->mPlayerSendIndex = 0;
}
#pragma thumb off

#pragma thumb on

void UpdateMPState14(void) {
    if (MPStatesGetConnectionMode() == 1) {
        if ((gConnectionWork->mRecordReceivedMask & (1 << gConnectionWork->mPlayerSendIndex)) != 0) {
            if (QueueMPDataPlayerBits(gConnectionWork->mPlayerSendIndex, gConnectionWork->mChildren.mChildMask) !=
                FALSE) {
                gConnectionWork->mPlayerSendIndex += 1;
            }
        } else {
            gConnectionWork->mPlayerSendIndex += 1;
        }
        if (gConnectionWork->mPlayerSendIndex > 8) {
            MPStatesRequestMPState(0xb);
        }
    } else if (gConnectionWork->mRecordReceivedMask ==
               (gConnectionWork->mRecordReceivedMask & gConnectionWork->mBitsReceivedMask)) {
        MPStatesRequestMPState(0xb);
    }
}
#pragma thumb off

#pragma thumb on

u32 EnterMPState15ReturnArgument(u32 value) {
    return value;
}

#pragma thumb off
