#include "Main/Save/ghost_clear.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_0214d018.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void ClearCourseAndFirstSlotGhost(void) {
    MI_CpuFill8(gBackupBuffers->mCourseGhostRecord, 0, sizeof(GhostRecord));
    MI_CpuFill8(gBackupBuffers->mSlotGhostRecords[0], 0, 0x1000);
}

#pragma thumb off
