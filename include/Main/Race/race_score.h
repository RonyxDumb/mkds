#pragma once

#include "types.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Item/item_objects_and_race_progress.h"

// Sets up gRaceProgress (clock, counts, time limit, karts, random generators, lap progress), writes
// RaceSetup.mNextHeader.mSeed; in MODE_BATTLE also shuffles the respawn slots and picks mStartPlacementOffset.
void InitRaceProgress(void);
void InitRaceProgressKart(RaceProgressKart *raceProgressKart, s32 kartIndex);
s16 ComputeRaceProgressKartScore(s32 kartIndex);
void ComputeGrandPrixScoreTerms(RaceProgressScoreTerms *scoreTerms, s32 kartIndex);
BOOL IsEntryRaceEnded(void);
s64 ComputeDotOfPairsRoundedS64(const IntPair *first, const IntPair *second);
s32 ComputeDotOfPairsRounded(const IntPair *first, const IntPair *second);
BattlePointLink *GetKeyedPlacementBattlePointLink(u32 key);
