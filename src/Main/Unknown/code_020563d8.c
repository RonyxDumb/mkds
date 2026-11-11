#include "Main/Unknown/code_020563d8.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void WriteBackupMissionRecords(void) {
    WriteBackupMissionRecordBlock(gBackupBuffers->mMissionRecordBlock);
}

#pragma thumb off
