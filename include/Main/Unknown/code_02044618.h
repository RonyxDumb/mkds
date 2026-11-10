#pragma once

#include "types.h"

// The 0x1e8 bytes at the start of the object behind gRaceSetup, taken from 0x1e8.
typedef struct RaceSetupBlock {
    /* 000 */ u32 mUnk_000[0x7a];
} RaceSetupBlock;

u16 GetLapCount(void);
void ResetTimeAttackNextEntries(void);
void SetNextRaceByMode(void);
void SetCurrentRaceFromNext(void);
BOOL SetNextEntryFromSecondSlotGhost(s32 courseId, s32 entryIndex);
BOOL SetNextEntryFromFirstSlotGhost(s32 courseId, s32 entryIndex);
BOOL SetNextEntryFromCourseGhost(s32 courseId, s32 entryIndex);
void RefreshListedCpuEntryIndices(void);
void SetCurrentEntryPlayer(s32 entryIndex);
void ResetRaceSetup(void);
