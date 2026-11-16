#include "Main/Unknown/code_02001080.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02001290.h"
#include "Main/Unknown/code_02001294.h"
#include "Main/Unknown/code_020019ac.h"
#include "Main/Unknown/code_020019b0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126230.h"

// Initialized data kept in .text between two functions (as in the original).
#pragma define_section MAIN_TEXT ".text"                                                                               \
                                 ".bss" abs32 RWX
#pragma section MAIN_TEXT begin

UnkFunc *logo_sStates[24] = {
    logo_fadeInStateInit,
    logo_fadeInStateUpdate,
    logo_waitSaveBusyStateInit,
    logo_waitSaveBusyStateUpdate,
    logo_corruptedMsgStateInit,
    logo_corruptedMsgStateUpdate,
    logo_corruptedErasingMsgStateInit,
    logo_corruptedErasingMsgStateUpdate,
    logo_corruptedDeletedMsgStateInit,
    logo_corruptedDeletedMsgStateUpdate,
    logo_eraseAllConfirmStateInit,
    logo_eraseAllConfirmStateUpdate,
    logo_eraseAllErasingMsgStateInit,
    logo_eraseAllErasingMsgStateUpdate,
    logo_eraseAllDoneMsgStateInit,
    logo_eraseAllDoneMsgStateUpdate,
    logo_dwcInitResultCheckStateInit,
    logo_dwcInitResultCheckStateUpdate,
    logo_wifiIdErasedMsgStateInit,
    logo_wifiIdErasedMsgStateUpdate,
    logo_checkApSettingsMsgStateInit,
    logo_checkApSettingsMsgStateUpdate,
    NULL,
    NULL,
};

#pragma section MAIN_TEXT end

void logo_dwcInitResultCheckStateUpdate(void) {
    StateMachine *stateMachine;
    if (gDWCInitResult == 3) {
        stateMachine = &logo_sLogoState->mStateMachine;
        stateMachine->mNextState = 9;
        stateMachine->mNextStateRequested = 1;
        return;
    }
    stateMachine = &logo_sLogoState->mStateMachine;
    stateMachine->mNextState = 11;
    stateMachine->mNextStateRequested = 1;
}

void logo_wifiIdErasedMsgStateInit(void) {
    void *message;
    message = jn_msg_getMessage(logo_sLogoState->mCommonMessages, 137);
    SetupTxtSystemSubTextButton(message, jn_msg_getMessage(logo_sLogoState->mCommonMessages, 6));
}

void logo_wifiIdErasedMsgStateUpdate(void) {
    StateMachine *stateMachine;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    stateMachine = &logo_sLogoState->mStateMachine;
    stateMachine->mNextState = 10;
    stateMachine->mNextStateRequested = 1;
}

void logo_checkApSettingsMsgStateInit(void) {
    void *message;
    message = jn_msg_getMessage(logo_sLogoState->mCommonMessages, 138);
    SetupTxtSystemSubTextButton(message, jn_msg_getMessage(logo_sLogoState->mCommonMessages, 4));
}

void logo_checkApSettingsMsgStateUpdate(void) {
    StateMachine *stateMachine;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemState0NoOpenRequest() == 0) {
        return;
    }
    stateMachine = &logo_sLogoState->mStateMachine;
    stateMachine->mNextState = 11;
    stateMachine->mNextStateRequested = 1;
}
