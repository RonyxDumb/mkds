#pragma once

#include "types.h"

// States of LogoScene.mStateMachine, in the order of gLogoStateTable.
typedef enum LogoState {
    LOGO_STATE_READ_BACKUP = 0, // reads the backup and counts 120 frames
    LOGO_STATE_WAIT_BACKUP_READ = 1,
    LOGO_STATE_RESET_NOTICE = 2, // message with one button before the failed blocks are reset
    LOGO_STATE_RESET_FAILED_BLOCKS = 3,
    LOGO_STATE_RESET_FAILED_BLOCKS_DONE = 4, // message with one button after the reset
    LOGO_STATE_ASK_RESET_BACKUP = 5, // message with two buttons
    LOGO_STATE_RESET_BACKUP = 6,
    LOGO_STATE_RESET_BACKUP_DONE = 7, // message with one button after the reset
    LOGO_STATE_CHECK_DWC_INIT = 8,
    LOGO_STATE_DWC_NOTICE_FIRST = 9,
    LOGO_STATE_DWC_NOTICE_SECOND = 10,
    LOGO_STATE_END = 11, // the scene asks for the next scene
} LogoState;

extern const char gLogoAskResetBackupCommonBmgFileName[];

void UpdateLogoResetBackupDone(void *stateObject);
void EnterLogoResetBackupDone(void *stateObject);
void UpdateLogoResetBackup(void *stateObject);
void EnterLogoResetBackup(void *stateObject);
void UpdateLogoAskResetBackup(void *stateObject);
void EnterLogoAskResetBackup(void *stateObject);
void UpdateLogoResetFailedBlocksDone(void *stateObject);
void EnterLogoResetFailedBlocksDone(void *stateObject);
void UpdateLogoResetFailedBlocks(void *stateObject);
void EnterLogoResetFailedBlocks(void *stateObject);
void UpdateLogoResetNotice(void *stateObject);
void EnterLogoResetNotice(void *stateObject);
void UpdateLogoWaitBackupRead(void *stateObject);
