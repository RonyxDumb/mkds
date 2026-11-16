#include "Main/Save/course_time_record.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void TimeTrialRecordCopyTo_from_thumb(PackedCourseTimeRecord *packedCourseTimeRecord, TimeRecord *timeRecord) {
    if (timeRecord->mFilled != 0) {
        Mem_CpuCopy8(timeRecord->mName, packedCourseTimeRecord->mName, sizeof(packedCourseTimeRecord->mName));
        packedCourseTimeRecord->mFilled = 1;
        packedCourseTimeRecord->mCharacterIndex = timeRecord->mCharacterIndex;
        packedCourseTimeRecord->mKartIndex = timeRecord->mKartIndex;
        packedCourseTimeRecord->mMinute = timeRecord->mMinute;
        packedCourseTimeRecord->mSecond = timeRecord->mSecond;
        packedCourseTimeRecord->mMillisecond = timeRecord->mMillisecond;
    } else {
        Mem_CpuFill8(packedCourseTimeRecord, 0, sizeof(PackedCourseTimeRecord));
    }
}

#pragma thumb off

#pragma thumb on

void TimeTrialCopyToSaveData_from_thumb(u32 courseId, int recordIndex, TimeRecord *timeRecord) {
    int cupCourseIndex;
    cupCourseIndex = GetCourseIdFromInternalId(courseId);
    if (cupCourseIndex != -1) {
        TimeTrialRecordCopyTo_from_thumb(&g_SaveDataHolder->mCourseTimeRecordBlock->mRecords[recordIndex][cupCourseIndex],
                             timeRecord);
    }
}

#pragma thumb off

#pragma thumb on

void TimeTrialRecord_CopyFromImpl_from_thumb(PackedCourseTimeRecord *packedCourseTimeRecord, TimeRecord *timeRecord) {
    if (packedCourseTimeRecord->mFilled != 0) {
        Mem_CpuCopy8(packedCourseTimeRecord->mName, timeRecord->mName, sizeof(timeRecord->mName));
        timeRecord->mCharacterIndex = packedCourseTimeRecord->mCharacterIndex;
        timeRecord->mKartIndex = packedCourseTimeRecord->mKartIndex;
        timeRecord->mMinute = packedCourseTimeRecord->mMinute;
        timeRecord->mSecond = packedCourseTimeRecord->mSecond;
        timeRecord->mMillisecond = packedCourseTimeRecord->mMillisecond;
        timeRecord->mFilled = 1;
    } else {
        Mem_CpuFill8(timeRecord, 0, sizeof(TimeRecord));
    }
}

BOOL TimeTrialRecord_CopyFrom_from_thumb(s32 courseId, s32 recordIndex, TimeRecord *timeRecord) {
    BOOL found;
    s32 cupCourseIndex;

    cupCourseIndex = GetCourseIdFromInternalId(courseId);
    found = TRUE;
    if (cupCourseIndex != -1) {
        TimeTrialRecord_CopyFromImpl_from_thumb(&g_SaveDataHolder->mCourseTimeRecordBlock->mRecords[recordIndex][cupCourseIndex],
                               timeRecord);
    } else {
        found = FALSE;
    }
    if (found == FALSE) {
        timeRecord->mFilled = 0;
    }
    return found;
}

void StructNKGPCupEntry_CopyFrom_from_thumb(PackedGrandPrixRecord *packedGrandPrixRecord, TimeRecord *timeRecord) {
    if (timeRecord->mFilled != 0) {
        Mem_CpuCopy8(timeRecord->mName, packedGrandPrixRecord->mName, sizeof(packedGrandPrixRecord->mName));
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
