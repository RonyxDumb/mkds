#include "Main/Unknown/code_02056408.h"
#include "Main/Save/BackupBlocks.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void savd_flushNkem(void) {
    savd_writeNkem(gSaveData->mEmblemRecord);
}

void savd_flushNkgp(void) {
    savd_writeNkgp(gSaveData->mGrandPrixRecordBlock);
}

void savd_flushNkta(void) {
    savd_writeNkta(gSaveData->mCourseTimeRecordBlock);
}

#pragma thumb off
