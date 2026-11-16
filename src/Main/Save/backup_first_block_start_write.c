#include "Main/Save/backup_first_block_start_write.h"
#include "Main/Save/backup_busy.h"
#include "Main/System/thread_function_queue.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void WriteSaveDataHeader_from_thumb(void) {
    EnableMKDSSVSomeFlag_from_thumb();
    WorkerInsertTask(Task_WriteSaveDataHeader_from_thumb);
    g_WorkerContext->mRunRequested = 1;
}

#pragma thumb off
