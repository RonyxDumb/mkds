#pragma once

#include "types.h"

// States of LogoScene.mStateMachine, in the order of g_E7FnList0.
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

extern const char gLogoCommonBmgFileName[];

void Logo_StateHandler_NotifySaveDataErased_Second(void *stateObject);
void Logo_StateHandler_NotifySaveDataErased_First(void *stateObject);
void Logo_StateHandler_EraseSaveData_Second(void *stateObject);
void Logo_StateHandler_EraseSaveData_First(void *stateObject);
void Logo_StateHandler_AskEraseSaveData_Second(void *stateObject);
void Logo_StateHandler_AskEraseSaveData_First(void *stateObject);
void Logo_StateHandler_NotifyCorruptedSaveDataErased_Second(void *stateObject);
void Logo_StateHandler_NotifyCorruptedSaveDataErased_First(void *stateObject);
void Logo_StateHandler_EraseCorruptedSaveData_Second(void *stateObject);
void Logo_StateHandler_EraseCorruptedSaveData_First(void *stateObject);
void Logo_StateHandler_NotifySaveDataCorrupted_Second(void *stateObject);
void Logo_StateHandler_NotifySaveDataCorrupted_First(void *stateObject);
void Logo_StateHandler_WaitCheckSaveData_Second(void *stateObject);
