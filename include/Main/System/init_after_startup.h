#pragma once

#include "types.h"
#include "Main/Item/item_objects_and_race_progress.h"
#include "Main/Scene/scene_display_archive_work.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/System/input_slots.h"


void InitAfterStartup(void);

extern struct RaceProgress *gRaceProgress;
extern struct InputState *gInputState;
extern struct CourseMap *gCourseMap;
extern InputSlot gInputSlots[10];
