#pragma once

#include "types.h"

typedef struct CourseSoundSlot CourseSoundSlot;

void InitCourseSoundSlot(CourseSoundSlot *slot, unsigned int volumeHandle, unsigned int firstTableIndex);

// Rows of gCourseSoundTable, named after the course that selects them (SelectCourseSoundTable), and the low and mid
// volumes InitCourseSoundSlot gives a slot.
#define COURSE_SOUND_TABLE_RAINBOW 0
#define COURSE_SOUND_TABLE_TOWN 1
#define COURSE_SOUND_TABLE_KOOPA 2
#define COURSE_SOUND_TABLE_PINBALL 3
#define COURSE_SOUND_TABLE_STADIUM 4
#define COURSE_SOUND_LOW_VOLUME 0x28
#define COURSE_SOUND_MID_VOLUME 0x50

// Object gCourseSoundTable: five 16-byte rows of eight halfwords; ApplyCourseSoundTableEntry reads one halfword of a
// row and SelectCourseSoundTable walks a row.
typedef struct CourseSoundTableRow {
    /* 00 */ u16 mEntries[8];
} CourseSoundTableRow;

// A course sound slot: its volume handle and previous volume handle, first table index and the low, mid and high
// volumes (mVolumes).
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
