#include "Main/Unknown/code_02056a7c.h"
#include "Main/Unknown/code_02056b08.h"
#include "Main/Unknown/code_02056b30.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02056aa4.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214d018.h"

#pragma thumb on

void SetGrandPrixRecord(int cup, int engineClass, TimeRecord *record) {
    PackGrandPrixRecord(&gBackupBuffers->mGrandPrixRecordBlock->mRecords[engineClass][cup], record);
}

#pragma thumb off

#pragma thumb on

void UnpackGrandPrixRecord(PackedGrandPrixRecord *packedGrandPrixRecord, TimeRecord *timeRecord) {
    if (packedGrandPrixRecord->mFilled != 0) {
        MI_CpuCopy8(packedGrandPrixRecord->mName, timeRecord->mName, 0x14);
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
