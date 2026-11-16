#include "Main/Unknown/code_020563d8.h"
#include "Main/Save/BackupBlocks.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void savd_flushNkmr(void) {
    savd_writeNkmr(gSaveData->mMissionRecordBlock);
}

#pragma thumb off
