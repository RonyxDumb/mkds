#pragma once

#include "types.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/System/input_slots.h"


void InitializeGeneralObjects(void);

extern struct RaceProgress *g_GlobalMV;
extern struct InputState *g_Global5624;
extern struct CourseMap *g_GlobalPE;
extern InputSlot g_GlobalCYT[10];
