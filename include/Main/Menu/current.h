#pragma once

#include "types.h"

unsigned int GetCurrentRuleKind(void);
unsigned int GetCurrentCourseCount(void);
unsigned int GetCurrentBattleKind(void);
unsigned int GetCurrentMirrorMode(void);
unsigned int GetCurrentEngineIndex(void);
unsigned int GetCurrentCourseId(void);
unsigned int GetCurrentMode(void);
unsigned int GetCurrentKartCount(void);
unsigned int GetCurrentCpuDifficulty(void);
unsigned int GetCurrentCupIndex(void);

u32 GetCurrentListedCpuSlot(u32 entryIndex);
u32 GetCurrentTeamIndex(u32 entryIndex);

unsigned int GetCurrentUseTeams(void);

u32 GetCurrentPlayerKind(u32 entryIndex);
u32 GetCurrentKartIndex(u32 entryIndex);
u32 GetCurrentCharacterIndex(u32 entryIndex);
