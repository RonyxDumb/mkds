#include "Main/Save/backup_mission_records.h"
#include "Main/Save/backup.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void WriteBackupMissionRecords(void) {
    WriteBackupMissionRecordBlock(gBackupBuffers->mMissionRecordBlock);
}

#pragma thumb off
