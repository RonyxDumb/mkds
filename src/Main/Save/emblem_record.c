#include "Main/Save/emblem_record.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on
void ClearEmblemRecord(void) {
    MI_CpuFill8(gBackupBuffers->mEmblemRecord, 0u, sizeof(EmblemRecord));
}
#pragma thumb off

#pragma thumb on
void ClearGrandPrixRecordBlock(void) {
    MI_CpuFill8(gBackupBuffers->mGrandPrixRecordBlock, 0u, sizeof(GrandPrixRecordBlock));
}
#pragma thumb off

#pragma thumb on
void ClearCourseTimeRecordBlock(void) {
    MI_CpuFill8(gBackupBuffers->mCourseTimeRecordBlock, 0u, sizeof(CourseTimeRecordBlock));
}
#pragma thumb off

#pragma thumb on
void ClearMissionRecordBlock(void) {
    MI_CpuFill8(gBackupBuffers->mMissionRecordBlock, 0u, sizeof(MissionRecordBlock));
}
#pragma thumb off
