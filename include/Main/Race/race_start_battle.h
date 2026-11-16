#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

// The two values DrawRaceStartBattle passes to GetB3C4_Cell_RaceStartBattleM.
enum {
    RACE_START_BATTLE_BALLOON_CELL = 0,
    RACE_START_BATTLE_OTHER_CELL = 1,
};

void DrawRaceStartBattle(RaceHudOamBuffer *oamBuffer);
u16 *GetBootIndicatorPointer_1(void);
u32 IsDwc_1(void);
u32 j_IsDwc_1(void);

void nullsub_10(void);

void ClearRaceStartBattlePointer(void);

void SomeAlloc2(void);

extern void *gRaceStartBattle;
