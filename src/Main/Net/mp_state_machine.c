#include "Main/Net/mp_state_machine.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/mp.h"
#include "Main/Menu/select_race_rule_state.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Net/mp_chunk_state_machine.h"

#pragma opt_rebuildconditionals off

static inline u32 MPStateMachineGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline s32 MPStateMachineIsConnectionActive(void) {
    BOOL result = FALSE;
    if (MPStateMachineGetConnectionMode() != CONNECTION_MODE_NONE &&
        gConnectionWork->mState != CONNECTION_STATE_ENDED) {
        result = TRUE;
    }
    return result;
}

static inline s32 MPStateMachineIsConnectionActiveNotEnding(void) {
    BOOL result = FALSE;
    if (MPStateMachineIsConnectionActive() && !(gConnectionWork->mFlags & CONNECTION_FLAG_ENDING)) {
        result = TRUE;
    }
    return result;
}

static inline s32 MPStateMachineIsConnectionActiveNotEndingWithError(void) {
    BOOL result = FALSE;
    if (MPStateMachineIsConnectionActiveNotEnding() && gConnectionWork->mErrorCode != CONNECTION_ERROR_NONE) {
        result = TRUE;
    }
    return result;
}

#pragma thumb on

BOOL AdvanceMPStateMachine(void) {
    BOOL finished;

    finished = FALSE;
    if (!MPStateMachineIsConnectionActive()) {
        return TRUE;
    }
    AdvanceStateMachine(&gConnectionWork->mMPStateMachine.mStateMachine);
    if (!MPStateMachineIsConnectionActiveNotEndingWithError()) {
        if (MPStateMachineGetConnectionMode() == CONNECTION_MODE_PARENT &&
            gConnectionWork->mChildren.mChildCount == 0) {
            SetRequestErrorCode(CONNECTION_ERROR_COMMUNICATION_LOST);
        }
    }
    if (gConnectionWork->mMPStateMachine.mStateMachine.mState == MP_STATE_READY) {
        finished = TRUE;
    }
    return finished;
}

s32 WLMenuToRaceAdvanceMPStateMachineWrapper(void) {
    return AdvanceMPStateMachine();
}

s32 WLMenuToMenuAdvanceMPStateMachineWrapper(void) {
    return AdvanceMPStateMachine();
}

u32 AdvanceMenuDLArchives(void) {
    if (MPStateMachineIsConnectionActiveNotEndingWithError()) {
        return 3;
    }
    if (!MPStateMachineIsConnectionActive()) {
        return 1;
    }
    switch (MPStateMachineGetConnectionMode()) {
        case CONNECTION_MODE_PARENT:
            return AdvanceParentSync();
        case CONNECTION_MODE_CHILD:
            return AdvanceChildArchiveSync(3, NULL, NULL);
        default:
            return 3;
    }
}

u32 AdvanceResultDLArchives(void) {
    if (MPStateMachineIsConnectionActiveNotEndingWithError()) {
        return 3;
    }
    if (!MPStateMachineIsConnectionActive()) {
        return 1;
    }
    switch (MPStateMachineGetConnectionMode()) {
        case CONNECTION_MODE_PARENT:
            return AdvanceParentSync();
        case CONNECTION_MODE_CHILD:
            return AdvanceChildArchiveSync(2, NULL, NULL);
        default:
            return 3;
    }
}

#pragma thumb off
