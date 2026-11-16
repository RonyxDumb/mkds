#include "Main/Save/ghost_clear.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void ClearSaveDataGhosts_from_thumb(void) {
    Mem_CpuFill8(g_SaveDataHolder->mCourseGhostRecord, 0, sizeof(GhostRecord));
    Mem_CpuFill8(g_SaveDataHolder->mSlotGhostRecords[0], 0, sizeof(SlotGhostRecord));
}

#pragma thumb off
