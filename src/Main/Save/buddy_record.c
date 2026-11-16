#include "Main/Save/buddy_record.h"
#include "Main/Race/demo_race.h"
#include "Main/Menu/second_menu_scene.h"
#include "Main/Save/course_time_records_and_first.h"
#include "Main/Save/backup_records_write.h"
#include "Main/Save/grand_prix_record_get.h"
#include "Main/Save/course_time_record.h"
#include "Main/Save/backup_bit_array.h"
#include "Main/Save/buddy_record_reset.h"
#include "Main/Save/buddy_records_write.h"
#include "Main/Save/buddy_record_time.h"
#include "friend_data_account_fields.h"
#include "cpu_copy_fill.h"
#include "00/Menu/wi_fi_vs_matching.h"
#include "00/Lib/DWC/friend_status.h"
#include "Main/Net/wifi_session.h"
#include "Main/Save/ghost_record_file.h"

static inline s32 TryGetFilledTimeRecord(s32 courseId, s32 recordIndex, TimeRecord *timeRecord) {
    BOOL isFilled;

    if (TimeTrialRecord_CopyFrom_from_thumb(courseId, recordIndex, timeRecord) != 0 && timeRecord->mFilled != 0) {
        isFilled = TRUE;
    } else {
        isFilled = FALSE;
    }
    return isFilled;
}

void CopyFriendCodesToSaveData(DWCAccFriendData *buddies) {
    Mem_CpuCopy8(buddies, g_SaveDataHolder->mBuddyRecordBlock->mFriendData,
                sizeof(g_SaveDataHolder->mBuddyRecordBlock->mFriendData));
}

void RefreshNotYetBuddyFlags(void) {
    BuddyRecord buddyRecord;
    u8 recordIndex;

    for (recordIndex = 0; recordIndex < 60; recordIndex++) {
        GlobalZ_GetOI(recordIndex, &buddyRecord);
        if (buddyRecord.mFilled == 1 && buddyRecord.mNotYetBuddy == 1 &&
            FriendCode_SomeFn_from_thumb(&g_SaveDataHolder->mBuddyRecordBlock->mFriendData[recordIndex]) != 0) {
            buddyRecord.mNotYetBuddy = 0;
            GlobalZ_SetOI(recordIndex, &buddyRecord);
        }
    }
}

BOOL IsBuddyRecordFilled(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GlobalZ_GetOI(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return TRUE;
    }
    return FALSE;
}

s32 IsBuddyRecordFlagged(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GlobalZ_GetOI(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mFlagged;
    }
    return 0;
}

s32 GetBuddyRecordVsWinCount(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GlobalZ_GetOI(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[0][0];
    }
    return -1;
}

s32 GetBuddyRecordVsLossCount(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GlobalZ_GetOI(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[0][1];
    }
    return -1;
}

s32 GetBuddyRecordBattleWinCount(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GlobalZ_GetOI(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[1][0];
    }
    return -1;
}

s32 GetBuddyRecordBattleLossCount(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GlobalZ_GetOI(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[1][1];
    }
    return -1;
}

s32 GetBuddyRecordWiFiRaceWinCount(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GlobalZ_GetOI(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[2][0];
    }
    return -1;
}

s32 GetBuddyRecordWiFiRaceLossCount(u8 recordIndex) {
    BuddyRecord buddyRecord;

    GlobalZ_GetOI(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        return buddyRecord.mResultCounts[2][1];
    }
    return -1;
}

BOOL GetBuddyRecordDate(u8 recordIndex, u8 *dateOut) {
    BuddyRecord buddyRecord;

    GlobalZ_GetOI(recordIndex, &buddyRecord);
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

    GlobalZ_GetOI(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled != 1) {
        return FALSE;
    }
    Mem_CpuCopy8(buddyRecord.mName, nameOut, sizeof(buddyRecord.mName));
    return TRUE;
}

BOOL SetBuddyRecordFlag(u8 recordIndex, s32 flag) {
    BuddyRecord buddyRecord;

    GlobalZ_GetOI(recordIndex, &buddyRecord);
    if (buddyRecord.mFilled == 1) {
        buddyRecord.mFlagged = flag != 0;
        GlobalZ_SetOI(recordIndex, &buddyRecord);
        return TRUE;
    }
    return FALSE;
}

