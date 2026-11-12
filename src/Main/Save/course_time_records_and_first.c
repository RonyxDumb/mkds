#include "Main/Save/course_time_records_and_first.h"
#include "Main/Save/backup_first_block_start_write.h"
#include "Main/Save/backup.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

// Writes the course time record block now and only starts the write of the first block.
void WriteCourseTimeRecordsAndFirstBlock(void) {
    WriteBackupCourseTimeRecordBlock(gBackupBuffers->mCourseTimeRecordBlock);
    StartWriteBackupFirstBlock();
}

#pragma thumb off
