#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057ca4.h"
#include "01/code_021956dc.h"

#pragma thumb on

void savd_beginOperation(void) {
    gSaveData->mBusy = 1;
}

void savd_endOperation(void) {
    gSaveData->mBusy = 0;
}

void savd_writeNksyTask(void) {
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    savd_writeNksy(gSaveData->mFirstBlock);
    if (gSaveCore->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    savd_endOperation();
}

#pragma thumb off
