#include "Main/Unknown/code_02056408.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void WriteBackupEmblem(void) {
    WriteBackupEmblemRecord(gBackupBuffers->mEmblemRecord);
}

void WriteBackupGrandPrixRecords(void) {
    WriteBackupGrandPrixRecordBlock(gBackupBuffers->mGrandPrixRecordBlock);
}

void WriteBackupCourseTimeRecords(void) {
    WriteBackupCourseTimeRecordBlock(gBackupBuffers->mCourseTimeRecordBlock);
}

#pragma thumb off
