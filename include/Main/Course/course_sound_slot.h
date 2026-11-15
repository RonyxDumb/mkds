#pragma once

#include "types.h"

typedef struct CourseSoundSlot CourseSoundSlot;

void InitCourseSoundSlot(CourseSoundSlot *slot, unsigned int volumeHandle, unsigned int firstTableIndex);

// Object gCourseSoundTable: five 16-byte rows of eight halfwords; ApplyCourseSoundTableEntry reads one halfword of a
// row and SelectCourseSoundTable walks a row.
typedef struct CourseSoundTableRow {
    /* 00 */ u16 mEntries[8];
} CourseSoundTableRow;

// Object gCourseSoundSlots: a word at 0, a word at 4 and eight bytes at 8; UpdateCourseSound, StartCourseSoundAtVolume,
// ApplyCourseSoundTableEntry and SelectCourseSoundTable read the word at 0, and SelectCourseSoundTable writes the two
// words.
typedef struct CourseSoundSlot {
    /* 00 */ u32 mVolumeHandle;
    /* 04 */ u32 mPreviousVolumeHandle;
    /* 08 */ u32 mFirstTableIndex;
    /* 0c */ union {
        u8 mVolumes[4];
        struct {
            u8 mLowVolume;
            u8 mMidVolume;
            u8 mHighVolume;
            u8 mUnk_0f;
        };
    };
} CourseSoundSlot;

extern CourseSoundSlot gCourseSoundSlots[2];
extern u32 gCourseSoundTableIndex;
extern CourseSoundTableRow gCourseSoundTable[5];

void SelectCourseSoundTable(u32 courseId);
void ApplyCourseSoundTableEntry(s32 entryIndex);
BOOL StartCourseSoundAtVolume(s32 slotIndex, u32 soundId);
BOOL UpdateCourseSound(u32 slotIndex, u32 soundId);
