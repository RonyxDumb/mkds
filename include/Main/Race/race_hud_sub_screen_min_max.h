#pragma once

#include "types.h"
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
#include "Main/Race/race_hud_sub_screen_projection.h" // UnkPair020b502c
#include "Main/Save/course_time_record.h" // TimeRecord

void GetRaceHudSubScreenScrollLimits(UnkPair020b502c *outFirst, UnkPair020b502c *outSecond);
void GetRaceHudSubScreenCourseMinMax(UnkPair020b502c *outFirst, UnkPair020b502c *outSecond);
void SetFixed12MinMaxFromWhole(UnkPair020b502c *outFirst, UnkPair020b502c *outSecond, s32 firstX, s32 firstZ,
                               s16 secondX, s16 secondZ);
void GetRaceHudSubScreenState0MinMax(UnkPair020b502c *outFirst, UnkPair020b502c *outSecond);
void ComputeRaceHudSubScreenState0MinMax(UnkPair020b502c *outFirst, UnkPair020b502c *outSecond, s32 firstX, s32 firstZ,
                                         s16 secondX, s16 secondZ);
void CopyPlayerOrTimeRecordName(u32 rowIndex, u16 *nameOut, u32 copyFullLength);
