#pragma once

#include "types.h"

typedef struct BuddyRecord BuddyRecord;

typedef struct TimeRecord TimeRecord;

// The kart appear file: a header and the rows of values that tell which karts a character may use.
typedef struct KartAppearFile {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u8 mValues[1][13];
} KartAppearFile;

// The loaded kart appear file, used to test which karts a character may use.
typedef struct KartAppear {
    /* 00 */ KartAppearFile *mFileData;
} KartAppear;

extern const u8 g_TimeTrialBase32Table[33];
extern u32 g_dec_1000000;

static inline u8 GetTimeRecordChar(u8 charIndex) {
    return g_TimeTrialBase32Table[charIndex];
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

// MissionRecord values that ComputeMissionInternalScore gives for a cup score of 70 or more, 90 or more and 100 or more
// (cup_records.c:379-387); the values 5 to 7 are the top tiers.
#define MISSION_RECORD_VALUE_FIRST_HIGH_TIER 5
#define MISSION_RECORD_VALUE_SECOND_HIGH_TIER 6
#define MISSION_RECORD_VALUE_TOP_TIER 7

u32 GlobalZ_GetOI(u32 recordIndex, BuddyRecord *buddyRecordOut);
void GlobalZ_SetOI(u32 recordIndex, BuddyRecord *buddyRecord);
void SetRaceResultRecords(void);
void AddWiFiRaceBuddyRecordResults(void);
void AddShineBattleBuddyRecordResults(void);
void AddBattleBuddyRecordResults(void);
void AddVSBuddyRecordResults(void);
void AddBuddyRecordResult(u32 entryIndex, s32 *date, u32 matchKind, u32 resultKind);
s32 CheckSecretFlag(s32 bitIndex);
s32 IsBitSetInAllParticipants(s32 bitIndex);
BOOL IsKartAppearWithinParticipantLimit(KartAppear *kartAppear, u32 characterIndex, u32 kartIndex);
BOOL IsKartAppearWithinLimit(KartAppear *kartAppear, u32 characterIndex, u32 kartIndex);
BOOL IsMissionStageBeaten(s32 row, s32 column, s32 *out);
BOOL GenerateTimeTrialCode(s32 courseId, void *charsOut);
BOOL GenerateTimeTrialCodeImpl(u8 *charsOut, TimeRecord *timeRecord, s32 courseId);
