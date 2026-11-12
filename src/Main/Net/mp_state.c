#include "Main/Net/mp_state.h"
#include "Main/Net/scan.h"
#include "Main/Net/mp_states_connection.h"
#include "Main/Unknown/code_0210e000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02058000.h"
#include "Main/Unknown/code_02051000.h"
#include "Main/Unknown/code_02059000.h"

#include "Main/Net/mp_state_machine.h"
#include "Main/Sound/sound_set_load.h"

#pragma thumb on

void EnterMPState21(void) {
    int connectionMode;
    if (gConnectionWork == NULL) {
        connectionMode = 0;
    } else {
        connectionMode = gConnectionWork->mConnectionMode;
    }
    if (connectionMode == 1) {
        SetMPFrequency(0);
    }
}

void UpdateMPState21(void) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceMenuDLArchives();
    if (result == 1) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = 0x14;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

void EnterMPState18(void) {
    int connectionMode;
    if (gConnectionWork == NULL) {
        connectionMode = 0;
    } else {
        connectionMode = gConnectionWork->mConnectionMode;
    }
    if (connectionMode == 1) {
        SetMPFrequency(0);
    }
}

void UpdateMPState18(void) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceResultDLArchives();
    if (result == 1) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = 0x13;
        stateMachine->mStateMachine.mNextStateRequested = 1;
    }
}

#pragma thumb off

#pragma thumb on

void EnterMPState19(void) {
    gConnectionWork->mSyncState = 0;
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

void UpdateMPState19(void) {
    int result;
    MPStateMachine *stateMachine;
    result = AdvanceSyncedCallback(LoadResultSceneSoundSetCallback);
    if (result == 1) {
        stateMachine = &gConnectionWork->mMPStateMachine;
        stateMachine->mStateMachine.mNextState = 0xf;
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
