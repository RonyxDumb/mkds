#include "Main/Save/emblem_record.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on
void ClearSaveDataSection_Emblem_from_thumb(void) {
    Mem_CpuFill8(g_SaveDataHolder->mEmblemRecord, 0u, sizeof(EmblemRecord));
}
#pragma thumb off

#pragma thumb on
void ClearSaveDataSection_GrandPrix_from_thumb(void) {
    Mem_CpuFill8(g_SaveDataHolder->mGrandPrixRecordBlock, 0u, sizeof(GrandPrixRecordBlock));
}
#pragma thumb off

#pragma thumb on
void ClearSaveDataSection_TimeTrials_from_thumb(void) {
    Mem_CpuFill8(g_SaveDataHolder->mCourseTimeRecordBlock, 0u, sizeof(CourseTimeRecordBlock));
}
#pragma thumb off

#pragma thumb on
void ClearSaveDataSection_MissionRun_from_thumb(void) {
    Mem_CpuFill8(g_SaveDataHolder->mMissionRecordBlock, 0u, sizeof(MissionRecordBlock));
}
#pragma thumb off
