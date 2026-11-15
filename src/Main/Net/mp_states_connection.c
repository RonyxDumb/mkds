#include "Main/Net/mp_states_connection.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Save/ghost_record.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/scan.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/System/backup_net_camera_work.h"
#include "os_tick.h"
#include "Main/Save/ghost_record_file.h"
#include "Main/Net/mp_chunk_state_machine.h"
#include "Main/MapObjects/map_object_park.h"

#pragma opt_rebuildconditionals off

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

static inline s32 MPStatesIsConnectionActive(void) {
    BOOL result = FALSE;
    if (MPStatesGetConnectionMode() != CONNECTION_MODE_NONE && gConnectionWork->mState != CONNECTION_STATE_ENDED) {
        result = TRUE;
    }
    return result;
}

static inline s32 MPStatesIsConnectionActiveNotEnding(void) {
    BOOL result = FALSE;
    if (MPStatesIsConnectionActive() && !(gConnectionWork->mFlags & CONNECTION_FLAG_ENDING)) {
        result = TRUE;
    }
    return result;
}

static inline s32 MPStatesIsConnectionActiveNotEndingWithError(void) {
    BOOL result = FALSE;
    if (MPStatesIsConnectionActiveNotEnding() && gConnectionWork->mErrorCode != CONNECTION_ERROR_NONE) {
        result = TRUE;
    }
    return result;
}

#pragma thumb on

s32 AdvanceSyncedCallback(void (*callback)(void)) {
    BOOL done;

    done = FALSE;
    switch (gConnectionWork->mSyncState) {
        case CONNECTION_SYNC_START:
            if (gConnectionWork->mFlags & CONNECTION_FLAG_SEND_READY) {
                switch (MPStatesGetConnectionMode()) {
                    case CONNECTION_MODE_PARENT:
                        gConnectionWork->mSyncState = CONNECTION_SYNC_PARENT_WAIT_CHILDREN;
                        break;
                    case CONNECTION_MODE_CHILD:
                        gConnectionWork->mSyncState = CONNECTION_SYNC_CHILD_LOAD;
                        break;
                }
            }
            break;
        case CONNECTION_SYNC_PARENT_ANNOUNCE:
            QueueMPDataHalfword(MP_MESSAGE_TRANSFER_SYNC_DONE, 0xff);
            gConnectionWork->mTransferFlags |= CONNECTION_TRANSFER_SYNC_DONE;
            gConnectionWork->mSyncDoneChildMask = done;
            gConnectionWork->mSyncState = CONNECTION_SYNC_DONE;
            break;
        case CONNECTION_SYNC_PARENT_WAIT_CHILDREN:
            if (gConnectionWork->mChildren.mChildMask ==
                (gConnectionWork->mChildren.mChildMask & gConnectionWork->mSyncDoneChildMask)) {
                gConnectionWork->mSyncState = CONNECTION_SYNC_PARENT_ANNOUNCE;
            }
            break;
        case CONNECTION_SYNC_CHILD_LOAD:
            if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                QueueThreadFunction(callback);
                gThreadFunctionQueue->mRunRequested = 1;
            }
            gConnectionWork->mSyncState = CONNECTION_SYNC_CHILD_LOAD_WAIT;
            QueueMPDataHalfword(MP_MESSAGE_SYNC_NOT_DONE, 1);
            break;
        case CONNECTION_SYNC_CHILD_LOAD_WAIT:
            if (gThreadFunctionQueue->mRunRequested == 0) {
                if (gConnectionWork->mCallbackFailed != 0) {
                    SetRequestErrorCode(CONNECTION_ERROR_COMMUNICATION_LOST);
                } else {
                    gConnectionWork->mSyncState = CONNECTION_SYNC_CHILD_REPORT;
                }
            }
            break;
        case CONNECTION_SYNC_CHILD_REPORT:
            if (QueueMPDataHalfword(MP_MESSAGE_SYNC_DONE, 1) != FALSE) {
                gConnectionWork->mSyncState = CONNECTION_SYNC_DONE;
            }
            break;
        case CONNECTION_SYNC_DONE:
            if (gConnectionWork->mTransferFlags & CONNECTION_TRANSFER_SYNC_DONE) {
                done = TRUE;
            }
            break;
    }
    return done;
}

