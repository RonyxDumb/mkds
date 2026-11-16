#include "Main/Save/backup_mission_records.h"
#include "Main/Save/backup.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void WriteSaveDataMissionRunSection_from_thumb(void) {
    WriteSaveDataSection_MissionRun_from_thumb(g_SaveDataHolder->mMissionRecordBlock);
}

#pragma thumb off
