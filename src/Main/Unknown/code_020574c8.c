#include "Main/Unknown/code_020574c8.h"
#include "Main/Unknown/code_02057ca4.h"
#include "01/code_021956dc.h"

#pragma thumb on

void SetBackupBusy(void) {
    gBackupBuffers->mBusy = 1;
}

void ClearBackupBusy(void) {
    gBackupBuffers->mBusy = 0;
}

void WriteBackupFirstBlockAndWait(void) {
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    WriteBackupFirstBlock(gBackupBuffers->mFirstBlock);
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    ClearBackupBusy();
}

#pragma thumb off
