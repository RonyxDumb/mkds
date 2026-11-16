#pragma once

#include "types.h"
#include "Main/Save/course_time_record.h"

void StructE8_SomeFnHandle7(void);

void StructE8_SomeFnHandle6(void);

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

// The time-attack record handling of a race: compares the run with the saved records and shows the new-record page.
typedef struct RaceNewRecordTa {
    /* 00 */ void (*mUpdate)(void);
    /* 04 */ s32 mUpdateFrames;
    /* 08 */ s32 mFinishTimeIsRecord;
    /* 0c */ s32 mFinishRecordIndex;
    /* 10 */ s32 mBestLapIsRecord;
    /* 14 */ u16 mBestLapNumber;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ s32 mSaving;
    // The course's six time records, copied from the save by CreateGlobalE8 (TimeTrialRecord_CopyFrom_from_thumb): slots 0..4 are
    // the ranked list (an insert shifts them down and writes through TimeTrialCopyToSaveData_from_thumb), slot 5 is a further record
    // shown in a sixth row: the best lap time.
    /* 1c */ TimeRecord mRecords[6];
    /* dc */ s32 mRunning;
    // X of the whole page: -0x100 at allocation, eased to 0 over 0x14 frames by StructE8_SomeFnHandle2, added to every
    // sprite and row x in the draw.
    /* e0 */ s32 mOffsetX;
    /* e4 */ s32 mCycleFrames;
} RaceNewRecordTa;

BOOL IsSavingTimeTrialRecord(void);
BOOL IsRaceNewRecordTaRunning(void);
void CreateGlobalE8(void);
void ResetGlobalE8(void);
void InvokeE8Handler(void);
void StructRA_SomeFn_6(RaceHudOamBuffer *oamBuffer, s32 baseX, s32 baseY, TimeRecord *record);
void StructRA_SomeFn_5(RaceHudOamBuffer *oamBuffer, s32 index, s32 baseX, s32 baseY);
void StructRA_SomeFn_4(RaceHudOamBuffer *oamBuffer);
BOOL CheckHandleSaveTimeTrialRecord2(s32 store);
BOOL CheckHandleSaveTimeTrialRecord_LeastLap(s32 store);
void StructE8_SomeFnHandle(void);
void StructE8_SomeFnHandle4(void);
void StructE8_SomeFnHandle3(void);
void StructE8_SomeFnHandle5(void);
void StructE8_SomeFnHandle2(void);

unsigned int GetLeastTimeLapId(void);

extern struct RaceNewRecordTa *g_GlobalE8;

// Frames of the new record cycle, and the digit value that shows no digit.
#define RACE_NEW_RECORD_TA_CYCLE_FRAMES 0x18
#define RACE_NEW_RECORD_TA_BLANK_DIGIT 0xb
