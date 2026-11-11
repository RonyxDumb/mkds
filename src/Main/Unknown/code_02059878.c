#include "Main/Unknown/code_02059878.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_02057fe4.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02059920.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"

#pragma opt_rebuildconditionals off

s32 RunResultScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks resultSceneCallbacks = gResultSceneCallbacks;

    RunScene(sceneNumbers, &resultSceneCallbacks);
    return 0;
}

#pragma thumb on

static inline u32 MPChunkGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline void MPChunkRequestMPState(u16 nextState) {
    MPStateMachine *stateMachine = &gConnectionWork->mMPStateMachine;
    stateMachine->mStateMachine.mNextState = nextState;
    stateMachine->mStateMachine.mNextStateRequested = 1;
}

u32 IsAllMPChunksReceived(u32 slot) {
    u32 chunkCount;
    u8 *receivedFlags;
    u32 allReceived;
    u32 chunkIndex;

    receivedFlags = gConnectionWork->mChunkReceivedFlags[slot];
    allReceived = 1;
    if (MPChunkGetConnectionMode() == 1) {
        chunkCount = 0x12;
    } else {
        chunkCount = 2;
    }
    for (chunkIndex = 0; chunkIndex < chunkCount; chunkIndex++) {
        if (receivedFlags[chunkIndex] == 0) {
            allReceived = 0;
            break;
        }
    }
    return allReceived;
}

void ProcessMPChunk(u8 *chunk) {
    u32 playerIndex;
    PlayerRecord *entry;
    u32 finished;
    u32 byteOffset;
    u16 ownIndex;
    u8 playerBit;

    playerIndex = chunk[0];
    entry = &gConnectionWork->mPlayerRecords[playerIndex];
    finished = 0;
    if (MPChunkGetConnectionMode() == 1) {
        byteOffset = chunk[1] << 5;
    } else {
        byteOffset = chunk[1] * 0x168;
    }
    switch (chunk[1]) {
        case 0xff:
            if (MPChunkGetConnectionMode() == 2) {
                MPChunkRequestMPState(9);
            }
            break;
        case 0xfe:
            if (MPChunkGetConnectionMode() == 2) {
                gConnectionWork->mExpectedRecordMask = *(u16 *) (chunk + 2);
            }
            break;
        case 0xfd:
            if (MPChunkGetConnectionMode() == 1) {
                gConnectionWork->mRecordReceivedMask |= 1 << playerIndex;
                if (gConnectionWork->mChildren.mChildMask ==
                    (gConnectionWork->mChildren.mChildMask & gConnectionWork->mRecordReceivedMask)) {
                    MPChunkRequestMPState(10);
                }
            }
            break;
        case 0xfc:
            gConnectionWork->mPlayerRecords[playerIndex].mHasEmblem = 0;
            finished = 1;
            break;
        default:
            MI_CpuCopy8(chunk + 4, entry->mName + byteOffset, *(u16 *) (chunk + 2));
            gConnectionWork->mChunkReceivedFlags[chunk[0]][chunk[1]] = 1;
            if (IsAllMPChunksReceived(chunk[0]) != 0) {
                finished = 1;
            }
            break;
    }
    if (finished != 0) {
        playerBit = 1U << chunk[0];
        if (MPChunkGetConnectionMode() == 1) {
            if (QueueMPChunk(0xff, NULL, 0, 0, playerBit) != FALSE) {
                gConnectionWork->mRecordReceivedMask |= 1 << chunk[0];
                return;
            }
        } else {
            gConnectionWork->mRecordReceivedMask |= 1 << chunk[0];
            if (gConnectionWork->mExpectedRecordMask ==
                (gConnectionWork->mExpectedRecordMask & gConnectionWork->mRecordReceivedMask)) {
                ownIndex = gConnectionWork->mConnectionMode == 2 ? gConnectionWork->mOwnIndex : 0;
                if (QueueMPChunk(0xfd, NULL, 0, ownIndex, 1) != FALSE) {
                    MPChunkRequestMPState(10);
                }
            }
        }
    }
}

void MPChunkPortCallback(Unk021425e8 *event) {
    if (event->mResultCode == 0 && event->mUnk_0c != NULL && event->mUnk_10 >= 4) {
        DC_StoreRange(event->mUnk_0c, event->mUnk_10);
        switch (event->mUnk_04) {
            case 7:
            case 9:
                break;
            case 0x15:
                ProcessMPChunk(event->mUnk_0c);
                break;
        }
    }
}

void InitMPStateMachine(void) {
    ConnectionWork *connectionWork;
    u32 connectionMode;

    InitStateMachine(&gConnectionWork->mMPStateMachine.mStateMachine, gMPStateTable, 0x17, NULL);
    gConnectionWork->mPlayerSendIndex = 0;
    gConnectionWork->mMPStateMachine.mChildDataWaitFrames = 0;
    gConnectionWork->mMPStateMachine.mChunkSendFlags = 0;
    gConnectionWork->mEntryChunkIndex = 0;
    gConnectionWork->mRecordReceivedMask = 0;
    gConnectionWork->mNamesStoredMask = 0;
    connectionWork = gConnectionWork;
    connectionMode = 0;
    if (connectionWork != NULL) {
        connectionMode = connectionWork->mConnectionMode;
    }
    if (connectionMode == 1) {
        connectionWork->mChildren.mExpectedRecordMask = (connectionWork->mFlags & CONNECTION_FLAG_MULTIBOOT_SETUP) != 0
                                                            ? connectionWork->mMultiBootChildMask
                                                            : connectionWork->mChildren.mChildMask;
    }
    gConnectionWork->mRaceSeed = 0;
}

#pragma thumb off
