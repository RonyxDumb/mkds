#pragma once

#include "types.h"

typedef struct BuddyRecord BuddyRecord;

typedef struct TimeRecord TimeRecord;

// The word at 0 points to rows of 13 bytes from 6.
typedef struct KartAppearFile {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u8 mValues[1][13];
} KartAppearFile;

typedef struct KartAppear {
    /* 00 */ KartAppearFile *mFileData;
} KartAppear;

extern const u8 gTimeRecordCharTable[33];
extern u32 gResultTotalMax;

static inline u8 GetTimeRecordChar(u8 charIndex) {
    return gTimeRecordCharTable[charIndex];
}

// Third argument of AddBuddyRecordResult: the row of BuddyRecord.mResultCounts the result goes into.
#define BUDDY_RECORD_MATCH_VS 0
#define BUDDY_RECORD_MATCH_BATTLE 1
#define BUDDY_RECORD_MATCH_WIFI_RACE 2
// Courses at the start of a Wi-Fi race series (RaceSetup.mCourseNumber 1 to this) that add no buddy record.
#define WIFI_BUDDY_RECORD_SKIPPED_COURSE_COUNT 3
// The latest date the oldest-record search can see, as year, month and day.
#define BUDDY_RECORD_LATEST_YEAR 100
#define BUDDY_RECORD_LATEST_MONTH 12
#define BUDDY_RECORD_LATEST_DAY 31

// MissionRecord values that ComputeMissionRecordValue gives for a cup score of 70 or more, 90 or more and 100 or more
// (cup_records.c:379-387); the values 5 to 7 are the top tiers.
#define MISSION_RECORD_VALUE_FIRST_HIGH_TIER 5
#define MISSION_RECORD_VALUE_SECOND_HIGH_TIER 6
#define MISSION_RECORD_VALUE_TOP_TIER 7

u32 GetBuddyRecord(u32 recordIndex, BuddyRecord *buddyRecordOut);
void SetBuddyRecord(u32 recordIndex, BuddyRecord *buddyRecord);
void SetRaceResultRecords(void);
void AddWiFiRaceBuddyRecordResults(void);
void AddShineBattleBuddyRecordResults(void);
void AddBattleBuddyRecordResults(void);
void AddVSBuddyRecordResults(void);
void AddBuddyRecordResult(u32 entryIndex, s32 *date, u32 matchKind, u32 resultKind);
s32 IsBitSetInAnyParticipant(s32 bitIndex);
s32 IsBitSetInAllParticipants(s32 bitIndex);
BOOL IsKartAppearWithinParticipantLimit(KartAppear *kartAppear, u32 characterIndex, u32 kartIndex);
BOOL IsKartAppearWithinLimit(KartAppear *kartAppear, u32 characterIndex, u32 kartIndex);
BOOL GetMissionRecordValue(s32 row, s32 column, s32 *out);
BOOL FormatFirstCourseTimeRecord(s32 courseId, void *charsOut);
BOOL FormatTimeRecordChars(u8 *charsOut, TimeRecord *timeRecord, s32 courseId);
