#include "Main/Menu/logo_backup_read_and_reset.h"
#include "Main/Net/multiboot_parent_finish.h"
#include "Main/Save/backup_reset.h"
#include "Main/Sound/sound_seq.h"
#include "Main/Menu/txt_system.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Save/ghost_record_file.h"

void Logo_StateHandler_WaitCheckSaveData_Second(void *stateObject) {
    s32 commandBusy;
    StateMachine *stateMachine;
    s32 readStatus;
    LogoScene *scene;
    if (g_SaveDataHolder->mBusy == 0) {
        if (g_SaveDataIoManager->mBackupEnabled != 0) {
            commandBusy = g_SaveDataIoManager->mCommandRunning;
        } else {
            commandBusy = 0;
        }
    } else {
        commandBusy = 1;
    }
    if (commandBusy != 0) {
        return;
    }
    readStatus = g_SaveDataHolder->mReadStatus;
    if (readStatus != 0) {
        if (readStatus == BACKUP_READ_STATUS_BLOCKS_FAILED) {
            g_LogoContext->mUnk_2c_1 = 1;
            stateMachine = &g_LogoContext->mStateMachine;
            stateMachine->mNextState = LOGO_STATE_RESET_NOTICE;
            stateMachine->mNextStateRequested = 1;
        } else if (g_SaveDataIoManager->mErrorCode == BACKUP_ERROR_BAD_PREFIX) {
            g_LogoContext->mUnk_2c_1 = 0;
            stateMachine = &g_LogoContext->mStateMachine;
            stateMachine->mNextState = LOGO_STATE_RESET_BACKUP;
            stateMachine->mNextStateRequested = 1;
        } else {
            stateMachine = &g_LogoContext->mStateMachine;
            stateMachine->mNextState = LOGO_STATE_CHECK_DWC_INIT;
            stateMachine->mNextStateRequested = 1;
        }
    } else {
        scene = g_LogoContext;
        if (scene->mResetBackupRequested != 0) {
            stateMachine = &scene->mStateMachine;
            stateMachine->mNextState = LOGO_STATE_ASK_RESET_BACKUP;
            stateMachine->mNextStateRequested = 1;
        } else {
            stateMachine = &scene->mStateMachine;
            stateMachine->mNextState = LOGO_STATE_CHECK_DWC_INIT;
            stateMachine->mNextStateRequested = 1;
        }
    }
}

void Logo_StateHandler_NotifySaveDataCorrupted_First(void *stateObject) {
    void *message;
    message = Bmg_GetRawStringPointer_from_thumb(g_LogoContext->mCommonMessages, 125);
    TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(message, Bmg_GetRawStringPointer_from_thumb(g_LogoContext->mCommonMessages, 4));
}

void Logo_StateHandler_NotifySaveDataCorrupted_Second(void *stateObject) {
    StateMachine *stateMachine;
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_CloseDialog_from_thumb();
        return;
    }
    if (TextSystem_IsDialogFinished_from_thumb() == 0) {
        return;
    }
    stateMachine = &g_LogoContext->mStateMachine;
    stateMachine->mNextState = LOGO_STATE_RESET_FAILED_BLOCKS;
    stateMachine->mNextStateRequested = 1;
}

void Logo_StateHandler_EraseCorruptedSaveData_First(void *stateObject) {
    void *message;
    EraseNonGhostSaveDataSections_from_thumb();
    message = Bmg_GetRawStringPointer_from_thumb(g_LogoContext->mCommonMessages, 126);
    TextSystem_DisplayProgressDialog_from_thumb(message, 1, 1, 1, 0, 1);
    g_LogoContext->mSubTextFrames = 0;
}

void Logo_StateHandler_EraseCorruptedSaveData_Second(void *stateObject) {
    s32 commandBusy;
    StateMachine *stateMachine;
    g_LogoContext->mSubTextFrames = g_LogoContext->mSubTextFrames + 1;
    if (TextSystem_JustFadedIn_from_thumb() != 0) {
        MaybePlaySomeSseqFromSarc0(34);
    }
    if (g_SaveDataHolder->mBusy == 0) {
        if (g_SaveDataIoManager->mBackupEnabled != 0) {
            commandBusy = g_SaveDataIoManager->mCommandRunning;
        } else {
            commandBusy = 0;
        }
    } else {
        commandBusy = 1;
    }
    if (commandBusy != 0) {
        return;
    }
    if (TextSystem_IsDialogIdle_from_thumb() == 0) {
        return;
    }
    if (g_LogoContext->mSubTextFrames > LOGO_SUB_TEXT_FRAMES) {
        stateMachine = &g_LogoContext->mStateMachine;
        stateMachine->mNextState = LOGO_STATE_RESET_FAILED_BLOCKS_DONE;
        stateMachine->mNextStateRequested = 1;
    }
}

void Logo_StateHandler_NotifyCorruptedSaveDataErased_First(void *stateObject) {
    void *message;
    TextSystem_SetFadeInSseqId_from_thumb(33);
    message = Bmg_GetRawStringPointer_from_thumb(g_LogoContext->mCommonMessages, 128);
    TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(message, Bmg_GetRawStringPointer_from_thumb(g_LogoContext->mCommonMessages, 4));
}

