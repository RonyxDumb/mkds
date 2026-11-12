#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

#include "01/code_02188950.h"
#include "Main/Race/code_020b1dbc.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "code_02012b30.h"
#include "tp.h"
#include "Main/Race/followed_kart_or.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/code_0207a880.h"
#include "Main/Race/race_hud_sub_screen_projection.h"

void StopMapObjectState(MissionRunMapObject *mapObject);
void ClearAndRunCallback(MissionRunMapObject *mapObject, void (**callbackSlot)());
BOOL IsDirectionToPointWithinAngle(MissionRunMapObject *mapObject, s32 angle, Vec3 *point, s32 halfAngle);
BOOL IsWithinXzDistanceOfPoint(MissionRunMapObject *mapObject, Vec3 *point, s32 radius);
void DrawRaceHudSubScreenKingTeresaCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenKingTeresaCells(void);
void ClearRaceHudSubScreenKingTeresaCells(void);
BOOL CreateRaceHudSubScreenKingTeresaCells(void);
void DrawRaceHudSubScreenKingIceDonketuCells(RaceHudOamBuffer *oamBuffer);
void UpdateRaceHudSubScreenKingIceDonketuCells(void);
void ClearRaceHudSubScreenKingIceDonketuCells(void);
s32 CreateRaceHudSubScreenKingIceDonketuCells(void);
