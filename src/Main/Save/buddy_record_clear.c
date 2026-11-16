#include "Main/Save/buddy_record_clear.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on
void ClearBuddyRecordBlock(void) {
    MI_CpuFill8(gBackupBuffers->mBuddyRecordBlock, 0u, sizeof(BuddyRecordBlock));
}
#pragma thumb off
