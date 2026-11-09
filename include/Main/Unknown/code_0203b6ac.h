#pragma once

#include "types.h"

typedef struct RandomState64 RandomState64;

typedef struct CharacterKartPicks CharacterKartPicks;

void SetNextDemoRace(CharacterKartPicks *picks);
u32 func_0203b8e4(RandomState64 *random);
BOOL func_0203b96c(s32 cupIndex);
