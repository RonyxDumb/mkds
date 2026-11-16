#pragma once

#include "types.h"
#include "Main/Kart/kart_drift.h"
#include "Main/Course/course_map_group_entry.h"
#include "Main/Item/item_koura_w.h"
#include "Main/MapObjects/iron_ball.h" // IronBall
#include "Main/Race/race_hud_keyboard_map_object_work.h"

void DrawIronBall(void *mapObjectList, IronBall *ironBall);
void SetupDrawIronBall(void *mapObjectList);
void CreateIronBall(void *mapObjectList);
u32 CollideKartWithIronBall(IronBall *ironBall, void *kart, u8 *firstResponse, u8 *response);
void InitIronBall(IronBall *ironBall);
s32 GetKeyboardChosenKeyValue(void);
s32 GetKeyboardCursorValue(void);
void MoveKeyboardCursorToValue(u16 value);
