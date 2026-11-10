#include "Main/Unknown/code_020563ec.h"
#include "Main/Unknown/code_020574a0.h"
#include "Main/Unknown/code_02057a18.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

// Writes the course time record block now and only starts the write of the first block.
void WriteCourseTimeRecordsAndFirstBlock(void) {
    WriteBackupCourseTimeRecordBlock(data_0217aa08->mCourseTimeRecordBlock);
    StartWriteBackupFirstBlock();
}

#pragma thumb off
