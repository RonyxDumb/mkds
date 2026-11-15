#include "Main/Save/grand_prix_record_get.h"
#include "Main/Save/course_time_record.h"
#include "Main/System/backup_net_camera_work.h"
#include "cpu_copy_fill.h"
#include "Main/Save/ghost_record_file.h"

#pragma thumb on

void SetGrandPrixRecord(int cup, int engineClass, TimeRecord *record) {
    PackGrandPrixRecord(&gBackupBuffers->mGrandPrixRecordBlock->mRecords[engineClass][cup], record);
}

#pragma thumb off

#pragma thumb on

void UnpackGrandPrixRecord(PackedGrandPrixRecord *packedGrandPrixRecord, TimeRecord *timeRecord) {
    if (packedGrandPrixRecord->mFilled != 0) {
        MI_CpuCopy8(packedGrandPrixRecord->mName, timeRecord->mName, sizeof(timeRecord->mName));
        timeRecord->mCharacterIndex = packedGrandPrixRecord->mCharacterIndex;
        timeRecord->mKartIndex = packedGrandPrixRecord->mKartIndex;
        timeRecord->mMinute = packedGrandPrixRecord->mMinute;
        timeRecord->mSecond = packedGrandPrixRecord->mSecond;
        timeRecord->mMillisecond = packedGrandPrixRecord->mMillisecond;
        timeRecord->mGrade = packedGrandPrixRecord->mGrade;
        timeRecord->mTotalPoints = packedGrandPrixRecord->mTotalPoints;
        timeRecord->mCupRank = packedGrandPrixRecord->mCupRank;
        timeRecord->mFilled = 1;
    } else {
        timeRecord->mFilled = 0;
    }
}

#pragma thumb off

#pragma thumb on

u32 GetGrandPrixRecord(int cup, int engineClass, TimeRecord *record) {
    UnpackGrandPrixRecord(&gBackupBuffers->mGrandPrixRecordBlock->mRecords[engineClass][cup], record);
    return 1;
}

#pragma thumb off
