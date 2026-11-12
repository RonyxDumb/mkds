#include "Main/Net/mp_chunk_state_machine.h"
#include "Main/Scene/run_scene_connection.h"
#include "Main/Net/mp_states.h"
#include "Main/Net/mp_states_connection.h"
#include "Main/Net/mp_state.h"
#include "Main/Net/mp.h"
#include "Main/Net/slot_result_sync.h"
#include "os_thread.h"
#include "Main/System/state_machine_init.h"
#include "Main/MapObjects/data_02165000.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Scene/display_settings.h"
#include "code_020182c0.h"
#include "frameheap.h"
#include "Main/MapObjects/map_object_park.h"
#include "pm.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Kart/kart_name_tags.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_0200eddc.h"
#include "code_0214d018.h"

StateCallbacks gMPStateTable[23] = {{EnterMPState0, UpdateMPState0}, {NULL, UpdateMPState1}, {EnterMPState2, UpdateMPState2}, {EnterMPState3, UpdateMPState3}, {EnterMPState4, UpdateMPState4}, {EnterMPState5, UpdateMPState5}, {NULL, UpdateMPState6}, {EnterMPState7, UpdateMPState7}, {EnterMPState8, UpdateMPState8}, {EnterMPState9, UpdateMPState9}, {EnterMPState10, UpdateMPState10}, {EnterMPState11, UpdateMPState11}, {EnterMPState12, UpdateMPState12}, {EnterMPState13, UpdateMPState13}, {EnterMPState14, UpdateMPState14}, {(UnkFunc *) EnterMPState15ReturnArgument, NULL}, {EnterMPState16, UpdateMPState16}, {EnterMPState17, UpdateMPState17}, {EnterMPState18, UpdateMPState18}, {EnterMPState19, UpdateMPState19}, {EnterMPState20, UpdateMPState20}, {EnterMPState21, UpdateMPState21}, {EnterMPState22, UpdateMPState22}};

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
    if (event->mResultCode == 0 && event->mData != NULL && event->mLength >= 4) {
        DC_StoreRange(event->mData, event->mLength);
        switch (event->mState) {
            case 7:
            case 9:
                break;
            case 0x15:
                ProcessMPChunk(event->mData);
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
