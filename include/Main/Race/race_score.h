#pragma once

#include "types.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Race/data_020f36d8.h"

// Writes mNextHeader.mSeed; shuffles the respawn slots in mode 2.
void InitRaceProgress(void);
void InitRaceProgressKart(RaceProgressKart *raceProgressKart, s32 kartIndex);
s16 ComputeRaceProgressKartScore(s32 kartIndex);
void ComputeGrandPrixScoreTerms(RaceProgressScoreTerms *scoreTerms, s32 kartIndex);
BOOL IsEntryRaceEnded(void);
s64 ComputeDotOfPairsRoundedS64(const UnkPair020b502c *first, const UnkPair020b502c *second);
s32 ComputeDotOfPairsRounded(const UnkPair020b502c *first, const UnkPair020b502c *second);
PointLink *GetKeyedPlacementBattlePointLink(u32 key);
