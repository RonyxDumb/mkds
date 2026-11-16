#include "Main/Unknown/code_020563ec.h"
#include "Main/Unknown/code_020574a0.h"
#include "Main/Save/BackupBlocks.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void func_020563ec(void) {
    savd_writeNkta(gSaveData->mCourseTimeRecordBlock);
    savd_writeNksyAsync();
}

#pragma thumb off
