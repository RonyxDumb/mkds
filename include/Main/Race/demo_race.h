#pragma once

#include "types.h"

typedef struct RandomState64 RandomState64;

typedef struct CharacterKartPicks CharacterKartPicks;

void SetNextDemoRace(CharacterKartPicks *picks);
u32 PickRandomCupIndex(RandomState64 *random);
BOOL IsCupAlwaysOrSecretMessageFlagSet(s32 cupIndex);
