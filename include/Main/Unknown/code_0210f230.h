#pragma once

#include "types.h"

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
    /* 0c */ u8 mLowVolume;
    /* 0d */ u8 mMidVolume;
    /* 0e */ u8 mHighVolume;
    /* 0f */ u8 mUnk_0f;
} CourseSoundSlot;

// Object data_0217d1cc: sixteen bytes; UpdateCourseSound and StartCourseSoundAtVolume read one byte of the row that the
// first word of the gCourseSoundSlots element selects.
typedef struct Unk0217d1cc {
    /* 00 */ u8 mVolumes[0x10];
} Unk0217d1cc;

extern CourseSoundSlot gCourseSoundSlots[];
extern Unk0217d1cc data_0217d1cc[];
extern u32 gCourseSoundTableIndex;
extern CourseSoundTableRow gCourseSoundTable[5];

void SelectCourseSoundTable(u32 courseId);
void ApplyCourseSoundTableEntry(s32 entryIndex);
BOOL StartCourseSoundAtVolume(s32 slotIndex, u32 soundId);
BOOL UpdateCourseSound(u32 slotIndex, u32 soundId);