s32 AdvanceMPStateMachineWithOwnIndex(void) {
    BOOL finished;
    u16 ownIndex;

    finished = FALSE;
    if (!MPStatesIsConnectionActive()) {
        return 1;
    }
    ownIndex = ((const ConnectionWork *) gConnectionWork)->mConnectionMode == CONNECTION_MODE_CHILD
                   ? gConnectionWork->mOwnIndex
                   : 0;
    if (ownIndex == 0xffff && MPStatesGetConnectionMode() == CONNECTION_MODE_CHILD) {
        if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
            SetRequestErrorCode(CONNECTION_ERROR_DISCONNECTED);
            return 3;
        }
        return 2;
    }
    AdvanceStateMachine(&gConnectionWork->mMPStateMachine.mStateMachine);
    if (!MPStatesIsConnectionActiveNotEndingWithError()) {
        if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT && gConnectionWork->mChildren.mChildCount == 0) {
            SetRequestErrorCode(CONNECTION_ERROR_COMMUNICATION_LOST);
        }
    }
    if (gConnectionWork->mMPStateMachine.mStateMachine.mState == MP_STATE_READY) {
        finished = TRUE;
    }
    return finished;
}

void EnterMPFillOwnRecord(void *stateObject) {
    u16 ownIndex;

    ownIndex = gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD ? gConnectionWork->mOwnIndex : 0;
    FillPlayerRecord(&gConnectionWork->mPlayerRecords[ownIndex]);
}

void UpdateMPFillOwnRecord(void *stateObject) {
    if (gConnectionWork->mRequestPending != 0) {
        return;
    }
    if (MPStatesGetConnectionMode() != CONNECTION_MODE_PARENT) {
        MPStatesRequestMPState(MP_STATE_CHILD_DELAY);
        return;
    }
    switch (gConnectionWork->mStep) {
        case CONNECTION_STEP_STARTING_EXCHANGE:
        case CONNECTION_STEP_PUBLISHING_GAME_INFO:
            SetEntry(0);
            return;
        case CONNECTION_STEP_REGISTERING_ENTRY:
            MPStatesRequestMPState(MP_STATE_START_EXCHANGE);
            break;
    }
}

void EnterMPChildDelay(void *stateObject) {
    u64 randomState;

    randomState = (u32) OS_GetTick() << 8;
    randomState = (u32) randomState & ~(u32) (randomState >> 32);
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        randomState = randomState * RANDOM_STATE64_MULTIPLIER + RANDOM_STATE64_INCREMENT;
        gConnectionWork->mMPStateMachine.mDelayTimer =
            (u16) (((randomState >> 32) * MP_CHILD_DELAY_RANDOM_SPREAD_FRAMES) >> 32) +
            MP_CHILD_DELAY_RANDOM_MIN_FRAMES;
    } else {
        gConnectionWork->mMPStateMachine.mDelayTimer = MP_CHILD_DELAY_FRAMES;
    }
}

void UpdateMPChildDelay(void *stateObject) {
    gConnectionWork->mMPStateMachine.mDelayTimer = gConnectionWork->mMPStateMachine.mDelayTimer - 1;
    if (gConnectionWork->mMPStateMachine.mDelayTimer < 0) {
        MPStatesRequestMPState(MP_STATE_START_EXCHANGE);
    }
}

void EnterMPSendParticipantMask(void *stateObject) {
    if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT) {
        gConnectionWork->mParticipantMask = gConnectionWork->mChildren.mChildMask | 1;
    }
    gConnectionWork->mMPStateMachine.mChildDataWaitFrames = 0;
}

#pragma thumb off
