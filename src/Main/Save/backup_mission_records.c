#include "Main/Save/backup_mission_records.h"
#include "Main/Save/backup.h"
#include "Main/MapObjects/data_0217a000.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void WriteBackupMissionRecords(void) {
    WriteBackupMissionRecordBlock(gBackupBuffers->mMissionRecordBlock);
}

#pragma thumb off
