#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h" // RaceHudSubScreenBgAffine

unsigned int GetRaceHudKartRemoved(unsigned int kartIndex);
BOOL IsRaceHudGoalMEnabled(void);
BOOL IsRaceHudGoalMUploaded(void);
RaceHudSubScreenBgAffine *GetRaceHudSubScreenBgAffine(void);
s32 GetRaceHudSubScreenCourseScale(void);
