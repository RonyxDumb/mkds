#pragma once

#include "types.h"

unsigned int GetCurrentRaceRules(void);
unsigned int GetMaybeNextRuleParam(void);
unsigned int GetCurrentBattleType(void);
unsigned int GetIsMirror(void);
unsigned int GetCurrrentCcType(void);
unsigned int GetCurrentInternalCourseId_1(void);
unsigned int GetCurrentRaceMode(void);
unsigned int GetRacerCount(void);
unsigned int GetCurrentRaceCpuMode(void);
unsigned int GetCurrentCupIndex(void);

u32 GetCurrentListedCpuSlot(u32 entryIndex);
u32 GetRacerTeam(u32 entryIndex);

unsigned int GetIsTeams(void);

u32 GetRacerType_0(u32 entryIndex);
u32 GetRacerKartId(u32 entryIndex);
u32 GetRacerCharacterId(u32 entryIndex);
