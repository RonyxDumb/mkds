#include "Main/Save/backup_first_block_start_write.h"
#include "Main/Save/backup_busy.h"
#include "Main/System/thread_function_queue.h"
#include "Main/MapObjects/data_0217a000.h"

#pragma thumb on

void StartWriteBackupFirstBlock(void) {
    SetBackupBusy();
    QueueThreadFunction(WriteBackupFirstBlockAndWait);
    gThreadFunctionQueue->mRunRequested = 1;
}

#pragma thumb off
