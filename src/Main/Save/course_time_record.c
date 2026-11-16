#include "Main/Save/course_time_record.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void PackCourseTimeRecord(PackedCourseTimeRecord *packedCourseTimeRecord, TimeRecord *timeRecord) {
    if (timeRecord->mFilled != 0) {
        MI_CpuCopy8(timeRecord->mName, packedCourseTimeRecord->mName, sizeof(packedCourseTimeRecord->mName));
        packedCourseTimeRecord->mFilled = 1;
        packedCourseTimeRecord->mCharacterIndex = timeRecord->mCharacterIndex;
        packedCourseTimeRecord->mKartIndex = timeRecord->mKartIndex;
        packedCourseTimeRecord->mMinute = timeRecord->mMinute;
        packedCourseTimeRecord->mSecond = timeRecord->mSecond;
        packedCourseTimeRecord->mMillisecond = timeRecord->mMillisecond;
    } else {
        MI_CpuFill8(packedCourseTimeRecord, 0, sizeof(PackedCourseTimeRecord));
    }
}

void SetCourseTimeRecord(u32 courseId, int recordIndex, TimeRecord *timeRecord) {
    int cupCourseIndex;
    cupCourseIndex = FindCupCourseIndex(courseId);
    if (cupCourseIndex != -1) {
        PackCourseTimeRecord(&gBackupBuffers->mCourseTimeRecordBlock->mRecords[recordIndex][cupCourseIndex],
                             timeRecord);
    }
}

void UnpackCourseTimeRecord(PackedCourseTimeRecord *packedCourseTimeRecord, TimeRecord *timeRecord) {
    if (packedCourseTimeRecord->mFilled != 0) {
        MI_CpuCopy8(packedCourseTimeRecord->mName, timeRecord->mName, sizeof(timeRecord->mName));
        timeRecord->mCharacterIndex = packedCourseTimeRecord->mCharacterIndex;
        timeRecord->mKartIndex = packedCourseTimeRecord->mKartIndex;
        timeRecord->mMinute = packedCourseTimeRecord->mMinute;
        timeRecord->mSecond = packedCourseTimeRecord->mSecond;
        timeRecord->mMillisecond = packedCourseTimeRecord->mMillisecond;
        timeRecord->mFilled = 1;
    } else {
        MI_CpuFill8(timeRecord, 0, sizeof(TimeRecord));
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
        MI_CpuCopy8(timeRecord->mName, packedGrandPrixRecord->mName, sizeof(packedGrandPrixRecord->mName));
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
