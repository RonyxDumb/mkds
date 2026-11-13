#include "Main/Save/ghost_clear.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_0214d018.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void ClearCourseAndFirstSlotGhost(void) {
    MI_CpuFill8(gBackupBuffers->mCourseGhostRecord, 0, (0x00000e00u));
    MI_CpuFill8(gBackupBuffers->mSlotGhostRecords[0], 0, (0x00001000u));
}

#pragma thumb off
