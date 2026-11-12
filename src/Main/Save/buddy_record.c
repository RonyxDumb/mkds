#include "Main/Save/buddy_record.h"
#include "Main/Race/demo_race.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Save/course_time_records_and_first.h"
#include "Main/Save/backup_records_write.h"
#include "Main/Save/grand_prix_record_get.h"
#include "Main/Save/course_time_record.h"
#include "Main/Unknown/code_02056c6c.h"
#include "Main/Save/backup_bit_array.h"
#include "Main/Save/buddy_record_reset.h"
#include "Main/Save/buddy_records_write.h"
#include "Main/Save/buddy_record_time.h"
#include "dwc_account.h"
#include "code_0214d018.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/Lib/DWC/dwc_friend.h"

static inline s32 TryGetFilledTimeRecord(s32 courseId, s32 recordIndex, TimeRecord *timeRecord) {
    BOOL isFilled;

    if (GetCourseTimeRecord(courseId, recordIndex, timeRecord) != 0 && timeRecord->mFilled != 0) {
        isFilled = TRUE;
    } else {
        isFilled = FALSE;
    }
    return isFilled;
}

void CopyWiFiBuddiesToRecordBlock(DWCAccFriendData *buddies) {
    MI_CpuCopy8(buddies, gBackupBuffers->mBuddyRecordBlock->mFriendData, 0x2d0);
}

void RefreshNotYetBuddyFlags(void) {
    BuddyRecord buddyRecord;
    u8 recordIndex;

    for (recordIndex = 0; recordIndex < 60; recordIndex++) {
        GetBuddyRecord(recordIndex, &buddyRecord);
        if (buddyRecord.mFilled == 1 && buddyRecord.mNotYetBuddy == 1 &&
            DWC_IsBuddyFriendData(&gBackupBuffers->mBuddyRecordBlock->mFriendData[recordIndex]) != 0) {
            buddyRecord.mNotYetBuddy = 0;
            SetBuddyRecord(recordIndex, &buddyRecord);
        }
    }
}

BOOL IsBuddyRecordFilled(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return TRUE;
    }
    return FALSE;
}

s32 IsBuddyRecordFlagged(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mFlagged;
    }
    return 0;
}

s32 GetBuddyRecordMatchKind0FirstCount(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[0][0];
    }
    return -1;
}

s32 GetBuddyRecordMatchKind0SecondCount(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[0][1];
    }
    return -1;
}

s32 GetBuddyRecordMatchKind1FirstCount(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[1][0];
    }
    return -1;
}

s32 GetBuddyRecordMatchKind1SecondCount(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[1][1];
    }
    return -1;
}

s32 GetBuddyRecordMatchKind2FirstCount(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[2][0];
    }
    return -1;
}

s32 GetBuddyRecordMatchKind2SecondCount(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[2][1];
    }
    return -1;
}

BOOL GetBuddyRecordDate(u8 recordIndex, u8 *dateOut) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled != 1) {
        return FALSE;
    }
    dateOut[0] = buddyRecord.mYear;
    dateOut[1] = buddyRecord.mMonth;
    dateOut[2] = buddyRecord.mDay;
    return TRUE;
}

BOOL GetBuddyRecordName(u8 recordIndex, void *nameOut) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled != 1) {
        return FALSE;
    }
    MI_CpuCopy8(buddyRecord.mName, nameOut, 0x14);
    return TRUE;
}

BOOL SetBuddyRecordFlag(u8 recordIndex, s32 flag) {
    BuddyRecord buddyRecord;

    GetBuddyRecord(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        buddyRecord.mFlagged = flag != 0;
        SetBuddyRecord(recordIndex, &buddyRecord);
        return TRUE;
    }
    return FALSE;
}

s32 RemoveBuddyRecord(u8 recordIndex) {
    BuddyRecord buddyRecord;
    BOOL wasFilled;

    GetBuddyRecord(recordIndex, &buddyRecord);
    wasFilled = buddyRecord.mFilled == 1;
    MI_CpuFill8(&buddyRecord, 0, 0x24);
    buddyRecord.mFilled = 0;
    SetBuddyRecord(recordIndex, &buddyRecord);
    if (gWiFiSession->mStateMachine.mState != 0) {
        DWC_DeleteBuddyFriendData(&gBackupBuffers->mBuddyRecordBlock->mFriendData[recordIndex]);
    } else {
        MI_CpuFill8(&gBackupBuffers->mBuddyRecordBlock->mFriendData[recordIndex], 0, 0xc);
    }
    WriteBackupBuddyRecords();
    return wasFilled;
}

