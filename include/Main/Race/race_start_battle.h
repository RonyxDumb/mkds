#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

// The two values DrawRaceStartBattle passes to GetRaceStartBattleMNcerEntry.
enum {
    VALUE_0 = 0,
    VALUE_1 = 1,
};

void DrawRaceStartBattle(RaceHudOamBuffer *oamBuffer);
u16 *CupPictureMB_GetMultiBootParam(void);
u32 CupPictureMB_IsMultiBootChild(void);
u32 CupPictureMB_IsMultiBootChildWrapper(void);

void UpdateRaceStartBattleNop(void);

void ClearRaceStartBattlePointer(void);

void InitRaceStartBattle(void);

extern void *gRaceStartBattle;
