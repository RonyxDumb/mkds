#include "Main/Save/backup_records_write.h"
#include "Main/Save/backup.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Save/ghost_record_file.h"

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
