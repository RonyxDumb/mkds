#include "Main/Save/backup_records_write.h"
#include "Main/Save/backup.h"
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
