#pragma once

#include "types.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Item/item_objects_and_race_progress.h"

// Writes mNextHeader.mSeed; shuffles the respawn slots in mode 2.
void InitRaceProgress(void);
void InitRaceProgressKart(RaceProgressKart *raceProgressKart, s32 kartIndex);
s16 ComputeRaceProgressKartScore(s32 kartIndex);
void ComputeGrandPrixScoreTerms(RaceProgressScoreTerms *scoreTerms, s32 kartIndex);
BOOL IsEntryRaceEnded(void);
s64 ComputeDotOfPairsRoundedS64(const IntPair *first, const IntPair *second);
s32 ComputeDotOfPairsRounded(const IntPair *first, const IntPair *second);
PointLink *GetKeyedPlacementBattlePointLink(u32 key);
