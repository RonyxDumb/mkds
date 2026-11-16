#pragma once

#include "types.h"

typedef struct RaceHudOamBuffer RaceHudOamBuffer;

#include "01/MapObjects/mission_run_map_object.h"
#include "Main/Race/race_hud_sub_screen_frames.h"
#include "Main/Kart/point_link_cursor.h"
#include "Main/Race/race_hud_sub_screen_course_id.h"
#include "model_material_set.h"
#include "touch_panel_sampling.h"
#include "Main/Race/graphic_file_loaders_and_matrix2x2.h"
#include "Main/Race/race_hud_sub_screen_min_max.h"
#include "Main/Kart/kart_heading_item_effect.h"
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
