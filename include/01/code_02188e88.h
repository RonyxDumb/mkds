#pragma once

#include "types.h"
#include "01/code_02188950.h"
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
#include "Main/Race/race_hud_sub_screen_projection.h"

void StopMapObjectState(MissionRunMapObject *mapObject);
void ClearAndRunCallback(MissionRunMapObject *mapObject, void (**callbackSlot)());
BOOL IsDirectionToPointWithinAngle(MissionRunMapObject *mapObject, s32 angle, Vec3 *point, s32 halfAngle);
BOOL IsWithinXzDistanceOfPoint(MissionRunMapObject *mapObject, Vec3 *point, s32 radius);
void DrawRaceHudSubScreenKingTeresaCells(void *oamBuffer);
void UpdateRaceHudSubScreenKingTeresaCells(void);
void ClearRaceHudSubScreenKingTeresaCells(void);
BOOL CreateRaceHudSubScreenKingTeresaCells(void);
void DrawRaceHudSubScreenKingIceDonketuCells(void *oamBuffer);
void UpdateRaceHudSubScreenKingIceDonketuCells(void);
void ClearRaceHudSubScreenKingIceDonketuCells(void);
s32 CreateRaceHudSubScreenKingIceDonketuCells(void);
