#include "Main/Save/backup_records_write.h"
#include "Main/Save/backup.h"
#include "Main/System/backup_net_camera_work.h"
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
