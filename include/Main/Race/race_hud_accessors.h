#pragma once

#include "types.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
#include "Main/Race/race_hud_sub_screen_projection.h" // RaceHudSubScreenBgAffine

unsigned int GetRaceHudKartRemoved(unsigned int kartIndex);
BOOL IsRaceHudGoalMEnabled(void);
BOOL IsRaceHudGoalMUploaded(void);
RaceHudSubScreenBgAffine *GetRaceHudSubScreenBgAffine(void);
s32 GetRaceHudSubScreenCourseScale(void);
