#include "Main/Net/mp_state.h"
#include "Main/Net/scan.h"
#include "Main/Net/mp_states_connection.h"
#include "code_0212d214.h"
#include "Main/MapObjects/data_0217a000.h"

#include "Main/Net/mp_state_machine.h"
#include "Main/Sound/sound_set_load.h"
#include "Main/Net/mp_chunk_state_machine.h"

#pragma thumb on

void EnterMPState21(void *stateObject) {
    int connectionMode;
    if (gConnectionWork == NULL) {
        connectionMode = CONNECTION_MODE_NONE;
    } else {
        connectionMode = gConnectionWork->mConnectionMode;
    }
    if (connectionMode == CONNECTION_MODE_PARENT) {
        SetMPFrequency(0);
    }
}

void UpdateMPState21(void *stateObject) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceMenuDLArchives();
    if (result == 1) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = MP_STATE_WAIT_REQUEST_DONE;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

void EnterMPState18(void *stateObject) {
    int connectionMode;
    if (gConnectionWork == NULL) {
        connectionMode = CONNECTION_MODE_NONE;
    } else {
        connectionMode = gConnectionWork->mConnectionMode;
    }
    if (connectionMode == CONNECTION_MODE_PARENT) {
        SetMPFrequency(0);
    }
}

void UpdateMPState18(void *stateObject) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceResultDLArchives();
    if (result == 1) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = MP_STATE_LOAD_RESULT_SOUND;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

void EnterMPState19(void *stateObject) {
    gConnectionWork->mSyncState = CONNECTION_SYNC_START;
    gConnectionWork->mTransferFlags &= ~CONNECTION_TRANSFER_SYNC_DONE;
    gConnectionWork->mCallbackFailed = 0;
}

void LoadResultSceneSoundSetCallback(void) {
    if (LoadResultSceneSoundSet() == 0) {
        gConnectionWork->mCallbackFailed = 1;
    }
}

#pragma thumb off

#pragma thumb on

void UpdateMPState19(void *stateObject) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceSyncedCallback(LoadResultSceneSoundSetCallback);
    if (result == 1) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = MP_STATE_READY;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

s32 WLMenuToResultAdvanceMPStateMachineWrapper(void) {
    return AdvanceMPStateMachine();
}

#pragma thumb off

#pragma thumb on

void LoadSndDataFromFileCallback(void) {
    int result;
    result = LoadSndDataFromFile();
    if (result == 0) {
        gConnectionWork->mCallbackFailed = 1;
    }
}

#pragma thumb off