void Logo_StateHandler_NotifyCorruptedSaveDataErased_Second(void *stateObject) {
    StateMachine *stateMachine;
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_SetFadeInSseqId_from_thumb(35);
        TextSystem_CloseDialog_from_thumb();
        return;
    }
    if (TextSystem_IsDialogFinished_from_thumb() == 0) {
        return;
    }
    stateMachine = &g_LogoContext->mStateMachine;
    stateMachine->mNextState = LOGO_STATE_CHECK_DWC_INIT;
    stateMachine->mNextStateRequested = 1;
}

void Logo_StateHandler_AskEraseSaveData_First(void *stateObject) {
    void *commonMessages;
    void *message;
    void *firstButtonMessage;
    void *secondButtonMessage;
    commonMessages = FindFileBuffer_G2L_GE2_CKL_CKS_S2D_M2L_MA2_from_thumb(gLogoCommonBmgFileName);
    message = Bmg_GetRawStringPointer_from_thumb(commonMessages, 124);
    firstButtonMessage = Bmg_GetRawStringPointer_from_thumb(commonMessages, 0);
    secondButtonMessage = Bmg_GetRawStringPointer_from_thumb(commonMessages, 1);
    TextSystem_DisplayDoubleButtonDialog_Simple_from_thumb(message, firstButtonMessage, secondButtonMessage, 1);
}

void Logo_StateHandler_AskEraseSaveData_Second(void *stateObject) {
    StateMachine *stateMachine;
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_CloseDialog_from_thumb();
        return;
    }
    if (TextSystem_IsDialogFinished_from_thumb() == 0) {
        return;
    }
    if (TextSystem_IsButton2Focused_from_thumb() == 0) {
        stateMachine = &g_LogoContext->mStateMachine;
        stateMachine->mNextState = LOGO_STATE_RESET_BACKUP;
        stateMachine->mNextStateRequested = 1;
        return;
    }
    stateMachine = &g_LogoContext->mStateMachine;
    stateMachine->mNextState = LOGO_STATE_CHECK_DWC_INIT;
    stateMachine->mNextStateRequested = 1;
}

void Logo_StateHandler_EraseSaveData_First(void *stateObject) {
    void *message;
    OverwriteEmptySaveData_from_thumb();
    if (g_LogoContext->mResetBackupRequested == 0) {
        return;
    }
    message = Bmg_GetRawStringPointer_from_thumb(g_LogoContext->mCommonMessages, 126);
    TextSystem_DisplayProgressDialog_from_thumb(message, 1, 1, 1, 0, 1);
    g_LogoContext->mSubTextFrames = 0;
}

void Logo_StateHandler_EraseSaveData_Second(void *stateObject) {
    LogoScene *scene;
    s32 commandBusy;
    StateMachine *stateMachine;
    g_LogoContext->mSubTextFrames = g_LogoContext->mSubTextFrames + 1;
    scene = g_LogoContext;
    if (scene->mResetBackupRequested != 0) {
        if (TextSystem_JustFadedIn_from_thumb() != 0) {
            MaybePlaySomeSseqFromSarc0(34);
        }
        if (g_SaveDataHolder->mBusy == 0) {
            if (g_SaveDataIoManager->mBackupEnabled != 0) {
                commandBusy = g_SaveDataIoManager->mCommandRunning;
            } else {
                commandBusy = 0;
            }
        } else {
            commandBusy = 1;
        }
        if (commandBusy != 0) {
            return;
        }
        if (TextSystem_IsDialogIdle_from_thumb() == 0) {
            return;
        }
        if (g_LogoContext->mSubTextFrames > LOGO_SUB_TEXT_FRAMES) {
            stateMachine = &g_LogoContext->mStateMachine;
            stateMachine->mNextState = LOGO_STATE_RESET_BACKUP_DONE;
            stateMachine->mNextStateRequested = 1;
        }
    } else {
        if (g_SaveDataHolder->mBusy == 0) {
            if (g_SaveDataIoManager->mBackupEnabled != 0) {
                commandBusy = g_SaveDataIoManager->mCommandRunning;
            } else {
                commandBusy = 0;
            }
        } else {
            commandBusy = 1;
        }
        if (commandBusy == 0) {
            stateMachine = &scene->mStateMachine;
            stateMachine->mNextState = LOGO_STATE_CHECK_DWC_INIT;
            stateMachine->mNextStateRequested = 1;
        }
    }
}

void Logo_StateHandler_NotifySaveDataErased_First(void *stateObject) {
    void *message;
    TextSystem_SetFadeInSseqId_from_thumb(33);
    message = Bmg_GetRawStringPointer_from_thumb(g_LogoContext->mCommonMessages, 127);
    TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(message, Bmg_GetRawStringPointer_from_thumb(g_LogoContext->mCommonMessages, 4));
}

void Logo_StateHandler_NotifySaveDataErased_Second(void *stateObject) {
    StateMachine *stateMachine;
    if (TextSystem_WasAnyDialogButtonPressed_from_thumb() != 0) {
        TextSystem_SetFadeInSseqId_from_thumb(35);
        TextSystem_CloseDialog_from_thumb();
        return;
    }
    if (TextSystem_IsDialogFinished_from_thumb() == 0) {
        return;
    }
    stateMachine = &g_LogoContext->mStateMachine;
    stateMachine->mNextState = LOGO_STATE_CHECK_DWC_INIT;
    stateMachine->mNextStateRequested = 1;
}
