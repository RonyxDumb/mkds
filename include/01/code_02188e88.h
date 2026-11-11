#pragma once

#include "types.h"
#include "01/code_02188950.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"

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
