#include "Main/Menu/logo_backup_read_and_reset.h"
#include "Main/Net/multiboot_parent_finish.h"
#include "Main/Save/backup_reset.h"
#include "Main/Sound/sound_init_scene_sounds_and_screen_seqs.h"
#include "Main/Menu/txt_system.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/record_time_attack_requests.h"
#include "Main/Save/ghost_record_file.h"

void UpdateLogoWaitBackupRead(void *stateObject) {
    s32 commandBusy;
    StateMachine *stateMachine;
    s32 readStatus;
    LogoScene *scene;
    if (gBackupBuffers->mBusy == 0) {
        if (gBackupAccess->mBackupEnabled != 0) {
            commandBusy = gBackupAccess->mCommandRunning;
        } else {
            commandBusy = 0;
        }
    } else {
        commandBusy = 1;
    }
    if (commandBusy != 0) {
        return;
    }
    readStatus = gBackupBuffers->mReadStatus;
    if (readStatus != 0) {
        if (readStatus == BACKUP_READ_STATUS_BLOCKS_FAILED) {
            gLogoScene->mUnk_2c_1 = 1;
            stateMachine = &gLogoScene->mStateMachine;
            stateMachine->mNextState = LOGO_STATE_RESET_NOTICE;
            stateMachine->mNextStateRequested = 1;
        } else if (gBackupAccess->mErrorCode == BACKUP_ERROR_BAD_PREFIX) {
            gLogoScene->mUnk_2c_1 = 0;
            stateMachine = &gLogoScene->mStateMachine;
            stateMachine->mNextState = LOGO_STATE_RESET_BACKUP;
            stateMachine->mNextStateRequested = 1;
        } else {
            stateMachine = &gLogoScene->mStateMachine;
            stateMachine->mNextState = LOGO_STATE_CHECK_DWC_INIT;
            stateMachine->mNextStateRequested = 1;
        }
    } else {
        scene = gLogoScene;
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

void EnterLogoResetNotice(void *stateObject) {
    void *message;
    message = GetBmgEntry(gLogoScene->mCommonMessages, 125);
    SetupTxtSystemSubTextButton(message, GetBmgEntry(gLogoScene->mCommonMessages, 4));
}

void UpdateLogoResetNotice(void *stateObject) {
    StateMachine *stateMachine;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() == 0) {
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = LOGO_STATE_RESET_FAILED_BLOCKS;
    stateMachine->mNextStateRequested = 1;
}

void EnterLogoResetFailedBlocks(void *stateObject) {
    void *message;
    StartResetFailedBackupBlocks();
    message = GetBmgEntry(gLogoScene->mCommonMessages, 126);
    SetupTxtSystemSubTextEx(message, 1, 1, 1, 0, 1);
    gLogoScene->mSubTextFrames = 0;
}

void UpdateLogoResetFailedBlocks(void *stateObject) {
    s32 commandBusy;
    StateMachine *stateMachine;
    gLogoScene->mSubTextFrames = gLogoScene->mSubTextFrames + 1;
    if (IsTxtSystemOpenAfterOpening() != 0) {
        StartSoundOncePerFrame(34);
    }
    if (gBackupBuffers->mBusy == 0) {
        if (gBackupAccess->mBackupEnabled != 0) {
            commandBusy = gBackupAccess->mCommandRunning;
        } else {
            commandBusy = 0;
        }
    } else {
        commandBusy = 1;
    }
    if (commandBusy != 0) {
        return;
    }
    if (IsTxtSystemOpenNoCloseRequest() == 0) {
        return;
    }
    if (gLogoScene->mSubTextFrames > LOGO_SUB_TEXT_FRAMES) {
        stateMachine = &gLogoScene->mStateMachine;
        stateMachine->mNextState = LOGO_STATE_RESET_FAILED_BLOCKS_DONE;
        stateMachine->mNextStateRequested = 1;
    }
}

void EnterLogoResetFailedBlocksDone(void *stateObject) {
    void *message;
    SetTxtSystemOpenSoundId(33);
    message = GetBmgEntry(gLogoScene->mCommonMessages, 128);
    SetupTxtSystemSubTextButton(message, GetBmgEntry(gLogoScene->mCommonMessages, 4));
}

void UpdateLogoResetFailedBlocksDone(void *stateObject) {
    StateMachine *stateMachine;
    if (GetTxtSystemDone() != 0) {
        SetTxtSystemOpenSoundId(35);
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() == 0) {
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = LOGO_STATE_CHECK_DWC_INIT;
    stateMachine->mNextStateRequested = 1;
}

void EnterLogoAskResetBackup(void *stateObject) {
    void *commonMessages;
    void *message;
    void *firstButtonMessage;
    void *secondButtonMessage;
    commonMessages = FindFileInLoadedArchives(gLogoCommonBmgFileName);
    message = GetBmgEntry(commonMessages, 124);
    firstButtonMessage = GetBmgEntry(commonMessages, 0);
    secondButtonMessage = GetBmgEntry(commonMessages, 1);
    SetupTxtSystemSubTextTwoButtons(message, firstButtonMessage, secondButtonMessage, 1);
}

void UpdateLogoAskResetBackup(void *stateObject) {
    StateMachine *stateMachine;
    if (GetTxtSystemDone() != 0) {
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() == 0) {
        return;
    }
    if (GetTxtSystemSelectedIndex() == 0) {
        stateMachine = &gLogoScene->mStateMachine;
        stateMachine->mNextState = LOGO_STATE_RESET_BACKUP;
        stateMachine->mNextStateRequested = 1;
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = LOGO_STATE_CHECK_DWC_INIT;
    stateMachine->mNextStateRequested = 1;
}

void EnterLogoResetBackup(void *stateObject) {
    void *message;
    ResetBackupAndStartWrite();
    if (gLogoScene->mResetBackupRequested == 0) {
        return;
    }
    message = GetBmgEntry(gLogoScene->mCommonMessages, 126);
    SetupTxtSystemSubTextEx(message, 1, 1, 1, 0, 1);
    gLogoScene->mSubTextFrames = 0;
}

void UpdateLogoResetBackup(void *stateObject) {
    LogoScene *scene;
    s32 commandBusy;
    StateMachine *stateMachine;
    gLogoScene->mSubTextFrames = gLogoScene->mSubTextFrames + 1;
    scene = gLogoScene;
    if (scene->mResetBackupRequested != 0) {
        if (IsTxtSystemOpenAfterOpening() != 0) {
            StartSoundOncePerFrame(34);
        }
        if (gBackupBuffers->mBusy == 0) {
            if (gBackupAccess->mBackupEnabled != 0) {
                commandBusy = gBackupAccess->mCommandRunning;
            } else {
                commandBusy = 0;
            }
        } else {
            commandBusy = 1;
        }
        if (commandBusy != 0) {
            return;
        }
        if (IsTxtSystemOpenNoCloseRequest() == 0) {
            return;
        }
        if (gLogoScene->mSubTextFrames > LOGO_SUB_TEXT_FRAMES) {
            stateMachine = &gLogoScene->mStateMachine;
            stateMachine->mNextState = LOGO_STATE_RESET_BACKUP_DONE;
            stateMachine->mNextStateRequested = 1;
        }
    } else {
        if (gBackupBuffers->mBusy == 0) {
            if (gBackupAccess->mBackupEnabled != 0) {
                commandBusy = gBackupAccess->mCommandRunning;
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

void EnterLogoResetBackupDone(void *stateObject) {
    void *message;
    SetTxtSystemOpenSoundId(33);
    message = GetBmgEntry(gLogoScene->mCommonMessages, 127);
    SetupTxtSystemSubTextButton(message, GetBmgEntry(gLogoScene->mCommonMessages, 4));
}

void UpdateLogoResetBackupDone(void *stateObject) {
    StateMachine *stateMachine;
    if (GetTxtSystemDone() != 0) {
        SetTxtSystemOpenSoundId(35);
        RequestTxtSystemClose();
        return;
    }
    if (IsTxtSystemClosedNoOpenRequest() == 0) {
        return;
    }
    stateMachine = &gLogoScene->mStateMachine;
    stateMachine->mNextState = LOGO_STATE_CHECK_DWC_INIT;
    stateMachine->mNextStateRequested = 1;
}
