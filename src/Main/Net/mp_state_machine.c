#include "Main/Net/mp_state_machine.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Net/disconnect.h"
#include "Main/Net/mp.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma opt_rebuildconditionals off

static inline u32 MPStateMachineGetConnectionMode(void) {
    if (gConnectionWork == NULL) {
        return 0;
    }
    return gConnectionWork->mConnectionMode;
}

static inline s32 MPStateMachineIsConnectionActive(void) {
    BOOL result = FALSE;
    if (MPStateMachineGetConnectionMode() != 0 && gConnectionWork->mState != 13) {
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
    if (MPStateMachineIsConnectionActiveNotEnding() && gConnectionWork->mErrorCode != 9) {
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
        if (MPStateMachineGetConnectionMode() == 1 && gConnectionWork->mChildren.mChildCount == 0) {
            SetRequestErrorCode(7);
        }
    }
    if (gConnectionWork->mMPStateMachine.mStateMachine.mState == 0xf) {
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
        case 1:
            return AdvanceParentSync();
        case 2:
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
        case 1:
            return AdvanceParentSync();
        case 2:
            return AdvanceChildArchiveSync(2, NULL, NULL);
        default:
            return 3;
    }
}

#pragma thumb off
