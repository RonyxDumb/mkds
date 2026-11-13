#include "Main/Save/backup_busy.h"
#include "Main/Save/backup_first_block.h"
#include "01/Menu/record_time_attack.h"
#include "01/Menu/code_02196d58.h"
#include "Main/Save/ghost_record_file.h"

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
