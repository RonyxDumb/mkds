#pragma once

#include "types.h"

typedef struct PackedGrandPrixRecord PackedGrandPrixRecord;
typedef struct PackedCourseTimeRecord PackedCourseTimeRecord;

// A saved record: mMillisecond, mMinute, mSecond, mName, mCharacterIndex and mKartIndex; the Grand Prix kind also has
// mCupRank, mTotalPoints and mGrade.
typedef struct TimeRecord {
    /* 00 */ u16 mMillisecond;
    /* 02 */ u8 mMinute;
    /* 03 */ u8 mSecond;
    /* 04 */ u16 mName[10];
    /* 18 */ u8 mFilled;
    /* 19 */ u8 mCharacterIndex;
    /* 1a */ u8 mKartIndex;
    /* 1b */ u8 mUnk_1b;
    /* 1c */ u8 mCupRank;
    /* 1d */ u8 mTotalPoints;
    /* 1e */ u8 mGrade;
    /* 1f */ u8 mUnk_1f;
} TimeRecord;
// Slot of a course's time records that holds the best lap; slots 0 to 4 are the ranked race times.
#define TIME_RECORD_BEST_LAP 5

void PackGrandPrixRecord(PackedGrandPrixRecord *packedGrandPrixRecord, TimeRecord *timeRecord);
BOOL GetCourseTimeRecord(s32 courseId, s32 recordIndex, TimeRecord *timeRecord);
void UnpackCourseTimeRecord(PackedCourseTimeRecord *packedCourseTimeRecord, TimeRecord *timeRecord);

typedef struct TimeRecord TimeRecord;

void SetCourseTimeRecord(u32 courseId, int recordIndex, TimeRecord *timeRecord);

void PackCourseTimeRecord(PackedCourseTimeRecord *packedCourseTimeRecord, TimeRecord *timeRecord);
