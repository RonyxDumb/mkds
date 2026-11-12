#include "Main/Save/course_time_record.h"
#include "Main/Unknown/code_02056cac.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02056c6c.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Unknown/code_02046000.h"

#pragma thumb on

void PackCourseTimeRecord(PackedCourseTimeRecord *packedCourseTimeRecord, TimeRecord *timeRecord) {
    if (timeRecord->mFilled != 0) {
        MI_CpuCopy8(timeRecord->mName, packedCourseTimeRecord->mName, 0x14);
        packedCourseTimeRecord->mFilled = 1;
        packedCourseTimeRecord->mCharacterIndex = timeRecord->mCharacterIndex;
        packedCourseTimeRecord->mKartIndex = timeRecord->mKartIndex;
        packedCourseTimeRecord->mMinute = timeRecord->mMinute;
        packedCourseTimeRecord->mSecond = timeRecord->mSecond;
        packedCourseTimeRecord->mMillisecond = timeRecord->mMillisecond;
    } else {
        MI_CpuFill8(packedCourseTimeRecord, 0, 0x1c);
    }
}

#pragma thumb off

#pragma thumb on

void SetCourseTimeRecord(u32 courseId, int recordIndex, TimeRecord *timeRecord) {
    int cupCourseIndex;
    cupCourseIndex = FindCupCourseIndex(courseId);
    if (cupCourseIndex != -1) {
        PackCourseTimeRecord(&gBackupBuffers->mCourseTimeRecordBlock->mRecords[recordIndex][cupCourseIndex],
                             timeRecord);
    }
}

#pragma thumb off

#pragma thumb on

void UnpackCourseTimeRecord(PackedCourseTimeRecord *packedCourseTimeRecord, TimeRecord *timeRecord) {
    if (packedCourseTimeRecord->mFilled != 0) {
        MI_CpuCopy8(packedCourseTimeRecord->mName, timeRecord->mName, 0x14);
        timeRecord->mCharacterIndex = packedCourseTimeRecord->mCharacterIndex;
        timeRecord->mKartIndex = packedCourseTimeRecord->mKartIndex;
        timeRecord->mMinute = packedCourseTimeRecord->mMinute;
        timeRecord->mSecond = packedCourseTimeRecord->mSecond;
        timeRecord->mMillisecond = packedCourseTimeRecord->mMillisecond;
        timeRecord->mFilled = 1;
    } else {
        MI_CpuFill8(timeRecord, 0, 0x20);
    }
}

BOOL GetCourseTimeRecord(s32 courseId, s32 recordIndex, TimeRecord *timeRecord) {
    BOOL found;
    s32 cupCourseIndex;

    cupCourseIndex = FindCupCourseIndex(courseId);
    found = TRUE;
    if (cupCourseIndex != -1) {
        UnpackCourseTimeRecord(&gBackupBuffers->mCourseTimeRecordBlock->mRecords[recordIndex][cupCourseIndex],
                               timeRecord);
    } else {
        found = FALSE;
    }
    if (found == FALSE) {
        timeRecord->mFilled = 0;
    }
    return found;
}

void PackGrandPrixRecord(PackedGrandPrixRecord *packedGrandPrixRecord, TimeRecord *timeRecord) {
    if (timeRecord->mFilled != 0) {
        MI_CpuCopy8(timeRecord->mName, packedGrandPrixRecord->mName, 0x14);
        packedGrandPrixRecord->mFilled = 1;
        packedGrandPrixRecord->mCharacterIndex = timeRecord->mCharacterIndex;
        packedGrandPrixRecord->mKartIndex = timeRecord->mKartIndex;
        packedGrandPrixRecord->mMinute = timeRecord->mMinute;
        packedGrandPrixRecord->mSecond = timeRecord->mSecond;
        packedGrandPrixRecord->mMillisecond = timeRecord->mMillisecond;
        packedGrandPrixRecord->mGrade = timeRecord->mGrade;
        packedGrandPrixRecord->mTotalPoints = timeRecord->mTotalPoints;
        packedGrandPrixRecord->mCupRank = timeRecord->mCupRank;
    }
}

#pragma thumb off