s32 RemoveBuddyRecord(u8 recordIndex) {
    BuddyRecord buddyRecord;
    BOOL wasFilled;

    GlobalZ_GetOI(recordIndex, &buddyRecord);
    wasFilled = buddyRecord.mFilled == 1;
    Mem_CpuFill8(&buddyRecord, 0, sizeof(BuddyRecord));
    buddyRecord.mFilled = 0;
    GlobalZ_SetOI(recordIndex, &buddyRecord);
    if (g_GlobalB->mStateMachine.mState != 0) {
        DWC_DeleteBuddyFriendData(&g_SaveDataHolder->mBuddyRecordBlock->mFriendData[recordIndex]);
    } else {
        Mem_CpuFill8(&g_SaveDataHolder->mBuddyRecordBlock->mFriendData[recordIndex], 0, 0xc);
    }
    WriteFriendListSaveDataSection();
    return wasFilled;
}

void OI_JoinInSlot1FreeSlot2(u8 keptIndex, u8 mergedIndex) {
    BuddyRecord keptRecord;
    BuddyRecord mergedRecord;
    BuddyRecord combinedRecord;

    GlobalZ_GetOI(keptIndex, &keptRecord);
    GlobalZ_GetOI(mergedIndex, &mergedRecord);
    StructOI_Initialize_from_thumb(&combinedRecord);
    if (mergedRecord.mNotYetBuddy == 0) {
        combinedRecord.mResultCounts[0][0] = combinedRecord.mResultCounts[0][0] + mergedRecord.mResultCounts[0][0];
        combinedRecord.mResultCounts[0][1] = combinedRecord.mResultCounts[0][1] + mergedRecord.mResultCounts[0][1];
        combinedRecord.mResultCounts[1][0] = combinedRecord.mResultCounts[1][0] + mergedRecord.mResultCounts[1][0];
        combinedRecord.mResultCounts[1][1] = combinedRecord.mResultCounts[1][1] + mergedRecord.mResultCounts[1][1];
        combinedRecord.mResultCounts[2][0] = combinedRecord.mResultCounts[2][0] + mergedRecord.mResultCounts[2][0];
        combinedRecord.mResultCounts[2][1] = combinedRecord.mResultCounts[2][1] + mergedRecord.mResultCounts[2][1];
        Mem_CpuCopy8(mergedRecord.mName, combinedRecord.mName, sizeof(combinedRecord.mName));
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
        Mem_CpuCopy8(keptRecord.mName, combinedRecord.mName, sizeof(combinedRecord.mName));
        combinedRecord.mYear = keptRecord.mYear;
        combinedRecord.mMonth = keptRecord.mMonth;
        combinedRecord.mDay = keptRecord.mDay;
    }
    combinedRecord.mFilled = 1;
    combinedRecord.mNotYetBuddy = 0;
    combinedRecord.mHasEmblem = keptRecord.mHasEmblem;
    combinedRecord.mFlagged = keptRecord.mFlagged == 1 || mergedRecord.mFlagged == 1;
    GlobalZ_SetOI(keptIndex, &combinedRecord);
    Mem_CpuFill8(&mergedRecord, 0, sizeof(BuddyRecord));
    mergedRecord.mFilled = 0;
    GlobalZ_SetOI(mergedIndex, &mergedRecord);
}

BOOL GetBuddyFriendKeyText(u8 recordIndex, void *textOut) {
    DWCAccFriendData *friendData;
    BOOL found;
    BOOL hasFriendKey;
    BuddyRecord buddyRecord;

    found = FALSE;
    GlobalZ_GetOI(recordIndex, &buddyRecord);
    friendData = &g_SaveDataHolder->mBuddyRecordBlock->mFriendData[recordIndex];
    if (buddyRecord.mFilled == 1 && buddyRecord.mNotYetBuddy == 1 && FriendCode_HasNonzeroState_from_thumb(friendData) != 0) {
        hasFriendKey = TRUE;
    } else {
        hasFriendKey = FALSE;
    }
    if (hasFriendKey != FALSE) {
        u64 friendKey = FriendCode_GetFriendCodePacked_0_from_thumb(friendData);

        PrintfUll_from_thumb(friendKey, friendKey >> 32, (u32) textOut);
        found = TRUE;
    }
    return found;
}