void MergeBuddyRecords(u8 keptIndex, u8 mergedIndex) {
    BuddyRecord keptRecord;
    BuddyRecord mergedRecord;
    BuddyRecord combinedRecord;

    GetBuddyRecord(keptIndex, &keptRecord);
    GetBuddyRecord(mergedIndex, &mergedRecord);
    ResetBuddyRecord(&combinedRecord);
    if (mergedRecord.mNotYetBuddy == 0) {
        combinedRecord.mResultCounts[0][0] = combinedRecord.mResultCounts[0][0] + mergedRecord.mResultCounts[0][0];
        combinedRecord.mResultCounts[0][1] = combinedRecord.mResultCounts[0][1] + mergedRecord.mResultCounts[0][1];
        combinedRecord.mResultCounts[1][0] = combinedRecord.mResultCounts[1][0] + mergedRecord.mResultCounts[1][0];
        combinedRecord.mResultCounts[1][1] = combinedRecord.mResultCounts[1][1] + mergedRecord.mResultCounts[1][1];
        combinedRecord.mResultCounts[2][0] = combinedRecord.mResultCounts[2][0] + mergedRecord.mResultCounts[2][0];
        combinedRecord.mResultCounts[2][1] = combinedRecord.mResultCounts[2][1] + mergedRecord.mResultCounts[2][1];
        MI_CpuCopy8(mergedRecord.mName, combinedRecord.mName, 0x14);
        combinedRecord.mYear = mergedRecord.mYear;
        combinedRecord.mMonth = mergedRecord.mMonth;
        combinedRecord.mDay = mergedRecord.mDay;
    }
    if (keptRecord.mNotYetBuddy == 0) {
        combinedRecord.mResultCounts[0][0] = combinedRecord.mResultCounts[0][0] + keptRecord.mResultCounts[0][0];
        combinedRecord.mResultCounts[0][1] = combinedRecord.mResultCounts[0][1] + keptRecord.mResultCounts[0][1];
        combinedRecord.mResultCounts[1][0] = combinedRecord.mResultCounts[1][0] + keptRecord.mResultCounts[1][0];
        combinedRecord.mResultCounts[1][1] = combinedRecord.mResultCounts[1][1] + keptRecord.mResultCounts[1][1];
        combinedRecord.mResultCounts[2][0] = combinedRecord.mResultCounts[2][0] + keptRecord.mResultCounts[2][0];
        combinedRecord.mResultCounts[2][1] = combinedRecord.mResultCounts[2][1] + mergedRecord.mResultCounts[2][1];
        MI_CpuCopy8(keptRecord.mName, combinedRecord.mName, 0x14);
        combinedRecord.mYear = keptRecord.mYear;
        combinedRecord.mMonth = keptRecord.mMonth;
        combinedRecord.mDay = keptRecord.mDay;
    }
    combinedRecord.mFilled = 1;
    combinedRecord.mNotYetBuddy = 0;
    combinedRecord.mHasEmblem = keptRecord.mHasEmblem;
    combinedRecord.mFlagged = keptRecord.mFlagged == 1 || mergedRecord.mFlagged == 1;
    SetBuddyRecord(keptIndex, &combinedRecord);
    MI_CpuFill8(&mergedRecord, 0, 0x24);
    mergedRecord.mFilled = 0;
    SetBuddyRecord(mergedIndex, &mergedRecord);
}

BOOL GetBuddyFriendKeyText(u8 recordIndex, void *textOut) {
    DWCAccFriendData *friendData;
    BOOL found;
    BOOL hasFriendKey;
    BuddyRecord buddyRecord;

    found = FALSE;
    GetBuddyRecord(recordIndex, &buddyRecord);
    friendData = &gBackupBuffers->mBuddyRecordBlock->mFriendData[recordIndex];
    if (buddyRecord.mFilled == 1 && buddyRecord.mNotYetBuddy == 1 && IsFriendDataTypeNonZero(friendData) != 0) {
        hasFriendKey = TRUE;
    } else {
        hasFriendKey = FALSE;
    }
    if (hasFriendKey != FALSE) {
        u64 friendKey = DWC_GetFriendKey(friendData);

        FormatFriendKey(friendKey, friendKey >> 32, (u32) textOut);
        found = TRUE;
    }
    return found;
}

s32 IsGrandPrixRecordFilled(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    GetGrandPrixRecord(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled == 0) {
        return 0;
    }
    return timeRecord.mFilled;
}

s32 GetGrandPrixRecordCharacterIndex(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    GetGrandPrixRecord(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return timeRecord.mCharacterIndex;
    }
    return -1;
}

s32 GetGrandPrixRecordKartIndex(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    GetGrandPrixRecord(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return timeRecord.mKartIndex;
    }
    return -1;
}

