#include "Main/Save/course_time_records_and_first.h"
#include "Main/Save/backup_first_block_start_write.h"
#include "Main/Save/backup.h"
#include "Main/System/backup_net_camera_work.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

// Writes the course time record block now and only starts the write of the first block.
void WriteTimeTrialsSaveDataSectionAndHeader_from_thumb(void) {
    WriteSaveDataSection_TimeTrials_from_thumb(g_SaveDataHolder->mCourseTimeRecordBlock);
    WriteSaveDataHeader_from_thumb();
}

#pragma thumb off
