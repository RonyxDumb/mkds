#pragma once

#include "types.h"

// One entry of the table returned by GetCourseMapGroupEntry.
typedef struct CourseMapGroupEntry {
    /* 00 */ Vec3 mPos;
    /* 0c */ u8 mEntryIndex;
    /* 0d */ u8 mFlagBitOn;
    /* 0e */ s16 mValue;
    /* 10 */ s16 mExtraValue;
    /* 12 */ s16 mCullDotLimit;
} CourseMapGroupEntry;

CourseMapGroupEntry *GetCourseMapGroupEntry(u16 groupIndex, u16 entryIndex);
