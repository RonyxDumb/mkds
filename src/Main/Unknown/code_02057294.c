#include "Main/Unknown/code_02057294.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on
void ClearEmblemRecord(void) {
    MI_CpuFill8(gBackupBuffers->mEmblemRecord, 0u, 0x300u);
}
#pragma thumb off

#pragma thumb on
void ClearGrandPrixRecordBlock(void) {
    MI_CpuFill8(gBackupBuffers->mGrandPrixRecordBlock, 0u, 0x400u);
}
#pragma thumb off

#pragma thumb on
void ClearCourseTimeRecordBlock(void) {
    MI_CpuFill8(gBackupBuffers->mCourseTimeRecordBlock, 0u, 0x1600u);
}
#pragma thumb off

#pragma thumb on
void ClearMissionRecordBlock(void) {
    MI_CpuFill8(gBackupBuffers->mMissionRecordBlock, 0u, 0x100u);
}
#pragma thumb off
