#include "Main/Save/backup_records_write.h"
#include "Main/Save/backup.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void WriteBackupEmblem(void) {
    WriteSaveDataSection_Emblem_from_thumb(g_SaveDataHolder->mEmblemRecord);
}

void SaveNKGPChunk_from_thumb(void) {
    WriteSaveDataSection_GrandPrix_from_thumb(g_SaveDataHolder->mGrandPrixRecordBlock);
}

void WriteTimeTrialsSaveDataSection_from_thumb(void) {
    WriteSaveDataSection_TimeTrials_from_thumb(g_SaveDataHolder->mCourseTimeRecordBlock);
}

#pragma thumb off
