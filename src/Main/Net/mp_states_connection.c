#include "Main/Net/mp_states_connection.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Save/ghost_record.h"
#include "Main/System/thread_function_queue.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/scan.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/MapObjects/data_0217a000.h"
#include "os_tick.h"
#include "Main/Save/ghost_record_file.h"

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
        case 0:
            if (gConnectionWork->mFlags & CONNECTION_FLAG_SEND_READY) {
                switch (MPStatesGetConnectionMode()) {
                    case CONNECTION_MODE_PARENT:
                        gConnectionWork->mSyncState = 6;
                        break;
                    case CONNECTION_MODE_CHILD:
                        gConnectionWork->mSyncState = 2;
                        break;
                }
            }
            break;
        case 7:
            QueueMPDataHalfword(5, 0xff);
            gConnectionWork->mTransferFlags |= CONNECTION_TRANSFER_SYNC_DONE;
            gConnectionWork->mSyncDoneChildMask = done;
            gConnectionWork->mSyncState = 1;
            break;
        case 6:
            if (gConnectionWork->mChildren.mChildMask ==
                (gConnectionWork->mChildren.mChildMask & gConnectionWork->mSyncDoneChildMask)) {
                gConnectionWork->mSyncState = 7;
            }
            break;
        case 2:
            if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
                QueueThreadFunction(callback);
                gThreadFunctionQueue->mRunRequested = 1;
            }
            gConnectionWork->mSyncState = 3;
            QueueMPDataHalfword(3, 1);
            break;
        case 3:
            if (gThreadFunctionQueue->mRunRequested == 0) {
                if (gConnectionWork->mCallbackFailed != 0) {
                    SetRequestErrorCode(CONNECTION_ERROR_COMMUNICATION_LOST);
                } else {
                    gConnectionWork->mSyncState = 5;
                }
            }
            break;
        case 5:
            if (QueueMPDataHalfword(4, 1) != FALSE) {
                gConnectionWork->mSyncState = 1;
            }
            break;
        case 1:
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
    if (gConnectionWork->mMPStateMachine.mStateMachine.mState == 0xf) {
        finished = TRUE;
    }
    return finished;
}

void EnterMPState0(void) {
    u16 ownIndex;

    ownIndex = gConnectionWork->mConnectionMode == CONNECTION_MODE_CHILD ? gConnectionWork->mOwnIndex : 0;
    FillPlayerRecord(&gConnectionWork->mPlayerRecords[ownIndex]);
}

void UpdateMPState0(void) {
    if (gConnectionWork->mRequestPending != 0) {
        return;
    }
    if (MPStatesGetConnectionMode() != CONNECTION_MODE_PARENT) {
        MPStatesRequestMPState(0x16);
        return;
    }
    switch (gConnectionWork->mStep) {
        case CONNECTION_STEP_STARTING_EXCHANGE:
        case CONNECTION_STEP_PUBLISHING_GAME_INFO:
            SetEntry(0);
            return;
        case CONNECTION_STEP_REGISTERING_ENTRY:
            MPStatesRequestMPState(7);
            break;
    }
}

void EnterMPState22(void) {
    u64 randomState;

    randomState = (u32) OS_GetTick() << 8;
    randomState = (u32) randomState & ~(u32) (randomState >> 32);
    if (gBootInfo->mBootType == BOOT_TYPE_MULTIBOOT) {
        randomState = randomState * 0x5d588b656c078965ull + 0x269ec3;
        gConnectionWork->mMPStateMachine.mDelayTimer = (u16) (((randomState >> 32) * 0xb4) >> 32) + 0x78;
    } else {
        gConnectionWork->mMPStateMachine.mDelayTimer = 0xb4;
    }
}

void UpdateMPState22(void) {
    gConnectionWork->mMPStateMachine.mDelayTimer = gConnectionWork->mMPStateMachine.mDelayTimer - 1;
    if (gConnectionWork->mMPStateMachine.mDelayTimer < 0) {
        MPStatesRequestMPState(7);
    }
}

void EnterMPState5(void) {
    if (MPStatesGetConnectionMode() == CONNECTION_MODE_PARENT) {
        gConnectionWork->mParticipantMask = gConnectionWork->mChildren.mChildMask | 1;
    }
    gConnectionWork->mMPStateMachine.mChildDataWaitFrames = 0;
}

#pragma thumb off
