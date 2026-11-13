#include "Main/Save/buddy_record_clear.h"
#include "Main/MapObjects/data_0217a000.h"
#include "code_0214d018.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on
void ClearBuddyRecordBlock(void) {
    MI_CpuFill8(gBackupBuffers->mBuddyRecordBlock, 0u, 0xc00u);
}
#pragma thumb off
