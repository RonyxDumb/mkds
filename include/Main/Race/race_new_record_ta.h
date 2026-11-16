#pragma once

#include "types.h"
#include "Main/Save/course_time_record.h"

void FinishRaceNewRecordTa(void);

void HoldRaceNewRecordTa(void);

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

// The time-attack record handling of a race: compares the run with the saved records, stores new records and the ghost,
// and shows the new-record page.
typedef struct RaceNewRecordTa {
    /* 00 */ void (*mUpdate)(void);
    /* 04 */ s32 mUpdateFrames;
    /* 08 */ s32 mFinishTimeIsRecord;
    /* 0c */ s32 mFinishRecordIndex;
    /* 10 */ s32 mBestLapIsRecord;
    /* 14 */ u16 mBestLapNumber;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ s32 mSaving;
    // The course's six time records, copied from the save by InitRaceNewRecordTa (GetCourseTimeRecord): slots 0..4 are
    // the ranked list (an insert shifts them down and writes through SetCourseTimeRecord), slot 5 is a further record
    // shown in a sixth row: the best lap time.
    /* 1c */ TimeRecord mRecords[6];
    /* dc */ s32 mRunning;
    // X offset of everything DrawRaceNewRecordTa draws: -0x100 at allocation, eased to 0 over 0x14 frames by
    // SlideInRaceNewRecordTa, added to the x of the header, each row and its cells (the sixth row gets one more).
    /* e0 */ s32 mOffsetX;
    /* e4 */ s32 mCycleFrames;
} RaceNewRecordTa;

BOOL IsRaceNewRecordTaSaving(void);
BOOL IsRaceNewRecordTaRunning(void);
void InitRaceNewRecordTa(void);
void ClearRaceNewRecordTaPointer(void);
void UpdateRaceNewRecordTa(void);
void DrawRaceNewRecordTaTime(RaceHudOamBuffer *oamBuffer, s32 baseX, s32 baseY, TimeRecord *record);
void DrawRaceNewRecordTaRow(RaceHudOamBuffer *oamBuffer, s32 index, s32 baseX, s32 baseY);
void DrawRaceNewRecordTa(RaceHudOamBuffer *oamBuffer);
BOOL TryStoreRaceNewRecordTaFinishTime(s32 store);
BOOL TryStoreRaceNewRecordTaBestLap(s32 store);
void StartRaceNewRecordTa(void);
void StoreRaceNewRecordTaGhost(void);
void AdvanceRaceNewRecordTaAfterSave(void);
void ShowRaceNewRecordTaSubScreen(void);
void SlideInRaceNewRecordTa(void);

unsigned int GetRaceNewRecordTaBestLapNumber(void);

extern struct RaceNewRecordTa *gRaceNewRecordTa;

// Frames of the new record cycle, and the digit value drawn for every digit of a record whose mFilled is 0.
#define RACE_NEW_RECORD_TA_CYCLE_FRAMES 0x18
#define RACE_NEW_RECORD_TA_BLANK_DIGIT 0xb
