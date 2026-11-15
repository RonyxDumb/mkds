#pragma once

#include "types.h"
#include "Main/Race/race_hud_keyboard_map_object_work.h"
#include "tp.h"
#include "Main/Race/race_goal_times.h"
#include "Main/Graphics/font_and_player_character.h"

void DrawRaceMNumberPair(RaceHudOamBuffer *oamBuffer);
void SetRaceMNumberPairAnimation(RaceHudOamBuffer *oamBuffer, s32 startFrames);
void DrawRaceMNumberPairTwoDigit(RaceHudOamBuffer *oamBuffer);
void DrawRaceMNumberPairOneDigit(RaceHudOamBuffer *oamBuffer);

extern RaceMNumberPair *gRaceMNumberPair;