s32 GetGrandPrixRecordCupRank(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    GetGrandPrixRecord(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return timeRecord.mCupRank;
    }
    return 3;
}

s32 GetGrandPrixRecordTotalPoints(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    GetGrandPrixRecord(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return (s8) timeRecord.mTotalPoints;
    }
    return -1;
}

// The grade of a Grand Prix record, 0 to 7, or 9 when the record is empty.
s32 GetGrandPrixRecordGrade(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    GetGrandPrixRecord(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return timeRecord.mGrade;
    }
    return 9;
}

BOOL GetGrandPrixRecordTime(s32 cup, s32 engineClass, void *timeOut) {
    TimeRecord timeRecord;

    GetGrandPrixRecord(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled == 0) {
        return FALSE;
    }
    MI_CpuCopy8(&timeRecord, timeOut, 4);
    return TRUE;
}

// FALSE when the course has a saved ghost and at least one filled time record, TRUE otherwise.
BOOL IsCourseGhostRecordMissing(s32 courseId) {
    u8 recordIndex;
    BOOL noRecords;
    s32 cupCourseIndex;
    TimeRecord timeRecord;

    noRecords = TRUE;
    cupCourseIndex = FindCupCourseIndex(courseId);
    if (cupCourseIndex == -1) {
        return noRecords;
    }
    if (IsCourseGhostBitSet(cupCourseIndex) == 0) {
        return noRecords;
    }
    for (recordIndex = 0; recordIndex < 6; recordIndex++) {
        if (TryGetFilledTimeRecord(courseId, recordIndex, &timeRecord)) {
            noRecords = FALSE;
            break;
        }
    }
    return noRecords;
}

BOOL IsTimeRecordFilled(s32 courseId, s32 recordIndex) {
    TimeRecord timeRecord;

    if (GetCourseTimeRecord(courseId, recordIndex, &timeRecord) != 0 && timeRecord.mFilled != 0) {
        return TRUE;
    }
    return FALSE;
}

s32 GetTimeRecordCharacterIndex(s32 courseId, s32 recordIndex) {
    TimeRecord timeRecord;

    if (TryGetFilledTimeRecord(courseId, recordIndex, &timeRecord)) {
        return timeRecord.mCharacterIndex;
    }
    return -1;
}

s32 GetTimeRecordKartIndex(s32 courseId, s32 recordIndex) {
    TimeRecord timeRecord;

    if (TryGetFilledTimeRecord(courseId, recordIndex, &timeRecord)) {
        return timeRecord.mKartIndex;
    }
    return -1;
}

BOOL GetTimeRecordTime(s32 courseId, s32 recordIndex, void *timeOut) {
    TimeRecord timeRecord;
    TimeRecord *outRecord;

    if (!TryGetFilledTimeRecord(courseId, recordIndex, &timeRecord)) {
        return FALSE;
    }
    outRecord = timeOut;
    outRecord->mMinute = timeRecord.mMinute;
    outRecord->mSecond = timeRecord.mSecond;
    outRecord->mMillisecond = timeRecord.mMillisecond;
    return TRUE;
}

BOOL GetTimeRecordName(s32 courseId, s32 recordIndex, void *nameOut) {
    TimeRecord timeRecord;

    if (!TryGetFilledTimeRecord(courseId, recordIndex, &timeRecord)) {
        return FALSE;
    }
    MI_CpuCopy8(timeRecord.mName, nameOut, 0x14);
    return TRUE;
}

s32 IsCourseCupMessageFlagSet(s32 courseId) {
    return IsCupAlwaysOrSecretMessageFlagSet(FindCupIndexOfCourse(courseId));
}

void ClearCourseTimeRecords(s32 courseId) {
    u8 recordIndex;
    BOOL ghostBitCleared;
    u8 ghostCourseIndex;
    s32 cupCourseIndex;
    TimeRecord timeRecord;

    cupCourseIndex = FindCupCourseIndex(courseId);
    ghostBitCleared = FALSE;
    if (cupCourseIndex == -1) {
        return;
    }
    ghostCourseIndex = cupCourseIndex;
    if (IsCourseGhostBitSet(ghostCourseIndex) != 0) {
        ClearCourseGhostBit(ghostCourseIndex);
        ghostBitCleared = TRUE;
    }
    for (recordIndex = 0; recordIndex < 6; recordIndex++) {
        MI_CpuFill8(&timeRecord, 0, 0x20);
        SetCourseTimeRecord(courseId, recordIndex, &timeRecord);
    }
    if (ghostBitCleared != FALSE) {
        WriteCourseTimeRecordsAndFirstBlock();
    } else {
        WriteBackupCourseTimeRecords();
    }
}
