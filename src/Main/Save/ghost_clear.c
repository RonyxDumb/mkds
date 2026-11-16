#include "Main/Save/ghost_clear.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void ClearCourseAndFirstSlotGhost(void) {
    MI_CpuFill8(gBackupBuffers->mCourseGhostRecord, 0, sizeof(GhostRecord));
    MI_CpuFill8(gBackupBuffers->mSlotGhostRecords[0], 0, sizeof(SlotGhostRecord));
}

#pragma thumb off