s32 CupHasRecord(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    CopyCupEntryTo_from_thumb(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled == 0) {
        return 0;
    }
    return timeRecord.mFilled;
}

s32 GetGrandPrixRecordCharacterIndex(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    CopyCupEntryTo_from_thumb(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return timeRecord.mCharacterIndex;
    }
    return -1;
}

s32 GetGrandPrixRecordKartIndex(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    CopyCupEntryTo_from_thumb(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return timeRecord.mKartIndex;
    }
    return -1;
}

s32 CupGetResult(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    CopyCupEntryTo_from_thumb(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return timeRecord.mCupRank;
    }
    return 3;
}

s32 GetGrandPrixRecordTotalPoints(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    CopyCupEntryTo_from_thumb(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return (s8) timeRecord.mTotalPoints;
    }
    return -1;
}

// The grade of a Grand Prix record, 0 to 7, or 9 when the record is empty.
s32 GetCupEntryRank(s32 cup, s32 engineClass) {
    TimeRecord timeRecord;

    CopyCupEntryTo_from_thumb(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled != 0) {
        return timeRecord.mGrade;
    }
    return 9;
}

BOOL GetGrandPrixRecordTime(s32 cup, s32 engineClass, void *timeOut) {
    TimeRecord timeRecord;

    CopyCupEntryTo_from_thumb(cup, engineClass, &timeRecord);
    if (timeRecord.mFilled == 0) {
        return FALSE;
    }
    Mem_CpuCopy8(&timeRecord, timeOut, 4);
    return TRUE;
}

// FALSE when the course has a saved ghost and at least one filled time record, TRUE otherwise.
BOOL CourseTimeTrialRecordsEmpty(s32 courseId) {
    u8 recordIndex;
    BOOL noRecords;
    s32 cupCourseIndex;
    TimeRecord timeRecord;

    noRecords = TRUE;
    cupCourseIndex = GetCourseIdFromInternalId(courseId);
    if (cupCourseIndex == -1) {
        return noRecords;
    }
    if (MaybeHasPersonalGhostForCourse_from_thumb(cupCourseIndex) == 0) {
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

    if (TimeTrialRecord_CopyFrom_from_thumb(courseId, recordIndex, &timeRecord) != 0 && timeRecord.mFilled != 0) {
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
    Mem_CpuCopy8(timeRecord.mName, nameOut, sizeof(timeRecord.mName));
    return TRUE;
}

s32 IsCourseCupMessageFlagSet(s32 courseId) {
    return IsCupAlwaysOrSecretMessageFlagSet(GetCupForCourse(courseId));
}

void ClearCourseTimeRecords(s32 courseId) {
    u8 recordIndex;
    BOOL ghostBitCleared;
    u8 ghostCourseIndex;
    s32 cupCourseIndex;
    TimeRecord timeRecord;

    cupCourseIndex = GetCourseIdFromInternalId(courseId);
    ghostBitCleared = FALSE;
    if (cupCourseIndex == -1) {
        return;
    }
    ghostCourseIndex = cupCourseIndex;
    if (MaybeHasPersonalGhostForCourse_from_thumb(ghostCourseIndex) != 0) {
        ClearCourseGhostBit(ghostCourseIndex);
        ghostBitCleared = TRUE;
    }
    for (recordIndex = 0; recordIndex < 6; recordIndex++) {
        Mem_CpuFill8(&timeRecord, 0, sizeof(TimeRecord));
        TimeTrialCopyToSaveData_from_thumb(courseId, recordIndex, &timeRecord);
    }
    if (ghostBitCleared != FALSE) {
        WriteTimeTrialsSaveDataSectionAndHeader_from_thumb();
    } else {
        WriteTimeTrialsSaveDataSection_from_thumb();
    }
}
