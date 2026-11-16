#pragma once

#include "types.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020f36d8.h"

// Writes mNextHeader.field5C; shuffles the respawn slots in mode 2.
void rstat_init2(void);
void rstat_initDriverStatus(RaceProgressKart *raceProgressKart, s32 kartIndex);
s16 rstat_calculateSkillRankPoints(s32 kartIndex);
void rstat_calculateSkillRankPointsGp(RaceProgressScoreTerms *scoreTerms, s32 kartIndex);
BOOL rstat_calcUncontrollableRaceDisplayMode(void);
s64 rstat_getProgressByTrigPos(const UnkPair020b502c *first, const UnkPair020b502c *second);
s32 rstat_rotCompare(const UnkPair020b502c *first, const UnkPair020b502c *second);
PointLink *mdat_getNextMgEnemyPointForWarpPipe(u32 key);
