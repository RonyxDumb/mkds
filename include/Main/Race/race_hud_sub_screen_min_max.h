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
#include "Main/Race/race_hud_sub_screen_projection.h" // IntPair
#include "Main/Save/course_time_record.h" // TimeRecord

void GetRaceHudSubScreenScrollLimits(IntPair *outFirst, IntPair *outSecond);
void GetRaceHudSubScreenCourseMinMax(IntPair *outFirst, IntPair *outSecond);
void SetFixed12MinMaxFromWhole(IntPair *outFirst, IntPair *outSecond, s32 firstX, s32 firstZ,
                               s16 secondX, s16 secondZ);
void GetRaceHudSubScreenKartIconsMinMax(IntPair *outFirst, IntPair *outSecond);
void ComputeRaceHudSubScreenKartIconsMinMax(IntPair *outFirst, IntPair *outSecond, s32 firstX, s32 firstZ, s16 secondX,
                                            s16 secondZ);
void FormatTimeTrialRecordRacerNameString(u32 rowIndex, u16 *nameOut, u32 copyFullLength);
