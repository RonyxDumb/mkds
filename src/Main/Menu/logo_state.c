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

StateCallbacks g_E7FnList0[12] = {
    {Logo_StateHandler_ReadSaveData_First, Logo_StateHandler_ReadSaveData_Second},
    {Logo_StateHandler_WaitCheckSaveData_First, Logo_StateHandler_WaitCheckSaveData_Second},
    {Logo_StateHandler_NotifySaveDataCorrupted_First, Logo_StateHandler_NotifySaveDataCorrupted_Second},
    {Logo_StateHandler_EraseCorruptedSaveData_First, Logo_StateHandler_EraseCorruptedSaveData_Second},
    {Logo_StateHandler_NotifyCorruptedSaveDataErased_First, Logo_StateHandler_NotifyCorruptedSaveDataErased_Second},
    {Logo_StateHandler_AskEraseSaveData_First, Logo_StateHandler_AskEraseSaveData_Second},
    {Logo_StateHandler_EraseSaveData_First, Logo_StateHandler_EraseSaveData_Second},
    {Logo_StateHandler_NotifySaveDataErased_First, Logo_StateHandler_NotifySaveDataErased_Second},
    {Logo_StateHandler_CheckWiFiStatus_First, Logo_StateHandler_CheckWiFiStatus_Second},
    {Logo_StateHandler_NotifyWiFiIdIssue_First, Logo_StateHandler_NotifyWiFiIdIssue_Second},
    {Logo_StateHandler_NotifyWiFiHelp_First, Logo_StateHandler_NotifyWiFiHelp_Second},
    {NULL, NULL},
};

#pragma section MAIN_TEXT end

void Logo_StateHandler_CheckWiFiStatus_Second(void *stateObject) {
    StateMachine *stateMachine;
    if (g_DwcStatus == 3) {
        stateMachine = &g_LogoContext->mStateMachine;
        stateMachine->mNextState = LOGO_STATE_DWC_NOTICE_FIRST;
        stateMachine->mNextStateRequested = 1;
        return;
    }
    stateMachine = &g_LogoContext->mStateMachine;
    stateMachine->mNextState = LOGO_STATE_END;
    stateMachine->mNextStateRequested = 1;
}

void Logo_StateHandler_NotifyWiFiIdIssue_First(void *stateObject) {
    void *message;
    message = Bmg_GetRawStringPointer_from_thumb(g_LogoContext->mCommonMessages, 137);
    TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(message, Bmg_GetRawStringPointer_from_thumb(g_LogoContext->mCommonMessages, 6));
}

void Logo_StateHandler_NotifyWiFiIdIssue_Second(void *stateObject) {
    StateMachine *stateMachine;
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_CloseDialog_from_thumb();
        return;
    }
    if (TextSystem_IsDialogFinished_from_thumb() == 0) {
        return;
    }
    stateMachine = &g_LogoContext->mStateMachine;
    stateMachine->mNextState = LOGO_STATE_DWC_NOTICE_SECOND;
    stateMachine->mNextStateRequested = 1;
}

void Logo_StateHandler_NotifyWiFiHelp_First(void *stateObject) {
    void *message;
    message = Bmg_GetRawStringPointer_from_thumb(g_LogoContext->mCommonMessages, 138);
    TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(message, Bmg_GetRawStringPointer_from_thumb(g_LogoContext->mCommonMessages, 4));
}

void Logo_StateHandler_NotifyWiFiHelp_Second(void *stateObject) {
    StateMachine *stateMachine;
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_CloseDialog_from_thumb();
        return;
    }
    if (TextSystem_IsDialogFinished_from_thumb() == 0) {
        return;
    }
    stateMachine = &g_LogoContext->mStateMachine;
    stateMachine->mNextState = LOGO_STATE_END;
    stateMachine->mNextStateRequested = 1;
}
