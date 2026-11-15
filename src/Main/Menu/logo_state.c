#include "Main/Menu/logo_state.h"
#include "Main/Net/multiboot_parent_finish.h"
#include "Main/Menu/logo_check_dwc_init_enter_nop.h"
#include "Main/Menu/logo_backup_read_and_reset.h"
#include "Main/Menu/logo_wait_backup_read_enter_nop.h"
#include "Main/Menu/logo_scene.h"
#include "Main/Graphics/locate_bmg_sections.h"
#include "Main/Menu/txt_system.h"

// Initialized data kept in .text between two functions.
#pragma define_section MAIN_TEXT ".text"                                                                               \
                                 ".bss" abs32 RWX
#pragma section MAIN_TEXT begin

StateCallbacks gLogoStateTable[12] = {
    {EnterLogoReadBackup, UpdateLogoReadBackup},
    {EnterLogoWaitBackupReadNop, UpdateLogoWaitBackupRead},
    {EnterLogoResetNotice, UpdateLogoResetNotice},
    {EnterLogoResetFailedBlocks, UpdateLogoResetFailedBlocks},
    {EnterLogoResetFailedBlocksDone, UpdateLogoResetFailedBlocksDone},
    {EnterLogoAskResetBackup, UpdateLogoAskResetBackup},
    {EnterLogoResetBackup, UpdateLogoResetBackup},
    {EnterLogoResetBackupDone, UpdateLogoResetBackupDone},
    {EnterLogoCheckDwcInitNop, UpdateLogoCheckDwcInit},
    {EnterLogoDwcNoticeFirst, UpdateLogoDwcNoticeFirst},
    {EnterLogoDwcNoticeSecond, UpdateLogoDwcNoticeSecond},
    {NULL, NULL},
};

#pragma section MAIN_TEXT end

void UpdateLogoCheckDwcInit(void *stateObject) {
    StateMachine *stateMachine;
    if (gDwcInitResult == 3) {
        stateMachine = &gLogoScene->mStateMachine;
        stateMachine->mNextState = LOGO_STATE_DWC_NOTICE_FIRST;
        stateMachine->mNextStateRequested = 1;
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = LOGO_STATE_END;
    stateMachine->mNextStateRequested = 1;
}

void EnterLogoDwcNoticeFirst(void *stateObject) {
    void *message;
    message = GetBmgEntry(gLogoScene->mCommonMessages, 137);
    SetupTxtSystemSubTextButton(message, GetBmgEntry(gLogoScene->mCommonMessages, 6));
}

void UpdateLogoDwcNoticeFirst(void *stateObject) {
    StateMachine *stateMachine;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() == 0) {
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = LOGO_STATE_DWC_NOTICE_SECOND;
    stateMachine->mNextStateRequested = 1;
}

void EnterLogoDwcNoticeSecond(void *stateObject) {
    void *message;
    message = GetBmgEntry(gLogoScene->mCommonMessages, 138);
    SetupTxtSystemSubTextButton(message, GetBmgEntry(gLogoScene->mCommonMessages, 4));
}

void UpdateLogoDwcNoticeSecond(void *stateObject) {
    StateMachine *stateMachine;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() == 0) {
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = LOGO_STATE_END;
    stateMachine->mNextStateRequested = 1;
}
