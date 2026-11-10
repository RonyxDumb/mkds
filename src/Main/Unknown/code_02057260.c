#include "Main/Unknown/code_02057260.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

void ClearCourseAndFirstSlotGhost(void) {
    MI_CpuFill8(data_0217aa08->mCourseGhostRecord, 0, (0x00000e00u));
    MI_CpuFill8(data_0217aa08->mSlotGhostRecords[0], 0, (0x00001000u));
}

#pragma thumb off
