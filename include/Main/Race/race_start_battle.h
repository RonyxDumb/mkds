#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

// The cells DrawRaceStartBattle picks by BattleKind for GetRaceStartBattleMNcerEntry; its second picture uses the cell
// 2.
enum {
    RACE_START_BATTLE_BALLOON_CELL = 0,
    RACE_START_BATTLE_OTHER_CELL = 1,
};

void DrawRaceStartBattle(RaceHudOamBuffer *oamBuffer);
u16 *CupPictureMB_GetMultiBootParam(void);
u32 CupPictureMB_IsMultiBootChild(void);
u32 CupPictureMB_IsMultiBootChildWrapper(void);

void UpdateRaceStartBattleNop(void);

void ClearRaceStartBattlePointer(void);

void InitRaceStartBattle(void);

extern void *gRaceStartBattle;
