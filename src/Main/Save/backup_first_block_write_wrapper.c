#include "Main/Save/backup_first_block_write_wrapper.h"
#include "Main/Save/backup_first_block.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on
void WriteBackupFirstBlockWrapper(void) {
    WriteBackupFirstBlock(gBackupBuffers->mFirstBlock);
}
#pragma thumb off
