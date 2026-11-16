#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

// The two values r2d_renderBattleIntro passes to r2d_getRaceStartBattleMCell.
enum {
    VALUE_0 = 0,
    VALUE_1 = 1,
};

void r2d_renderBattleIntro(RaceHudOamBuffer *oamBuffer);
u16 *cpic_MB_GetMultiBootParam(void);
u32 cpic_MB_IsMultiBootChild(void);
u32 cpic_MB_IsMultiBootChild_2(void);
