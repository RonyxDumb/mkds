#pragma once

#include "types.h"
#include "Main/Race/data_020f36d8.h"
#include "Main/Menu/data_02175000.h"
#include "Main/Race/race_hud_sub_screen_projection.h"
#include "Main/Menu/data_02175628.h"


void InitAfterStartup(void);

extern struct RaceProgress *gRaceProgress;
extern struct InputState *gInputState;
extern struct CourseMap *gCourseMap;
extern InputSlot gInputSlots[10];
